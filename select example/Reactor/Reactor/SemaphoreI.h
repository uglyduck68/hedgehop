#pragma once

#include "X1.h"

class SemaphoreI
{
public:
	SemaphoreI(void);
	~SemaphoreI(void);

	virtual ret_t	Init(int InitValue, int MaxValue) = 0;
	virtual ret_t	GetValue(int* pValue) = 0;
	virtual ret_t	Wait() = 0;
	virtual ret_t	Post() = 0;
	virtual ret_t	Destroy() = 0;
};

