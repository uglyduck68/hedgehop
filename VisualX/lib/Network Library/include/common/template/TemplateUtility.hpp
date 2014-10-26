#pragma once
#include "common/template/weak_shared_ptr.hpp"

/// 생성
template <typename T1,typename T2> void TCreateObject(T2*& obj) { obj = new T1;}
template <typename T1,typename T2> void TCreateObject(std::shared_ptr<T2>& obj) { obj.reset(new T1);}
template <typename T1,typename T2> void TCreateObject(weak_shared_ptr<T2>& obj) { obj.assign(new T1);}
template <typename T> T* TCreateObject() { return new T;}

/// 할당
template <typename T1,typename T2> void TAssignObject(T2*& obj,T1* src) { obj = src;}
template <typename T1,typename T2> void TAssignObject(std::shared_ptr<T2>& obj,T1* src) { obj.reset(src);}
template <typename T1,typename T2> void TAssignObject(std::shared_ptr<T2>& obj,std::shared_ptr<T1> src) { obj.reset(src);}
template <typename T1,typename T2> void TAssignObject(weak_shared_ptr<T2>& obj,T1* src) { obj.assign(src);}
template <typename T1,typename T2> void TAssignObject(weak_shared_ptr<T2>& obj,std::shared_ptr<T1> src) { obj.assign(src);}

/// 해제
template <typename T> void TDeleteObject(T& ptr){ /// 단순 형은 delete 안함.
	UNREFERENCED_PARAMETER(ptr)
}
template <typename T> void TDeleteObject(T*& ptr) {
	if(nullptr == ptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}

template <typename T> void TDeleteObject(std::shared_ptr<T>& ptr ) {
	ptr.reset();
}

template <typename T> void TDeleteObject(weak_shared_ptr<T>& ptr){
	ptr.release();
}

/// 순회
template <typename CT>
void Foreach_SequenceContainer(CT& Content,std::function<void(typename CT::value_type item)> Func,bool inner = true)
{
	std::for_each(Content.begin(),Content.end(),(!inner)? Func : [&](typename CT::value_type item)
	{
		Func(item);
	});
}
template <typename CT>
void Foreach_SequenceContainer(CT& Content)
{
	Foreach_SequenceContainer(Content,[&](typename CT::value_type item)
	{
		item->RunWorker();
		Content.pop_front();
	},false);
}
template <typename T,typename CT>
void Foreach_SequenceContainer(CT& Content,std::shared_ptr<T> Proc)
{
	Foreach_SequenceContainer(Content,[&](typename CT::value_type item)
	{
		item->RunWorker(Proc);
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

/// 제거
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