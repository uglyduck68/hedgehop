#pragma once
#include <memory>
#include <string>
#ifndef _WINSOCK2API_
#include <winsock2.h>
#include <ws2tcpip.h>
#endif
#include <functional>
class SocketObj
{
public:
	SocketObj(void);
	SocketObj(SocketObj* other);
	SocketObj(const SocketObj& other);
	~SocketObj(void);

	bool IsOpen() const;
	void Close();
	bool Open(LPCSTR pszHost,LPCSTR pszServiceName,int nFamily,int nType,unsigned int uOptions = 0);
	bool Connect(LPCSTR pszHostName, LPCSTR pszRemote, LPCSTR pszServiceName, int nFamily, int nType,unsigned int uOptions = 0);
	unsigned long Write(const void* lpBuffer,unsigned long dwCount,unsigned long timeout = 0xFFFFFFFF);

	void SetUID(const int id);
	const int GetUID() const;
	void SetCallback(std::function<void(void*,size_t)> pCallback);
private:
	class BaseImpl;
	class ServerInterface;
	class ClientInterface;
	std::unique_ptr<BaseImpl> Impl;
	int UID;
};

