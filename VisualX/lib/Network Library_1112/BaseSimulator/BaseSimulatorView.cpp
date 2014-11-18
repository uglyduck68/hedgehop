
// BaseSimulatorView.cpp : CBaseSimulatorView 클래스의 구현
#include "stdafx.h"

// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// CBaseSimulatorView 생성/소멸
CBaseSimulatorView::CBaseSimulatorView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// 시뮬레이터 생성
	con.OpenConsole();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}

CBaseSimulatorView::~CBaseSimulatorView()
{
}


// CBaseSimulatorView 그리기

void CBaseSimulatorView::OnDraw(CDC* /*pDC*/)
{
	CBaseSimulatorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CBaseSimulatorView 진단

#ifdef _DEBUG
void CBaseSimulatorView::AssertValid() const
{
	CView::AssertValid();
}

void CBaseSimulatorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBaseSimulatorDoc* CBaseSimulatorView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBaseSimulatorDoc)));
	return (CBaseSimulatorDoc*)m_pDocument;
}
#endif //_DEBUG
// CBaseSimulatorView 메시지 처리기

//////////////////////////////////////////////
void CBaseSimulatorView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}

void CBaseSimulatorView::OnTestInitsim1()
{
}

void CBaseSimulatorView::OnTestInitsim2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
const int s_TcpBufferSize = 1024;
void CBaseSimulatorView::OnTestSend()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}

void CBaseSimulatorView::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CView::PostNcDestroy();
	printf("Simulator Exit!\n");

	EnLibrary::Suspend();
	isRun = false;
	EnLibrary::ReleaseLibrary<1>();
	con.CloseConsole();

}

void CBaseSimulatorView::OnSimstop()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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