#pragma once

#include "node.h"
#include "pool.h"
#include "eventresult.h"
#include "asyncresultimpl.h"
#include "threadmutex.h"








NS_ECILA_START

class DECL_SPEC_DLL ActPoolElement
{
public:
	ActPoolElement	*self_;
	EventResult		evr_;
	AsyncResultImpl	act_;

	 ActPoolElement()
	 {
		 //bind event_result <- act_result
		 evr_.ActImpl(&act_);
	 }

	~ActPoolElement() {}
};




class DECL_SPEC_DLL AsyncResultPool
:	public Node
{
public:

			 AsyncResultPool();
	virtual ~AsyncResultPool();

	CLASSNAME("AsyncResultPool");

	bool_t Initialize();
	bool_t Finalize();

	EventResult*	Acquire();
	bool_t			Release(EventResult *evr);

private:

	typedef std::map< EventResult*, ActPoolElement* > MAP_T;
	typedef MAP_T::iterator							  ITER_T;

	ThreadMutex				mutex_;
	Pool<ActPoolElement>	*pool_;
	MAP_T					acquire_map_;
};

NS_ECILA_END
