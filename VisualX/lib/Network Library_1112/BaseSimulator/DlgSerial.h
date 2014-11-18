#pragma once


// CDlgSerial ��ȭ �����Դϴ�.

class CDlgSerial : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSerial)

public:
	CDlgSerial(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgSerial();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_SERIAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
//	virtual void OnOK();
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
private:
	std::string comPort;
	int comBps;
	int comDatabits;
	int comParity;
	int comStopbits;
	int comFlowcontrol;

};
int GetComSpeedIndex(int value);
int GetComSpeedValue(int index);