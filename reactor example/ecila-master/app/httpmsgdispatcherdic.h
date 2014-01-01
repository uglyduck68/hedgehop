#pragma once


#include <ecila/node.h>






class IHttpMsgDispatcher;

class HttpMsgDispatcherDic
:	public NS_ECILA::Node
{
public:

			 HttpMsgDispatcherDic();
	virtual ~HttpMsgDispatcherDic();

	CLASSNAME("HttpMsgDispatcherDic");

	bool_t				Load(NS_ECILA::Node *root);
	IHttpMsgDispatcher*	Find(const char_t *uri);


private:

	typedef std::map< std::string, IHttpMsgDispatcher* > MAP_T;
	typedef MAP_T::iterator								 ITER_T;

	MAP_T map_;
};

