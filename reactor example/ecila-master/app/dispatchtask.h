#pragma once


#include <ecila/itask.h>
#include <ecila/msgqueue.h>
#include <ecila/bufferpool.h>







class HttpMsgDispatcherDic;

class DispatchTask
:	public NS_ECILA::ITask
{
public:

			 DispatchTask();
	virtual ~DispatchTask();

	virtual bool_t Run();


private:

	NS_ECILA::MsgQueue		*dispatch_q_;
	NS_ECILA::BufferPool	*buff_pool_;
	HttpMsgDispatcherDic	*httpd_dic_;

	void CacheNode(NS_ECILA::Node *root);

	bool_t DispatchMsg();

};

