/**
 * @file		SkyTest.h
 * @remarks		SkyXDemo2 ������ �̿��Ͽ� VisualX�� ��� �����ϵ��� �׽�Ʈ�ϱ� ����
 *				�׽�Ʈ �о�
 *					1. Ű�� �̿��Ͽ� Sky condition(��� �� �ð�)�� �����ϰ�,
 *					2. Intro�� ��� �����ϵ��� hide ó�� �׽�Ʈ
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

