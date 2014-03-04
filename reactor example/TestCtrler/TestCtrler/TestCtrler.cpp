
// TestCtrler.cpp : 응용 프로그램에 대한 클래스 동작을 정의합니다.
//

#include "stdafx.h"
#include "TestCtrler.h"
#include "TestCtrlerDlg.h"

#include "ace\Select_Reactor.h"
#include "ace\TP_Reactor.h"
#include "ace\Thread_Manager.h" 
#include "Option.h"
#include "Error.h"
#include "Admin.h"
#include "MyAcceptor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


/**
 * ACE reactor setting
 */
ACE_Select_Reactor*		g_pSelectReactor	= NULL;
ACE_TP_Reactor*			g_pTPReactor		= NULL;



CAdmin*					mAdmin;

static ACE_THR_FUNC_RETURN event_acceptor_loop (void *arg) 
{ 
	ACE_TRACE("enter event_accoptor_loop");
	
	ACE_Reactor *reactor = static_cast<ACE_Reactor *>(arg); 
	
	reactor->owner (ACE_OS::thr_self ()); 
	reactor->run_reactor_event_loop (); 

	return 0; 
} 

// CTestCtrlerApp

BEGIN_MESSAGE_MAP(CTestCtrlerApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CTestCtrlerApp 생성

CTestCtrlerApp::CTestCtrlerApp()
{
	// 다시 시작 관리자 지원
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CTestCtrlerApp 개체입니다.

CTestCtrlerApp theApp;

Option			g_Option;

// CTestCtrlerApp 초기화

BOOL CTestCtrlerApp::InitInstance()
{
//TODO: call AfxInitRichEdit2() to initialize richedit2 library.
	AfxInitRichEdit2();
	// 응용 프로그램 매니페스트가 ComCtl32.dll 버전 6 이상을 사용하여 비주얼 스타일을
	// 사용하도록 지정하는 경우, Windows XP 상에서 반드시 InitCommonControlsEx()가 필요합니다.
	// InitCommonControlsEx()를 사용하지 않으면 창을 만들 수 없습니다.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 응용 프로그램에서 사용할 모든 공용 컨트롤 클래스를 포함하도록
	// 이 항목을 설정하십시오.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;

	/**
	* VisualStudio2010에서 아래 명령이 웬지 오류를 일으킨다. 단지 특정 소스를 컴파일만 한 경우에도..희안하다.
	*/
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 대화 상자에 셸 트리 뷰 또는
	// 셸 목록 뷰 컨트롤이 포함되어 있는 경우 셸 관리자를 만듭니다.
	CShellManager *pShellManager = new CShellManager;

	// 표준 초기화
	// 이들 기능을 사용하지 않고 최종 실행 파일의 크기를 줄이려면
	// 아래에서 필요 없는 특정 초기화
	// 루틴을 제거해야 합니다.
	// 해당 설정이 저장된 레지스트리 키를 변경하십시오.
	// TODO: 이 문자열을 회사 또는 조직의 이름과 같은
	// 적절한 내용으로 수정해야 합니다.
	SetRegistryKey(_T("로컬 응용 프로그램 마법사에서 생성된 응용 프로그램"));

	/**
	* winsock & ACE initialization
	*/
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2,2), &WSAData);

	ACE::init();

	try
	{
//		g_pSelectReactor	= new ACE_Select_Reactor;
		g_pTPReactor		= new ACE_TP_Reactor;
	}
	catch(...)
	{
		return FALSE;
	}

	ACE_Reactor				g_Reactor(g_pTPReactor);

	/**
	* read test configureation for clients
	*/
	char	IniPath[MAX_PATH];

	GetCurrentDirectory(MAX_PATH, IniPath);

	strcat(IniPath, "\\TestCtrler.ini");

	// setup configuration
	if (g_Option.LoadConfiguration(IniPath) != 0)
	{
		AfxMessageBox(Error::Get());
		return -1;
	}

	mAdmin	= new CAdmin;
    mAdmin->SetReactor(&g_Reactor);


	CMyAcceptor* mAcceptor;
	mAcceptor	= new CMyAcceptor;

	mAcceptor->open("127.0.0.1:8000");
	mAcceptor->SetReactor(&g_Reactor);
		
	int		nGrpID;

	assert(ACE_Thread_Manager::instance() != NULL);
	nGrpID	= ACE_Thread_Manager::instance()->spawn_n (3, event_acceptor_loop, &g_Reactor);

	CTestCtrlerDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 여기에 [확인]을 클릭하여 대화 상자가 없어질 때 처리할
		//  코드를 배치합니다.
		g_Reactor.end_reactor_event_loop();		
		ACE_Thread_Manager::instance()->cancel_all();
	}
	else if (nResponse == IDCANCEL)
	{
		g_Reactor.end_reactor_event_loop();
		// TODO: 여기에 [취소]를 클릭하여 대화 상자가 없어질 때 처리할
		//  코드를 배치합니다.
	}

	// 위에서 만든 셸 관리자를 삭제합니다.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

//	delete g_pSelectReactor;
	delete g_pTPReactor;

	/**
	* winsock & ACE finalization
	*/
	ACE::fini();
	WSACleanup();

	// 대화 상자가 닫혔으므로 응용 프로그램의 메시지 펌프를 시작하지 않고  응용 프로그램을 끝낼 수 있도록 FALSE를
	// 반환합니다.
	return FALSE;
}

