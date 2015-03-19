#pragma once
#include "SemaphoreI.h"

class Semaphore_Win :public SemaphoreI
{
public:
	Semaphore_Win(void);
	~Semaphore_Win(void);

	virtual ret_t	Init(int InitValue, int MaxValue);
	virtual ret_t	GetValue(int* pValue);
	virtual ret_t	Wait();
	virtual ret_t	Post();
	virtual ret_t	Destroy();

protected:
	HANDLE		m_Sem;
	bool		m_bInit;

	/// current semaphore value
	int			m_nSemValue;

	/// For mutual exclusion of m_nSemValue
	/// Windows semaphore don't support Semaphore Getvalue API.
	HANDLE		m_Mutex;
};

