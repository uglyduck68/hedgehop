#include "ipackethandler.h"

#include "node.h"








US_ECILA

IPacketHandler::IPacketHandler()
{
	root_		= 0;
}








IPacketHandler::~IPacketHandler()
{
}








bool_t IPacketHandler::Initialize(Node *root)
{
	ECILA_ASSERT(root);
	root_ = root;

	CacheNode();

	return TRUE;
}








void IPacketHandler::CacheNode()
{
}

