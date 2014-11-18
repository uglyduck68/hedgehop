// DlgEthernet.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "BaseSimulator.h"
#include "DlgEthernet.h"
#include "afxdialogex.h"

// CDlgEthernet ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgEthernet, CDialogEx)
CDlgEthernet::CDlgEthernet(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgEthernet::IDD, pParent)
{

}

CDlgEthernet::~CDlgEthernet()
{
}
// CDlgEthernet �޽��� ó�����Դϴ�.

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
	// ȣ��Ʈ���� ���ͳݿ� ����Ǿ� �ִ� IP �ּҸ� �����´�.
	// ȣ��Ʈ�� ����� IP �ּ� �߿��� default gw �� ������ ��Ʈ��ũ�� �����ϴ� IP �ּҸ� ã�Ƴ���.
	std::vector<DWORD> ips;

	DWORD size = 0;
	int ret = GetAdaptersInfo( NULL, &size);

	// Allocate memory from sizing information

	IP_ADAPTER_INFO *pAdapterInfo = (IP_ADAPTER_INFO *)malloc (size);

	// Get actual adapter information
#pragma comment(lib,"Iphlpapi.lib") // Library Loading GetAdaptersInfo �� ����ϱ� ���ؼ� Iphlpapi.lib�� �ʿ��ϴ�.
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

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
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
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CDlgEthernet::SetConnectionMode(int mode)
{
	m_mode = mode;
	GetDlgItem (IDC_COMBO_LOCAL_IP) ->EnableWindow ( (mode != 2) ? TRUE : FALSE);	// 0-UDP, 1-TCP Server���� Ȱ��ȭ
	GetDlgItem (IDC_IPADDRESS_DEST) ->EnableWindow ( (mode != 1) ? TRUE : FALSE);	// 0-UDP, 2-TCP Client���� Ȱ��ȭ
	GetDlgItem (IDC_CHECK_BROADCAST)->EnableWindow ( (mode == 0) ? TRUE : FALSE);	// 0-UDP���� Ȱ��ȭ
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (IsDlgButtonChecked (IDC_CHECK_BROADCAST) == BST_CHECKED) {
		remoteIpAddrCtl.SetAddress (INADDR_BROADCAST);
		remoteIpAddrCtl.EnableWindow (FALSE);
	}
	else {
		remoteIpAddrCtl.EnableWindow (TRUE);
	}
}
