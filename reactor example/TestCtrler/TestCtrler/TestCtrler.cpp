
// TestCtrler.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
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


// CTestCtrlerApp ����

CTestCtrlerApp::CTestCtrlerApp()
{
	// �ٽ� ���� ������ ����
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CTestCtrlerApp ��ü�Դϴ�.

CTestCtrlerApp theApp;

Option			g_Option;

// CTestCtrlerApp �ʱ�ȭ

BOOL CTestCtrlerApp::InitInstance()
{
//TODO: call AfxInitRichEdit2() to initialize richedit2 library.
	AfxInitRichEdit2();
	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControlsEx()�� �ʿ��մϴ�.
	// InitCommonControlsEx()�� ������� ������ â�� ���� �� �����ϴ�.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ���� ���α׷����� ����� ��� ���� ��Ʈ�� Ŭ������ �����ϵ���
	// �� �׸��� �����Ͻʽÿ�.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;

	/**
	* VisualStudio2010���� �Ʒ� ����� ���� ������ ����Ų��. ���� Ư�� �ҽ��� �����ϸ� �� ��쿡��..����ϴ�.
	*/
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ��ȭ ���ڿ� �� Ʈ�� �� �Ǵ�
	// �� ��� �� ��Ʈ���� ���ԵǾ� �ִ� ��� �� �����ڸ� ����ϴ�.
	CShellManager *pShellManager = new CShellManager;

	// ǥ�� �ʱ�ȭ
	// �̵� ����� ������� �ʰ� ���� ���� ������ ũ�⸦ ���̷���
	// �Ʒ����� �ʿ� ���� Ư�� �ʱ�ȭ
	// ��ƾ�� �����ؾ� �մϴ�.
	// �ش� ������ ����� ������Ʈ�� Ű�� �����Ͻʽÿ�.
	// TODO: �� ���ڿ��� ȸ�� �Ǵ� ������ �̸��� ����
	// ������ �������� �����ؾ� �մϴ�.
	SetRegistryKey(_T("���� ���� ���α׷� �����翡�� ������ ���� ���α׷�"));

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
		// TODO: ���⿡ [Ȯ��]�� Ŭ���Ͽ� ��ȭ ���ڰ� ������ �� ó����
		//  �ڵ带 ��ġ�մϴ�.
		g_Reactor.end_reactor_event_loop();		
		ACE_Thread_Manager::instance()->cancel_all();
	}
	else if (nResponse == IDCANCEL)
	{
		g_Reactor.end_reactor_event_loop();
		// TODO: ���⿡ [���]�� Ŭ���Ͽ� ��ȭ ���ڰ� ������ �� ó����
		//  �ڵ带 ��ġ�մϴ�.
	}

	// ������ ���� �� �����ڸ� �����մϴ�.
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

	// ��ȭ ���ڰ� �������Ƿ� ���� ���α׷��� �޽��� ������ �������� �ʰ�  ���� ���α׷��� ���� �� �ֵ��� FALSE��
	// ��ȯ�մϴ�.
	return FALSE;
}

