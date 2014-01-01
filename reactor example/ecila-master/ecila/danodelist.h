#pragma once


#include <list>
#include "ecila.h"








NS_ECILA_START

class Node;

//dynamic allocation node lists
class DECL_SPEC_DLL DANodeList
{
public:
	 DANodeList();
	~DANodeList();

	void AddNode(Node *node);
	void Destroy();


private:

	typedef std::list< Node* >  LIST_T;
	typedef LIST_T::iterator	ITER_T;

	LIST_T list_;
};


NS_ECILA_END
