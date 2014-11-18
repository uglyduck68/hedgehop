
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_CMS.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef DDS_CMSSupport_1867575076_h
#define DDS_CMSSupport_1867575076_h

/* Uses */
#include "DDS_CMS.h"



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

DDS_TYPESUPPORT_CPP(TrkNoSysTypeSupport, TrkNoSys);

DDS_DATAWRITER_CPP(TrkNoSysDataWriter, TrkNoSys);
DDS_DATAREADER_CPP(TrkNoSysDataReader, TrkNoSysSeq, TrkNoSys);


#else

DDS_TYPESUPPORT_C(TrkNoSysTypeSupport, TrkNoSys);
DDS_DATAWRITER_C(TrkNoSysDataWriter, TrkNoSys);
DDS_DATAREADER_C(TrkNoSysDataReader, TrkNoSysSeq, TrkNoSys);

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

DDS_TYPESUPPORT_CPP(stDateTypeSupport, stDate);

DDS_DATAWRITER_CPP(stDateDataWriter, stDate);
DDS_DATAREADER_CPP(stDateDataReader, stDateSeq, stDate);


#else

DDS_TYPESUPPORT_C(stDateTypeSupport, stDate);
DDS_DATAWRITER_C(stDateDataWriter, stDate);
DDS_DATAREADER_C(stDateDataReader, stDateSeq, stDate);

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

DDS_TYPESUPPORT_CPP(stTimeTypeSupport, stTime);

DDS_DATAWRITER_CPP(stTimeDataWriter, stTime);
DDS_DATAREADER_CPP(stTimeDataReader, stTimeSeq, stTime);


#else

DDS_TYPESUPPORT_C(stTimeTypeSupport, stTime);
DDS_DATAWRITER_C(stTimeDataWriter, stTime);
DDS_DATAREADER_C(stTimeDataReader, stTimeSeq, stTime);

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

DDS_TYPESUPPORT_CPP(time1TypeSupport, time1);

DDS_DATAWRITER_CPP(time1DataWriter, time1);
DDS_DATAREADER_CPP(time1DataReader, time1Seq, time1);


#else

DDS_TYPESUPPORT_C(time1TypeSupport, time1);
DDS_DATAWRITER_C(time1DataWriter, time1);
DDS_DATAREADER_C(time1DataReader, time1Seq, time1);

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

DDS_TYPESUPPORT_CPP(time2TypeSupport, time2);

DDS_DATAWRITER_CPP(time2DataWriter, time2);
DDS_DATAREADER_CPP(time2DataReader, time2Seq, time2);


#else

DDS_TYPESUPPORT_C(time2TypeSupport, time2);
DDS_DATAWRITER_C(time2DataWriter, time2);
DDS_DATAREADER_C(time2DataReader, time2Seq, time2);

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

DDS_TYPESUPPORT_CPP(coordiSysTypeSupport, coordiSys);

DDS_DATAWRITER_CPP(coordiSysDataWriter, coordiSys);
DDS_DATAREADER_CPP(coordiSysDataReader, coordiSysSeq, coordiSys);


#else

DDS_TYPESUPPORT_C(coordiSysTypeSupport, coordiSys);
DDS_DATAWRITER_C(coordiSysDataWriter, coordiSys);
DDS_DATAREADER_C(coordiSysDataReader, coordiSysSeq, coordiSys);

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

DDS_TYPESUPPORT_CPP(coordiHSysTypeSupport, coordiHSys);

DDS_DATAWRITER_CPP(coordiHSysDataWriter, coordiHSys);
DDS_DATAREADER_CPP(coordiHSysDataReader, coordiHSysSeq, coordiHSys);


#else

DDS_TYPESUPPORT_C(coordiHSysTypeSupport, coordiHSys);
DDS_DATAWRITER_C(coordiHSysDataWriter, coordiHSys);
DDS_DATAREADER_C(coordiHSysDataReader, coordiHSysSeq, coordiHSys);

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

DDS_TYPESUPPORT_CPP(coordiRSysTypeSupport, coordiRSys);

DDS_DATAWRITER_CPP(coordiRSysDataWriter, coordiRSys);
DDS_DATAREADER_CPP(coordiRSysDataReader, coordiRSysSeq, coordiRSys);


#else

DDS_TYPESUPPORT_C(coordiRSysTypeSupport, coordiRSys);
DDS_DATAWRITER_C(coordiRSysDataWriter, coordiRSys);
DDS_DATAREADER_C(coordiRSysDataReader, coordiRSysSeq, coordiRSys);

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

DDS_TYPESUPPORT_CPP(rectSysTypeSupport, rectSys);

DDS_DATAWRITER_CPP(rectSysDataWriter, rectSys);
DDS_DATAREADER_CPP(rectSysDataReader, rectSysSeq, rectSys);


#else

DDS_TYPESUPPORT_C(rectSysTypeSupport, rectSys);
DDS_DATAWRITER_C(rectSysDataWriter, rectSys);
DDS_DATAREADER_C(rectSysDataReader, rectSysSeq, rectSys);

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

DDS_TYPESUPPORT_CPP(rectHSysTypeSupport, rectHSys);

DDS_DATAWRITER_CPP(rectHSysDataWriter, rectHSys);
DDS_DATAREADER_CPP(rectHSysDataReader, rectHSysSeq, rectHSys);


#else

DDS_TYPESUPPORT_C(rectHSysTypeSupport, rectHSys);
DDS_DATAWRITER_C(rectHSysDataWriter, rectHSys);
DDS_DATAREADER_C(rectHSysDataReader, rectHSysSeq, rectHSys);

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

DDS_TYPESUPPORT_CPP(rectRSysTypeSupport, rectRSys);

DDS_DATAWRITER_CPP(rectRSysDataWriter, rectRSys);
DDS_DATAREADER_CPP(rectRSysDataReader, rectRSysSeq, rectRSys);


#else

DDS_TYPESUPPORT_C(rectRSysTypeSupport, rectRSys);
DDS_DATAWRITER_C(rectRSysDataWriter, rectRSys);
DDS_DATAREADER_C(rectRSysDataReader, rectRSysSeq, rectRSys);

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

DDS_TYPESUPPORT_CPP(velocity3DTypeSupport, velocity3D);

DDS_DATAWRITER_CPP(velocity3DDataWriter, velocity3D);
DDS_DATAREADER_CPP(velocity3DDataReader, velocity3DSeq, velocity3D);


#else

DDS_TYPESUPPORT_C(velocity3DTypeSupport, velocity3D);
DDS_DATAWRITER_C(velocity3DDataWriter, velocity3D);
DDS_DATAREADER_C(velocity3DDataReader, velocity3DSeq, velocity3D);

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

DDS_TYPESUPPORT_CPP(SonarTrackTypeSupport, SonarTrack);

DDS_DATAWRITER_CPP(SonarTrackDataWriter, SonarTrack);
DDS_DATAREADER_CPP(SonarTrackDataReader, SonarTrackSeq, SonarTrack);


#else

DDS_TYPESUPPORT_C(SonarTrackTypeSupport, SonarTrack);
DDS_DATAWRITER_C(SonarTrackDataWriter, SonarTrack);
DDS_DATAREADER_C(SonarTrackDataReader, SonarTrackSeq, SonarTrack);

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

DDS_TYPESUPPORT_CPP(stWakeTypeSupport, stWake);

DDS_DATAWRITER_CPP(stWakeDataWriter, stWake);
DDS_DATAREADER_CPP(stWakeDataReader, stWakeSeq, stWake);


#else

DDS_TYPESUPPORT_C(stWakeTypeSupport, stWake);
DDS_DATAWRITER_C(stWakeDataWriter, stWake);
DDS_DATAREADER_C(stWakeDataReader, stWakeSeq, stWake);

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

DDS_TYPESUPPORT_CPP(stSubSysTrackIDTypeSupport, stSubSysTrackID);

DDS_DATAWRITER_CPP(stSubSysTrackIDDataWriter, stSubSysTrackID);
DDS_DATAREADER_CPP(stSubSysTrackIDDataReader, stSubSysTrackIDSeq, stSubSysTrackID);


#else

DDS_TYPESUPPORT_C(stSubSysTrackIDTypeSupport, stSubSysTrackID);
DDS_DATAWRITER_C(stSubSysTrackIDDataWriter, stSubSysTrackID);
DDS_DATAREADER_C(stSubSysTrackIDDataReader, stSubSysTrackIDSeq, stSubSysTrackID);

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

DDS_TYPESUPPORT_CPP(stFullTimeTypeSupport, stFullTime);

DDS_DATAWRITER_CPP(stFullTimeDataWriter, stFullTime);
DDS_DATAREADER_CPP(stFullTimeDataReader, stFullTimeSeq, stFullTime);


#else

DDS_TYPESUPPORT_C(stFullTimeTypeSupport, stFullTime);
DDS_DATAWRITER_C(stFullTimeDataWriter, stFullTime);
DDS_DATAREADER_C(stFullTimeDataReader, stFullTimeSeq, stFullTime);

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

DDS_TYPESUPPORT_CPP(DMSG_OSM_SENSORSTATETypeSupport, DMSG_OSM_SENSORSTATE);

DDS_DATAWRITER_CPP(DMSG_OSM_SENSORSTATEDataWriter, DMSG_OSM_SENSORSTATE);
DDS_DATAREADER_CPP(DMSG_OSM_SENSORSTATEDataReader, DMSG_OSM_SENSORSTATESeq, DMSG_OSM_SENSORSTATE);


#else

DDS_TYPESUPPORT_C(DMSG_OSM_SENSORSTATETypeSupport, DMSG_OSM_SENSORSTATE);
DDS_DATAWRITER_C(DMSG_OSM_SENSORSTATEDataWriter, DMSG_OSM_SENSORSTATE);
DDS_DATAREADER_C(DMSG_OSM_SENSORSTATEDataReader, DMSG_OSM_SENSORSTATESeq, DMSG_OSM_SENSORSTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_OSM_WEAPONSTATETypeSupport, DMSG_OSM_WEAPONSTATE);

DDS_DATAWRITER_CPP(DMSG_OSM_WEAPONSTATEDataWriter, DMSG_OSM_WEAPONSTATE);
DDS_DATAREADER_CPP(DMSG_OSM_WEAPONSTATEDataReader, DMSG_OSM_WEAPONSTATESeq, DMSG_OSM_WEAPONSTATE);


#else

DDS_TYPESUPPORT_C(DMSG_OSM_WEAPONSTATETypeSupport, DMSG_OSM_WEAPONSTATE);
DDS_DATAWRITER_C(DMSG_OSM_WEAPONSTATEDataWriter, DMSG_OSM_WEAPONSTATE);
DDS_DATAREADER_C(DMSG_OSM_WEAPONSTATEDataReader, DMSG_OSM_WEAPONSTATESeq, DMSG_OSM_WEAPONSTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_REQMISSILEENGAGEPLANTypeSupport, DMSG_HMI_REQMISSILEENGAGEPLAN);

DDS_DATAWRITER_CPP(DMSG_HMI_REQMISSILEENGAGEPLANDataWriter, DMSG_HMI_REQMISSILEENGAGEPLAN);
DDS_DATAREADER_CPP(DMSG_HMI_REQMISSILEENGAGEPLANDataReader, DMSG_HMI_REQMISSILEENGAGEPLANSeq, DMSG_HMI_REQMISSILEENGAGEPLAN);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_REQMISSILEENGAGEPLANTypeSupport, DMSG_HMI_REQMISSILEENGAGEPLAN);
DDS_DATAWRITER_C(DMSG_HMI_REQMISSILEENGAGEPLANDataWriter, DMSG_HMI_REQMISSILEENGAGEPLAN);
DDS_DATAREADER_C(DMSG_HMI_REQMISSILEENGAGEPLANDataReader, DMSG_HMI_REQMISSILEENGAGEPLANSeq, DMSG_HMI_REQMISSILEENGAGEPLAN);

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

DDS_TYPESUPPORT_CPP(DMSG_SUBHMI_SYSCTRLMODETypeSupport, DMSG_SUBHMI_SYSCTRLMODE);

DDS_DATAWRITER_CPP(DMSG_SUBHMI_SYSCTRLMODEDataWriter, DMSG_SUBHMI_SYSCTRLMODE);
DDS_DATAREADER_CPP(DMSG_SUBHMI_SYSCTRLMODEDataReader, DMSG_SUBHMI_SYSCTRLMODESeq, DMSG_SUBHMI_SYSCTRLMODE);


#else

DDS_TYPESUPPORT_C(DMSG_SUBHMI_SYSCTRLMODETypeSupport, DMSG_SUBHMI_SYSCTRLMODE);
DDS_DATAWRITER_C(DMSG_SUBHMI_SYSCTRLMODEDataWriter, DMSG_SUBHMI_SYSCTRLMODE);
DDS_DATAREADER_C(DMSG_SUBHMI_SYSCTRLMODEDataReader, DMSG_SUBHMI_SYSCTRLMODESeq, DMSG_SUBHMI_SYSCTRLMODE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_WEAPONLIMITSETTypeSupport, DMSG_HMI_WEAPONLIMITSET);

DDS_DATAWRITER_CPP(DMSG_HMI_WEAPONLIMITSETDataWriter, DMSG_HMI_WEAPONLIMITSET);
DDS_DATAREADER_CPP(DMSG_HMI_WEAPONLIMITSETDataReader, DMSG_HMI_WEAPONLIMITSETSeq, DMSG_HMI_WEAPONLIMITSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_WEAPONLIMITSETTypeSupport, DMSG_HMI_WEAPONLIMITSET);
DDS_DATAWRITER_C(DMSG_HMI_WEAPONLIMITSETDataWriter, DMSG_HMI_WEAPONLIMITSET);
DDS_DATAREADER_C(DMSG_HMI_WEAPONLIMITSETDataReader, DMSG_HMI_WEAPONLIMITSETSeq, DMSG_HMI_WEAPONLIMITSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_CREATEMANUALTRACKTypeSupport, DMSG_HMI_CREATEMANUALTRACK);

DDS_DATAWRITER_CPP(DMSG_HMI_CREATEMANUALTRACKDataWriter, DMSG_HMI_CREATEMANUALTRACK);
DDS_DATAREADER_CPP(DMSG_HMI_CREATEMANUALTRACKDataReader, DMSG_HMI_CREATEMANUALTRACKSeq, DMSG_HMI_CREATEMANUALTRACK);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_CREATEMANUALTRACKTypeSupport, DMSG_HMI_CREATEMANUALTRACK);
DDS_DATAWRITER_C(DMSG_HMI_CREATEMANUALTRACKDataWriter, DMSG_HMI_CREATEMANUALTRACK);
DDS_DATAREADER_C(DMSG_HMI_CREATEMANUALTRACKDataReader, DMSG_HMI_CREATEMANUALTRACKSeq, DMSG_HMI_CREATEMANUALTRACK);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TARGETIDENTITYSETTypeSupport, DMSG_HMI_TARGETIDENTITYSET);

DDS_DATAWRITER_CPP(DMSG_HMI_TARGETIDENTITYSETDataWriter, DMSG_HMI_TARGETIDENTITYSET);
DDS_DATAREADER_CPP(DMSG_HMI_TARGETIDENTITYSETDataReader, DMSG_HMI_TARGETIDENTITYSETSeq, DMSG_HMI_TARGETIDENTITYSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TARGETIDENTITYSETTypeSupport, DMSG_HMI_TARGETIDENTITYSET);
DDS_DATAWRITER_C(DMSG_HMI_TARGETIDENTITYSETDataWriter, DMSG_HMI_TARGETIDENTITYSET);
DDS_DATAREADER_C(DMSG_HMI_TARGETIDENTITYSETDataReader, DMSG_HMI_TARGETIDENTITYSETSeq, DMSG_HMI_TARGETIDENTITYSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TARGETCATEGORYSETTypeSupport, DMSG_HMI_TARGETCATEGORYSET);

DDS_DATAWRITER_CPP(DMSG_HMI_TARGETCATEGORYSETDataWriter, DMSG_HMI_TARGETCATEGORYSET);
DDS_DATAREADER_CPP(DMSG_HMI_TARGETCATEGORYSETDataReader, DMSG_HMI_TARGETCATEGORYSETSeq, DMSG_HMI_TARGETCATEGORYSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TARGETCATEGORYSETTypeSupport, DMSG_HMI_TARGETCATEGORYSET);
DDS_DATAWRITER_C(DMSG_HMI_TARGETCATEGORYSETDataWriter, DMSG_HMI_TARGETCATEGORYSET);
DDS_DATAREADER_C(DMSG_HMI_TARGETCATEGORYSETDataReader, DMSG_HMI_TARGETCATEGORYSETSeq, DMSG_HMI_TARGETCATEGORYSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TARGETNAMESETTypeSupport, DMSG_HMI_TARGETNAMESET);

DDS_DATAWRITER_CPP(DMSG_HMI_TARGETNAMESETDataWriter, DMSG_HMI_TARGETNAMESET);
DDS_DATAREADER_CPP(DMSG_HMI_TARGETNAMESETDataReader, DMSG_HMI_TARGETNAMESETSeq, DMSG_HMI_TARGETNAMESET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TARGETNAMESETTypeSupport, DMSG_HMI_TARGETNAMESET);
DDS_DATAWRITER_C(DMSG_HMI_TARGETNAMESETDataWriter, DMSG_HMI_TARGETNAMESET);
DDS_DATAREADER_C(DMSG_HMI_TARGETNAMESETDataReader, DMSG_HMI_TARGETNAMESETSeq, DMSG_HMI_TARGETNAMESET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_ENGAGESETTypeSupport, DMSG_HMI_ENGAGESET);

DDS_DATAWRITER_CPP(DMSG_HMI_ENGAGESETDataWriter, DMSG_HMI_ENGAGESET);
DDS_DATAREADER_CPP(DMSG_HMI_ENGAGESETDataReader, DMSG_HMI_ENGAGESETSeq, DMSG_HMI_ENGAGESET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_ENGAGESETTypeSupport, DMSG_HMI_ENGAGESET);
DDS_DATAWRITER_C(DMSG_HMI_ENGAGESETDataWriter, DMSG_HMI_ENGAGESET);
DDS_DATAREADER_C(DMSG_HMI_ENGAGESETDataReader, DMSG_HMI_ENGAGESETSeq, DMSG_HMI_ENGAGESET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_MANUALSELECTSETTypeSupport, DMSG_HMI_MANUALSELECTSET);

DDS_DATAWRITER_CPP(DMSG_HMI_MANUALSELECTSETDataWriter, DMSG_HMI_MANUALSELECTSET);
DDS_DATAREADER_CPP(DMSG_HMI_MANUALSELECTSETDataReader, DMSG_HMI_MANUALSELECTSETSeq, DMSG_HMI_MANUALSELECTSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_MANUALSELECTSETTypeSupport, DMSG_HMI_MANUALSELECTSET);
DDS_DATAWRITER_C(DMSG_HMI_MANUALSELECTSETDataWriter, DMSG_HMI_MANUALSELECTSET);
DDS_DATAREADER_C(DMSG_HMI_MANUALSELECTSETDataReader, DMSG_HMI_MANUALSELECTSETSeq, DMSG_HMI_MANUALSELECTSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_IDENTITYDETAILSETTypeSupport, DMSG_HMI_IDENTITYDETAILSET);

DDS_DATAWRITER_CPP(DMSG_HMI_IDENTITYDETAILSETDataWriter, DMSG_HMI_IDENTITYDETAILSET);
DDS_DATAREADER_CPP(DMSG_HMI_IDENTITYDETAILSETDataReader, DMSG_HMI_IDENTITYDETAILSETSeq, DMSG_HMI_IDENTITYDETAILSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_IDENTITYDETAILSETTypeSupport, DMSG_HMI_IDENTITYDETAILSET);
DDS_DATAWRITER_C(DMSG_HMI_IDENTITYDETAILSETDataWriter, DMSG_HMI_IDENTITYDETAILSET);
DDS_DATAREADER_C(DMSG_HMI_IDENTITYDETAILSETDataReader, DMSG_HMI_IDENTITYDETAILSETSeq, DMSG_HMI_IDENTITYDETAILSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_WEAPONCAPABILITYSETTypeSupport, DMSG_HMI_WEAPONCAPABILITYSET);

DDS_DATAWRITER_CPP(DMSG_HMI_WEAPONCAPABILITYSETDataWriter, DMSG_HMI_WEAPONCAPABILITYSET);
DDS_DATAREADER_CPP(DMSG_HMI_WEAPONCAPABILITYSETDataReader, DMSG_HMI_WEAPONCAPABILITYSETSeq, DMSG_HMI_WEAPONCAPABILITYSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_WEAPONCAPABILITYSETTypeSupport, DMSG_HMI_WEAPONCAPABILITYSET);
DDS_DATAWRITER_C(DMSG_HMI_WEAPONCAPABILITYSETDataWriter, DMSG_HMI_WEAPONCAPABILITYSET);
DDS_DATAREADER_C(DMSG_HMI_WEAPONCAPABILITYSETDataReader, DMSG_HMI_WEAPONCAPABILITYSETSeq, DMSG_HMI_WEAPONCAPABILITYSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_DATUMSETTypeSupport, DMSG_HMI_DATUMSET);

DDS_DATAWRITER_CPP(DMSG_HMI_DATUMSETDataWriter, DMSG_HMI_DATUMSET);
DDS_DATAREADER_CPP(DMSG_HMI_DATUMSETDataReader, DMSG_HMI_DATUMSETSeq, DMSG_HMI_DATUMSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_DATUMSETTypeSupport, DMSG_HMI_DATUMSET);
DDS_DATAWRITER_C(DMSG_HMI_DATUMSETDataWriter, DMSG_HMI_DATUMSET);
DDS_DATAREADER_C(DMSG_HMI_DATUMSETDataReader, DMSG_HMI_DATUMSETSeq, DMSG_HMI_DATUMSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_SYSTRACKDELTypeSupport, DMSG_HMI_SYSTRACKDEL);

DDS_DATAWRITER_CPP(DMSG_HMI_SYSTRACKDELDataWriter, DMSG_HMI_SYSTRACKDEL);
DDS_DATAREADER_CPP(DMSG_HMI_SYSTRACKDELDataReader, DMSG_HMI_SYSTRACKDELSeq, DMSG_HMI_SYSTRACKDEL);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_SYSTRACKDELTypeSupport, DMSG_HMI_SYSTRACKDEL);
DDS_DATAWRITER_C(DMSG_HMI_SYSTRACKDELDataWriter, DMSG_HMI_SYSTRACKDEL);
DDS_DATAREADER_C(DMSG_HMI_SYSTRACKDELDataReader, DMSG_HMI_SYSTRACKDELSeq, DMSG_HMI_SYSTRACKDEL);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_PAIRINGSETTypeSupport, DMSG_HMI_PAIRINGSET);

DDS_DATAWRITER_CPP(DMSG_HMI_PAIRINGSETDataWriter, DMSG_HMI_PAIRINGSET);
DDS_DATAREADER_CPP(DMSG_HMI_PAIRINGSETDataReader, DMSG_HMI_PAIRINGSETSeq, DMSG_HMI_PAIRINGSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_PAIRINGSETTypeSupport, DMSG_HMI_PAIRINGSET);
DDS_DATAWRITER_C(DMSG_HMI_PAIRINGSETDataWriter, DMSG_HMI_PAIRINGSET);
DDS_DATAREADER_C(DMSG_HMI_PAIRINGSETDataReader, DMSG_HMI_PAIRINGSETSeq, DMSG_HMI_PAIRINGSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_ASSOCIATIONSETTypeSupport, DMSG_HMI_ASSOCIATIONSET);

DDS_DATAWRITER_CPP(DMSG_HMI_ASSOCIATIONSETDataWriter, DMSG_HMI_ASSOCIATIONSET);
DDS_DATAREADER_CPP(DMSG_HMI_ASSOCIATIONSETDataReader, DMSG_HMI_ASSOCIATIONSETSeq, DMSG_HMI_ASSOCIATIONSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_ASSOCIATIONSETTypeSupport, DMSG_HMI_ASSOCIATIONSET);
DDS_DATAWRITER_C(DMSG_HMI_ASSOCIATIONSETDataWriter, DMSG_HMI_ASSOCIATIONSET);
DDS_DATAREADER_C(DMSG_HMI_ASSOCIATIONSETDataReader, DMSG_HMI_ASSOCIATIONSETSeq, DMSG_HMI_ASSOCIATIONSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_CORRELATIONSETTypeSupport, DMSG_HMI_CORRELATIONSET);

DDS_DATAWRITER_CPP(DMSG_HMI_CORRELATIONSETDataWriter, DMSG_HMI_CORRELATIONSET);
DDS_DATAREADER_CPP(DMSG_HMI_CORRELATIONSETDataReader, DMSG_HMI_CORRELATIONSETSeq, DMSG_HMI_CORRELATIONSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_CORRELATIONSETTypeSupport, DMSG_HMI_CORRELATIONSET);
DDS_DATAWRITER_C(DMSG_HMI_CORRELATIONSETDataWriter, DMSG_HMI_CORRELATIONSET);
DDS_DATAREADER_C(DMSG_HMI_CORRELATIONSETDataReader, DMSG_HMI_CORRELATIONSETSeq, DMSG_HMI_CORRELATIONSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_CORRELATIONCLEARTypeSupport, DMSG_HMI_CORRELATIONCLEAR);

DDS_DATAWRITER_CPP(DMSG_HMI_CORRELATIONCLEARDataWriter, DMSG_HMI_CORRELATIONCLEAR);
DDS_DATAREADER_CPP(DMSG_HMI_CORRELATIONCLEARDataReader, DMSG_HMI_CORRELATIONCLEARSeq, DMSG_HMI_CORRELATIONCLEAR);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_CORRELATIONCLEARTypeSupport, DMSG_HMI_CORRELATIONCLEAR);
DDS_DATAWRITER_C(DMSG_HMI_CORRELATIONCLEARDataWriter, DMSG_HMI_CORRELATIONCLEAR);
DDS_DATAREADER_C(DMSG_HMI_CORRELATIONCLEARDataReader, DMSG_HMI_CORRELATIONCLEARSeq, DMSG_HMI_CORRELATIONCLEAR);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TRACECHANGETypeSupport, DMSG_HMI_TRACECHANGE);

DDS_DATAWRITER_CPP(DMSG_HMI_TRACECHANGEDataWriter, DMSG_HMI_TRACECHANGE);
DDS_DATAREADER_CPP(DMSG_HMI_TRACECHANGEDataReader, DMSG_HMI_TRACECHANGESeq, DMSG_HMI_TRACECHANGE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TRACECHANGETypeSupport, DMSG_HMI_TRACECHANGE);
DDS_DATAWRITER_C(DMSG_HMI_TRACECHANGEDataWriter, DMSG_HMI_TRACECHANGE);
DDS_DATAREADER_C(DMSG_HMI_TRACECHANGEDataReader, DMSG_HMI_TRACECHANGESeq, DMSG_HMI_TRACECHANGE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TRACKWEAPONRANGETypeSupport, DMSG_HMI_TRACKWEAPONRANGE);

DDS_DATAWRITER_CPP(DMSG_HMI_TRACKWEAPONRANGEDataWriter, DMSG_HMI_TRACKWEAPONRANGE);
DDS_DATAREADER_CPP(DMSG_HMI_TRACKWEAPONRANGEDataReader, DMSG_HMI_TRACKWEAPONRANGESeq, DMSG_HMI_TRACKWEAPONRANGE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TRACKWEAPONRANGETypeSupport, DMSG_HMI_TRACKWEAPONRANGE);
DDS_DATAWRITER_C(DMSG_HMI_TRACKWEAPONRANGEDataWriter, DMSG_HMI_TRACKWEAPONRANGE);
DDS_DATAREADER_C(DMSG_HMI_TRACKWEAPONRANGEDataReader, DMSG_HMI_TRACKWEAPONRANGESeq, DMSG_HMI_TRACKWEAPONRANGE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TRACKSENSORRANGETypeSupport, DMSG_HMI_TRACKSENSORRANGE);

DDS_DATAWRITER_CPP(DMSG_HMI_TRACKSENSORRANGEDataWriter, DMSG_HMI_TRACKSENSORRANGE);
DDS_DATAREADER_CPP(DMSG_HMI_TRACKSENSORRANGEDataReader, DMSG_HMI_TRACKSENSORRANGESeq, DMSG_HMI_TRACKSENSORRANGE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TRACKSENSORRANGETypeSupport, DMSG_HMI_TRACKSENSORRANGE);
DDS_DATAWRITER_C(DMSG_HMI_TRACKSENSORRANGEDataWriter, DMSG_HMI_TRACKSENSORRANGE);
DDS_DATAREADER_C(DMSG_HMI_TRACKSENSORRANGEDataReader, DMSG_HMI_TRACKSENSORRANGESeq, DMSG_HMI_TRACKSENSORRANGE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_ANTIWEAPONWEIGHTTypeSupport, DMSG_HMI_ANTIWEAPONWEIGHT);

DDS_DATAWRITER_CPP(DMSG_HMI_ANTIWEAPONWEIGHTDataWriter, DMSG_HMI_ANTIWEAPONWEIGHT);
DDS_DATAREADER_CPP(DMSG_HMI_ANTIWEAPONWEIGHTDataReader, DMSG_HMI_ANTIWEAPONWEIGHTSeq, DMSG_HMI_ANTIWEAPONWEIGHT);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_ANTIWEAPONWEIGHTTypeSupport, DMSG_HMI_ANTIWEAPONWEIGHT);
DDS_DATAWRITER_C(DMSG_HMI_ANTIWEAPONWEIGHTDataWriter, DMSG_HMI_ANTIWEAPONWEIGHT);
DDS_DATAREADER_C(DMSG_HMI_ANTIWEAPONWEIGHTDataReader, DMSG_HMI_ANTIWEAPONWEIGHTSeq, DMSG_HMI_ANTIWEAPONWEIGHT);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TAGSETTypeSupport, DMSG_HMI_TAGSET);

DDS_DATAWRITER_CPP(DMSG_HMI_TAGSETDataWriter, DMSG_HMI_TAGSET);
DDS_DATAREADER_CPP(DMSG_HMI_TAGSETDataReader, DMSG_HMI_TAGSETSeq, DMSG_HMI_TAGSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TAGSETTypeSupport, DMSG_HMI_TAGSET);
DDS_DATAWRITER_C(DMSG_HMI_TAGSETDataWriter, DMSG_HMI_TAGSET);
DDS_DATAREADER_C(DMSG_HMI_TAGSETDataReader, DMSG_HMI_TAGSETSeq, DMSG_HMI_TAGSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_SONARSETTypeSupport, DMSG_HMI_SONARSET);

DDS_DATAWRITER_CPP(DMSG_HMI_SONARSETDataWriter, DMSG_HMI_SONARSET);
DDS_DATAREADER_CPP(DMSG_HMI_SONARSETDataReader, DMSG_HMI_SONARSETSeq, DMSG_HMI_SONARSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_SONARSETTypeSupport, DMSG_HMI_SONARSET);
DDS_DATAWRITER_C(DMSG_HMI_SONARSETDataWriter, DMSG_HMI_SONARSET);
DDS_DATAREADER_C(DMSG_HMI_SONARSETDataReader, DMSG_HMI_SONARSETSeq, DMSG_HMI_SONARSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_WEAPONSETTypeSupport, DMSG_HMI_WEAPONSET);

DDS_DATAWRITER_CPP(DMSG_HMI_WEAPONSETDataWriter, DMSG_HMI_WEAPONSET);
DDS_DATAREADER_CPP(DMSG_HMI_WEAPONSETDataReader, DMSG_HMI_WEAPONSETSeq, DMSG_HMI_WEAPONSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_WEAPONSETTypeSupport, DMSG_HMI_WEAPONSET);
DDS_DATAWRITER_C(DMSG_HMI_WEAPONSETDataWriter, DMSG_HMI_WEAPONSET);
DDS_DATAREADER_C(DMSG_HMI_WEAPONSETDataReader, DMSG_HMI_WEAPONSETSeq, DMSG_HMI_WEAPONSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_SUBCORRELATIONSETTypeSupport, DMSG_HMI_SUBCORRELATIONSET);

DDS_DATAWRITER_CPP(DMSG_HMI_SUBCORRELATIONSETDataWriter, DMSG_HMI_SUBCORRELATIONSET);
DDS_DATAREADER_CPP(DMSG_HMI_SUBCORRELATIONSETDataReader, DMSG_HMI_SUBCORRELATIONSETSeq, DMSG_HMI_SUBCORRELATIONSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_SUBCORRELATIONSETTypeSupport, DMSG_HMI_SUBCORRELATIONSET);
DDS_DATAWRITER_C(DMSG_HMI_SUBCORRELATIONSETDataWriter, DMSG_HMI_SUBCORRELATIONSET);
DDS_DATAREADER_C(DMSG_HMI_SUBCORRELATIONSETDataReader, DMSG_HMI_SUBCORRELATIONSETSeq, DMSG_HMI_SUBCORRELATIONSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_SUBCORRELATIONCLEARTypeSupport, DMSG_HMI_SUBCORRELATIONCLEAR);

DDS_DATAWRITER_CPP(DMSG_HMI_SUBCORRELATIONCLEARDataWriter, DMSG_HMI_SUBCORRELATIONCLEAR);
DDS_DATAREADER_CPP(DMSG_HMI_SUBCORRELATIONCLEARDataReader, DMSG_HMI_SUBCORRELATIONCLEARSeq, DMSG_HMI_SUBCORRELATIONCLEAR);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_SUBCORRELATIONCLEARTypeSupport, DMSG_HMI_SUBCORRELATIONCLEAR);
DDS_DATAWRITER_C(DMSG_HMI_SUBCORRELATIONCLEARDataWriter, DMSG_HMI_SUBCORRELATIONCLEAR);
DDS_DATAREADER_C(DMSG_HMI_SUBCORRELATIONCLEARDataReader, DMSG_HMI_SUBCORRELATIONCLEARSeq, DMSG_HMI_SUBCORRELATIONCLEAR);

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

DDS_TYPESUPPORT_CPP(DMSG_TM_SYSTRACKDELTypeSupport, DMSG_TM_SYSTRACKDEL);

DDS_DATAWRITER_CPP(DMSG_TM_SYSTRACKDELDataWriter, DMSG_TM_SYSTRACKDEL);
DDS_DATAREADER_CPP(DMSG_TM_SYSTRACKDELDataReader, DMSG_TM_SYSTRACKDELSeq, DMSG_TM_SYSTRACKDEL);


#else

DDS_TYPESUPPORT_C(DMSG_TM_SYSTRACKDELTypeSupport, DMSG_TM_SYSTRACKDEL);
DDS_DATAWRITER_C(DMSG_TM_SYSTRACKDELDataWriter, DMSG_TM_SYSTRACKDEL);
DDS_DATAREADER_C(DMSG_TM_SYSTRACKDELDataReader, DMSG_TM_SYSTRACKDELSeq, DMSG_TM_SYSTRACKDEL);

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

DDS_TYPESUPPORT_CPP(DMSG_TM_SYSTRACKTypeSupport, DMSG_TM_SYSTRACK);

DDS_DATAWRITER_CPP(DMSG_TM_SYSTRACKDataWriter, DMSG_TM_SYSTRACK);
DDS_DATAREADER_CPP(DMSG_TM_SYSTRACKDataReader, DMSG_TM_SYSTRACKSeq, DMSG_TM_SYSTRACK);


#else

DDS_TYPESUPPORT_C(DMSG_TM_SYSTRACKTypeSupport, DMSG_TM_SYSTRACK);
DDS_DATAWRITER_C(DMSG_TM_SYSTRACKDataWriter, DMSG_TM_SYSTRACK);
DDS_DATAREADER_C(DMSG_TM_SYSTRACKDataReader, DMSG_TM_SYSTRACKSeq, DMSG_TM_SYSTRACK);

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

DDS_TYPESUPPORT_CPP(DMSG_TM_SWSTATETypeSupport, DMSG_TM_SWSTATE);

DDS_DATAWRITER_CPP(DMSG_TM_SWSTATEDataWriter, DMSG_TM_SWSTATE);
DDS_DATAREADER_CPP(DMSG_TM_SWSTATEDataReader, DMSG_TM_SWSTATESeq, DMSG_TM_SWSTATE);


#else

DDS_TYPESUPPORT_C(DMSG_TM_SWSTATETypeSupport, DMSG_TM_SWSTATE);
DDS_DATAWRITER_C(DMSG_TM_SWSTATEDataWriter, DMSG_TM_SWSTATE);
DDS_DATAREADER_C(DMSG_TM_SWSTATEDataReader, DMSG_TM_SWSTATESeq, DMSG_TM_SWSTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_TM_SUBSYSTEMTRACKTypeSupport, DMSG_TM_SUBSYSTEMTRACK);

DDS_DATAWRITER_CPP(DMSG_TM_SUBSYSTEMTRACKDataWriter, DMSG_TM_SUBSYSTEMTRACK);
DDS_DATAREADER_CPP(DMSG_TM_SUBSYSTEMTRACKDataReader, DMSG_TM_SUBSYSTEMTRACKSeq, DMSG_TM_SUBSYSTEMTRACK);


#else

DDS_TYPESUPPORT_C(DMSG_TM_SUBSYSTEMTRACKTypeSupport, DMSG_TM_SUBSYSTEMTRACK);
DDS_DATAWRITER_C(DMSG_TM_SUBSYSTEMTRACKDataWriter, DMSG_TM_SUBSYSTEMTRACK);
DDS_DATAREADER_C(DMSG_TM_SUBSYSTEMTRACKDataReader, DMSG_TM_SUBSYSTEMTRACKSeq, DMSG_TM_SUBSYSTEMTRACK);

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

DDS_TYPESUPPORT_CPP(DMSG_TM_SUBSYSTRACKDELTypeSupport, DMSG_TM_SUBSYSTRACKDEL);

DDS_DATAWRITER_CPP(DMSG_TM_SUBSYSTRACKDELDataWriter, DMSG_TM_SUBSYSTRACKDEL);
DDS_DATAREADER_CPP(DMSG_TM_SUBSYSTRACKDELDataReader, DMSG_TM_SUBSYSTRACKDELSeq, DMSG_TM_SUBSYSTRACKDEL);


#else

DDS_TYPESUPPORT_C(DMSG_TM_SUBSYSTRACKDELTypeSupport, DMSG_TM_SUBSYSTRACKDEL);
DDS_DATAWRITER_C(DMSG_TM_SUBSYSTRACKDELDataWriter, DMSG_TM_SUBSYSTRACKDEL);
DDS_DATAREADER_C(DMSG_TM_SUBSYSTRACKDELDataReader, DMSG_TM_SUBSYSTRACKDELSeq, DMSG_TM_SUBSYSTRACKDEL);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_WEAPONCTRLTypeSupport, DMSG_HMI_WEAPONCTRL);

DDS_DATAWRITER_CPP(DMSG_HMI_WEAPONCTRLDataWriter, DMSG_HMI_WEAPONCTRL);
DDS_DATAREADER_CPP(DMSG_HMI_WEAPONCTRLDataReader, DMSG_HMI_WEAPONCTRLSeq, DMSG_HMI_WEAPONCTRL);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_WEAPONCTRLTypeSupport, DMSG_HMI_WEAPONCTRL);
DDS_DATAWRITER_C(DMSG_HMI_WEAPONCTRLDataWriter, DMSG_HMI_WEAPONCTRL);
DDS_DATAREADER_C(DMSG_HMI_WEAPONCTRLDataReader, DMSG_HMI_WEAPONCTRLSeq, DMSG_HMI_WEAPONCTRL);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_FASTRESPONSEMODETypeSupport, DMSG_HMI_FASTRESPONSEMODE);

DDS_DATAWRITER_CPP(DMSG_HMI_FASTRESPONSEMODEDataWriter, DMSG_HMI_FASTRESPONSEMODE);
DDS_DATAREADER_CPP(DMSG_HMI_FASTRESPONSEMODEDataReader, DMSG_HMI_FASTRESPONSEMODESeq, DMSG_HMI_FASTRESPONSEMODE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_FASTRESPONSEMODETypeSupport, DMSG_HMI_FASTRESPONSEMODE);
DDS_DATAWRITER_C(DMSG_HMI_FASTRESPONSEMODEDataWriter, DMSG_HMI_FASTRESPONSEMODE);
DDS_DATAREADER_C(DMSG_HMI_FASTRESPONSEMODEDataReader, DMSG_HMI_FASTRESPONSEMODESeq, DMSG_HMI_FASTRESPONSEMODE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_WEAPONUSELIMITTypeSupport, DMSG_HMI_WEAPONUSELIMIT);

DDS_DATAWRITER_CPP(DMSG_HMI_WEAPONUSELIMITDataWriter, DMSG_HMI_WEAPONUSELIMIT);
DDS_DATAREADER_CPP(DMSG_HMI_WEAPONUSELIMITDataReader, DMSG_HMI_WEAPONUSELIMITSeq, DMSG_HMI_WEAPONUSELIMIT);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_WEAPONUSELIMITTypeSupport, DMSG_HMI_WEAPONUSELIMIT);
DDS_DATAWRITER_C(DMSG_HMI_WEAPONUSELIMITDataWriter, DMSG_HMI_WEAPONUSELIMIT);
DDS_DATAREADER_C(DMSG_HMI_WEAPONUSELIMITDataReader, DMSG_HMI_WEAPONUSELIMITSeq, DMSG_HMI_WEAPONUSELIMIT);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_ENGAGEMODESETTypeSupport, DMSG_HMI_ENGAGEMODESET);

DDS_DATAWRITER_CPP(DMSG_HMI_ENGAGEMODESETDataWriter, DMSG_HMI_ENGAGEMODESET);
DDS_DATAREADER_CPP(DMSG_HMI_ENGAGEMODESETDataReader, DMSG_HMI_ENGAGEMODESETSeq, DMSG_HMI_ENGAGEMODESET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_ENGAGEMODESETTypeSupport, DMSG_HMI_ENGAGEMODESET);
DDS_DATAWRITER_C(DMSG_HMI_ENGAGEMODESETDataWriter, DMSG_HMI_ENGAGEMODESET);
DDS_DATAREADER_C(DMSG_HMI_ENGAGEMODESETDataReader, DMSG_HMI_ENGAGEMODESETSeq, DMSG_HMI_ENGAGEMODESET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_ENGAGEADVICEREQTypeSupport, DMSG_HMI_ENGAGEADVICEREQ);

DDS_DATAWRITER_CPP(DMSG_HMI_ENGAGEADVICEREQDataWriter, DMSG_HMI_ENGAGEADVICEREQ);
DDS_DATAREADER_CPP(DMSG_HMI_ENGAGEADVICEREQDataReader, DMSG_HMI_ENGAGEADVICEREQSeq, DMSG_HMI_ENGAGEADVICEREQ);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_ENGAGEADVICEREQTypeSupport, DMSG_HMI_ENGAGEADVICEREQ);
DDS_DATAWRITER_C(DMSG_HMI_ENGAGEADVICEREQDataWriter, DMSG_HMI_ENGAGEADVICEREQ);
DDS_DATAREADER_C(DMSG_HMI_ENGAGEADVICEREQDataReader, DMSG_HMI_ENGAGEADVICEREQSeq, DMSG_HMI_ENGAGEADVICEREQ);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_THREATDICISIONTypeSupport, DMSG_HMI_THREATDICISION);

DDS_DATAWRITER_CPP(DMSG_HMI_THREATDICISIONDataWriter, DMSG_HMI_THREATDICISION);
DDS_DATAREADER_CPP(DMSG_HMI_THREATDICISIONDataReader, DMSG_HMI_THREATDICISIONSeq, DMSG_HMI_THREATDICISION);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_THREATDICISIONTypeSupport, DMSG_HMI_THREATDICISION);
DDS_DATAWRITER_C(DMSG_HMI_THREATDICISIONDataWriter, DMSG_HMI_THREATDICISION);
DDS_DATAREADER_C(DMSG_HMI_THREATDICISIONDataReader, DMSG_HMI_THREATDICISIONSeq, DMSG_HMI_THREATDICISION);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_WEAPONRANGETypeSupport, DMSG_HMI_WEAPONRANGE);

DDS_DATAWRITER_CPP(DMSG_HMI_WEAPONRANGEDataWriter, DMSG_HMI_WEAPONRANGE);
DDS_DATAREADER_CPP(DMSG_HMI_WEAPONRANGEDataReader, DMSG_HMI_WEAPONRANGESeq, DMSG_HMI_WEAPONRANGE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_WEAPONRANGETypeSupport, DMSG_HMI_WEAPONRANGE);
DDS_DATAWRITER_C(DMSG_HMI_WEAPONRANGEDataWriter, DMSG_HMI_WEAPONRANGE);
DDS_DATAREADER_C(DMSG_HMI_WEAPONRANGEDataReader, DMSG_HMI_WEAPONRANGESeq, DMSG_HMI_WEAPONRANGE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_SENSORRANGETypeSupport, DMSG_HMI_SENSORRANGE);

DDS_DATAWRITER_CPP(DMSG_HMI_SENSORRANGEDataWriter, DMSG_HMI_SENSORRANGE);
DDS_DATAREADER_CPP(DMSG_HMI_SENSORRANGEDataReader, DMSG_HMI_SENSORRANGESeq, DMSG_HMI_SENSORRANGE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_SENSORRANGETypeSupport, DMSG_HMI_SENSORRANGE);
DDS_DATAWRITER_C(DMSG_HMI_SENSORRANGEDataWriter, DMSG_HMI_SENSORRANGE);
DDS_DATAREADER_C(DMSG_HMI_SENSORRANGEDataReader, DMSG_HMI_SENSORRANGESeq, DMSG_HMI_SENSORRANGE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_ENGAGEADVICEMODIFYTypeSupport, DMSG_HMI_ENGAGEADVICEMODIFY);

DDS_DATAWRITER_CPP(DMSG_HMI_ENGAGEADVICEMODIFYDataWriter, DMSG_HMI_ENGAGEADVICEMODIFY);
DDS_DATAREADER_CPP(DMSG_HMI_ENGAGEADVICEMODIFYDataReader, DMSG_HMI_ENGAGEADVICEMODIFYSeq, DMSG_HMI_ENGAGEADVICEMODIFY);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_ENGAGEADVICEMODIFYTypeSupport, DMSG_HMI_ENGAGEADVICEMODIFY);
DDS_DATAWRITER_C(DMSG_HMI_ENGAGEADVICEMODIFYDataWriter, DMSG_HMI_ENGAGEADVICEMODIFY);
DDS_DATAREADER_C(DMSG_HMI_ENGAGEADVICEMODIFYDataReader, DMSG_HMI_ENGAGEADVICEMODIFYSeq, DMSG_HMI_ENGAGEADVICEMODIFY);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_CLEARENGAGEASSIGNTypeSupport, DMSG_HMI_CLEARENGAGEASSIGN);

DDS_DATAWRITER_CPP(DMSG_HMI_CLEARENGAGEASSIGNDataWriter, DMSG_HMI_CLEARENGAGEASSIGN);
DDS_DATAREADER_CPP(DMSG_HMI_CLEARENGAGEASSIGNDataReader, DMSG_HMI_CLEARENGAGEASSIGNSeq, DMSG_HMI_CLEARENGAGEASSIGN);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_CLEARENGAGEASSIGNTypeSupport, DMSG_HMI_CLEARENGAGEASSIGN);
DDS_DATAWRITER_C(DMSG_HMI_CLEARENGAGEASSIGNDataWriter, DMSG_HMI_CLEARENGAGEASSIGN);
DDS_DATAREADER_C(DMSG_HMI_CLEARENGAGEASSIGNDataReader, DMSG_HMI_CLEARENGAGEASSIGNSeq, DMSG_HMI_CLEARENGAGEASSIGN);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_THREATWEIGHTTypeSupport, DMSG_HMI_THREATWEIGHT);

DDS_DATAWRITER_CPP(DMSG_HMI_THREATWEIGHTDataWriter, DMSG_HMI_THREATWEIGHT);
DDS_DATAREADER_CPP(DMSG_HMI_THREATWEIGHTDataReader, DMSG_HMI_THREATWEIGHTSeq, DMSG_HMI_THREATWEIGHT);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_THREATWEIGHTTypeSupport, DMSG_HMI_THREATWEIGHT);
DDS_DATAWRITER_C(DMSG_HMI_THREATWEIGHTDataWriter, DMSG_HMI_THREATWEIGHT);
DDS_DATAREADER_C(DMSG_HMI_THREATWEIGHTDataReader, DMSG_HMI_THREATWEIGHTSeq, DMSG_HMI_THREATWEIGHT);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_DEFENSEMODETypeSupport, DMSG_HMI_DEFENSEMODE);

DDS_DATAWRITER_CPP(DMSG_HMI_DEFENSEMODEDataWriter, DMSG_HMI_DEFENSEMODE);
DDS_DATAREADER_CPP(DMSG_HMI_DEFENSEMODEDataReader, DMSG_HMI_DEFENSEMODESeq, DMSG_HMI_DEFENSEMODE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_DEFENSEMODETypeSupport, DMSG_HMI_DEFENSEMODE);
DDS_DATAWRITER_C(DMSG_HMI_DEFENSEMODEDataWriter, DMSG_HMI_DEFENSEMODE);
DDS_DATAREADER_C(DMSG_HMI_DEFENSEMODEDataReader, DMSG_HMI_DEFENSEMODESeq, DMSG_HMI_DEFENSEMODE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_FIREPERMITTypeSupport, DMSG_HMI_FIREPERMIT);

DDS_DATAWRITER_CPP(DMSG_HMI_FIREPERMITDataWriter, DMSG_HMI_FIREPERMIT);
DDS_DATAREADER_CPP(DMSG_HMI_FIREPERMITDataReader, DMSG_HMI_FIREPERMITSeq, DMSG_HMI_FIREPERMIT);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_FIREPERMITTypeSupport, DMSG_HMI_FIREPERMIT);
DDS_DATAWRITER_C(DMSG_HMI_FIREPERMITDataWriter, DMSG_HMI_FIREPERMIT);
DDS_DATAREADER_C(DMSG_HMI_FIREPERMITDataReader, DMSG_HMI_FIREPERMITSeq, DMSG_HMI_FIREPERMIT);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_ENGAGECANCELTypeSupport, DMSG_HMI_ENGAGECANCEL);

DDS_DATAWRITER_CPP(DMSG_HMI_ENGAGECANCELDataWriter, DMSG_HMI_ENGAGECANCEL);
DDS_DATAREADER_CPP(DMSG_HMI_ENGAGECANCELDataReader, DMSG_HMI_ENGAGECANCELSeq, DMSG_HMI_ENGAGECANCEL);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_ENGAGECANCELTypeSupport, DMSG_HMI_ENGAGECANCEL);
DDS_DATAWRITER_C(DMSG_HMI_ENGAGECANCELDataWriter, DMSG_HMI_ENGAGECANCEL);
DDS_DATAREADER_C(DMSG_HMI_ENGAGECANCELDataReader, DMSG_HMI_ENGAGECANCELSeq, DMSG_HMI_ENGAGECANCEL);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_HITEVALUATIONSETTypeSupport, DMSG_HMI_HITEVALUATIONSET);

DDS_DATAWRITER_CPP(DMSG_HMI_HITEVALUATIONSETDataWriter, DMSG_HMI_HITEVALUATIONSET);
DDS_DATAREADER_CPP(DMSG_HMI_HITEVALUATIONSETDataReader, DMSG_HMI_HITEVALUATIONSETSeq, DMSG_HMI_HITEVALUATIONSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_HITEVALUATIONSETTypeSupport, DMSG_HMI_HITEVALUATIONSET);
DDS_DATAWRITER_C(DMSG_HMI_HITEVALUATIONSETDataWriter, DMSG_HMI_HITEVALUATIONSET);
DDS_DATAREADER_C(DMSG_HMI_HITEVALUATIONSETDataReader, DMSG_HMI_HITEVALUATIONSETSeq, DMSG_HMI_HITEVALUATIONSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_ASSIGNCONSOLETypeSupport, DMSG_HMI_ASSIGNCONSOLE);

DDS_DATAWRITER_CPP(DMSG_HMI_ASSIGNCONSOLEDataWriter, DMSG_HMI_ASSIGNCONSOLE);
DDS_DATAREADER_CPP(DMSG_HMI_ASSIGNCONSOLEDataReader, DMSG_HMI_ASSIGNCONSOLESeq, DMSG_HMI_ASSIGNCONSOLE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_ASSIGNCONSOLETypeSupport, DMSG_HMI_ASSIGNCONSOLE);
DDS_DATAWRITER_C(DMSG_HMI_ASSIGNCONSOLEDataWriter, DMSG_HMI_ASSIGNCONSOLE);
DDS_DATAREADER_C(DMSG_HMI_ASSIGNCONSOLEDataReader, DMSG_HMI_ASSIGNCONSOLESeq, DMSG_HMI_ASSIGNCONSOLE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_GUIDEDWEAPONPERMITTypeSupport, DMSG_HMI_GUIDEDWEAPONPERMIT);

DDS_DATAWRITER_CPP(DMSG_HMI_GUIDEDWEAPONPERMITDataWriter, DMSG_HMI_GUIDEDWEAPONPERMIT);
DDS_DATAREADER_CPP(DMSG_HMI_GUIDEDWEAPONPERMITDataReader, DMSG_HMI_GUIDEDWEAPONPERMITSeq, DMSG_HMI_GUIDEDWEAPONPERMIT);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_GUIDEDWEAPONPERMITTypeSupport, DMSG_HMI_GUIDEDWEAPONPERMIT);
DDS_DATAWRITER_C(DMSG_HMI_GUIDEDWEAPONPERMITDataWriter, DMSG_HMI_GUIDEDWEAPONPERMIT);
DDS_DATAREADER_C(DMSG_HMI_GUIDEDWEAPONPERMITDataReader, DMSG_HMI_GUIDEDWEAPONPERMITSeq, DMSG_HMI_GUIDEDWEAPONPERMIT);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_ASSIGNTUBETypeSupport, DMSG_HMI_ASSIGNTUBE);

DDS_DATAWRITER_CPP(DMSG_HMI_ASSIGNTUBEDataWriter, DMSG_HMI_ASSIGNTUBE);
DDS_DATAREADER_CPP(DMSG_HMI_ASSIGNTUBEDataReader, DMSG_HMI_ASSIGNTUBESeq, DMSG_HMI_ASSIGNTUBE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_ASSIGNTUBETypeSupport, DMSG_HMI_ASSIGNTUBE);
DDS_DATAWRITER_C(DMSG_HMI_ASSIGNTUBEDataWriter, DMSG_HMI_ASSIGNTUBE);
DDS_DATAREADER_C(DMSG_HMI_ASSIGNTUBEDataReader, DMSG_HMI_ASSIGNTUBESeq, DMSG_HMI_ASSIGNTUBE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_ENGAGEPLANSETTypeSupport, DMSG_HMI_ENGAGEPLANSET);

DDS_DATAWRITER_CPP(DMSG_HMI_ENGAGEPLANSETDataWriter, DMSG_HMI_ENGAGEPLANSET);
DDS_DATAREADER_CPP(DMSG_HMI_ENGAGEPLANSETDataReader, DMSG_HMI_ENGAGEPLANSETSeq, DMSG_HMI_ENGAGEPLANSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_ENGAGEPLANSETTypeSupport, DMSG_HMI_ENGAGEPLANSET);
DDS_DATAWRITER_C(DMSG_HMI_ENGAGEPLANSETDataWriter, DMSG_HMI_ENGAGEPLANSET);
DDS_DATAREADER_C(DMSG_HMI_ENGAGEPLANSETDataReader, DMSG_HMI_ENGAGEPLANSETSeq, DMSG_HMI_ENGAGEPLANSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_FIREPERMITKEYSTATETypeSupport, DMSG_HMI_FIREPERMITKEYSTATE);

DDS_DATAWRITER_CPP(DMSG_HMI_FIREPERMITKEYSTATEDataWriter, DMSG_HMI_FIREPERMITKEYSTATE);
DDS_DATAREADER_CPP(DMSG_HMI_FIREPERMITKEYSTATEDataReader, DMSG_HMI_FIREPERMITKEYSTATESeq, DMSG_HMI_FIREPERMITKEYSTATE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_FIREPERMITKEYSTATETypeSupport, DMSG_HMI_FIREPERMITKEYSTATE);
DDS_DATAWRITER_C(DMSG_HMI_FIREPERMITKEYSTATEDataWriter, DMSG_HMI_FIREPERMITKEYSTATE);
DDS_DATAREADER_C(DMSG_HMI_FIREPERMITKEYSTATEDataReader, DMSG_HMI_FIREPERMITKEYSTATESeq, DMSG_HMI_FIREPERMITKEYSTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_FIREPERMITBTNSTATETypeSupport, DMSG_HMI_FIREPERMITBTNSTATE);

DDS_DATAWRITER_CPP(DMSG_HMI_FIREPERMITBTNSTATEDataWriter, DMSG_HMI_FIREPERMITBTNSTATE);
DDS_DATAREADER_CPP(DMSG_HMI_FIREPERMITBTNSTATEDataReader, DMSG_HMI_FIREPERMITBTNSTATESeq, DMSG_HMI_FIREPERMITBTNSTATE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_FIREPERMITBTNSTATETypeSupport, DMSG_HMI_FIREPERMITBTNSTATE);
DDS_DATAWRITER_C(DMSG_HMI_FIREPERMITBTNSTATEDataWriter, DMSG_HMI_FIREPERMITBTNSTATE);
DDS_DATAREADER_C(DMSG_HMI_FIREPERMITBTNSTATEDataReader, DMSG_HMI_FIREPERMITBTNSTATESeq, DMSG_HMI_FIREPERMITBTNSTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_FIRECMDTypeSupport, DMSG_HMI_FIRECMD);

DDS_DATAWRITER_CPP(DMSG_HMI_FIRECMDDataWriter, DMSG_HMI_FIRECMD);
DDS_DATAREADER_CPP(DMSG_HMI_FIRECMDDataReader, DMSG_HMI_FIRECMDSeq, DMSG_HMI_FIRECMD);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_FIRECMDTypeSupport, DMSG_HMI_FIRECMD);
DDS_DATAWRITER_C(DMSG_HMI_FIRECMDDataWriter, DMSG_HMI_FIRECMD);
DDS_DATAREADER_C(DMSG_HMI_FIRECMDDataReader, DMSG_HMI_FIRECMDSeq, DMSG_HMI_FIRECMD);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_ENGAGEASSIGNCMDTypeSupport, DMSG_HMI_ENGAGEASSIGNCMD);

DDS_DATAWRITER_CPP(DMSG_HMI_ENGAGEASSIGNCMDDataWriter, DMSG_HMI_ENGAGEASSIGNCMD);
DDS_DATAREADER_CPP(DMSG_HMI_ENGAGEASSIGNCMDDataReader, DMSG_HMI_ENGAGEASSIGNCMDSeq, DMSG_HMI_ENGAGEASSIGNCMD);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_ENGAGEASSIGNCMDTypeSupport, DMSG_HMI_ENGAGEASSIGNCMD);
DDS_DATAWRITER_C(DMSG_HMI_ENGAGEASSIGNCMDDataWriter, DMSG_HMI_ENGAGEASSIGNCMD);
DDS_DATAREADER_C(DMSG_HMI_ENGAGEASSIGNCMDDataReader, DMSG_HMI_ENGAGEASSIGNCMDSeq, DMSG_HMI_ENGAGEASSIGNCMD);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_FIRINGCMDTypeSupport, DMSG_HMI_FIRINGCMD);

DDS_DATAWRITER_CPP(DMSG_HMI_FIRINGCMDDataWriter, DMSG_HMI_FIRINGCMD);
DDS_DATAREADER_CPP(DMSG_HMI_FIRINGCMDDataReader, DMSG_HMI_FIRINGCMDSeq, DMSG_HMI_FIRINGCMD);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_FIRINGCMDTypeSupport, DMSG_HMI_FIRINGCMD);
DDS_DATAWRITER_C(DMSG_HMI_FIRINGCMDDataWriter, DMSG_HMI_FIRINGCMD);
DDS_DATAREADER_C(DMSG_HMI_FIRINGCMDDataReader, DMSG_HMI_FIRINGCMDSeq, DMSG_HMI_FIRINGCMD);

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

DDS_TYPESUPPORT_CPP(DMSG_EC_ENGAGEDELTypeSupport, DMSG_EC_ENGAGEDEL);

DDS_DATAWRITER_CPP(DMSG_EC_ENGAGEDELDataWriter, DMSG_EC_ENGAGEDEL);
DDS_DATAREADER_CPP(DMSG_EC_ENGAGEDELDataReader, DMSG_EC_ENGAGEDELSeq, DMSG_EC_ENGAGEDEL);


#else

DDS_TYPESUPPORT_C(DMSG_EC_ENGAGEDELTypeSupport, DMSG_EC_ENGAGEDEL);
DDS_DATAWRITER_C(DMSG_EC_ENGAGEDELDataWriter, DMSG_EC_ENGAGEDEL);
DDS_DATAREADER_C(DMSG_EC_ENGAGEDELDataReader, DMSG_EC_ENGAGEDELSeq, DMSG_EC_ENGAGEDEL);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_MANUALENGAGEASSIGNTypeSupport, DMSG_HMI_MANUALENGAGEASSIGN);

DDS_DATAWRITER_CPP(DMSG_HMI_MANUALENGAGEASSIGNDataWriter, DMSG_HMI_MANUALENGAGEASSIGN);
DDS_DATAREADER_CPP(DMSG_HMI_MANUALENGAGEASSIGNDataReader, DMSG_HMI_MANUALENGAGEASSIGNSeq, DMSG_HMI_MANUALENGAGEASSIGN);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_MANUALENGAGEASSIGNTypeSupport, DMSG_HMI_MANUALENGAGEASSIGN);
DDS_DATAWRITER_C(DMSG_HMI_MANUALENGAGEASSIGNDataWriter, DMSG_HMI_MANUALENGAGEASSIGN);
DDS_DATAREADER_C(DMSG_HMI_MANUALENGAGEASSIGNDataReader, DMSG_HMI_MANUALENGAGEASSIGNSeq, DMSG_HMI_MANUALENGAGEASSIGN);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_EMERGENCYFIRETypeSupport, DMSG_HMI_EMERGENCYFIRE);

DDS_DATAWRITER_CPP(DMSG_HMI_EMERGENCYFIREDataWriter, DMSG_HMI_EMERGENCYFIRE);
DDS_DATAREADER_CPP(DMSG_HMI_EMERGENCYFIREDataReader, DMSG_HMI_EMERGENCYFIRESeq, DMSG_HMI_EMERGENCYFIRE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_EMERGENCYFIRETypeSupport, DMSG_HMI_EMERGENCYFIRE);
DDS_DATAWRITER_C(DMSG_HMI_EMERGENCYFIREDataWriter, DMSG_HMI_EMERGENCYFIRE);
DDS_DATAREADER_C(DMSG_HMI_EMERGENCYFIREDataReader, DMSG_HMI_EMERGENCYFIRESeq, DMSG_HMI_EMERGENCYFIRE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_SAMTARGETDESIGTypeSupport, DMSG_HMI_SAMTARGETDESIG);

DDS_DATAWRITER_CPP(DMSG_HMI_SAMTARGETDESIGDataWriter, DMSG_HMI_SAMTARGETDESIG);
DDS_DATAREADER_CPP(DMSG_HMI_SAMTARGETDESIGDataReader, DMSG_HMI_SAMTARGETDESIGSeq, DMSG_HMI_SAMTARGETDESIG);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_SAMTARGETDESIGTypeSupport, DMSG_HMI_SAMTARGETDESIG);
DDS_DATAWRITER_C(DMSG_HMI_SAMTARGETDESIGDataWriter, DMSG_HMI_SAMTARGETDESIG);
DDS_DATAREADER_C(DMSG_HMI_SAMTARGETDESIGDataReader, DMSG_HMI_SAMTARGETDESIGSeq, DMSG_HMI_SAMTARGETDESIG);

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

DDS_TYPESUPPORT_CPP(DMSG_EC_GUIDEDWEAPONPERMITTypeSupport, DMSG_EC_GUIDEDWEAPONPERMIT);

DDS_DATAWRITER_CPP(DMSG_EC_GUIDEDWEAPONPERMITDataWriter, DMSG_EC_GUIDEDWEAPONPERMIT);
DDS_DATAREADER_CPP(DMSG_EC_GUIDEDWEAPONPERMITDataReader, DMSG_EC_GUIDEDWEAPONPERMITSeq, DMSG_EC_GUIDEDWEAPONPERMIT);


#else

DDS_TYPESUPPORT_C(DMSG_EC_GUIDEDWEAPONPERMITTypeSupport, DMSG_EC_GUIDEDWEAPONPERMIT);
DDS_DATAWRITER_C(DMSG_EC_GUIDEDWEAPONPERMITDataWriter, DMSG_EC_GUIDEDWEAPONPERMIT);
DDS_DATAREADER_C(DMSG_EC_GUIDEDWEAPONPERMITDataReader, DMSG_EC_GUIDEDWEAPONPERMITSeq, DMSG_EC_GUIDEDWEAPONPERMIT);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TRRTRACKINGCMDTypeSupport, DMSG_HMI_TRRTRACKINGCMD);

DDS_DATAWRITER_CPP(DMSG_HMI_TRRTRACKINGCMDDataWriter, DMSG_HMI_TRRTRACKINGCMD);
DDS_DATAREADER_CPP(DMSG_HMI_TRRTRACKINGCMDDataReader, DMSG_HMI_TRRTRACKINGCMDSeq, DMSG_HMI_TRRTRACKINGCMD);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TRRTRACKINGCMDTypeSupport, DMSG_HMI_TRRTRACKINGCMD);
DDS_DATAWRITER_C(DMSG_HMI_TRRTRACKINGCMDDataWriter, DMSG_HMI_TRRTRACKINGCMD);
DDS_DATAREADER_C(DMSG_HMI_TRRTRACKINGCMDDataReader, DMSG_HMI_TRRTRACKINGCMDSeq, DMSG_HMI_TRRTRACKINGCMD);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_EOTSSUBTRACKINGSETTypeSupport, DMSG_HMI_EOTSSUBTRACKINGSET);

DDS_DATAWRITER_CPP(DMSG_HMI_EOTSSUBTRACKINGSETDataWriter, DMSG_HMI_EOTSSUBTRACKINGSET);
DDS_DATAREADER_CPP(DMSG_HMI_EOTSSUBTRACKINGSETDataReader, DMSG_HMI_EOTSSUBTRACKINGSETSeq, DMSG_HMI_EOTSSUBTRACKINGSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_EOTSSUBTRACKINGSETTypeSupport, DMSG_HMI_EOTSSUBTRACKINGSET);
DDS_DATAWRITER_C(DMSG_HMI_EOTSSUBTRACKINGSETDataWriter, DMSG_HMI_EOTSSUBTRACKINGSET);
DDS_DATAREADER_C(DMSG_HMI_EOTSSUBTRACKINGSETDataReader, DMSG_HMI_EOTSSUBTRACKINGSETSeq, DMSG_HMI_EOTSSUBTRACKINGSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRTWSTARGETDESIGTypeSupport, DMSG_HMI_TDSRTWSTARGETDESIG);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRTWSTARGETDESIGDataWriter, DMSG_HMI_TDSRTWSTARGETDESIG);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRTWSTARGETDESIGDataReader, DMSG_HMI_TDSRTWSTARGETDESIGSeq, DMSG_HMI_TDSRTWSTARGETDESIG);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRTWSTARGETDESIGTypeSupport, DMSG_HMI_TDSRTWSTARGETDESIG);
DDS_DATAWRITER_C(DMSG_HMI_TDSRTWSTARGETDESIGDataWriter, DMSG_HMI_TDSRTWSTARGETDESIG);
DDS_DATAREADER_C(DMSG_HMI_TDSRTWSTARGETDESIGDataReader, DMSG_HMI_TDSRTWSTARGETDESIGSeq, DMSG_HMI_TDSRTWSTARGETDESIG);

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

DDS_TYPESUPPORT_CPP(DMSG_HMISUB_ENGAGECANCELTypeSupport, DMSG_HMISUB_ENGAGECANCEL);

DDS_DATAWRITER_CPP(DMSG_HMISUB_ENGAGECANCELDataWriter, DMSG_HMISUB_ENGAGECANCEL);
DDS_DATAREADER_CPP(DMSG_HMISUB_ENGAGECANCELDataReader, DMSG_HMISUB_ENGAGECANCELSeq, DMSG_HMISUB_ENGAGECANCEL);


#else

DDS_TYPESUPPORT_C(DMSG_HMISUB_ENGAGECANCELTypeSupport, DMSG_HMISUB_ENGAGECANCEL);
DDS_DATAWRITER_C(DMSG_HMISUB_ENGAGECANCELDataWriter, DMSG_HMISUB_ENGAGECANCEL);
DDS_DATAREADER_C(DMSG_HMISUB_ENGAGECANCELDataReader, DMSG_HMISUB_ENGAGECANCELSeq, DMSG_HMISUB_ENGAGECANCEL);

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

DDS_TYPESUPPORT_CPP(DMSG_EC_SUBENGAGEDELTypeSupport, DMSG_EC_SUBENGAGEDEL);

DDS_DATAWRITER_CPP(DMSG_EC_SUBENGAGEDELDataWriter, DMSG_EC_SUBENGAGEDEL);
DDS_DATAREADER_CPP(DMSG_EC_SUBENGAGEDELDataReader, DMSG_EC_SUBENGAGEDELSeq, DMSG_EC_SUBENGAGEDEL);


#else

DDS_TYPESUPPORT_C(DMSG_EC_SUBENGAGEDELTypeSupport, DMSG_EC_SUBENGAGEDEL);
DDS_DATAWRITER_C(DMSG_EC_SUBENGAGEDELDataWriter, DMSG_EC_SUBENGAGEDEL);
DDS_DATAREADER_C(DMSG_EC_SUBENGAGEDELDataReader, DMSG_EC_SUBENGAGEDELSeq, DMSG_EC_SUBENGAGEDEL);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_FIREMODETypeSupport, DMSG_HMI_FIREMODE);

DDS_DATAWRITER_CPP(DMSG_HMI_FIREMODEDataWriter, DMSG_HMI_FIREMODE);
DDS_DATAREADER_CPP(DMSG_HMI_FIREMODEDataReader, DMSG_HMI_FIREMODESeq, DMSG_HMI_FIREMODE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_FIREMODETypeSupport, DMSG_HMI_FIREMODE);
DDS_DATAWRITER_C(DMSG_HMI_FIREMODEDataWriter, DMSG_HMI_FIREMODE);
DDS_DATAREADER_C(DMSG_HMI_FIREMODEDataReader, DMSG_HMI_FIREMODESeq, DMSG_HMI_FIREMODE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_ASSIGNSLTSTUBETypeSupport, DMSG_HMI_ASSIGNSLTSTUBE);

DDS_DATAWRITER_CPP(DMSG_HMI_ASSIGNSLTSTUBEDataWriter, DMSG_HMI_ASSIGNSLTSTUBE);
DDS_DATAREADER_CPP(DMSG_HMI_ASSIGNSLTSTUBEDataReader, DMSG_HMI_ASSIGNSLTSTUBESeq, DMSG_HMI_ASSIGNSLTSTUBE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_ASSIGNSLTSTUBETypeSupport, DMSG_HMI_ASSIGNSLTSTUBE);
DDS_DATAWRITER_C(DMSG_HMI_ASSIGNSLTSTUBEDataWriter, DMSG_HMI_ASSIGNSLTSTUBE);
DDS_DATAREADER_C(DMSG_HMI_ASSIGNSLTSTUBEDataReader, DMSG_HMI_ASSIGNSLTSTUBESeq, DMSG_HMI_ASSIGNSLTSTUBE);

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

DDS_TYPESUPPORT_CPP(DMSG_TEWA_ENGAGEADVICEDELTypeSupport, DMSG_TEWA_ENGAGEADVICEDEL);

DDS_DATAWRITER_CPP(DMSG_TEWA_ENGAGEADVICEDELDataWriter, DMSG_TEWA_ENGAGEADVICEDEL);
DDS_DATAREADER_CPP(DMSG_TEWA_ENGAGEADVICEDELDataReader, DMSG_TEWA_ENGAGEADVICEDELSeq, DMSG_TEWA_ENGAGEADVICEDEL);


#else

DDS_TYPESUPPORT_C(DMSG_TEWA_ENGAGEADVICEDELTypeSupport, DMSG_TEWA_ENGAGEADVICEDEL);
DDS_DATAWRITER_C(DMSG_TEWA_ENGAGEADVICEDELDataWriter, DMSG_TEWA_ENGAGEADVICEDEL);
DDS_DATAREADER_C(DMSG_TEWA_ENGAGEADVICEDELDataReader, DMSG_TEWA_ENGAGEADVICEDELSeq, DMSG_TEWA_ENGAGEADVICEDEL);

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

DDS_TYPESUPPORT_CPP(DMSG_TEWA_FASTRESPONSECHANNELTypeSupport, DMSG_TEWA_FASTRESPONSECHANNEL);

DDS_DATAWRITER_CPP(DMSG_TEWA_FASTRESPONSECHANNELDataWriter, DMSG_TEWA_FASTRESPONSECHANNEL);
DDS_DATAREADER_CPP(DMSG_TEWA_FASTRESPONSECHANNELDataReader, DMSG_TEWA_FASTRESPONSECHANNELSeq, DMSG_TEWA_FASTRESPONSECHANNEL);


#else

DDS_TYPESUPPORT_C(DMSG_TEWA_FASTRESPONSECHANNELTypeSupport, DMSG_TEWA_FASTRESPONSECHANNEL);
DDS_DATAWRITER_C(DMSG_TEWA_FASTRESPONSECHANNELDataWriter, DMSG_TEWA_FASTRESPONSECHANNEL);
DDS_DATAREADER_C(DMSG_TEWA_FASTRESPONSECHANNELDataReader, DMSG_TEWA_FASTRESPONSECHANNELSeq, DMSG_TEWA_FASTRESPONSECHANNEL);

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

DDS_TYPESUPPORT_CPP(DMSG_TEWA_ENGAGEADVICETypeSupport, DMSG_TEWA_ENGAGEADVICE);

DDS_DATAWRITER_CPP(DMSG_TEWA_ENGAGEADVICEDataWriter, DMSG_TEWA_ENGAGEADVICE);
DDS_DATAREADER_CPP(DMSG_TEWA_ENGAGEADVICEDataReader, DMSG_TEWA_ENGAGEADVICESeq, DMSG_TEWA_ENGAGEADVICE);


#else

DDS_TYPESUPPORT_C(DMSG_TEWA_ENGAGEADVICETypeSupport, DMSG_TEWA_ENGAGEADVICE);
DDS_DATAWRITER_C(DMSG_TEWA_ENGAGEADVICEDataWriter, DMSG_TEWA_ENGAGEADVICE);
DDS_DATAREADER_C(DMSG_TEWA_ENGAGEADVICEDataReader, DMSG_TEWA_ENGAGEADVICESeq, DMSG_TEWA_ENGAGEADVICE);

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

DDS_TYPESUPPORT_CPP(DMSG_TEWA_THREATDELTypeSupport, DMSG_TEWA_THREATDEL);

DDS_DATAWRITER_CPP(DMSG_TEWA_THREATDELDataWriter, DMSG_TEWA_THREATDEL);
DDS_DATAREADER_CPP(DMSG_TEWA_THREATDELDataReader, DMSG_TEWA_THREATDELSeq, DMSG_TEWA_THREATDEL);


#else

DDS_TYPESUPPORT_C(DMSG_TEWA_THREATDELTypeSupport, DMSG_TEWA_THREATDEL);
DDS_DATAWRITER_C(DMSG_TEWA_THREATDELDataWriter, DMSG_TEWA_THREATDEL);
DDS_DATAREADER_C(DMSG_TEWA_THREATDELDataReader, DMSG_TEWA_THREATDELSeq, DMSG_TEWA_THREATDEL);

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

DDS_TYPESUPPORT_CPP(DMSG_TEWA_AIRTHREATEVALUATIONTypeSupport, DMSG_TEWA_AIRTHREATEVALUATION);

DDS_DATAWRITER_CPP(DMSG_TEWA_AIRTHREATEVALUATIONDataWriter, DMSG_TEWA_AIRTHREATEVALUATION);
DDS_DATAREADER_CPP(DMSG_TEWA_AIRTHREATEVALUATIONDataReader, DMSG_TEWA_AIRTHREATEVALUATIONSeq, DMSG_TEWA_AIRTHREATEVALUATION);


#else

DDS_TYPESUPPORT_C(DMSG_TEWA_AIRTHREATEVALUATIONTypeSupport, DMSG_TEWA_AIRTHREATEVALUATION);
DDS_DATAWRITER_C(DMSG_TEWA_AIRTHREATEVALUATIONDataWriter, DMSG_TEWA_AIRTHREATEVALUATION);
DDS_DATAREADER_C(DMSG_TEWA_AIRTHREATEVALUATIONDataReader, DMSG_TEWA_AIRTHREATEVALUATIONSeq, DMSG_TEWA_AIRTHREATEVALUATION);

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

DDS_TYPESUPPORT_CPP(DMSG_TEWA_SHIPTHREATEVALUATIONTypeSupport, DMSG_TEWA_SHIPTHREATEVALUATION);

DDS_DATAWRITER_CPP(DMSG_TEWA_SHIPTHREATEVALUATIONDataWriter, DMSG_TEWA_SHIPTHREATEVALUATION);
DDS_DATAREADER_CPP(DMSG_TEWA_SHIPTHREATEVALUATIONDataReader, DMSG_TEWA_SHIPTHREATEVALUATIONSeq, DMSG_TEWA_SHIPTHREATEVALUATION);


#else

DDS_TYPESUPPORT_C(DMSG_TEWA_SHIPTHREATEVALUATIONTypeSupport, DMSG_TEWA_SHIPTHREATEVALUATION);
DDS_DATAWRITER_C(DMSG_TEWA_SHIPTHREATEVALUATIONDataWriter, DMSG_TEWA_SHIPTHREATEVALUATION);
DDS_DATAREADER_C(DMSG_TEWA_SHIPTHREATEVALUATIONDataReader, DMSG_TEWA_SHIPTHREATEVALUATIONSeq, DMSG_TEWA_SHIPTHREATEVALUATION);

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

DDS_TYPESUPPORT_CPP(DMSG_TEWA_SUBTHREATEVALUATIONTypeSupport, DMSG_TEWA_SUBTHREATEVALUATION);

DDS_DATAWRITER_CPP(DMSG_TEWA_SUBTHREATEVALUATIONDataWriter, DMSG_TEWA_SUBTHREATEVALUATION);
DDS_DATAREADER_CPP(DMSG_TEWA_SUBTHREATEVALUATIONDataReader, DMSG_TEWA_SUBTHREATEVALUATIONSeq, DMSG_TEWA_SUBTHREATEVALUATION);


#else

DDS_TYPESUPPORT_C(DMSG_TEWA_SUBTHREATEVALUATIONTypeSupport, DMSG_TEWA_SUBTHREATEVALUATION);
DDS_DATAWRITER_C(DMSG_TEWA_SUBTHREATEVALUATIONDataWriter, DMSG_TEWA_SUBTHREATEVALUATION);
DDS_DATAREADER_C(DMSG_TEWA_SUBTHREATEVALUATIONDataReader, DMSG_TEWA_SUBTHREATEVALUATIONSeq, DMSG_TEWA_SUBTHREATEVALUATION);

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

DDS_TYPESUPPORT_CPP(DMSG_TEWA_ENGAGEPOSSIBILITYTypeSupport, DMSG_TEWA_ENGAGEPOSSIBILITY);

DDS_DATAWRITER_CPP(DMSG_TEWA_ENGAGEPOSSIBILITYDataWriter, DMSG_TEWA_ENGAGEPOSSIBILITY);
DDS_DATAREADER_CPP(DMSG_TEWA_ENGAGEPOSSIBILITYDataReader, DMSG_TEWA_ENGAGEPOSSIBILITYSeq, DMSG_TEWA_ENGAGEPOSSIBILITY);


#else

DDS_TYPESUPPORT_C(DMSG_TEWA_ENGAGEPOSSIBILITYTypeSupport, DMSG_TEWA_ENGAGEPOSSIBILITY);
DDS_DATAWRITER_C(DMSG_TEWA_ENGAGEPOSSIBILITYDataWriter, DMSG_TEWA_ENGAGEPOSSIBILITY);
DDS_DATAREADER_C(DMSG_TEWA_ENGAGEPOSSIBILITYDataReader, DMSG_TEWA_ENGAGEPOSSIBILITYSeq, DMSG_TEWA_ENGAGEPOSSIBILITY);

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

DDS_TYPESUPPORT_CPP(DMSG_TEWA_SWSTATETypeSupport, DMSG_TEWA_SWSTATE);

DDS_DATAWRITER_CPP(DMSG_TEWA_SWSTATEDataWriter, DMSG_TEWA_SWSTATE);
DDS_DATAREADER_CPP(DMSG_TEWA_SWSTATEDataReader, DMSG_TEWA_SWSTATESeq, DMSG_TEWA_SWSTATE);


#else

DDS_TYPESUPPORT_C(DMSG_TEWA_SWSTATETypeSupport, DMSG_TEWA_SWSTATE);
DDS_DATAWRITER_C(DMSG_TEWA_SWSTATEDataWriter, DMSG_TEWA_SWSTATE);
DDS_DATAREADER_C(DMSG_TEWA_SWSTATEDataReader, DMSG_TEWA_SWSTATESeq, DMSG_TEWA_SWSTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_TEWA_TORPEDOALERTTypeSupport, DMSG_TEWA_TORPEDOALERT);

DDS_DATAWRITER_CPP(DMSG_TEWA_TORPEDOALERTDataWriter, DMSG_TEWA_TORPEDOALERT);
DDS_DATAREADER_CPP(DMSG_TEWA_TORPEDOALERTDataReader, DMSG_TEWA_TORPEDOALERTSeq, DMSG_TEWA_TORPEDOALERT);


#else

DDS_TYPESUPPORT_C(DMSG_TEWA_TORPEDOALERTTypeSupport, DMSG_TEWA_TORPEDOALERT);
DDS_DATAWRITER_C(DMSG_TEWA_TORPEDOALERTDataWriter, DMSG_TEWA_TORPEDOALERT);
DDS_DATAREADER_C(DMSG_TEWA_TORPEDOALERTDataReader, DMSG_TEWA_TORPEDOALERTSeq, DMSG_TEWA_TORPEDOALERT);

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

DDS_TYPESUPPORT_CPP(DMSG_TEWA_DIRECTENGAGEADVICETypeSupport, DMSG_TEWA_DIRECTENGAGEADVICE);

DDS_DATAWRITER_CPP(DMSG_TEWA_DIRECTENGAGEADVICEDataWriter, DMSG_TEWA_DIRECTENGAGEADVICE);
DDS_DATAREADER_CPP(DMSG_TEWA_DIRECTENGAGEADVICEDataReader, DMSG_TEWA_DIRECTENGAGEADVICESeq, DMSG_TEWA_DIRECTENGAGEADVICE);


#else

DDS_TYPESUPPORT_C(DMSG_TEWA_DIRECTENGAGEADVICETypeSupport, DMSG_TEWA_DIRECTENGAGEADVICE);
DDS_DATAWRITER_C(DMSG_TEWA_DIRECTENGAGEADVICEDataWriter, DMSG_TEWA_DIRECTENGAGEADVICE);
DDS_DATAREADER_C(DMSG_TEWA_DIRECTENGAGEADVICEDataReader, DMSG_TEWA_DIRECTENGAGEADVICESeq, DMSG_TEWA_DIRECTENGAGEADVICE);

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

DDS_TYPESUPPORT_CPP(DMSG_TEWA_SENSORWEAPONREQTypeSupport, DMSG_TEWA_SENSORWEAPONREQ);

DDS_DATAWRITER_CPP(DMSG_TEWA_SENSORWEAPONREQDataWriter, DMSG_TEWA_SENSORWEAPONREQ);
DDS_DATAREADER_CPP(DMSG_TEWA_SENSORWEAPONREQDataReader, DMSG_TEWA_SENSORWEAPONREQSeq, DMSG_TEWA_SENSORWEAPONREQ);


#else

DDS_TYPESUPPORT_C(DMSG_TEWA_SENSORWEAPONREQTypeSupport, DMSG_TEWA_SENSORWEAPONREQ);
DDS_DATAWRITER_C(DMSG_TEWA_SENSORWEAPONREQDataWriter, DMSG_TEWA_SENSORWEAPONREQ);
DDS_DATAREADER_C(DMSG_TEWA_SENSORWEAPONREQDataReader, DMSG_TEWA_SENSORWEAPONREQSeq, DMSG_TEWA_SENSORWEAPONREQ);

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

DDS_TYPESUPPORT_CPP(DMSG_EC_HITEVALUATIONSRESULTTypeSupport, DMSG_EC_HITEVALUATIONSRESULT);

DDS_DATAWRITER_CPP(DMSG_EC_HITEVALUATIONSRESULTDataWriter, DMSG_EC_HITEVALUATIONSRESULT);
DDS_DATAREADER_CPP(DMSG_EC_HITEVALUATIONSRESULTDataReader, DMSG_EC_HITEVALUATIONSRESULTSeq, DMSG_EC_HITEVALUATIONSRESULT);


#else

DDS_TYPESUPPORT_C(DMSG_EC_HITEVALUATIONSRESULTTypeSupport, DMSG_EC_HITEVALUATIONSRESULT);
DDS_DATAWRITER_C(DMSG_EC_HITEVALUATIONSRESULTDataWriter, DMSG_EC_HITEVALUATIONSRESULT);
DDS_DATAREADER_C(DMSG_EC_HITEVALUATIONSRESULTDataReader, DMSG_EC_HITEVALUATIONSRESULTSeq, DMSG_EC_HITEVALUATIONSRESULT);

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

DDS_TYPESUPPORT_CPP(DMSG_EC_ENGAGEINFOTypeSupport, DMSG_EC_ENGAGEINFO);

DDS_DATAWRITER_CPP(DMSG_EC_ENGAGEINFODataWriter, DMSG_EC_ENGAGEINFO);
DDS_DATAREADER_CPP(DMSG_EC_ENGAGEINFODataReader, DMSG_EC_ENGAGEINFOSeq, DMSG_EC_ENGAGEINFO);


#else

DDS_TYPESUPPORT_C(DMSG_EC_ENGAGEINFOTypeSupport, DMSG_EC_ENGAGEINFO);
DDS_DATAWRITER_C(DMSG_EC_ENGAGEINFODataWriter, DMSG_EC_ENGAGEINFO);
DDS_DATAREADER_C(DMSG_EC_ENGAGEINFODataReader, DMSG_EC_ENGAGEINFOSeq, DMSG_EC_ENGAGEINFO);

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

DDS_TYPESUPPORT_CPP(DMSG_EC_ENGAGEASSIGNTypeSupport, DMSG_EC_ENGAGEASSIGN);

DDS_DATAWRITER_CPP(DMSG_EC_ENGAGEASSIGNDataWriter, DMSG_EC_ENGAGEASSIGN);
DDS_DATAREADER_CPP(DMSG_EC_ENGAGEASSIGNDataReader, DMSG_EC_ENGAGEASSIGNSeq, DMSG_EC_ENGAGEASSIGN);


#else

DDS_TYPESUPPORT_C(DMSG_EC_ENGAGEASSIGNTypeSupport, DMSG_EC_ENGAGEASSIGN);
DDS_DATAWRITER_C(DMSG_EC_ENGAGEASSIGNDataWriter, DMSG_EC_ENGAGEASSIGN);
DDS_DATAREADER_C(DMSG_EC_ENGAGEASSIGNDataReader, DMSG_EC_ENGAGEASSIGNSeq, DMSG_EC_ENGAGEASSIGN);

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

DDS_TYPESUPPORT_CPP(DMSG_EC_ENGAGEPLANSETTypeSupport, DMSG_EC_ENGAGEPLANSET);

DDS_DATAWRITER_CPP(DMSG_EC_ENGAGEPLANSETDataWriter, DMSG_EC_ENGAGEPLANSET);
DDS_DATAREADER_CPP(DMSG_EC_ENGAGEPLANSETDataReader, DMSG_EC_ENGAGEPLANSETSeq, DMSG_EC_ENGAGEPLANSET);


#else

DDS_TYPESUPPORT_C(DMSG_EC_ENGAGEPLANSETTypeSupport, DMSG_EC_ENGAGEPLANSET);
DDS_DATAWRITER_C(DMSG_EC_ENGAGEPLANSETDataWriter, DMSG_EC_ENGAGEPLANSET);
DDS_DATAREADER_C(DMSG_EC_ENGAGEPLANSETDataReader, DMSG_EC_ENGAGEPLANSETSeq, DMSG_EC_ENGAGEPLANSET);

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

DDS_TYPESUPPORT_CPP(DMSG_EC_FIREPERMITKEYSTATETypeSupport, DMSG_EC_FIREPERMITKEYSTATE);

DDS_DATAWRITER_CPP(DMSG_EC_FIREPERMITKEYSTATEDataWriter, DMSG_EC_FIREPERMITKEYSTATE);
DDS_DATAREADER_CPP(DMSG_EC_FIREPERMITKEYSTATEDataReader, DMSG_EC_FIREPERMITKEYSTATESeq, DMSG_EC_FIREPERMITKEYSTATE);


#else

DDS_TYPESUPPORT_C(DMSG_EC_FIREPERMITKEYSTATETypeSupport, DMSG_EC_FIREPERMITKEYSTATE);
DDS_DATAWRITER_C(DMSG_EC_FIREPERMITKEYSTATEDataWriter, DMSG_EC_FIREPERMITKEYSTATE);
DDS_DATAREADER_C(DMSG_EC_FIREPERMITKEYSTATEDataReader, DMSG_EC_FIREPERMITKEYSTATESeq, DMSG_EC_FIREPERMITKEYSTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_EC_ENGAGESTATETypeSupport, DMSG_EC_ENGAGESTATE);

DDS_DATAWRITER_CPP(DMSG_EC_ENGAGESTATEDataWriter, DMSG_EC_ENGAGESTATE);
DDS_DATAREADER_CPP(DMSG_EC_ENGAGESTATEDataReader, DMSG_EC_ENGAGESTATESeq, DMSG_EC_ENGAGESTATE);


#else

DDS_TYPESUPPORT_C(DMSG_EC_ENGAGESTATETypeSupport, DMSG_EC_ENGAGESTATE);
DDS_DATAWRITER_C(DMSG_EC_ENGAGESTATEDataWriter, DMSG_EC_ENGAGESTATE);
DDS_DATAREADER_C(DMSG_EC_ENGAGESTATEDataReader, DMSG_EC_ENGAGESTATESeq, DMSG_EC_ENGAGESTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_EC_SWSTATETypeSupport, DMSG_EC_SWSTATE);

DDS_DATAWRITER_CPP(DMSG_EC_SWSTATEDataWriter, DMSG_EC_SWSTATE);
DDS_DATAREADER_CPP(DMSG_EC_SWSTATEDataReader, DMSG_EC_SWSTATESeq, DMSG_EC_SWSTATE);


#else

DDS_TYPESUPPORT_C(DMSG_EC_SWSTATETypeSupport, DMSG_EC_SWSTATE);
DDS_DATAWRITER_C(DMSG_EC_SWSTATEDataWriter, DMSG_EC_SWSTATE);
DDS_DATAREADER_C(DMSG_EC_SWSTATEDataReader, DMSG_EC_SWSTATESeq, DMSG_EC_SWSTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_EC_WEAPONCTRLMODETypeSupport, DMSG_EC_WEAPONCTRLMODE);

DDS_DATAWRITER_CPP(DMSG_EC_WEAPONCTRLMODEDataWriter, DMSG_EC_WEAPONCTRLMODE);
DDS_DATAREADER_CPP(DMSG_EC_WEAPONCTRLMODEDataReader, DMSG_EC_WEAPONCTRLMODESeq, DMSG_EC_WEAPONCTRLMODE);


#else

DDS_TYPESUPPORT_C(DMSG_EC_WEAPONCTRLMODETypeSupport, DMSG_EC_WEAPONCTRLMODE);
DDS_DATAWRITER_C(DMSG_EC_WEAPONCTRLMODEDataWriter, DMSG_EC_WEAPONCTRLMODE);
DDS_DATAREADER_C(DMSG_EC_WEAPONCTRLMODEDataReader, DMSG_EC_WEAPONCTRLMODESeq, DMSG_EC_WEAPONCTRLMODE);

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

DDS_TYPESUPPORT_CPP(DMSG_EC_HORTUBEASSIGNTypeSupport, DMSG_EC_HORTUBEASSIGN);

DDS_DATAWRITER_CPP(DMSG_EC_HORTUBEASSIGNDataWriter, DMSG_EC_HORTUBEASSIGN);
DDS_DATAREADER_CPP(DMSG_EC_HORTUBEASSIGNDataReader, DMSG_EC_HORTUBEASSIGNSeq, DMSG_EC_HORTUBEASSIGN);


#else

DDS_TYPESUPPORT_C(DMSG_EC_HORTUBEASSIGNTypeSupport, DMSG_EC_HORTUBEASSIGN);
DDS_DATAWRITER_C(DMSG_EC_HORTUBEASSIGNDataWriter, DMSG_EC_HORTUBEASSIGN);
DDS_DATAREADER_C(DMSG_EC_HORTUBEASSIGNDataReader, DMSG_EC_HORTUBEASSIGNSeq, DMSG_EC_HORTUBEASSIGN);

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

DDS_TYPESUPPORT_CPP(DMSG_EC_VERTUBEASSIGNTypeSupport, DMSG_EC_VERTUBEASSIGN);

DDS_DATAWRITER_CPP(DMSG_EC_VERTUBEASSIGNDataWriter, DMSG_EC_VERTUBEASSIGN);
DDS_DATAREADER_CPP(DMSG_EC_VERTUBEASSIGNDataReader, DMSG_EC_VERTUBEASSIGNSeq, DMSG_EC_VERTUBEASSIGN);


#else

DDS_TYPESUPPORT_C(DMSG_EC_VERTUBEASSIGNTypeSupport, DMSG_EC_VERTUBEASSIGN);
DDS_DATAWRITER_C(DMSG_EC_VERTUBEASSIGNDataWriter, DMSG_EC_VERTUBEASSIGN);
DDS_DATAREADER_C(DMSG_EC_VERTUBEASSIGNDataReader, DMSG_EC_VERTUBEASSIGNSeq, DMSG_EC_VERTUBEASSIGN);

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

DDS_TYPESUPPORT_CPP(DMSG_EC_WEAPONFIRESTATETypeSupport, DMSG_EC_WEAPONFIRESTATE);

DDS_DATAWRITER_CPP(DMSG_EC_WEAPONFIRESTATEDataWriter, DMSG_EC_WEAPONFIRESTATE);
DDS_DATAREADER_CPP(DMSG_EC_WEAPONFIRESTATEDataReader, DMSG_EC_WEAPONFIRESTATESeq, DMSG_EC_WEAPONFIRESTATE);


#else

DDS_TYPESUPPORT_C(DMSG_EC_WEAPONFIRESTATETypeSupport, DMSG_EC_WEAPONFIRESTATE);
DDS_DATAWRITER_C(DMSG_EC_WEAPONFIRESTATEDataWriter, DMSG_EC_WEAPONFIRESTATE);
DDS_DATAREADER_C(DMSG_EC_WEAPONFIRESTATEDataReader, DMSG_EC_WEAPONFIRESTATESeq, DMSG_EC_WEAPONFIRESTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_EC_FIRECMDTypeSupport, DMSG_EC_FIRECMD);

DDS_DATAWRITER_CPP(DMSG_EC_FIRECMDDataWriter, DMSG_EC_FIRECMD);
DDS_DATAREADER_CPP(DMSG_EC_FIRECMDDataReader, DMSG_EC_FIRECMDSeq, DMSG_EC_FIRECMD);


#else

DDS_TYPESUPPORT_C(DMSG_EC_FIRECMDTypeSupport, DMSG_EC_FIRECMD);
DDS_DATAWRITER_C(DMSG_EC_FIRECMDDataWriter, DMSG_EC_FIRECMD);
DDS_DATAREADER_C(DMSG_EC_FIRECMDDataReader, DMSG_EC_FIRECMDSeq, DMSG_EC_FIRECMD);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TACTICORDERTypeSupport, DMSG_HMI_TACTICORDER);

DDS_DATAWRITER_CPP(DMSG_HMI_TACTICORDERDataWriter, DMSG_HMI_TACTICORDER);
DDS_DATAREADER_CPP(DMSG_HMI_TACTICORDERDataReader, DMSG_HMI_TACTICORDERSeq, DMSG_HMI_TACTICORDER);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TACTICORDERTypeSupport, DMSG_HMI_TACTICORDER);
DDS_DATAWRITER_C(DMSG_HMI_TACTICORDERDataWriter, DMSG_HMI_TACTICORDER);
DDS_DATAREADER_C(DMSG_HMI_TACTICORDERDataReader, DMSG_HMI_TACTICORDERSeq, DMSG_HMI_TACTICORDER);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_DCOYLAUNCHMODETypeSupport, DMSG_HMI_DCOYLAUNCHMODE);

DDS_DATAWRITER_CPP(DMSG_HMI_DCOYLAUNCHMODEDataWriter, DMSG_HMI_DCOYLAUNCHMODE);
DDS_DATAREADER_CPP(DMSG_HMI_DCOYLAUNCHMODEDataReader, DMSG_HMI_DCOYLAUNCHMODESeq, DMSG_HMI_DCOYLAUNCHMODE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_DCOYLAUNCHMODETypeSupport, DMSG_HMI_DCOYLAUNCHMODE);
DDS_DATAWRITER_C(DMSG_HMI_DCOYLAUNCHMODEDataWriter, DMSG_HMI_DCOYLAUNCHMODE);
DDS_DATAREADER_C(DMSG_HMI_DCOYLAUNCHMODEDataReader, DMSG_HMI_DCOYLAUNCHMODESeq, DMSG_HMI_DCOYLAUNCHMODE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_DCOYTUBESETTypeSupport, DMSG_HMI_DCOYTUBESET);

DDS_DATAWRITER_CPP(DMSG_HMI_DCOYTUBESETDataWriter, DMSG_HMI_DCOYTUBESET);
DDS_DATAREADER_CPP(DMSG_HMI_DCOYTUBESETDataReader, DMSG_HMI_DCOYTUBESETSeq, DMSG_HMI_DCOYTUBESET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_DCOYTUBESETTypeSupport, DMSG_HMI_DCOYTUBESET);
DDS_DATAWRITER_C(DMSG_HMI_DCOYTUBESETDataWriter, DMSG_HMI_DCOYTUBESET);
DDS_DATAREADER_C(DMSG_HMI_DCOYTUBESETDataReader, DMSG_HMI_DCOYTUBESETSeq, DMSG_HMI_DCOYTUBESET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_MISSILECTRLTypeSupport, DMSG_HMI_MISSILECTRL);

DDS_DATAWRITER_CPP(DMSG_HMI_MISSILECTRLDataWriter, DMSG_HMI_MISSILECTRL);
DDS_DATAREADER_CPP(DMSG_HMI_MISSILECTRLDataReader, DMSG_HMI_MISSILECTRLSeq, DMSG_HMI_MISSILECTRL);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_MISSILECTRLTypeSupport, DMSG_HMI_MISSILECTRL);
DDS_DATAWRITER_C(DMSG_HMI_MISSILECTRLDataWriter, DMSG_HMI_MISSILECTRL);
DDS_DATAREADER_C(DMSG_HMI_MISSILECTRLDataReader, DMSG_HMI_MISSILECTRLSeq, DMSG_HMI_MISSILECTRL);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_MISSILEENGAGEPLANTypeSupport, DMSG_HMI_MISSILEENGAGEPLAN);

DDS_DATAWRITER_CPP(DMSG_HMI_MISSILEENGAGEPLANDataWriter, DMSG_HMI_MISSILEENGAGEPLAN);
DDS_DATAREADER_CPP(DMSG_HMI_MISSILEENGAGEPLANDataReader, DMSG_HMI_MISSILEENGAGEPLANSeq, DMSG_HMI_MISSILEENGAGEPLAN);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_MISSILEENGAGEPLANTypeSupport, DMSG_HMI_MISSILEENGAGEPLAN);
DDS_DATAWRITER_C(DMSG_HMI_MISSILEENGAGEPLANDataWriter, DMSG_HMI_MISSILEENGAGEPLAN);
DDS_DATAREADER_C(DMSG_HMI_MISSILEENGAGEPLANDataReader, DMSG_HMI_MISSILEENGAGEPLANSeq, DMSG_HMI_MISSILEENGAGEPLAN);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TORPEDOENGAGEPLANTypeSupport, DMSG_HMI_TORPEDOENGAGEPLAN);

DDS_DATAWRITER_CPP(DMSG_HMI_TORPEDOENGAGEPLANDataWriter, DMSG_HMI_TORPEDOENGAGEPLAN);
DDS_DATAREADER_CPP(DMSG_HMI_TORPEDOENGAGEPLANDataReader, DMSG_HMI_TORPEDOENGAGEPLANSeq, DMSG_HMI_TORPEDOENGAGEPLAN);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TORPEDOENGAGEPLANTypeSupport, DMSG_HMI_TORPEDOENGAGEPLAN);
DDS_DATAWRITER_C(DMSG_HMI_TORPEDOENGAGEPLANDataWriter, DMSG_HMI_TORPEDOENGAGEPLAN);
DDS_DATAREADER_C(DMSG_HMI_TORPEDOENGAGEPLANDataReader, DMSG_HMI_TORPEDOENGAGEPLANSeq, DMSG_HMI_TORPEDOENGAGEPLAN);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_RESERVEDENGAGEPLANTypeSupport, DMSG_HMI_RESERVEDENGAGEPLAN);

DDS_DATAWRITER_CPP(DMSG_HMI_RESERVEDENGAGEPLANDataWriter, DMSG_HMI_RESERVEDENGAGEPLAN);
DDS_DATAREADER_CPP(DMSG_HMI_RESERVEDENGAGEPLANDataReader, DMSG_HMI_RESERVEDENGAGEPLANSeq, DMSG_HMI_RESERVEDENGAGEPLAN);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_RESERVEDENGAGEPLANTypeSupport, DMSG_HMI_RESERVEDENGAGEPLAN);
DDS_DATAWRITER_C(DMSG_HMI_RESERVEDENGAGEPLANDataWriter, DMSG_HMI_RESERVEDENGAGEPLAN);
DDS_DATAREADER_C(DMSG_HMI_RESERVEDENGAGEPLANDataReader, DMSG_HMI_RESERVEDENGAGEPLANSeq, DMSG_HMI_RESERVEDENGAGEPLAN);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TORPCTRLTypeSupport, DMSG_HMI_TORPCTRL);

DDS_DATAWRITER_CPP(DMSG_HMI_TORPCTRLDataWriter, DMSG_HMI_TORPCTRL);
DDS_DATAREADER_CPP(DMSG_HMI_TORPCTRLDataReader, DMSG_HMI_TORPCTRLSeq, DMSG_HMI_TORPCTRL);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TORPCTRLTypeSupport, DMSG_HMI_TORPCTRL);
DDS_DATAWRITER_C(DMSG_HMI_TORPCTRLDataWriter, DMSG_HMI_TORPCTRL);
DDS_DATAREADER_C(DMSG_HMI_TORPCTRLDataReader, DMSG_HMI_TORPCTRLSeq, DMSG_HMI_TORPCTRL);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_SHOOTMODIFYTypeSupport, DMSG_HMI_SHOOTMODIFY);

DDS_DATAWRITER_CPP(DMSG_HMI_SHOOTMODIFYDataWriter, DMSG_HMI_SHOOTMODIFY);
DDS_DATAREADER_CPP(DMSG_HMI_SHOOTMODIFYDataReader, DMSG_HMI_SHOOTMODIFYSeq, DMSG_HMI_SHOOTMODIFY);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_SHOOTMODIFYTypeSupport, DMSG_HMI_SHOOTMODIFY);
DDS_DATAWRITER_C(DMSG_HMI_SHOOTMODIFYDataWriter, DMSG_HMI_SHOOTMODIFY);
DDS_DATAREADER_C(DMSG_HMI_SHOOTMODIFYDataReader, DMSG_HMI_SHOOTMODIFYSeq, DMSG_HMI_SHOOTMODIFY);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_CORRECTTypeSupport, DMSG_HMI_CORRECT);

DDS_DATAWRITER_CPP(DMSG_HMI_CORRECTDataWriter, DMSG_HMI_CORRECT);
DDS_DATAREADER_CPP(DMSG_HMI_CORRECTDataReader, DMSG_HMI_CORRECTSeq, DMSG_HMI_CORRECT);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_CORRECTTypeSupport, DMSG_HMI_CORRECT);
DDS_DATAWRITER_C(DMSG_HMI_CORRECTDataWriter, DMSG_HMI_CORRECT);
DDS_DATAREADER_C(DMSG_HMI_CORRECTDataReader, DMSG_HMI_CORRECTSeq, DMSG_HMI_CORRECT);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_SENSORWEAPONPOSTypeSupport, DMSG_HMI_SENSORWEAPONPOS);

DDS_DATAWRITER_CPP(DMSG_HMI_SENSORWEAPONPOSDataWriter, DMSG_HMI_SENSORWEAPONPOS);
DDS_DATAREADER_CPP(DMSG_HMI_SENSORWEAPONPOSDataReader, DMSG_HMI_SENSORWEAPONPOSSeq, DMSG_HMI_SENSORWEAPONPOS);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_SENSORWEAPONPOSTypeSupport, DMSG_HMI_SENSORWEAPONPOS);
DDS_DATAWRITER_C(DMSG_HMI_SENSORWEAPONPOSDataWriter, DMSG_HMI_SENSORWEAPONPOS);
DDS_DATAREADER_C(DMSG_HMI_SENSORWEAPONPOSDataReader, DMSG_HMI_SENSORWEAPONPOSSeq, DMSG_HMI_SENSORWEAPONPOS);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_BLINDNESSFIRETypeSupport, DMSG_HMI_BLINDNESSFIRE);

DDS_DATAWRITER_CPP(DMSG_HMI_BLINDNESSFIREDataWriter, DMSG_HMI_BLINDNESSFIRE);
DDS_DATAREADER_CPP(DMSG_HMI_BLINDNESSFIREDataReader, DMSG_HMI_BLINDNESSFIRESeq, DMSG_HMI_BLINDNESSFIRE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_BLINDNESSFIRETypeSupport, DMSG_HMI_BLINDNESSFIRE);
DDS_DATAWRITER_C(DMSG_HMI_BLINDNESSFIREDataWriter, DMSG_HMI_BLINDNESSFIRE);
DDS_DATAREADER_C(DMSG_HMI_BLINDNESSFIREDataReader, DMSG_HMI_BLINDNESSFIRESeq, DMSG_HMI_BLINDNESSFIRE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_DIRECTFIRETypeSupport, DMSG_HMI_DIRECTFIRE);

DDS_DATAWRITER_CPP(DMSG_HMI_DIRECTFIREDataWriter, DMSG_HMI_DIRECTFIRE);
DDS_DATAREADER_CPP(DMSG_HMI_DIRECTFIREDataReader, DMSG_HMI_DIRECTFIRESeq, DMSG_HMI_DIRECTFIRE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_DIRECTFIRETypeSupport, DMSG_HMI_DIRECTFIRE);
DDS_DATAWRITER_C(DMSG_HMI_DIRECTFIREDataWriter, DMSG_HMI_DIRECTFIRE);
DDS_DATAREADER_C(DMSG_HMI_DIRECTFIREDataReader, DMSG_HMI_DIRECTFIRESeq, DMSG_HMI_DIRECTFIRE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TORPMANUALWAYPOINTTypeSupport, DMSG_HMI_TORPMANUALWAYPOINT);

DDS_DATAWRITER_CPP(DMSG_HMI_TORPMANUALWAYPOINTDataWriter, DMSG_HMI_TORPMANUALWAYPOINT);
DDS_DATAREADER_CPP(DMSG_HMI_TORPMANUALWAYPOINTDataReader, DMSG_HMI_TORPMANUALWAYPOINTSeq, DMSG_HMI_TORPMANUALWAYPOINT);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TORPMANUALWAYPOINTTypeSupport, DMSG_HMI_TORPMANUALWAYPOINT);
DDS_DATAWRITER_C(DMSG_HMI_TORPMANUALWAYPOINTDataWriter, DMSG_HMI_TORPMANUALWAYPOINT);
DDS_DATAREADER_C(DMSG_HMI_TORPMANUALWAYPOINTDataReader, DMSG_HMI_TORPMANUALWAYPOINTSeq, DMSG_HMI_TORPMANUALWAYPOINT);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TORPBREAKENGAGETypeSupport, DMSG_HMI_TORPBREAKENGAGE);

DDS_DATAWRITER_CPP(DMSG_HMI_TORPBREAKENGAGEDataWriter, DMSG_HMI_TORPBREAKENGAGE);
DDS_DATAREADER_CPP(DMSG_HMI_TORPBREAKENGAGEDataReader, DMSG_HMI_TORPBREAKENGAGESeq, DMSG_HMI_TORPBREAKENGAGE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TORPBREAKENGAGETypeSupport, DMSG_HMI_TORPBREAKENGAGE);
DDS_DATAWRITER_C(DMSG_HMI_TORPBREAKENGAGEDataWriter, DMSG_HMI_TORPBREAKENGAGE);
DDS_DATAREADER_C(DMSG_HMI_TORPBREAKENGAGEDataReader, DMSG_HMI_TORPBREAKENGAGESeq, DMSG_HMI_TORPBREAKENGAGE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_RESERVEDCOPYTypeSupport, DMSG_HMI_RESERVEDCOPY);

DDS_DATAWRITER_CPP(DMSG_HMI_RESERVEDCOPYDataWriter, DMSG_HMI_RESERVEDCOPY);
DDS_DATAREADER_CPP(DMSG_HMI_RESERVEDCOPYDataReader, DMSG_HMI_RESERVEDCOPYSeq, DMSG_HMI_RESERVEDCOPY);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_RESERVEDCOPYTypeSupport, DMSG_HMI_RESERVEDCOPY);
DDS_DATAWRITER_C(DMSG_HMI_RESERVEDCOPYDataWriter, DMSG_HMI_RESERVEDCOPY);
DDS_DATAREADER_C(DMSG_HMI_RESERVEDCOPYDataReader, DMSG_HMI_RESERVEDCOPYSeq, DMSG_HMI_RESERVEDCOPY);

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

DDS_TYPESUPPORT_CPP(DMSG_TFC_FIRINGDATATypeSupport, DMSG_TFC_FIRINGDATA);

DDS_DATAWRITER_CPP(DMSG_TFC_FIRINGDATADataWriter, DMSG_TFC_FIRINGDATA);
DDS_DATAREADER_CPP(DMSG_TFC_FIRINGDATADataReader, DMSG_TFC_FIRINGDATASeq, DMSG_TFC_FIRINGDATA);


#else

DDS_TYPESUPPORT_C(DMSG_TFC_FIRINGDATATypeSupport, DMSG_TFC_FIRINGDATA);
DDS_DATAWRITER_C(DMSG_TFC_FIRINGDATADataWriter, DMSG_TFC_FIRINGDATA);
DDS_DATAREADER_C(DMSG_TFC_FIRINGDATADataReader, DMSG_TFC_FIRINGDATASeq, DMSG_TFC_FIRINGDATA);

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

DDS_TYPESUPPORT_CPP(DMSG_TFC_TORPSTATETypeSupport, DMSG_TFC_TORPSTATE);

DDS_DATAWRITER_CPP(DMSG_TFC_TORPSTATEDataWriter, DMSG_TFC_TORPSTATE);
DDS_DATAREADER_CPP(DMSG_TFC_TORPSTATEDataReader, DMSG_TFC_TORPSTATESeq, DMSG_TFC_TORPSTATE);


#else

DDS_TYPESUPPORT_C(DMSG_TFC_TORPSTATETypeSupport, DMSG_TFC_TORPSTATE);
DDS_DATAWRITER_C(DMSG_TFC_TORPSTATEDataWriter, DMSG_TFC_TORPSTATE);
DDS_DATAREADER_C(DMSG_TFC_TORPSTATEDataReader, DMSG_TFC_TORPSTATESeq, DMSG_TFC_TORPSTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_TFC_TORPMANEUVERTypeSupport, DMSG_TFC_TORPMANEUVER);

DDS_DATAWRITER_CPP(DMSG_TFC_TORPMANEUVERDataWriter, DMSG_TFC_TORPMANEUVER);
DDS_DATAREADER_CPP(DMSG_TFC_TORPMANEUVERDataReader, DMSG_TFC_TORPMANEUVERSeq, DMSG_TFC_TORPMANEUVER);


#else

DDS_TYPESUPPORT_C(DMSG_TFC_TORPMANEUVERTypeSupport, DMSG_TFC_TORPMANEUVER);
DDS_DATAWRITER_C(DMSG_TFC_TORPMANEUVERDataWriter, DMSG_TFC_TORPMANEUVER);
DDS_DATAREADER_C(DMSG_TFC_TORPMANEUVERDataReader, DMSG_TFC_TORPMANEUVERSeq, DMSG_TFC_TORPMANEUVER);

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

DDS_TYPESUPPORT_CPP(DMSG_TFC_CHECKRESULTTypeSupport, DMSG_TFC_CHECKRESULT);

DDS_DATAWRITER_CPP(DMSG_TFC_CHECKRESULTDataWriter, DMSG_TFC_CHECKRESULT);
DDS_DATAREADER_CPP(DMSG_TFC_CHECKRESULTDataReader, DMSG_TFC_CHECKRESULTSeq, DMSG_TFC_CHECKRESULT);


#else

DDS_TYPESUPPORT_C(DMSG_TFC_CHECKRESULTTypeSupport, DMSG_TFC_CHECKRESULT);
DDS_DATAWRITER_C(DMSG_TFC_CHECKRESULTDataWriter, DMSG_TFC_CHECKRESULT);
DDS_DATAREADER_C(DMSG_TFC_CHECKRESULTDataReader, DMSG_TFC_CHECKRESULTSeq, DMSG_TFC_CHECKRESULT);

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

DDS_TYPESUPPORT_CPP(DMSG_TFC_INTERLOCKTypeSupport, DMSG_TFC_INTERLOCK);

DDS_DATAWRITER_CPP(DMSG_TFC_INTERLOCKDataWriter, DMSG_TFC_INTERLOCK);
DDS_DATAREADER_CPP(DMSG_TFC_INTERLOCKDataReader, DMSG_TFC_INTERLOCKSeq, DMSG_TFC_INTERLOCK);


#else

DDS_TYPESUPPORT_C(DMSG_TFC_INTERLOCKTypeSupport, DMSG_TFC_INTERLOCK);
DDS_DATAWRITER_C(DMSG_TFC_INTERLOCKDataWriter, DMSG_TFC_INTERLOCK);
DDS_DATAREADER_C(DMSG_TFC_INTERLOCKDataReader, DMSG_TFC_INTERLOCKSeq, DMSG_TFC_INTERLOCK);

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

DDS_TYPESUPPORT_CPP(DMSG_TFC_TORPSONARTypeSupport, DMSG_TFC_TORPSONAR);

DDS_DATAWRITER_CPP(DMSG_TFC_TORPSONARDataWriter, DMSG_TFC_TORPSONAR);
DDS_DATAREADER_CPP(DMSG_TFC_TORPSONARDataReader, DMSG_TFC_TORPSONARSeq, DMSG_TFC_TORPSONAR);


#else

DDS_TYPESUPPORT_C(DMSG_TFC_TORPSONARTypeSupport, DMSG_TFC_TORPSONAR);
DDS_DATAWRITER_C(DMSG_TFC_TORPSONARDataWriter, DMSG_TFC_TORPSONAR);
DDS_DATAREADER_C(DMSG_TFC_TORPSONARDataReader, DMSG_TFC_TORPSONARSeq, DMSG_TFC_TORPSONAR);

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

DDS_TYPESUPPORT_CPP(DMSG_TFC_TORPTARGETTypeSupport, DMSG_TFC_TORPTARGET);

DDS_DATAWRITER_CPP(DMSG_TFC_TORPTARGETDataWriter, DMSG_TFC_TORPTARGET);
DDS_DATAREADER_CPP(DMSG_TFC_TORPTARGETDataReader, DMSG_TFC_TORPTARGETSeq, DMSG_TFC_TORPTARGET);


#else

DDS_TYPESUPPORT_C(DMSG_TFC_TORPTARGETTypeSupport, DMSG_TFC_TORPTARGET);
DDS_DATAWRITER_C(DMSG_TFC_TORPTARGETDataWriter, DMSG_TFC_TORPTARGET);
DDS_DATAREADER_C(DMSG_TFC_TORPTARGETDataReader, DMSG_TFC_TORPTARGETSeq, DMSG_TFC_TORPTARGET);

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

DDS_TYPESUPPORT_CPP(DMSG_TFC_TORPEDOAVAILABILITYTypeSupport, DMSG_TFC_TORPEDOAVAILABILITY);

DDS_DATAWRITER_CPP(DMSG_TFC_TORPEDOAVAILABILITYDataWriter, DMSG_TFC_TORPEDOAVAILABILITY);
DDS_DATAREADER_CPP(DMSG_TFC_TORPEDOAVAILABILITYDataReader, DMSG_TFC_TORPEDOAVAILABILITYSeq, DMSG_TFC_TORPEDOAVAILABILITY);


#else

DDS_TYPESUPPORT_C(DMSG_TFC_TORPEDOAVAILABILITYTypeSupport, DMSG_TFC_TORPEDOAVAILABILITY);
DDS_DATAWRITER_C(DMSG_TFC_TORPEDOAVAILABILITYDataWriter, DMSG_TFC_TORPEDOAVAILABILITY);
DDS_DATAREADER_C(DMSG_TFC_TORPEDOAVAILABILITYDataReader, DMSG_TFC_TORPEDOAVAILABILITYSeq, DMSG_TFC_TORPEDOAVAILABILITY);

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

DDS_TYPESUPPORT_CPP(DMSG_TFC_ENGAGESTATETypeSupport, DMSG_TFC_ENGAGESTATE);

DDS_DATAWRITER_CPP(DMSG_TFC_ENGAGESTATEDataWriter, DMSG_TFC_ENGAGESTATE);
DDS_DATAREADER_CPP(DMSG_TFC_ENGAGESTATEDataReader, DMSG_TFC_ENGAGESTATESeq, DMSG_TFC_ENGAGESTATE);


#else

DDS_TYPESUPPORT_C(DMSG_TFC_ENGAGESTATETypeSupport, DMSG_TFC_ENGAGESTATE);
DDS_DATAWRITER_C(DMSG_TFC_ENGAGESTATEDataWriter, DMSG_TFC_ENGAGESTATE);
DDS_DATAREADER_C(DMSG_TFC_ENGAGESTATEDataReader, DMSG_TFC_ENGAGESTATESeq, DMSG_TFC_ENGAGESTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_TFC_SWSTATETypeSupport, DMSG_TFC_SWSTATE);

DDS_DATAWRITER_CPP(DMSG_TFC_SWSTATEDataWriter, DMSG_TFC_SWSTATE);
DDS_DATAREADER_CPP(DMSG_TFC_SWSTATEDataReader, DMSG_TFC_SWSTATESeq, DMSG_TFC_SWSTATE);


#else

DDS_TYPESUPPORT_C(DMSG_TFC_SWSTATETypeSupport, DMSG_TFC_SWSTATE);
DDS_DATAWRITER_C(DMSG_TFC_SWSTATEDataWriter, DMSG_TFC_SWSTATE);
DDS_DATAREADER_C(DMSG_TFC_SWSTATEDataReader, DMSG_TFC_SWSTATESeq, DMSG_TFC_SWSTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_TFC_HLTCTRLTypeSupport, DMSG_TFC_HLTCTRL);

DDS_DATAWRITER_CPP(DMSG_TFC_HLTCTRLDataWriter, DMSG_TFC_HLTCTRL);
DDS_DATAREADER_CPP(DMSG_TFC_HLTCTRLDataReader, DMSG_TFC_HLTCTRLSeq, DMSG_TFC_HLTCTRL);


#else

DDS_TYPESUPPORT_C(DMSG_TFC_HLTCTRLTypeSupport, DMSG_TFC_HLTCTRL);
DDS_DATAWRITER_C(DMSG_TFC_HLTCTRLDataWriter, DMSG_TFC_HLTCTRL);
DDS_DATAREADER_C(DMSG_TFC_HLTCTRLDataReader, DMSG_TFC_HLTCTRLSeq, DMSG_TFC_HLTCTRL);

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

DDS_TYPESUPPORT_CPP(DMSG_MFC_SUMSTATETypeSupport, DMSG_MFC_SUMSTATE);

DDS_DATAWRITER_CPP(DMSG_MFC_SUMSTATEDataWriter, DMSG_MFC_SUMSTATE);
DDS_DATAREADER_CPP(DMSG_MFC_SUMSTATEDataReader, DMSG_MFC_SUMSTATESeq, DMSG_MFC_SUMSTATE);


#else

DDS_TYPESUPPORT_C(DMSG_MFC_SUMSTATETypeSupport, DMSG_MFC_SUMSTATE);
DDS_DATAWRITER_C(DMSG_MFC_SUMSTATEDataWriter, DMSG_MFC_SUMSTATE);
DDS_DATAREADER_C(DMSG_MFC_SUMSTATEDataReader, DMSG_MFC_SUMSTATESeq, DMSG_MFC_SUMSTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_MFC_FIRINGDATATypeSupport, DMSG_MFC_FIRINGDATA);

DDS_DATAWRITER_CPP(DMSG_MFC_FIRINGDATADataWriter, DMSG_MFC_FIRINGDATA);
DDS_DATAREADER_CPP(DMSG_MFC_FIRINGDATADataReader, DMSG_MFC_FIRINGDATASeq, DMSG_MFC_FIRINGDATA);


#else

DDS_TYPESUPPORT_C(DMSG_MFC_FIRINGDATATypeSupport, DMSG_MFC_FIRINGDATA);
DDS_DATAWRITER_C(DMSG_MFC_FIRINGDATADataWriter, DMSG_MFC_FIRINGDATA);
DDS_DATAREADER_C(DMSG_MFC_FIRINGDATADataReader, DMSG_MFC_FIRINGDATASeq, DMSG_MFC_FIRINGDATA);

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

DDS_TYPESUPPORT_CPP(DMSG_MFC_INTERLOCKTypeSupport, DMSG_MFC_INTERLOCK);

DDS_DATAWRITER_CPP(DMSG_MFC_INTERLOCKDataWriter, DMSG_MFC_INTERLOCK);
DDS_DATAREADER_CPP(DMSG_MFC_INTERLOCKDataReader, DMSG_MFC_INTERLOCKSeq, DMSG_MFC_INTERLOCK);


#else

DDS_TYPESUPPORT_C(DMSG_MFC_INTERLOCKTypeSupport, DMSG_MFC_INTERLOCK);
DDS_DATAWRITER_C(DMSG_MFC_INTERLOCKDataWriter, DMSG_MFC_INTERLOCK);
DDS_DATAREADER_C(DMSG_MFC_INTERLOCKDataReader, DMSG_MFC_INTERLOCKSeq, DMSG_MFC_INTERLOCK);

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

DDS_TYPESUPPORT_CPP(DMSG_MFC_SAFETYSWITCHSTATETypeSupport, DMSG_MFC_SAFETYSWITCHSTATE);

DDS_DATAWRITER_CPP(DMSG_MFC_SAFETYSWITCHSTATEDataWriter, DMSG_MFC_SAFETYSWITCHSTATE);
DDS_DATAREADER_CPP(DMSG_MFC_SAFETYSWITCHSTATEDataReader, DMSG_MFC_SAFETYSWITCHSTATESeq, DMSG_MFC_SAFETYSWITCHSTATE);


#else

DDS_TYPESUPPORT_C(DMSG_MFC_SAFETYSWITCHSTATETypeSupport, DMSG_MFC_SAFETYSWITCHSTATE);
DDS_DATAWRITER_C(DMSG_MFC_SAFETYSWITCHSTATEDataWriter, DMSG_MFC_SAFETYSWITCHSTATE);
DDS_DATAREADER_C(DMSG_MFC_SAFETYSWITCHSTATEDataReader, DMSG_MFC_SAFETYSWITCHSTATESeq, DMSG_MFC_SAFETYSWITCHSTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_MFC_SUMTESTRESULTTypeSupport, DMSG_MFC_SUMTESTRESULT);

DDS_DATAWRITER_CPP(DMSG_MFC_SUMTESTRESULTDataWriter, DMSG_MFC_SUMTESTRESULT);
DDS_DATAREADER_CPP(DMSG_MFC_SUMTESTRESULTDataReader, DMSG_MFC_SUMTESTRESULTSeq, DMSG_MFC_SUMTESTRESULT);


#else

DDS_TYPESUPPORT_C(DMSG_MFC_SUMTESTRESULTTypeSupport, DMSG_MFC_SUMTESTRESULT);
DDS_DATAWRITER_C(DMSG_MFC_SUMTESTRESULTDataWriter, DMSG_MFC_SUMTESTRESULT);
DDS_DATAREADER_C(DMSG_MFC_SUMTESTRESULTDataReader, DMSG_MFC_SUMTESTRESULTSeq, DMSG_MFC_SUMTESTRESULT);

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

DDS_TYPESUPPORT_CPP(DMSG_MFC_ENGAGESTATETypeSupport, DMSG_MFC_ENGAGESTATE);

DDS_DATAWRITER_CPP(DMSG_MFC_ENGAGESTATEDataWriter, DMSG_MFC_ENGAGESTATE);
DDS_DATAREADER_CPP(DMSG_MFC_ENGAGESTATEDataReader, DMSG_MFC_ENGAGESTATESeq, DMSG_MFC_ENGAGESTATE);


#else

DDS_TYPESUPPORT_C(DMSG_MFC_ENGAGESTATETypeSupport, DMSG_MFC_ENGAGESTATE);
DDS_DATAWRITER_C(DMSG_MFC_ENGAGESTATEDataWriter, DMSG_MFC_ENGAGESTATE);
DDS_DATAREADER_C(DMSG_MFC_ENGAGESTATEDataReader, DMSG_MFC_ENGAGESTATESeq, DMSG_MFC_ENGAGESTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_MFC_MISSILEAVAILABILITYTypeSupport, DMSG_MFC_MISSILEAVAILABILITY);

DDS_DATAWRITER_CPP(DMSG_MFC_MISSILEAVAILABILITYDataWriter, DMSG_MFC_MISSILEAVAILABILITY);
DDS_DATAREADER_CPP(DMSG_MFC_MISSILEAVAILABILITYDataReader, DMSG_MFC_MISSILEAVAILABILITYSeq, DMSG_MFC_MISSILEAVAILABILITY);


#else

DDS_TYPESUPPORT_C(DMSG_MFC_MISSILEAVAILABILITYTypeSupport, DMSG_MFC_MISSILEAVAILABILITY);
DDS_DATAWRITER_C(DMSG_MFC_MISSILEAVAILABILITYDataWriter, DMSG_MFC_MISSILEAVAILABILITY);
DDS_DATAREADER_C(DMSG_MFC_MISSILEAVAILABILITYDataReader, DMSG_MFC_MISSILEAVAILABILITYSeq, DMSG_MFC_MISSILEAVAILABILITY);

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

DDS_TYPESUPPORT_CPP(DMSG_MFC_SWSTATETypeSupport, DMSG_MFC_SWSTATE);

DDS_DATAWRITER_CPP(DMSG_MFC_SWSTATEDataWriter, DMSG_MFC_SWSTATE);
DDS_DATAREADER_CPP(DMSG_MFC_SWSTATEDataReader, DMSG_MFC_SWSTATESeq, DMSG_MFC_SWSTATE);


#else

DDS_TYPESUPPORT_C(DMSG_MFC_SWSTATETypeSupport, DMSG_MFC_SWSTATE);
DDS_DATAWRITER_C(DMSG_MFC_SWSTATEDataWriter, DMSG_MFC_SWSTATE);
DDS_DATAREADER_C(DMSG_MFC_SWSTATEDataReader, DMSG_MFC_SWSTATESeq, DMSG_MFC_SWSTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_MFC_COUNTDOWNSTATETypeSupport, DMSG_MFC_COUNTDOWNSTATE);

DDS_DATAWRITER_CPP(DMSG_MFC_COUNTDOWNSTATEDataWriter, DMSG_MFC_COUNTDOWNSTATE);
DDS_DATAREADER_CPP(DMSG_MFC_COUNTDOWNSTATEDataReader, DMSG_MFC_COUNTDOWNSTATESeq, DMSG_MFC_COUNTDOWNSTATE);


#else

DDS_TYPESUPPORT_C(DMSG_MFC_COUNTDOWNSTATETypeSupport, DMSG_MFC_COUNTDOWNSTATE);
DDS_DATAWRITER_C(DMSG_MFC_COUNTDOWNSTATEDataWriter, DMSG_MFC_COUNTDOWNSTATE);
DDS_DATAREADER_C(DMSG_MFC_COUNTDOWNSTATEDataReader, DMSG_MFC_COUNTDOWNSTATESeq, DMSG_MFC_COUNTDOWNSTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_DFC_MANOEUVRETypeSupport, DMSG_DFC_MANOEUVRE);

DDS_DATAWRITER_CPP(DMSG_DFC_MANOEUVREDataWriter, DMSG_DFC_MANOEUVRE);
DDS_DATAREADER_CPP(DMSG_DFC_MANOEUVREDataReader, DMSG_DFC_MANOEUVRESeq, DMSG_DFC_MANOEUVRE);


#else

DDS_TYPESUPPORT_C(DMSG_DFC_MANOEUVRETypeSupport, DMSG_DFC_MANOEUVRE);
DDS_DATAWRITER_C(DMSG_DFC_MANOEUVREDataWriter, DMSG_DFC_MANOEUVRE);
DDS_DATAREADER_C(DMSG_DFC_MANOEUVREDataReader, DMSG_DFC_MANOEUVRESeq, DMSG_DFC_MANOEUVRE);

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

DDS_TYPESUPPORT_CPP(DMSG_DFC_TACTICINFOTypeSupport, DMSG_DFC_TACTICINFO);

DDS_DATAWRITER_CPP(DMSG_DFC_TACTICINFODataWriter, DMSG_DFC_TACTICINFO);
DDS_DATAREADER_CPP(DMSG_DFC_TACTICINFODataReader, DMSG_DFC_TACTICINFOSeq, DMSG_DFC_TACTICINFO);


#else

DDS_TYPESUPPORT_C(DMSG_DFC_TACTICINFOTypeSupport, DMSG_DFC_TACTICINFO);
DDS_DATAWRITER_C(DMSG_DFC_TACTICINFODataWriter, DMSG_DFC_TACTICINFO);
DDS_DATAREADER_C(DMSG_DFC_TACTICINFODataReader, DMSG_DFC_TACTICINFOSeq, DMSG_DFC_TACTICINFO);

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

DDS_TYPESUPPORT_CPP(DMSG_DFC_LOADINGTypeSupport, DMSG_DFC_LOADING);

DDS_DATAWRITER_CPP(DMSG_DFC_LOADINGDataWriter, DMSG_DFC_LOADING);
DDS_DATAREADER_CPP(DMSG_DFC_LOADINGDataReader, DMSG_DFC_LOADINGSeq, DMSG_DFC_LOADING);


#else

DDS_TYPESUPPORT_C(DMSG_DFC_LOADINGTypeSupport, DMSG_DFC_LOADING);
DDS_DATAWRITER_C(DMSG_DFC_LOADINGDataWriter, DMSG_DFC_LOADING);
DDS_DATAREADER_C(DMSG_DFC_LOADINGDataReader, DMSG_DFC_LOADINGSeq, DMSG_DFC_LOADING);

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

DDS_TYPESUPPORT_CPP(DMSG_DFC_PREDICTPOSTypeSupport, DMSG_DFC_PREDICTPOS);

DDS_DATAWRITER_CPP(DMSG_DFC_PREDICTPOSDataWriter, DMSG_DFC_PREDICTPOS);
DDS_DATAREADER_CPP(DMSG_DFC_PREDICTPOSDataReader, DMSG_DFC_PREDICTPOSSeq, DMSG_DFC_PREDICTPOS);


#else

DDS_TYPESUPPORT_C(DMSG_DFC_PREDICTPOSTypeSupport, DMSG_DFC_PREDICTPOS);
DDS_DATAWRITER_C(DMSG_DFC_PREDICTPOSDataWriter, DMSG_DFC_PREDICTPOS);
DDS_DATAREADER_C(DMSG_DFC_PREDICTPOSDataReader, DMSG_DFC_PREDICTPOSSeq, DMSG_DFC_PREDICTPOS);

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

DDS_TYPESUPPORT_CPP(DMSG_DFC_PERFORMTypeSupport, DMSG_DFC_PERFORM);

DDS_DATAWRITER_CPP(DMSG_DFC_PERFORMDataWriter, DMSG_DFC_PERFORM);
DDS_DATAREADER_CPP(DMSG_DFC_PERFORMDataReader, DMSG_DFC_PERFORMSeq, DMSG_DFC_PERFORM);


#else

DDS_TYPESUPPORT_C(DMSG_DFC_PERFORMTypeSupport, DMSG_DFC_PERFORM);
DDS_DATAWRITER_C(DMSG_DFC_PERFORMDataWriter, DMSG_DFC_PERFORM);
DDS_DATAREADER_C(DMSG_DFC_PERFORMDataReader, DMSG_DFC_PERFORMSeq, DMSG_DFC_PERFORM);

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

DDS_TYPESUPPORT_CPP(DMSG_DFC_EXPECTROUTETypeSupport, DMSG_DFC_EXPECTROUTE);

DDS_DATAWRITER_CPP(DMSG_DFC_EXPECTROUTEDataWriter, DMSG_DFC_EXPECTROUTE);
DDS_DATAREADER_CPP(DMSG_DFC_EXPECTROUTEDataReader, DMSG_DFC_EXPECTROUTESeq, DMSG_DFC_EXPECTROUTE);


#else

DDS_TYPESUPPORT_C(DMSG_DFC_EXPECTROUTETypeSupport, DMSG_DFC_EXPECTROUTE);
DDS_DATAWRITER_C(DMSG_DFC_EXPECTROUTEDataWriter, DMSG_DFC_EXPECTROUTE);
DDS_DATAREADER_C(DMSG_DFC_EXPECTROUTEDataReader, DMSG_DFC_EXPECTROUTESeq, DMSG_DFC_EXPECTROUTE);

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

DDS_TYPESUPPORT_CPP(DMSG_DFC_SUBDCOYFIREPLANTypeSupport, DMSG_DFC_SUBDCOYFIREPLAN);

DDS_DATAWRITER_CPP(DMSG_DFC_SUBDCOYFIREPLANDataWriter, DMSG_DFC_SUBDCOYFIREPLAN);
DDS_DATAREADER_CPP(DMSG_DFC_SUBDCOYFIREPLANDataReader, DMSG_DFC_SUBDCOYFIREPLANSeq, DMSG_DFC_SUBDCOYFIREPLAN);


#else

DDS_TYPESUPPORT_C(DMSG_DFC_SUBDCOYFIREPLANTypeSupport, DMSG_DFC_SUBDCOYFIREPLAN);
DDS_DATAWRITER_C(DMSG_DFC_SUBDCOYFIREPLANDataWriter, DMSG_DFC_SUBDCOYFIREPLAN);
DDS_DATAREADER_C(DMSG_DFC_SUBDCOYFIREPLANDataReader, DMSG_DFC_SUBDCOYFIREPLANSeq, DMSG_DFC_SUBDCOYFIREPLAN);

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

DDS_TYPESUPPORT_CPP(DMSG_DFC_ENGAGESTATETypeSupport, DMSG_DFC_ENGAGESTATE);

DDS_DATAWRITER_CPP(DMSG_DFC_ENGAGESTATEDataWriter, DMSG_DFC_ENGAGESTATE);
DDS_DATAREADER_CPP(DMSG_DFC_ENGAGESTATEDataReader, DMSG_DFC_ENGAGESTATESeq, DMSG_DFC_ENGAGESTATE);


#else

DDS_TYPESUPPORT_C(DMSG_DFC_ENGAGESTATETypeSupport, DMSG_DFC_ENGAGESTATE);
DDS_DATAWRITER_C(DMSG_DFC_ENGAGESTATEDataWriter, DMSG_DFC_ENGAGESTATE);
DDS_DATAREADER_C(DMSG_DFC_ENGAGESTATEDataReader, DMSG_DFC_ENGAGESTATESeq, DMSG_DFC_ENGAGESTATE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_SELECTEDSENSORTypeSupport, DMSG_HMI_SELECTEDSENSOR);

DDS_DATAWRITER_CPP(DMSG_HMI_SELECTEDSENSORDataWriter, DMSG_HMI_SELECTEDSENSOR);
DDS_DATAREADER_CPP(DMSG_HMI_SELECTEDSENSORDataReader, DMSG_HMI_SELECTEDSENSORSeq, DMSG_HMI_SELECTEDSENSOR);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_SELECTEDSENSORTypeSupport, DMSG_HMI_SELECTEDSENSOR);
DDS_DATAWRITER_C(DMSG_HMI_SELECTEDSENSORDataWriter, DMSG_HMI_SELECTEDSENSOR);
DDS_DATAREADER_C(DMSG_HMI_SELECTEDSENSORDataReader, DMSG_HMI_SELECTEDSENSORSeq, DMSG_HMI_SELECTEDSENSOR);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_SELECTEDWEAPONTypeSupport, DMSG_HMI_SELECTEDWEAPON);

DDS_DATAWRITER_CPP(DMSG_HMI_SELECTEDWEAPONDataWriter, DMSG_HMI_SELECTEDWEAPON);
DDS_DATAREADER_CPP(DMSG_HMI_SELECTEDWEAPONDataReader, DMSG_HMI_SELECTEDWEAPONSeq, DMSG_HMI_SELECTEDWEAPON);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_SELECTEDWEAPONTypeSupport, DMSG_HMI_SELECTEDWEAPON);
DDS_DATAWRITER_C(DMSG_HMI_SELECTEDWEAPONDataWriter, DMSG_HMI_SELECTEDWEAPON);
DDS_DATAREADER_C(DMSG_HMI_SELECTEDWEAPONDataReader, DMSG_HMI_SELECTEDWEAPONSeq, DMSG_HMI_SELECTEDWEAPON);

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

DDS_TYPESUPPORT_CPP(DMSG_PA_SENSORRANGERESULTTypeSupport, DMSG_PA_SENSORRANGERESULT);

DDS_DATAWRITER_CPP(DMSG_PA_SENSORRANGERESULTDataWriter, DMSG_PA_SENSORRANGERESULT);
DDS_DATAREADER_CPP(DMSG_PA_SENSORRANGERESULTDataReader, DMSG_PA_SENSORRANGERESULTSeq, DMSG_PA_SENSORRANGERESULT);


#else

DDS_TYPESUPPORT_C(DMSG_PA_SENSORRANGERESULTTypeSupport, DMSG_PA_SENSORRANGERESULT);
DDS_DATAWRITER_C(DMSG_PA_SENSORRANGERESULTDataWriter, DMSG_PA_SENSORRANGERESULT);
DDS_DATAREADER_C(DMSG_PA_SENSORRANGERESULTDataReader, DMSG_PA_SENSORRANGERESULTSeq, DMSG_PA_SENSORRANGERESULT);

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

DDS_TYPESUPPORT_CPP(DMSG_PA_WEAPONRANGERESULTTypeSupport, DMSG_PA_WEAPONRANGERESULT);

DDS_DATAWRITER_CPP(DMSG_PA_WEAPONRANGERESULTDataWriter, DMSG_PA_WEAPONRANGERESULT);
DDS_DATAREADER_CPP(DMSG_PA_WEAPONRANGERESULTDataReader, DMSG_PA_WEAPONRANGERESULTSeq, DMSG_PA_WEAPONRANGERESULT);


#else

DDS_TYPESUPPORT_C(DMSG_PA_WEAPONRANGERESULTTypeSupport, DMSG_PA_WEAPONRANGERESULT);
DDS_DATAWRITER_C(DMSG_PA_WEAPONRANGERESULTDataWriter, DMSG_PA_WEAPONRANGERESULT);
DDS_DATAREADER_C(DMSG_PA_WEAPONRANGERESULTDataReader, DMSG_PA_WEAPONRANGERESULTSeq, DMSG_PA_WEAPONRANGERESULT);

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

DDS_TYPESUPPORT_CPP(DMSG_SMS_CONNECTTypeSupport, DMSG_SMS_CONNECT);

DDS_DATAWRITER_CPP(DMSG_SMS_CONNECTDataWriter, DMSG_SMS_CONNECT);
DDS_DATAREADER_CPP(DMSG_SMS_CONNECTDataReader, DMSG_SMS_CONNECTSeq, DMSG_SMS_CONNECT);


#else

DDS_TYPESUPPORT_C(DMSG_SMS_CONNECTTypeSupport, DMSG_SMS_CONNECT);
DDS_DATAWRITER_C(DMSG_SMS_CONNECTDataWriter, DMSG_SMS_CONNECT);
DDS_DATAREADER_C(DMSG_SMS_CONNECTDataReader, DMSG_SMS_CONNECTSeq, DMSG_SMS_CONNECT);

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

DDS_TYPESUPPORT_CPP(DMSG_MMI_CONNECTREPLYTypeSupport, DMSG_MMI_CONNECTREPLY);

DDS_DATAWRITER_CPP(DMSG_MMI_CONNECTREPLYDataWriter, DMSG_MMI_CONNECTREPLY);
DDS_DATAREADER_CPP(DMSG_MMI_CONNECTREPLYDataReader, DMSG_MMI_CONNECTREPLYSeq, DMSG_MMI_CONNECTREPLY);


#else

DDS_TYPESUPPORT_C(DMSG_MMI_CONNECTREPLYTypeSupport, DMSG_MMI_CONNECTREPLY);
DDS_DATAWRITER_C(DMSG_MMI_CONNECTREPLYDataWriter, DMSG_MMI_CONNECTREPLY);
DDS_DATAREADER_C(DMSG_MMI_CONNECTREPLYDataReader, DMSG_MMI_CONNECTREPLYSeq, DMSG_MMI_CONNECTREPLY);

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

DDS_TYPESUPPORT_CPP(DMSG_SMS_INITTypeSupport, DMSG_SMS_INIT);

DDS_DATAWRITER_CPP(DMSG_SMS_INITDataWriter, DMSG_SMS_INIT);
DDS_DATAREADER_CPP(DMSG_SMS_INITDataReader, DMSG_SMS_INITSeq, DMSG_SMS_INIT);


#else

DDS_TYPESUPPORT_C(DMSG_SMS_INITTypeSupport, DMSG_SMS_INIT);
DDS_DATAWRITER_C(DMSG_SMS_INITDataWriter, DMSG_SMS_INIT);
DDS_DATAREADER_C(DMSG_SMS_INITDataReader, DMSG_SMS_INITSeq, DMSG_SMS_INIT);

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

DDS_TYPESUPPORT_CPP(DMSG_SMS_DDSTESTTypeSupport, DMSG_SMS_DDSTEST);

DDS_DATAWRITER_CPP(DMSG_SMS_DDSTESTDataWriter, DMSG_SMS_DDSTEST);
DDS_DATAREADER_CPP(DMSG_SMS_DDSTESTDataReader, DMSG_SMS_DDSTESTSeq, DMSG_SMS_DDSTEST);


#else

DDS_TYPESUPPORT_C(DMSG_SMS_DDSTESTTypeSupport, DMSG_SMS_DDSTEST);
DDS_DATAWRITER_C(DMSG_SMS_DDSTESTDataWriter, DMSG_SMS_DDSTEST);
DDS_DATAREADER_C(DMSG_SMS_DDSTESTDataReader, DMSG_SMS_DDSTESTSeq, DMSG_SMS_DDSTEST);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_SAVECYCLESETTypeSupport, DMSG_HMI_SAVECYCLESET);

DDS_DATAWRITER_CPP(DMSG_HMI_SAVECYCLESETDataWriter, DMSG_HMI_SAVECYCLESET);
DDS_DATAREADER_CPP(DMSG_HMI_SAVECYCLESETDataReader, DMSG_HMI_SAVECYCLESETSeq, DMSG_HMI_SAVECYCLESET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_SAVECYCLESETTypeSupport, DMSG_HMI_SAVECYCLESET);
DDS_DATAWRITER_C(DMSG_HMI_SAVECYCLESETDataWriter, DMSG_HMI_SAVECYCLESET);
DDS_DATAREADER_C(DMSG_HMI_SAVECYCLESETDataReader, DMSG_HMI_SAVECYCLESETSeq, DMSG_HMI_SAVECYCLESET);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif  /* DDS_CMSSupport_1867575076_h */
