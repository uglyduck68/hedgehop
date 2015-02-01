/**
* @file			Fighter.h
* @remarks		This file is interface for fighter aircraft.
* @FIXME		fighter�� ���� Ŭ���� ������, ���� ����� CAirVessel ��
*				�Ű����� ��.
*/
#pragma once

#include "target.h"
#include "OgreOggSound.h"

//#define	_TEST_TRACK_

using namespace	OgreOggSound;

class CFighter : public CTarget
{
public:
	CFighter(Ogre::SceneManager* pSceneMgr, int name, string mesh);

	~CFighter(void);

protected:
	OgreOggISound*			m_pSound;

public:
	/**
	 * @function	PostCreate
	 * @remarks		post processinf according to characteristic of each target
	 */
	virtual void CreatePostprocess();

    virtual void createFrameListener(void);
	virtual bool frameRenderingQueued( const Ogre::FrameEvent &evt );
	/**
	* @function		frameStarted
	* @remarks		make animation effect
	*/
	bool frameStarted(const Ogre::FrameEvent& evt);

#ifdef	_TEST_TRACK_
	static const int	MAX_INDEX	= 100;
	Vector3			m_aCirclePos[ MAX_INDEX ];
	CFighter*		m_paTrack[ MAX_INDEX ];
	int				m_nCurPos;
	ManualObject*	m_pCircle;
#endif

	//////////////////////////////////////////////////////////////////////////////
	// for animation effect
	//////////////////////////////////////////////////////////////////////////////
	static const int	MAX_INDEX	= 100;	// # of points that make up circle

	//< coordinate of 3D circle
	std::deque<Ogre::Vector3> m_WalkList;		// set of waypoint
	Ogre::Real				mDistance;		// ���� �������� ���� �Ÿ�
	Ogre::Vector3				mDirection;		// ��ü�� �����̰� �ִ� ����
	Ogre::Vector3				mDestination;	// ��ü�� ���� �ִ� ��ǥ��
	static const int	m_WalkSpeed		= 100;	// character speed


	//< object to display 3D circle that is orbit of fighter
	Ogre::ManualObject*	m_pCircle;
	void CreateCircleOrbit();

	bool nextLocation();
};

