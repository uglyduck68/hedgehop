#pragma once
#include "common/template/TemplateUtility.hpp"

template <typename T> class weak_shared_ptr
{
	std::shared_ptr<T> data;

public:
	weak_shared_ptr()
	{
		data.reset();
#ifdef DebugLog
		PRINT_DBG("%s",typeid(T).name());
#endif
	}
	weak_shared_ptr(T* ptr) : data(ptr){
#ifdef DebugLog
		PRINT_DBG("%s",typeid(T).name());
#endif
	}
	weak_shared_ptr(const std::shared_ptr<T>& shared) : data(shared){
#ifdef DebugLog
		PRINT_DBG("%s",typeid(T).name());
#endif
	}
	
	weak_shared_ptr(const weak_shared_ptr& source){*this = source;}

	weak_shared_ptr(weak_shared_ptr&& source){ *this = std::move(source);}
	virtual ~weak_shared_ptr()
	{
		release();
	}

	void release()
	{
		data.reset();
#ifdef DebugLog
		PRINT_DBG("%s %s","Release ",typeid(T).name());
#endif
	}

	weak_shared_ptr& operator=(const weak_shared_ptr& src)
	{
		if(this != &src)
		{
			TDeleteObject(data);
			data = src.data;
		}
		return *this;
	}

	weak_shared_ptr& operator=(weak_shared_ptr&& src)
	{
		if(this != &src)
		{
			TDeleteObject(data);
			data = src.data;
			src.release();
		}
		return *this;
	}

	bool operator==(weak_shared_ptr& obj)
	{
		return obj->get() == *this->get();
	}

	void operator()(std::function<void(std::shared_ptr<T>& sp)> Func)
	{
		get_functional(Func);
	}
	T& operator*() const {
		if(!data){
#ifdef _DEBUG
//			LERROR("Dead Reference");
#endif
		}
		return *data;
	}
	std::shared_ptr<T>& operator->(){
		return get();
	}
	std::vector<unsigned char> toByte()
	{
		return std::vector<unsigned char>(data,data+sizeof(data));
	}
	std::shared_ptr<T>& assign(T* ptr)
	{
		data.reset(ptr);
#ifdef DebugLog
		PRINT_DBG("%s",typeid(T).name());
#endif
		return get();
	}

	std::shared_ptr<T>& assign(const std::shared_ptr<T>& ptr)
	{
		data = ptr;
#ifdef DebugLog
		PRINT_DBG("%s",typeid(T).name());
#endif
		return get();
	}

	/// 외부 함수에 값 안전하게 넘겨주기
	void get_functional(std::function<void(std::shared_ptr<T>& sp)> Func)
	{
			Func(get());
	}
	/// weak_ptr return
	std::shared_ptr<T>& get()
	{
		if(!data){
#ifdef _DEBUG
//			LERROR("Dead Reference");
#endif
		}
		return data;
	}
	T& reference()
	{
		return *get();
	}
	T* raw()
	{
		if(!data){
#ifdef _DEBUG
			//			LERROR("Dead Reference");
#endif
		}
		return data.get();
	}
	enum ConvertType{
		static_type = 0,
		const_type,
		dynamic_type
	};
	template <typename DestType>
	std::shared_ptr<DestType> Convert(ConvertType Type = static_type)
	{
		std::shared_ptr<T>& ptr = get();
		switch(Type)
		{
		case static_type:
			return std::static_pointer_cast<DestType>(ptr);
			break;
		case const_type:
			return std::const_pointer_cast<DestType>(ptr);
			break;
		case dynamic_type:
			return std::dynamic_pointer_cast<DestType>(ptr);
			break;
		}
	}
	/// shared_ptr이 유효한지 체크
	bool isExpired() const
	{
		return (data);
	}
};