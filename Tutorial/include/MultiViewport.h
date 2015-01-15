/**
 * @file		MultiViewport.h
 * @remarks		��������ȯ���� ��Ʈ�� ȭ�鿡 ���� ��Ƽ����Ʈ ����
 *				ȭ�� �߾ȿ� 2/3 ũ���� �̴� �����츦 �����
 *				�� ������ȿ��� Ÿ�ϵ��� iso view�� 360�� ȸ���ϸ鼭 ���ٰ�
 *				Ư�� Ű�� ��� ���ų� 360�� ȸ���� ������ ���� Ÿ������ �Ѿ��
 *				��� Ÿ�ϵ��� �Ұ��� ������ ��������ȭ�� �ʱ� ���� �����ϵ��� �Ѵ�.
 */

#pragma once

#include <vector>
#include "baseapplication.h"

using namespace	Ogre;
using namespace	std;

class MultiViewport :
	public BaseApplication
{
public:
	MultiViewport(void);
	~MultiViewport(void);
protected:
	SceneNode*		m_snIntroTarget;

	std::deque<SceneNode*>	m_TargetList;

	Ogre::Camera*			m_IntroCamera;
	Ogre::Viewport*			m_IntroViewport;
	bool					m_IsIntro;	//< initial value is true.
	Real					m_RotTime;

	static const int		ROT_TIME	= 10;	//< rotate for 10 sec.

	void ControlCameraDistance(Ogre::Camera* pCamera, Ogre::Entity* pEntity)
	{
		// move camera to initial position
		setupCameraPosition();

		// getWorldBoundingBox() and getWorldBoundingBox( true ) return a different value
  		Ogre::AxisAlignedBox modelBoundsBox	= pEntity->getWorldBoundingBox( true );

		if( pCamera == NULL || pEntity == NULL /*|| modelBoundsBox.isFinite() || modelBoundsBox.isNull()*/)
			return;

		Ogre::Vector3			center	= modelBoundsBox.getCenter();//(modelBoundsBox.getMaximum() - modelBoundsBox.getMinimum()) / 2 + modelBoundsBox.getMinimum();//modelBoundsBox.getCenter();

		pCamera->lookAt( center );
		
		const Ogre::Vector3*	corners	= modelBoundsBox.getAllCorners();
		const Ogre::Matrix4		viewMatrix	= pCamera->getViewMatrix();
		Ogre::Vector3			screenCorner;

		Real	min_x =	1.0, max_x = 0.0, min_y = 1.0, max_y = 0.0, min_dim = 1.0, max_dim = 0.0;

		for( int i = 0 ; i < 7; i++ )
		{
			screenCorner	= corners[i];
			screenCorner	= viewMatrix * screenCorner;

			Real	x		= screenCorner.x / screenCorner.z + 0.5;
			Real	y		= screenCorner.y / screenCorner.z + 0.5;

			if( x < min_x )
				min_x	= x;
			if( x > max_x )
				max_x	= x;
			if( y < min_y )
				min_y	= y;
			if( y > max_y )
				max_y	= y;
			if( min_x < min_dim )
				min_dim	= min_x;
			if( min_y < min_dim )
				min_dim	= min_y;
			if( max_x > max_dim )
				max_dim	= max_x;
			if( max_y > max_dim )
				max_dim	= max_y;
		}

		Real	width	= (max_x - min_x);
		Real	height	= (max_y - min_y);
		Real	longdimension;

		if( width > height )
			longdimension	= width;
		else
			longdimension	= height;

		// move the camera according to axis of camera coordinate
		if( longdimension > 1.2 )
		{
			Real	d	= (longdimension - 0.9) * 200.0;

			// move backward
			pCamera->moveRelative(Ogre::Vector3(0, 0, d));
		}
		else if( longdimension < 0.8 )
		{
			Real	d	= (1-(0.8/longdimension)) * 10.0;

			// move forward
			pCamera->moveRelative(Ogre::Vector3(0, 0, d));
		}
	}

	/**
	* @function		SetNextIntroTarget
	* @remark		get the next target from target list and 
	*				set the target to next intro target
	*/
	void SetNextIntroTarget()
	{
		// set the previous invisible
		if( m_snIntroTarget )
			m_snIntroTarget->setVisible( false );

		// get next target and set visible
		if( m_TargetList.size() > 0 )
		{
			m_snIntroTarget		= m_TargetList.front(); m_TargetList.pop_front();

			////////////////////////////////////////////////////////////////////////////
			// check the target size and control the distance between the camera and target
			////////////////////////////////////////////////////////////////////////////
			Entity*	pTemp		= static_cast<Entity*>(m_snIntroTarget->getAttachedObject(0));

			ControlCameraDistance(m_IntroCamera, pTemp);

			m_snIntroTarget->setVisible( true );
		}
		else
		{
			m_snIntroTarget		= NULL;

			// finalize the intro
			SetIntroEnd();
		}

		m_RotTime	= ROT_TIME;
	}

	/**
	* @function		SetIntroEnd
	* @remark		finalize intro mode. set intro flag to false and
	*				delete intro viewport
	*/
	void SetIntroEnd()
	{
		// set flag to false
		m_IsIntro	= false;

		// delete intro viewport
		mWindow->removeViewport( 1 );
	}

protected:
	// derived from FrameListener via BaseApplication
	virtual void setupCameraPosition();

	/**
	 * @function		createViewport
	 * @remarks			BaseApplication Ŭ�������� �����ϴ� 
	 *					��ü ��ũ���� �ش��ϴ� main viewport �ܿ�
	 *					��Ʈ�ο� ���� viewport�� �����Ѵ�.
	 */
    virtual void createViewports(void);

	/**
	 * @function		createScene
	 * @remarks			��Ʈ�ο� ���� Ÿ���� �����. �ϴ�
	 *					ogrehead�� ������ ����� ȸ�� ��Ʈ�� �׽�Ʈ��
	 *					��������. ���������� �Ҹ����� �־�� ���� �𸥴�.
	 */
    virtual void createScene(void);
    virtual void createFrameListener(void);
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);

	virtual bool keyPressed(const OIS::KeyEvent &arg);
    virtual bool keyReleased(const OIS::KeyEvent &arg);
    virtual bool mouseMoved(const OIS::MouseEvent &arg);
    virtual bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
    virtual bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
};

