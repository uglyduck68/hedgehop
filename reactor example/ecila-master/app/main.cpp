#include "main.h"

#include <ecila/danodelist.h>

#include "packethandler.h"
#include "networktask.h"
#include "dispatchtask.h"


//dictionary
#include "httpmsgdispatcherdic.h"


#ifdef OS_WINDOWS
//google-breakpad (minidump)
#include "client/windows/handler/exception_handler.h"
#endif






US_ECILA

Main::Main()
:	pkt_handler_	(0),
	network_task_	(0),
	dispatch_task_	(0)
{
	pkt_handler_	= new PacketHandler();
	network_task_	= new NetworkTask();
	dispatch_task_	= new DispatchTask();

	svr_frame_		= new Server("../bin/cfg.ini");
}








Main::~Main()
{

	ECILA_SAFE_DELETE(svr_frame_);
	ECILA_SAFE_DELETE(pkt_handler_);
	ECILA_SAFE_DELETE(network_task_);
	ECILA_SAFE_DELETE(dispatch_task_);
}








void Main::Run()
{
	svr_frame_->Initialize(pkt_handler_, network_task_, dispatch_task_);


	InitDictionary();

	svr_frame_->RootNode()->Dump();
	svr_frame_->Start();
	svr_frame_->JoinAll();
}








bool_t Main::InitDictionary()
{
	bool_t ret = FALSE;

	//parent node
	Node *dictionary = svr_frame_->RootNode()->FindChild<Node>("dictionary");
	ECILA_ASSERT(dictionary);


	//http msg dispatcher dic
	HttpMsgDispatcherDic *httpd_dic = new HttpMsgDispatcherDic();
	svr_frame_->NodeList()->AddNode(httpd_dic);
	ret = httpd_dic->Load(svr_frame_->RootNode());
	if(!ret) { ECILA_TRACE(); return FALSE; }
	httpd_dic->Name("httpd_dic");
	ret = dictionary->Attach(httpd_dic);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return true;
}






#ifdef OS_WINDOWS
static bool callback(const wchar_t *dump_path,
	                 const wchar_t *id,
                     void *context,
					 EXCEPTION_POINTERS *exinfo,
					 MDRawAssertionInfo *assertion,
					 bool succeeded)
{
	if (succeeded)
	{
		printf("dump guid is %ws\n", id);
	}
	else
	{
		printf("dump failed\n");
	}
	
	fflush(stdout);

	return succeeded;
}
#endif








int32_t main(int32_t argc, char_t* argv[])
{
	#ifdef OS_WINDOWS
	google_breakpad::ExceptionHandler eh(L".", NULL, callback, NULL,
					google_breakpad::ExceptionHandler::HANDLER_ALL);
	#endif

	Main main;
	main.Run();

	return 0;
}

