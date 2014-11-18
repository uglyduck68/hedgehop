#pragma once
#include "afxcmn.h"


// CDlgEthernet ��ȭ �����Դϴ�.
class CDlgEthernet : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgEthernet)

public:
	CDlgEthernet(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgEthernet();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_ETHERNET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CIPAddressCtrl remoteIpAddrCtl;
	unsigned long remoteIpAddr;
	unsigned long localIpAddr;
	unsigned long portNum;
	virtual BOOL OnInitDialog();
	void SetConnectionMode(int mode);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheckBroadcast();
private:
	int m_mode;
};
