
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_TDSRMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef DDS_TDSRMMISupport_1808377665_h
#define DDS_TDSRMMISupport_1808377665_h

/* Uses */
#include "DDS_TDSRMMI.h"



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

DDS_TYPESUPPORT_CPP(DMSG_TDSR_FIELDSETRESULTTypeSupport, DMSG_TDSR_FIELDSETRESULT);

DDS_DATAWRITER_CPP(DMSG_TDSR_FIELDSETRESULTDataWriter, DMSG_TDSR_FIELDSETRESULT);
DDS_DATAREADER_CPP(DMSG_TDSR_FIELDSETRESULTDataReader, DMSG_TDSR_FIELDSETRESULTSeq, DMSG_TDSR_FIELDSETRESULT);


#else

DDS_TYPESUPPORT_C(DMSG_TDSR_FIELDSETRESULTTypeSupport, DMSG_TDSR_FIELDSETRESULT);
DDS_DATAWRITER_C(DMSG_TDSR_FIELDSETRESULTDataWriter, DMSG_TDSR_FIELDSETRESULT);
DDS_DATAREADER_C(DMSG_TDSR_FIELDSETRESULTDataReader, DMSG_TDSR_FIELDSETRESULTSeq, DMSG_TDSR_FIELDSETRESULT);

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

DDS_TYPESUPPORT_CPP(DMSG_TDSR_JAMMINGTypeSupport, DMSG_TDSR_JAMMING);

DDS_DATAWRITER_CPP(DMSG_TDSR_JAMMINGDataWriter, DMSG_TDSR_JAMMING);
DDS_DATAREADER_CPP(DMSG_TDSR_JAMMINGDataReader, DMSG_TDSR_JAMMINGSeq, DMSG_TDSR_JAMMING);


#else

DDS_TYPESUPPORT_C(DMSG_TDSR_JAMMINGTypeSupport, DMSG_TDSR_JAMMING);
DDS_DATAWRITER_C(DMSG_TDSR_JAMMINGDataWriter, DMSG_TDSR_JAMMING);
DDS_DATAREADER_C(DMSG_TDSR_JAMMINGDataReader, DMSG_TDSR_JAMMINGSeq, DMSG_TDSR_JAMMING);

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

DDS_TYPESUPPORT_CPP(DMSG_TDSR_STATETypeSupport, DMSG_TDSR_STATE);

DDS_DATAWRITER_CPP(DMSG_TDSR_STATEDataWriter, DMSG_TDSR_STATE);
DDS_DATAREADER_CPP(DMSG_TDSR_STATEDataReader, DMSG_TDSR_STATESeq, DMSG_TDSR_STATE);


#else

DDS_TYPESUPPORT_C(DMSG_TDSR_STATETypeSupport, DMSG_TDSR_STATE);
DDS_DATAWRITER_C(DMSG_TDSR_STATEDataWriter, DMSG_TDSR_STATE);
DDS_DATAREADER_C(DMSG_TDSR_STATEDataReader, DMSG_TDSR_STATESeq, DMSG_TDSR_STATE);

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

DDS_TYPESUPPORT_CPP(DMSG_TDSR_TARGETTypeSupport, DMSG_TDSR_TARGET);

DDS_DATAWRITER_CPP(DMSG_TDSR_TARGETDataWriter, DMSG_TDSR_TARGET);
DDS_DATAREADER_CPP(DMSG_TDSR_TARGETDataReader, DMSG_TDSR_TARGETSeq, DMSG_TDSR_TARGET);


#else

DDS_TYPESUPPORT_C(DMSG_TDSR_TARGETTypeSupport, DMSG_TDSR_TARGET);
DDS_DATAWRITER_C(DMSG_TDSR_TARGETDataWriter, DMSG_TDSR_TARGET);
DDS_DATAREADER_C(DMSG_TDSR_TARGETDataReader, DMSG_TDSR_TARGETSeq, DMSG_TDSR_TARGET);

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

DDS_TYPESUPPORT_CPP(DMSG_TDSR_BSCOPETypeSupport, DMSG_TDSR_BSCOPE);

DDS_DATAWRITER_CPP(DMSG_TDSR_BSCOPEDataWriter, DMSG_TDSR_BSCOPE);
DDS_DATAREADER_CPP(DMSG_TDSR_BSCOPEDataReader, DMSG_TDSR_BSCOPESeq, DMSG_TDSR_BSCOPE);


#else

DDS_TYPESUPPORT_C(DMSG_TDSR_BSCOPETypeSupport, DMSG_TDSR_BSCOPE);
DDS_DATAWRITER_C(DMSG_TDSR_BSCOPEDataWriter, DMSG_TDSR_BSCOPE);
DDS_DATAREADER_C(DMSG_TDSR_BSCOPEDataReader, DMSG_TDSR_BSCOPESeq, DMSG_TDSR_BSCOPE);

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

DDS_TYPESUPPORT_CPP(DMSG_TDSR_COLUMNOFWATERTypeSupport, DMSG_TDSR_COLUMNOFWATER);

DDS_DATAWRITER_CPP(DMSG_TDSR_COLUMNOFWATERDataWriter, DMSG_TDSR_COLUMNOFWATER);
DDS_DATAREADER_CPP(DMSG_TDSR_COLUMNOFWATERDataReader, DMSG_TDSR_COLUMNOFWATERSeq, DMSG_TDSR_COLUMNOFWATER);


#else

DDS_TYPESUPPORT_C(DMSG_TDSR_COLUMNOFWATERTypeSupport, DMSG_TDSR_COLUMNOFWATER);
DDS_DATAWRITER_C(DMSG_TDSR_COLUMNOFWATERDataWriter, DMSG_TDSR_COLUMNOFWATER);
DDS_DATAREADER_C(DMSG_TDSR_COLUMNOFWATERDataReader, DMSG_TDSR_COLUMNOFWATERSeq, DMSG_TDSR_COLUMNOFWATER);

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

DDS_TYPESUPPORT_CPP(DMSG_TDSR_TWSTRACKINGTypeSupport, DMSG_TDSR_TWSTRACKING);

DDS_DATAWRITER_CPP(DMSG_TDSR_TWSTRACKINGDataWriter, DMSG_TDSR_TWSTRACKING);
DDS_DATAREADER_CPP(DMSG_TDSR_TWSTRACKINGDataReader, DMSG_TDSR_TWSTRACKINGSeq, DMSG_TDSR_TWSTRACKING);


#else

DDS_TYPESUPPORT_C(DMSG_TDSR_TWSTRACKINGTypeSupport, DMSG_TDSR_TWSTRACKING);
DDS_DATAWRITER_C(DMSG_TDSR_TWSTRACKINGDataWriter, DMSG_TDSR_TWSTRACKING);
DDS_DATAREADER_C(DMSG_TDSR_TWSTRACKINGDataReader, DMSG_TDSR_TWSTRACKINGSeq, DMSG_TDSR_TWSTRACKING);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRANTENNACTRLTypeSupport, DMSG_HMI_TDSRANTENNACTRL);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRANTENNACTRLDataWriter, DMSG_HMI_TDSRANTENNACTRL);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRANTENNACTRLDataReader, DMSG_HMI_TDSRANTENNACTRLSeq, DMSG_HMI_TDSRANTENNACTRL);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRANTENNACTRLTypeSupport, DMSG_HMI_TDSRANTENNACTRL);
DDS_DATAWRITER_C(DMSG_HMI_TDSRANTENNACTRLDataWriter, DMSG_HMI_TDSRANTENNACTRL);
DDS_DATAREADER_C(DMSG_HMI_TDSRANTENNACTRLDataReader, DMSG_HMI_TDSRANTENNACTRLSeq, DMSG_HMI_TDSRANTENNACTRL);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRBATTLESHORTCMDTypeSupport, DMSG_HMI_TDSRBATTLESHORTCMD);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRBATTLESHORTCMDDataWriter, DMSG_HMI_TDSRBATTLESHORTCMD);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRBATTLESHORTCMDDataReader, DMSG_HMI_TDSRBATTLESHORTCMDSeq, DMSG_HMI_TDSRBATTLESHORTCMD);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRBATTLESHORTCMDTypeSupport, DMSG_HMI_TDSRBATTLESHORTCMD);
DDS_DATAWRITER_C(DMSG_HMI_TDSRBATTLESHORTCMDDataWriter, DMSG_HMI_TDSRBATTLESHORTCMD);
DDS_DATAREADER_C(DMSG_HMI_TDSRBATTLESHORTCMDDataReader, DMSG_HMI_TDSRBATTLESHORTCMDSeq, DMSG_HMI_TDSRBATTLESHORTCMD);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRTRANSMITTERCTRLTypeSupport, DMSG_HMI_TDSRTRANSMITTERCTRL);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRTRANSMITTERCTRLDataWriter, DMSG_HMI_TDSRTRANSMITTERCTRL);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRTRANSMITTERCTRLDataReader, DMSG_HMI_TDSRTRANSMITTERCTRLSeq, DMSG_HMI_TDSRTRANSMITTERCTRL);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRTRANSMITTERCTRLTypeSupport, DMSG_HMI_TDSRTRANSMITTERCTRL);
DDS_DATAWRITER_C(DMSG_HMI_TDSRTRANSMITTERCTRLDataWriter, DMSG_HMI_TDSRTRANSMITTERCTRL);
DDS_DATAREADER_C(DMSG_HMI_TDSRTRANSMITTERCTRLDataReader, DMSG_HMI_TDSRTRANSMITTERCTRLSeq, DMSG_HMI_TDSRTRANSMITTERCTRL);

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

DDS_TYPESUPPORT_CPP(DMSG_OSM_TDSRFIELDSETTypeSupport, DMSG_OSM_TDSRFIELDSET);

DDS_DATAWRITER_CPP(DMSG_OSM_TDSRFIELDSETDataWriter, DMSG_OSM_TDSRFIELDSET);
DDS_DATAREADER_CPP(DMSG_OSM_TDSRFIELDSETDataReader, DMSG_OSM_TDSRFIELDSETSeq, DMSG_OSM_TDSRFIELDSET);


#else

DDS_TYPESUPPORT_C(DMSG_OSM_TDSRFIELDSETTypeSupport, DMSG_OSM_TDSRFIELDSET);
DDS_DATAWRITER_C(DMSG_OSM_TDSRFIELDSETDataWriter, DMSG_OSM_TDSRFIELDSET);
DDS_DATAREADER_C(DMSG_OSM_TDSRFIELDSETDataReader, DMSG_OSM_TDSRFIELDSETSeq, DMSG_OSM_TDSRFIELDSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRSURFACETRACKCTRLTypeSupport, DMSG_HMI_TDSRSURFACETRACKCTRL);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRSURFACETRACKCTRLDataWriter, DMSG_HMI_TDSRSURFACETRACKCTRL);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRSURFACETRACKCTRLDataReader, DMSG_HMI_TDSRSURFACETRACKCTRLSeq, DMSG_HMI_TDSRSURFACETRACKCTRL);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRSURFACETRACKCTRLTypeSupport, DMSG_HMI_TDSRSURFACETRACKCTRL);
DDS_DATAWRITER_C(DMSG_HMI_TDSRSURFACETRACKCTRLDataWriter, DMSG_HMI_TDSRSURFACETRACKCTRL);
DDS_DATAREADER_C(DMSG_HMI_TDSRSURFACETRACKCTRLDataReader, DMSG_HMI_TDSRSURFACETRACKCTRLSeq, DMSG_HMI_TDSRSURFACETRACKCTRL);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRRDRSILENCECTRLTypeSupport, DMSG_HMI_TDSRRDRSILENCECTRL);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRRDRSILENCECTRLDataWriter, DMSG_HMI_TDSRRDRSILENCECTRL);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRRDRSILENCECTRLDataReader, DMSG_HMI_TDSRRDRSILENCECTRLSeq, DMSG_HMI_TDSRRDRSILENCECTRL);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRRDRSILENCECTRLTypeSupport, DMSG_HMI_TDSRRDRSILENCECTRL);
DDS_DATAWRITER_C(DMSG_HMI_TDSRRDRSILENCECTRLDataWriter, DMSG_HMI_TDSRRDRSILENCECTRL);
DDS_DATAREADER_C(DMSG_HMI_TDSRRDRSILENCECTRLDataReader, DMSG_HMI_TDSRRDRSILENCECTRLSeq, DMSG_HMI_TDSRRDRSILENCECTRL);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRSENDCHANNELSETTypeSupport, DMSG_HMI_TDSRSENDCHANNELSET);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRSENDCHANNELSETDataWriter, DMSG_HMI_TDSRSENDCHANNELSET);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRSENDCHANNELSETDataReader, DMSG_HMI_TDSRSENDCHANNELSETSeq, DMSG_HMI_TDSRSENDCHANNELSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRSENDCHANNELSETTypeSupport, DMSG_HMI_TDSRSENDCHANNELSET);
DDS_DATAWRITER_C(DMSG_HMI_TDSRSENDCHANNELSETDataWriter, DMSG_HMI_TDSRSENDCHANNELSET);
DDS_DATAREADER_C(DMSG_HMI_TDSRSENDCHANNELSETDataReader, DMSG_HMI_TDSRSENDCHANNELSETSeq, DMSG_HMI_TDSRSENDCHANNELSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRSENDRFMODETypeSupport, DMSG_HMI_TDSRSENDRFMODE);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRSENDRFMODEDataWriter, DMSG_HMI_TDSRSENDRFMODE);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRSENDRFMODEDataReader, DMSG_HMI_TDSRSENDRFMODESeq, DMSG_HMI_TDSRSENDRFMODE);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRSENDRFMODETypeSupport, DMSG_HMI_TDSRSENDRFMODE);
DDS_DATAWRITER_C(DMSG_HMI_TDSRSENDRFMODEDataWriter, DMSG_HMI_TDSRSENDRFMODE);
DDS_DATAREADER_C(DMSG_HMI_TDSRSENDRFMODEDataReader, DMSG_HMI_TDSRSENDRFMODESeq, DMSG_HMI_TDSRSENDRFMODE);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRBLANKSECTORCTRLTypeSupport, DMSG_HMI_TDSRBLANKSECTORCTRL);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRBLANKSECTORCTRLDataWriter, DMSG_HMI_TDSRBLANKSECTORCTRL);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRBLANKSECTORCTRLDataReader, DMSG_HMI_TDSRBLANKSECTORCTRLSeq, DMSG_HMI_TDSRBLANKSECTORCTRL);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRBLANKSECTORCTRLTypeSupport, DMSG_HMI_TDSRBLANKSECTORCTRL);
DDS_DATAWRITER_C(DMSG_HMI_TDSRBLANKSECTORCTRLDataWriter, DMSG_HMI_TDSRBLANKSECTORCTRL);
DDS_DATAREADER_C(DMSG_HMI_TDSRBLANKSECTORCTRLDataReader, DMSG_HMI_TDSRBLANKSECTORCTRLSeq, DMSG_HMI_TDSRBLANKSECTORCTRL);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRVIDEOSETTypeSupport, DMSG_HMI_TDSRVIDEOSET);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRVIDEOSETDataWriter, DMSG_HMI_TDSRVIDEOSET);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRVIDEOSETDataReader, DMSG_HMI_TDSRVIDEOSETSeq, DMSG_HMI_TDSRVIDEOSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRVIDEOSETTypeSupport, DMSG_HMI_TDSRVIDEOSET);
DDS_DATAWRITER_C(DMSG_HMI_TDSRVIDEOSETDataWriter, DMSG_HMI_TDSRVIDEOSET);
DDS_DATAREADER_C(DMSG_HMI_TDSRVIDEOSETDataReader, DMSG_HMI_TDSRVIDEOSETSeq, DMSG_HMI_TDSRVIDEOSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRVIDEOREQTypeSupport, DMSG_HMI_TDSRVIDEOREQ);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRVIDEOREQDataWriter, DMSG_HMI_TDSRVIDEOREQ);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRVIDEOREQDataReader, DMSG_HMI_TDSRVIDEOREQSeq, DMSG_HMI_TDSRVIDEOREQ);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRVIDEOREQTypeSupport, DMSG_HMI_TDSRVIDEOREQ);
DDS_DATAWRITER_C(DMSG_HMI_TDSRVIDEOREQDataWriter, DMSG_HMI_TDSRVIDEOREQ);
DDS_DATAREADER_C(DMSG_HMI_TDSRVIDEOREQDataReader, DMSG_HMI_TDSRVIDEOREQSeq, DMSG_HMI_TDSRVIDEOREQ);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRRDRMODESETTypeSupport, DMSG_HMI_TDSRRDRMODESET);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRRDRMODESETDataWriter, DMSG_HMI_TDSRRDRMODESET);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRRDRMODESETDataReader, DMSG_HMI_TDSRRDRMODESETSeq, DMSG_HMI_TDSRRDRMODESET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRRDRMODESETTypeSupport, DMSG_HMI_TDSRRDRMODESET);
DDS_DATAWRITER_C(DMSG_HMI_TDSRRDRMODESETDataWriter, DMSG_HMI_TDSRRDRMODESET);
DDS_DATAREADER_C(DMSG_HMI_TDSRRDRMODESETDataReader, DMSG_HMI_TDSRRDRMODESETSeq, DMSG_HMI_TDSRRDRMODESET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRAIRTRACKINGSETTypeSupport, DMSG_HMI_TDSRAIRTRACKINGSET);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRAIRTRACKINGSETDataWriter, DMSG_HMI_TDSRAIRTRACKINGSET);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRAIRTRACKINGSETDataReader, DMSG_HMI_TDSRAIRTRACKINGSETSeq, DMSG_HMI_TDSRAIRTRACKINGSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRAIRTRACKINGSETTypeSupport, DMSG_HMI_TDSRAIRTRACKINGSET);
DDS_DATAWRITER_C(DMSG_HMI_TDSRAIRTRACKINGSETDataWriter, DMSG_HMI_TDSRAIRTRACKINGSET);
DDS_DATAREADER_C(DMSG_HMI_TDSRAIRTRACKINGSETDataReader, DMSG_HMI_TDSRAIRTRACKINGSETSeq, DMSG_HMI_TDSRAIRTRACKINGSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRSHIPTRACKINGSETTypeSupport, DMSG_HMI_TDSRSHIPTRACKINGSET);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRSHIPTRACKINGSETDataWriter, DMSG_HMI_TDSRSHIPTRACKINGSET);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRSHIPTRACKINGSETDataReader, DMSG_HMI_TDSRSHIPTRACKINGSETSeq, DMSG_HMI_TDSRSHIPTRACKINGSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRSHIPTRACKINGSETTypeSupport, DMSG_HMI_TDSRSHIPTRACKINGSET);
DDS_DATAWRITER_C(DMSG_HMI_TDSRSHIPTRACKINGSETDataWriter, DMSG_HMI_TDSRSHIPTRACKINGSET);
DDS_DATAREADER_C(DMSG_HMI_TDSRSHIPTRACKINGSETDataReader, DMSG_HMI_TDSRSHIPTRACKINGSETSeq, DMSG_HMI_TDSRSHIPTRACKINGSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRJAMMINGDETECTSETTypeSupport, DMSG_HMI_TDSRJAMMINGDETECTSET);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRJAMMINGDETECTSETDataWriter, DMSG_HMI_TDSRJAMMINGDETECTSET);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRJAMMINGDETECTSETDataReader, DMSG_HMI_TDSRJAMMINGDETECTSETSeq, DMSG_HMI_TDSRJAMMINGDETECTSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRJAMMINGDETECTSETTypeSupport, DMSG_HMI_TDSRJAMMINGDETECTSET);
DDS_DATAWRITER_C(DMSG_HMI_TDSRJAMMINGDETECTSETDataWriter, DMSG_HMI_TDSRJAMMINGDETECTSET);
DDS_DATAREADER_C(DMSG_HMI_TDSRJAMMINGDETECTSETDataReader, DMSG_HMI_TDSRJAMMINGDETECTSETSeq, DMSG_HMI_TDSRJAMMINGDETECTSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRLOWSPEEDDETECTSETTypeSupport, DMSG_HMI_TDSRLOWSPEEDDETECTSET);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRLOWSPEEDDETECTSETDataWriter, DMSG_HMI_TDSRLOWSPEEDDETECTSET);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRLOWSPEEDDETECTSETDataReader, DMSG_HMI_TDSRLOWSPEEDDETECTSETSeq, DMSG_HMI_TDSRLOWSPEEDDETECTSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRLOWSPEEDDETECTSETTypeSupport, DMSG_HMI_TDSRLOWSPEEDDETECTSET);
DDS_DATAWRITER_C(DMSG_HMI_TDSRLOWSPEEDDETECTSETDataWriter, DMSG_HMI_TDSRLOWSPEEDDETECTSET);
DDS_DATAREADER_C(DMSG_HMI_TDSRLOWSPEEDDETECTSETDataReader, DMSG_HMI_TDSRLOWSPEEDDETECTSETSeq, DMSG_HMI_TDSRLOWSPEEDDETECTSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRLOWALTDETECTSETTypeSupport, DMSG_HMI_TDSRLOWALTDETECTSET);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRLOWALTDETECTSETDataWriter, DMSG_HMI_TDSRLOWALTDETECTSET);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRLOWALTDETECTSETDataReader, DMSG_HMI_TDSRLOWALTDETECTSETSeq, DMSG_HMI_TDSRLOWALTDETECTSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRLOWALTDETECTSETTypeSupport, DMSG_HMI_TDSRLOWALTDETECTSET);
DDS_DATAWRITER_C(DMSG_HMI_TDSRLOWALTDETECTSETDataWriter, DMSG_HMI_TDSRLOWALTDETECTSET);
DDS_DATAREADER_C(DMSG_HMI_TDSRLOWALTDETECTSETDataReader, DMSG_HMI_TDSRLOWALTDETECTSETSeq, DMSG_HMI_TDSRLOWALTDETECTSET);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSRSIDELOBEBLOCKTypeSupport, DMSG_HMI_TDSRSIDELOBEBLOCK);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSRSIDELOBEBLOCKDataWriter, DMSG_HMI_TDSRSIDELOBEBLOCK);
DDS_DATAREADER_CPP(DMSG_HMI_TDSRSIDELOBEBLOCKDataReader, DMSG_HMI_TDSRSIDELOBEBLOCKSeq, DMSG_HMI_TDSRSIDELOBEBLOCK);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSRSIDELOBEBLOCKTypeSupport, DMSG_HMI_TDSRSIDELOBEBLOCK);
DDS_DATAWRITER_C(DMSG_HMI_TDSRSIDELOBEBLOCKDataWriter, DMSG_HMI_TDSRSIDELOBEBLOCK);
DDS_DATAREADER_C(DMSG_HMI_TDSRSIDELOBEBLOCKDataReader, DMSG_HMI_TDSRSIDELOBEBLOCKSeq, DMSG_HMI_TDSRSIDELOBEBLOCK);

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

DDS_TYPESUPPORT_CPP(DMSG_HMI_TDSREQUIPQUITSETTypeSupport, DMSG_HMI_TDSREQUIPQUITSET);

DDS_DATAWRITER_CPP(DMSG_HMI_TDSREQUIPQUITSETDataWriter, DMSG_HMI_TDSREQUIPQUITSET);
DDS_DATAREADER_CPP(DMSG_HMI_TDSREQUIPQUITSETDataReader, DMSG_HMI_TDSREQUIPQUITSETSeq, DMSG_HMI_TDSREQUIPQUITSET);


#else

DDS_TYPESUPPORT_C(DMSG_HMI_TDSREQUIPQUITSETTypeSupport, DMSG_HMI_TDSREQUIPQUITSET);
DDS_DATAWRITER_C(DMSG_HMI_TDSREQUIPQUITSETDataWriter, DMSG_HMI_TDSREQUIPQUITSET);
DDS_DATAREADER_C(DMSG_HMI_TDSREQUIPQUITSETDataReader, DMSG_HMI_TDSREQUIPQUITSETSeq, DMSG_HMI_TDSREQUIPQUITSET);

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

DDS_TYPESUPPORT_CPP(DMSG_EC_TDSRTWSTARGETDESIGTypeSupport, DMSG_EC_TDSRTWSTARGETDESIG);

DDS_DATAWRITER_CPP(DMSG_EC_TDSRTWSTARGETDESIGDataWriter, DMSG_EC_TDSRTWSTARGETDESIG);
DDS_DATAREADER_CPP(DMSG_EC_TDSRTWSTARGETDESIGDataReader, DMSG_EC_TDSRTWSTARGETDESIGSeq, DMSG_EC_TDSRTWSTARGETDESIG);


#else

DDS_TYPESUPPORT_C(DMSG_EC_TDSRTWSTARGETDESIGTypeSupport, DMSG_EC_TDSRTWSTARGETDESIG);
DDS_DATAWRITER_C(DMSG_EC_TDSRTWSTARGETDESIGDataWriter, DMSG_EC_TDSRTWSTARGETDESIG);
DDS_DATAREADER_C(DMSG_EC_TDSRTWSTARGETDESIGDataReader, DMSG_EC_TDSRTWSTARGETDESIGSeq, DMSG_EC_TDSRTWSTARGETDESIG);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif  /* DDS_TDSRMMISupport_1808377665_h */
