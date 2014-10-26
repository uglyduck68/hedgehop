#pragma once
#include "LibHeader.h"
#include "Interface/ICommandInterfaceDDS.h"
#include "Mgr/CommandMgr.h"
#include "common/Enum.h"
#include "common/CTimer.h"

enum LibraryType
{
	DDS = 0,
	NET = 1
};
namespace EnLibrary{
	template <int nDomain,int nIpCnt>
	void InitializeLibrary( const std::string& IP="*.*.*.*",const std::string& QOS="Reliable" )
	{
		LDDS_SETIP(nDomain,QOS.c_str(),nIpCnt,IP.c_str());
		InitializeLibrary();
	}
	extern LIBEXPORT void InitializeLibrary();
	extern LIBEXPORT void ReleaseLibrary();
	extern LIBEXPORT int GetDDSBufferSize();
	extern LIBEXPORT int GetDDSBufferSize2();
	/// TCP UDP ��� �߰�(ip �Ķ���� �ȳ����� Server)
	extern LIBEXPORT void AddNetwork(enNetwork::NetworkType::NetworkType Type,unsigned short port,const std::string& ip="");

	template<typename T>
	inline void AddPacket(T* data,std::function<void(T*)> Func = NULL)
	{
		CCommand<T>::CreateCommand(Func);
		Callback(data);
	}
#ifdef NEO
#include "msg/CMS/DDS_CMS_module.hpp"
	template<int nDomain,typename SUB,typename PUB,DDSType Type>
	inline std::shared_ptr<ICommandInterface> Initialize( const std::function<void(SUB*)>& Func,const std::string& SUBQOS, const std::string& PUBQOS,unsigned char CSCI,unsigned char CSC,unsigned short TopicID)
	{
		return CDDSCommand<nDomain,SUB,PUB,Type>::CreateCommand(Func,SUBQOS,PUBQOS);
	}
	template<int nDomain,typename PUB>
	inline std::shared_ptr<ICommandInterface> Initialize(const std::string& QOS = "Reliable",unsigned char CSCI = 0,unsigned char CSC = 0,unsigned short TopicID = 0)
	{
		return CDDSCommand<nDomain,PUB,PUB,PUBMode>::CreateCommand(NULL,QOS,QOS);
	}
#else
	/// DDS Interface�� �߰��Ѵ�.(CSCU ����ü,ó���� Ŭ����)
	template<int nDomain,typename SUB,typename PUB,DDSType Type>
	inline std::shared_ptr<ICommandInterface>& Initialize( const std::function<void(SUB*)>& Func,const std::string& SUBQOS, const std::string& PUBQOS,unsigned char CSCI,unsigned char CSC,unsigned short TopicID)
	{
		return CDDSCommand<nDomain,SUB,PUB,Type>::CreateCommand(Func,SUBQOS,PUBQOS,CSCI,CSC,TopicID);
	}
	template<int nDomain,typename PUB>
	inline std::shared_ptr<ICommandInterface>& Initialize(const std::string& QOS = "Reliable",unsigned char CSCI = 0,unsigned char CSC = 0,unsigned short TopicID = 0)
	{
		return CDDSCommand<nDomain,PUB,PUB,PUBMode>::CreateCommand(NULL,QOS,QOS,CSCI,CSC,TopicID);
	}
	template <typename T>
	inline void PrintDDSData(const T* data)
	{
		T::TypeSupport::print_data(data);
	}
	template <typename T>
	inline DDSHeader& GetMessageHeader(T msg)
	{
		return GetCommand<T>().getMessageHeader();
	}
	template <typename T>
	inline void setStatus(bool flag)
	{
		CDDSCommand<1,T>& Interface = GetCommand<T>();
		Interface.setStatus(flag);
	}

#endif
	template<int nDomain,typename SUB,typename PUB>
	inline std::shared_ptr<ICommandInterface>& Initialize( const std::function<void(SUB*)>& Func,const std::string& SUBQOS = "Reliable",const std::string& PUBQOS = "Reliable",unsigned char CSCI = 0,unsigned char CSC = 0,unsigned short TopicID = 0)
	{
		return CDDSCommand<nDomain,SUB,PUB,SUBPUB>::CreateCommand(Func,SUBQOS,PUBQOS,CSCI,CSC,TopicID);
	}

	template<int nDomain,typename SUB>
	inline std::shared_ptr<ICommandInterface>& Initialize( const std::function<void(SUB*)>& Func,const std::string& QOS = "Reliable",unsigned char CSCI = 0,unsigned char CSC = 0,unsigned short TopicID = 0 )
	{
		return CDDSCommand<nDomain,SUB,SUB,SUBMode>::CreateCommand(Func,QOS,QOS,CSCI,CSC,TopicID);
	}

	/// DDS Interface���� ó���� �������̽��� ������ Send�� ȣ���Ѵ�.(DDS Send)
	template <typename T>
	inline int Send( T* data )
	{
		CDDSCommand<1,T>& Interface = GetCommand<T>();
		return Interface.Send(data);
	}

	/// �߰��� DDS Interface�� �����´�.(ó���� Ŭ����)
	template <typename T>
	inline CDDSCommand<1,T>& GetCommand()
	{
		return static_cast<CDDSCommand<1,T>&>(*CCommand<T>::GetCommand());
	}
	/// �⺻������ Network Send�� �ڵ����� Queue ó�� �ȴ�. Send Thread���� �ϳ��� �������� �ȴ�.(Network Send)
	extern LIBEXPORT void Send(void* data,size_t len);
	extern LIBEXPORT void Resume();
	extern LIBEXPORT void Pause();
	extern LIBEXPORT void Start();
	extern LIBEXPORT void Stop();
}