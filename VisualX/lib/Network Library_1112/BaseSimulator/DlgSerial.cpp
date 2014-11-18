m_Ini
// DlgSerial.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "BaseSimulator.h"
#include "DlgSerial.h"
#include "afxdialogex.h"
static int _comSpeed[] = { 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200, 230400, 460800, 921600 };
int GetComSpeedIndex(int value)
{
	for (int i=0; i<sizeof(_comSpeed)/sizeof(int); i++) {
		if (_comSpeed[i] == value) return i;
	}
	return 7;	// 115200
}

int GetComSpeedValue(int index)
{
	if (0 <= index && index < sizeof(_comSpeed)/sizeof(int)) {
		return _comSpeed[index];
	}
	return _comSpeed[7];	// 115200
}

// CDlgSerial ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgSerial, CDialogEx)

CDlgSerial::CDlgSerial(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgSerial::IDD, pParent)
{

}

CDlgSerial::~CDlgSerial()
{
}

void CDlgSerial::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgSerial, CDialogEx)
END_MESSAGE_MAP()


// CDlgSerial �޽��� ó�����Դϴ�.

BOOL CDlgSerial::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	SendDlgItemMessage (IDC_COMBO_PORT, CB_INITSTORAGE, 10, 100);
	SendDlgItemMessage (IDC_COMBO_PORT,  WM_SETREDRAW, 0, 0);
	for (int i=0; i<256; i++) {
		char name[MAX_PATH];
		sprintf_s (name,sizeof(name), "\\\\.\\COM%d", i);

		HANDLE h = CreateFile (name, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
		if (h != INVALID_HANDLE_VALUE){
			CloseHandle (h);

			SendDlgItemMessage (IDC_COMBO_PORT, CB_ADDSTRING, 0, (LPARAM)name);
		}
	}
/*
	SetDlgItemText (IDC_COMBO_PORT, g_Setting.serial_port.c_str());
	SendDlgItemMessage (IDC_COMBO_PORT,  WM_SETREDRAW, 1, 0);

	SendDlgItemMessage (IDC_COMBO_BPS,		CB_SETCURSEL, GetComSpeedIndex(g_Setting.baudRate));
	SendDlgItemMessage (IDC_COMBO_DATABITS, CB_SETCURSEL, g_Setting.dataBits - 5);
	SendDlgItemMessage (IDC_COMBO_PARITY,	CB_SETCURSEL, g_Setting.parity);
	SendDlgItemMessage (IDC_COMBO_STOPBITS, CB_SETCURSEL, g_Setting.stopBits);
	SendDlgItemMessage (IDC_COMBO_FLOWCTL,	CB_SETCURSEL, g_Setting.flowCtrl);*/
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgSerial::OnBnClickedOk()
{
/*
	g_Setting.baudRate = GetComSpeedValue(SendDlgItemMessage(IDC_COMBO_BPS,CB_GETCURSEL));
	g_Setting.dataBits		= (unsigned char)(5 + SendDlgItemMessage (IDC_COMBO_DATABITS, CB_GETCURSEL));
	g_Setting.parity		= (unsigned char)(SendDlgItemMessage (IDC_COMBO_PARITY,	CB_GETCURSEL)); 
	g_Setting.stopBits		= (unsigned char)(SendDlgItemMessage (IDC_COMBO_STOPBITS, CB_GETCURSEL)); 
	g_Setting.flowCtrl	= (unsigned char)(SendDlgItemMessage (IDC_COMBO_FLOWCTL, CB_GETCURSEL)); */

	OnOK();
}