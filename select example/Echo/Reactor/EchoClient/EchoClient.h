
// EchoClient.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CEchoClientApp:
// �� Ŭ������ ������ ���ؼ��� EchoClient.cpp�� �����Ͻʽÿ�.
//

class CEchoClientApp : public CWinApp
{
public:
	CEchoClientApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CEchoClientApp theApp;