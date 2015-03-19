/**
 * @file		LockFreeQueue.h
 * @author		Sean Kim<uglyduck68@gmail.com>
 * @version		0.1
 * @date		20150310
 */

#include "StdAfx.h"
#include "LockFreeQueue.h"


///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////

void LockFreeQueue::Create()
{
	this->m_head		= &this->m_stub;
	this->m_tail		= &this->m_stub;
	this->m_stub.next	= nullptr;
}

LockFreeQueue::LockFreeQueue()
{
	Create();
}

LockFreeQueue::~LockFreeQueue()
{
}

void LockFreeQueue::push(NODE* node)
{
	node->next	= nullptr;

#if	1
	NODE* prev	= (NODE*)InterlockedExchangePointer((PVOID volatile *)&this->m_head, node);	//(*)
#else
	NODE* prev	= XCHG(&this->m_head, node);	//(*)
#endif

	prev->next	= node;
}

LONG LockFreeQueue::push(OBJ_TYPE& data)
{
	// FIXME
	NODE* node = new Node(data);

#if	1
	NODE* prev	= (NODE*)InterlockedExchangePointer((PVOID volatile *)&this->m_head, node);	//(*)
#else
	NODE* prev	= XCHG(&this->m_head, node);	//(*)
#endif

	prev->next	= node;

	// if you want more performance, comment out following
	return ::InterlockedIncrement( &m_size );
}

LONG LockFreeQueue::pop(OBJ_TYPE& data)
{
	NODE* tail	= this->m_tail;
	NODE* next	= tail->next;

	if (tail == &this->m_stub)
	{
		if (next == nullptr)
			return -1;

		this->m_tail	= next;

		tail			= next;
		next			= next->next;
	}

	if (next)
	{
		this->m_tail	= next;

		data			= tail->data;

		delete tail;

		LONG size = ::InterlockedDecrement( &m_size ); 
	
		return m_size;
	}

	NODE*	head	= this->m_head;

	if (tail != head)
		return -1;

//	push(&this->m_stub);
	this->m_stub.next	= nullptr;

#if	1
	NODE* prev	= (NODE*)InterlockedExchangePointer((PVOID volatile *)&this->m_head, &this->m_stub);	//(*)
#else
	NODE* prev	= XCHG(&this->m_head, node);	//(*)
#endif

	prev->next	= &this->m_stub;

	next	= tail->next;

	if (next)
	{
		this->m_tail	= next;

		data			= tail->data;

		delete tail;

		LONG size = ::InterlockedDecrement( &m_size ); 
	
		return m_size;
	}

	return -1;
}