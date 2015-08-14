/**
 * @file	define TCP messages between client and server for Star
 * @history
 * [20130713] initial draft
 *
 */

#pragma once

#include <time.h>

#include "Defines.h"


enum MSGID 
{
	///
	// Msg ID between 100 and 199 is status messages
	MSGID_HEARTHEAT		= 100,	// ping command from server

	//////////////////////////////////////////////////////////////////////////
	// Msg ID between 200 and 299 is client request messages
	MSGID_ACK			= 200	// ack response from client

	//////////////////////////////////////////////////////////////////////////
	// Msg ID between 300 and 399 is server response messages

	//////////////////////////////////////////////////////////////////////////
	// Msg ID between 400 and 499 is server command messages

};

#pragma pack(push, 1)

typedef struct tagHEADER 
{
	uint16		nID;		// message ID
	uint16		nVer;		// message version
	uint16		nSize;		// message size
	time_t		nMsgTime;	// message generation time (__time64_t type)
							// this time *MUST* be gmt time because server communicate to clinets from many country

	void	InitMsg(uint16 ID, uint16 Size, uint16 Ver = 1)
	{
		nID			= ID;
		nVer		= Ver;
		nSize		= Size;
		nMsgTime	= time(NULL);
	}
} HEADER;

typedef	struct tagHEARTBEAT : tagHEADER
{
	uint16	nCmd;

	tagHEARTBEAT()
	{
		InitMsg(MSGID_HEARTHEAT, sizeof(tagHEARTBEAT));
	}
} HEARTBEAT;

#pragma pack(pop)