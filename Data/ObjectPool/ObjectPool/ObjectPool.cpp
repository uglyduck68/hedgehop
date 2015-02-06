/**
 * @file		ObjectPool.h
 * @author		sean kim <uglyduck68@gmail.com>
 * @brief		implementation file for object pool
 * @date		2015/02/05
 * @version		1.0
 */
#include "ObjectPool.h"


CObjectPool*	CObjectPool::m_pInstance	= NULL;

CObjectPool::CObjectPool(int nPoolSize/* = 10*/) : m_nPoolSize(nPoolSize), m_nFreeObj(0), m_Sync(PTHREAD_MUTEX_INITIALIZER)
{
	if (nPoolSize >= 1)
		m_lstPool.resize(nPoolSize);

	pthread_mutex_init (&m_Mutex, NULL);

	pthread_mutex_init (&m_Sync, NULL);
	pthread_cond_init (&m_SyncCond, NULL);
}


CObjectPool::~CObjectPool(void)
{
	if (m_pInstance)
		delete m_pInstance;

	pthread_mutex_destroy(&m_Mutex);
	pthread_mutex_destroy(&m_Sync);
	pthread_cond_destroy(&m_SyncCond);
}

/**
* @function		GetInstance
* @brief		for singleton
*/
CObjectPool*	CObjectPool::GetInstance(int nPoolSize/* = 10*/)
{
	///< FIXME
	///< following is very simple singleton
	if (m_pInstance == NULL)
	{
		m_pInstance	= new CObjectPool (nPoolSize);
	}

	return m_pInstance;
}


/**
* @function		InsertFreeObject
* @brief		insert object to container for pooling
*/
void			CObjectPool::InsertFreeObject(void* pObject)
{
	Item		a;

	pthread_mutex_lock (&m_Mutex);

	a.pObj		= pObject;
	a.nUse		= FREE_OBJ;

	// insert free object
	m_lstPool.push_back(a);

	// increase # of free object
	m_nFreeObj++;

	pthread_mutex_unlock (&m_Mutex);
}


/**
* @function		GetFreeObject
* @return		return free object
* @brief		call this to get the free object
*/
void			CObjectPool::GetFreeObject(OBJ_TYPE& Obj)
{
	pthread_mutex_lock (&m_Sync);

	while(!m_nFreeObj)
	{
		printf("Debug: enter waiting: %d\n", m_nFreeObj);
		pthread_cond_wait(&m_SyncCond, &m_Sync);
	}
	pthread_mutex_unlock (&m_Sync);


	pthread_mutex_lock (&m_Mutex);

	for (list<Item>::iterator	itr = m_lstPool.begin(); itr != m_lstPool.end(); itr++)
	{
		if (itr->nUse == FREE_OBJ)
		{
			Obj		= itr->pObj;

			itr->nUse	= USED_OBJ;	// from now this is used
			itr->pObj	= NULL;

			m_nFreeObj--;

			pthread_mutex_unlock (&m_Mutex);

			return;
		}
	}

	pthread_mutex_unlock (&m_Mutex);

	// no free object
	Obj		= NULL;

	return;
}



/**
* @function		ReturnFreeObject
* @brief		if you finish to use the object,
*				then call this to return the free object
*/
void			CObjectPool::ReturnFreeObject(void* pObject)
{
	pthread_mutex_lock (&m_Mutex);

	for (list<Item>::iterator	itr = m_lstPool.begin(); itr != m_lstPool.end(); itr++)
	{
		if (itr->nUse == USED_OBJ)
		{
			itr->pObj	= pObject;
			itr->nUse	= FREE_OBJ;	// from now this is used

			break;
		}
	}

	m_nFreeObj++;
	pthread_mutex_unlock (&m_Mutex);


	pthread_mutex_lock (&m_Sync);

	// wakeup the waiting thread
	pthread_cond_signal(&m_SyncCond);

	pthread_mutex_unlock (&m_Sync);
}
