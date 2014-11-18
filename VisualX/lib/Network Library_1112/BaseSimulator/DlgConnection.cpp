// DlgConnection.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "BaseSimulator.h"
#include "DlgConnection.h"
#include "afxdialogex.h"


// CDlgConnection 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgConnection, CDialogEx)

CDlgConnection::CDlgConnection(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgConnection::IDD, pParent),dlgEthernet(this),dlgSerial(this),dlgDDS(this)
{

}

CDlgConnection::~CDlgConnection()
{
}

void CDlgConnection::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgConnection, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgConnection::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgConnection::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_RADIO_COM, &CDlgConnection::OnBnClickedRadioCom)
	ON_BN_CLICKED(IDC_RADIO_TCPC, &CDlgConnection::OnBnClickedRadioTcpc)
	ON_BN_CLICKED(IDC_RADIO_TCPS, &CDlgConnection::OnBnClickedRadioTcps)
	ON_BN_CLICKED(IDC_RADIO_UDP, &CDlgConnection::OnBnClickedRadioUdp)
	ON_BN_CLICKED(IDC_RADIO_DDS, &CDlgConnection::OnBnClickedRadioDds)
END_MESSAGE_MAP()


// CDlgConnection 메시지 처리기입니다.


void CDlgConnection::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	dlgDDS.OnBnClickedOk();
	dlgEthernet.OnBnClickedOk();
	dlgSerial.OnBnClickedOk();
	CDialogEx::OnOK();
}


void CDlgConnection::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void CDlgConnection::OnBnClickedRadioCom()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnBnClickedRadio();
}


void CDlgConnection::OnBnClickedRadioTcpc()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnBnClickedRadio();
}


void CDlgConnection::OnBnClickedRadioTcps()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnBnClickedRadio();
}


void CDlgConnection::OnBnClickedRadioUdp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnBnClickedRadio();
}


void CDlgConnection::OnBnClickedRadioDds()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnBnClickedRadio();
}

void CDlgConnection::OnBnClickedRadio()
{
	if      (IsDlgButtonChecked (IDC_RADIO_UDP )  == BST_CHECKED) m_NetType = CONNECTION_UDP ;
	else if (IsDlgButtonChecked (IDC_RADIO_TCPS)  == BST_CHECKED) m_NetType = CONNECTION_TCPS;
	else if (IsDlgButtonChecked (IDC_RADIO_TCPC)  == BST_CHECKED) m_NetType = CONNECTION_TCPC;
	else if (IsDlgButtonChecked (IDC_RADIO_COM )  == BST_CHECKED) m_NetType = CONNECTION_COM ;
	else if (IsDlgButtonChecked (IDC_RADIO_DDS )  == BST_CHECKED) m_NetType = CONNECTION_DDS ;

	switch (m_NetType) {
	case CONNECTION_UDP : dlgDDS.ShowWindow (SW_HIDE); dlgSerial.ShowWindow (SW_HIDE); dlgEthernet.ShowWindow (SW_SHOW); break;
	case CONNECTION_TCPS: dlgDDS.ShowWindow (SW_HIDE); dlgSerial.ShowWindow (SW_HIDE); dlgEthernet.ShowWindow (SW_SHOW); break;
	case CONNECTION_TCPC: dlgDDS.ShowWindow (SW_HIDE); dlgSerial.ShowWindow (SW_HIDE); dlgEthernet.ShowWindow (SW_SHOW); break;
	case CONNECTION_COM : dlgDDS.ShowWindow (SW_HIDE); dlgSerial.ShowWindow (SW_SHOW); dlgEthernet.ShowWindow (SW_HIDE); break;
	case CONNECTION_DDS : dlgDDS.ShowWindow (SW_SHOW); dlgSerial.ShowWindow (SW_HIDE); dlgEthernet.ShowWindow (SW_HIDE); break;
	}
	dlgEthernet.SetConnectionMode (m_NetType); 
}
BOOL CDlgConnection::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//
	dlgSerial.Create (IDD_DIALOG_SERIAL, this);
	dlgSerial.SetWindowPos (NULL, 2, 52, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	dlgSerial.ShowWindow (SW_HIDE);

	dlgEthernet.Create (IDD_DIALOG_ETHERNET, this);
	dlgEthernet.SetWindowPos (NULL, 2, 52, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	dlgEthernet.ShowWindow (SW_HIDE);


	dlgDDS.Create (IDD_DIALOG_DDS, this);
	dlgDDS.SetWindowPos (NULL, 2, 52, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	dlgDDS.ShowWindow (SW_HIDE);


	CheckDlgButton (IDC_RADIO_UDP,  (m_NetType == CONNECTION_UDP ) ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_RADIO_TCPS, (m_NetType == CONNECTION_TCPS) ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_RADIO_TCPC, (m_NetType == CONNECTION_TCPC) ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_RADIO_COM,  (m_NetType == CONNECTION_COM ) ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_RADIO_DDS,  (m_NetType == CONNECTION_DDS ) ? BST_CHECKED : BST_UNCHECKED);

	OnBnClickedRadio ();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}