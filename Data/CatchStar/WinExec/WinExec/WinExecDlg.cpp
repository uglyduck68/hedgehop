
// WinExecDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "WinExec.h"
#include "WinExecDlg.h"
#include "afxdialogex.h"

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


// CWinExecDlg 대화 상자




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


// CWinExecDlg 메시지 처리기

BOOL CWinExecDlg::OnInitDialog()
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
	Init();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CWinExecDlg::OnPaint()
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
