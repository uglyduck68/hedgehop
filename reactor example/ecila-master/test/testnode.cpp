#include "testnode.h"

#include <ecila/node.h>
#include <ecila/danodelist.h>









class Child
:	public Node
{
public:
			 Child() {}
	virtual ~Child() {}

	CLASSNAME("Child");
};









void TestNode::Do()
{
	DANodeList list;

	Node *root = new Node();
	root->Name("root");
	ECILA_ASSERT(root);
	list.AddNode(root);
	

	Child *child_1 = new Child();
	ECILA_ASSERT(child_1);
	child_1->Name("child_1");
	root->Attach(child_1);
	list.AddNode(child_1);


	Child *child_2 = new Child();
	ECILA_ASSERT(child_2);
	child_2->Name("child_2");
	child_1->Attach(child_2);
	list.AddNode(child_2);


	assertEquals(child_1, root->FindChild<Child>("child_1"));
	assertEquals(child_2, root->FindObject<Child>("/child_1/child_2"));


	root->Dump();


//	NodeInstance::Inst()->Destroy();
}

