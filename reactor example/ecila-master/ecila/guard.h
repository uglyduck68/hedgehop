#pragma once


#include "ecila.h"






NS_ECILA_START

template < typename Lock > 
class DECL_SPEC_DLL Guard
{
private:
	bool_t	owner_;
	Lock	*lock_;


public:
	
	Guard(Lock &lock)
	: owner_(FALSE), lock_(&lock)
	{
		Acquire(); 
	}


	~Guard()
	{
		Release();
	}


	void Acquire()
	{
		lock_->Acquire();
		owner_ = TRUE;
	}


	void Release()
	{
		if(owner_)
		{
			owner_ = FALSE;
			lock_->Release();
		}
	}
};

NS_ECILA_END

