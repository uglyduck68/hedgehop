#pragma once


// CDlgSerial 대화 상자입니다.

class CDlgSerial : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSerial)

public:
	CDlgSerial(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgSerial();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_SERIAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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