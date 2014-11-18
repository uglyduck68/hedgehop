
// BaseSimulatorView.cpp : CBaseSimulatorView Ŭ������ ����
#include "stdafx.h"

// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "BaseSimulator.h"
#endif

#include "BaseSimulatorDoc.h"
#include "BaseSimulatorView.h"
#include "DlgConnection.h"
#include "EnLib2.h"
#include "LocationMgr.h"
#include "Console.h"
CConsole con;
#define Cycle 1
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CBaseSimulatorView
IMPLEMENT_DYNCREATE(CBaseSimulatorView, CView)

BEGIN_MESSAGE_MAP(CBaseSimulatorView, CView)
	ON_COMMAND(ID_TEST_INITSIM1, &CBaseSimulatorView::OnTestInitsim1)
	ON_COMMAND(ID_TEST_INITSIM2, &CBaseSimulatorView::OnTestInitsim2)
	ON_COMMAND(ID_TEST_SEND, &CBaseSimulatorView::OnTestSend)
	ON_COMMAND(ID_SimStop, &CBaseSimulatorView::OnSimstop)
	ON_COMMAND(ID_SimStart, &CBaseSimulatorView::OnSimstart)
END_MESSAGE_MAP()

// CBaseSimulatorView ����/�Ҹ�
CBaseSimulatorView::CBaseSimulatorView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// �ùķ����� ����
	con.OpenConsole();
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}

CBaseSimulatorView::~CBaseSimulatorView()
{
}


// CBaseSimulatorView �׸���

void CBaseSimulatorView::OnDraw(CDC* /*pDC*/)
{
	CBaseSimulatorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CBaseSimulatorView ����

#ifdef _DEBUG
void CBaseSimulatorView::AssertValid() const
{
	CView::AssertValid();
}

void CBaseSimulatorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBaseSimulatorDoc* CBaseSimulatorView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBaseSimulatorDoc)));
	return (CBaseSimulatorDoc*)m_pDocument;
}
#endif //_DEBUG
// CBaseSimulatorView �޽��� ó����

//////////////////////////////////////////////
void CBaseSimulatorView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
}

void CBaseSimulatorView::OnTestInitsim1()
{
}

void CBaseSimulatorView::OnTestInitsim2()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}
const int s_TcpBufferSize = 1024;
void CBaseSimulatorView::OnTestSend()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}

void CBaseSimulatorView::PostNcDestroy()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CView::PostNcDestroy();
	printf("Simulator Exit!\n");

	EnLibrary::Suspend();
	isRun = false;
	EnLibrary::ReleaseLibrary<1>();
	con.CloseConsole();

}

void CBaseSimulatorView::OnSimstop()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	EnLibrary::Suspend();
	isRun = false;
	EnLibrary::ReleaseLibrary<1>();
	con.CloseConsole();
	exit(0);
}
LocationMgr Loc;
void SendGPS(int no,bool flag=false)
{
	DMSG_TM_SYSTRACK msg;
	memset(&msg,0,sizeof(DMSG_TM_SYSTRACK));
	int trkno = no;
	int Identity = (rand()%6+1);
	float Speed = (rand()%30+15);
	int LocNo = 0;
	if(no != 0 && flag)
		LocNo = (rand()%19+1);
	else
		LocNo = trkno;
	POS& pos = Loc.GetLocation(LocNo);
	msg.trkNo.trkNo = trkno;
	msg.cTrackIdentity = no == 0 ? 0 : Identity;
	msg.positionCHSys.longitude = pos.x;
	msg.positionCHSys.latitude = pos.y;
	msg.fCourse = 35;
	msg.fRange = 40;
	msg.fSpeed = Speed;
	EnLibrary::Send(&msg);
}
void CBaseSimulatorView::OnSimstart()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	EnLibrary::InitializeLibrary<1,1>("*.*.*.*","Reliable");
	EnLibrary::Initialize<1,DMSG_TM_SYSTRACK>();
	EnLibrary::Initialize<1,DMSG_OSSMMI_PLATFORMREQ>([&](DMSG_OSSMMI_PLATFORMREQ* msg)
	{
		printf("OK! Platform Req Cnt : %d!\n",cnt);
		Sleep(Cycle);
		SendGPS(++cnt,true);
	});
	EnLibrary::Resume();
	cnt = 0;
	isRun = true;
	EnLibrary::AddTask([&]()
	{
		SendGPS(cnt,true);	
	},Cycle);
}