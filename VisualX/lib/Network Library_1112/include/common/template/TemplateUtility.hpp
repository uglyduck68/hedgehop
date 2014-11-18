/*!	@file TemplateUtility.hpp
 *	@brief ���ø� �Լ���
 *	@author ����(hyunpark@endcs.net)
 *	@date 2014-11-10
 */

#pragma once
#include "common/RefPtr.hpp"
#include <algorithm>
/// ����
template <typename T1,typename T2> void TCreateObject(T2*& obj) { obj = new T1;}
template <typename T1,typename T2> void TCreateObject(RefPtr<T2>& obj) { obj.Reset(new T1);}
template <typename T> T* TCreateObject() { return new T;}

/// �Ҵ�
template <typename T1,typename T2> void TAssignObject(T2*& obj,T1* src) { obj = src;}
template <typename T1,typename T2> void TAssignObject(RefPtr<T2>& obj,T1* src) { obj.Reset(src);}

/// ����
template <typename T> void TDeleteObject(T& ptr){ /// �ܼ� ���� delete ����.
	UNREFERENCED_PARAMETER(ptr);
}
template <typename T> void TDeleteObject(T*& ptr) {
	if(nullptr == ptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}

template <typename T> void TDeleteObject(RefPtr<T>& ptr ) {
	ptr.Reset(nullptr);
}

/// ��ȸ
template <typename CT>
void Foreach_SequenceContainer(CT& Content,std::function<void(typename CT::value_type& item)> Func,bool inner = true)
{
	std::for_each(Content.begin(),Content.end(),(!inner)? Func : [&](typename CT::value_type& item)
	{
		Func(item);
	});
}
template <typename CT>
void Foreach_SequenceContainer(CT& Content)
{
	Foreach_SequenceContainer(Content,[&](typename CT::value_type& item)
	{
		(*item)();
		Content.pop_front();
	},false);
}
template <typename T,typename CT>
void Foreach_SequenceContainer(CT& Content,RefPtr<T> Proc)
{
	Foreach_SequenceContainer(Content,[&](typename CT::value_type& item)
	{
		(*item)(Proc);
		Content.pop_front();
	},false);
}
template <typename CT>
void Foreach_AssociativeContainer(CT& Content,std::function<void(typename CT::value_type item)> Func,bool inner = true)
{
	std::for_each(Content.begin(),Content.end(),(!inner)? Func : [&](typename CT::value_type item)
	{
		Func(item.second);
	});
}

/// ����
template <typename CT>
void Delete_Container(CT& Content,std::function<void(typename CT::value_type& item)> Func)
{
	if(!Content.empty()){
			std::for_each(Content.begin(),Content.end(),Func);
	}
	Content.clear();
}
template <typename CT>
void Delete_SequenceContainer(CT& Content,std::function<void(typename CT::value_type& item)> Func=NULL,bool inner = true)
{
	Delete_Container(Content,(inner)? [&](typename CT::value_type& item){
		TDeleteObject(item);
	}:Func);
}
template <typename CT>
void Delete_AssociativeContainer(CT& Content,std::function<void(typename CT::value_type& item)> Func=NULL,bool inner = true)
{
	Delete_Container(Content,(inner)? [&](typename CT::value_type& item){
		TDeleteObject(item.second);
	}:Func);
}

template <typename CT, typename IT>
bool IndexIn(CT& container, const IT& idx)
{
	if(idx < 0 || static_cast<IT>(container.size())) return false;
	return true;
}