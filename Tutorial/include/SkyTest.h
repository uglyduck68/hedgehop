/**
 * @file		SkyTest.h
 * @remarks		SkyXDemo2 샘플을 이용하여 VisualX에 사용 가능하도록 테스트하기 위함
 *				테스트 분야
 *					1. 키를 이용하여 Sky condition(기상 및 시간)을 조절하고,
 *					2. Intro에 사용 가능하도록 hide 처리 테스트
 *					3. test the function of terrain collision
 */

#pragma once
#include "baseapplication.h"

#include "Sky.h"	// wrapper for SkyX
#include "Terrain.h"

class SkyTest :
	public BaseApplication
{
public:
	SkyTest(void);
	~SkyTest(void);
	/**
	* create sky entity
	*/
	void createScene();

	void createFrameListener(void);

    virtual bool keyPressed(const OIS::KeyEvent &arg);
    virtual bool keyReleased(const OIS::KeyEvent &arg);
    virtual bool mouseMoved(const OIS::MouseEvent &arg);
    virtual bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
    virtual bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	virtual void setupCameraPosition();

	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);

protected:
	CSky*		m_pSky;
	CTerrain*	m_pTerrain;
	bool		m_bColl;

	void createLight();

};

