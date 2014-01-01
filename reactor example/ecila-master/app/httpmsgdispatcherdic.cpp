#include "httpmsgdispatcherdic.h"


//http msg dispatcher
#include "httpmsgindex.h"
#include "httpmsgnotfound.h"









HttpMsgDispatcherDic::HttpMsgDispatcherDic()
{
}








HttpMsgDispatcherDic::~HttpMsgDispatcherDic()
{
	for(ITER_T iter = map_.begin(); iter != map_.end(); ++iter)
	{
		IHttpMsgDispatcher *d = iter->second;
		ECILA_SAFE_DELETE(d);
	}
	map_.clear();
}








bool_t HttpMsgDispatcherDic::Load(NS_ECILA::Node *root)
{
	map_["/"]          = new HttpMsgIndex();
	map_["/index"]     = new HttpMsgIndex();
	map_["/not_found"] = new HttpMsgNotFound();


	for(ITER_T iter = map_.begin(); iter != map_.end(); ++iter)
	{
		IHttpMsgDispatcher *d = iter->second;

		d->Initialize(root);
		d->CacheNode();
	}

	return TRUE;
}








IHttpMsgDispatcher* HttpMsgDispatcherDic::Find(const char_t* uri)
{
	ITER_T iter = map_.find(uri);
	if(iter == map_.end()) { return map_["/not_found"]; }

	return iter->second;
}
