
// EchoSvrDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "EchoSvr.h"
#include "EchoSvrDlg.h"
#include "afxdialogex.h"

#include "ace/OS_NS_time.h"
#include "ace/Log_Msg.h"

#include "ace/Event_Handler.h"
#include "ace/Thread_Manager.h" 

#include "CpuUsage.h"

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


// CEchoSvrDlg ��ȭ ����




CEchoSvrDlg::CEchoSvrDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEchoSvrDlg::IDD, pParent)
	, m_nPort(8000)
	, m_nNumClient(0)
	, m_nCpuPercentage(0)
	, m_nBandwidth(0)
	, m_nTimerID(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEchoSvrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_PORT, m_nPort);
	DDX_Text(pDX, IDC_EDIT_NUM_CLIENTS, m_nNumClient);
	DDV_MinMaxInt(pDX, m_nNumClient, 0, 1024);
	DDX_Text(pDX, IDC_EDIT_CPU_PERCENT, m_nCpuPercentage);
	DDV_MinMaxFloat(pDX, m_nCpuPercentage, 0, 100);
	DDX_Text(pDX, IDC_EDIT_BANDWIDTH_PERCENT, m_nBandwidth);
	DDV_MinMaxFloat(pDX, m_nBandwidth, 0, 100);
	DDX_Control(pDX, IDC_EDIT_MSG, m_ctrlMsg);
}

BEGIN_MESSAGE_MAP(CEchoSvrDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_RUN, &CEchoSvrDlg::OnBnClickedButtonRun)
	ON_MESSAGE(WM_INC_CONNECTION, &CEchoSvrDlg::OnIncConnection)
	ON_MESSAGE(WM_DEC_CONNECTION, &CEchoSvrDlg::OnDecConnection)
	ON_MESSAGE(WM_PRINT_MESSAGE, &CEchoSvrDlg::OnPrintMessage)
	ON_MESSAGE(WM_USAGE, &CEchoSvrDlg::OnUsage)
END_MESSAGE_MAP()


// CEchoSvrDlg �޽��� ó����

BOOL CEchoSvrDlg::OnInitDialog()
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
	OnBnClickedButtonRun();

	PrintMsg("Start\n");

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CEchoSvrDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEchoSvrDlg::OnPaint()
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
HCURSOR CEchoSvrDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#define	MEGA	(1000000)

/**
* reactor timer But *NOT* works in MFC GUI
*/

class MyTimerHandler : public ACE_Event_Handler
{
public:
	int handle_timeout (const ACE_Time_Value &current_time,
		const void * = 0)
	{
		time_t epoch = ((timespec_t)current_time).tv_sec;

		float		nCpu	= m_cpu.GetCpuUsage();
		float		nBandwidth	= (m_cpu.GetBandwidth() * 8 * 100) / (100.0f*MEGA);

		AfxGetApp()->GetMainWnd()->SendMessage(WM_USAGE, (WPARAM)&nCpu, (LPARAM)&nBandwidth);
	char	caMsg[1024];

	sprintf(caMsg, "cpu: %f, bandwidth: %f\n", &nCpu, &nBandwidth);
	AfxGetApp()->GetMainWnd()->SendMessage(WM_PRINT_MESSAGE, 0U, (LPARAM)caMsg);
		return 0;
	}

	int	handle_close(ACE_HANDLE handle, ACE_Reactor_Mask close_mask)
	{
		return 0;
	}

protected:
	CCpuUsage	m_cpu;
};

static ACE_THR_FUNC_RETURN run_reactor_event_loop (void *arg) 
{ 
	ACE_TRACE("enter event_accoptor_loop");
	

	ACE_Reactor::instance ()->run_reactor_event_loop ();

	return 0; 
}

CCpuUsage	m_cpu;

void CALLBACK TimerCB(HWND, UINT, UINT, DWORD)
{
	float		nCpu		= m_cpu.GetCpuUsage();
	float		nBandwidth	= (m_cpu.GetBandwidth() * 8 * 100.0f) / (100.0f*MEGA);

	AfxGetApp()->GetMainWnd()->SendMessage(WM_USAGE, (WPARAM)&nCpu, (LPARAM)&nBandwidth);

#if	0
	char	caMsg[1024];

	sprintf(caMsg, "cpu: %f, bandwidth: %f\n", nCpu, nBandwidth);
	AfxGetApp()->GetMainWnd()->SendMessage(WM_PRINT_MESSAGE, 0U, (LPARAM)caMsg);
#endif
}

/**
* run echo server
*/
void CEchoSvrDlg::OnBnClickedButtonRun()
{
	UpdateData();

	ACE_INET_Addr	port_to_listen(m_nPort);

	m_Acceptor.reactor(ACE_Reactor::instance());

	if (m_Acceptor.open(port_to_listen) == -1)
	{
		AfxMessageBox("fail to open port");

		return;
	}

	// register timer callback with 3 sec period
	SetTimer(1, 3, TimerCB);

	m_nTimerID	= 1;

	/**
	* register reactor timer. 
	* In console mode this works well. But this timer don't work in MFC GUI.
	*/
	//MyTimerHandler*		pTimer	= new MyTimerHandler();
	//ACE_Time_Value		InitialDelay(1);	// 1 sec
	//ACE_Time_Value		Interval(3);		// 1 sec

	//m_nTimerID	= ACE_Reactor::instance()->schedule_timer(pTimer, 0, InitialDelay, Interval);


	// run reactor event loop
	ACE_Thread_Manager::instance()->spawn_n (1, run_reactor_event_loop, NULL);

}

int CEchoSvrDlg::GetTime(char* pcTime)
{
	SYSTEMTIME	st;

	GetLocalTime(&st);

	sprintf(pcTime, "[%4d-%02d-%02d %02d:%02d:%02d.%04d] ", 
		st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);

	return 1;
}

int	CEchoSvrDlg::PrintMsg(char* pcFmt, ...)
{
	char		caMsg[1024]	= {0,};
	va_list		args;

	// get current time
	GetTime(caMsg);

	va_start(args, pcFmt);

	_vsprintf_p(caMsg+strlen(caMsg), 1024, pcFmt, args);

	va_end(args);

	// print message to control
	int		nLen	= m_ctrlMsg.GetWindowTextLengthA();
	m_ctrlMsg.SetSel(nLen, nLen);
	m_ctrlMsg.ReplaceSel(caMsg);

	return 1;
}

afx_msg LRESULT CEchoSvrDlg::OnIncConnection(WPARAM wParam, LPARAM lParam)
{
	m_nNumClient++;
	UpdateData(FALSE);

	return 0;
}


afx_msg LRESULT CEchoSvrDlg::OnDecConnection(WPARAM wParam, LPARAM lParam)
{
	m_nNumClient--;
	UpdateData(FALSE);

	return 0;
}


afx_msg LRESULT CEchoSvrDlg::OnPrintMessage(WPARAM wParam, LPARAM lParam)
{
	PrintMsg((char*)lParam);

	return 0;
}


afx_msg LRESULT CEchoSvrDlg::OnUsage(WPARAM wParam, LPARAM lParam)
{
	if (0 <= *(float*)wParam && *(float*)wParam <= 100)
		m_nCpuPercentage	= *(float*)wParam;


	if (0 <= *(float*)lParam && *(float*)lParam <= 100)
		m_nBandwidth		= *(float*)lParam;

	UpdateData(FALSE);

	return 0;
}


void CEchoSvrDlg::OnCancel()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	Fin();

	CDialogEx::OnCancel();
}


void CEchoSvrDlg::OnOK()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	Fin();

	CDialogEx::OnOK();
}
