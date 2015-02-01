/*!	@file enLib2.h
 *	@brief En Library
 *	@author ����(hyunpark@endcs.net)
 *	@date 2014-11-10
 */
#pragma once
#include "LibHeader.h"
#include "ExtendLibrary.hpp"
#include "Interface/SerialObj.h"
#include "Interface/SocketObj.h"
namespace EnLibrary{
	/// ���̺귯���� �ʱ�ȭ �Ѵ�.
	template <int nDomain,int nIpCnt>
	void InitializeLibrary( const std::string& IP="*.*.*.*",const std::string& QOS="Default" )
	{
		LDDS_SETIP(nDomain,QOS.c_str(),nIpCnt,IP.c_str());
		InitializeLibrary();
	}
	/// ���̺귯���� �����Ѵ�.
	template <int nDomain>
	void ReleaseLibrary()
	{
		ReleaseLibrary();
	}
	/// ���̺귯���� �ʱ�ȭ �Ѵ�.
	extern LIBEXPORT void InitializeLibrary();
	/// ���̺귯���� �����Ѵ�.
	extern LIBEXPORT void ReleaseLibrary();
	/// ���� Ȱ��ȭ�� ������ ����� ��ȯ�Ѵ�.
	extern LIBEXPORT int GetDDSBufferSize();
	/// ���� ������ ������ ����� ��ȯ�Ѵ�.
	extern LIBEXPORT int GetDDSBufferSize2();
	/// TCP,UDP ��� ����
	extern LIBEXPORT SocketObj* CreateSocket();
	/// �ø��� ��� ����
	extern LIBEXPORT SerialObj* CreateSerial(short port,short timeout,long baudRate,unsigned char dataBits,unsigned char parity,unsigned char stopBits );

	/// TCP,UDP ��� ����
	extern LIBEXPORT void DeleteSocket(SocketObj* Obj);
	/// �ø��� ��� ����
	extern LIBEXPORT void DeleteSerial(SerialObj* Obj);

	/// ������ ����� �߰��Ͽ� �ݹ��� �޴´�.
	template<typename T>
	inline void AddPacket(T* data,std::function<void(T*)> Func = NULL)
	{
			CCommand<T>::CreateCommand(Func);
			Callback(data);
	}
	/// �۾��� �߰��Ѵ�.
	extern LIBEXPORT void AddTask(std::function<void()> Func);
	/// ������ �ð��� �۵��ϴ� �۾��� �߰��Ѵ�.
	extern LIBEXPORT void AddTask(std::function<void()> Func,const double& cycle);
	/// ������ �ð����� �ݺ��Ǵ� �۾��� �߰��Ѵ�.
	extern LIBEXPORT void AddTask(std::function<void()> Func,const double& cycle,bool& looper);
	/// �ݺ��Ǵ� �۾��� �߰��Ѵ�.
	extern LIBEXPORT void AddTask(std::function<void()> Func,bool& islooper);
/*	extern LIBEXPORT void AddTask(ULONG tmID, std::function<void()> Func,const double& cycle,bool& islooper );
	extern LIBEXPORT void AddTask(ULONG tmID, std::function<void()> Func,const double& cycle );
	extern LIBEXPORT void RemoveTask(ULONG tmID);
*/
#ifdef NEO
	template<int nDomain,typename SUB,typename PUB,DDSType Type>
	inline ICommandInterface* Initialize( const std::function<void(SUB*)>& Func,const std::string& SUBQOS, const std::string& PUBQOS,unsigned char CSCI,unsigned char CSC,unsigned short TopicID)
	{
		return CDDSCommand<nDomain,SUB,PUB,Type>::CreateCommand(Func,SUBQOS,PUBQOS);
	}
	template<int nDomain,typename PUB>
	inline ICommandInterface* Initialize(const std::string& QOS = "EventReliable",unsigned char CSCI = 0,unsigned char CSC = 0,unsigned short TopicID = 0)
	{
		return CDDSCommand<nDomain,PUB,PUB,PUBMode>::CreateCommand(NULL,QOS,QOS);
	}
#else
	/// DDS Interface�� �߰��Ѵ�.(CSCU ����ü,ó���� Ŭ����)
	template<int nDomain,typename SUB,typename PUB,DDSType Type>
	inline ICommandInterface* Initialize( const std::function<void(SUB*)>& Func,const std::string& SUBQOS, const std::string& PUBQOS,unsigned char CSCI,unsigned char CSC,unsigned short TopicID)
	{
		return CDDSCommand<nDomain,SUB,PUB,Type>::CreateCommand(Func,SUBQOS,PUBQOS,CSCI,CSC,TopicID);
	}
	/// DDS Interface�� �߰��Ѵ�.(CSCU ����ü,ó���� Ŭ����)
	template<int nDomain,typename PUB>
	inline ICommandInterface* Initialize(const std::string& QOS = "EventReliable",unsigned char CSCI = 0,unsigned char CSC = 0,unsigned short TopicID = 0)
	{
		return CDDSCommand<nDomain,PUB,PUB,PUBMode>::CreateCommand(NULL,QOS,QOS,CSCI,CSC,TopicID);
	}
	/// DDS �����͸� ����Ѵ�.
	template <typename T>
	inline void PrintDDSData(const T* data)
	{
		T::TypeSupport::print_data(data);
	}
	/// DDS �޽��� ����� ��ȯ�Ѵ�.
	template <typename T>
	inline DDSHeader GetMessageHeader(T msg)
	{
		UNREFERENCED_PARAMETER(msg);
		CDDSCommand<1,T>* Interface = GetCommand<T>();
		if(Interface == NULL || Interface == nullptr)
		{
			DDSHeader Header;
			memset(&Header,0,sizeof(Header));
			return Header;
		}else{
			return Interface->getMessageHeader();
		}
	}
	/// ���� DDS ���¸� �����Ѵ�.
	template <typename T>
	inline void setStatus(bool flag)
	{
			CDDSCommand<1,T>* Interface = GetCommand<T>();
			if(Interface == NULL || Interface == nullptr) return;
			Interface->setStatus(flag);
	}

#endif
	/// DDS Interface�� �߰��Ѵ�.(CSCU ����ü,ó���� Ŭ����)
	template<int nDomain,typename SUB,typename PUB>
	inline ICommandInterface* Initialize( const std::function<void(SUB*)>& Func,const std::string& SUBQOS = "EventReliable",const std::string& PUBQOS = "EventReliable",unsigned char CSCI = 0,unsigned char CSC = 0,unsigned short TopicID = 0)
	{
		return CDDSCommand<nDomain,SUB,PUB,SUBPUB>::CreateCommand(Func,SUBQOS,PUBQOS,CSCI,CSC,TopicID);
	}
	/// DDS Interface�� �߰��Ѵ�.(CSCU ����ü,ó���� Ŭ����)
	template<int nDomain,typename SUB>
	inline ICommandInterface* Initialize( const std::function<void(SUB*)>& Func,const std::string& QOS = "EventReliable",unsigned char CSCI = 0,unsigned char CSC = 0,unsigned short TopicID = 0 )
	{
		return CDDSCommand<nDomain,SUB,SUB,SUBMode>::CreateCommand(Func,QOS,QOS,CSCI,CSC,TopicID);
	}

	/// DDS Interface���� ó���� �������̽��� ������ Send�� ȣ���Ѵ�.(DDS Send)
	template <typename T>
	inline int Send( T* data )
	{
			CDDSCommand<1,T>* Interface = GetCommand<T>();
			if(Interface == NULL || Interface == nullptr) return 0;
//			DDSHeader Header = GetMessageHeader(*data);
//			memcpy(&data->stHead,&Header,sizeof(data->stHead));
			return Interface->Send(data);
		return 0;
	}

	/// �߰��� DDS Interface�� �����´�.(ó���� Ŭ����)
	template <typename T>
	inline CDDSCommand<1,T>* GetCommand()
	{
		ICommandInterface* Interface = CCommand<T>::GetCommand();

		if(Interface == NULL || Interface == nullptr)
		{
			return nullptr;
		}
		return static_cast<CDDSCommand<1,T>*>(Interface);
	}
	/// ������ �簳
	extern LIBEXPORT void Resume();
	/// ������ �Ͻ� ����
	extern LIBEXPORT void Suspend();
}