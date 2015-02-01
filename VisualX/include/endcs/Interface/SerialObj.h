#pragma once
#include <memory>
#include <vector>
struct _PK_HDR
{
	char type;
	char len[3];

	_PK_HDR(){
		Init();
	}
	void Init()
	{
		type = 0x00;
		memset(len,0x00,3);
	}

	int GetMsgLength()
	{
		return strtoul(len,NULL,16);
	}
};
struct _PK_REC
{
	_PK_HDR hdr;
	std::vector<char> buf;

	_PK_REC(unsigned short nLen = 0)
	{
		if(nLen > 0)
			buf.resize(nLen,0x00);
	}

	~_PK_REC()
	{
		buf.clear();
	}

	void Init()
	{
		hdr.Init();
		buf.clear();
	}

	short GetCheckLength()
	{
		if(hdr.GetMsgLength() <= 0)
			return 0;
		if(hdr.GetMsgLength() != (int)buf.size() )
			return 2;

		return 1;

	}
};
class SerialObj
{
public:
	SerialObj(short port,short timeout,long baudRate,unsigned char dataBits,unsigned char parity,unsigned char stopBits);
	SerialObj(SerialObj* other);
	SerialObj(const SerialObj& other);
	~SerialObj(void);
	int Open();
	int Connect();
	int Close();
	int Recv();
	int Send(const void* data, int dataLength);
	void SetMessageType(const std::string& Type);
	void SetStartChar(const char s);
	void SetEndChar(const char e);

	void Clear();
	unsigned short GetCount();
	_PK_REC* GetMessageData(unsigned short index);
	void Switch();
	void SetUID(const int id);
	const int GetUID() const;
private:
	class pImpl;
	std::unique_ptr<pImpl> Impl;
	int UID;
};

