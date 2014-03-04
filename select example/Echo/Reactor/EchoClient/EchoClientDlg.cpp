
// EchoClientDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "EchoClient.h"
#include "EchoClientDlg.h"
#include "afxdialogex.h"

#include "ace/INET_Addr.h"
#include "ace/SOCK_Stream.h"
#include "ace/Sock_Connect.h"
#include "ace/Reactor.h"
#include "ace\Thread_Manager.h" 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CEchoClientDlg 대화 상자




CEchoClientDlg::CEchoClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEchoClientDlg::IDD, pParent)
	, m_dwIP(2130706433)	// 127.0.0.1
	, m_nPort(8000)
	, m_strMsg(_T("Hi! Are You OK? Winner takes all as you know"))
	, m_bAuto(FALSE)
	, m_nDuration(0)
	, m_bConnect(FALSE)
	, m_bTimer(FALSE)
	, m_nTimerID(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEchoClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_IPAddress(pDX, IDC_IPADDRESS_SVR, m_dwIP);
	DDX_Text(pDX, IDC_EDIT_PORT, m_nPort);
	DDX_Text(pDX, IDC_EDIT_MSG, m_strMsg);
	DDV_MaxChars(pDX, m_strMsg, 1000);
	DDX_Check(pDX, IDC_CHECK_AUTO, m_bAuto);
	DDX_Text(pDX, IDC_EDIT_DURATION, m_nDuration);
	DDV_MinMaxInt(pDX, m_nDuration, 0, 60);
}

BEGIN_MESSAGE_MAP(CEchoClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CEchoClientDlg::OnBnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CEchoClientDlg::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDC_CHECK_AUTO, &CEchoClientDlg::OnBnClickedCheckAuto)
END_MESSAGE_MAP()


// CEchoClientDlg 메시지 처리기

BOOL CEchoClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CEchoClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CEchoClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CEchoClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/**
* reactor loop
*/

static ACE_THR_FUNC_RETURN reactor_loop (void *arg) 
{ 
	ACE_TRACE("enter reactor_loop");
	
	ACE_Reactor::instance ()->run_reactor_event_loop ();

	return 0; 
}

void CEchoClientDlg::OnBnClickedButtonConnect()
{
	UpdateData();

	TRACE("m_dwIP: %d\n", m_dwIP);

	ACE_INET_Addr		addr(m_nPort, m_dwIP);

	if (m_Connector.connect(m_Sock, addr) == -1)
	{
		AfxMessageBox("fail to connect");

		return;
	}

	m_bConnect	= TRUE;

	//MyTimerHandler*		pTimer	= new MyTimerHandler();
	//ACE_Time_Value		InitialDelay(1);	// 1 sec
	//ACE_Time_Value		Interval(3);		// 1 sec

	//m_nTimerID	= ACE_Reactor::instance()->schedule_timer(pTimer, 0, InitialDelay, Interval);

	ACE_Thread_Manager::instance()->spawn_n (1, reactor_loop, NULL);
}

void CALLBACK lpfnTimer(HWND, UINT, UINT, DWORD)
{
	((CEchoClientDlg*)AfxGetMainWnd())->OnBnClickedButtonSend();
}

void CEchoClientDlg::OnBnClickedButtonSend()
{
	UpdateData();

	if (m_bConnect)
	{
		m_Sock.send_n(m_strMsg, m_strMsg.GetLength());

		if (m_bAuto && m_nDuration > 0 && m_bTimer == FALSE)
		{
			/**
			* register timer
			*/

			SetTimer(1, m_nDuration, lpfnTimer);

			// timer is registered
			m_bTimer	= TRUE;
		}
	}
	else
	{
		AfxMessageBox("Info: You must connect first");
	}
}


void CEchoClientDlg::OnBnClickedCheckAuto()
{
	UpdateData();

}


void CEchoClientDlg::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	Fin();
	CDialogEx::OnCancel();
}


void CEchoClientDlg::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	Fin();

	CDialogEx::OnOK();
}
