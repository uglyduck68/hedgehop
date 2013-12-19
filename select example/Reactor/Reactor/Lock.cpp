#include "Lock.h"


Lock::Lock(void)
{
	if (pthread_mutex_init(&m_mutex, NULL) != 0)
	{
		// error
	}

	if (pthread_mutex_lock(&m_mutex) != 0)
	{
		// error
	}
}


Lock::~Lock(void)
{
	if (pthread_mutex_unlock(&m_mutex) != 0)
	{

	}
	pthread_mutex_destroy(&m_mutex);
}
