
// EchoClientDlg.h : ��� ����
//

#pragma once

#include "ace/INET_Addr.h"
#include "ace/SOCK_Stream.h"
#include "ace/Sock_Connector.h"


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
	ACE_SOCK_Connector		m_Connector;
	ACE_SOCK_Stream			m_Sock;
	int						m_nTimerID;

	afx_msg void OnBnClickedCheckAuto();

	void Fin()
	{
		if (m_bConnect)
			m_Sock.close();

		if (m_bTimer)
		{
			KillTimer(1);
		}
	}
	virtual void OnCancel();
	virtual void OnOK();
};
