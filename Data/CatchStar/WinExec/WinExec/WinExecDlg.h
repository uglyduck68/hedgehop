
// WinExecDlg.h : ��� ����
//

#pragma once

#define		MAX_PROCESS		100
#define		CLOSEHANDLE(h)	CloseHandle(h); h = NULL



// CWinExecDlg ��ȭ ����
class CWinExecDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CWinExecDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_WINEXEC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_nRunCount;
	CString m_strProcessPath;
	afx_msg void OnBnClicked_Run();
	afx_msg void OnBnClicked_SelectProcess();
	CString m_strArguments;

	PROCESS_INFORMATION		PI[MAX_PROCESS];
	STARTUPINFO				SI[MAX_PROCESS];

	afx_msg void OnBnClickedOk();

	void	CloseAllHandles();
	void	Init();
};
