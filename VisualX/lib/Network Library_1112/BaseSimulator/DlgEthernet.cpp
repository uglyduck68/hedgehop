// DlgEthernet.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "BaseSimulator.h"
#include "DlgEthernet.h"
#include "afxdialogex.h"

// CDlgEthernet 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgEthernet, CDialogEx)
CDlgEthernet::CDlgEthernet(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgEthernet::IDD, pParent)
{

}

CDlgEthernet::~CDlgEthernet()
{
}
// CDlgEthernet 메시지 처리기입니다.

void CDlgEthernet::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_IPADDRESS_DEST, remoteIpAddrCtl);
}


BEGIN_MESSAGE_MAP(CDlgEthernet, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgEthernet::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_BROADCAST, &CDlgEthernet::OnBnClickedCheckBroadcast)
END_MESSAGE_MAP()

std::vector<DWORD> GetHostIPAddress()
{
	// 호스트에서 인터넷에 연결되어 있는 IP 주소를 가져온다.
	// 호스트에 연결된 IP 주소 중에서 default gw 와 동일한 네트워크에 존재하는 IP 주소를 찾아낸다.
	std::vector<DWORD> ips;

	DWORD size = 0;
	int ret = GetAdaptersInfo( NULL, &size);

	// Allocate memory from sizing information

	IP_ADAPTER_INFO *pAdapterInfo = (IP_ADAPTER_INFO *)malloc (size);

	// Get actual adapter information
#pragma comment(lib,"Iphlpapi.lib") // Library Loading GetAdaptersInfo 를 사용하기 위해선 Iphlpapi.lib가 필요하다.
	ret = GetAdaptersInfo(pAdapterInfo, &size);
	if (ret) {
		free (pAdapterInfo);
		return ips;
	}

	for (IP_ADAPTER_INFO *pAdapt = pAdapterInfo; pAdapt; pAdapt = pAdapt->Next) {
		//if (pAdapt->Type == MIB_IF_TYPE_ETHERNET) {
		DWORD dwGwIp = inet_addr( pAdapt->GatewayList.IpAddress.String );
		TRACE ("Gateway IP Address = %s\n", pAdapt->GatewayList.IpAddress.String);
		TRACE ("Gateway IP Address = %d\n",dwGwIp);
		for (PIP_ADDR_STRING pAddrStr = &(pAdapt->IpAddressList); pAddrStr; pAddrStr = pAddrStr->Next ) {
			ips.push_back (inet_addr (pAddrStr->IpAddress.String));

			TRACE ("    Local IP Address = %s\n", pAddrStr->IpAddress.String);
		}
		//}
	}
	free (pAdapterInfo);
	return ips;
}
BOOL CDlgEthernet::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	if(m_mode == 0){
//		remoteIpAddrCtl.SetAddress (GetIpAddress(g_Setting.udp_ip));
//		SetDlgItemInt (IDC_EDIT_DEST_PORT,g_Setting.udp_port, FALSE);
	}else{
//		remoteIpAddrCtl.SetAddress (GetIpAddress(g_Setting.tcp_ip));
//		SetDlgItemInt (IDC_EDIT_DEST_PORT,g_Setting.tcp_port, FALSE);

	}
	std::vector<DWORD> host_ip = GetHostIPAddress();

	SendDlgItemMessage (IDC_COMBO_LOCAL_IP, CB_INSERTSTRING, 0, (LPARAM)"0.0.0.0");			// INADDR_ANY
	SendDlgItemMessage (IDC_COMBO_LOCAL_IP, CB_INSERTSTRING, 1, (LPARAM)"127.0.0.1");	// INADDR_LOOPBACK

	int sel = 0;
	if (localIpAddr == INADDR_ANY)      sel = 0;
	if (localIpAddr == INADDR_LOOPBACK) sel = 1;

	int count = 2;
	for (int i=0; i<(int)host_ip.size(); i++) {
		DWORD ip = ntohl(host_ip[i]);
		if (ip != INADDR_ANY && ip != INADDR_LOOPBACK) { 
	//		SendDlgItemMessage (IDC_COMBO_LOCAL_IP, CB_INSERTSTRING, count, (LPARAM)ip_addr_str(ip).c_str());
			if (localIpAddr == ip) sel = count;
			count++;
		}
	}
	SendDlgItemMessage (IDC_COMBO_LOCAL_IP, CB_SETCURSEL, sel);

	//CheckDlgButton (IDC_CHECK_BROADCAST, (GetIpAddress(g_Setting.udp_ip) == INADDR_BROADCAST) ? BST_CHECKED : BST_UNCHECKED);
	OnBnClickedCheckBroadcast();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlgEthernet::SetConnectionMode(int mode)
{
	m_mode = mode;
	GetDlgItem (IDC_COMBO_LOCAL_IP) ->EnableWindow ( (mode != 2) ? TRUE : FALSE);	// 0-UDP, 1-TCP Server에서 활성화
	GetDlgItem (IDC_IPADDRESS_DEST) ->EnableWindow ( (mode != 1) ? TRUE : FALSE);	// 0-UDP, 2-TCP Client에서 활성화
	GetDlgItem (IDC_CHECK_BROADCAST)->EnableWindow ( (mode == 0) ? TRUE : FALSE);	// 0-UDP에서 활성화
	GetDlgItem (IDC_EDIT_DEST_PORT) ->EnableWindow (TRUE);
}


void CDlgEthernet::OnBnClickedOk()
{
	CString buff;
	GetDlgItemText (IDC_COMBO_LOCAL_IP, buff);

//	g_Setting.udp_ip = buff;
//	g_Setting.tcp_ip = buff;
	if(m_mode == 0)
	{
//		g_Setting.udp_port = (unsigned short)GetDlgItemInt (IDC_EDIT_DEST_PORT, FALSE);
	}else{
//		g_Setting.tcp_port = (unsigned short)GetDlgItemInt (IDC_EDIT_DEST_PORT, FALSE);
	}
//	remoteIpAddr = GetIpAddress(g_Setting.tcp_ip);
	remoteIpAddrCtl.GetAddress ((DWORD&)remoteIpAddr);

	OnOK();
}
void CDlgEthernet::OnBnClickedCheckBroadcast()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (IsDlgButtonChecked (IDC_CHECK_BROADCAST) == BST_CHECKED) {
		remoteIpAddrCtl.SetAddress (INADDR_BROADCAST);
		remoteIpAddrCtl.EnableWindow (FALSE);
	}
	else {
		remoteIpAddrCtl.EnableWindow (TRUE);
	}
}
