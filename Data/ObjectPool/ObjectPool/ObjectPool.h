/**
 * @file		ObjectPool.h
 * @author		sean kim <uglyduck68@gmail.com>
 * @brief		interface file for object pool
 * @date		2015/02/05
 * @version		1.0
 */
#pragma once

#include <list>
#include <pthread.h>

#include "Mutex.h"

using namespace		std;

#define		USED_OBJ	1

/**
 * I use void * to emulate the generic object.
 * if you want class typed then you must implement some operation.
 */
typedef	void*	OBJ_TYPE;
typedef list<OBJ_TYPE>			ObjList;

class CObjectPool
{
protected:


	///< container for object pool
	///< if you want template version, change this container
#ifdef	USED_OBJ
    ObjList m_lstUsing;	// reserved objects
#endif
    ObjList m_lstFree;		// free objects
	
	int			m_nPoolSize;	///< pool size
	int			m_nFreeObj;		///< # of free object

	static Mutex	m_MutexPool;	//< mutex for singleton
	Mutex			m_MutexData;		//< mutex for data

	Mutex			m_MutexCond;	//< mutex for conditional variable
	pthread_cond_t	m_Cond;

	///< for singleton
	static CObjectPool*	m_pInstance;

public:
	CObjectPool(int nPoolSize);
	~CObjectPool(void);

	int GetPoolSize()
	{
		return m_nPoolSize;
	}

	/**
	* @function		GetInstance
	* @brief		for singleton
	*/
	static CObjectPool*	GetInstance(int nPoolSize = 10);

	/**
	* @function		InsertFreeObject
	* @brief		insert object to container for pooling
	*/
	void			InsertFreeObject(OBJ_TYPE& Obj);

	/**
	* @function		GetObject
	* @param		if bWait == true, then I wait for free object
	* @return		return free object
	* @brief		call this to get the free object
	*/
	void			GetFreeObject(OBJ_TYPE& Obj, bool bWait = true);


	/**
	* @function		FreeObject
	* @brief		if you finish to use the object,
	*				then call this to return the free object
	*/
	void			ReturnFreeObject(OBJ_TYPE& Obj);
};

