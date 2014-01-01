#pragma once

#include "os.h"








// hash_map
#if defined(OS_WINDOWS)
	#include <hash_map>
	#define ecila_hash_map	stdext::hash_map
#elif defined(OS_LINUX)
	#ifdef __GNUC__
//		#include <features.h>
//
//		#if __GNUC_PREREQ (4,2)
//			//gcc_version >= 4.2
//			#include <unordered_map>
//			#define ecila_hash_map	std::unordered_map

//		#elif __GNUC_PREREQ (4,0)
//			//gcc_version >= 4.0
			#include <tr1/unordered_map>
			#define ecila_hash_map	std::unordered_map
//		#else
//			#include <ext/hash_map>
//			#define ecila_hash_map	__gnu_cxx::hash_map
//		#endif

	#endif
#else
//	#include <ext/hash_map>
//	#define ecila_hash_map	__gnu_cxx::hash_map
	#include <tr1/unordered_map>
	#define ecila_hash_map	std::unordered_map
#endif








// macro function
#if defined(OS_WINDOWS)

	//string to real number
	#define ecila_atoi32					atoi
	#define ecila_atoui32					(uint32_t)atoi
	#define ecila_atoi64					_atoi64
	#define ecila_atoui64					(uint64_t)_atoi64
	#define ecila_atof32					(float_t)atof
	#define ecila_atof64					atof

	//string handling
	#define ecila_strlen					strlen
	#define ecila_strncmp					strncmp
	#define ecila_strnicmp					_strnicmp
	#define ecila_strncpy					strncpy_s
	#define ecila_sprintf(b, s, ...)		sprintf_s((b), (s), __VA_ARGS__)
	#define ecila_vsprintf(b, s, ...)		vsprintf_s((b), (s), __VA_ARGS__)
	#define ecila_strtok					strtok_s

#else
	
	//string to real number
	#define ecila_atoi32					atoi
	#define ecila_atoui32					(uint32_t)atoi
	#define ecila_atoi64					atoll
	#define ecila_atoui64					(uint64_t)atoll
	#define ecila_atof32					(float_t)atof
	#define ecila_atof64					atof

	//string handling
	#define ecila_strlen					strlen
	#define ecila_strncmp					strncmp
	#define ecila_strnicmp					strncasecmp
	#define ecila_strncpy					strncpy
	#define ecila_sprintf(b, s, ...)		sprintf((b), __VA_ARGS__)
	#define ecila_vsprintf(b, s, ...)		vsprintf((b), __VA_ARGS__)
	#define ecila_strtok					strtok_r

#endif







#if defined(OS_WINDOWS)
	#define DECL_SPEC_DLL_EXPORT	__declspec(dllexport)
	#define DECL_SPEC_DLL_IMPORT	__declspec(dllimport)
	#define DECL_SPEC_TLS			__declspec(thread)
	#ifdef USE_DLL_EXPORT
		#define DECL_SPEC_DLL		DECL_SPEC_DLL_EXPORT
	#else
		#define DECL_SPEC_DLL		DECL_SPEC_DLL_IMPORT
	#endif
#else
	#define DECL_SPEC_DLL_EXPORT
	#define DECL_SPEC_DLL_IMPORT
	#define DECL_SPEC_DLL
	#define DECL_SPEC_TLS			__thread
#endif








//fomat string
#if defined(OS_WINDOWS)
	#define ECILA_FI64D		"%I64d"
	#define ECILA_FI64U		"%I64u"
	#define ECILA_FI64X		"%I64x"
#else
	#define ECILA_FI64D		"%lld"
	#define ECILA_FI64U		"%llu"
	#define ECILA_FI64X		"%llx"
#endif








// infra assert
#define ECILA_ASSERT(x)	assert(x)






// safe delete
#if defined(OS_WINDOWS)
	#define ECILA_SAFE_DELETE(x)		do { delete x;		x = 0; } while(0,0);
	#define ECILA_SAFE_DELETE_ARRAY(x)	do { delete[] x;	x = 0; } while(0,0);
#else
	#define ECILA_SAFE_DELETE(x)		do { if(x != NULL) { delete x; }	x = 0; } while(0);
	#define ECILA_SAFE_DELETE_ARRAY(x)	do { if(x != NULL) { delete[] x; }	x = 0; } while(0);
#endif






// infra logger
#if defined(OS_WINDOWS)
	#define	ECILA_PRINT(x)	printf x
	#define ECILA_ERROR(x)	printf x
	#define ECILA_TRACE()	printf("[TRACE] [%s:%d]\n", __FUNCTION__, __LINE__);
#else
	#define	ECILA_PRINT(x)	printf x
	#define ECILA_ERROR(x)	printf x
	#define ECILA_TRACE()	printf("[TRACE] [%s:%d]\n", __PRETTY_FUNCTION__, __LINE__);
#endif






//compile time log
#if defined(USE_DEBUG_MODE)
	#if defined(OS_WINDOWS)
		#define ECILA_STR2(x)	#x
		#define ECILA_STR(x)	ECILA_STR2(x)

		#define COMPILE_LOG(msg) do { __pragma (message(__FILE__ "(" ECILA_STR(__LINE__) "): [TODO] : " #msg)) } while(0, 0)
	#else
		#define COMPILE_LOG(msg)
	#endif
#endif

