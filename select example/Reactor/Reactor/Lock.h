#pragma once

#include	<pthread.h>

class Lock
{
protected:
	pthread_mutex_t    m_mutex;

public:
	Lock(void);
	~Lock(void);
};

