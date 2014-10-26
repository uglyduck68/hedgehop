#pragma once
#include "buffer/rmBuffer.h"
#include "common/Template.hpp"

class BufferMgr
{
public:
	BufferMgr(void);
	~BufferMgr(void);

	static BufferMgr& GetBufferMgr();
	static void ReleaseBufferMgr();
	rmBuffer& GetBuffer();
	rmBuffer& GetDDSBuffer();

private:
	void Init();
	weak_shared_ptr<rmBuffer> m_Buffer;
	weak_shared_ptr<rmBuffer> m_DDSBuffer;
};

