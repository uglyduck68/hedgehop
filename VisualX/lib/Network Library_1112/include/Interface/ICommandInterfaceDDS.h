/*!	@file ICommandInterfaceDDS.h
 *	@brief DDS 커멘드 인터페이스
 *	@author 박현(hyunpark@endcs.net)
 *	@date 2014-11-10
 */

#pragma once
#include "interface/ICommandInterface.h"
#ifdef NEO
#include "DDS/NEO/CDDSLibrary.hpp"
#else
#include "DDS/RTI/CDDSLibrary.hpp"
#endif

/// DDS 타입
enum DDSType
{
	SUBPUB = 0,
	SUBMode = 1,
	PUBMode = 2
};
/// DDS 상태(기본값은 2)
enum DDSStatus
{
	Disable = 0,
	Standby,
	Active
};
/*!	@class	DDSHeader
 *	@brief	DDS Header
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class DDSHeader
{
public:
	unsigned short unTopicID;
	unsigned char bySendCSCI;
	unsigned char bySendCSC;
	unsigned short unDomain;
};
template<typename T>
static void Callback(T* data) 
{
	Callback_(data,BufferMgr::GetBufferMgr().GetDDSBuffer());
}
#if defined NEO
#pragma warning(disable:4127)
#include "Mgr/CommandMgr.h"
#include "Msg/CMS/DDS_CMS_module.hpp"
#include "msg/OSS MMI/DDS_OSSMMI_module.hpp"
template <int nDomain,typename SUB,typename PUB=SUB,DDSType nType = SUBPUB> 
class CDDSCommand :public CCommand<SUB>
{
private:
	CDDSCommand(const CDDSCommand&);
	CDDSCommand& operator=(const CDDSCommand&);
public:
	CDDSCommand(const std::string& _SUBQOS="Reliable",const std::string& _PUBQOS="Reliable") : SUBQOS(_SUBQOS),PUBQOS(_PUBQOS)
	{
		Create();
	}
	virtual ~CDDSCommand()
	{
	}

	int Send(DMSG_TM_SYSTRACK* msg){
		// Dummy
	}

	void Create(){
		// Dummy
	}

private:
	std::string SUBQOS;
	std::string PUBQOS;
	std::function<void(SUB*)> m_Func;
};

template <> 
class CDDSCommand<1,DMSG_TM_SYSTRACK,DMSG_TM_SYSTRACK,SUBPUB> :public CCommand<DMSG_TM_SYSTRACK>
{
private:
	CDDSCommand(const CDDSCommand&);
	CDDSCommand& operator=(const CDDSCommand&);
public:
	static RefPtr<ICommandInterface>& CreateCommand(const std::function<void(DMSG_TM_SYSTRACK*)>& Func,const std::string& _SUBQOS="Reliable",const std::string& _PUBQOS="Reliable",unsigned char CSCI=0,unsigned char CSC=0,unsigned short TopicID=0)
	{
		if(GetCommand() == NULL){
			CDDSCommand<1,DMSG_TM_SYSTRACK,DMSG_TM_SYSTRACK,SUBPUB>* Command = new CDDSCommand<1,DMSG_TM_SYSTRACK,DMSG_TM_SYSTRACK,SUBPUB>(_SUBQOS,_PUBQOS);
			if(Func!=NULL)Command->SetFunc(Func);
			CommandMgr::GetCommandMgr().AddCommand(typeid(DMSG_TM_SYSTRACK).hash_code(),Command);
		}
		return GetCommand();
	}
	CDDSCommand(const std::string& _SUBQOS="Reliable",const std::string& _PUBQOS="Reliable") : SUBQOS(_SUBQOS),PUBQOS(_PUBQOS)
	{
		Create();
	}
	virtual ~CDDSCommand()
	{
	}

	int Send(DMSG_TM_SYSTRACK* msg){
		if(LDDS_ISSETWRITE(1,DMSG_TM_SYSTRACK)){
			int nRetCode = LDDS_WRITE(1,DMSG_TM_SYSTRACK,msg);
			return nRetCode;
		}
		return -1;
	}

	void Create(){
		LDDS_CREATE_TOPIC(1,DMSG_TM_SYSTRACK,SUBQOS.c_str(),true,false,NULL);
		LDDS_CREATE_TOPIC(1,DMSG_TM_SYSTRACK,SUBQOS.c_str(),false,true,(CALLBACK_FUNC)Callback<DMSG_TM_SYSTRACK>);
	}

private:
	std::string SUBQOS;
	std::string PUBQOS;
	std::function<void(DMSG_TM_SYSTRACK*)> m_Func;
};
template <> 
class CDDSCommand<1,DMSG_TM_SYSTRACK,DMSG_TM_SYSTRACK,PUBMode> :public CCommand<DMSG_TM_SYSTRACK>
{
private:
	CDDSCommand(const CDDSCommand&);
	CDDSCommand& operator=(const CDDSCommand&);
public:
	static RefPtr<ICommandInterface>& CreateCommand(const std::function<void(DMSG_TM_SYSTRACK*)>& Func,const std::string& _SUBQOS="Reliable",const std::string& _PUBQOS="Reliable",unsigned char CSCI=0,unsigned char CSC=0,unsigned short TopicID=0)
	{
		if(GetCommand() == NULL){
			CDDSCommand<1,DMSG_TM_SYSTRACK,DMSG_TM_SYSTRACK,PUBMode>* Command = new CDDSCommand<1,DMSG_TM_SYSTRACK,DMSG_TM_SYSTRACK,PUBMode>(_SUBQOS,_PUBQOS);
			CommandMgr::GetCommandMgr().AddCommand(typeid(DMSG_TM_SYSTRACK).hash_code(),Command);
		}
		return GetCommand();
	}

	CDDSCommand(const std::string& _SUBQOS="Reliable",const std::string& _PUBQOS="Reliable") : SUBQOS(_SUBQOS),PUBQOS(_PUBQOS)
	{
		Create();
	}
	virtual ~CDDSCommand()
	{
	}

	int Send(DMSG_TM_SYSTRACK* msg){
		if(LDDS_ISSETWRITE(1,DMSG_TM_SYSTRACK)){
			int nRetCode = LDDS_WRITE(1,DMSG_TM_SYSTRACK,msg);
			return nRetCode;
		}
		return -1;
	}

	void Create(){
		LDDS_CREATE_TOPIC(1,DMSG_TM_SYSTRACK,SUBQOS.c_str(),true,false,NULL);
	}

private:
	std::string SUBQOS;
	std::string PUBQOS;
};
template <> 
class CDDSCommand<1,DMSG_TM_SYSTRACK,DMSG_TM_SYSTRACK,SUBMode> :public CCommand<DMSG_TM_SYSTRACK>
{
private:
	CDDSCommand(const CDDSCommand&);
	CDDSCommand& operator=(const CDDSCommand&);
public:
	static RefPtr<ICommandInterface>& CreateCommand(const std::function<void(DMSG_TM_SYSTRACK*)>& Func,const std::string& _SUBQOS="Reliable",const std::string& _PUBQOS="Reliable",unsigned char CSCI=0,unsigned char CSC=0,unsigned short TopicID=0)
	{
		if(GetCommand() == NULL){
			CDDSCommand<1,DMSG_TM_SYSTRACK,DMSG_TM_SYSTRACK,SUBMode>* Command = new CDDSCommand<1,DMSG_TM_SYSTRACK,DMSG_TM_SYSTRACK,SUBMode>(_SUBQOS,_PUBQOS);
			if(Func!=NULL)Command->SetFunc(Func);
			CommandMgr::GetCommandMgr().AddCommand(typeid(DMSG_TM_SYSTRACK).hash_code(),Command);
		}
		return GetCommand();
	}
	CDDSCommand(const std::string& _SUBQOS="Reliable",const std::string& _PUBQOS="Reliable") : SUBQOS(_SUBQOS),PUBQOS(_PUBQOS)
	{
		Create();
	}
	virtual ~CDDSCommand()
	{
	}

	int Send(DMSG_TM_SYSTRACK* msg){
		if(LDDS_ISSETWRITE(1,DMSG_TM_SYSTRACK)){
			int nRetCode = LDDS_WRITE(1,DMSG_TM_SYSTRACK,msg);
			return nRetCode;
		}
		return -1;
	}

	void Create(){
		LDDS_CREATE_TOPIC(1,DMSG_TM_SYSTRACK,SUBQOS.c_str(),false,true,(CALLBACK_FUNC)Callback<DMSG_TM_SYSTRACK>);
	}

private:
	std::string SUBQOS;
	std::string PUBQOS;
	std::function<void(DMSG_TM_SYSTRACK*)> m_Func;
};

template <> 
class CDDSCommand<1,DMSG_OSSMMI_PLATFORMREQ,DMSG_OSSMMI_PLATFORMREQ,SUBPUB> :public CCommand<DMSG_OSSMMI_PLATFORMREQ>
{
private:
	CDDSCommand(const CDDSCommand&);
	CDDSCommand& operator=(const CDDSCommand&);
public:
	static RefPtr<ICommandInterface>& CreateCommand(const std::function<void(DMSG_OSSMMI_PLATFORMREQ*)>& Func,const std::string& _SUBQOS="Reliable",const std::string& _PUBQOS="Reliable",unsigned char CSCI=0,unsigned char CSC=0,unsigned short TopicID=0)
	{
		if(GetCommand() == NULL){
			CDDSCommand<1,DMSG_OSSMMI_PLATFORMREQ,DMSG_OSSMMI_PLATFORMREQ,SUBPUB>* Command = new CDDSCommand<1,DMSG_OSSMMI_PLATFORMREQ,DMSG_OSSMMI_PLATFORMREQ,SUBPUB>(_SUBQOS,_PUBQOS);
			if(Func!=NULL)Command->SetFunc(Func);
			CommandMgr::GetCommandMgr().AddCommand(typeid(DMSG_OSSMMI_PLATFORMREQ).hash_code(),Command);
		}
		return GetCommand();
	}
	CDDSCommand(const std::string& _SUBQOS="Reliable",const std::string& _PUBQOS="Reliable") : SUBQOS(_SUBQOS),PUBQOS(_PUBQOS)
	{
		Create();
	}
	virtual ~CDDSCommand()
	{
	}

	int Send(DMSG_OSSMMI_PLATFORMREQ* msg){
		if(LDDS_ISSETWRITE(1,DMSG_OSSMMI_PLATFORMREQ)){
			int nRetCode = LDDS_WRITE(1,DMSG_OSSMMI_PLATFORMREQ,msg);
			return nRetCode;
		}
		return -1;
	}

	void Create(){
		LDDS_CREATE_TOPIC(1,DMSG_OSSMMI_PLATFORMREQ,SUBQOS.c_str(),true,false,NULL);
		LDDS_CREATE_TOPIC(1,DMSG_OSSMMI_PLATFORMREQ,SUBQOS.c_str(),false,true,(CALLBACK_FUNC)Callback<DMSG_OSSMMI_PLATFORMREQ>);
	}

private:
	std::string SUBQOS;
	std::string PUBQOS;
	std::function<void(DMSG_OSSMMI_PLATFORMREQ*)> m_Func;
};
template <> 
class CDDSCommand<1,DMSG_OSSMMI_PLATFORMREQ,DMSG_OSSMMI_PLATFORMREQ,PUBMode> :public CCommand<DMSG_OSSMMI_PLATFORMREQ>
{
private:
	CDDSCommand(const CDDSCommand&);
	CDDSCommand& operator=(const CDDSCommand&);
public:
	static RefPtr<ICommandInterface>& CreateCommand(const std::function<void(DMSG_OSSMMI_PLATFORMREQ*)>& Func,const std::string& _SUBQOS="Reliable",const std::string& _PUBQOS="Reliable",unsigned char CSCI=0,unsigned char CSC=0,unsigned short TopicID=0)
	{
		if(GetCommand() == NULL){
			CDDSCommand<1,DMSG_OSSMMI_PLATFORMREQ,DMSG_OSSMMI_PLATFORMREQ,PUBMode>* Command = new CDDSCommand<1,DMSG_OSSMMI_PLATFORMREQ,DMSG_OSSMMI_PLATFORMREQ,PUBMode>(_SUBQOS,_PUBQOS);
			CommandMgr::GetCommandMgr().AddCommand(typeid(DMSG_OSSMMI_PLATFORMREQ).hash_code(),Command);
		}
		return GetCommand();
	}
	CDDSCommand(const std::string& _SUBQOS="Reliable",const std::string& _PUBQOS="Reliable") : SUBQOS(_SUBQOS),PUBQOS(_PUBQOS)
	{
		Create();
	}
	virtual ~CDDSCommand()
	{
	}

	int Send(DMSG_OSSMMI_PLATFORMREQ* msg){
		if(LDDS_ISSETWRITE(1,DMSG_OSSMMI_PLATFORMREQ)){
			int nRetCode = LDDS_WRITE(1,DMSG_OSSMMI_PLATFORMREQ,msg);
			return nRetCode;
		}
		return -1;
	}

	void Create(){
		LDDS_CREATE_TOPIC(1,DMSG_OSSMMI_PLATFORMREQ,SUBQOS.c_str(),true,false,NULL);
	}

private:
	std::string SUBQOS;
	std::string PUBQOS;
};
template <> 
class CDDSCommand<1,DMSG_OSSMMI_PLATFORMREQ,DMSG_OSSMMI_PLATFORMREQ,SUBMode> :public CCommand<DMSG_OSSMMI_PLATFORMREQ>
{
private:
	CDDSCommand(const CDDSCommand&);
	CDDSCommand& operator=(const CDDSCommand&);
public:
	static RefPtr<ICommandInterface>& CreateCommand(const std::function<void(DMSG_OSSMMI_PLATFORMREQ*)>& Func,const std::string& _SUBQOS="Reliable",const std::string& _PUBQOS="Reliable",unsigned char CSCI=0,unsigned char CSC=0,unsigned short TopicID=0)
	{
		if(GetCommand() == NULL){
			CDDSCommand<1,DMSG_OSSMMI_PLATFORMREQ,DMSG_OSSMMI_PLATFORMREQ,SUBMode>* Command = new CDDSCommand<1,DMSG_OSSMMI_PLATFORMREQ,DMSG_OSSMMI_PLATFORMREQ,SUBMode>(_SUBQOS,_PUBQOS);
			if(Func!=NULL)Command->SetFunc(Func);
			CommandMgr::GetCommandMgr().AddCommand(typeid(DMSG_OSSMMI_PLATFORMREQ).hash_code(),Command);
		}
		return GetCommand();
	}
	CDDSCommand(const std::string& _SUBQOS="Reliable",const std::string& _PUBQOS="Reliable") : SUBQOS(_SUBQOS),PUBQOS(_PUBQOS)
	{
		Create();
	}
	virtual ~CDDSCommand()
	{
	}

	int Send(DMSG_OSSMMI_PLATFORMREQ* msg){
		if(LDDS_ISSETWRITE(1,DMSG_OSSMMI_PLATFORMREQ)){
			int nRetCode = LDDS_WRITE(1,DMSG_OSSMMI_PLATFORMREQ,msg);
			return nRetCode;
		}
		return -1;
	}

	void Create(){
		LDDS_CREATE_TOPIC(1,DMSG_OSSMMI_PLATFORMREQ,SUBQOS.c_str(),false,true,(CALLBACK_FUNC)Callback<DMSG_OSSMMI_PLATFORMREQ>);
	}

private:
	std::string SUBQOS;
	std::string PUBQOS;
	std::function<void(DMSG_OSSMMI_PLATFORMREQ*)> m_Func;
};
#else
/*!	@class	CDDSCommand
 *	@brief	DDS 커맨드 인터페이스
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
template <int nDomain,typename SUB,typename PUB=SUB,DDSType nType = SUBPUB> 
class CDDSCommand : public CCommand<SUB> {

private:
	CDDSCommand(const CDDSCommand&);
	CDDSCommand& operator=(const CDDSCommand&);
public:

	/*!	@fn	CDDSCommand<nDomain, SUB, PUB, nType>::CreateCommand
	 *	@brief	추적성 : 해당없음 \n
				설명  : 커맨드를 생성한다.
	 *	@param	Func : 콜백 함수
	 *	@param	_SUBQOS : Sub QOS Type
	 *	@param	_PUBQOS : Pub QOS Type
	 *	@param	CSCI : CSCI ID
	 *	@param	CSC : CSC ID
	 *	@param	TopicID :  Topic ID
	 *	@return	RefPtr<ICommandInterface>&
	 *	@author	박현(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	static RefPtr<ICommandInterface>& CreateCommand(const std::function<void(SUB*)>& Func,const std::string& _SUBQOS="Reliable",const std::string& _PUBQOS="Reliable",unsigned char CSCI=0,unsigned char CSC=0,unsigned short TopicID=0)
	{
		if(GetCommand() == NULL){
			CDDSCommand<nDomain,SUB,PUB,nType>* Command = new CDDSCommand<nDomain,SUB,PUB,nType>(_SUBQOS,_PUBQOS);
			if(CSCI != 0 || CSC != 0 || TopicID != 0) Command->setMessageHeader(nDomain,CSCI,CSC,TopicID);
			if(Func == NULL)
			{
				Command->setStatus(Active);
			}else{
				Command->SetFunc(Func);
			}
			CommandMgr::GetCommandMgr().AddCommand(typeid(SUB).hash_code(),Command);
		}
		return GetCommand();
	}
	CDDSCommand(const std::string& _SUBQOS="Reliable",const std::string& _PUBQOS="Reliable") : SUBQOS(_SUBQOS),PUBQOS(_PUBQOS)
	{
		Create();
		setStatus(Active);
	}
	virtual ~CDDSCommand()
	{
		Delete();
	}
	/*!	@fn	CDDSCommand<nDomain, SUB, PUB, nType>::setStatus
	 *	@brief	추적성 : 해당없음 \n
				설명  : 상태 설정
	 *	@param	status : Active/Standby/Disable
	 *	@return	void
	 *	@author	박현(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	void setStatus(DDSStatus status)
	{
		m_status = status;
	}
	/*!	@fn	CDDSCommand<nDomain, SUB, PUB, nType>::Send
	 *	@brief	추적성 : 해당없음 \n
				설명  : Topic 전송
	 *	@param	msg : 전송할 메시지
	 *	@return	int
	 *	@author	박현(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	int Send(SUB* msg){
		if(m_status == Active){
			if(LBTS_DDS::IsSetWriter_G<nDomain,SUB,SUB::DataWriter,SUB::DataReader,SUB::Seq,SUB::TypeSupport>()){
				int nRetCode = LBTS_DDS::Write_G<nDomain, SUB, SUB::DataWriter,SUB::DataReader,SUB::Seq,SUB::TypeSupport>(msg);
				return nRetCode;
			}
			return -1;
		}else{
			return m_status; /// DisActive
		}
	}
	/*!	@fn	CDDSCommand<nDomain, SUB, PUB, nType>::PrintData
	 *	@brief	추적성 : 해당없음 \n
				설명  : 데이터 출력
	 *	@param	msg : 출력할 메시지
	 *	@return	void
	 *	@author	박현(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	void PrintData(const SUB* msg)
	{
		SUB::TypeSupport::PrintData(msg);
	}

	/*!	@fn	CDDSCommand<nDomain, SUB, PUB, nType>::setMessageHeader
	 *	@brief	추적성 : 해당없음 \n
				설명  : 메시지 헤더 설정
	 *	@param	domain : 도메인 아이디
	 *	@param	CSCI : CSCI ID
	 *	@param	CSC : CSC ID
	 *	@param	TopicID : Topic ID
	 *	@return	void
	 *	@author	박현(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	void setMessageHeader(unsigned short domain,unsigned char CSCI,unsigned char CSC,unsigned short TopicID)
	{
		m_Header.unDomain = domain;
		m_Header.bySendCSCI = CSCI;
		m_Header.bySendCSC = CSC;
		m_Header.unTopicID = TopicID;
	}
	DDSHeader getMessageHeader()
	{
		return m_Header;
	}
	/*!	@fn	CDDSCommand<nDomain, SUB, PUB, nType>::Create
	 *	@brief	추적성 : 해당없음 \n
				설명  : 토픽 생성
	 *	@return	void
	 *	@author	박현(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	void Create(){
		switch(nType){
		case SUBPUB:
			LBTS_DDS::CreateTopic_G<nDomain, SUB, SUB::DataWriter,SUB::DataReader,SUB::Seq,SUB::TypeSupport>(SUBQOS.c_str(), false, true, (CALLBACK_FUNC)Callback<SUB> );
			LBTS_DDS::CreateTopic_G<nDomain, PUB, PUB::DataWriter,PUB::DataReader,PUB::Seq,PUB::TypeSupport>(PUBQOS.c_str(), true, false, 0);
			break;
		case SUBMode:
			LBTS_DDS::CreateTopic_G<nDomain, SUB, SUB::DataWriter,SUB::DataReader,SUB::Seq,SUB::TypeSupport>(SUBQOS.c_str(), false, true, (CALLBACK_FUNC)Callback<SUB>);
			break;
		case PUBMode:
			LBTS_DDS::CreateTopic_G<nDomain, SUB, SUB::DataWriter,SUB::DataReader,SUB::Seq,SUB::TypeSupport>(SUBQOS.c_str(), true, false, 0);
			break;
		}
	}
	/*!	@fn	CDDSCommand::Delete
	 *	@brief	추적성 : 해당없음 \n
				설명  : 토픽 제거
	 *	@return	bool
	 *	@author	박현(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	template<typename Target>
	bool Delete()
	{
		LBTS_DDS::DeleteTopic_G<nDomain, Target, Target::DataWriter, Target::DataReader, Target::Seq, Target::TypeSupport>();
		return true;
	}
	/*!	@fn	CDDSCommand<nDomain, SUB, PUB, nType>::Delete
	 *	@brief	추적성 : 해당없음 \n
				설명  : 토픽 제거
	 *	@return	void
	 *	@author	박현(hyunpark@endcs.net)
	 *	@date	2014-11-10
	 */
	void Delete()
	{
		if(nType == SUBPUB){
			Delete<PUB>();
			Delete<SUB>();
		}else{
			Delete<SUB>();
		}
		printf("[%s] Delete Topic \n",typeid(SUB).name());
	}

private:
	std::string SUBQOS;
	std::string PUBQOS;
	DDSHeader m_Header;
	DDSStatus m_status;
	std::function<void(SUB*)> m_Func;

};
#endif