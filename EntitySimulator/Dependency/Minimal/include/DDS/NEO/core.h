/*
코어의 메인 헤더파일

작성자 :
이력
2010-07-12 : 시작
*/

#if !defined(__CORE_H)
#define __CORE_H

#define QOS_EF
#define QOS_RL
#define QOS_H_R
#define QOS_O
#define QOS_L

#ifdef __APPLE__
# include <stdlib.h>
#else
#	include <malloc.h>
#endif
#include <string.h>
#include <stdarg.h>

#define pseokil_141113 1		// NeoDDS_v1.0에 최초 Merge
#define pseokil_141114 1		// Lock과 Update를 한번만 하기 위해 수정한 버전
#define pseokil_141117 1		// 종료 시 죽는 문제
#define pseokil_141209 1		// CPU 소모량을 줄이기 위해 수정 (LIGNex1의 issue)

//#define _JWKIM_141204_EXIT_ISSUE							: 종료시 문제되는 부분 수정
//#define _JWKIM_141204_EXIT_ISSUE_OPTIONAL					: 종료시 문제될 가능성 있는 부분 수정
//#define _JWKIM_REMOVE_WARNING								: 컴파일시 warning 제거
//#define DDS_147_JWKIM_141204_MULTI_DOMAIN					: 멀티도메인 구현
//#define DDS_147_JWKIM_141205_MULTI_DOMAIN_QOS				: QOS 관련 함수 멀티도메인 구현
//#define DDS_147_JWKIM_141208_MULTI_DOMAIN_QOS_LIVENESSTHREAD : livenessThread 관련 멀티도메인 구현
//#define DDS_180_JWKIM_141211_GET_DISCOVERED_PARTICIPANT	: get_discovered_participants & get_discovered_pariticipant_data API 수정
//#define _JWKIM_141211_EXIT_ISSUE							: 종료시 문제되는 부분 추가수정(read thread 종료, cond_wait 수정

#ifdef _MSC_VER
#define msleep(delay)		Sleep( (int) (delay / 1000) )
#else

#ifdef Android
#define msleep(delay)		usleep(delay);
#else

#define msleep(delay)		{\
struct timespec ts_delay; \
	ts_delay.tv_sec = delay / 1000000; \
	ts_delay.tv_nsec = (delay % 1000000) * 1000; \
	nanosleep(&ts_delay, NULL); \
}

#endif

#endif
#define CLOCK_FREQ			1000000
#define DEFAULT_PTS_DELAY   (mtime_t)(.3*CLOCK_FREQ)
#define THREAD_SLEEP		((mtime_t)(0.010*CLOCK_FREQ))

#ifdef _MSC_VER
#	define inline __inline
#	pragma warning(disable : 4996)
#	define strcasecmp stricmp
#	define snprintf _snprintf
#endif


#if defined( _MSC_VER )
#	if defined(UNDER_CE) && defined(sockaddr_storage)
#       undef sockaddr_storage
#	endif
#   if defined(UNDER_CE)
#       define HAVE_STRUCT_ADDRINFO
#	else
//#       include <io.h>
#   endif
#   include <winsock2.h>
#   include <ws2tcpip.h>
#   include <iphlpapi.h>
#	ifndef ENETUNREACH
#		if _MSC_VER < 1600
#		define ENETUNREACH WSAENETUNREACH
#		endif
#	endif
#   define net_errno (WSAGetLastError())

#else
#   if HAVE_SYS_SOCKET_H
#      include <sys/socket.h>
#   endif
#   if HAVE_NETINET_IN_H
#      include <netinet/in.h>
#   endif
#   if HAVE_ARPA_INET_H
#      include <arpa/inet.h>
#   elif defined( SYS_BEOS )
#      include <net/netdb.h>
#   endif
#   include <netdb.h>
#   define net_errno errno
#   define net_strerror strerror
#endif

#include <fcntl.h>

#ifdef _MSC_VER
#	include <io.h>
#endif

///////////////////////////////////////////////////
// 메모리 할당 및 해제시 제되로 되었는지 알아보기 위해서, 출력


#ifdef _MSC_VER
//#	define __MEMEMORY_TRACING
#endif

#ifdef __MEMEMORY_TRACING
#	define malloc(x)		tracemalloc(__FUNCDNAME__,#x,x)
#	define free(x)			tracefree(__FUNCDNAME__,#x,x)
#	define strdup(x)		tracestrdup(__FUNCDNAME__,#x,x)
#	define realloc(x, y)	tracerealloc(__FUNCDNAME__,#x,x, y)
#endif

#ifdef __cplusplus
extern "C" {
#endif
	void *tracemalloc(const char *p_funcname, const char *p_name, size_t size);
	void tracefree(const char *p_funcname, const char *p_name, void *ptr);
	char *tracestrdup(const char *p_funcname, const char *p_name, const char *psz);
	void *tracerealloc(const char *p_funcname, const char *p_name, void *ptr, size_t size);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __MEMEMORY_TRACING
	static inline void* malloc_zero(size_t x)
	{
		void * v_xx = malloc(x);
		memset(v_xx, 0, x);

		return v_xx;
	}

#endif



#ifdef __cplusplus
}
#endif

#ifndef __cplusplus

#ifdef __MEMEMORY_TRACING
//#	define malloc(x) malloc_zero(x)
#else
#	define malloc(x) malloc_zero(x)
#endif

#endif

//#define BEFOR_PRINT_MALLOC_TRACE \
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),\
//                    FOREGROUND_INTENSITY | FOREGROUND_GREEN |\
//                    FOREGROUND_BLUE);



///////////////////////////////////////////////////
#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

#ifndef __cplusplus
#ifndef bool
#define bool char
#endif
#endif



#ifndef __cplusplus
#define false 0
#define true  1
#endif

#define FREE(x) if(x) {free(x); x=NULL;}


enum TRACE_TYPE
{
	TRACE_NORMAL,
	TRACE_ERROR,
	TRACE_WARM,
	TRACE_DEBUG,
	TRACE_TRACE,
	TRACE_TRACE2,
	TRACE_TRACE3,
	TRACE_LOG
};

//////////  struct define /////////////////////////

typedef struct module_object_t module_object_t;
typedef struct module_bank_t module_bank_t;
typedef struct libmodule_t libmodule_t;
typedef struct module_t module_t;
typedef struct moduleload_t moduleload_t;
typedef struct module_config_t module_config_t;
typedef struct module_list_t module_list_t;

typedef struct trace_t trace_t;
typedef struct service_t service_t;
typedef struct typesupport_t typesupport_t;
typedef struct discovery_t discovery_t;
typedef struct qos_policy_t qos_policy_t;//by kki (qos module)

//////////////////////////////////////////////////
typedef struct trace_sys_t trace_sys_t;

///////////////////////////////////////////////////
typedef struct variable_t variable_t;
typedef struct callback_entry_t callback_entry_t;

///////////////////////////////////////////////////
#ifndef DOMAINPARTICIPANT_DEFINE
#define DOMAINPARTICIPANT_DEFINE 1
typedef struct DomainParticipant DomainParticipant;
#endif
#ifndef WAITSET_DEFINE
#define WAITSET_DEFINE 1
typedef struct WaitSet WaitSet;
#endif

typedef struct message_t message_t;
typedef struct message_fifo_t message_fifo_t;
typedef struct management_t management_t;
typedef struct access_t access_t;
typedef struct access_out_t access_out_t;
typedef struct data_t data_t;
typedef struct data_fifo_t data_fifo_t;
typedef struct dds_string dds_string;

#include <thread.h>
#include <module_common.h>
#include <module_config.h>
#include <trace.h>
#include <service.h>
#include <configuration.h>
#include <util.h>
#include <typesupport.h>

#include <management.h>
#include <network.h>
#include <access.h>
#include <data.h>
#include <discovery.h>
#include <qos_policy.h>//by kki (qos module)

#include <stdlib.h>
#include <assert.h>

#ifndef THREAD_PRIORITY_HIGHEST
#	define THREAD_PRIORITY_HIGHEST 0
#endif

/***************************************************************
# 작성자: eunji.you (eunji@mdstec.com)
# 이력  :
[2013-12-12]
- port setting regard to domain id.
- port setting algorithm for specification
[2013-12-17]
- 임시 주석 처리
[2013-12-18]
- 구조 변경
***************************************************************/
#if 1

typedef struct Domain_port Domain_port;

struct Domain_port {
	int spdp;
	int sedp;
	int data;
};

#ifdef __cplusplus
extern "C" {
#endif
	void domain_port_set(int domain_id);	// Network Port Setting regard to Domain ID 
	Domain_port domain_port_get();			// get the Network Port already setting.
#ifdef __cplusplus
}
#endif

#endif

// [20140703] by eunji
#ifdef DISCOVERY_TEST
typedef struct _INTERNAL_TIME
{
	int hour;
	int min;
	int sec;
	int ms;
}_INTERNAL_TIME;

#ifdef __cplusplus
extern "C" {
#endif
	_INTERNAL_TIME _get_current_time();
	void at_the_time_execution(time_t reserve_time);

#ifdef __cplusplus
}
#endif
#endif
// end
#endif

#ifndef DDS_147_JWKIM_141204_MULTI_DOMAIN	//jwkim : MultiDomain 지원을 위한 상수 추가
#define MAX_MULTI_DOMAIN_SIZE				255		//jwkim : Max multi domain count, 최대가능한 domainID가 255까지라고 함(조부장님:도메인에 따른 포트결정식에 따라 포트할당가능영역이 제한됨)
#define BUILTIN_DOMAIN_ID_CHANGE_CONSTANT	1000	//jwkim : BuiltinDomainParticipant DomainID = UserDomainPacitipant DomainID - BUILTIN_DOMAIN_ID_CHANGE_CONSTANT
#define NOT_ASSGINED_DOMAIN_ID				-9999	//jwkim : 초기 domainID
#define ROOT_DOMAIN_ID						-10000	//jwkim : root 모듈을 위한 domainID
#endif //DDS_147_JWKIM_141204_MULTI_DOMAIN



