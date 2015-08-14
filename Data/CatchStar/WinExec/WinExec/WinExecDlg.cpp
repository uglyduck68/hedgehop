
// WinExecDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "WinExec.h"
#include "WinExecDlg.h"
#include "afxdialogex.h"

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


// CWinExecDlg ��ȭ ����




CWinExecDlg::CWinExecDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWinExecDlg::IDD, pParent)
	, m_nRunCount(1)
	, m_strProcessPath(_T(""))
	, m_strArguments(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWinExecDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_nRunCount);
	DDV_MinMaxInt(pDX, m_nRunCount, 1, MAX_PROCESS);
	DDX_Text(pDX, IDC_EDIT1, m_strProcessPath);
	DDX_Text(pDX, IDC_EDIT3, m_strArguments);
}

BEGIN_MESSAGE_MAP(CWinExecDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CWinExecDlg::OnBnClicked_Run)
	ON_BN_CLICKED(IDC_BUTTON1, &CWinExecDlg::OnBnClicked_SelectProcess)
	ON_BN_CLICKED(IDOK, &CWinExecDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CWinExecDlg �޽��� ó����

BOOL CWinExecDlg::OnInitDialog()
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
	Init();

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CWinExecDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWinExecDlg::OnPaint()
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
HCURSOR CWinExecDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWinExecDlg::OnBnClicked_Run()
{
	CloseAllHandles();

	char		strExec[MAX_PATH];//	= m_strProcessPath + m_strArguments;
	int			nRet	= 0;

	sprintf(strExec, "%s %s", (LPCTSTR)m_strProcessPath, (LPCTSTR)m_strArguments);

	UpdateData();

	for( int i = 0; i < m_nRunCount; i++ )
	{
		memset(&PI[i], 0x00, sizeof(PROCESS_INFORMATION));
		memset(&SI[i], 0x00, sizeof(STARTUPINFO));

		SI[i].cb			= sizeof(STARTUPINFO);
		SI[i].dwFlags		= STARTF_USEPOSITION | STARTF_USESIZE | STARTF_USESTDHANDLES;
		SI[i].dwX			= i;
		SI[i].dwY			= i;
		SI[i].dwXSize		= 100;
		SI[i].dwYSize		= 100;
		SI[i].wShowWindow	= SW_SHOW;

//		if( (nRet = WinExec(strExec, TRUE)) <= 31 )
		if( (nRet = CreateProcess(NULL, strExec, NULL, NULL, TRUE, CREATE_NEW_CONSOLE /*| DETACHED_PROCESS*/, NULL, NULL, &SI[i], &PI[i])) == 0/*<= 31*/ )
		{
			// fail
			CString		strError;

			strError.Format("Error: fail to exec \"%s\": %d", (LPCTSTR)strExec, GetLastError() );

			//switch(nRet)
			//{
			//case 0:
			//	strError.Format("Error: fail to exec %s: cause is out of memory", (LPCTSTR)strExec);
			//	break;
			//case ERROR_BAD_FORMAT:
			//	strError.Format("Error: fail to exec %s: cause is .exe is invalid", (LPCTSTR)strExec);
			//	break;
			//case ERROR_FILE_NOT_FOUND:
			//case ERROR_PATH_NOT_FOUND:
			//	strError.Format("Error: fail to exec %s: cause is file or path not found", (LPCTSTR)strExec);
			//	break;
			//default:
			//	break;
			//}

			AfxMessageBox(strError);
		}
	}
}


void CWinExecDlg::OnBnClicked_SelectProcess()
{
	TCHAR szFilters[]= _T("Exe Files (*.exe)|*.exe|All Files (*.*)|*.*||");


	CFileDialog		dlgFile(TRUE, _T("Exe"), _T("*.exe"), OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters);

	CString fileName;
	const int c_cMaxFiles = 100;
	const int c_cbBuffSize = (c_cMaxFiles * (MAX_PATH + 1)) + 1;
	dlgFile.GetOFN().lpstrFile = fileName.GetBuffer(c_cbBuffSize);
	dlgFile.GetOFN().nMaxFile = c_cbBuffSize;

	if (dlgFile.DoModal() == IDOK )
	{
		m_strProcessPath	= dlgFile.GetPathName();

		UpdateData(FALSE);
	}

	fileName.ReleaseBuffer();
}

void CWinExecDlg::Init()
{
	for( int i = 0; i < MAX_PROCESS; i++ )
	{
		memset(&PI[i], 0x00, sizeof(PROCESS_INFORMATION));
		memset(&SI[i], 0x00, sizeof(STARTUPINFO));
	}
}

void CWinExecDlg::CloseAllHandles()
{
	for( int i = 0; i < MAX_PROCESS; i++ )
	{
		if( PI[i].dwProcessId != NULL )
		{
			CLOSEHANDLE(SI[i].hStdError);
			CLOSEHANDLE(SI[i].hStdInput);
			CLOSEHANDLE(SI[i].hStdOutput);

			CLOSEHANDLE(PI[i].hProcess);
			CLOSEHANDLE(PI[i].hThread);

			memset(&PI[i], 0x00, sizeof(PROCESS_INFORMATION));
			memset(&SI[i], 0x00, sizeof(STARTUPINFO));
		}
	}
}

void CWinExecDlg::OnBnClickedOk()
{
	CloseAllHandles();

	CDialogEx::OnOK();
}
