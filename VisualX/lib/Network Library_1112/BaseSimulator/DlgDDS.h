#pragma once


// CDlgDDS ��ȭ �����Դϴ�.

class CDlgDDS : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgDDS)

public:
	CDlgDDS(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgDDS();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_DDS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CIPAddressCtrl remoteIpAddrCtl;
	unsigned long remoteIpAddr;
	unsigned long ipCnt;
	unsigned long domain;
	std::string QosType;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
