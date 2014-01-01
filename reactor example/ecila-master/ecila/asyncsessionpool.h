#pragma once

#include "pool.h"
#include "node.h"
#include "iactsession.h"
#include "asyncsession.h"
#include "threadmutex.h"









NS_ECILA_START

class Serial;

class DECL_SPEC_DLL AsyncSessionPool
:	public Node, public IActSession
{
public:

			 AsyncSessionPool();
	virtual ~AsyncSessionPool();

	CLASSNAME("AsyncSessionPool");

	bool_t Initialize();
	bool_t Finalize();

	AsyncSession*	Acquire();
	bool_t			Release(AsyncSession *h);
	Session*		ACTSession(serial_t uidx);

private:

	typedef std::map< serial_t, AsyncSession* > MAP_T;
	typedef MAP_T::iterator                     ITER_T;

	ThreadMutex			mutex_;
	Serial				*serial_;
	Pool<AsyncSession>	*pool_;
	MAP_T				map_; // management map


	bool_t Register  (serial_t uidx, AsyncSession*);
	bool_t UnRegister(serial_t uidx);
};

NS_ECILA_END
