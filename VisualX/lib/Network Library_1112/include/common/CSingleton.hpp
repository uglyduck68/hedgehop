/*!	@file CSingleton.hpp
 *	@brief �̱��� Ŭ����
 *	@author ����(hyunpark@endcs.net)
 *	@date 2014-11-10
 */

#pragma once
#include "common/Lock.h"
#include "common/Refptr.hpp"
/*!	@class	CSingleton
 *	@brief	�̱��� Ŭ����
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
template <typename T>
class CSingleton
{
public:
	/// ������
	CSingleton(){}
	/// �Ҹ���
	~CSingleton(){}
	/// �̱��� ��ü�� �����Ѵ�.
	static void destroy_singleton()
	{
		if(isCreated()) p_instance.Reset();
	}
	/// �̱��� ��ü�� �����Ѵ�.
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
	/// �̱��� ��ü�� �����Ǿ����� üũ�Ѵ�.
	static bool isCreated()
	{
		return (p_instance.IsNull());
	}
private:
	static RefPtr<T> p_instance;
};

template <typename T>
	typename RefPtr<T> CSingleton<T>::p_instance(nullptr);