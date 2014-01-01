#pragma once


#include "node.h"








NS_ECILA_START

class IDemultiplexer;

class DECL_SPEC_DLL Demultiplexer
:	public Node
{
public:

			 Demultiplexer();
	virtual ~Demultiplexer();

	CLASSNAME("Demultiplexer");

	void			Initialize(const char_t *netio);
	IDemultiplexer* DemultiplexerImpl();


private:
	IDemultiplexer *demultiplexer_;
	
};
	
NS_ECILA_END

