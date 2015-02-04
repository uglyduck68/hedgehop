#pragma once
#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#pragma warning (disable : 4530)

#include <Ogre.h>

#include "ETTerrainInfo.h"

using namespace Ogre;

class CollisionHandler {
public:
	const ET::TerrainInfo* mTerrainInfo;

	CollisionHandler(Ogre::SceneManager *sceneMgr, const ET::TerrainInfo* terrainInfo);
	~CollisionHandler();

	bool collidesWithEntity(const Vector3& fromPoint, const Vector3& toPoint, const uint32 queryMask = 0xFFFFFFFF);

	void calculateY(SceneNode *n, const uint32 queryMask = 0xFFFFFFFF);

	bool raycastFromPoint(const Vector3 &point, const Vector3 &normal, Vector3 &result,ulong &target,float &closest_distance, const uint32 queryMask = 0xFFFFFFFF);

	void GetMeshInformation(const Ogre::MeshPtr mesh,
                                size_t &vertex_count,
                                Ogre::Vector3* &vertices,
                                size_t &index_count,
                                unsigned long* &indices,
                                const Ogre::Vector3 &position,
                                const Ogre::Quaternion &orient,
                                const Ogre::Vector3 &scale);

	Ogre::RaySceneQuery *mRaySceneQuery;

};

#endif