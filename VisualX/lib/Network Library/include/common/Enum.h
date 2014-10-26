#pragma once
namespace enNetwork{
	namespace NetworkType{
		enum NetworkType
		{
			TCP,
			UDP,
			SERIAL
		};
	};
	namespace NetworkState{
		enum NetworkState
		{
			Created,
			Initialize,
			Bind,
			Connect,
			Initiate,
			Disconnect
		};
	};
	namespace NetworkUsageType {
		enum NetworkUsageType
		{
			Unknown,
			Server,
			Client
		};
	};
	namespace NetworkReturn {
		enum NetworkReturn
		{
			Success = 0x1000,
			Failed
		};
	};
	namespace MsgTable {
		enum MsgTable
		{
			WM_SOCKET = 0x0400+1,
			Connected,
			Accepted,
			Received,
			Sended,
		};
	};
};
static const int packetsz = 1024;
struct packetHDR
{
	int sz;
	int pknum;
	int pktotal;
};
struct Packet
{
	packetHDR hdr;
	unsigned char data[packetsz];
};