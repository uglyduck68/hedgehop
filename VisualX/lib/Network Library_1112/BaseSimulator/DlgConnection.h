#pragma once
#include "DlgSerial.h"
#include "DlgEthernet.h"
#include "DlgDDS.h"
// CDlgConnection 대화 상자입니다.

class CDlgConnection : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgConnection)

public:
	CDlgConnection(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgConnection();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_CONNECTION };

	/// 연결 타입 설정
	typedef enum {
		CONNECTION_UDP,
		CONNECTION_TCPS,
		CONNECTION_TCPC,
		CONNECTION_COM,
		CONNECTION_DDS,
	} CONNECTION_TYPE;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
private:
	CDlgSerial dlgSerial;
	CDlgEthernet dlgEthernet;
	CDlgDDS dlgDDS;

	void OnBnClickedRadio();
	CONNECTION_TYPE m_NetType;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedRadioCom();
	afx_msg void OnBnClickedRadioTcpc();
	afx_msg void OnBnClickedRadioTcps();
	afx_msg void OnBnClickedRadioUdp();
	afx_msg void OnBnClickedRadioDds();
	virtual BOOL OnInitDialog();
};
