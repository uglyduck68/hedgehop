
// WinExec.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CWinExecApp:
// �� Ŭ������ ������ ���ؼ��� WinExec.cpp�� �����Ͻʽÿ�.
//

class CWinExecApp : public CWinApp
{
public:
	CWinExecApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CWinExecApp theApp;