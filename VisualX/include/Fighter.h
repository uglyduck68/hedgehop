/**
* @file			Fighter.h
* @remarks		This file is interface for fighter aircraft.
* @FIXME		fighter를 위한 클래스 였으나, 설계 개념상 CAirVessel 로
*				옮겨져야 함.
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
	Ogre::Real				mDistance;		// 다음 지점까지 남은 거리
	Ogre::Vector3				mDirection;		// 객체가 움직이고 있는 방향
	Ogre::Vector3				mDestination;	// 객체가 가고 있는 목표점
	static const int	m_WalkSpeed		= 100;	// character speed


	//< object to display 3D circle that is orbit of fighter
	Ogre::ManualObject*	m_pCircle;
	void CreateCircleOrbit();

	bool nextLocation();
};

