#include "testpool.h"

#include <ecila/pool.h>
#include <ecila/socket.h>








void TestPool::Do()
{
	uint32_t capacity = 1000;
	uint32_t inc_size = 1000;

	Pool<Socket> pool;
	assertEquals(TRUE, pool.Initialize(capacity, inc_size));
	assertEquals(capacity, pool.Capacity());
	

	Socket *s1 = pool.Acquire(__FUNCTION__, __LINE__);
	Socket *s2 = pool.Acquire(__FUNCTION__, __LINE__);


	assertNotEquals(s1, s2);


	assertEquals(capacity - 2, pool.Remain());
	assertEquals(TRUE, pool.Release(s1));
	assertEquals(capacity - 1, pool.Remain());


	assertEquals(TRUE, pool.Finalize());
}

