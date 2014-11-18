
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_TRRMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef DDS_TRRMMISupport_1980992815_h
#define DDS_TRRMMISupport_1980992815_h

/* Uses */
#include "DDS_TRRMMI.h"



#ifdef __cplusplus
#ifndef ndds_cpp_h
  #include "ndds/ndds_cpp.h"
#endif
#else
#ifndef ndds_c_h
  #include "ndds/ndds_c.h"
#endif
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(DMSG_TRR_TARGETTypeSupport, DMSG_TRR_TARGET);

DDS_DATAWRITER_CPP(DMSG_TRR_TARGETDataWriter, DMSG_TRR_TARGET);
DDS_DATAREADER_CPP(DMSG_TRR_TARGETDataReader, DMSG_TRR_TARGETSeq, DMSG_TRR_TARGET);


#else

DDS_TYPESUPPORT_C(DMSG_TRR_TARGETTypeSupport, DMSG_TRR_TARGET);
DDS_DATAWRITER_C(DMSG_TRR_TARGETDataWriter, DMSG_TRR_TARGET);
DDS_DATAREADER_C(DMSG_TRR_TARGETDataReader, DMSG_TRR_TARGETSeq, DMSG_TRR_TARGET);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(DMSG_TRR_DIRECTORTypeSupport, DMSG_TRR_DIRECTOR);

DDS_DATAWRITER_CPP(DMSG_TRR_DIRECTORDataWriter, DMSG_TRR_DIRECTOR);
DDS_DATAREADER_CPP(DMSG_TRR_DIRECTORDataReader, DMSG_TRR_DIRECTORSeq, DMSG_TRR_DIRECTOR);


#else

DDS_TYPESUPPORT_C(DMSG_TRR_DIRECTORTypeSupport, DMSG_TRR_DIRECTOR);
DDS_DATAWRITER_C(DMSG_TRR_DIRECTORDataWriter, DMSG_TRR_DIRECTOR);
DDS_DATAREADER_C(DMSG_TRR_DIRECTORDataReader, DMSG_TRR_DIRECTORSeq, DMSG_TRR_DIRECTOR);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(DMSG_TRR_TRACKINGTypeSupport, DMSG_TRR_TRACKING);

DDS_DATAWRITER_CPP(DMSG_TRR_TRACKINGDataWriter, DMSG_TRR_TRACKING);
DDS_DATAREADER_CPP(DMSG_TRR_TRACKINGDataReader, DMSG_TRR_TRACKINGSeq, DMSG_TRR_TRACKING);


#else

DDS_TYPESUPPORT_C(DMSG_TRR_TRACKINGTypeSupport, DMSG_TRR_TRACKING);
DDS_DATAWRITER_C(DMSG_TRR_TRACKINGDataWriter, DMSG_TRR_TRACKING);
DDS_DATAREADER_C(DMSG_TRR_TRACKINGDataReader, DMSG_TRR_TRACKINGSeq, DMSG_TRR_TRACKING);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(DMSG_TRR_SHOOTDOWNRESULTTypeSupport, DMSG_TRR_SHOOTDOWNRESULT);

DDS_DATAWRITER_CPP(DMSG_TRR_SHOOTDOWNRESULTDataWriter, DMSG_TRR_SHOOTDOWNRESULT);
DDS_DATAREADER_CPP(DMSG_TRR_SHOOTDOWNRESULTDataReader, DMSG_TRR_SHOOTDOWNRESULTSeq, DMSG_TRR_SHOOTDOWNRESULT);


#else

DDS_TYPESUPPORT_C(DMSG_TRR_SHOOTDOWNRESULTTypeSupport, DMSG_TRR_SHOOTDOWNRESULT);
DDS_DATAWRITER_C(DMSG_TRR_SHOOTDOWNRESULTDataWriter, DMSG_TRR_SHOOTDOWNRESULT);
DDS_DATAREADER_C(DMSG_TRR_SHOOTDOWNRESULTDataReader, DMSG_TRR_SHOOTDOWNRESULTSeq, DMSG_TRR_SHOOTDOWNRESULT);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(DMSG_TRR_SETRESULTTypeSupport, DMSG_TRR_SETRESULT);

DDS_DATAWRITER_CPP(DMSG_TRR_SETRESULTDataWriter, DMSG_TRR_SETRESULT);
DDS_DATAREADER_CPP(DMSG_TRR_SETRESULTDataReader, DMSG_TRR_SETRESULTSeq, DMSG_TRR_SETRESULT);


#else

DDS_TYPESUPPORT_C(DMSG_TRR_SETRESULTTypeSupport, DMSG_TRR_SETRESULT);
DDS_DATAWRITER_C(DMSG_TRR_SETRESULTDataWriter, DMSG_TRR_SETRESULT);
DDS_DATAREADER_C(DMSG_TRR_SETRESULTDataReader, DMSG_TRR_SETRESULTSeq, DMSG_TRR_SETRESULT);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(DMSG_TRR_ASCOPETypeSupport, DMSG_TRR_ASCOPE);

DDS_DATAWRITER_CPP(DMSG_TRR_ASCOPEDataWriter, DMSG_TRR_ASCOPE);
DDS_DATAREADER_CPP(DMSG_TRR_ASCOPEDataReader, DMSG_TRR_ASCOPESeq, DMSG_TRR_ASCOPE);


#else

DDS_TYPESUPPORT_C(DMSG_TRR_ASCOPETypeSupport, DMSG_TRR_ASCOPE);
DDS_DATAWRITER_C(DMSG_TRR_ASCOPEDataWriter, DMSG_TRR_ASCOPE);
DDS_DATAREADER_C(DMSG_TRR_ASCOPEDataReader, DMSG_TRR_ASCOPESeq, DMSG_TRR_ASCOPE);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(DMSG_TRR_STATETypeSupport, DMSG_TRR_STATE);

DDS_DATAWRITER_CPP(DMSG_TRR_STATEDataWriter, DMSG_TRR_STATE);
DDS_DATAREADER_CPP(DMSG_TRR_STATEDataReader, DMSG_TRR_STATESeq, DMSG_TRR_STATE);


#else

DDS_TYPESUPPORT_C(DMSG_TRR_STATETypeSupport, DMSG_TRR_STATE);
DDS_DATAWRITER_C(DMSG_TRR_STATEDataWriter, DMSG_TRR_STATE);
DDS_DATAREADER_C(DMSG_TRR_STATEDataReader, DMSG_TRR_STATESeq, DMSG_TRR_STATE);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(DMSG_HMI_TRRRDRCHECKREQTypeSupport, DMSG_HMI_TRRRDRCHECKREQ);

DDS_DATAWRITER_CPP(DMSG_HMI_TRRRDRCHECKREQDataWriter, DMSG_HMI_TRRRDRCHECKREQ);
DDS_DATAREADER_CPP(DMSG_HMI_TRRRDRCHECKREQDataReader, DMSG_HMI_TRRRDRCHECKREQSeq, DMSG_HMI_TRRRDRCHECKREQ);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TRRRDRCHECKREQTypeSupport, DMSG_HMI_TRRRDRCHECKREQ);
DDS_DATAWRITER_C(DMSG_HMI_TRRRDRCHECKREQDataWriter, DMSG_HMI_TRRRDRCHECKREQ);
DDS_DATAREADER_C(DMSG_HMI_TRRRDRCHECKREQDataReader, DMSG_HMI_TRRRDRCHECKREQSeq, DMSG_HMI_TRRRDRCHECKREQ);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(DMSG_EC_TRRTRACKINGCMDTypeSupport, DMSG_EC_TRRTRACKINGCMD);

DDS_DATAWRITER_CPP(DMSG_EC_TRRTRACKINGCMDDataWriter, DMSG_EC_TRRTRACKINGCMD);
DDS_DATAREADER_CPP(DMSG_EC_TRRTRACKINGCMDDataReader, DMSG_EC_TRRTRACKINGCMDSeq, DMSG_EC_TRRTRACKINGCMD);


#else

DDS_TYPESUPPORT_C(DMSG_EC_TRRTRACKINGCMDTypeSupport, DMSG_EC_TRRTRACKINGCMD);
DDS_DATAWRITER_C(DMSG_EC_TRRTRACKINGCMDDataWriter, DMSG_EC_TRRTRACKINGCMD);
DDS_DATAREADER_C(DMSG_EC_TRRTRACKINGCMDDataReader, DMSG_EC_TRRTRACKINGCMDSeq, DMSG_EC_TRRTRACKINGCMD);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(DMSG_HMI_TRRSHOOTDOWNRESULTREQTypeSupport, DMSG_HMI_TRRSHOOTDOWNRESULTREQ);

DDS_DATAWRITER_CPP(DMSG_HMI_TRRSHOOTDOWNRESULTREQDataWriter, DMSG_HMI_TRRSHOOTDOWNRESULTREQ);
DDS_DATAREADER_CPP(DMSG_HMI_TRRSHOOTDOWNRESULTREQDataReader, DMSG_HMI_TRRSHOOTDOWNRESULTREQSeq, DMSG_HMI_TRRSHOOTDOWNRESULTREQ);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TRRSHOOTDOWNRESULTREQTypeSupport, DMSG_HMI_TRRSHOOTDOWNRESULTREQ);
DDS_DATAWRITER_C(DMSG_HMI_TRRSHOOTDOWNRESULTREQDataWriter, DMSG_HMI_TRRSHOOTDOWNRESULTREQ);
DDS_DATAREADER_C(DMSG_HMI_TRRSHOOTDOWNRESULTREQDataReader, DMSG_HMI_TRRSHOOTDOWNRESULTREQSeq, DMSG_HMI_TRRSHOOTDOWNRESULTREQ);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(DMSG_HMI_TRRRDRSETTypeSupport, DMSG_HMI_TRRRDRSET);

DDS_DATAWRITER_CPP(DMSG_HMI_TRRRDRSETDataWriter, DMSG_HMI_TRRRDRSET);
DDS_DATAREADER_CPP(DMSG_HMI_TRRRDRSETDataReader, DMSG_HMI_TRRRDRSETSeq, DMSG_HMI_TRRRDRSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TRRRDRSETTypeSupport, DMSG_HMI_TRRRDRSET);
DDS_DATAWRITER_C(DMSG_HMI_TRRRDRSETDataWriter, DMSG_HMI_TRRRDRSET);
DDS_DATAREADER_C(DMSG_HMI_TRRRDRSETDataReader, DMSG_HMI_TRRRDRSETSeq, DMSG_HMI_TRRRDRSET);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(DMSG_HMI_TRRVIDEOSETTypeSupport, DMSG_HMI_TRRVIDEOSET);

DDS_DATAWRITER_CPP(DMSG_HMI_TRRVIDEOSETDataWriter, DMSG_HMI_TRRVIDEOSET);
DDS_DATAREADER_CPP(DMSG_HMI_TRRVIDEOSETDataReader, DMSG_HMI_TRRVIDEOSETSeq, DMSG_HMI_TRRVIDEOSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TRRVIDEOSETTypeSupport, DMSG_HMI_TRRVIDEOSET);
DDS_DATAWRITER_C(DMSG_HMI_TRRVIDEOSETDataWriter, DMSG_HMI_TRRVIDEOSET);
DDS_DATAREADER_C(DMSG_HMI_TRRVIDEOSETDataReader, DMSG_HMI_TRRVIDEOSETSeq, DMSG_HMI_TRRVIDEOSET);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(DMSG_HMI_TRRMANAGESETTypeSupport, DMSG_HMI_TRRMANAGESET);

DDS_DATAWRITER_CPP(DMSG_HMI_TRRMANAGESETDataWriter, DMSG_HMI_TRRMANAGESET);
DDS_DATAREADER_CPP(DMSG_HMI_TRRMANAGESETDataReader, DMSG_HMI_TRRMANAGESETSeq, DMSG_HMI_TRRMANAGESET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TRRMANAGESETTypeSupport, DMSG_HMI_TRRMANAGESET);
DDS_DATAWRITER_C(DMSG_HMI_TRRMANAGESETDataWriter, DMSG_HMI_TRRMANAGESET);
DDS_DATAREADER_C(DMSG_HMI_TRRMANAGESETDataReader, DMSG_HMI_TRRMANAGESETSeq, DMSG_HMI_TRRMANAGESET);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(DMSG_HMI_TRRCAUTIONSETTypeSupport, DMSG_HMI_TRRCAUTIONSET);

DDS_DATAWRITER_CPP(DMSG_HMI_TRRCAUTIONSETDataWriter, DMSG_HMI_TRRCAUTIONSET);
DDS_DATAREADER_CPP(DMSG_HMI_TRRCAUTIONSETDataReader, DMSG_HMI_TRRCAUTIONSETSeq, DMSG_HMI_TRRCAUTIONSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TRRCAUTIONSETTypeSupport, DMSG_HMI_TRRCAUTIONSET);
DDS_DATAWRITER_C(DMSG_HMI_TRRCAUTIONSETDataWriter, DMSG_HMI_TRRCAUTIONSET);
DDS_DATAREADER_C(DMSG_HMI_TRRCAUTIONSETDataReader, DMSG_HMI_TRRCAUTIONSETSeq, DMSG_HMI_TRRCAUTIONSET);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(DMSG_HMI_TRREQUIPMENTSETTypeSupport, DMSG_HMI_TRREQUIPMENTSET);

DDS_DATAWRITER_CPP(DMSG_HMI_TRREQUIPMENTSETDataWriter, DMSG_HMI_TRREQUIPMENTSET);
DDS_DATAREADER_CPP(DMSG_HMI_TRREQUIPMENTSETDataReader, DMSG_HMI_TRREQUIPMENTSETSeq, DMSG_HMI_TRREQUIPMENTSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TRREQUIPMENTSETTypeSupport, DMSG_HMI_TRREQUIPMENTSET);
DDS_DATAWRITER_C(DMSG_HMI_TRREQUIPMENTSETDataWriter, DMSG_HMI_TRREQUIPMENTSET);
DDS_DATAREADER_C(DMSG_HMI_TRREQUIPMENTSETDataReader, DMSG_HMI_TRREQUIPMENTSETSeq, DMSG_HMI_TRREQUIPMENTSET);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(DMSG_HMI_TRRTRACKINGSETTypeSupport, DMSG_HMI_TRRTRACKINGSET);

DDS_DATAWRITER_CPP(DMSG_HMI_TRRTRACKINGSETDataWriter, DMSG_HMI_TRRTRACKINGSET);
DDS_DATAREADER_CPP(DMSG_HMI_TRRTRACKINGSETDataReader, DMSG_HMI_TRRTRACKINGSETSeq, DMSG_HMI_TRRTRACKINGSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TRRTRACKINGSETTypeSupport, DMSG_HMI_TRRTRACKINGSET);
DDS_DATAWRITER_C(DMSG_HMI_TRRTRACKINGSETDataWriter, DMSG_HMI_TRRTRACKINGSET);
DDS_DATAREADER_C(DMSG_HMI_TRRTRACKINGSETDataReader, DMSG_HMI_TRRTRACKINGSETSeq, DMSG_HMI_TRRTRACKINGSET);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(DMSG_HMI_TRRVIDEOREQTypeSupport, DMSG_HMI_TRRVIDEOREQ);

DDS_DATAWRITER_CPP(DMSG_HMI_TRRVIDEOREQDataWriter, DMSG_HMI_TRRVIDEOREQ);
DDS_DATAREADER_CPP(DMSG_HMI_TRRVIDEOREQDataReader, DMSG_HMI_TRRVIDEOREQSeq, DMSG_HMI_TRRVIDEOREQ);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TRRVIDEOREQTypeSupport, DMSG_HMI_TRRVIDEOREQ);
DDS_DATAWRITER_C(DMSG_HMI_TRRVIDEOREQDataWriter, DMSG_HMI_TRRVIDEOREQ);
DDS_DATAREADER_C(DMSG_HMI_TRRVIDEOREQDataReader, DMSG_HMI_TRRVIDEOREQSeq, DMSG_HMI_TRRVIDEOREQ);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif  /* DDS_TRRMMISupport_1980992815_h */
