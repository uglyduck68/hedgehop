#pragma once
#include "afxcmn.h"


// CDlgEthernet 대화 상자입니다.
class CDlgEthernet : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgEthernet)

public:
	CDlgEthernet(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgEthernet();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_ETHERNET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
