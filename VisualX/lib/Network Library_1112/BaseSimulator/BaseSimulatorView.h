
// BaseSimulatorView.h : CBaseSimulatorView 클래스의 인터페이스
//

#pragma once
#include <memory>
interface IClosure;
class CBaseSimulatorView : public CView
{
protected: // serialization에서만 만들어집니다.
	CBaseSimulatorView();
	DECLARE_DYNCREATE(CBaseSimulatorView)

// 특성입니다.
public:
	CBaseSimulatorDoc* GetDocument() const;

// 작업입니다.
private:
// 재정의입니다
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
protected:

// 구현입니다.
public:
	virtual ~CBaseSimulatorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:
	void TestRun(std::shared_ptr<IClosure> Run);
protected:

// 생성된 메시지 맵 함수
public:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnTestInitsim1();
	afx_msg void OnTestInitsim2();
	afx_msg void OnTestSend();
//	virtual BOOL DestroyWindow();
	virtual void PostNcDestroy();
/*	afx_msg void OnSetting();*/

	afx_msg void OnSimstop();
	afx_msg void OnSimstart();
	bool isRun;
	int cnt;
};
#ifndef _DEBUG  // BaseSimulatorView.cpp의 디버그 버전
inline CBaseSimulatorDoc* CBaseSimulatorView::GetDocument() const
   { return reinterpret_cast<CBaseSimulatorDoc*>(m_pDocument); }
#endif

