
// EchoClientDlg.h : ��� ����
//

#pragma once

#include "ace/INET_Addr.h"
#include "ace/SOCK_Stream.h"
#include "ace/Sock_Connector.h"
#include "Client.h"
#include "afxwin.h"

#define	WM_PRINT_MESSAGE	WM_USER+1

// CEchoClientDlg ��ȭ ����
class CEchoClientDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CEchoClientDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

	~CEchoClientDlg()
	{
	}

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ECHOCLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonConnect();
	afx_msg void OnBnClickedButtonSend();
	DWORD m_dwIP;
	int m_nPort;
	CString m_strMsg;
	BOOL m_bAuto;
	int m_nDuration;

	BOOL					m_bConnect;
	BOOL					m_bTimer;	// 1: timer is registered
	ACE_Connector<Client, ACE_SOCK_CONNECTOR> connector;
	Client*					m_pClient;

	int						m_nTimerID;

	int	PrintMsg(char* pcFmt, ...);
	int GetTime(char* pcTime);

	afx_msg void OnBnClickedCheckAuto();

	void Fin()
	{
		if (m_bConnect)
			ACE_Reactor::instance()->end_reactor_event_loop();

		if (m_bTimer)
		{
			KillTimer(1);
		}

		if (m_pClient)
			delete m_pClient;
	}
	virtual void OnCancel();
	virtual void OnOK();
	// edit control that show send & received message

	// edit control that show send & received message
	CEdit m_ctrlLogMsg;
protected:
	afx_msg LRESULT OnPrintMessage(WPARAM wParam, LPARAM lParam);
};
