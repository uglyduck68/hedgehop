
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_GUNMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef DDS_GUNMMISupport_731994764_h
#define DDS_GUNMMISupport_731994764_h

/* Uses */
#include "DDS_GUNMMI.h"



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

DDS_TYPESUPPORT_CPP(DMSG_GFC_FIREDATATypeSupport, DMSG_GFC_FIREDATA);

DDS_DATAWRITER_CPP(DMSG_GFC_FIREDATADataWriter, DMSG_GFC_FIREDATA);
DDS_DATAREADER_CPP(DMSG_GFC_FIREDATADataReader, DMSG_GFC_FIREDATASeq, DMSG_GFC_FIREDATA);


#else

DDS_TYPESUPPORT_C(DMSG_GFC_FIREDATATypeSupport, DMSG_GFC_FIREDATA);
DDS_DATAWRITER_C(DMSG_GFC_FIREDATADataWriter, DMSG_GFC_FIREDATA);
DDS_DATAREADER_C(DMSG_GFC_FIREDATADataReader, DMSG_GFC_FIREDATASeq, DMSG_GFC_FIREDATA);

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

DDS_TYPESUPPORT_CPP(DMSG_EC_FIRINGCMDTypeSupport, DMSG_EC_FIRINGCMD);

DDS_DATAWRITER_CPP(DMSG_EC_FIRINGCMDDataWriter, DMSG_EC_FIRINGCMD);
DDS_DATAREADER_CPP(DMSG_EC_FIRINGCMDDataReader, DMSG_EC_FIRINGCMDSeq, DMSG_EC_FIRINGCMD);


#else

DDS_TYPESUPPORT_C(DMSG_EC_FIRINGCMDTypeSupport, DMSG_EC_FIRINGCMD);
DDS_DATAWRITER_C(DMSG_EC_FIRINGCMDDataWriter, DMSG_EC_FIRINGCMD);
DDS_DATAREADER_C(DMSG_EC_FIRINGCMDDataReader, DMSG_EC_FIRINGCMDSeq, DMSG_EC_FIRINGCMD);

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

DDS_TYPESUPPORT_CPP(DMSG_GFC_HITEXPECTTypeSupport, DMSG_GFC_HITEXPECT);

DDS_DATAWRITER_CPP(DMSG_GFC_HITEXPECTDataWriter, DMSG_GFC_HITEXPECT);
DDS_DATAREADER_CPP(DMSG_GFC_HITEXPECTDataReader, DMSG_GFC_HITEXPECTSeq, DMSG_GFC_HITEXPECT);


#else

DDS_TYPESUPPORT_C(DMSG_GFC_HITEXPECTTypeSupport, DMSG_GFC_HITEXPECT);
DDS_DATAWRITER_C(DMSG_GFC_HITEXPECTDataWriter, DMSG_GFC_HITEXPECT);
DDS_DATAREADER_C(DMSG_GFC_HITEXPECTDataReader, DMSG_GFC_HITEXPECTSeq, DMSG_GFC_HITEXPECT);

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

DDS_TYPESUPPORT_CPP(DMSG_GUN_STATETypeSupport, DMSG_GUN_STATE);

DDS_DATAWRITER_CPP(DMSG_GUN_STATEDataWriter, DMSG_GUN_STATE);
DDS_DATAREADER_CPP(DMSG_GUN_STATEDataReader, DMSG_GUN_STATESeq, DMSG_GUN_STATE);


#else

DDS_TYPESUPPORT_C(DMSG_GUN_STATETypeSupport, DMSG_GUN_STATE);
DDS_DATAWRITER_C(DMSG_GUN_STATEDataWriter, DMSG_GUN_STATE);
DDS_DATAREADER_C(DMSG_GUN_STATEDataReader, DMSG_GUN_STATESeq, DMSG_GUN_STATE);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif  /* DDS_GUNMMISupport_731994764_h */
