#ifndef __Mech_h_
#define __Mech_h_

#include "BaseApplication.h"

class Mech
{
public:
    Mech(Ogre::String name, Ogre::SceneManager* sceneMgr, Ogre::Real worldSize);
    virtual ~Mech(void);

	const Ogre::Vector3 & getPosition(void);
	Ogre::Vector3 getDirection(void);
	Ogre::Real getSpeed(void);
	void accelerate(void);
	void decelerate(void);
	void turnLeft(void);
	void turnRight(void);	
	const Ogre::String getName(void);
	virtual void move(Ogre::Real time);
	virtual void fireLaser(Mech* opponent);
	void mechDead(void);
	bool isActive(void);

protected:

	Ogre::String mName;
	bool mActive;
	Ogre::Real mWorldSize;
	Ogre::Real mTurnIncrementRadians;
	Ogre::Real mMechDirection;  
	Ogre::Real mSpeed;
	Ogre::Real mSpeedChange;
	Ogre::Real mLaserLength;
	Ogre::Real mMechLength;
	Ogre::Real mScale;
	Ogre::Real mLaserSeconds;
	Ogre::Real mCurrentLaserSeconds;
	Ogre::Entity* mEntity;
	Ogre::SceneNode* mMechNode;
	Ogre::AnimationState *mAnimationState; // The current animation state of the object	
	Ogre::SceneManager* mSceneMgr;
	Ogre::RaySceneQuery *mRaySceneQuery;
	Ogre::ManualObject* mLaser; 
	Ogre::SceneNode* mLaserNode; 

	virtual bool isCollision(const Ogre::Vector3& position, const Ogre::Vector3& direction); 
	virtual void checkBounds(const Ogre::Vector3& position);
	void removeLaser(void); 
	bool laserHits(Mech* opponent);

private:	

};

#endif // #ifndef __Mech_h_