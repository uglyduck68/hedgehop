/*!	@file ICommandInterface.h
 *	@brief 커맨드 인터페이스
 *	@author 박현(hyunpark@endcs.net)
 *	@date 2014-11-10
 */

#pragma once
#include "Mgr\CommandMgr.h"
#include <memory>
#include <functional>
#include "mgr\BufferMgr.h"
/*!	@class	ICommandInterface
 *	@brief	커맨드 인터페이스
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class ICommandInterface
{
private:
	ICommandInterface(const ICommandInterface&);
	ICommandInterface& operator=(const ICommandInterface&);

public:
	/// 생성자
	ICommandInterface(){}
	/// 소멸자
	virtual ~ICommandInterface(){}
	/// 커맨드 실행
	virtual void Process(void* msg) = 0;
};
/*!	@class	CCommand
 *	@brief	기본 커멘드 인터페이스 구현
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
template <typename T>
class CCommand : public ICommandInterface 
{
private:
	CCommand(const CCommand&);
	CCommand& operator=(const CCommand&);
public:
	CCommand(){}
	virtual ~CCommand(){}
	static RefPtr<ICommandInterface>& CreateCommand(std::function<void(T*)> Func)
	{
		if(GetCommand().IsNull()){
			CCommand<T>* Interface = new CCommand<T>();
			CommandMgr::GetCommandMgr().AddCommand(typeid(T).hash_code(),Interface);
			Interface->SetFunc(Func);
		}
		return GetCommand();
	}
	static RefPtr<ICommandInterface>& GetCommand(){
		return CommandMgr::GetCommandMgr().GetCommand(typeid(T).hash_code());
	}
	void SetFunc(std::function<void(T*)> Func){
		m_Func = Func;
	}

	virtual void Process(void* msg)
	{
		m_Func(static_cast<T*>(msg));
	}
private:
	std::function<void(T*)> m_Func;
};

template <typename T>
static void Callback_(T* data,rmBuffer& Buffer)
{
	RefPtr<ICommandInterface>& Interface = CCommand<T>::GetCommand();
	if( data != NULL ) Buffer.AddData(data,sizeof(*data),[&](void* data)
	{
		Interface->Process(data);
	});
}
