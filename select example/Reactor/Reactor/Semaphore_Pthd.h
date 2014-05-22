#pragma once

#include "SemaphoreI.h"

class Semaphore_Pthd :public SemaphoreI
{
public:
	Semaphore_Pthd(void);
	~Semaphore_Pthd(void);

	virtual ret_t	Init(int InitValue, int MaxValue);
	virtual ret_t	GetValue(int* pValue);
	virtual ret_t	Wait();
	virtual ret_t	Post();
	virtual ret_t	Destroy();

protected:
	sem_t		m_Sem;
	bool		m_bInit;
};

