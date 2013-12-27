#include "EchoService.h"
#include "NetAddr.h"

using namespace X1;

EchoService::EchoService(void)
{
	recvBytes		= 0;
	sendBytes		= 0;
}


EchoService::~EchoService(void)
{
}

void DisplayError(int errCode)
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

// called when input event occur (e.g., connection or data)
int		EchoService::HandleRead(X1_SOCHANDLE h)
{
	int		nRet	= 0;
	int		nAddrLength	= 0;
	NetAddr clientAddr;

	LOG_INFO("recv byte: %d, send byte: %d\n", recvBytes, sendBytes);

	if(recvBytes == 0)
	{
		// 데이터 받기
		nRet = recv(GetHandle(), recvBuffer, DATA_BUFSIZE, 0);

		if(nRet == SOCKET_ERROR)
		{
			if(WSAGetLastError() != WSAEWOULDBLOCK)
			{
				return X1_FAIL;
			}
		}
		else if (nRet == 0)
		{
			// connection closed
			return X1_CLOSED;
		}

		recvBytes			= nRet;
		recvBuffer[nRet]	= '\0';

		if (clientAddr.SetAddr(GetHandle()) != X1_OK)
		{
			DisplayError(WSAGetLastError());
		}

		nAddrLength = sizeof(clientAddr);


		printf("[TCP/%s:%d] %s\n", inet_ntoa(clientAddr), ntohs(clientAddr.GetPort()), recvBuffer);

		// 에코서버이므로 받은데이터를 반송한다.
		sendBytes = nRet;
		memcpy(sendBuffer, recvBuffer, nRet);

		// 보낸만큼 리시브버퍼를 관리한다.
		recvBytes -= sendBytes;
		memmove(recvBuffer, recvBuffer + nRet, recvBytes);

#ifdef	_REACTORIMPL_WIN32_H_
		HandleWrite(h);
#elif defined(_REACTORIMPL_WIN32_SELECT_H_)
		// select call HandleWrite function if write buffer is available
#endif
	}

	return X1_OK;
}

// called when output events are possible
int 	EchoService::HandleWrite(X1_SOCHANDLE h)
{
	int		nRet	= 0;

	LOG_INFO("recv byte: %d, send byte: %d\n", recvBytes, sendBytes);

	if(sendBytes > 0)
	{
		// 보내고자 하는 버퍼에 값을 모두 보낼 때 까지 처리한다.
		do
		{
			nRet = send(GetHandle(), sendBuffer, sendBytes, 0);

			if(nRet == SOCKET_ERROR)
			{
				if(WSAGetLastError() != WSAEWOULDBLOCK)
				{
					return X1_FAIL;
				}
				continue;
			}
			else if (nRet == 0)
			{
				// connection closed
				return X1_CLOSED;
			}

			sendBytes -= nRet;
			memmove(sendBuffer, sendBuffer + nRet, sendBytes);

		} while(sendBytes > 0);
	}

	return X1_OK;
}

int 	EchoService::HandleException(X1_SOCHANDLE h)
{
	return X1_OK;
}

int 	EchoService::HandleClose(X1_SOCHANDLE h /*= INVALID_HANDLE*/, EVENT_MASK e/* = ALL_EVENTS_MASK*/)
{
	printf("connection closed\n");

	closesocket(GetHandle());

	return X1_OK;
}

int 	EchoService::HandleTimeout(const TimeValue& tv)
{

	return X1_OK;
}
