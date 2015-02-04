
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from rmOPV_Protocol.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/

#ifndef rmOPV_ProtocolSupport_139685288_h
#define rmOPV_ProtocolSupport_139685288_h

/* Uses */
#include "rmOPV_Protocol.h"



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

DDS_TYPESUPPORT_CPP(ST_POSITIONTypeSupport, ST_POSITION);

DDS_DATAWRITER_CPP(ST_POSITIONDataWriter, ST_POSITION);
DDS_DATAREADER_CPP(ST_POSITIONDataReader, ST_POSITIONSeq, ST_POSITION);


#else

DDS_TYPESUPPORT_C(ST_POSITIONTypeSupport, ST_POSITION);
DDS_DATAWRITER_C(ST_POSITIONDataWriter, ST_POSITION);
DDS_DATAREADER_C(ST_POSITIONDataReader, ST_POSITIONSeq, ST_POSITION);

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

DDS_TYPESUPPORT_CPP(ST_ENTITY_STATETypeSupport, ST_ENTITY_STATE);

DDS_DATAWRITER_CPP(ST_ENTITY_STATEDataWriter, ST_ENTITY_STATE);
DDS_DATAREADER_CPP(ST_ENTITY_STATEDataReader, ST_ENTITY_STATESeq, ST_ENTITY_STATE);


#else

DDS_TYPESUPPORT_C(ST_ENTITY_STATETypeSupport, ST_ENTITY_STATE);
DDS_DATAWRITER_C(ST_ENTITY_STATEDataWriter, ST_ENTITY_STATE);
DDS_DATAREADER_C(ST_ENTITY_STATEDataReader, ST_ENTITY_STATESeq, ST_ENTITY_STATE);

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

DDS_TYPESUPPORT_CPP(ST_ENTITY_INFOTypeSupport, ST_ENTITY_INFO);

DDS_DATAWRITER_CPP(ST_ENTITY_INFODataWriter, ST_ENTITY_INFO);
DDS_DATAREADER_CPP(ST_ENTITY_INFODataReader, ST_ENTITY_INFOSeq, ST_ENTITY_INFO);


#else

DDS_TYPESUPPORT_C(ST_ENTITY_INFOTypeSupport, ST_ENTITY_INFO);
DDS_DATAWRITER_C(ST_ENTITY_INFODataWriter, ST_ENTITY_INFO);
DDS_DATAREADER_C(ST_ENTITY_INFODataReader, ST_ENTITY_INFOSeq, ST_ENTITY_INFO);

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

DDS_TYPESUPPORT_CPP(ST_ENTITY_ATTRIBUTETypeSupport, ST_ENTITY_ATTRIBUTE);

DDS_DATAWRITER_CPP(ST_ENTITY_ATTRIBUTEDataWriter, ST_ENTITY_ATTRIBUTE);
DDS_DATAREADER_CPP(ST_ENTITY_ATTRIBUTEDataReader, ST_ENTITY_ATTRIBUTESeq, ST_ENTITY_ATTRIBUTE);


#else

DDS_TYPESUPPORT_C(ST_ENTITY_ATTRIBUTETypeSupport, ST_ENTITY_ATTRIBUTE);
DDS_DATAWRITER_C(ST_ENTITY_ATTRIBUTEDataWriter, ST_ENTITY_ATTRIBUTE);
DDS_DATAREADER_C(ST_ENTITY_ATTRIBUTEDataReader, ST_ENTITY_ATTRIBUTESeq, ST_ENTITY_ATTRIBUTE);

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

DDS_TYPESUPPORT_CPP(ST_MISSILE_DATATypeSupport, ST_MISSILE_DATA);

DDS_DATAWRITER_CPP(ST_MISSILE_DATADataWriter, ST_MISSILE_DATA);
DDS_DATAREADER_CPP(ST_MISSILE_DATADataReader, ST_MISSILE_DATASeq, ST_MISSILE_DATA);


#else

DDS_TYPESUPPORT_C(ST_MISSILE_DATATypeSupport, ST_MISSILE_DATA);
DDS_DATAWRITER_C(ST_MISSILE_DATADataWriter, ST_MISSILE_DATA);
DDS_DATAREADER_C(ST_MISSILE_DATADataReader, ST_MISSILE_DATASeq, ST_MISSILE_DATA);

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

DDS_TYPESUPPORT_CPP(ST_AMMUNITION_DATATypeSupport, ST_AMMUNITION_DATA);

DDS_DATAWRITER_CPP(ST_AMMUNITION_DATADataWriter, ST_AMMUNITION_DATA);
DDS_DATAREADER_CPP(ST_AMMUNITION_DATADataReader, ST_AMMUNITION_DATASeq, ST_AMMUNITION_DATA);


#else

DDS_TYPESUPPORT_C(ST_AMMUNITION_DATATypeSupport, ST_AMMUNITION_DATA);
DDS_DATAWRITER_C(ST_AMMUNITION_DATADataWriter, ST_AMMUNITION_DATA);
DDS_DATAREADER_C(ST_AMMUNITION_DATADataReader, ST_AMMUNITION_DATASeq, ST_AMMUNITION_DATA);

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

DDS_TYPESUPPORT_CPP(SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKTypeSupport, SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK);

DDS_DATAWRITER_CPP(SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKDataWriter, SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK);
DDS_DATAREADER_CPP(SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKDataReader, SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKSeq, SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK);


#else

DDS_TYPESUPPORT_C(SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKTypeSupport, SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK);
DDS_DATAWRITER_C(SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKDataWriter, SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK);
DDS_DATAREADER_C(SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKDataReader, SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKSeq, SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK);

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

DDS_TYPESUPPORT_CPP(SIM_SC_SIMULATOR_STATUS_REPORTTypeSupport, SIM_SC_SIMULATOR_STATUS_REPORT);

DDS_DATAWRITER_CPP(SIM_SC_SIMULATOR_STATUS_REPORTDataWriter, SIM_SC_SIMULATOR_STATUS_REPORT);
DDS_DATAREADER_CPP(SIM_SC_SIMULATOR_STATUS_REPORTDataReader, SIM_SC_SIMULATOR_STATUS_REPORTSeq, SIM_SC_SIMULATOR_STATUS_REPORT);


#else

DDS_TYPESUPPORT_C(SIM_SC_SIMULATOR_STATUS_REPORTTypeSupport, SIM_SC_SIMULATOR_STATUS_REPORT);
DDS_DATAWRITER_C(SIM_SC_SIMULATOR_STATUS_REPORTDataWriter, SIM_SC_SIMULATOR_STATUS_REPORT);
DDS_DATAREADER_C(SIM_SC_SIMULATOR_STATUS_REPORTDataReader, SIM_SC_SIMULATOR_STATUS_REPORTSeq, SIM_SC_SIMULATOR_STATUS_REPORT);

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

DDS_TYPESUPPORT_CPP(SC_SER_LINK_CONNECTION_COMMANDTypeSupport, SC_SER_LINK_CONNECTION_COMMAND);

DDS_DATAWRITER_CPP(SC_SER_LINK_CONNECTION_COMMANDDataWriter, SC_SER_LINK_CONNECTION_COMMAND);
DDS_DATAREADER_CPP(SC_SER_LINK_CONNECTION_COMMANDDataReader, SC_SER_LINK_CONNECTION_COMMANDSeq, SC_SER_LINK_CONNECTION_COMMAND);


#else

DDS_TYPESUPPORT_C(SC_SER_LINK_CONNECTION_COMMANDTypeSupport, SC_SER_LINK_CONNECTION_COMMAND);
DDS_DATAWRITER_C(SC_SER_LINK_CONNECTION_COMMANDDataWriter, SC_SER_LINK_CONNECTION_COMMAND);
DDS_DATAREADER_C(SC_SER_LINK_CONNECTION_COMMANDDataReader, SC_SER_LINK_CONNECTION_COMMANDSeq, SC_SER_LINK_CONNECTION_COMMAND);

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

DDS_TYPESUPPORT_CPP(SER_SC_LINK_CONNECTION_COMMAND_ACKTypeSupport, SER_SC_LINK_CONNECTION_COMMAND_ACK);

DDS_DATAWRITER_CPP(SER_SC_LINK_CONNECTION_COMMAND_ACKDataWriter, SER_SC_LINK_CONNECTION_COMMAND_ACK);
DDS_DATAREADER_CPP(SER_SC_LINK_CONNECTION_COMMAND_ACKDataReader, SER_SC_LINK_CONNECTION_COMMAND_ACKSeq, SER_SC_LINK_CONNECTION_COMMAND_ACK);


#else

DDS_TYPESUPPORT_C(SER_SC_LINK_CONNECTION_COMMAND_ACKTypeSupport, SER_SC_LINK_CONNECTION_COMMAND_ACK);
DDS_DATAWRITER_C(SER_SC_LINK_CONNECTION_COMMAND_ACKDataWriter, SER_SC_LINK_CONNECTION_COMMAND_ACK);
DDS_DATAREADER_C(SER_SC_LINK_CONNECTION_COMMAND_ACKDataReader, SER_SC_LINK_CONNECTION_COMMAND_ACKSeq, SER_SC_LINK_CONNECTION_COMMAND_ACK);

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

DDS_TYPESUPPORT_CPP(SC_SIM_SIMULATION_MANAGEMENT_COMMANDTypeSupport, SC_SIM_SIMULATION_MANAGEMENT_COMMAND);

DDS_DATAWRITER_CPP(SC_SIM_SIMULATION_MANAGEMENT_COMMANDDataWriter, SC_SIM_SIMULATION_MANAGEMENT_COMMAND);
DDS_DATAREADER_CPP(SC_SIM_SIMULATION_MANAGEMENT_COMMANDDataReader, SC_SIM_SIMULATION_MANAGEMENT_COMMANDSeq, SC_SIM_SIMULATION_MANAGEMENT_COMMAND);


#else

DDS_TYPESUPPORT_C(SC_SIM_SIMULATION_MANAGEMENT_COMMANDTypeSupport, SC_SIM_SIMULATION_MANAGEMENT_COMMAND);
DDS_DATAWRITER_C(SC_SIM_SIMULATION_MANAGEMENT_COMMANDDataWriter, SC_SIM_SIMULATION_MANAGEMENT_COMMAND);
DDS_DATAREADER_C(SC_SIM_SIMULATION_MANAGEMENT_COMMANDDataReader, SC_SIM_SIMULATION_MANAGEMENT_COMMANDSeq, SC_SIM_SIMULATION_MANAGEMENT_COMMAND);

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

DDS_TYPESUPPORT_CPP(SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKTypeSupport, SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK);

DDS_DATAWRITER_CPP(SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKDataWriter, SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK);
DDS_DATAREADER_CPP(SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKDataReader, SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKSeq, SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK);


#else

DDS_TYPESUPPORT_C(SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKTypeSupport, SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK);
DDS_DATAWRITER_C(SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKDataWriter, SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK);
DDS_DATAREADER_C(SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKDataReader, SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKSeq, SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK);

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

DDS_TYPESUPPORT_CPP(SC_SIM_PARAMETER_DISTRIBUTION_COMMANDTypeSupport, SC_SIM_PARAMETER_DISTRIBUTION_COMMAND);

DDS_DATAWRITER_CPP(SC_SIM_PARAMETER_DISTRIBUTION_COMMANDDataWriter, SC_SIM_PARAMETER_DISTRIBUTION_COMMAND);
DDS_DATAREADER_CPP(SC_SIM_PARAMETER_DISTRIBUTION_COMMANDDataReader, SC_SIM_PARAMETER_DISTRIBUTION_COMMANDSeq, SC_SIM_PARAMETER_DISTRIBUTION_COMMAND);


#else

DDS_TYPESUPPORT_C(SC_SIM_PARAMETER_DISTRIBUTION_COMMANDTypeSupport, SC_SIM_PARAMETER_DISTRIBUTION_COMMAND);
DDS_DATAWRITER_C(SC_SIM_PARAMETER_DISTRIBUTION_COMMANDDataWriter, SC_SIM_PARAMETER_DISTRIBUTION_COMMAND);
DDS_DATAREADER_C(SC_SIM_PARAMETER_DISTRIBUTION_COMMANDDataReader, SC_SIM_PARAMETER_DISTRIBUTION_COMMANDSeq, SC_SIM_PARAMETER_DISTRIBUTION_COMMAND);

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

DDS_TYPESUPPORT_CPP(SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKTypeSupport, SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK);

DDS_DATAWRITER_CPP(SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKDataWriter, SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK);
DDS_DATAREADER_CPP(SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKDataReader, SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKSeq, SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK);


#else

DDS_TYPESUPPORT_C(SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKTypeSupport, SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK);
DDS_DATAWRITER_C(SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKDataWriter, SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK);
DDS_DATAREADER_C(SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKDataReader, SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKSeq, SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK);

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

DDS_TYPESUPPORT_CPP(SC_SIM_SIMULATOR_PARAMETERTypeSupport, SC_SIM_SIMULATOR_PARAMETER);

DDS_DATAWRITER_CPP(SC_SIM_SIMULATOR_PARAMETERDataWriter, SC_SIM_SIMULATOR_PARAMETER);
DDS_DATAREADER_CPP(SC_SIM_SIMULATOR_PARAMETERDataReader, SC_SIM_SIMULATOR_PARAMETERSeq, SC_SIM_SIMULATOR_PARAMETER);


#else

DDS_TYPESUPPORT_C(SC_SIM_SIMULATOR_PARAMETERTypeSupport, SC_SIM_SIMULATOR_PARAMETER);
DDS_DATAWRITER_C(SC_SIM_SIMULATOR_PARAMETERDataWriter, SC_SIM_SIMULATOR_PARAMETER);
DDS_DATAREADER_C(SC_SIM_SIMULATOR_PARAMETERDataReader, SC_SIM_SIMULATOR_PARAMETERSeq, SC_SIM_SIMULATOR_PARAMETER);

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

DDS_TYPESUPPORT_CPP(SIM_SC_SIMULATOR_PARAMETER_ACKTypeSupport, SIM_SC_SIMULATOR_PARAMETER_ACK);

DDS_DATAWRITER_CPP(SIM_SC_SIMULATOR_PARAMETER_ACKDataWriter, SIM_SC_SIMULATOR_PARAMETER_ACK);
DDS_DATAREADER_CPP(SIM_SC_SIMULATOR_PARAMETER_ACKDataReader, SIM_SC_SIMULATOR_PARAMETER_ACKSeq, SIM_SC_SIMULATOR_PARAMETER_ACK);


#else

DDS_TYPESUPPORT_C(SIM_SC_SIMULATOR_PARAMETER_ACKTypeSupport, SIM_SC_SIMULATOR_PARAMETER_ACK);
DDS_DATAWRITER_C(SIM_SC_SIMULATOR_PARAMETER_ACKDataWriter, SIM_SC_SIMULATOR_PARAMETER_ACK);
DDS_DATAREADER_C(SIM_SC_SIMULATOR_PARAMETER_ACKDataReader, SIM_SC_SIMULATOR_PARAMETER_ACKSeq, SIM_SC_SIMULATOR_PARAMETER_ACK);

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

DDS_TYPESUPPORT_CPP(SC_SIM_ENVIRONMENTTypeSupport, SC_SIM_ENVIRONMENT);

DDS_DATAWRITER_CPP(SC_SIM_ENVIRONMENTDataWriter, SC_SIM_ENVIRONMENT);
DDS_DATAREADER_CPP(SC_SIM_ENVIRONMENTDataReader, SC_SIM_ENVIRONMENTSeq, SC_SIM_ENVIRONMENT);


#else

DDS_TYPESUPPORT_C(SC_SIM_ENVIRONMENTTypeSupport, SC_SIM_ENVIRONMENT);
DDS_DATAWRITER_C(SC_SIM_ENVIRONMENTDataWriter, SC_SIM_ENVIRONMENT);
DDS_DATAREADER_C(SC_SIM_ENVIRONMENTDataReader, SC_SIM_ENVIRONMENTSeq, SC_SIM_ENVIRONMENT);

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

DDS_TYPESUPPORT_CPP(SC_SIM_ENTITYTypeSupport, SC_SIM_ENTITY);

DDS_DATAWRITER_CPP(SC_SIM_ENTITYDataWriter, SC_SIM_ENTITY);
DDS_DATAREADER_CPP(SC_SIM_ENTITYDataReader, SC_SIM_ENTITYSeq, SC_SIM_ENTITY);


#else

DDS_TYPESUPPORT_C(SC_SIM_ENTITYTypeSupport, SC_SIM_ENTITY);
DDS_DATAWRITER_C(SC_SIM_ENTITYDataWriter, SC_SIM_ENTITY);
DDS_DATAREADER_C(SC_SIM_ENTITYDataReader, SC_SIM_ENTITYSeq, SC_SIM_ENTITY);

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

DDS_TYPESUPPORT_CPP(SC_SIM_ENTITY_STATETypeSupport, SC_SIM_ENTITY_STATE);

DDS_DATAWRITER_CPP(SC_SIM_ENTITY_STATEDataWriter, SC_SIM_ENTITY_STATE);
DDS_DATAREADER_CPP(SC_SIM_ENTITY_STATEDataReader, SC_SIM_ENTITY_STATESeq, SC_SIM_ENTITY_STATE);


#else

DDS_TYPESUPPORT_C(SC_SIM_ENTITY_STATETypeSupport, SC_SIM_ENTITY_STATE);
DDS_DATAWRITER_C(SC_SIM_ENTITY_STATEDataWriter, SC_SIM_ENTITY_STATE);
DDS_DATAREADER_C(SC_SIM_ENTITY_STATEDataReader, SC_SIM_ENTITY_STATESeq, SC_SIM_ENTITY_STATE);

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

DDS_TYPESUPPORT_CPP(SC_SIM_OWNSHIPTypeSupport, SC_SIM_OWNSHIP);

DDS_DATAWRITER_CPP(SC_SIM_OWNSHIPDataWriter, SC_SIM_OWNSHIP);
DDS_DATAREADER_CPP(SC_SIM_OWNSHIPDataReader, SC_SIM_OWNSHIPSeq, SC_SIM_OWNSHIP);


#else

DDS_TYPESUPPORT_C(SC_SIM_OWNSHIPTypeSupport, SC_SIM_OWNSHIP);
DDS_DATAWRITER_C(SC_SIM_OWNSHIPDataWriter, SC_SIM_OWNSHIP);
DDS_DATAREADER_C(SC_SIM_OWNSHIPDataReader, SC_SIM_OWNSHIPSeq, SC_SIM_OWNSHIP);

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

DDS_TYPESUPPORT_CPP(SC_SIM_OWNSHIP_STATETypeSupport, SC_SIM_OWNSHIP_STATE);

DDS_DATAWRITER_CPP(SC_SIM_OWNSHIP_STATEDataWriter, SC_SIM_OWNSHIP_STATE);
DDS_DATAREADER_CPP(SC_SIM_OWNSHIP_STATEDataReader, SC_SIM_OWNSHIP_STATESeq, SC_SIM_OWNSHIP_STATE);


#else

DDS_TYPESUPPORT_C(SC_SIM_OWNSHIP_STATETypeSupport, SC_SIM_OWNSHIP_STATE);
DDS_DATAWRITER_C(SC_SIM_OWNSHIP_STATEDataWriter, SC_SIM_OWNSHIP_STATE);
DDS_DATAREADER_C(SC_SIM_OWNSHIP_STATEDataReader, SC_SIM_OWNSHIP_STATESeq, SC_SIM_OWNSHIP_STATE);

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

DDS_TYPESUPPORT_CPP(SIM_SC_MISSILE_CREATIONTypeSupport, SIM_SC_MISSILE_CREATION);

DDS_DATAWRITER_CPP(SIM_SC_MISSILE_CREATIONDataWriter, SIM_SC_MISSILE_CREATION);
DDS_DATAREADER_CPP(SIM_SC_MISSILE_CREATIONDataReader, SIM_SC_MISSILE_CREATIONSeq, SIM_SC_MISSILE_CREATION);


#else

DDS_TYPESUPPORT_C(SIM_SC_MISSILE_CREATIONTypeSupport, SIM_SC_MISSILE_CREATION);
DDS_DATAWRITER_C(SIM_SC_MISSILE_CREATIONDataWriter, SIM_SC_MISSILE_CREATION);
DDS_DATAREADER_C(SIM_SC_MISSILE_CREATIONDataReader, SIM_SC_MISSILE_CREATIONSeq, SIM_SC_MISSILE_CREATION);

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

DDS_TYPESUPPORT_CPP(SIM_SC_SHELL_CREATIONTypeSupport, SIM_SC_SHELL_CREATION);

DDS_DATAWRITER_CPP(SIM_SC_SHELL_CREATIONDataWriter, SIM_SC_SHELL_CREATION);
DDS_DATAREADER_CPP(SIM_SC_SHELL_CREATIONDataReader, SIM_SC_SHELL_CREATIONSeq, SIM_SC_SHELL_CREATION);


#else

DDS_TYPESUPPORT_C(SIM_SC_SHELL_CREATIONTypeSupport, SIM_SC_SHELL_CREATION);
DDS_DATAWRITER_C(SIM_SC_SHELL_CREATIONDataWriter, SIM_SC_SHELL_CREATION);
DDS_DATAREADER_C(SIM_SC_SHELL_CREATIONDataReader, SIM_SC_SHELL_CREATIONSeq, SIM_SC_SHELL_CREATION);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif  /* rmOPV_ProtocolSupport_139685288_h */
