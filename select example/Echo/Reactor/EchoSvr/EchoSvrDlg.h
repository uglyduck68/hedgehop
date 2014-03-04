
// EchoSvrDlg.h : ��� ����
//

#pragma once

#include "ace/INET_Addr.h"
#include "ace/SOCK_Stream.h"
#include "ace/Sock_Acceptor.h"
#include "ace/Reactor.h"

#include "ClientAcceptor.h"
#include "afxwin.h"

#define	WM_INC_CONNECTION	WM_USER+1
#define	WM_DEC_CONNECTION	WM_USER+2
#define	WM_PRINT_MESSAGE	WM_USER+3
#define	WM_USAGE			WM_USER+4

// CEchoSvrDlg ��ȭ ����
class CEchoSvrDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CEchoSvrDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	~CEchoSvrDlg()
	{

	}

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ECHOSVR_DIALOG };

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
	afx_msg void OnBnClickedButtonRun();


	ClientAcceptor		m_Acceptor;
	// echo port
	int m_nPort;
	// the number of clients that is connected
	int m_nNumClient;
	// CPU load percentage
	float m_nCpuPercentage;
	// network bandwidth
	float m_nBandwidth;
	// edit control that show send & received message
	CEdit m_ctrlMsg;

	// timer ID
	int		m_nTimerID;

	int	PrintMsg(char* pcFmt, ...);
	int GetTime(char* pcTime);

	/**
	* release all resource before Dialog is destructed
	*/
	void	Fin()
	{
		if (m_nTimerID > 0)
			KillTimer(m_nTimerID);

		ACE_Reactor::instance()->end_reactor_event_loop();
	}

protected:
	afx_msg LRESULT OnIncConnection(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDecConnection(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnPrintMessage(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUsage(WPARAM wParam, LPARAM lParam);
	virtual void OnCancel();
	virtual void OnOK();
};
