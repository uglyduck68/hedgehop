#include <new>
#include <string>

#include "Packet.h"

using namespace std;

/**
* @function		MakePacket
* @brief		make Packet struct that has nPayloadSize payload
*/
int MakePacket(int nPayloadSize, Packet** ppPacket)
{
	*ppPacket	= (Packet*)new (std::nothrow)unsigned char[nPayloadSize+sizeof(unsigned short)];

	if (*ppPacket == NULL)
		return -1;

	(*ppPacket)->Length	= nPayloadSize;

#if	0	// debug
	const char* p	= "I love you";

	strncpy((char*)(*ppPacket)->Payload, p, strlen(p));
#endif

	return 1;
}