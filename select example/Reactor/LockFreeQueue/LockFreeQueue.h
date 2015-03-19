/**
 * @file		LockFreeQueue.h
 * @author		Sean Kim<uglyduck68@gmail.com>
 * @version		0.1
 * @date		20150310
 * @remark		lock-free queue for multi-producer multi-consumer.
 *				should use my own memory manager.
 */
#pragma once

#include <queue>

#ifdef	WIN32
#include <Windows.h>
#elif defined(VXWORKS)
#include <vxAtomicLib.h>	// refer to vxworks_application_api_reference_*.pdf manual.
#endif

using namespace	std;

///< 
typedef void*	OBJ_TYPE;
typedef	long	LONG;

/**
 * @class		ILockFreeQueue
 * @remark		interface of LockFreeQueue
 */
class ILockFreeQueue
{
protected:
	typedef struct Node
	{
		OBJ_TYPE	data;
		Node*		next;

		Node() : next(nullptr) {}
		Node(OBJ_TYPE dat) : next(nullptr), data(dat) {}

		void operator=(Node* rvalue)
		{
			this->data	= rvalue->data;
			this->next	= rvalue->next;
		}
	} NODE;

public:
	/**
	 * @function		push
	 * @return			size of queue and always success
	 */
	virtual LONG push(OBJ_TYPE& data) = 0;

	/**
	 * @function		pop
	 * @return			-1 on fails
	 *					size of queue if success
	 */
	virtual LONG pop(OBJ_TYPE& data) = 0;
};


/**
 * @class		LockFreeQueue
 * @remark		for Multi Producer Single Consumer.
 *				This class is more good performance.
 */
class LockFreeQueue : public ILockFreeQueue
{
public:
	LockFreeQueue();
	~LockFreeQueue();

	/**
	 * @function		push
	 * @return			size of queue and always success
	 */
	LONG push(OBJ_TYPE& data);

	/**
	 * @function		pop
	 * @return			-1 on fails
	 *					size of queue if success
	 */
	LONG pop(OBJ_TYPE& data);

protected:

	void push(NODE*);

	NODE* volatile	m_head;
	NODE*			m_tail;
	NODE			m_stub;

	// if you want more performance comment out following and modify something
	LONG			m_size;

	void Create();
};
