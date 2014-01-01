#include "danodelist.h"

#include "node.h"








US_ECILA

DANodeList::DANodeList()
{
}








DANodeList::~DANodeList()	
{
	Destroy();
}








void DANodeList::AddNode(Node *node)
{
	ECILA_ASSERT(node);

	list_.push_back(node);
}








void DANodeList::Destroy()
{
	for(ITER_T iter = list_.begin(); iter != list_.end(); ++iter)
	{
		Node *n = *iter;
		ECILA_SAFE_DELETE(n);
	}
	list_.clear();
}

