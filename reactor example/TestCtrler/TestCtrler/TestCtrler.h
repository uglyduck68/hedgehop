
// TestCtrler.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CTestCtrlerApp:
// �� Ŭ������ ������ ���ؼ��� TestCtrler.cpp�� �����Ͻʽÿ�.
//

class CTestCtrlerApp : public CWinApp
{
public:
	CTestCtrlerApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CTestCtrlerApp theApp;