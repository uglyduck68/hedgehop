// server.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Log.h"
#include "Reactor.h"

// Description:
//
//    This sample illustrates how to develop a simple echo server Winsock
//    application using the select() API I/O model. This sample is
//    implemented as a console-style application and simply prints
//    messages when connections are established and removed from the server.
//    The application listens for TCP connections on port 5150 and accepts
//    them as they arrive. When this application receives data from a client,
//    it simply echos (this is why we call it an echo server) the data back in
//    it's original form until the client closes the connection.
//
//    Note: There are no command line options for this sample.
//
// Link to ws2_32.lib

#include <winsock2.h>
#include <windows.h>
#include <stdio.h>

#include "X1.h"
#include "Acceptor.h"

#include "EchoService.h"

using namespace	X1;

#define PORT 5150

#define DATA_BUFSIZE 8192



typedef struct _SOCKET_INFORMATION 
{
	CHAR Buffer[DATA_BUFSIZE];
	WSABUF DataBuf;
	SOCKET Socket;
	OVERLAPPED Overlapped;	// when this is used??
	DWORD BytesSEND;
	DWORD BytesRECV;
} SOCKET_INFORMATION, * LPSOCKET_INFORMATION;



// Prototypes
BOOL CreateSocketInformation(SOCKET s);
void FreeSocketInformation(DWORD Index);



// Global var
DWORD TotalSockets = 0;

LPSOCKET_INFORMATION SocketArray[FD_SETSIZE];



int main(int argc, char **argv)
{
	SOCKET ListenSocket;
	SOCKET AcceptSocket;
//	SOCKADDR_IN InternetAddr;
	FD_SET WriteSet;
	FD_SET ReadSet;
	DWORD i;
	DWORD Total;
	ULONG NonBlock;
	DWORD Flags;
	DWORD SendBytes;
	DWORD RecvBytes;

	if (Lib::Init() != X1_OK)
	{
		LOG_FATAL("X1::Init()\n");

		Lib::Fin();

		return 1;
	}

	LOG_INIT("echosvr.log");

	NetAddr				Addr(PORT, INADDR_ANY);
	Acceptor			acceptor;
	Reactor				reactor;

	acceptor.SetSvc(new EchoService);

	// FIXME: use ConnectionAcceptor pattern
	// Prepare a socket to listen for connections
	if (acceptor.Open(Addr, Reactor::GetInstance()) != X1_OK)
	{
		LOG_FATAL("acceptor.Open fails\n");
		return X1_FAIL;
	}




	while(TRUE)
	{
		if (Reactor::GetInstance()->HandleEvent() == X1_FAIL)
		{
			LOG_ERROR("HandleEvent() fails. return from main\n");
			return 1;
		}
	}

	LOG_INFO("end of reactor\n");

	return X1_OK;
	while(TRUE)
	{

		// Prepare the Read and Write socket sets for network I/O notification

		FD_ZERO(&ReadSet);
		FD_ZERO(&WriteSet);



		// Always look for connection attempts
		FD_SET(ListenSocket, &ReadSet);



		// Set Read and Write notification for each socket based on the
		// current state the buffer.  If there is data remaining in the
		// buffer then set the Write set otherwise the Read set

		for (i = 0; i < TotalSockets; i++)
		{
			if (SocketArray[i]->BytesRECV > SocketArray[i]->BytesSEND)
				FD_SET(SocketArray[i]->Socket, &WriteSet);
			else
				FD_SET(SocketArray[i]->Socket, &ReadSet);
		}


		if ((Total = select(0, &ReadSet, &WriteSet, NULL, NULL)) == SOCKET_ERROR)
		{

			printf("select() returned with error %d\n", WSAGetLastError());

			return 1;
		}
		else
			printf("select() is OK!\n");



		// Check for arriving connections on the listening socket.

		if (FD_ISSET(ListenSocket, &ReadSet))
		{

			Total--;

			if ((AcceptSocket = accept(ListenSocket, NULL, NULL)) != INVALID_SOCKET)
			{

				// Set the accepted socket to non-blocking mode so the server will
				// not get caught in a blocked condition on WSASends

				NonBlock = 1;

				if (ioctlsocket(AcceptSocket, FIONBIO, &NonBlock) == SOCKET_ERROR)
				{

					printf("ioctlsocket(FIONBIO) failed with error %d\n", WSAGetLastError());

					return 1;

				}
				else
					printf("ioctlsocket(FIONBIO) is OK!\n");



				if (CreateSocketInformation(AcceptSocket) == FALSE)
				{

					printf("CreateSocketInformation(AcceptSocket) failed!\n");

					return 1;
				}
				else
					printf("CreateSocketInformation() is OK!\n");
			}	// end of accept
			else
			{
				if (WSAGetLastError() != WSAEWOULDBLOCK)
				{

					printf("accept() failed with error %d\n", WSAGetLastError());

					return 1;
				}
				else
					printf("accept() is fine!\n");

			}
		}



		// Check each socket for Read and Write notification until the number
		// of sockets in Total is satisfied

		for (i = 0; Total > 0 && i < TotalSockets; i++)
		{
			LPSOCKET_INFORMATION SocketInfo = SocketArray[i];



			// If the ReadSet is marked for this socket then this means data

			// is available to be read on the socket

			if (FD_ISSET(SocketInfo->Socket, &ReadSet))
			{
				Total--;



				SocketInfo->DataBuf.buf = SocketInfo->Buffer;
				SocketInfo->DataBuf.len = DATA_BUFSIZE;

				Flags = 0;

				if (WSARecv(SocketInfo->Socket, &(SocketInfo->DataBuf), 1, &RecvBytes, &Flags, NULL, NULL) == SOCKET_ERROR)
				{

					if (WSAGetLastError() != WSAEWOULDBLOCK)

					{

						printf("WSARecv() failed with error %d\n", WSAGetLastError());

						FreeSocketInformation(i);

					}

					else

						printf("WSARecv() is OK!\n");

					continue;

				}
				else
				{
					SocketInfo->BytesRECV = RecvBytes;



					// If zero bytes are received, this indicates the peer closed the connection.

					if (RecvBytes == 0)
					{

						FreeSocketInformation(i);

						continue;
					}
				}
			}



			// If the WriteSet is marked on this socket then this means the internal
			// data buffers are available for more data

			if (FD_ISSET(SocketInfo->Socket, &WriteSet))
			{

				Total--;



				SocketInfo->DataBuf.buf = SocketInfo->Buffer + SocketInfo->BytesSEND;

				SocketInfo->DataBuf.len = SocketInfo->BytesRECV - SocketInfo->BytesSEND;



				if (WSASend(SocketInfo->Socket, &(SocketInfo->DataBuf), 1, &SendBytes, 0, NULL, NULL) == SOCKET_ERROR)
				{

					if (WSAGetLastError() != WSAEWOULDBLOCK)

					{

						printf("WSASend() failed with error %d\n", WSAGetLastError());

						FreeSocketInformation(i);

					}

					else

						printf("WSASend() is OK!\n");



					continue;

				}

				else

				{

					SocketInfo->BytesSEND += SendBytes;



					if (SocketInfo->BytesSEND == SocketInfo->BytesRECV)
					{
						SocketInfo->BytesSEND = 0;

						SocketInfo->BytesRECV = 0;
					}

				}

			}	// FD_ISSET write socket

		}	// for each sockets is array

	}

}



BOOL CreateSocketInformation(SOCKET s)
{
	LPSOCKET_INFORMATION SI;


	printf("Accepted socket number %d\n", s);


	if ((SI = (LPSOCKET_INFORMATION) GlobalAlloc(GPTR, sizeof(SOCKET_INFORMATION))) == NULL)
	{

		printf("GlobalAlloc() failed with error %d\n", GetLastError());

		return FALSE;
	}
	else
		printf("GlobalAlloc() for SOCKET_INFORMATION is OK!\n");



	// Prepare SocketInfo structure for use
	SI->Socket = s;
	SI->BytesSEND = 0;
	SI->BytesRECV = 0;



	SocketArray[TotalSockets] = SI;

	TotalSockets++;

	return(TRUE);
}



void FreeSocketInformation(DWORD Index)
{

	LPSOCKET_INFORMATION SI = SocketArray[Index];

	DWORD i;



	closesocket(SI->Socket);

	printf("Closing socket number %d\n", SI->Socket);

	GlobalFree(SI);



	// Squash the socket array
	for (i = Index; i < TotalSockets; i++)
	{

		SocketArray[i] = SocketArray[i + 1];
	}



	TotalSockets--;
}


/*
int _tmain(int argc, _TCHAR* argv[])
{
return 0;
}
*/


/*
int main()
{
return 1;
}
*/