
// EchoClientDlg.h : 헤더 파일
//

#pragma once

#include "ace/INET_Addr.h"
#include "ace/SOCK_Stream.h"
#include "ace/Sock_Connector.h"


// CEchoClientDlg 대화 상자
class CEchoClientDlg : public CDialogEx
{
// 생성입니다.
public:
	CEchoClientDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

	~CEchoClientDlg()
	{
	}

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ECHOCLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
