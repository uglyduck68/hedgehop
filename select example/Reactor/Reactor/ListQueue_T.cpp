//#include "StdAfx.h"
//#include "ListQueue_T.h"

#include	<new>

NS_X1_START

// make initial free list
template<typename T>
void				ListQueue<T>::Init()
{
	// make free list
	for (int i = 1; i < MAX_NODE; i++)
	{
		QNode[i-1].next = &QNode[i];
	}

	QNode[MAX_NODE-1].next	= NULL;

	m_pFreeList	= &QNode[0];
}

// get free node or NULL if no available
template<typename T> 
typename ListQueue<T>::QNODE*				ListQueue<T>::GetFreeNode()
{
#ifdef	NOT_EMBEDDED
    return new(std::nothrow) Node;
#else
	if (m_pFreeList == NULL)
		// no available node
		return NULL;

	QNODE*	tmp		= m_pFreeList;
	m_pFreeList		= m_pFreeList->next;

	return tmp;
#endif
}

// return used node to free list
// insert this node to head of free list
template<typename T>
void				ListQueue<T>::SetFreeNode(QNODE* pNode)
{
#ifdef	NOT_EMBEDDED
    delete pNode;
#else
	// insert it at head of free list
	pNode->next		= m_pFreeList;
	m_pFreeList		= pNode;
#endif

}

// return the count of free node for debug
template<typename T>
int		ListQueue<T>::GetFreeNodeCount()
{
	int		i = 0;

	// FIXME: don't traversal list because of time-consuming
	for (QNODE* tmp = m_pFreeList; tmp != NULL; tmp = tmp->next)
		i++;

	return i;
}

template<typename T>
ListQueue<T>::ListQueue(void) 
	: m_pFront(NULL), m_pBack(NULL), m_nSize(0) 
{
	Init();
}

template<typename T>
void	ListQueue<T>::Debug()
{
#ifdef	_DEBUG
	printf("ListQueue: size: %d, free node: %d\n", m_nSize, GetFreeNodeCount());
#endif

	return;
}

template<typename T>
void	ListQueue<T>::DeleteAll()
{
    while (m_nSize > 0)
        SetHeadFreeNode(0);

#ifdef	_DEBUG
	printf("ListQueue: size: %d, free node: %d\n", m_nSize, GetFreeNodeCount());
#endif

	return;
}

template<typename T>
ListQueue<T>::~ListQueue(void)
{
#ifdef	_DEBUG
	printf("dtor of ListQueue\n");
#endif
	DeleteAll();
}
 

// Enqueue the data into the tail of node list
//
template<typename T>
int		ListQueue<T>::Enqueue(T* pData)
{
    QNODE* tmp = GetFreeNode();

	if (tmp == NULL)
		return -1;

	if (tmp->Set(pData) < 0)
		return -1;

	tmp->next = NULL;
    tmp->prev = m_pBack;
 
    if (Empty() == true)
        m_pFront = tmp;
    else
        m_pBack->next = tmp;
 
    m_pBack = tmp;
 
    m_nSize++;

	return 1;
}
 
// return the first node of list to free node
//
template<typename T>
int		ListQueue<T>::SetHeadFreeNode(int nClearUsrData /*= 0*/)
{
    QNODE* tmp = m_pFront;
 
    m_pFront = m_pFront->next;

    if (m_pFront == NULL)
        m_pBack = NULL;
    else
        m_pFront->prev = NULL;
 
    m_nSize--;
 
	if (nClearUsrData == 1)
	{
		// delete user-defined data
		tmp->Free();
	}

	SetFreeNode(tmp);

	return 1;
}
 
template<typename T>
int ListQueue<T>::Dequeue(T*&	Data)
{
	if (m_nSize <= 0)
		return 0;

	Data	= Front();

	SetHeadFreeNode();

	return 1;
}
  
// size(): Queue에 들어있는 데이터의 개수를 반환한다.
//

template<typename T>
int ListQueue<T>::Size() const
{
    return m_nSize;
}
 
// empty(): Queue가 비어있으면 true, 아니면 false를 반환한다.

template<typename T>
bool ListQueue<T>::Empty() const
{
    return (m_nSize == 0);
}

///////////////////////////////////////////////////////////////////////////
// followings *NOT* used
///////////////////////////////////////////////////////////////////////////

// return user data of head
template<typename T>
T* ListQueue<T>::Front()
{
    return m_pFront->Data;
}
 
// return user data of tail
template<typename T>
T* ListQueue<T>::Back()
{
    return m_pBack->Data;
}
 


NS_X1_END