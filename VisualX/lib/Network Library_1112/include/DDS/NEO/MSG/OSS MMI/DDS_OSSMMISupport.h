
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_OSSMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef DDS_OSSMMISupport_1396059854_h
#define DDS_OSSMMISupport_1396059854_h

/* Uses */
#include "DDS_OSSMMI.h"



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

DDS_TYPESUPPORT_CPP(DMSG_OSSMMI_SENSORSTATETypeSupport, DMSG_OSSMMI_SENSORSTATE);

DDS_DATAWRITER_CPP(DMSG_OSSMMI_SENSORSTATEDataWriter, DMSG_OSSMMI_SENSORSTATE);
DDS_DATAREADER_CPP(DMSG_OSSMMI_SENSORSTATEDataReader, DMSG_OSSMMI_SENSORSTATESeq, DMSG_OSSMMI_SENSORSTATE);


#else

DDS_TYPESUPPORT_C(DMSG_OSSMMI_SENSORSTATETypeSupport, DMSG_OSSMMI_SENSORSTATE);
DDS_DATAWRITER_C(DMSG_OSSMMI_SENSORSTATEDataWriter, DMSG_OSSMMI_SENSORSTATE);
DDS_DATAREADER_C(DMSG_OSSMMI_SENSORSTATEDataReader, DMSG_OSSMMI_SENSORSTATESeq, DMSG_OSSMMI_SENSORSTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_OSSMMI_GPSTypeSupport, DMSG_OSSMMI_GPS);

DDS_DATAWRITER_CPP(DMSG_OSSMMI_GPSDataWriter, DMSG_OSSMMI_GPS);
DDS_DATAREADER_CPP(DMSG_OSSMMI_GPSDataReader, DMSG_OSSMMI_GPSSeq, DMSG_OSSMMI_GPS);


#else

DDS_TYPESUPPORT_C(DMSG_OSSMMI_GPSTypeSupport, DMSG_OSSMMI_GPS);
DDS_DATAWRITER_C(DMSG_OSSMMI_GPSDataWriter, DMSG_OSSMMI_GPS);
DDS_DATAREADER_C(DMSG_OSSMMI_GPSDataReader, DMSG_OSSMMI_GPSSeq, DMSG_OSSMMI_GPS);

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

DDS_TYPESUPPORT_CPP(DMSG_OSSMMI_GYROTypeSupport, DMSG_OSSMMI_GYRO);

DDS_DATAWRITER_CPP(DMSG_OSSMMI_GYRODataWriter, DMSG_OSSMMI_GYRO);
DDS_DATAREADER_CPP(DMSG_OSSMMI_GYRODataReader, DMSG_OSSMMI_GYROSeq, DMSG_OSSMMI_GYRO);


#else

DDS_TYPESUPPORT_C(DMSG_OSSMMI_GYROTypeSupport, DMSG_OSSMMI_GYRO);
DDS_DATAWRITER_C(DMSG_OSSMMI_GYRODataWriter, DMSG_OSSMMI_GYRO);
DDS_DATAREADER_C(DMSG_OSSMMI_GYRODataReader, DMSG_OSSMMI_GYROSeq, DMSG_OSSMMI_GYRO);

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

DDS_TYPESUPPORT_CPP(DMSG_OSSMMI_EMLOGTypeSupport, DMSG_OSSMMI_EMLOG);

DDS_DATAWRITER_CPP(DMSG_OSSMMI_EMLOGDataWriter, DMSG_OSSMMI_EMLOG);
DDS_DATAREADER_CPP(DMSG_OSSMMI_EMLOGDataReader, DMSG_OSSMMI_EMLOGSeq, DMSG_OSSMMI_EMLOG);


#else

DDS_TYPESUPPORT_C(DMSG_OSSMMI_EMLOGTypeSupport, DMSG_OSSMMI_EMLOG);
DDS_DATAWRITER_C(DMSG_OSSMMI_EMLOGDataWriter, DMSG_OSSMMI_EMLOG);
DDS_DATAREADER_C(DMSG_OSSMMI_EMLOGDataReader, DMSG_OSSMMI_EMLOGSeq, DMSG_OSSMMI_EMLOG);

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

DDS_TYPESUPPORT_CPP(DMSG_OSSMMI_WINDTypeSupport, DMSG_OSSMMI_WIND);

DDS_DATAWRITER_CPP(DMSG_OSSMMI_WINDDataWriter, DMSG_OSSMMI_WIND);
DDS_DATAREADER_CPP(DMSG_OSSMMI_WINDDataReader, DMSG_OSSMMI_WINDSeq, DMSG_OSSMMI_WIND);


#else

DDS_TYPESUPPORT_C(DMSG_OSSMMI_WINDTypeSupport, DMSG_OSSMMI_WIND);
DDS_DATAWRITER_C(DMSG_OSSMMI_WINDDataWriter, DMSG_OSSMMI_WIND);
DDS_DATAREADER_C(DMSG_OSSMMI_WINDDataReader, DMSG_OSSMMI_WINDSeq, DMSG_OSSMMI_WIND);

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

DDS_TYPESUPPORT_CPP(DMSG_OSSMMI_TEMPTypeSupport, DMSG_OSSMMI_TEMP);

DDS_DATAWRITER_CPP(DMSG_OSSMMI_TEMPDataWriter, DMSG_OSSMMI_TEMP);
DDS_DATAREADER_CPP(DMSG_OSSMMI_TEMPDataReader, DMSG_OSSMMI_TEMPSeq, DMSG_OSSMMI_TEMP);


#else

DDS_TYPESUPPORT_C(DMSG_OSSMMI_TEMPTypeSupport, DMSG_OSSMMI_TEMP);
DDS_DATAWRITER_C(DMSG_OSSMMI_TEMPDataWriter, DMSG_OSSMMI_TEMP);
DDS_DATAREADER_C(DMSG_OSSMMI_TEMPDataReader, DMSG_OSSMMI_TEMPSeq, DMSG_OSSMMI_TEMP);

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

DDS_TYPESUPPORT_CPP(DMSG_OSSMMI_ECHOTypeSupport, DMSG_OSSMMI_ECHO);

DDS_DATAWRITER_CPP(DMSG_OSSMMI_ECHODataWriter, DMSG_OSSMMI_ECHO);
DDS_DATAREADER_CPP(DMSG_OSSMMI_ECHODataReader, DMSG_OSSMMI_ECHOSeq, DMSG_OSSMMI_ECHO);


#else

DDS_TYPESUPPORT_C(DMSG_OSSMMI_ECHOTypeSupport, DMSG_OSSMMI_ECHO);
DDS_DATAWRITER_C(DMSG_OSSMMI_ECHODataWriter, DMSG_OSSMMI_ECHO);
DDS_DATAREADER_C(DMSG_OSSMMI_ECHODataReader, DMSG_OSSMMI_ECHOSeq, DMSG_OSSMMI_ECHO);

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

DDS_TYPESUPPORT_CPP(DMSG_OSSMMI_PLATFORMTypeSupport, DMSG_OSSMMI_PLATFORM);

DDS_DATAWRITER_CPP(DMSG_OSSMMI_PLATFORMDataWriter, DMSG_OSSMMI_PLATFORM);
DDS_DATAREADER_CPP(DMSG_OSSMMI_PLATFORMDataReader, DMSG_OSSMMI_PLATFORMSeq, DMSG_OSSMMI_PLATFORM);


#else

DDS_TYPESUPPORT_C(DMSG_OSSMMI_PLATFORMTypeSupport, DMSG_OSSMMI_PLATFORM);
DDS_DATAWRITER_C(DMSG_OSSMMI_PLATFORMDataWriter, DMSG_OSSMMI_PLATFORM);
DDS_DATAREADER_C(DMSG_OSSMMI_PLATFORMDataReader, DMSG_OSSMMI_PLATFORMSeq, DMSG_OSSMMI_PLATFORM);

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

DDS_TYPESUPPORT_CPP(DMSG_OSSMMI_PLATFORMREQTypeSupport, DMSG_OSSMMI_PLATFORMREQ);

DDS_DATAWRITER_CPP(DMSG_OSSMMI_PLATFORMREQDataWriter, DMSG_OSSMMI_PLATFORMREQ);
DDS_DATAREADER_CPP(DMSG_OSSMMI_PLATFORMREQDataReader, DMSG_OSSMMI_PLATFORMREQSeq, DMSG_OSSMMI_PLATFORMREQ);


#else

DDS_TYPESUPPORT_C(DMSG_OSSMMI_PLATFORMREQTypeSupport, DMSG_OSSMMI_PLATFORMREQ);
DDS_DATAWRITER_C(DMSG_OSSMMI_PLATFORMREQDataWriter, DMSG_OSSMMI_PLATFORMREQ);
DDS_DATAREADER_C(DMSG_OSSMMI_PLATFORMREQDataReader, DMSG_OSSMMI_PLATFORMREQSeq, DMSG_OSSMMI_PLATFORMREQ);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif  /* DDS_OSSMMISupport_1396059854_h */
