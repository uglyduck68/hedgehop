
// EchoSvr.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CEchoSvrApp:
// �� Ŭ������ ������ ���ؼ��� EchoSvr.cpp�� �����Ͻʽÿ�.
//

class CEchoSvrApp : public CWinApp
{
public:
	CEchoSvrApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()

};

extern CEchoSvrApp theApp;