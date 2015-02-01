/*!	@file enLib2.h
 *	@brief En Library
 *	@author 박현(hyunpark@endcs.net)
 *	@date 2014-11-10
 */
#pragma once
#include "LibHeader.h"
#include "ExtendLibrary.hpp"
#include "Interface/SerialObj.h"
#include "Interface/SocketObj.h"
namespace EnLibrary{
	/// 라이브러리를 초기화 한다.
	template <int nDomain,int nIpCnt>
	void InitializeLibrary( const std::string& IP="*.*.*.*",const std::string& QOS="Default" )
	{
		LDDS_SETIP(nDomain,QOS.c_str(),nIpCnt,IP.c_str());
		InitializeLibrary();
	}
	/// 라이브러리를 해제한다.
	template <int nDomain>
	void ReleaseLibrary()
	{
		ReleaseLibrary();
	}
	/// 라이브러리를 초기화 한다.
	extern LIBEXPORT void InitializeLibrary();
	/// 라이브러리를 해제한다.
	extern LIBEXPORT void ReleaseLibrary();
	/// 현재 활성화된 버퍼의 사이즈를 반환한다.
	extern LIBEXPORT int GetDDSBufferSize();
	/// 현재 가져온 버퍼의 사이즈를 반환한다.
	extern LIBEXPORT int GetDDSBufferSize2();
	/// TCP,UDP 통신 생성
	extern LIBEXPORT SocketObj* CreateSocket();
	/// 시리얼 통신 생성
	extern LIBEXPORT SerialObj* CreateSerial(short port,short timeout,long baudRate,unsigned char dataBits,unsigned char parity,unsigned char stopBits );

	/// TCP,UDP 통신 제거
	extern LIBEXPORT void DeleteSocket(SocketObj* Obj);
	/// 시리얼 통신 제거
	extern LIBEXPORT void DeleteSerial(SerialObj* Obj);

	/// 임의의 명령을 추가하여 콜백을 받는다.
	template<typename T>
	inline void AddPacket(T* data,std::function<void(T*)> Func = NULL)
	{
			CCommand<T>::CreateCommand(Func);
			Callback(data);
	}
	/// 작업을 추가한다.
	extern LIBEXPORT void AddTask(std::function<void()> Func);
	/// 지정된 시간후 작동하는 작업을 추가한다.
	extern LIBEXPORT void AddTask(std::function<void()> Func,const double& cycle);
	/// 지정된 시간마다 반복되는 작업을 추가한다.
	extern LIBEXPORT void AddTask(std::function<void()> Func,const double& cycle,bool& looper);
	/// 반복되는 작업을 추가한다.
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
	/// DDS Interface를 추가한다.(CSCU 구조체,처리할 클래스)
	template<int nDomain,typename SUB,typename PUB,DDSType Type>
	inline ICommandInterface* Initialize( const std::function<void(SUB*)>& Func,const std::string& SUBQOS, const std::string& PUBQOS,unsigned char CSCI,unsigned char CSC,unsigned short TopicID)
	{
		return CDDSCommand<nDomain,SUB,PUB,Type>::CreateCommand(Func,SUBQOS,PUBQOS,CSCI,CSC,TopicID);
	}
	/// DDS Interface를 추가한다.(CSCU 구조체,처리할 클래스)
	template<int nDomain,typename PUB>
	inline ICommandInterface* Initialize(const std::string& QOS = "EventReliable",unsigned char CSCI = 0,unsigned char CSC = 0,unsigned short TopicID = 0)
	{
		return CDDSCommand<nDomain,PUB,PUB,PUBMode>::CreateCommand(NULL,QOS,QOS,CSCI,CSC,TopicID);
	}
	/// DDS 데이터를 출력한다.
	template <typename T>
	inline void PrintDDSData(const T* data)
	{
		T::TypeSupport::print_data(data);
	}
	/// DDS 메시지 헤더를 반환한다.
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
	/// 현재 DDS 상태를 설정한다.
	template <typename T>
	inline void setStatus(bool flag)
	{
			CDDSCommand<1,T>* Interface = GetCommand<T>();
			if(Interface == NULL || Interface == nullptr) return;
			Interface->setStatus(flag);
	}

#endif
	/// DDS Interface를 추가한다.(CSCU 구조체,처리할 클래스)
	template<int nDomain,typename SUB,typename PUB>
	inline ICommandInterface* Initialize( const std::function<void(SUB*)>& Func,const std::string& SUBQOS = "EventReliable",const std::string& PUBQOS = "EventReliable",unsigned char CSCI = 0,unsigned char CSC = 0,unsigned short TopicID = 0)
	{
		return CDDSCommand<nDomain,SUB,PUB,SUBPUB>::CreateCommand(Func,SUBQOS,PUBQOS,CSCI,CSC,TopicID);
	}
	/// DDS Interface를 추가한다.(CSCU 구조체,처리할 클래스)
	template<int nDomain,typename SUB>
	inline ICommandInterface* Initialize( const std::function<void(SUB*)>& Func,const std::string& QOS = "EventReliable",unsigned char CSCI = 0,unsigned char CSC = 0,unsigned short TopicID = 0 )
	{
		return CDDSCommand<nDomain,SUB,SUB,SUBMode>::CreateCommand(Func,QOS,QOS,CSCI,CSC,TopicID);
	}

	/// DDS Interface에서 처리할 인터페이스를 가져와 Send를 호출한다.(DDS Send)
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

	/// 추가한 DDS Interface를 가져온다.(처리할 클래스)
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
	/// 스레드 재개
	extern LIBEXPORT void Resume();
	/// 스레드 일시 정지
	extern LIBEXPORT void Suspend();
}