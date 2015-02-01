#ifndef LBTS_DDS_LIBRARY
#define LBTS_DDS_LIBRARY

/************************************************************************************

							NEO-DDS LBTS DDS Library


 # MDS Technology Co., Ltd.
 # version : 1.0
 # History
	[2013.11.21] Byungung Min(byungung@mdstec.com)
	- NEO-DDS Engine 楷悼阑 困茄 LBTS_DDS_LIBRARY v1.0 积己

 *************************************************************************************/


#include <string>
#include <core.h>
#include <cpsdcps.h>
#include <dcps_func.h>
#include <SetQosXml.h>


#define UM_DDS_WRITER(tDDSMsg)		FooDataWriter
#define UM_DDS_READER(tDDSMsg)		FooDataReader
#define UM_DDS_SEQ(tDDSMsg)			FooSeq
#define UM_DDS_TYPESUPP(tDDSMsg)	tDDSMsg##TypeSupport
#define UM_DDS_TYPE_NAME(tDDSMsg)	#tDDSMsg
#define UM_DDS_LISTENER(tDDSMsg)	CDDSListener<UM_DDS_READER(tDDSMsg), UM_DDS_SEQ(tDDSMsg)>


typedef void (*CALLBACK_FUNC)(void*);


#define _REMOVE_ELEM( p_ar, i_oldsize, i_pos )										\
    do																				\
    {																				\
        if( (i_oldsize) - (i_pos) - 1 )												\
        {																			\
            memmove( (p_ar) + (i_pos),												\
                     (p_ar) + (i_pos) + 1,											\
                     ((i_oldsize) - (i_pos) - 1) * sizeof( *(p_ar) ) );				\
        }																			\
        if( i_oldsize > 1 )															\
        {																			\
            (p_ar) = (Foo**)realloc( p_ar, ((i_oldsize) - 1) * sizeof( *(p_ar) ) );	\
        }																			\
        else																		\
        {																			\
            FREE( p_ar );															\
            (p_ar) = NULL;															\
        }																			\
        (i_oldsize)--;																\
    }																				\
    while( 0 )


namespace LBTS_DDS {

template<int nDomainID>
class CDDSDomain {
private:
	DomainParticipantFactory *p_dpf;
public:
	int						m_nDomainID;
	DomainParticipant*	m_pParticipant;
	Publisher*			m_pPublisher;
	Subscriber*			m_pSubscriber;
	std::string				m_strQosName;
	unsigned int			m_nIPCount;
	std::string				m_strIP;
	long unsigned					m_nAppID;

	template<typename T>
	struct Inline_static_ddsdomain {
		T& get() {
			static T t;
			return t;
		}
	};

	static CDDSDomain<nDomainID>& singleton() {
		static Inline_static_ddsdomain<CDDSDomain<nDomainID> > tDDSDomain;
		tDDSDomain.get().m_nDomainID = nDomainID;
		return tDDSDomain.get();
	}

	bool CreateDomainPubSub() 
	{
		bool bResult = true;
		if (m_pParticipant == NULL) 
		{
			//StatusMask mask = 0xffffffff;
			StatusMask mask = 0;
			PublisherQos publisherQos;
			SubscriberQos subscriberQos;

			// 20131128
			memset(&publisherQos, 0, sizeof(PublisherQos));
			memset(&subscriberQos, 0, sizeof(SubscriberQos));

#if 1 // MDS, 20131213
			if (m_nIPCount > 0)
			{
				NeoDDS_transport_property_ipcnt(m_nIPCount);

				for(unsigned int i=0;i<m_nIPCount;i++)
				{
					std::string strIP;
					static unsigned int nFirst = 0;
					int nIndex = m_strIP.find(",", nFirst);
					if (nIndex != -1)
						strIP = m_strIP.substr(nFirst, nIndex);
					else if (i == m_nIPCount - 1 && nFirst < m_strIP.length()) 
					{
						nIndex = m_strIP.length();
						strIP = m_strIP.substr(nFirst, nIndex);
					}

					NeoDDS_transport_property_ipaddr(strIP.c_str());

					printf("DDS DOMAIN [%d] : IP SET [%d][%s] \n", m_nDomainID, i + 1, strIP.c_str());
					nFirst = nIndex + 1;
				}
			}
#endif
			//set_global_domain_id(m_nDomainID);
			p_dpf = DomainParticipantFactory_get_instance();
			if(!p_dpf)
				return false;

			m_pParticipant = p_dpf->create_participant(m_nDomainID, NULL, NULL, mask);

			static_get_default_publisher_qos(&publisherQos);
			static_get_default_subscriber_qos(&subscriberQos);

			if (m_pParticipant != NULL) 
			{
				//publisher积己
				m_pPublisher = m_pParticipant->create_publisher(m_pParticipant, &publisherQos, NULL, mask);
				if (m_pPublisher == NULL)
					bResult = false;

				//subscriber积己
				m_pSubscriber = m_pParticipant->create_subscriber(m_pParticipant, &subscriberQos, NULL, mask);
				if (m_pSubscriber == NULL)
					bResult = false;
			} 
			else
				bResult = false;
		}
		return bResult;
	}

	~CDDSDomain() 
	{
		Finalize();
	}

	int Finalize() 
	{
		dds_quit();
		m_pParticipant	= NULL;
		p_dpf			= NULL;
		return RETCODE_OK;
	}
};


template<typename TDataReader, typename TMsgSeq>
class CDDSListener {
public:
	DataReaderListener	datareaderListener;
	CDDSListener()
	{
		datareaderListener.on_data_available = this->on_data_available;	
	}
public:
	void SetCallBackFunc(CALLBACK_FUNC pCallBack) {
		m_CallBack = pCallBack;
	}

	void on_requested_deadline_missed(DataReader* /*reader*/,
			const RequestedDeadlineMissedStatus& /*status*/) {
		;
	}

	void on_requested_incompatible_qos(DataReader* /*reader*/,
			const RequestedIncompatibleQosStatus& /*status*/) {
		printf("on_requested_incompatible_qos~!\n");
	}

	void on_sample_rejected(DataReader* reader,
			const SampleRejectedStatus& status) {
		printf("on_sample_rejected~!\n");
	}

	void on_liveliness_changed(DataReader* reader,
			const LivelinessChangedStatus& status) {
		printf("liveliness changed~!\n");
	}

	void on_sample_lost(DataReader* reader,
			const SampleLostStatus& status) {
		printf("on_sample_lost~!\n");
	}

	void on_subscription_matched(DataReader* /*reader*/,
			const SubscriptionMatchedStatus& /*status*/) {
		;
	}

	static void on_data_available(DataReader* reader) {
		ReturnCode_t retcode;
		FooDataReader *pFDR = (FooDataReader*)reader;
		FooSeq fseq = INIT_FOOSEQ;                
		SampleInfoSeq sSeq = INIT_SAMPLEINFOSEQ;  
		CALLBACK_FUNC _CallBack = reader->p_datareader_listener->m_CallBack;

		retcode = pFDR->take(pFDR, &fseq, &sSeq, LENGTH_UNLIMITED,
				ANY_SAMPLE_STATE, ANY_VIEW_STATE,
				ANY_INSTANCE_STATE);

		if (retcode == RETCODE_NO_DATA) 
		{
			return;
		}
		else if (retcode != RETCODE_OK) 
		{
			printf("take error %d\n", retcode);
			return;
		}
		
		if(fseq.i_seq)
		{
			message_t *p_message = NULL;

			while(fseq.i_seq)
			{
				p_message = (message_t *)fseq.pp_foo[0];

				if(_CallBack)
					_CallBack(p_message->v_data);

				message_release(p_message);
				_REMOVE_ELEM(fseq.pp_foo, fseq.i_seq, 0);	
			}
		}
	}
};



template<int nDomainID, typename TMsg, typename TDataWriter,
		typename TDataReader, typename TMsgSeq, typename TMsgTypeSupport>
class CDDSTopic {
private:
	Topic* m_pTopic;
	TDataWriter* m_pWriter;
	DataReader* m_pReader;
	StatusMask mask;
	CDDSListener<TDataReader, TMsgSeq> m_cListener;

	template<typename T>
	struct Inline_static_ddstopic {
		T& get() {
			static T t;
			return t;
		}
	};

	CDDSTopic() 
	{
		m_pTopic	= NULL;
		m_pWriter	= NULL;
		m_pReader	= NULL;
		//mask		= 0xffffffff;
		mask		= 0;
	}

	~CDDSTopic() 
	{
		Finalize();
	}

	int Finalize() {
		if (m_pTopic)
		{
			m_pTopic	= NULL;
			m_pWriter	= NULL;
			m_pReader	= NULL;
		}

		return 1;
	}

	bool CreateTopic() 
	{
		bool bResult = true;
		TopicQos topicQos;

		memset(&topicQos, 0, sizeof(TopicQos)); // 20131128

		if (NULL == m_pTopic) 
		{
			DomainParticipant* pPaticipant = CDDSDomain<nDomainID>::singleton().m_pParticipant;

			if (pPaticipant != NULL) 
			{
				ReturnCode_t tRetcode = 0;							
				TMsgTypeSupport tsp;
				tsp.register_topic_type(pPaticipant);
				//const _string pszTypeNmae = tsp.fooTS->get_type_name(tsp.fooTS);
				const string_mds pszTypeNmae = tsp.fooTS->get_type_name(tsp.fooTS);

				static_get_default_topic_qos(&topicQos);	

				if (tRetcode != RETCODE_OK) 
				{
					bResult = false;
				} 
				else 
				{
					m_pTopic = pPaticipant->create_topic(pPaticipant, pszTypeNmae, pszTypeNmae, &topicQos, NULL, mask);

					if (m_pTopic == NULL) 
					{
						bResult = false;
					}
				}
			} 
			else
				bResult = false;
		}
		else
		{
			bResult = false; // MDS, 20131126
		}

		return bResult;
	}

public:

	static CDDSTopic<nDomainID, TMsg, TDataWriter, TDataReader, TMsgSeq, TMsgTypeSupport>& singleton() 
	{
		static Inline_static_ddstopic<CDDSTopic<nDomainID, TMsg, TDataWriter, TDataReader, TMsgSeq, TMsgTypeSupport> > tDDSTopic;
		return tDDSTopic.get();
	}

	bool CreateWriter(std::string strQosName) 
	{
		bool bResult = true;

		if (CreateTopic()) 
		{
			std::string strQosName = CDDSDomain<nDomainID>::singleton().m_strQosName;
			DomainParticipant* pPaticipant = CDDSDomain<nDomainID>::singleton().m_pParticipant;
			Publisher* pPub = CDDSDomain<nDomainID>::singleton().m_pPublisher;
			

			DataWriterQos writerQos;

			memset(&writerQos, 0, sizeof(DataWriterQos)); // 20131128

			static_get_default_datawriter_qos(&writerQos);

			if(!strQosName.empty())
			{
				char* ProfileName = new char[strQosName.size() + 1];
				std::copy(strQosName.begin(), strQosName.end(), ProfileName);
				ProfileName[strQosName.size()] = '\0';
				Set_qos_xml("DefaultLibrary",ProfileName,&writerQos, DATAWRITER, "USER_QOS_PROFILES.xml");
				delete[] ProfileName;

			}

			//if(strQosName == std::string("Reliable"))
			//{
			//	/* <Reliability> */
			//	// kind
			//	writerQos.reliability.kind = RELIABLE_RELIABILITY_QOS;

			//	/* <History> */
			//	// depth
			//	writerQos.history.depth = LENGTH_UNLIMITED_RELIABLE;
			//}
			//// else ... default

			m_pWriter = (TDataWriter*)pPub->create_datawriter(pPub, m_pTopic, &writerQos, NULL, mask);

			if (m_pWriter == NULL)		
				bResult = false;
		}
		return bResult;
	}

	bool CreateReader(std::string strQosName, CALLBACK_FUNC pCallBackFunc) 
	{
		bool bResult = true;

		if (CreateTopic()) 
		{
			std::string strQosName = CDDSDomain<nDomainID>::singleton().m_strQosName;
			DomainParticipant* pPaticipant = CDDSDomain<nDomainID>::singleton().m_pParticipant;
			Subscriber* pSub = CDDSDomain<nDomainID>::singleton().m_pSubscriber;
			
			m_cListener.datareaderListener.m_CallBack = pCallBackFunc;

			DataReaderQos readerQos;

			memset(&readerQos, 0, sizeof(DataReaderQos)); // 20131128

			static_get_default_datareader_qos(&readerQos);


			if(!strQosName.empty())
			{
				char* ProfileName = new char[strQosName.size() + 1];
				std::copy(strQosName.begin(), strQosName.end(), ProfileName);
				ProfileName[strQosName.size()] = '\0';
				Set_qos_xml("DefaultLibrary",ProfileName,&readerQos, DATAREADER, "USER_QOS_PROFILES.xml");
				delete[] ProfileName;

			}
			//if(strQosName == std::string("Reliable"))
			//{
			//	/* <Reliability> */
			//	// kind
			//	readerQos.reliability.kind = RELIABLE_RELIABILITY_QOS;

			//	/* <History> */
			//	// depth
			//	readerQos.history.depth = LENGTH_UNLIMITED_RELIABLE;
			//}
			//// else ... default

			m_pReader = pSub->create_datareader(pSub, m_pTopic, &readerQos, &m_cListener.datareaderListener, DATA_AVAILABLE_STATUS);

			if (m_pReader == NULL)
				bResult = false;
		}
		return bResult;
	}

	int Write(TMsg* p_tMsg) 
	{
		int nResult = 0;
		ReturnCode_t tRetcode = 0;

		if (m_pWriter == NULL) {
			printf("datawriter is not created!");
			return -1;
		}

		tRetcode = m_pWriter->write(m_pWriter, (Foo*)p_tMsg, 0);
		nResult = (int) tRetcode;

		return nResult;
	}

	bool IsSetWriter() {
		return (m_pWriter == NULL) ? false : true;
	}

	bool IsSetReader() {
		return (m_pReader == NULL) ? false : true;
	}
};

	template<int nDomainID, typename TMsg, typename TDataWriter, typename TDataReader, typename TMsgSeq, typename TMsgTypeSupport>
	inline void CreateTopic(std::string straQosName, bool bSetWriter, bool bSetReader, CALLBACK_FUNC pCallBackFunc = NULL) 
	{
		CDDSDomain<nDomainID>::singleton().m_strQosName = straQosName;
		CDDSDomain<nDomainID>::singleton().CreateDomainPubSub();

		if (bSetWriter)
			CDDSTopic<nDomainID, TMsg, TDataWriter, TDataReader, TMsgSeq, TMsgTypeSupport>::singleton().CreateWriter(straQosName);
		if (bSetReader)
			CDDSTopic<nDomainID, TMsg, TDataWriter, TDataReader, TMsgSeq, TMsgTypeSupport>::singleton().CreateReader(straQosName, (CALLBACK_FUNC) pCallBackFunc);
	}

	template<int nDomainID, typename TMsg, typename TDataWriter, typename TDataReader, typename TMsgSeq, typename TMsgTypeSupport>
	inline int Write(TMsg* p_tMsg) 
	{
		if (is_dds_quit()) return 0;
		return CDDSTopic<nDomainID, TMsg, TDataWriter, TDataReader, TMsgSeq, TMsgTypeSupport>::singleton().Write(p_tMsg);
	}

	template<int nDomainID, typename TMsg, typename TDataWriter, typename TDataReader, typename TMsgSeq, typename TMsgTypeSupport>
	inline bool IsSetWriter() 
	{
		if (is_dds_quit()) return 0;
		return CDDSTopic<nDomainID, TMsg, TDataWriter, TDataReader, TMsgSeq, TMsgTypeSupport>::singleton().IsSetWriter();
	}

	template<int nDomainID, typename TMsg, typename TDataWriter, typename TDataReader, typename TMsgSeq, typename TMsgTypeSupport>
	inline bool IsSetReader() 
	{
		if (is_dds_quit()) return 0;
		return CDDSTopic<nDomainID, TMsg, TDataWriter, TDataReader, TMsgSeq, TMsgTypeSupport>::singleton().IsSetReader();
	}

	template<int nDomainID>
	inline void SetInterfaceList(std::string straQosName, int nIPcount, std::string strIPList) 
	{
		CDDSDomain<nDomainID>::singleton().m_strQosName = straQosName;
		CDDSDomain<nDomainID>::singleton().m_nIPCount = nIPcount;
		CDDSDomain<nDomainID>::singleton().m_strIP = strIPList;
	}
}

// LDDS : LBTS DDS
#define LDDS_SETIP( nDomainID, strQosName, nIPcount, strIP )	LBTS_DDS::SetInterfaceList<nDomainID>(strQosName, nIPcount, strIP)
#define LDDS_CREATE_TOPIC( nDomainID, TMsg, strQosName, bIsWriter, bIsReader, pCallBack )	LBTS_DDS::CreateTopic<nDomainID, TMsg, UM_DDS_WRITER(TMsg), UM_DDS_READER(TMsg), UM_DDS_SEQ(TMsg), UM_DDS_TYPESUPP(TMsg)>( strQosName, bIsWriter, bIsReader, pCallBack )
#define LDDS_WRITE( nDomainID, TMsg, tRealMsg)	LBTS_DDS::Write<nDomainID, TMsg, UM_DDS_WRITER(TMsg), UM_DDS_READER(TMsg), UM_DDS_SEQ(TMsg), UM_DDS_TYPESUPP(TMsg)>( tRealMsg )
#define LDDS_ISSETWRITE( nDomainID, TMsg)		LBTS_DDS::IsSetWriter<nDomainID, TMsg, UM_DDS_WRITER(TMsg), UM_DDS_READER(TMsg), UM_DDS_SEQ(TMsg), UM_DDS_TYPESUPP(TMsg)>()
#define LDDS_ISSETREADER( nDomainID, TMsg)		LBTS_DDS::IsSetReader<nDomainID, TMsg, UM_DDS_WRITER(TMsg), UM_DDS_READER(TMsg), UM_DDS_SEQ(TMsg), UM_DDS_TYPESUPP(TMsg)>()
#define	LDDS_SHUTDOWN()							dds_quit()


#endif



