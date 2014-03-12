#pragma once

#pragma pack(push, 1)

typedef struct tagPacket
{
	unsigned short	Length;		// Length of Packet excluding Length itself
	unsigned short	ID;			// packet ID
	unsigned char	Payload[];	// variable size of payload
} Packet;

int MakePacket(int nPayloadSize, Packet** ppPacket);

#pragma pack(pop)