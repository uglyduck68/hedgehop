/**
* @file		Defines.h
* @auther	Younghwan Kim<uglyduck68@gmail.com>
* @version	0.1
* @date		20140816
* @brief	This file has all macro defines.
*/
#define NS_X1			X1
#define NS_X1_START		namespace NS_X1 {
#define NS_X1_END		}

#define NS_X1_USE		using namespace NS_X1;

#if defined(WIN32)
	#define DECL_SPEC_DLL_EXPORT	__declspec(dllexport)
	#define DECL_SPEC_DLL_IMPORT	__declspec(dllimport)
	#define DECL_SPEC_TLS			__declspec(thread)
	#ifdef USE_DLL_EXPORT
		#define DECL_SPEC_DLL		DECL_SPEC_DLL_EXPORT
	#else
		#define DECL_SPEC_DLL		DECL_SPEC_DLL_IMPORT
	#endif
#else
	/// pthread
	#define DECL_SPEC_DLL_EXPORT
	#define DECL_SPEC_DLL_IMPORT
	#define DECL_SPEC_DLL
	#define DECL_SPEC_TLS			__thread
#endif

/** for test program */
#define DECL_SPEC_DLL
