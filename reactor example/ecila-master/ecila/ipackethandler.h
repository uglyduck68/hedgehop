#pragma once


#include "ecila.h"
#include "eventtype.h"








NS_ECILA_START

class Node;
class Session;

class DECL_SPEC_DLL IPacketHandler
{
public:

			 IPacketHandler();
	virtual ~IPacketHandler();

	bool_t Initialize(Node *root);

	virtual bool_t HandleEvents(serial_t uidx, Session *sess, EVENT_T e) = 0;
	virtual void   CacheNode();


protected:

	Node		*root_;
};

NS_ECILA_END

