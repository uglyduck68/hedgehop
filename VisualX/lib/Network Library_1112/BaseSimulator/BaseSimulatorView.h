
// BaseSimulatorView.h : CBaseSimulatorView Ŭ������ �������̽�
//

#pragma once
#include <memory>
interface IClosure;
class CBaseSimulatorView : public CView
{
protected: // serialization������ ��������ϴ�.
	CBaseSimulatorView();
	DECLARE_DYNCREATE(CBaseSimulatorView)

// Ư���Դϴ�.
public:
	CBaseSimulatorDoc* GetDocument() const;

// �۾��Դϴ�.
private:
// �������Դϴ�
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
protected:

// �����Դϴ�.
public:
	virtual ~CBaseSimulatorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:
	void TestRun(std::shared_ptr<IClosure> Run);
protected:

// ������ �޽��� �� �Լ�
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
#ifndef _DEBUG  // BaseSimulatorView.cpp�� ����� ����
inline CBaseSimulatorDoc* CBaseSimulatorView::GetDocument() const
   { return reinterpret_cast<CBaseSimulatorDoc*>(m_pDocument); }
#endif

