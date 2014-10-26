#pragma once
#include "Mgr\CommandMgr.h"
#include <memory>
#include <functional>
#include "mgr\BufferMgr.h"

class ICommandInterface
{
private:
	ICommandInterface(const ICommandInterface&);
	ICommandInterface& operator=(const ICommandInterface&);

public:
	ICommandInterface(){}
	virtual ~ICommandInterface(){}
	virtual void Process(void* msg) = 0;
};
template <typename T>
class CCommand : public ICommandInterface 
{
private:
	CCommand(const CCommand&);
	CCommand& operator=(const CCommand&);
public:
	CCommand(){}
	virtual ~CCommand(){}
	static std::shared_ptr<ICommandInterface>& CreateCommand(std::function<void(T*)> Func)
	{
		if(GetCommand() == NULL){
			CCommand<T>* Interface = new CCommand<T>();
			CommandMgr::GetCommandMgr().AddCommand(typeid(T).hash_code(),Interface);
			Interface->SetFunc(Func);
		}
		return GetCommand();
	}
	static std::shared_ptr<ICommandInterface>& GetCommand(){
		return CommandMgr::GetCommandMgr().GetCommand(typeid(T).hash_code()).get();
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
	std::shared_ptr<ICommandInterface>& Interface = CCommand<T>::GetCommand();
	if( data != NULL ) Buffer.AddData(data,sizeof(*data),[&](void* data)
	{
		Interface->Process(data);
	});
}
