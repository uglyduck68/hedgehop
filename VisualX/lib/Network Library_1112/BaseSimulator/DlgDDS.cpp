// DlgDDS.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "BaseSimulator.h"
#include "DlgDDS.h"
#include "afxdialogex.h"

// CDlgDDS ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgDDS, CDialogEx)

CDlgDDS::CDlgDDS(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgDDS::IDD, pParent)
{

}

CDlgDDS::~CDlgDDS()
{
}

void CDlgDDS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_DDS_DEST,remoteIpAddrCtl);
}


BEGIN_MESSAGE_MAP(CDlgDDS, CDialogEx)
END_MESSAGE_MAP()


// CDlgDDS �޽��� ó�����Դϴ�.


BOOL CDlgDDS::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//remoteIpAddrCtl.SetAddress(GetIpAddress("127.0.0.1"));
	SetDlgItemInt(IDC_EDIT_DDSDOMAIN,1,FALSE);
	SetDlgItemInt(IDC_EDIT_DDSIPCNT,1,FALSE);

	SendDlgItemMessage(IDC_COMBO_DDSQOS,CB_INSERTSTRING,0,(LPARAM)"Reliable");

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
void CDlgDDS::OnBnClickedOk()
{
	DWORD buf;
	remoteIpAddrCtl.GetAddress(buf);
	CString str;
	str.Format("%d.%d.%d.%d",
		(unsigned int)((buf>>24)&0xFF),
		(unsigned int)((buf>>16)&0xFF),
		(unsigned int)((buf>>8)&0xFF),
		(unsigned int)((buf>>0)&0xFF)
		);
// 	g_Setting.dds_ip = str;
// 	g_Setting.domain = (unsigned short)GetDlgItemInt(IDC_EDIT_DDSDOMAIN, FALSE);
// 	g_Setting.dds_cnt = (unsigned short)GetDlgItemInt(IDC_EDIT_DDSIPCNT, FALSE); 
//	GetDlgItemText(IDC_COMBO_DDSQOS,str);
// 	g_Setting.QOS_Type = str;

	OnOK();
}