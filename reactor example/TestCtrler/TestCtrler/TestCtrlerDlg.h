
// TestCtrlerDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CTestCtrlerDlg ��ȭ ����
class CTestCtrlerDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CTestCtrlerDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TESTCTRLER_DIALOG };

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
	CString m_TestDuration;
	CString m_TestPayload;
	CRichEditCtrl m_CtrlTestList;
};
