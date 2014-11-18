
// LocationDlg.h : ��� ����
//

#pragma once

#include "NetworkMgr.h"

// CLocationDlg ��ȭ ����
class CLocationDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CLocationDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_LOCATION_DIALOG };

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
	afx_msg void OnBnClickedButton1();
private:
	CNetworkMgr Mgr;
public:
	afx_msg void OnNcDestroy();
};
