
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_TDSRMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef DDS_TDSRMMI_1808377665_h
#define DDS_TDSRMMI_1808377665_h

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

        
extern const char *DMSG_TDSR_FIELDSETRESULTTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TDSR_FIELDSETRESULT
{
    DDS_Char  byFieldCategory;
    DDS_Char  byFieldConfig;
    DDS_Char  bySerialNumber;
    DDS_Double  dStartBearing;
    DDS_Double  dEndBearing;
    DDS_Double  dStartDistance;
    DDS_Double  dEndDistance;
    DDS_Double  dStartAltitude;
    DDS_Double  dEndAltitude;
    DDS_Char  byStandardPoint;

} DMSG_TDSR_FIELDSETRESULT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TDSR_FIELDSETRESULT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TDSR_FIELDSETRESULTSeq, DMSG_TDSR_FIELDSETRESULT);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_FIELDSETRESULT_initialize(
        DMSG_TDSR_FIELDSETRESULT* self);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_FIELDSETRESULT_initialize_ex(
        DMSG_TDSR_FIELDSETRESULT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TDSR_FIELDSETRESULT_finalize(
        DMSG_TDSR_FIELDSETRESULT* self);
                        
NDDSUSERDllExport
void DMSG_TDSR_FIELDSETRESULT_finalize_ex(
        DMSG_TDSR_FIELDSETRESULT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_FIELDSETRESULT_copy(
        DMSG_TDSR_FIELDSETRESULT* dst,
        const DMSG_TDSR_FIELDSETRESULT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TDSR_JAMMINGTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TDSR_JAMMING
{
    DDS_Double  dTime;
    DDS_Char  ReceiveRFChannel;
    DDS_Double  dBearing;
    DDS_Double  dAltitude;

} DMSG_TDSR_JAMMING;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TDSR_JAMMING_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TDSR_JAMMINGSeq, DMSG_TDSR_JAMMING);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_JAMMING_initialize(
        DMSG_TDSR_JAMMING* self);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_JAMMING_initialize_ex(
        DMSG_TDSR_JAMMING* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TDSR_JAMMING_finalize(
        DMSG_TDSR_JAMMING* self);
                        
NDDSUSERDllExport
void DMSG_TDSR_JAMMING_finalize_ex(
        DMSG_TDSR_JAMMING* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_JAMMING_copy(
        DMSG_TDSR_JAMMING* dst,
        const DMSG_TDSR_JAMMING* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TDSR_STATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TDSR_STATE
{
    DDS_Char  StateInfo;
    DDS_Char  ValidState;
    DDS_Char  BattleShort;
    DDS_Char  PlatformControl;
    DDS_Char  BDriveControl;
    DDS_Long  BDriveAngle;
    DDS_Char  TransmitterControl;
    DDS_Char  DuctingMode;
    DDS_Char  RadarSlience;
    DDS_Char  RFChannel1State;
    DDS_Char  RFChannel2State;
    DDS_Char  RFChannel3State;
    DDS_Char  RFChannel4State;
    DDS_Char  RFChannel5State;
    DDS_Char  RFChannel6State;
    DDS_Char  RFChannel7State;
    DDS_Char  RFChannel8State;
    DDS_Char  RFMode;
    DDS_Char  VideoMode;
    DDS_Char  VideoFilter;
    DDS_Char  VideoSTCType;
    DDS_Char  VideoThreshold;

} DMSG_TDSR_STATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TDSR_STATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TDSR_STATESeq, DMSG_TDSR_STATE);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_STATE_initialize(
        DMSG_TDSR_STATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_STATE_initialize_ex(
        DMSG_TDSR_STATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TDSR_STATE_finalize(
        DMSG_TDSR_STATE* self);
                        
NDDSUSERDllExport
void DMSG_TDSR_STATE_finalize_ex(
        DMSG_TDSR_STATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_STATE_copy(
        DMSG_TDSR_STATE* dst,
        const DMSG_TDSR_STATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TDSR_TARGETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TDSR_TARGET
{
    DDS_Long  nTarget_Number;
    DDS_Double  dSystem_Time;
    DDS_Char  Target_Category;
    DDS_Double  dPosX;
    DDS_Double  dPosY;
    DDS_Double  dPosZ;
    DDS_Double  dVelocityX;
    DDS_Double  dVelocityY;
    DDS_Double  dVelocityZ;
    DDS_Double  dRange_Accuracy;
    DDS_Double  dBearing_Accuracy;
    DDS_Double  dElevation_Accuracy;
    DDS_Char  Track_Phase;

} DMSG_TDSR_TARGET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TDSR_TARGET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TDSR_TARGETSeq, DMSG_TDSR_TARGET);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_TARGET_initialize(
        DMSG_TDSR_TARGET* self);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_TARGET_initialize_ex(
        DMSG_TDSR_TARGET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TDSR_TARGET_finalize(
        DMSG_TDSR_TARGET* self);
                        
NDDSUSERDllExport
void DMSG_TDSR_TARGET_finalize_ex(
        DMSG_TDSR_TARGET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_TARGET_copy(
        DMSG_TDSR_TARGET* dst,
        const DMSG_TDSR_TARGET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TDSR_BSCOPETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TDSR_BSCOPE
{
    DDS_Long  nTWS_ID;
    DDS_Char  cGreen[40000];

} DMSG_TDSR_BSCOPE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TDSR_BSCOPE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TDSR_BSCOPESeq, DMSG_TDSR_BSCOPE);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_BSCOPE_initialize(
        DMSG_TDSR_BSCOPE* self);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_BSCOPE_initialize_ex(
        DMSG_TDSR_BSCOPE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TDSR_BSCOPE_finalize(
        DMSG_TDSR_BSCOPE* self);
                        
NDDSUSERDllExport
void DMSG_TDSR_BSCOPE_finalize_ex(
        DMSG_TDSR_BSCOPE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_BSCOPE_copy(
        DMSG_TDSR_BSCOPE* dst,
        const DMSG_TDSR_BSCOPE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TDSR_COLUMNOFWATERTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TDSR_COLUMNOFWATER
{
    DDS_Long  nTWS_ID;
    DDS_Long  nID;
    DDS_Double  dDegree;
    DDS_Double  dRange;

} DMSG_TDSR_COLUMNOFWATER;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TDSR_COLUMNOFWATER_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TDSR_COLUMNOFWATERSeq, DMSG_TDSR_COLUMNOFWATER);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_COLUMNOFWATER_initialize(
        DMSG_TDSR_COLUMNOFWATER* self);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_COLUMNOFWATER_initialize_ex(
        DMSG_TDSR_COLUMNOFWATER* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TDSR_COLUMNOFWATER_finalize(
        DMSG_TDSR_COLUMNOFWATER* self);
                        
NDDSUSERDllExport
void DMSG_TDSR_COLUMNOFWATER_finalize_ex(
        DMSG_TDSR_COLUMNOFWATER* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_COLUMNOFWATER_copy(
        DMSG_TDSR_COLUMNOFWATER* dst,
        const DMSG_TDSR_COLUMNOFWATER* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TDSR_TWSTRACKINGTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TDSR_TWSTRACKING
{
    DDS_Long  nTWS_TrackingInfo;
    DDS_Long  nTarget_Number;
    DDS_Double  dSystem_Time;
    DDS_Char  cTarget_Category;
    DDS_Double  dPosX;
    DDS_Double  dPosY;
    DDS_Double  dPosZ;
    DDS_Double  dVelocityX;
    DDS_Double  dVelocityY;
    DDS_Double  dVelocityZ;
    DDS_Double  dRange_Accuracy;
    DDS_Double  dBearing_Accuracy;
    DDS_Double  dElevation_Accuracy;
    DDS_Char  cTrack_Phase;

} DMSG_TDSR_TWSTRACKING;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TDSR_TWSTRACKING_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TDSR_TWSTRACKINGSeq, DMSG_TDSR_TWSTRACKING);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_TWSTRACKING_initialize(
        DMSG_TDSR_TWSTRACKING* self);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_TWSTRACKING_initialize_ex(
        DMSG_TDSR_TWSTRACKING* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TDSR_TWSTRACKING_finalize(
        DMSG_TDSR_TWSTRACKING* self);
                        
NDDSUSERDllExport
void DMSG_TDSR_TWSTRACKING_finalize_ex(
        DMSG_TDSR_TWSTRACKING* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TDSR_TWSTRACKING_copy(
        DMSG_TDSR_TWSTRACKING* dst,
        const DMSG_TDSR_TWSTRACKING* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRANTENNACTRLTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRANTENNACTRL
{
    DDS_Char  PlatformControl;
    DDS_Char  BDriveControl;
    DDS_Long  nRequiredBearing;

} DMSG_HMI_TDSRANTENNACTRL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRANTENNACTRL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRANTENNACTRLSeq, DMSG_HMI_TDSRANTENNACTRL);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRANTENNACTRL_initialize(
        DMSG_HMI_TDSRANTENNACTRL* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRANTENNACTRL_initialize_ex(
        DMSG_HMI_TDSRANTENNACTRL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRANTENNACTRL_finalize(
        DMSG_HMI_TDSRANTENNACTRL* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRANTENNACTRL_finalize_ex(
        DMSG_HMI_TDSRANTENNACTRL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRANTENNACTRL_copy(
        DMSG_HMI_TDSRANTENNACTRL* dst,
        const DMSG_HMI_TDSRANTENNACTRL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRBATTLESHORTCMDTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRBATTLESHORTCMD
{
    DDS_Char  BattleShot;

} DMSG_HMI_TDSRBATTLESHORTCMD;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRBATTLESHORTCMD_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRBATTLESHORTCMDSeq, DMSG_HMI_TDSRBATTLESHORTCMD);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRBATTLESHORTCMD_initialize(
        DMSG_HMI_TDSRBATTLESHORTCMD* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRBATTLESHORTCMD_initialize_ex(
        DMSG_HMI_TDSRBATTLESHORTCMD* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRBATTLESHORTCMD_finalize(
        DMSG_HMI_TDSRBATTLESHORTCMD* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRBATTLESHORTCMD_finalize_ex(
        DMSG_HMI_TDSRBATTLESHORTCMD* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRBATTLESHORTCMD_copy(
        DMSG_HMI_TDSRBATTLESHORTCMD* dst,
        const DMSG_HMI_TDSRBATTLESHORTCMD* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRTRANSMITTERCTRLTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRTRANSMITTERCTRL
{
    DDS_Char  TransmitterControl;

} DMSG_HMI_TDSRTRANSMITTERCTRL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRTRANSMITTERCTRL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRTRANSMITTERCTRLSeq, DMSG_HMI_TDSRTRANSMITTERCTRL);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRTRANSMITTERCTRL_initialize(
        DMSG_HMI_TDSRTRANSMITTERCTRL* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRTRANSMITTERCTRL_initialize_ex(
        DMSG_HMI_TDSRTRANSMITTERCTRL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRTRANSMITTERCTRL_finalize(
        DMSG_HMI_TDSRTRANSMITTERCTRL* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRTRANSMITTERCTRL_finalize_ex(
        DMSG_HMI_TDSRTRANSMITTERCTRL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRTRANSMITTERCTRL_copy(
        DMSG_HMI_TDSRTRANSMITTERCTRL* dst,
        const DMSG_HMI_TDSRTRANSMITTERCTRL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_OSM_TDSRFIELDSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_OSM_TDSRFIELDSET
{
    DDS_Char  SiteCategory;
    DDS_UnsignedLong  nID;
    DDS_Char  OnOff;
    DDS_Char  SerialNumber;
    DDS_Double  dStartBearing;
    DDS_Double  dEndBearing;
    DDS_Double  dStartDistance;
    DDS_Double  dEndDistance;
    DDS_Double  dStartAltitude;
    DDS_Double  dEndAltitude;
    DDS_Char  StandardPoint;

} DMSG_OSM_TDSRFIELDSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_OSM_TDSRFIELDSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_OSM_TDSRFIELDSETSeq, DMSG_OSM_TDSRFIELDSET);
        
NDDSUSERDllExport
RTIBool DMSG_OSM_TDSRFIELDSET_initialize(
        DMSG_OSM_TDSRFIELDSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_OSM_TDSRFIELDSET_initialize_ex(
        DMSG_OSM_TDSRFIELDSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_OSM_TDSRFIELDSET_finalize(
        DMSG_OSM_TDSRFIELDSET* self);
                        
NDDSUSERDllExport
void DMSG_OSM_TDSRFIELDSET_finalize_ex(
        DMSG_OSM_TDSRFIELDSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_OSM_TDSRFIELDSET_copy(
        DMSG_OSM_TDSRFIELDSET* dst,
        const DMSG_OSM_TDSRFIELDSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRSURFACETRACKCTRLTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRSURFACETRACKCTRL
{
    DDS_Char  command;
    DDS_Long  nTrackNum;
    DDS_Double  dPosX;
    DDS_Double  dPosY;
    DDS_Double  dTimeValidity;

} DMSG_HMI_TDSRSURFACETRACKCTRL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRSURFACETRACKCTRL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRSURFACETRACKCTRLSeq, DMSG_HMI_TDSRSURFACETRACKCTRL);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRSURFACETRACKCTRL_initialize(
        DMSG_HMI_TDSRSURFACETRACKCTRL* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRSURFACETRACKCTRL_initialize_ex(
        DMSG_HMI_TDSRSURFACETRACKCTRL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRSURFACETRACKCTRL_finalize(
        DMSG_HMI_TDSRSURFACETRACKCTRL* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRSURFACETRACKCTRL_finalize_ex(
        DMSG_HMI_TDSRSURFACETRACKCTRL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRSURFACETRACKCTRL_copy(
        DMSG_HMI_TDSRSURFACETRACKCTRL* dst,
        const DMSG_HMI_TDSRSURFACETRACKCTRL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRRDRSILENCECTRLTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRRDRSILENCECTRL
{
    DDS_Char  cCommand;

} DMSG_HMI_TDSRRDRSILENCECTRL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRRDRSILENCECTRL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRRDRSILENCECTRLSeq, DMSG_HMI_TDSRRDRSILENCECTRL);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRRDRSILENCECTRL_initialize(
        DMSG_HMI_TDSRRDRSILENCECTRL* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRRDRSILENCECTRL_initialize_ex(
        DMSG_HMI_TDSRRDRSILENCECTRL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRRDRSILENCECTRL_finalize(
        DMSG_HMI_TDSRRDRSILENCECTRL* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRRDRSILENCECTRL_finalize_ex(
        DMSG_HMI_TDSRRDRSILENCECTRL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRRDRSILENCECTRL_copy(
        DMSG_HMI_TDSRRDRSILENCECTRL* dst,
        const DMSG_HMI_TDSRRDRSILENCECTRL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRSENDCHANNELSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRSENDCHANNELSET
{
    DDS_Char  FreqVariableSys;
    DDS_Char  ReceiveChannel;
    DDS_UnsignedShort  usSetRFChannel;

} DMSG_HMI_TDSRSENDCHANNELSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRSENDCHANNELSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRSENDCHANNELSETSeq, DMSG_HMI_TDSRSENDCHANNELSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRSENDCHANNELSET_initialize(
        DMSG_HMI_TDSRSENDCHANNELSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRSENDCHANNELSET_initialize_ex(
        DMSG_HMI_TDSRSENDCHANNELSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRSENDCHANNELSET_finalize(
        DMSG_HMI_TDSRSENDCHANNELSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRSENDCHANNELSET_finalize_ex(
        DMSG_HMI_TDSRSENDCHANNELSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRSENDCHANNELSET_copy(
        DMSG_HMI_TDSRSENDCHANNELSET* dst,
        const DMSG_HMI_TDSRSENDCHANNELSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRSENDRFMODETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRSENDRFMODE
{
    DDS_Char  RFMode;

} DMSG_HMI_TDSRSENDRFMODE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRSENDRFMODE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRSENDRFMODESeq, DMSG_HMI_TDSRSENDRFMODE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRSENDRFMODE_initialize(
        DMSG_HMI_TDSRSENDRFMODE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRSENDRFMODE_initialize_ex(
        DMSG_HMI_TDSRSENDRFMODE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRSENDRFMODE_finalize(
        DMSG_HMI_TDSRSENDRFMODE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRSENDRFMODE_finalize_ex(
        DMSG_HMI_TDSRSENDRFMODE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRSENDRFMODE_copy(
        DMSG_HMI_TDSRSENDRFMODE* dst,
        const DMSG_HMI_TDSRSENDRFMODE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRBLANKSECTORCTRLTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRBLANKSECTORCTRL
{
    DDS_Char  cBlanckSector;

} DMSG_HMI_TDSRBLANKSECTORCTRL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRBLANKSECTORCTRL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRBLANKSECTORCTRLSeq, DMSG_HMI_TDSRBLANKSECTORCTRL);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRBLANKSECTORCTRL_initialize(
        DMSG_HMI_TDSRBLANKSECTORCTRL* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRBLANKSECTORCTRL_initialize_ex(
        DMSG_HMI_TDSRBLANKSECTORCTRL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRBLANKSECTORCTRL_finalize(
        DMSG_HMI_TDSRBLANKSECTORCTRL* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRBLANKSECTORCTRL_finalize_ex(
        DMSG_HMI_TDSRBLANKSECTORCTRL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRBLANKSECTORCTRL_copy(
        DMSG_HMI_TDSRBLANKSECTORCTRL* dst,
        const DMSG_HMI_TDSRBLANKSECTORCTRL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRVIDEOSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRVIDEOSET
{
    DDS_Char  VideoMode;
    DDS_Char  StcCurve;
    DDS_Char  VideoClutterFilter;
    DDS_Char  VideoLimitMode;
    DDS_Long  nVideoLimitValue;
    DDS_Char  DuctingConfigMode;

} DMSG_HMI_TDSRVIDEOSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRVIDEOSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRVIDEOSETSeq, DMSG_HMI_TDSRVIDEOSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRVIDEOSET_initialize(
        DMSG_HMI_TDSRVIDEOSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRVIDEOSET_initialize_ex(
        DMSG_HMI_TDSRVIDEOSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRVIDEOSET_finalize(
        DMSG_HMI_TDSRVIDEOSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRVIDEOSET_finalize_ex(
        DMSG_HMI_TDSRVIDEOSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRVIDEOSET_copy(
        DMSG_HMI_TDSRVIDEOSET* dst,
        const DMSG_HMI_TDSRVIDEOSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRVIDEOREQTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRVIDEOREQ
{
    DDS_Char  VideoRequestStatus;

} DMSG_HMI_TDSRVIDEOREQ;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRVIDEOREQ_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRVIDEOREQSeq, DMSG_HMI_TDSRVIDEOREQ);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRVIDEOREQ_initialize(
        DMSG_HMI_TDSRVIDEOREQ* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRVIDEOREQ_initialize_ex(
        DMSG_HMI_TDSRVIDEOREQ* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRVIDEOREQ_finalize(
        DMSG_HMI_TDSRVIDEOREQ* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRVIDEOREQ_finalize_ex(
        DMSG_HMI_TDSRVIDEOREQ* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRVIDEOREQ_copy(
        DMSG_HMI_TDSRVIDEOREQ* dst,
        const DMSG_HMI_TDSRVIDEOREQ* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRRDRMODESETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRRDRMODESET
{
    DDS_Char  ManagementMode;
    DDS_Char  PRF;

} DMSG_HMI_TDSRRDRMODESET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRRDRMODESET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRRDRMODESETSeq, DMSG_HMI_TDSRRDRMODESET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRRDRMODESET_initialize(
        DMSG_HMI_TDSRRDRMODESET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRRDRMODESET_initialize_ex(
        DMSG_HMI_TDSRRDRMODESET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRRDRMODESET_finalize(
        DMSG_HMI_TDSRRDRMODESET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRRDRMODESET_finalize_ex(
        DMSG_HMI_TDSRRDRMODESET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRRDRMODESET_copy(
        DMSG_HMI_TDSRRDRMODESET* dst,
        const DMSG_HMI_TDSRRDRMODESET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRAIRTRACKINGSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRAIRTRACKINGSET
{
    DDS_Char  Mode;

} DMSG_HMI_TDSRAIRTRACKINGSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRAIRTRACKINGSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRAIRTRACKINGSETSeq, DMSG_HMI_TDSRAIRTRACKINGSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRAIRTRACKINGSET_initialize(
        DMSG_HMI_TDSRAIRTRACKINGSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRAIRTRACKINGSET_initialize_ex(
        DMSG_HMI_TDSRAIRTRACKINGSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRAIRTRACKINGSET_finalize(
        DMSG_HMI_TDSRAIRTRACKINGSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRAIRTRACKINGSET_finalize_ex(
        DMSG_HMI_TDSRAIRTRACKINGSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRAIRTRACKINGSET_copy(
        DMSG_HMI_TDSRAIRTRACKINGSET* dst,
        const DMSG_HMI_TDSRAIRTRACKINGSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRSHIPTRACKINGSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRSHIPTRACKINGSET
{
    DDS_Char  Mode;

} DMSG_HMI_TDSRSHIPTRACKINGSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRSHIPTRACKINGSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRSHIPTRACKINGSETSeq, DMSG_HMI_TDSRSHIPTRACKINGSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRSHIPTRACKINGSET_initialize(
        DMSG_HMI_TDSRSHIPTRACKINGSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRSHIPTRACKINGSET_initialize_ex(
        DMSG_HMI_TDSRSHIPTRACKINGSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRSHIPTRACKINGSET_finalize(
        DMSG_HMI_TDSRSHIPTRACKINGSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRSHIPTRACKINGSET_finalize_ex(
        DMSG_HMI_TDSRSHIPTRACKINGSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRSHIPTRACKINGSET_copy(
        DMSG_HMI_TDSRSHIPTRACKINGSET* dst,
        const DMSG_HMI_TDSRSHIPTRACKINGSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRJAMMINGDETECTSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRJAMMINGDETECTSET
{
    DDS_Char  DetectMode;

} DMSG_HMI_TDSRJAMMINGDETECTSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRJAMMINGDETECTSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRJAMMINGDETECTSETSeq, DMSG_HMI_TDSRJAMMINGDETECTSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRJAMMINGDETECTSET_initialize(
        DMSG_HMI_TDSRJAMMINGDETECTSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRJAMMINGDETECTSET_initialize_ex(
        DMSG_HMI_TDSRJAMMINGDETECTSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRJAMMINGDETECTSET_finalize(
        DMSG_HMI_TDSRJAMMINGDETECTSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRJAMMINGDETECTSET_finalize_ex(
        DMSG_HMI_TDSRJAMMINGDETECTSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRJAMMINGDETECTSET_copy(
        DMSG_HMI_TDSRJAMMINGDETECTSET* dst,
        const DMSG_HMI_TDSRJAMMINGDETECTSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRLOWSPEEDDETECTSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRLOWSPEEDDETECTSET
{
    DDS_Char  LowDetectConfig;

} DMSG_HMI_TDSRLOWSPEEDDETECTSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRLOWSPEEDDETECTSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRLOWSPEEDDETECTSETSeq, DMSG_HMI_TDSRLOWSPEEDDETECTSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRLOWSPEEDDETECTSET_initialize(
        DMSG_HMI_TDSRLOWSPEEDDETECTSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRLOWSPEEDDETECTSET_initialize_ex(
        DMSG_HMI_TDSRLOWSPEEDDETECTSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRLOWSPEEDDETECTSET_finalize(
        DMSG_HMI_TDSRLOWSPEEDDETECTSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRLOWSPEEDDETECTSET_finalize_ex(
        DMSG_HMI_TDSRLOWSPEEDDETECTSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRLOWSPEEDDETECTSET_copy(
        DMSG_HMI_TDSRLOWSPEEDDETECTSET* dst,
        const DMSG_HMI_TDSRLOWSPEEDDETECTSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRLOWALTDETECTSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRLOWALTDETECTSET
{
    DDS_Char  LowAltitudeConfig;

} DMSG_HMI_TDSRLOWALTDETECTSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRLOWALTDETECTSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRLOWALTDETECTSETSeq, DMSG_HMI_TDSRLOWALTDETECTSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRLOWALTDETECTSET_initialize(
        DMSG_HMI_TDSRLOWALTDETECTSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRLOWALTDETECTSET_initialize_ex(
        DMSG_HMI_TDSRLOWALTDETECTSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRLOWALTDETECTSET_finalize(
        DMSG_HMI_TDSRLOWALTDETECTSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRLOWALTDETECTSET_finalize_ex(
        DMSG_HMI_TDSRLOWALTDETECTSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRLOWALTDETECTSET_copy(
        DMSG_HMI_TDSRLOWALTDETECTSET* dst,
        const DMSG_HMI_TDSRLOWALTDETECTSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRSIDELOBEBLOCKTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRSIDELOBEBLOCK
{
    DDS_Char  SubLobeBlock;

} DMSG_HMI_TDSRSIDELOBEBLOCK;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRSIDELOBEBLOCK_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRSIDELOBEBLOCKSeq, DMSG_HMI_TDSRSIDELOBEBLOCK);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRSIDELOBEBLOCK_initialize(
        DMSG_HMI_TDSRSIDELOBEBLOCK* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRSIDELOBEBLOCK_initialize_ex(
        DMSG_HMI_TDSRSIDELOBEBLOCK* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRSIDELOBEBLOCK_finalize(
        DMSG_HMI_TDSRSIDELOBEBLOCK* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRSIDELOBEBLOCK_finalize_ex(
        DMSG_HMI_TDSRSIDELOBEBLOCK* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRSIDELOBEBLOCK_copy(
        DMSG_HMI_TDSRSIDELOBEBLOCK* dst,
        const DMSG_HMI_TDSRSIDELOBEBLOCK* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSREQUIPQUITSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSREQUIPQUITSET
{
    DDS_Char  EquitQuitConfig;

} DMSG_HMI_TDSREQUIPQUITSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSREQUIPQUITSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSREQUIPQUITSETSeq, DMSG_HMI_TDSREQUIPQUITSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSREQUIPQUITSET_initialize(
        DMSG_HMI_TDSREQUIPQUITSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSREQUIPQUITSET_initialize_ex(
        DMSG_HMI_TDSREQUIPQUITSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSREQUIPQUITSET_finalize(
        DMSG_HMI_TDSREQUIPQUITSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSREQUIPQUITSET_finalize_ex(
        DMSG_HMI_TDSREQUIPQUITSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSREQUIPQUITSET_copy(
        DMSG_HMI_TDSREQUIPQUITSET* dst,
        const DMSG_HMI_TDSREQUIPQUITSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_TDSRTWSTARGETDESIGTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_TDSRTWSTARGETDESIG
{
    DDS_Char  byTrackingStatus;
    DDS_Char  TrackingChannel;
    DDS_Long  nTargetNumber;
    DDS_Double  dPosX;
    DDS_Double  dPosY;
    DDS_Double  dPosZ;

} DMSG_EC_TDSRTWSTARGETDESIG;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_TDSRTWSTARGETDESIG_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_TDSRTWSTARGETDESIGSeq, DMSG_EC_TDSRTWSTARGETDESIG);
        
NDDSUSERDllExport
RTIBool DMSG_EC_TDSRTWSTARGETDESIG_initialize(
        DMSG_EC_TDSRTWSTARGETDESIG* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_TDSRTWSTARGETDESIG_initialize_ex(
        DMSG_EC_TDSRTWSTARGETDESIG* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_TDSRTWSTARGETDESIG_finalize(
        DMSG_EC_TDSRTWSTARGETDESIG* self);
                        
NDDSUSERDllExport
void DMSG_EC_TDSRTWSTARGETDESIG_finalize_ex(
        DMSG_EC_TDSRTWSTARGETDESIG* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_TDSRTWSTARGETDESIG_copy(
        DMSG_EC_TDSRTWSTARGETDESIG* dst,
        const DMSG_EC_TDSRTWSTARGETDESIG* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* DDS_TDSRMMI_1808377665_h */
