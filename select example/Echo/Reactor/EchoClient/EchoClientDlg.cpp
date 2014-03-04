
// EchoClientDlg.cpp : ���� ����
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


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CEchoClientDlg ��ȭ ����




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


// CEchoClientDlg �޽��� ó����

BOOL CEchoClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CEchoClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	Fin();
	CDialogEx::OnCancel();
}


void CEchoClientDlg::OnOK()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	Fin();

	CDialogEx::OnOK();
}
