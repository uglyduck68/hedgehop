#pragma once
#include "X1.h"

#include	<stdlib.h>

NS_X1_START

//#define		NOT_EMBEDDED		1

/**
 * Queue with doubly-linked list
 */
template<typename T>
class DECL_SPEC_DLL ListQueue
{
protected:
	// node of queue
	//
	typedef struct tagNode
	{
		T*		Data;
		tagNode* prev;
		tagNode* next;

		int Set(T* pData)
		{
			if (pData == NULL)
				return -1;

			this->Data	= pData;

			return 1;
		}

		/// delete resource of user-defined data
		void Free()
		{
			if (Data)
				delete Data;
		}
	} QNODE;

	// max. queue length 
	static const int	MAX_NODE	= 100;	
	
	// FIXME: you can change this to dynamic allocation
	// fixed length queue for embedded system
	QNODE				QNode[MAX_NODE];	

	// make initial free list
	void				Init();

	// get free node or NULL if no available
	QNODE*				GetFreeNode();		

	// return used node to free list
	void				SetFreeNode(QNODE* pNode);	

	// return the count of free node for debug
	int					GetFreeNodeCount();
	int					SetHeadFreeNode(int nClearUsrData = 0);
	///////////////////////////////////////////////////////////////////////////
	// followings *NOT* used
	///////////////////////////////////////////////////////////////////////////
	T* Front();
	T* Back();
public:
    ListQueue();
    virtual ~ListQueue();
 
	int		Enqueue(T* pData);
	int		Dequeue(T*& Data);

	int		Push(T* pData)
	{
		return Enqueue(T);
	}

	int		Pop(T*& pData)
	{
		return Dequeue(pData);
	}
	
	void	DeleteAll();
	void	Debug();

	/// return the number of used node of node list
	int		Size() const;
    bool	Empty() const;
 
	static int		GetMaxLength()
	{
#ifdef	NOT_EMBEDDED
		return -1;
#else
		return MAX_NODE;
#endif
	}

 
private:
	// head of used node list
    QNODE*		m_pFront;

	// tail of used node list
	QNODE*		m_pBack;

	// the number of used node list
	int			m_nSize;

	// head of free node list
	QNODE*		m_pFreeList;
};

NS_X1_END

#include "ListQueue_T.cpp"

