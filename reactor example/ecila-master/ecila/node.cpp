#include "node.h"








US_ECILA

Node::Node()
{
	depth_	= 0;
	parent_	= 0;
	name_	= "";
}








Node::~Node()
{
	if(parent_)
	{
		parent_->Detach(this);
	}

	for(ITER_T iter = child_.begin(); iter != child_.end(); ++iter)
	{
		Node *node = iter->second;
		node->parent_ = 0;
	}
	child_.clear();
}








bool_t Node::Attach(Node *node)
{
	ECILA_ASSERT(node);

	ITER_T iter = child_.find(node->Name());
	if(iter != child_.end()) { ECILA_TRACE(); return FALSE; }

	child_[node->Name()] = node;

	node->parent_	= this;
	node->depth_	= node->parent_->depth_ + 1;

	return TRUE;
}








bool_t Node::Detach(Node *node)
{
	ECILA_ASSERT(node);

	ITER_T iter = child_.find(node->Name());
	if(iter == child_.end()) { ECILA_TRACE(); return FALSE; }

	node->parent_ = 0;
	child_.erase(iter);

	return TRUE;
}








void Node::Dump()
{
	for(uint32_t i=0; i<depth_; i++)
	{
		ECILA_PRINT(("\t"));
	}

	if(child_.empty())  { ECILA_PRINT(("[-] %s\n", name_.c_str())); }
	else				{ ECILA_PRINT(("[+] %s\n", name_.c_str())); }
	
	DUMPSPEC();

	for(ITER_T iter = child_.begin(); iter != child_.end(); ++iter)
	{
		iter->second->Dump();
	}
}








void Node::DUMPSPEC()
{
}

