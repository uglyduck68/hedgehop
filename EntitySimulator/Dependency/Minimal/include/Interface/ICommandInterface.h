/*!	@file ICommandInterface.h
 *	@brief Ŀ�ǵ� �������̽�
 *	@author ����(hyunpark@endcs.net)
 *	@date 2014-11-10
 */

#pragma once
#include "Interface/Helper.h"
/*!	@class	ICommandInterface
 *	@brief	Ŀ�ǵ� �������̽�
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class ICommandInterface
{
private:
	ICommandInterface(const ICommandInterface&);
	ICommandInterface& operator=(const ICommandInterface&);

public:
	/// ������
	ICommandInterface(){}
	/// �Ҹ���
	virtual ~ICommandInterface(){}
	/// Ŀ�ǵ� ����
	virtual void Process(void* msg) = 0;
};
/*!	@class	CCommand
 *	@brief	�⺻ Ŀ��� �������̽� ����
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
template <typename T>
class CCommand : public ICommandInterface 
{
private:
	CCommand(const CCommand&);
	CCommand& operator=(const CCommand&);
public:
	CCommand() {}
	virtual ~CCommand(){}
	static ICommandInterface* CreateCommand(std::function<void(T*)> Func)
	{
		if(GetCommand() == nullptr){
			CCommand<T>* Interface = new CCommand<T>();
			AddCommand(hash,Interface);
			Interface->SetFunc(Func);
		}
		return GetCommand();
	}
	static ICommandInterface* GetCommand(){
		return ::GetCommand(hash);
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
public:
	static size_t hash;
};
template <typename T>
size_t CCommand<T>::hash = typeid(T).hash_code();
template <typename T>
static void Callback_(T* data,int flag)
{
	if( !(data == NULL || data == nullptr) ) AddData(flag,data,sizeof(*data),[&](void* data)
	{
		ICommandInterface* Interface = CCommand<T>::GetCommand();
		Interface->Process(data);
	});
}
