// server_wsa.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>


#define PORT			5150
#define	DATA_BUFSIZE	8192

//////////////////////////////////////////////////////////////////////////
// method 2
//////////////////////////////////////////////////////////////////////////
// 소켓 정보 저장을 위한 구조체
typedef struct
{
	SOCKET sock;
	char recvBuffer[DATA_BUFSIZE + 1];
	char sendBuffer[DATA_BUFSIZE + 1];
	int recvBytes;
	int sendBytes;

} SOCKET_INFO;



int g_nTotalSockets = 0;

SOCKET_INFO*        g_aSocketInfoArray[WSA_MAXIMUM_WAIT_EVENTS];
WSAEVENT                g_aEventArray[WSA_MAXIMUM_WAIT_EVENTS];



// 소켓 관리 함수
BOOL AddSocketInfo(SOCKET clientSocket);
void RemoveSocketInfo(int nIndex);



// 오류 출력 함수
void err_quit(char* msg);
void err_display(char* msg);
void err_display(int errCode);


int main(int argc, _TCHAR* argv[])
{
	int retValue;

	// 윈속 초기화
	WSADATA wsa;
	if(WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return -1;

	// socket()
	SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(listenSocket == INVALID_SOCKET)
		err_quit("socket()");

	//소켓정보 추가
	if(AddSocketInfo(listenSocket) == FALSE)
		return -1;

	// WSAEventSelect 설정
	retValue = WSAEventSelect(listenSocket, g_aEventArray[g_nTotalSockets - 1], FD_ACCEPT | FD_CLOSE);
	if(retValue == SOCKET_ERROR)
		err_quit("WSAEventSelect()");

	// bind()
	SOCKADDR_IN serverAddr;

	memset(&serverAddr, 0, sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	retValue = bind(listenSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
	if(retValue == SOCKET_ERROR)
		err_quit("bind()");

	//listen()
	retValue = listen(listenSocket, SOMAXCONN);
	if(retValue == SOCKET_ERROR)
		err_quit("listen()");

	// 넌블로킹 소켓으로 전환
	unsigned long on = TRUE;
	retValue = ioctlsocket(listenSocket, FIONBIO, &on);
	if(retValue == SOCKET_ERROR)
		err_display("ioctlsocket()");

	// 통신에 사용할 변수
	int index;
	WSANETWORKEVENTS networkEvents;
	SOCKET clientSocket;
	SOCKADDR_IN clientAddr;
	int nAddrLength;

	while(1)
	{
		index = WSAWaitForMultipleEvents(g_nTotalSockets, g_aEventArray, FALSE, WSA_INFINITE, FALSE);
		if(index == WSA_WAIT_FAILED)
		{
			err_display("WSAWaitForMultipleEvents()");
			continue;
		}

		index -= WSA_WAIT_EVENT_0;

		// 구체적인 네트워크 이벤트 알아내기
		retValue = WSAEnumNetworkEvents(g_aSocketInfoArray[index]->sock, 
			g_aEventArray[index], &networkEvents);
		if(retValue == SOCKET_ERROR)
		{
			err_display("WSAEnumNetworkEvents()");
			continue;
		}

		// FD_ACCEPT 이벤트 처리
		if(networkEvents.lNetworkEvents & FD_ACCEPT)
		{
			if(networkEvents.iErrorCode[FD_ACCEPT_BIT] != 0)
			{
				err_display(networkEvents.iErrorCode[FD_ACCEPT_BIT]);
				continue;
			}
			nAddrLength = sizeof(clientAddr);
			clientSocket = accept(g_aSocketInfoArray[index]->sock,
				(SOCKADDR*)&clientAddr, &nAddrLength);
			if(clientSocket == INVALID_SOCKET)
			{
				err_display("accept()");
				continue;
			}
			printf("[TCP 서버] 클라이언트 접속: IP 주소 = %s, 포트번호 = %d\n",
				inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

			if(AddSocketInfo(clientSocket) == FALSE)
			{
				closesocket(clientSocket);
				continue;
			}

			retValue = WSAEventSelect(clientSocket, 
				g_aEventArray[g_nTotalSockets - 1], FD_READ | FD_WRITE | FD_CLOSE);

			if(retValue == SOCKET_ERROR)
				err_quit("WSAEventSelect()");
		}

		// FD_READ, FD_WRITE 이벤트 처리
		if((networkEvents.lNetworkEvents & FD_READ) ||
			(networkEvents.lNetworkEvents & FD_WRITE))
		{
			if((networkEvents.lNetworkEvents & FD_READ) && (networkEvents.iErrorCode[FD_READ_BIT] != 0))
			{
				err_display(networkEvents.iErrorCode[FD_READ_BIT]);
				continue;
			}

			if((networkEvents.lNetworkEvents & FD_WRITE) && (networkEvents.iErrorCode[FD_WRITE_BIT] != 0))
			{
				err_display(networkEvents.iErrorCode[FD_WRITE_BIT]);
				continue;
			}

			SOCKET_INFO* pSocketInfo = g_aSocketInfoArray[index];

			if(pSocketInfo->recvBytes == 0)
			{
				// 데이터 받기
				retValue = recv(pSocketInfo->sock, pSocketInfo->recvBuffer, DATA_BUFSIZE, 0);
				if(retValue == SOCKET_ERROR)
				{
					if(WSAGetLastError() != WSAEWOULDBLOCK)
					{
						err_display("recv()");
						RemoveSocketInfo(index);
					}
					continue;
				}
				pSocketInfo->recvBytes = retValue;
				pSocketInfo->recvBuffer[retValue] = '\0';
				nAddrLength = sizeof(clientAddr);
				getpeername(pSocketInfo->sock, (SOCKADDR*)&clientAddr, &nAddrLength);
				printf("[TCP/%s:%d] %s\n", inet_ntoa(clientAddr.sin_addr),
					ntohs(clientAddr.sin_port), pSocketInfo->recvBuffer);

				// 에코서버이므로 받은데이터를 반송한다.
				pSocketInfo->sendBytes = retValue;
				memcpy(pSocketInfo->sendBuffer, pSocketInfo->recvBuffer, retValue);

				// 보낸만큼 리시브버퍼를 관리한다.
				pSocketInfo->recvBytes -= pSocketInfo->sendBytes;
				memmove(pSocketInfo->recvBuffer, pSocketInfo->recvBuffer + retValue, pSocketInfo->recvBytes);
			}

			/**
			 *
			 */
			if(pSocketInfo->sendBytes > 0)
			{
				// 보내고자 하는 버퍼에 값을 모두 보낼 때 까지 처리한다.
				do
				{
					retValue = send(pSocketInfo->sock, pSocketInfo->sendBuffer, pSocketInfo->sendBytes, 0);
					if(retValue == SOCKET_ERROR)
					{
						if(WSAGetLastError() != WSAEWOULDBLOCK)
						{
							err_display("send()");
							RemoveSocketInfo(index);
						}
						continue;
					}
					pSocketInfo->sendBytes -= retValue;
					memmove(pSocketInfo->sendBuffer, pSocketInfo->sendBuffer + retValue, pSocketInfo->sendBytes);

				} while(pSocketInfo->sendBytes > 0);
			}
		}

		// 접속 종료
		if(networkEvents.lNetworkEvents & FD_CLOSE)
		{
			if(networkEvents.iErrorCode[FD_CLOSE_BIT] != 0)
				err_display(networkEvents.iErrorCode[FD_CLOSE_BIT]);

			RemoveSocketInfo(index);
		}
	}

	// 윈속 종료
	WSACleanup();
	return 0;
}

BOOL AddSocketInfo(SOCKET clientSocket)
{
	if(g_nTotalSockets >= WSA_MAXIMUM_WAIT_EVENTS)
	{
		printf("[오류] 소켓 정보를 추가할 수 없습니다.\n");
		return FALSE;
	}

	SOCKET_INFO* pSocketInfo = new SOCKET_INFO;
	if(pSocketInfo == NULL)
	{
		printf("[오류] 메모리가 부족합니다.\n");
		return FALSE;
	}

	WSAEVENT hEvent = WSACreateEvent();
	if(hEvent == WSA_INVALID_EVENT)
	{
		err_display("WSACreateEvent()");
		return FALSE;
	}

	pSocketInfo->sock = clientSocket;
	pSocketInfo->recvBytes = 0;
	pSocketInfo->sendBytes = 0;

	g_aSocketInfoArray[g_nTotalSockets] = pSocketInfo;
	g_aEventArray[g_nTotalSockets] = hEvent;
	g_nTotalSockets++;

	return TRUE;
}

void RemoveSocketInfo(int nIndex)
{
	SOCKET_INFO* pInfo = g_aSocketInfoArray[nIndex];

	// 클라이언트 정보 얻기
	SOCKADDR_IN socketAddr;
	int nAddrLength = sizeof(socketAddr);
	getpeername(pInfo->sock, (SOCKADDR*)&socketAddr, &nAddrLength);
	printf("[TCP 서버] 클라이언트 종료: IP 주소 = %s, 포트번호 = %d\n",
		inet_ntoa(socketAddr.sin_addr), ntohs(socketAddr.sin_port));

	closesocket(pInfo->sock);
	delete pInfo;
	WSACloseEvent(g_aEventArray[nIndex]);

	for(int i = nIndex; i < g_nTotalSockets; ++i)
	{
		g_aSocketInfoArray[i] = g_aSocketInfoArray[i + 1];
		g_aEventArray[i] = g_aEventArray[i + 1];
	}

	g_nTotalSockets--;
}

void err_quit(char* msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	MessageBox(NULL, (LPCTSTR)lpMsgBuf, msg, MB_ICONERROR);
	LocalFree(lpMsgBuf);
	exit(-1);
}

void err_display(char* msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	printf("[%s] %s\n", msg, (LPCTSTR)lpMsgBuf);
	LocalFree(lpMsgBuf);
}

void err_display(int errCode)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, errCode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	printf("[오류] %s", (LPCTSTR)lpMsgBuf);
	LocalFree(lpMsgBuf);
} 


/*
int _tmain(int argc, _TCHAR* argv[])
{
return 0;
}
*/

