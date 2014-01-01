#pragma once

#include "pool.h"
#include "node.h"
#include "iactsession.h"
#include "syncsession.h"








NS_ECILA_START

class Serial;

class DECL_SPEC_DLL SyncSessionPool
:	public Node, public IActSession
{
public:

			 SyncSessionPool();
	virtual ~SyncSessionPool();

	CLASSNAME("SyncSessionPool");

	bool_t Initialize();
	bool_t Finalize();

	SyncSession* Acquire();
	bool_t       Release(SyncSession *h);
	Session*     ACTSession(serial_t uidx);

private:
	typedef std::map< serial_t, SyncSession* > MAP_T;
	typedef MAP_T::iterator                ITER_T;

	Serial				*serial_;
	Pool<SyncSession>	*pool_;
	MAP_T				map_; // management map


	bool_t Register  (serial_t uidx, SyncSession* sess);
	bool_t UnRegister(serial_t uidx);
};

NS_ECILA_END
