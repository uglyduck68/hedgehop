/**
* @file		Fighter.h
* This file is interface for fighter aircraft.
*/
#pragma once

#include "target.h"

#define	_TEST_TRACK_

class CFighter : public CTarget
{
public:
	CFighter(Ogre::SceneManager* pSceneMgr, int name, string mesh);

	~CFighter(void);

    virtual void createFrameListener(void);
	virtual bool frameRenderingQueued( const FrameEvent &evt );

#ifdef	_TEST_TRACK_
	static const int	MAX_INDEX	= 100;
	Vector3			m_aCirclePos[ MAX_INDEX ];
	CFighter*		m_paTrack[ MAX_INDEX ];
	int				m_nCurPos;
	ManualObject*	m_pCircle;
#endif
};

