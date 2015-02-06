/**
 * @file		ObjectPool.h
 * @author		sean kim <uglyduck68@gmail.com>
 * @brief		interface file for object pool
 * @date		2015/02/05
 * @version		1.0
 */
#pragma once

#include	<list>
#include	<pthread.h>

using namespace		std;

#define		FREE_OBJ	0
#define		USED_OBJ	1

typedef	void*	OBJ_TYPE;

class CObjectPool
{
protected:

	typedef	struct tagItem 
	{
		OBJ_TYPE	pObj;
		int			nUse;	///< 0: free, 1: used

		tagItem()
		{
			pObj	= NULL;
			nUse	= 0;
		}
	} Item;

	///< container for object pool
	///< if you want template version, change this container
	list<Item>	m_lstPool;
	
	int			m_nPoolSize;	///< pool size
	int			m_nFreeObj;		///< # of free object

	pthread_mutex_t		m_Mutex;
	pthread_mutex_t		m_Sync;
	pthread_cond_t		m_SyncCond;


	///< for singleton
	static CObjectPool*	m_pInstance;

public:
	CObjectPool(int nPoolSize = 10);
	~CObjectPool(void);

	int GetPoolSize()
	{
		return m_nPoolSize;
	}

	/**
	* @function		GetInstance
	* @brief		for singleton
	*/
	static CObjectPool*	GetInstance(int nPoolSize = 2);

	/**
	* @function		InsertFreeObject
	* @brief		insert object to container for pooling
	*/
	void			InsertFreeObject(void* pObject);

	/**
	* @function		GetObject
	* @return		return free object
	* @brief		call this to get the free object
	*/
	void			GetFreeObject(OBJ_TYPE& Obj);


	/**
	* @function		FreeObject
	* @brief		if you finish to use the object,
	*				then call this to return the free object
	*/
	void			ReturnFreeObject(void* pObject);
};

