
// BaseSimulator.h : BaseSimulator ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CBaseSimulatorApp:
// �� Ŭ������ ������ ���ؼ��� BaseSimulator.cpp�� �����Ͻʽÿ�.
//

class CBaseSimulatorApp : public CWinAppEx
{
public:
	CBaseSimulatorApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBaseSimulatorApp theApp;
