#include "testringbuffer.h"

#include <ecila/ringbuffer.h>








void TestRingBuffer::Do()
{
	char_t  ch  = '\0';
	int32_t num = 0;
	RingBuffer rbuff(16);


	rbuff.PutInt32(1);
	rbuff.GetInt32(num);
	assertEquals(1, num);

	rbuff.PutInt32(2);
	rbuff.PutInt32(3);
	rbuff.PutByte('n');
	rbuff.PutInt32(5);
	rbuff.PutInt32(6);

	rbuff.GetInt32(num);
	assertEquals(2, num);

	rbuff.GetInt32(num);
	assertEquals(3, num);

	rbuff.GetByte(ch);
	assertEquals('n', ch);

	rbuff.GetInt32(num);
	assertEquals(5, num);

}

