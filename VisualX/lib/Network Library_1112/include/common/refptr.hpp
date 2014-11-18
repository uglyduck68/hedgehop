/*!	@file refptr.hpp
 *	@brief ���۷��� ������
 *	@author ����(hyunpark@endcs.net)
 *	@date 2014-11-10
 */
#pragma once
#include "common/atomic.h"
#include <stdexcept>
/*!	@class	Counter
 *	@brief	���۷��� ī����
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class Counter
{
public:
	/// ������
	Counter() {}
	/// ���۷��� ī��Ʈ�� ������Ų��.
	void AddRef()
	{
		count.Inc();
	}
	/// ���۷��� ī��Ʈ�� ���ҽ�Ų��.
	void DelRef()
	{
		count.Dec();
	}
	/// ���� ���۷��� ī��Ʈ�� ���´�.
	long GetCount()
	{
		return count.GetValue();
	}
private:
	Counter(const Counter&);
	Counter& operator=(const Counter&);
	AtomicNumber count;
};

/*!	@class	RefPtr
 *	@brief	���۷��� ������ Ŭ����
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
template<class T>
class RefPtr
{
public:
	typedef T Value;
	typedef T* Ptr;
	typedef T& Ref;
	/// ������
	RefPtr():counter(nullptr), pointer(nullptr){}

	/*!	@fn	RefPtr<T>::RefPtr
	 *	@brief	������ : �ش���� \n
				����  : ������
	 *	@param	ptr : ������ ������
	 *	@return	
	 *	@author	����(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	explicit RefPtr(Ptr ptr)
	{
		if(ptr != nullptr)
		{
			counter = new Counter();
			counter->AddRef();
			pointer = ptr;
		}else{
			counter = nullptr;
			pointer = nullptr;
		}
	}

	/*!	@fn	RefPtr<T>::Reset
	 *	@brief	������ : �ش���� \n
				����  : ���ο� ������ �Ҵ�
	 *	@param	ptr : ������ ������ 
	 *	@return	Ptr
	 *	@author	����(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	Ptr Reset(Ptr ptr = nullptr)
	{
		if(ptr == nullptr)
		{
			delete counter;
			counter = nullptr;
			delete pointer;
			pointer = nullptr;
			//TRACE_DBG("Release %s",typeid(Value).name());
			return nullptr;
		}else{
			Ptr oldPtr = pointer;
			Delete();
			counter = new Counter();
			counter->AddRef();
			pointer = ptr;
			return (ptr) ? oldPtr : nullptr;
		}
	}

	/*!	@fn	RefPtr<T>::RefPtr
	 *	@brief	������ : �ش���� \n
				����  : ������
	 *	@param	aptr : ������ ���۷��� ������
	 *	@return	
	 *	@author	����(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	RefPtr(const RefPtr& aptr)
	{
		Copy(*this, aptr);
	}

	/*!	@fn	RefPtr::RefPtr
	 *	@brief	������ : �ش���� \n
				����  : ������
	 *	@param	aptr : ������ ���۷��� ������
	 *	@return	
	 *	@author	����(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	template<class TT>
	RefPtr(const RefPtr<TT>& aptr)
	{
		if(IsEqual(*this, aptr))
		{
			return;
		}
		Delete();
		Copy(*this, aptr);
	}

	~RefPtr()
	{
		Delete();
	}

	RefPtr& operator = (const RefPtr& rhs)
	{
		if(IsEqual(*this, rhs))
		{
			return *this;
		}
		Delete();
		Copy(*this, rhs);
		return *this;
	}

	template<class TT>
	RefPtr& operator = (const RefPtr<TT>& rhs)
	{
		if(IsEqual(*this,rhs))
		{
			return *this;
		}
		Delete();
		Copy(*this, rhs);
		return *this;
	}

	Ref operator*()
	{
		if(IsNull())
		{
			throw std::logic_error("Not initialized pointer");
		}
		return *pointer;
	}

	Ptr operator->()
	{
		return Get();
	}

	const Ref operator*() const
	{
		if(IsNull())
		{
			throw std::logic_error("Not initialized pointer");
		}
		return *pointer;
	}

	const Ptr operator->()const
	{
		return Get();
	}

	/*!	@fn	RefPtr<T>::Get
	 *	@brief	������ : �ش���� \n
				����  : Raw ������ ��ȯ
	 *	@return	Ptr
	 *	@author	����(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	Ptr Get()
	{
		if(IsNull())
		{
			throw std::logic_error("Not initialized m_pointer");
		}
		return pointer;
	}

	const Ptr Get() const
	{
		if(IsNull())
		{
			throw std::logic_error("Not initialized m_pointer");
		}
		return pointer;
	}

	/*!	@fn	RefPtr<T>::GetCount
	 *	@brief	������ : �ش���� \n
				����  : ���� ���۷��� ī���� ��ȯ
	 *	@return	int
	 *	@author	����(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	int GetCount()const
	{
		if(counter != nullptr && pointer != nullptr)
		{
			return counter->GetCount();
		}
		return 0;
	};

	/*!	@fn	RefPtr<T>::IsNull
	 *	@brief	������ : �ش���� \n
				����  : �����Ͱ� Null���� üũ
	 *	@return	bool
	 *	@author	����(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	bool IsNull()const
	{
		return (pointer == nullptr || counter == nullptr);
	}

	/*!	@fn	RefPtr<T>::Delete
	 *	@brief	������ : �ش���� \n
				����  : ���۷��� ������ ����
	 *	@return	void
	 *	@author	����(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	void Delete()
	{
		if(counter != nullptr && pointer != nullptr)
		{
			counter->DelRef();

			if(counter->GetCount() == 0)
			{
				delete pointer;
				delete counter;
				counter = nullptr;
				pointer = nullptr;
			}
		}
	}

	bool operator == (const RefPtr<T>& ptr)
	{
		return IsEqual(*this, ptr);
	}

	bool operator != (const RefPtr<T>& ptr)
	{
		return !IsEqual(*this, ptr);
	}

	operator bool()
	{
		return !IsNull();
	}
private:
	/*!	@fn	RefPtr<T>::IsEqual
	 *	@brief	������ : �ش���� \n
				����  : �� ���۷��� �����Ͱ� ������ üũ
	 *	@param	ptr : ��� ���۷��� ������
	 *	@param	aptr : ��� ���۷��� ������
	 *	@return	bool
	 *	@author	����(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	bool IsEqual(const RefPtr& ptr, const RefPtr& aptr)
	{
		return (ptr.counter == aptr.counter && ptr.pointer == aptr.pointer);
	}
	/*!	@fn	RefPtr<T>::Copy
	 *	@brief	������ : �ش���� \n
				����  : �� ���۷��� �����͸� ����
	 *	@param	ptr : ���� ������
	 *	@param	aptr : ������ ������
	 *	@return	void
	 *	@author	����(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	void Copy(RefPtr& ptr, const RefPtr& aptr)
	{
		ptr.counter = aptr.counter;
		ptr.pointer = aptr.pointer;
		if (ptr.counter != 0)
		{
			ptr.counter->AddRef();
		}
	}
private:
	Counter* counter;
	Ptr pointer;
};