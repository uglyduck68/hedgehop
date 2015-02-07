/**
 * @file		ObjectPool.h
 * @author		sean kim <uglyduck68@gmail.com>
 * @brief		implementation file for object pool
 * @date		2015/02/05
 * @version		1.0
 */
#include "ObjectPool.h"


CObjectPool*	CObjectPool::m_pInstance	= NULL;
Mutex CObjectPool::m_MutexPool	= PTHREAD_MUTEX_INITIALIZER;

CObjectPool::CObjectPool(int nPoolSize/* = 10*/) : m_nPoolSize(nPoolSize), 
	m_nFreeObj(0), 
	m_Cond(PTHREAD_COND_INITIALIZER)
{
}


CObjectPool::~CObjectPool(void)
{
	ScopedLock<Mutex> gaurd(m_MutexPool);

	if (m_pInstance)
	{
		delete m_pInstance;
		m_pInstance	= NULL;
	}
}

/**
* @function		GetInstance
* @brief		for singleton
*/
CObjectPool*	CObjectPool::GetInstance(int nPoolSize/* = 10*/)
{
	if (m_pInstance == NULL)
	{
		ScopedLock<Mutex> gaurd(m_MutexPool);
	
		if(!m_pInstance)
			m_pInstance	= new CObjectPool (nPoolSize);
	}

	return m_pInstance;
}


/**
* @function		InsertFreeObject
* @brief		insert object to container for pooling
*/
void			CObjectPool::InsertFreeObject(OBJ_TYPE& Obj)
{
	ScopedLock<Mutex>	guard(m_MutexPool);

	// insert free object
	m_lstFree.push_back(Obj);
}


/**
* @function		GetFreeObject
* @return		return free object
* @brief		call this to get the free object
*/
void			CObjectPool::GetFreeObject(OBJ_TYPE& Obj, bool bWait /*= true*/)
{
	if (bWait)
	{
		// I wait for free object
		ScopedLock<Mutex>	guard(m_MutexCond);

		while(m_lstFree.empty())
			// I am waiting for free object
			pthread_cond_wait(&m_Cond, m_MutexCond);
	}

	{
		ScopedLock<Mutex>	guard(m_MutexData);

		if (!m_lstFree.empty())
		{
			Obj		= m_lstFree.front();

			m_lstFree.pop_front();

#ifdef	USED_OBJ
			m_lstUsing.push_back(Obj);
#endif
		}
	}
	

	return;
}



/**
* @function		ReturnFreeObject
* @brief		if you finish to use the object,
*				then call this to return the free object
*/
void			CObjectPool::ReturnFreeObject(OBJ_TYPE& Obj)
{
	{
		ScopedLock<Mutex>	guard(m_MutexData);

		m_lstFree.push_back (Obj);

#ifdef	USED_OBJ
		for (ObjList::iterator itr = m_lstUsing.begin(); itr != m_lstUsing.end(); itr++)
		{
			if (*itr == Obj)
			{
				m_lstUsing.erase(itr);
				break;
			}
		}
#endif

	}

	{
		ScopedLock<Mutex>	guard(m_MutexCond);

		// wakeup the waiting thread
		pthread_cond_signal(&m_Cond);
	}
}
