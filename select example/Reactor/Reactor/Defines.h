#ifndef	_DEFINES_H_
#define	_DEFINES_H_

//#define	X1_FAIL		-1
//#define	X1_SUCCESS	1

#define		DEL(p)		do{if(p) {delete p; p = NULL;}} while(0);
#define		DEL_A(p)	do{if(p) {delete[] p; p = NULL;}} while(0);

#define		ET		int/*EventHandler::EVENT_TYPE*/

#if defined(_X1_WINDOWS_)
	#define		X1_TRACE()		printf("[TRACE] [%s:%d]\n", __FUNCTION__, __LINE__);
#elif defined(_X1_LINUX_)
	#define		X1_TRACE()		printf("[TRACE] [%s:%d]\n", __PRETTY_FUNCTION__, __LINE__);
#endif

#define NS_X1_START		namespace X1 {
#define NS_X1_END		}
#define NS_X1			X1
#define US_X1			using namespace NS_X1;

#if defined(_X1_WINDOWS_)
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

#endif	//_DEFINES_H_
