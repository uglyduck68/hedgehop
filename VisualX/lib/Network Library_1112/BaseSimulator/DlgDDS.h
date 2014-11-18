#pragma once


// CDlgDDS 대화 상자입니다.

class CDlgDDS : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgDDS)

public:
	CDlgDDS(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgDDS();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_DDS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
