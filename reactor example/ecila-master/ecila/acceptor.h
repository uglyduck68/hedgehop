#pragma once


#include "node.h"








NS_ECILA_START

class IAcceptor;
class IPacketHandler;

class DECL_SPEC_DLL Acceptor
:	public Node
{
public:

	Acceptor();
	virtual ~Acceptor();

	CLASSNAME("Acceptor");

	void		Initialize(Node *root, IPacketHandler *pkt_handler);
	IAcceptor*  AcceptorImpl();


private:
	IAcceptor		*acceptor_;
	IPacketHandler	*pkt_handler_;

};
	
NS_ECILA_END

