/*!	@file refptr.hpp
 *	@brief 레퍼런스 포인터
 *	@author 박현(hyunpark@endcs.net)
 *	@date 2014-11-10
 */
#pragma once
#include "common/atomic.h"
#include <stdexcept>
/*!	@class	Counter
 *	@brief	레퍼런스 카운터
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class Counter
{
public:
	/// 생성자
	Counter() {}
	/// 레퍼런스 카운트를 증가시킨다.
	void AddRef()
	{
		count.Inc();
	}
	/// 레퍼런스 카운트를 감소시킨다.
	void DelRef()
	{
		count.Dec();
	}
	/// 현재 레퍼런스 카운트를 얻어온다.
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
 *	@brief	레퍼런스 포인터 클래스
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
template<class T>
class RefPtr
{
public:
	typedef T Value;
	typedef T* Ptr;
	typedef T& Ref;
	/// 생성자
	RefPtr():counter(nullptr), pointer(nullptr){}

	/*!	@fn	RefPtr<T>::RefPtr
	 *	@brief	추적성 : 해당없음 \n
				설명  : 생성자
	 *	@param	ptr : 관리할 포인터
	 *	@return	
	 *	@author	박현(hyunpark@endcs.net)
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
	 *	@brief	추적성 : 해당없음 \n
				설명  : 새로운 포인터 할당
	 *	@param	ptr : 관리할 포인터 
	 *	@return	Ptr
	 *	@author	박현(hyunpark@endcs.net)
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
	 *	@brief	추적성 : 해당없음 \n
				설명  : 생성자
	 *	@param	aptr : 복사할 레퍼런스 포인터
	 *	@return	
	 *	@author	박현(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	RefPtr(const RefPtr& aptr)
	{
		Copy(*this, aptr);
	}

	/*!	@fn	RefPtr::RefPtr
	 *	@brief	추적성 : 해당없음 \n
				설명  : 생성자
	 *	@param	aptr : 복사할 레퍼런스 포인터
	 *	@return	
	 *	@author	박현(hyunpark@endcs.net)
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
	 *	@brief	추적성 : 해당없음 \n
				설명  : Raw 포인터 반환
	 *	@return	Ptr
	 *	@author	박현(hyunpark@endcs.net)
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
	 *	@brief	추적성 : 해당없음 \n
				설명  : 현재 레퍼런스 카운터 반환
	 *	@return	int
	 *	@author	박현(hyunpark@endcs.net)
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
	 *	@brief	추적성 : 해당없음 \n
				설명  : 포인터가 Null인지 체크
	 *	@return	bool
	 *	@author	박현(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	bool IsNull()const
	{
		return (pointer == nullptr || counter == nullptr);
	}

	/*!	@fn	RefPtr<T>::Delete
	 *	@brief	추적성 : 해당없음 \n
				설명  : 레퍼런스 포인터 제거
	 *	@return	void
	 *	@author	박현(hyunpark@endcs.net)
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
	 *	@brief	추적성 : 해당없음 \n
				설명  : 두 레퍼런스 포인터가 같은지 체크
	 *	@param	ptr : 대상 레퍼런스 포인터
	 *	@param	aptr : 대상 레퍼런스 포인터
	 *	@return	bool
	 *	@author	박현(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	bool IsEqual(const RefPtr& ptr, const RefPtr& aptr)
	{
		return (ptr.counter == aptr.counter && ptr.pointer == aptr.pointer);
	}
	/*!	@fn	RefPtr<T>::Copy
	 *	@brief	추적성 : 해당없음 \n
				설명  : 두 레퍼런스 포인터를 복제
	 *	@param	ptr : 원본 포인터
	 *	@param	aptr : 복제할 포인터
	 *	@return	void
	 *	@author	박현(hyunpark@endcs.net)
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