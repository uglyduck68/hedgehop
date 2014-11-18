/*!	@file CSingleton.hpp
 *	@brief 싱글턴 클래스
 *	@author 박현(hyunpark@endcs.net)
 *	@date 2014-11-10
 */

#pragma once
#include "common/Lock.h"
#include "common/Refptr.hpp"
/*!	@class	CSingleton
 *	@brief	싱글턴 클래스
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
template <typename T>
class CSingleton
{
public:
	/// 생성자
	CSingleton(){}
	/// 소멸자
	~CSingleton(){}
	/// 싱글턴 객체를 해제한다.
	static void destroy_singleton()
	{
		if(isCreated()) p_instance.Reset();
	}
	/// 싱글턴 객체를 생성한다.
	static T& Instance()
	{
		if(!p_instance.IsNull())
		{
			return *p_instance;
		}
		{
			Mutex m;
			ScopedLock lock(m);
			if(!p_instance.IsNull())
			{
				return *p_instance;
			}else{
				p_instance.Reset(new T);
			}
		}
		return *p_instance;
	}
	/// 싱글턴 객체가 생성되었는지 체크한다.
	static bool isCreated()
	{
		return (p_instance.IsNull());
	}
private:
	static RefPtr<T> p_instance;
};

template <typename T>
	typename RefPtr<T> CSingleton<T>::p_instance(nullptr);