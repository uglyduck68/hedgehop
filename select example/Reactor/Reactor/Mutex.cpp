#include "Mutex.h"

NS_X1_START

Mutex::Mutex(void)
{
	if (pthread_mutex_init(&m_Mutex, NULL) != 0)
	{
		// error
	}
}


Mutex::~Mutex(void)
{
	if (pthread_mutex_unlock(&m_Mutex) != 0)
	{

	}

	pthread_mutex_destroy(&m_Mutex);
}

NS_X1_END