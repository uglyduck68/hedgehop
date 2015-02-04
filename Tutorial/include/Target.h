/**
 * @file    Target.h
 *
 * This file is base class of ship, fighter, missile and so on.
 */

#pragma once
#include "OgreOggSound.h"

using namespace	std;
using namespace	Ogre;
using namespace	OgreOggSound;


class CTarget  : public Ogre::FrameListener
{
protected:
	Ogre::SceneManager*         mSceneMgr;
    //Ogre::Camera*               mCamera;
    //Ogre::Root*                 mRoot;

	string					m_strName;		// character name
	string					m_strMeshName;	// meshfile name
	SceneNode*				m_pSceneNode;	// scene node

	// viewpoint node
	// In chase mode camera always look at this node
	SceneNode*				m_pViewpointNode;	
	Vector3					VP_DEFAULT_POSITION;// position of viewpoint node

	SceneNode*				m_pCamHolder;	//* camera holder node
	OgreOggISound*			m_pSound;

public:
	enum EFFECT {
		EFT_JETENGINE	= 1,
		EFT_SMOKE,
		EFT_EXPLOSION,
		EFT_WATER_EXPLOSION,
		EFT_ALL
	};
protected:
	EFFECT					m_eft;
	ParticleSystem*			m_eftJetEngine;		// 제트 엔진 화염 특수효과
	ParticleSystem*			m_eftSmoke;			// 상당한 데미지를 나타내는 검정 연기 특수효과
	ParticleSystem*			m_eftExplosion;		// 폭파 특수효과
	ParticleSystem*			m_eftWaterExplosion;	// 포탄이 바다 표면에 떨어 졌을 때 나타나는 특수효과
public:
	CTarget(Ogre::SceneManager* pSceneMgr, int nID, string mesh);
	~CTarget(void);

	SceneNode*	GetSceneNode()
	{
		return m_pSceneNode;
	}

	SceneNode*	GetViewpointNode()
	{
		return m_pViewpointNode;
	}

	SceneNode* GetCamNode()
	{
		return m_pCamHolder;
	}

	operator SceneNode*()
	{
		return m_pSceneNode;
	}

	void	createEffects()
	{
		m_eftJetEngine = mSceneMgr->createParticleSystem("JetEngine1", "Examples/JetEngine1");  // create a rainstorm
		m_eftJetEngine->setBoundsAutoUpdated(false);
		m_eftJetEngine->fastForward(5);   // fast-forward the rain so it looks more natural

		// change -y-axis direction to -z-axis like fighter's jet engine flare
		m_eftJetEngine->getEmitter(0)->setDirection( Vector3(0, 0, -1) );

		m_eftSmoke = mSceneMgr->createParticleSystem("Smoke", "Examples/Smoke");
		m_eftSmoke->setBoundsAutoUpdated(false);

		m_eftExplosion	= mSceneMgr->createParticleSystem("Explosion", "explosionTemplate");
		m_eftExplosion->setBoundsAutoUpdated(false);

		// fast forward 1 second  to the point where the particle has been emitted
		m_eftExplosion->fastForward(1.0);


		m_eftWaterExplosion	= mSceneMgr->createParticleSystem("WaterExplosion", "waterExplosionTemplate");
		m_eftWaterExplosion->fastForward(1.0);
		m_eftWaterExplosion->setBoundsAutoUpdated(false);
	}

	void detachObject(SceneNode* pNode, const char* name)
	{
		MovableObject*	obj;

		for (int i = 0; i < pNode->numAttachedObjects(); i++)
		{
			obj		= pNode->getAttachedObject (i);
			if (obj->getName() == name)
			{
				GetSceneNode()->detachObject (obj);
				break;
			}
		}	
	}

	/**
	*
	*/
	void	SetEffect (EFFECT eft)
	{

		if (m_eft == EFT_JETENGINE && eft != EFT_JETENGINE)
		{
			detachObject (GetSceneNode(), "JetEngine1");
		}
		else if (m_eft == EFT_SMOKE && eft != EFT_SMOKE)
		{
			detachObject (GetSceneNode(), "Smoke");
		}
		else if (m_eft == EFT_EXPLOSION && eft != EFT_EXPLOSION)
		{
			detachObject (GetSceneNode(), "Explosion");
		}
		else if (m_eft == EFT_WATER_EXPLOSION && eft != EFT_WATER_EXPLOSION)
		{
			detachObject (GetSceneNode(), "WaterExplosion");
		}
		else if (m_eft == EFT_ALL && eft != EFT_ALL)
		{
			detachObject (GetSceneNode(), "Smoke");
			detachObject (GetSceneNode(), "JetEngine1");
			detachObject (GetSceneNode(), "Explosion");
		}

		if (eft == EFT_JETENGINE && m_eftJetEngine != NULL)
		{
			GetSceneNode()->attachObject(m_eftJetEngine);
		}
		else if (eft == EFT_SMOKE)
		{
			GetSceneNode()->attachObject(m_eftSmoke);
		}
		else if (eft == EFT_EXPLOSION)
		{
			GetSceneNode()->attachObject(m_eftExplosion);
		}
		else if (eft == EFT_WATER_EXPLOSION)
		{
			GetSceneNode()->attachObject(m_eftWaterExplosion);
		}
		else if (eft == EFT_ALL && (m_eftJetEngine != NULL && m_eftSmoke != NULL && m_eftExplosion != NULL))
		{
			GetSceneNode()->attachObject(m_eftJetEngine);
			GetSceneNode()->attachObject(m_eftSmoke);
			GetSceneNode()->attachObject(m_eftExplosion);
		}
		else
		{
			Ogre::LogManager::getSingleton().logMessage( Ogre::String("Error: effect is invalid"));
		}

		m_eft	= eft;
	}

	EFFECT GetEffect()
	{
		return m_eft;
	}

	/**
	* @function		getViewport
	* @return		tracking camera가 이 target에 attached된 경우
	*				camera가 바라 봐야할 viewpoint를 return
	*/
	Vector3 getViewport()
	{
		if (m_pViewpointNode)
			return m_pViewpointNode->_getDerivedPosition();

		return Vector3(0, 0, 0);
	}

	Vector3 getCameraPosition(const Ogre::SceneNode* target)
	{
		AxisAlignedBox	bb		= target->_getWorldAABB();
		const Vector3			min	= bb.getMinimum();
		const Vector3			max	= bb.getMaximum();

		Vector3	pos				= target->_getDerivedPosition();
		pos.y	+= (max.y - min.y + 10);	// offset 10

		return pos;
	}

	/**
	* @function		setTrackingCamera
	* @remarks		chase mode에서 카메라와 그 시점 위치를 결정한다.
	*				
	*/
	void	setTrackingCameraPosition(Ogre::Camera* pCamera)
	{
		// set the location of camera
#if	0
		pCamera->setPosition (getCameraPosition(m_pSceneNode));
#else
		// Method 2 to handle viewpoint of camera
		pCamera->setPosition (m_pCamHolder->_getDerivedPosition());
#endif
	}
	/*
	* @function		MoveTo that translate mesh to @Dest and set mesh's
	* orientation to @Dest
	* @param		Src	that is mesh's current position
	* @param		Dest that is mesh's destination position
	* @return		1 if success
	*/
	int		MoveTo( Ogre::Vector3 Src, Ogre::Vector3 Dest );
	//void setPosition( Ogre::Vector3 pos )
	//{
	//	m_pSceneNode->setPosition( pos );
	//}

	//void setPosition(float x, float y, float z)
	//{
	//	assert(m_pSceneNode);

	//	m_pSceneNode->setPosition(x, y, z);
	//}

	virtual bool frameRenderingQueued( const FrameEvent &evt );
    virtual void createFrameListener(void);

};

