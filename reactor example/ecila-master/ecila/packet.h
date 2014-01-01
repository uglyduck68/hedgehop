#pragma once

#include "serial.h"
#include "ipaddrs.h"









NS_ECILA_START

enum PACKET_KIND
{
	PKT_KIND_NONE	= 0,
	PKT_KIND_SYSTEM,
	PKT_KIND_USERAPP,
	PKT_KIND_EMULAPP,
	PKT_KIND_MANAGEMENT,
};


enum PACKET_CMD
{
	PKT_CMD_NOND	= 0,
	PKT_CMD_RECV    = 1 << 0,
	PKT_CMD_SEND    = 1 << 1,
	PKT_CMD_CLOSE   = 1 << 2,
};


class DECL_SPEC_DLL PacketHeader
{
public:
	int32_t   kind_;
	int32_t   cmd_;
	uint32_t  size_;
	serial_t  uidx_;
	IPAddrs   from_addrs_;

	 PacketHeader();
	~PacketHeader();
};

NS_ECILA_END
