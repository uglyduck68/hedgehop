
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from rmOPV_Protocol.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/

#ifndef rmOPV_Protocol_139685288_h
#define rmOPV_Protocol_139685288_h

#ifndef NDDS_STANDALONE_TYPE
    #ifdef __cplusplus
        #ifndef ndds_cpp_h
            #include "ndds/ndds_cpp.h"
        #endif
    #else
        #ifndef ndds_c_h
            #include "ndds/ndds_c.h"
        #endif
    #endif
#else
    #include "ndds_standalone_type.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *ST_POSITIONTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct ST_POSITIONSeq;

#ifndef NDDS_STANDALONE_TYPE
    class ST_POSITIONTypeSupport;
    class ST_POSITIONDataWriter;
    class ST_POSITIONDataReader;
#endif

#endif

            
    
class ST_POSITION                                        
{
public:            
#ifdef __cplusplus
    typedef struct ST_POSITIONSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef ST_POSITIONTypeSupport TypeSupport;
    typedef ST_POSITIONDataWriter DataWriter;
    typedef ST_POSITIONDataReader DataReader;
#endif

#endif
    
    DDS_Double  dLon;

    DDS_Double  dLat;

    DDS_Double  dAlt;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* ST_POSITION_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(ST_POSITIONSeq, ST_POSITION);
        
NDDSUSERDllExport
RTIBool ST_POSITION_initialize(
        ST_POSITION* self);
        
NDDSUSERDllExport
RTIBool ST_POSITION_initialize_ex(
        ST_POSITION* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void ST_POSITION_finalize(
        ST_POSITION* self);
                        
NDDSUSERDllExport
void ST_POSITION_finalize_ex(
        ST_POSITION* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool ST_POSITION_copy(
        ST_POSITION* dst,
        const ST_POSITION* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *ST_ENTITY_STATETYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct ST_ENTITY_STATESeq;

#ifndef NDDS_STANDALONE_TYPE
    class ST_ENTITY_STATETypeSupport;
    class ST_ENTITY_STATEDataWriter;
    class ST_ENTITY_STATEDataReader;
#endif

#endif

            
    
class ST_ENTITY_STATE                                        
{
public:            
#ifdef __cplusplus
    typedef struct ST_ENTITY_STATESeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef ST_ENTITY_STATETypeSupport TypeSupport;
    typedef ST_ENTITY_STATEDataWriter DataWriter;
    typedef ST_ENTITY_STATEDataReader DataReader;
#endif

#endif
    
    ST_POSITION  stPosition;

    DDS_Double  dSpeed;

    DDS_Double  dCourse;

    DDS_Double  dHeading;

    DDS_Double  dRoll;

    DDS_Double  dPitch;

    DDS_Double  dHealthPoint;

    DDS_Short  bDestroyed;

    DDS_Short  Reserved_1;

    DDS_Short  Reserved_2;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* ST_ENTITY_STATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(ST_ENTITY_STATESeq, ST_ENTITY_STATE);
        
NDDSUSERDllExport
RTIBool ST_ENTITY_STATE_initialize(
        ST_ENTITY_STATE* self);
        
NDDSUSERDllExport
RTIBool ST_ENTITY_STATE_initialize_ex(
        ST_ENTITY_STATE* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void ST_ENTITY_STATE_finalize(
        ST_ENTITY_STATE* self);
                        
NDDSUSERDllExport
void ST_ENTITY_STATE_finalize_ex(
        ST_ENTITY_STATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool ST_ENTITY_STATE_copy(
        ST_ENTITY_STATE* dst,
        const ST_ENTITY_STATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *ST_ENTITY_INFOTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct ST_ENTITY_INFOSeq;

#ifndef NDDS_STANDALONE_TYPE
    class ST_ENTITY_INFOTypeSupport;
    class ST_ENTITY_INFODataWriter;
    class ST_ENTITY_INFODataReader;
#endif

#endif

            
    
class ST_ENTITY_INFO                                        
{
public:            
#ifdef __cplusplus
    typedef struct ST_ENTITY_INFOSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef ST_ENTITY_INFOTypeSupport TypeSupport;
    typedef ST_ENTITY_INFODataWriter DataWriter;
    typedef ST_ENTITY_INFODataReader DataReader;
#endif

#endif
    
    DDS_UnsignedLong  ulType;

    DDS_Char  chESM_Name[5];

    DDS_UnsignedLong  ulPlatformClass;

    DDS_UnsignedLong  ulPlatformKind;

    DDS_UnsignedLong  ulPlatformMission;

    DDS_UnsignedLong  ulIdentity;

    DDS_Short  nMode1;

    DDS_Short  nMode2;

    DDS_Short  nMode3A;

    DDS_Short  nMode4;

    DDS_Short  nWeaponClass;

    DDS_Char  chWeaponRadarInfo[5];

    DDS_Double  dWeaponRange;

    DDS_Double  dWeaponSpeed;

    DDS_Short  nWeaponOperationType;

    DDS_Short  nSensorClass;

    DDS_Short  nSensorThreatLevel;

    DDS_Char  chSensorInfo[5];

    DDS_Double  dSensorFreqency;

    DDS_Double  dSensorScanRate;

    DDS_Double  dSensorScanType;

    DDS_Double  dSensorAmplitude;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* ST_ENTITY_INFO_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(ST_ENTITY_INFOSeq, ST_ENTITY_INFO);
        
NDDSUSERDllExport
RTIBool ST_ENTITY_INFO_initialize(
        ST_ENTITY_INFO* self);
        
NDDSUSERDllExport
RTIBool ST_ENTITY_INFO_initialize_ex(
        ST_ENTITY_INFO* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void ST_ENTITY_INFO_finalize(
        ST_ENTITY_INFO* self);
                        
NDDSUSERDllExport
void ST_ENTITY_INFO_finalize_ex(
        ST_ENTITY_INFO* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool ST_ENTITY_INFO_copy(
        ST_ENTITY_INFO* dst,
        const ST_ENTITY_INFO* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *ST_ENTITY_ATTRIBUTETYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct ST_ENTITY_ATTRIBUTESeq;

#ifndef NDDS_STANDALONE_TYPE
    class ST_ENTITY_ATTRIBUTETypeSupport;
    class ST_ENTITY_ATTRIBUTEDataWriter;
    class ST_ENTITY_ATTRIBUTEDataReader;
#endif

#endif

            
    
class ST_ENTITY_ATTRIBUTE                                        
{
public:            
#ifdef __cplusplus
    typedef struct ST_ENTITY_ATTRIBUTESeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef ST_ENTITY_ATTRIBUTETypeSupport TypeSupport;
    typedef ST_ENTITY_ATTRIBUTEDataWriter DataWriter;
    typedef ST_ENTITY_ATTRIBUTEDataReader DataReader;
#endif

#endif
    
    DDS_Double  dTurnRate;

    DDS_Double  dRiseRate;

    DDS_Double  dMaxAltitude;

    DDS_Double  dMaxSpeed;

    DDS_Double  dMaxAcceleration;

    DDS_Double  dMaxHealthPoint;

    DDS_Double  dLength;

    DDS_Double  dWidth;

    DDS_Double  dHeight;

    DDS_Double  dWeight;

    DDS_Short  Reserved;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* ST_ENTITY_ATTRIBUTE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(ST_ENTITY_ATTRIBUTESeq, ST_ENTITY_ATTRIBUTE);
        
NDDSUSERDllExport
RTIBool ST_ENTITY_ATTRIBUTE_initialize(
        ST_ENTITY_ATTRIBUTE* self);
        
NDDSUSERDllExport
RTIBool ST_ENTITY_ATTRIBUTE_initialize_ex(
        ST_ENTITY_ATTRIBUTE* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void ST_ENTITY_ATTRIBUTE_finalize(
        ST_ENTITY_ATTRIBUTE* self);
                        
NDDSUSERDllExport
void ST_ENTITY_ATTRIBUTE_finalize_ex(
        ST_ENTITY_ATTRIBUTE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool ST_ENTITY_ATTRIBUTE_copy(
        ST_ENTITY_ATTRIBUTE* dst,
        const ST_ENTITY_ATTRIBUTE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *ST_MISSILE_DATATYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct ST_MISSILE_DATASeq;

#ifndef NDDS_STANDALONE_TYPE
    class ST_MISSILE_DATATypeSupport;
    class ST_MISSILE_DATADataWriter;
    class ST_MISSILE_DATADataReader;
#endif

#endif

            
    
class ST_MISSILE_DATA                                        
{
public:            
#ifdef __cplusplus
    typedef struct ST_MISSILE_DATASeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef ST_MISSILE_DATATypeSupport TypeSupport;
    typedef ST_MISSILE_DATADataWriter DataWriter;
    typedef ST_MISSILE_DATADataReader DataReader;
#endif

#endif
    
    DDS_Double  nMissileType;

    DDS_Double  nMissileCategory;

    DDS_Double  dWeight;

    DDS_Double  dDamage;

    DDS_Double  dSpeed;

    DDS_Double  dTurnRate;

    DDS_Double  dSeekerAngle;

    DDS_Double  dSeekerRange;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* ST_MISSILE_DATA_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(ST_MISSILE_DATASeq, ST_MISSILE_DATA);
        
NDDSUSERDllExport
RTIBool ST_MISSILE_DATA_initialize(
        ST_MISSILE_DATA* self);
        
NDDSUSERDllExport
RTIBool ST_MISSILE_DATA_initialize_ex(
        ST_MISSILE_DATA* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void ST_MISSILE_DATA_finalize(
        ST_MISSILE_DATA* self);
                        
NDDSUSERDllExport
void ST_MISSILE_DATA_finalize_ex(
        ST_MISSILE_DATA* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool ST_MISSILE_DATA_copy(
        ST_MISSILE_DATA* dst,
        const ST_MISSILE_DATA* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *ST_AMMUNITION_DATATYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct ST_AMMUNITION_DATASeq;

#ifndef NDDS_STANDALONE_TYPE
    class ST_AMMUNITION_DATATypeSupport;
    class ST_AMMUNITION_DATADataWriter;
    class ST_AMMUNITION_DATADataReader;
#endif

#endif

            
    
class ST_AMMUNITION_DATA                                        
{
public:            
#ifdef __cplusplus
    typedef struct ST_AMMUNITION_DATASeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef ST_AMMUNITION_DATATypeSupport TypeSupport;
    typedef ST_AMMUNITION_DATADataWriter DataWriter;
    typedef ST_AMMUNITION_DATADataReader DataReader;
#endif

#endif
    
    DDS_Short  nAmmunitionType;

    DDS_Short  nAmmunitionCategory;

    DDS_Double  dWeight;

    DDS_Double  dMuzzleVelocity;

    DDS_Short  nSimulatorManagementCommand;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* ST_AMMUNITION_DATA_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(ST_AMMUNITION_DATASeq, ST_AMMUNITION_DATA);
        
NDDSUSERDllExport
RTIBool ST_AMMUNITION_DATA_initialize(
        ST_AMMUNITION_DATA* self);
        
NDDSUSERDllExport
RTIBool ST_AMMUNITION_DATA_initialize_ex(
        ST_AMMUNITION_DATA* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void ST_AMMUNITION_DATA_finalize(
        ST_AMMUNITION_DATA* self);
                        
NDDSUSERDllExport
void ST_AMMUNITION_DATA_finalize_ex(
        ST_AMMUNITION_DATA* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool ST_AMMUNITION_DATA_copy(
        ST_AMMUNITION_DATA* dst,
        const ST_AMMUNITION_DATA* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKSeq;

#ifndef NDDS_STANDALONE_TYPE
    class SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKTypeSupport;
    class SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKDataWriter;
    class SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKDataReader;
#endif

#endif

            
    
class SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK                                        
{
public:            
#ifdef __cplusplus
    typedef struct SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKTypeSupport TypeSupport;
    typedef SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKDataWriter DataWriter;
    typedef SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKDataReader DataReader;
#endif

#endif
    
    DDS_Short  nSimulatorID;

    DDS_Short  nSimulatorManagementCommand;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKSeq, SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK);
        
NDDSUSERDllExport
RTIBool SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_initialize(
        SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK* self);
        
NDDSUSERDllExport
RTIBool SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_initialize_ex(
        SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_finalize(
        SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK* self);
                        
NDDSUSERDllExport
void SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_finalize_ex(
        SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_copy(
        SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK* dst,
        const SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SIM_SC_SIMULATOR_STATUS_REPORTTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct SIM_SC_SIMULATOR_STATUS_REPORTSeq;

#ifndef NDDS_STANDALONE_TYPE
    class SIM_SC_SIMULATOR_STATUS_REPORTTypeSupport;
    class SIM_SC_SIMULATOR_STATUS_REPORTDataWriter;
    class SIM_SC_SIMULATOR_STATUS_REPORTDataReader;
#endif

#endif

            
    
class SIM_SC_SIMULATOR_STATUS_REPORT                                        
{
public:            
#ifdef __cplusplus
    typedef struct SIM_SC_SIMULATOR_STATUS_REPORTSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef SIM_SC_SIMULATOR_STATUS_REPORTTypeSupport TypeSupport;
    typedef SIM_SC_SIMULATOR_STATUS_REPORTDataWriter DataWriter;
    typedef SIM_SC_SIMULATOR_STATUS_REPORTDataReader DataReader;
#endif

#endif
    
    DDS_Short  nSimulatorID;

    DDS_Short  nSimulatorStatus;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SIM_SC_SIMULATOR_STATUS_REPORT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SIM_SC_SIMULATOR_STATUS_REPORTSeq, SIM_SC_SIMULATOR_STATUS_REPORT);
        
NDDSUSERDllExport
RTIBool SIM_SC_SIMULATOR_STATUS_REPORT_initialize(
        SIM_SC_SIMULATOR_STATUS_REPORT* self);
        
NDDSUSERDllExport
RTIBool SIM_SC_SIMULATOR_STATUS_REPORT_initialize_ex(
        SIM_SC_SIMULATOR_STATUS_REPORT* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void SIM_SC_SIMULATOR_STATUS_REPORT_finalize(
        SIM_SC_SIMULATOR_STATUS_REPORT* self);
                        
NDDSUSERDllExport
void SIM_SC_SIMULATOR_STATUS_REPORT_finalize_ex(
        SIM_SC_SIMULATOR_STATUS_REPORT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SIM_SC_SIMULATOR_STATUS_REPORT_copy(
        SIM_SC_SIMULATOR_STATUS_REPORT* dst,
        const SIM_SC_SIMULATOR_STATUS_REPORT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SC_SER_LINK_CONNECTION_COMMANDTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct SC_SER_LINK_CONNECTION_COMMANDSeq;

#ifndef NDDS_STANDALONE_TYPE
    class SC_SER_LINK_CONNECTION_COMMANDTypeSupport;
    class SC_SER_LINK_CONNECTION_COMMANDDataWriter;
    class SC_SER_LINK_CONNECTION_COMMANDDataReader;
#endif

#endif

            
    
class SC_SER_LINK_CONNECTION_COMMAND                                        
{
public:            
#ifdef __cplusplus
    typedef struct SC_SER_LINK_CONNECTION_COMMANDSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef SC_SER_LINK_CONNECTION_COMMANDTypeSupport TypeSupport;
    typedef SC_SER_LINK_CONNECTION_COMMANDDataWriter DataWriter;
    typedef SC_SER_LINK_CONNECTION_COMMANDDataReader DataReader;
#endif

#endif
    
    DDS_Short  nLinkConnectionCommand;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SC_SER_LINK_CONNECTION_COMMAND_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SC_SER_LINK_CONNECTION_COMMANDSeq, SC_SER_LINK_CONNECTION_COMMAND);
        
NDDSUSERDllExport
RTIBool SC_SER_LINK_CONNECTION_COMMAND_initialize(
        SC_SER_LINK_CONNECTION_COMMAND* self);
        
NDDSUSERDllExport
RTIBool SC_SER_LINK_CONNECTION_COMMAND_initialize_ex(
        SC_SER_LINK_CONNECTION_COMMAND* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void SC_SER_LINK_CONNECTION_COMMAND_finalize(
        SC_SER_LINK_CONNECTION_COMMAND* self);
                        
NDDSUSERDllExport
void SC_SER_LINK_CONNECTION_COMMAND_finalize_ex(
        SC_SER_LINK_CONNECTION_COMMAND* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SC_SER_LINK_CONNECTION_COMMAND_copy(
        SC_SER_LINK_CONNECTION_COMMAND* dst,
        const SC_SER_LINK_CONNECTION_COMMAND* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SER_SC_LINK_CONNECTION_COMMAND_ACKTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct SER_SC_LINK_CONNECTION_COMMAND_ACKSeq;

#ifndef NDDS_STANDALONE_TYPE
    class SER_SC_LINK_CONNECTION_COMMAND_ACKTypeSupport;
    class SER_SC_LINK_CONNECTION_COMMAND_ACKDataWriter;
    class SER_SC_LINK_CONNECTION_COMMAND_ACKDataReader;
#endif

#endif

            
    
class SER_SC_LINK_CONNECTION_COMMAND_ACK                                        
{
public:            
#ifdef __cplusplus
    typedef struct SER_SC_LINK_CONNECTION_COMMAND_ACKSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef SER_SC_LINK_CONNECTION_COMMAND_ACKTypeSupport TypeSupport;
    typedef SER_SC_LINK_CONNECTION_COMMAND_ACKDataWriter DataWriter;
    typedef SER_SC_LINK_CONNECTION_COMMAND_ACKDataReader DataReader;
#endif

#endif
    
    DDS_Short  nLinkConnectionCommand;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SER_SC_LINK_CONNECTION_COMMAND_ACK_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SER_SC_LINK_CONNECTION_COMMAND_ACKSeq, SER_SC_LINK_CONNECTION_COMMAND_ACK);
        
NDDSUSERDllExport
RTIBool SER_SC_LINK_CONNECTION_COMMAND_ACK_initialize(
        SER_SC_LINK_CONNECTION_COMMAND_ACK* self);
        
NDDSUSERDllExport
RTIBool SER_SC_LINK_CONNECTION_COMMAND_ACK_initialize_ex(
        SER_SC_LINK_CONNECTION_COMMAND_ACK* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void SER_SC_LINK_CONNECTION_COMMAND_ACK_finalize(
        SER_SC_LINK_CONNECTION_COMMAND_ACK* self);
                        
NDDSUSERDllExport
void SER_SC_LINK_CONNECTION_COMMAND_ACK_finalize_ex(
        SER_SC_LINK_CONNECTION_COMMAND_ACK* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SER_SC_LINK_CONNECTION_COMMAND_ACK_copy(
        SER_SC_LINK_CONNECTION_COMMAND_ACK* dst,
        const SER_SC_LINK_CONNECTION_COMMAND_ACK* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SC_SIM_SIMULATION_MANAGEMENT_COMMANDTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct SC_SIM_SIMULATION_MANAGEMENT_COMMANDSeq;

#ifndef NDDS_STANDALONE_TYPE
    class SC_SIM_SIMULATION_MANAGEMENT_COMMANDTypeSupport;
    class SC_SIM_SIMULATION_MANAGEMENT_COMMANDDataWriter;
    class SC_SIM_SIMULATION_MANAGEMENT_COMMANDDataReader;
#endif

#endif

            
    
class SC_SIM_SIMULATION_MANAGEMENT_COMMAND                                        
{
public:            
#ifdef __cplusplus
    typedef struct SC_SIM_SIMULATION_MANAGEMENT_COMMANDSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef SC_SIM_SIMULATION_MANAGEMENT_COMMANDTypeSupport TypeSupport;
    typedef SC_SIM_SIMULATION_MANAGEMENT_COMMANDDataWriter DataWriter;
    typedef SC_SIM_SIMULATION_MANAGEMENT_COMMANDDataReader DataReader;
#endif

#endif
    
    DDS_Short  nSimulationManagementCommand;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SC_SIM_SIMULATION_MANAGEMENT_COMMAND_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SC_SIM_SIMULATION_MANAGEMENT_COMMANDSeq, SC_SIM_SIMULATION_MANAGEMENT_COMMAND);
        
NDDSUSERDllExport
RTIBool SC_SIM_SIMULATION_MANAGEMENT_COMMAND_initialize(
        SC_SIM_SIMULATION_MANAGEMENT_COMMAND* self);
        
NDDSUSERDllExport
RTIBool SC_SIM_SIMULATION_MANAGEMENT_COMMAND_initialize_ex(
        SC_SIM_SIMULATION_MANAGEMENT_COMMAND* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void SC_SIM_SIMULATION_MANAGEMENT_COMMAND_finalize(
        SC_SIM_SIMULATION_MANAGEMENT_COMMAND* self);
                        
NDDSUSERDllExport
void SC_SIM_SIMULATION_MANAGEMENT_COMMAND_finalize_ex(
        SC_SIM_SIMULATION_MANAGEMENT_COMMAND* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SC_SIM_SIMULATION_MANAGEMENT_COMMAND_copy(
        SC_SIM_SIMULATION_MANAGEMENT_COMMAND* dst,
        const SC_SIM_SIMULATION_MANAGEMENT_COMMAND* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKSeq;

#ifndef NDDS_STANDALONE_TYPE
    class SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKTypeSupport;
    class SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKDataWriter;
    class SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKDataReader;
#endif

#endif

            
    
class SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK                                        
{
public:            
#ifdef __cplusplus
    typedef struct SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKTypeSupport TypeSupport;
    typedef SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKDataWriter DataWriter;
    typedef SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKDataReader DataReader;
#endif

#endif
    
    DDS_Short  nSimulatorID;

    DDS_Short  nSimulationManagementCommand;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKSeq, SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK);
        
NDDSUSERDllExport
RTIBool SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_initialize(
        SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK* self);
        
NDDSUSERDllExport
RTIBool SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_initialize_ex(
        SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_finalize(
        SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK* self);
                        
NDDSUSERDllExport
void SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_finalize_ex(
        SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_copy(
        SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK* dst,
        const SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SC_SIM_PARAMETER_DISTRIBUTION_COMMANDTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct SC_SIM_PARAMETER_DISTRIBUTION_COMMANDSeq;

#ifndef NDDS_STANDALONE_TYPE
    class SC_SIM_PARAMETER_DISTRIBUTION_COMMANDTypeSupport;
    class SC_SIM_PARAMETER_DISTRIBUTION_COMMANDDataWriter;
    class SC_SIM_PARAMETER_DISTRIBUTION_COMMANDDataReader;
#endif

#endif

            
    
class SC_SIM_PARAMETER_DISTRIBUTION_COMMAND                                        
{
public:            
#ifdef __cplusplus
    typedef struct SC_SIM_PARAMETER_DISTRIBUTION_COMMANDSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef SC_SIM_PARAMETER_DISTRIBUTION_COMMANDTypeSupport TypeSupport;
    typedef SC_SIM_PARAMETER_DISTRIBUTION_COMMANDDataWriter DataWriter;
    typedef SC_SIM_PARAMETER_DISTRIBUTION_COMMANDDataReader DataReader;
#endif

#endif
    
    DDS_Short  eParameterDistributionCommand;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SC_SIM_PARAMETER_DISTRIBUTION_COMMANDSeq, SC_SIM_PARAMETER_DISTRIBUTION_COMMAND);
        
NDDSUSERDllExport
RTIBool SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_initialize(
        SC_SIM_PARAMETER_DISTRIBUTION_COMMAND* self);
        
NDDSUSERDllExport
RTIBool SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_initialize_ex(
        SC_SIM_PARAMETER_DISTRIBUTION_COMMAND* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_finalize(
        SC_SIM_PARAMETER_DISTRIBUTION_COMMAND* self);
                        
NDDSUSERDllExport
void SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_finalize_ex(
        SC_SIM_PARAMETER_DISTRIBUTION_COMMAND* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_copy(
        SC_SIM_PARAMETER_DISTRIBUTION_COMMAND* dst,
        const SC_SIM_PARAMETER_DISTRIBUTION_COMMAND* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKSeq;

#ifndef NDDS_STANDALONE_TYPE
    class SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKTypeSupport;
    class SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKDataWriter;
    class SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKDataReader;
#endif

#endif

            
    
class SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK                                        
{
public:            
#ifdef __cplusplus
    typedef struct SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKTypeSupport TypeSupport;
    typedef SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKDataWriter DataWriter;
    typedef SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKDataReader DataReader;
#endif

#endif
    
    DDS_Short  eParameterDistributionCommand;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKSeq, SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK);
        
NDDSUSERDllExport
RTIBool SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_initialize(
        SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK* self);
        
NDDSUSERDllExport
RTIBool SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_initialize_ex(
        SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_finalize(
        SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK* self);
                        
NDDSUSERDllExport
void SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_finalize_ex(
        SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_copy(
        SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK* dst,
        const SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SC_SIM_SIMULATOR_PARAMETERTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct SC_SIM_SIMULATOR_PARAMETERSeq;

#ifndef NDDS_STANDALONE_TYPE
    class SC_SIM_SIMULATOR_PARAMETERTypeSupport;
    class SC_SIM_SIMULATOR_PARAMETERDataWriter;
    class SC_SIM_SIMULATOR_PARAMETERDataReader;
#endif

#endif

            
    
class SC_SIM_SIMULATOR_PARAMETER                                        
{
public:            
#ifdef __cplusplus
    typedef struct SC_SIM_SIMULATOR_PARAMETERSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef SC_SIM_SIMULATOR_PARAMETERTypeSupport TypeSupport;
    typedef SC_SIM_SIMULATOR_PARAMETERDataWriter DataWriter;
    typedef SC_SIM_SIMULATOR_PARAMETERDataReader DataReader;
#endif

#endif
    
    DDS_Char  chParameterXML[2048];

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SC_SIM_SIMULATOR_PARAMETER_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SC_SIM_SIMULATOR_PARAMETERSeq, SC_SIM_SIMULATOR_PARAMETER);
        
NDDSUSERDllExport
RTIBool SC_SIM_SIMULATOR_PARAMETER_initialize(
        SC_SIM_SIMULATOR_PARAMETER* self);
        
NDDSUSERDllExport
RTIBool SC_SIM_SIMULATOR_PARAMETER_initialize_ex(
        SC_SIM_SIMULATOR_PARAMETER* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void SC_SIM_SIMULATOR_PARAMETER_finalize(
        SC_SIM_SIMULATOR_PARAMETER* self);
                        
NDDSUSERDllExport
void SC_SIM_SIMULATOR_PARAMETER_finalize_ex(
        SC_SIM_SIMULATOR_PARAMETER* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SC_SIM_SIMULATOR_PARAMETER_copy(
        SC_SIM_SIMULATOR_PARAMETER* dst,
        const SC_SIM_SIMULATOR_PARAMETER* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SIM_SC_SIMULATOR_PARAMETER_ACKTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct SIM_SC_SIMULATOR_PARAMETER_ACKSeq;

#ifndef NDDS_STANDALONE_TYPE
    class SIM_SC_SIMULATOR_PARAMETER_ACKTypeSupport;
    class SIM_SC_SIMULATOR_PARAMETER_ACKDataWriter;
    class SIM_SC_SIMULATOR_PARAMETER_ACKDataReader;
#endif

#endif

            
    
class SIM_SC_SIMULATOR_PARAMETER_ACK                                        
{
public:            
#ifdef __cplusplus
    typedef struct SIM_SC_SIMULATOR_PARAMETER_ACKSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef SIM_SC_SIMULATOR_PARAMETER_ACKTypeSupport TypeSupport;
    typedef SIM_SC_SIMULATOR_PARAMETER_ACKDataWriter DataWriter;
    typedef SIM_SC_SIMULATOR_PARAMETER_ACKDataReader DataReader;
#endif

#endif
    
    DDS_Short  nSimulatorID;

    DDS_Short  nSimulatorParameterAckState;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SIM_SC_SIMULATOR_PARAMETER_ACK_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SIM_SC_SIMULATOR_PARAMETER_ACKSeq, SIM_SC_SIMULATOR_PARAMETER_ACK);
        
NDDSUSERDllExport
RTIBool SIM_SC_SIMULATOR_PARAMETER_ACK_initialize(
        SIM_SC_SIMULATOR_PARAMETER_ACK* self);
        
NDDSUSERDllExport
RTIBool SIM_SC_SIMULATOR_PARAMETER_ACK_initialize_ex(
        SIM_SC_SIMULATOR_PARAMETER_ACK* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void SIM_SC_SIMULATOR_PARAMETER_ACK_finalize(
        SIM_SC_SIMULATOR_PARAMETER_ACK* self);
                        
NDDSUSERDllExport
void SIM_SC_SIMULATOR_PARAMETER_ACK_finalize_ex(
        SIM_SC_SIMULATOR_PARAMETER_ACK* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SIM_SC_SIMULATOR_PARAMETER_ACK_copy(
        SIM_SC_SIMULATOR_PARAMETER_ACK* dst,
        const SIM_SC_SIMULATOR_PARAMETER_ACK* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SC_SIM_ENVIRONMENTTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct SC_SIM_ENVIRONMENTSeq;

#ifndef NDDS_STANDALONE_TYPE
    class SC_SIM_ENVIRONMENTTypeSupport;
    class SC_SIM_ENVIRONMENTDataWriter;
    class SC_SIM_ENVIRONMENTDataReader;
#endif

#endif

            
    
class SC_SIM_ENVIRONMENT                                        
{
public:            
#ifdef __cplusplus
    typedef struct SC_SIM_ENVIRONMENTSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef SC_SIM_ENVIRONMENTTypeSupport TypeSupport;
    typedef SC_SIM_ENVIRONMENTDataWriter DataWriter;
    typedef SC_SIM_ENVIRONMENTDataReader DataReader;
#endif

#endif
    
    DDS_Short  nWeather;

    DDS_Double  dTemparature;

    DDS_Double  dAirPressure;

    DDS_Double  dHumidity;

    DDS_Double  dVisibility;

    DDS_Double  dWindDirection;

    DDS_Double  dWindSpeed;

    DDS_Double  dWaterDirection;

    DDS_Double  dWaterSpeed;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SC_SIM_ENVIRONMENT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SC_SIM_ENVIRONMENTSeq, SC_SIM_ENVIRONMENT);
        
NDDSUSERDllExport
RTIBool SC_SIM_ENVIRONMENT_initialize(
        SC_SIM_ENVIRONMENT* self);
        
NDDSUSERDllExport
RTIBool SC_SIM_ENVIRONMENT_initialize_ex(
        SC_SIM_ENVIRONMENT* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void SC_SIM_ENVIRONMENT_finalize(
        SC_SIM_ENVIRONMENT* self);
                        
NDDSUSERDllExport
void SC_SIM_ENVIRONMENT_finalize_ex(
        SC_SIM_ENVIRONMENT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SC_SIM_ENVIRONMENT_copy(
        SC_SIM_ENVIRONMENT* dst,
        const SC_SIM_ENVIRONMENT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SC_SIM_ENTITYTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct SC_SIM_ENTITYSeq;

#ifndef NDDS_STANDALONE_TYPE
    class SC_SIM_ENTITYTypeSupport;
    class SC_SIM_ENTITYDataWriter;
    class SC_SIM_ENTITYDataReader;
#endif

#endif

            
    
class SC_SIM_ENTITY                                        
{
public:            
#ifdef __cplusplus
    typedef struct SC_SIM_ENTITYSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef SC_SIM_ENTITYTypeSupport TypeSupport;
    typedef SC_SIM_ENTITYDataWriter DataWriter;
    typedef SC_SIM_ENTITYDataReader DataReader;
#endif

#endif
    
    DDS_UnsignedShort  unEntityID;

    ST_ENTITY_INFO  stEntityInfo;

    ST_ENTITY_ATTRIBUTE  stEntityAttribute;

    ST_ENTITY_STATE  stEntityState;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SC_SIM_ENTITY_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SC_SIM_ENTITYSeq, SC_SIM_ENTITY);
        
NDDSUSERDllExport
RTIBool SC_SIM_ENTITY_initialize(
        SC_SIM_ENTITY* self);
        
NDDSUSERDllExport
RTIBool SC_SIM_ENTITY_initialize_ex(
        SC_SIM_ENTITY* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void SC_SIM_ENTITY_finalize(
        SC_SIM_ENTITY* self);
                        
NDDSUSERDllExport
void SC_SIM_ENTITY_finalize_ex(
        SC_SIM_ENTITY* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SC_SIM_ENTITY_copy(
        SC_SIM_ENTITY* dst,
        const SC_SIM_ENTITY* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SC_SIM_ENTITY_STATETYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct SC_SIM_ENTITY_STATESeq;

#ifndef NDDS_STANDALONE_TYPE
    class SC_SIM_ENTITY_STATETypeSupport;
    class SC_SIM_ENTITY_STATEDataWriter;
    class SC_SIM_ENTITY_STATEDataReader;
#endif

#endif

            
    
class SC_SIM_ENTITY_STATE                                        
{
public:            
#ifdef __cplusplus
    typedef struct SC_SIM_ENTITY_STATESeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef SC_SIM_ENTITY_STATETypeSupport TypeSupport;
    typedef SC_SIM_ENTITY_STATEDataWriter DataWriter;
    typedef SC_SIM_ENTITY_STATEDataReader DataReader;
#endif

#endif
    
    DDS_UnsignedShort  unEntityID;

    ST_ENTITY_STATE  stEntityState;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SC_SIM_ENTITY_STATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SC_SIM_ENTITY_STATESeq, SC_SIM_ENTITY_STATE);
        
NDDSUSERDllExport
RTIBool SC_SIM_ENTITY_STATE_initialize(
        SC_SIM_ENTITY_STATE* self);
        
NDDSUSERDllExport
RTIBool SC_SIM_ENTITY_STATE_initialize_ex(
        SC_SIM_ENTITY_STATE* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void SC_SIM_ENTITY_STATE_finalize(
        SC_SIM_ENTITY_STATE* self);
                        
NDDSUSERDllExport
void SC_SIM_ENTITY_STATE_finalize_ex(
        SC_SIM_ENTITY_STATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SC_SIM_ENTITY_STATE_copy(
        SC_SIM_ENTITY_STATE* dst,
        const SC_SIM_ENTITY_STATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SC_SIM_OWNSHIPTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct SC_SIM_OWNSHIPSeq;

#ifndef NDDS_STANDALONE_TYPE
    class SC_SIM_OWNSHIPTypeSupport;
    class SC_SIM_OWNSHIPDataWriter;
    class SC_SIM_OWNSHIPDataReader;
#endif

#endif

            
    
class SC_SIM_OWNSHIP                                        
{
public:            
#ifdef __cplusplus
    typedef struct SC_SIM_OWNSHIPSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef SC_SIM_OWNSHIPTypeSupport TypeSupport;
    typedef SC_SIM_OWNSHIPDataWriter DataWriter;
    typedef SC_SIM_OWNSHIPDataReader DataReader;
#endif

#endif
    
    DDS_UnsignedShort  unEntityID;

    ST_ENTITY_INFO  stEntityInfo;

    ST_ENTITY_ATTRIBUTE  stEntityAttribute;

    ST_ENTITY_STATE  stEntityState;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SC_SIM_OWNSHIP_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SC_SIM_OWNSHIPSeq, SC_SIM_OWNSHIP);
        
NDDSUSERDllExport
RTIBool SC_SIM_OWNSHIP_initialize(
        SC_SIM_OWNSHIP* self);
        
NDDSUSERDllExport
RTIBool SC_SIM_OWNSHIP_initialize_ex(
        SC_SIM_OWNSHIP* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void SC_SIM_OWNSHIP_finalize(
        SC_SIM_OWNSHIP* self);
                        
NDDSUSERDllExport
void SC_SIM_OWNSHIP_finalize_ex(
        SC_SIM_OWNSHIP* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SC_SIM_OWNSHIP_copy(
        SC_SIM_OWNSHIP* dst,
        const SC_SIM_OWNSHIP* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SC_SIM_OWNSHIP_STATETYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct SC_SIM_OWNSHIP_STATESeq;

#ifndef NDDS_STANDALONE_TYPE
    class SC_SIM_OWNSHIP_STATETypeSupport;
    class SC_SIM_OWNSHIP_STATEDataWriter;
    class SC_SIM_OWNSHIP_STATEDataReader;
#endif

#endif

            
    
class SC_SIM_OWNSHIP_STATE                                        
{
public:            
#ifdef __cplusplus
    typedef struct SC_SIM_OWNSHIP_STATESeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef SC_SIM_OWNSHIP_STATETypeSupport TypeSupport;
    typedef SC_SIM_OWNSHIP_STATEDataWriter DataWriter;
    typedef SC_SIM_OWNSHIP_STATEDataReader DataReader;
#endif

#endif
    
    DDS_UnsignedShort  unEntityID;

    ST_ENTITY_STATE  stEntityState;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SC_SIM_OWNSHIP_STATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SC_SIM_OWNSHIP_STATESeq, SC_SIM_OWNSHIP_STATE);
        
NDDSUSERDllExport
RTIBool SC_SIM_OWNSHIP_STATE_initialize(
        SC_SIM_OWNSHIP_STATE* self);
        
NDDSUSERDllExport
RTIBool SC_SIM_OWNSHIP_STATE_initialize_ex(
        SC_SIM_OWNSHIP_STATE* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void SC_SIM_OWNSHIP_STATE_finalize(
        SC_SIM_OWNSHIP_STATE* self);
                        
NDDSUSERDllExport
void SC_SIM_OWNSHIP_STATE_finalize_ex(
        SC_SIM_OWNSHIP_STATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SC_SIM_OWNSHIP_STATE_copy(
        SC_SIM_OWNSHIP_STATE* dst,
        const SC_SIM_OWNSHIP_STATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SIM_SC_MISSILE_CREATIONTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct SIM_SC_MISSILE_CREATIONSeq;

#ifndef NDDS_STANDALONE_TYPE
    class SIM_SC_MISSILE_CREATIONTypeSupport;
    class SIM_SC_MISSILE_CREATIONDataWriter;
    class SIM_SC_MISSILE_CREATIONDataReader;
#endif

#endif

            
    
class SIM_SC_MISSILE_CREATION                                        
{
public:            
#ifdef __cplusplus
    typedef struct SIM_SC_MISSILE_CREATIONSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef SIM_SC_MISSILE_CREATIONTypeSupport TypeSupport;
    typedef SIM_SC_MISSILE_CREATIONDataWriter DataWriter;
    typedef SIM_SC_MISSILE_CREATIONDataReader DataReader;
#endif

#endif
    
    DDS_Long  lTimeToFire;

    ST_MISSILE_DATA  stMissileData;

    ST_POSITION  stWaypointCoordinate[8];

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SIM_SC_MISSILE_CREATION_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SIM_SC_MISSILE_CREATIONSeq, SIM_SC_MISSILE_CREATION);
        
NDDSUSERDllExport
RTIBool SIM_SC_MISSILE_CREATION_initialize(
        SIM_SC_MISSILE_CREATION* self);
        
NDDSUSERDllExport
RTIBool SIM_SC_MISSILE_CREATION_initialize_ex(
        SIM_SC_MISSILE_CREATION* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void SIM_SC_MISSILE_CREATION_finalize(
        SIM_SC_MISSILE_CREATION* self);
                        
NDDSUSERDllExport
void SIM_SC_MISSILE_CREATION_finalize_ex(
        SIM_SC_MISSILE_CREATION* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SIM_SC_MISSILE_CREATION_copy(
        SIM_SC_MISSILE_CREATION* dst,
        const SIM_SC_MISSILE_CREATION* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SIM_SC_SHELL_CREATIONTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct SIM_SC_SHELL_CREATIONSeq;

#ifndef NDDS_STANDALONE_TYPE
    class SIM_SC_SHELL_CREATIONTypeSupport;
    class SIM_SC_SHELL_CREATIONDataWriter;
    class SIM_SC_SHELL_CREATIONDataReader;
#endif

#endif

            
    
class SIM_SC_SHELL_CREATION                                        
{
public:            
#ifdef __cplusplus
    typedef struct SIM_SC_SHELL_CREATIONSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef SIM_SC_SHELL_CREATIONTypeSupport TypeSupport;
    typedef SIM_SC_SHELL_CREATIONDataWriter DataWriter;
    typedef SIM_SC_SHELL_CREATIONDataReader DataReader;
#endif

#endif
    
    DDS_Long  lTimeToFire;

    ST_AMMUNITION_DATA  stAmmunitionData;

    DDS_Double  dBearing;

    DDS_Double  dElevation;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SIM_SC_SHELL_CREATION_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SIM_SC_SHELL_CREATIONSeq, SIM_SC_SHELL_CREATION);
        
NDDSUSERDllExport
RTIBool SIM_SC_SHELL_CREATION_initialize(
        SIM_SC_SHELL_CREATION* self);
        
NDDSUSERDllExport
RTIBool SIM_SC_SHELL_CREATION_initialize_ex(
        SIM_SC_SHELL_CREATION* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void SIM_SC_SHELL_CREATION_finalize(
        SIM_SC_SHELL_CREATION* self);
                        
NDDSUSERDllExport
void SIM_SC_SHELL_CREATION_finalize_ex(
        SIM_SC_SHELL_CREATION* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SIM_SC_SHELL_CREATION_copy(
        SIM_SC_SHELL_CREATION* dst,
        const SIM_SC_SHELL_CREATION* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* rmOPV_Protocol_139685288_h */
