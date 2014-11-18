
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_TRRMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef DDS_TRRMMI_1980992815_h
#define DDS_TRRMMI_1980992815_h

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

        
extern const char *DMSG_TRR_TARGETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TRR_TARGET
{
    DDS_UnsignedLong  nTargetNum;
    DDS_Char  byTargetCategory;
    DDS_Double  dPosX;
    DDS_Double  dPosY;
    DDS_Double  dPosZ;
    DDS_Double  dVelocityX;
    DDS_Double  dVelocityY;
    DDS_Double  dVelocityZ;
    DDS_Char  byIsValidTarget;

} DMSG_TRR_TARGET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TRR_TARGET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TRR_TARGETSeq, DMSG_TRR_TARGET);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_TARGET_initialize(
        DMSG_TRR_TARGET* self);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_TARGET_initialize_ex(
        DMSG_TRR_TARGET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TRR_TARGET_finalize(
        DMSG_TRR_TARGET* self);
                        
NDDSUSERDllExport
void DMSG_TRR_TARGET_finalize_ex(
        DMSG_TRR_TARGET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_TARGET_copy(
        DMSG_TRR_TARGET* dst,
        const DMSG_TRR_TARGET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TRR_DIRECTORTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TRR_DIRECTOR
{
    DDS_Double  dDirectorTraverse;
    DDS_Double  dDirectorBearing;
    DDS_Double  dDirectorElevation;

} DMSG_TRR_DIRECTOR;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TRR_DIRECTOR_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TRR_DIRECTORSeq, DMSG_TRR_DIRECTOR);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_DIRECTOR_initialize(
        DMSG_TRR_DIRECTOR* self);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_DIRECTOR_initialize_ex(
        DMSG_TRR_DIRECTOR* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TRR_DIRECTOR_finalize(
        DMSG_TRR_DIRECTOR* self);
                        
NDDSUSERDllExport
void DMSG_TRR_DIRECTOR_finalize_ex(
        DMSG_TRR_DIRECTOR* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_DIRECTOR_copy(
        DMSG_TRR_DIRECTOR* dst,
        const DMSG_TRR_DIRECTOR* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TRR_TRACKINGTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TRR_TRACKING
{
    DDS_Long  nTargetNum;
    DDS_Char  byTrackingStatus;
    DDS_Char  bySourceTrack;
    DDS_Char  byKillAssessment;
    DDS_Char  byRadiationAuthority;

} DMSG_TRR_TRACKING;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TRR_TRACKING_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TRR_TRACKINGSeq, DMSG_TRR_TRACKING);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_TRACKING_initialize(
        DMSG_TRR_TRACKING* self);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_TRACKING_initialize_ex(
        DMSG_TRR_TRACKING* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TRR_TRACKING_finalize(
        DMSG_TRR_TRACKING* self);
                        
NDDSUSERDllExport
void DMSG_TRR_TRACKING_finalize_ex(
        DMSG_TRR_TRACKING* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_TRACKING_copy(
        DMSG_TRR_TRACKING* dst,
        const DMSG_TRR_TRACKING* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TRR_SHOOTDOWNRESULTTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TRR_SHOOTDOWNRESULT
{
    DDS_UnsignedLong  nTargetNum;
    DDS_Char  byshootdownResult;

} DMSG_TRR_SHOOTDOWNRESULT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TRR_SHOOTDOWNRESULT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TRR_SHOOTDOWNRESULTSeq, DMSG_TRR_SHOOTDOWNRESULT);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_SHOOTDOWNRESULT_initialize(
        DMSG_TRR_SHOOTDOWNRESULT* self);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_SHOOTDOWNRESULT_initialize_ex(
        DMSG_TRR_SHOOTDOWNRESULT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TRR_SHOOTDOWNRESULT_finalize(
        DMSG_TRR_SHOOTDOWNRESULT* self);
                        
NDDSUSERDllExport
void DMSG_TRR_SHOOTDOWNRESULT_finalize_ex(
        DMSG_TRR_SHOOTDOWNRESULT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_SHOOTDOWNRESULT_copy(
        DMSG_TRR_SHOOTDOWNRESULT* dst,
        const DMSG_TRR_SHOOTDOWNRESULT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TRR_SETRESULTTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TRR_SETRESULT
{
    DDS_Char  bySettingCategory;
    DDS_Char  bySettingResult;

} DMSG_TRR_SETRESULT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TRR_SETRESULT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TRR_SETRESULTSeq, DMSG_TRR_SETRESULT);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_SETRESULT_initialize(
        DMSG_TRR_SETRESULT* self);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_SETRESULT_initialize_ex(
        DMSG_TRR_SETRESULT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TRR_SETRESULT_finalize(
        DMSG_TRR_SETRESULT* self);
                        
NDDSUSERDllExport
void DMSG_TRR_SETRESULT_finalize_ex(
        DMSG_TRR_SETRESULT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_SETRESULT_copy(
        DMSG_TRR_SETRESULT* dst,
        const DMSG_TRR_SETRESULT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TRR_ASCOPETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TRR_ASCOPE
{
    DDS_Long  nSamplingNum;
    DDS_Long  nSignalPower[100];
    DDS_Long  nScaleX;
    DDS_Long  nScaleY;

} DMSG_TRR_ASCOPE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TRR_ASCOPE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TRR_ASCOPESeq, DMSG_TRR_ASCOPE);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_ASCOPE_initialize(
        DMSG_TRR_ASCOPE* self);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_ASCOPE_initialize_ex(
        DMSG_TRR_ASCOPE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TRR_ASCOPE_finalize(
        DMSG_TRR_ASCOPE* self);
                        
NDDSUSERDllExport
void DMSG_TRR_ASCOPE_finalize_ex(
        DMSG_TRR_ASCOPE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_ASCOPE_copy(
        DMSG_TRR_ASCOPE* dst,
        const DMSG_TRR_ASCOPE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TRR_STATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TRR_STATE
{
    DDS_Char  byInterlockState;
    DDS_Char  byAvailableState;

} DMSG_TRR_STATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TRR_STATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TRR_STATESeq, DMSG_TRR_STATE);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_STATE_initialize(
        DMSG_TRR_STATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_STATE_initialize_ex(
        DMSG_TRR_STATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TRR_STATE_finalize(
        DMSG_TRR_STATE* self);
                        
NDDSUSERDllExport
void DMSG_TRR_STATE_finalize_ex(
        DMSG_TRR_STATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TRR_STATE_copy(
        DMSG_TRR_STATE* dst,
        const DMSG_TRR_STATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TRRRDRCHECKREQTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TRRRDRCHECKREQ
{
    DDS_Char  cRadarTest;

} DMSG_HMI_TRRRDRCHECKREQ;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TRRRDRCHECKREQ_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TRRRDRCHECKREQSeq, DMSG_HMI_TRRRDRCHECKREQ);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRRDRCHECKREQ_initialize(
        DMSG_HMI_TRRRDRCHECKREQ* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRRDRCHECKREQ_initialize_ex(
        DMSG_HMI_TRRRDRCHECKREQ* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TRRRDRCHECKREQ_finalize(
        DMSG_HMI_TRRRDRCHECKREQ* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TRRRDRCHECKREQ_finalize_ex(
        DMSG_HMI_TRRRDRCHECKREQ* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRRDRCHECKREQ_copy(
        DMSG_HMI_TRRRDRCHECKREQ* dst,
        const DMSG_HMI_TRRRDRCHECKREQ* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_TRRTRACKINGCMDTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_TRRTRACKINGCMD
{
    DDS_Char  byTrackingStatus;
    DDS_UnsignedLong  nTargetNum;
    DDS_Double  dBearing;
    DDS_Double  dElevation;
    DDS_Double  dDistance;

} DMSG_EC_TRRTRACKINGCMD;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_TRRTRACKINGCMD_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_TRRTRACKINGCMDSeq, DMSG_EC_TRRTRACKINGCMD);
        
NDDSUSERDllExport
RTIBool DMSG_EC_TRRTRACKINGCMD_initialize(
        DMSG_EC_TRRTRACKINGCMD* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_TRRTRACKINGCMD_initialize_ex(
        DMSG_EC_TRRTRACKINGCMD* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_TRRTRACKINGCMD_finalize(
        DMSG_EC_TRRTRACKINGCMD* self);
                        
NDDSUSERDllExport
void DMSG_EC_TRRTRACKINGCMD_finalize_ex(
        DMSG_EC_TRRTRACKINGCMD* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_TRRTRACKINGCMD_copy(
        DMSG_EC_TRRTRACKINGCMD* dst,
        const DMSG_EC_TRRTRACKINGCMD* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TRRSHOOTDOWNRESULTREQTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TRRSHOOTDOWNRESULTREQ
{
    DDS_UnsignedLong  nTargetNum;
    DDS_Char  byRequestStatus;

} DMSG_HMI_TRRSHOOTDOWNRESULTREQ;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TRRSHOOTDOWNRESULTREQ_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TRRSHOOTDOWNRESULTREQSeq, DMSG_HMI_TRRSHOOTDOWNRESULTREQ);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRSHOOTDOWNRESULTREQ_initialize(
        DMSG_HMI_TRRSHOOTDOWNRESULTREQ* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRSHOOTDOWNRESULTREQ_initialize_ex(
        DMSG_HMI_TRRSHOOTDOWNRESULTREQ* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TRRSHOOTDOWNRESULTREQ_finalize(
        DMSG_HMI_TRRSHOOTDOWNRESULTREQ* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TRRSHOOTDOWNRESULTREQ_finalize_ex(
        DMSG_HMI_TRRSHOOTDOWNRESULTREQ* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRSHOOTDOWNRESULTREQ_copy(
        DMSG_HMI_TRRSHOOTDOWNRESULTREQ* dst,
        const DMSG_HMI_TRRSHOOTDOWNRESULTREQ* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TRRRDRSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TRRRDRSET
{
    DDS_Char  byTWTConfig;
    DDS_Char  byTransmitMode;
    DDS_Char  byDecreaseMode;

} DMSG_HMI_TRRRDRSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TRRRDRSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TRRRDRSETSeq, DMSG_HMI_TRRRDRSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRRDRSET_initialize(
        DMSG_HMI_TRRRDRSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRRDRSET_initialize_ex(
        DMSG_HMI_TRRRDRSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TRRRDRSET_finalize(
        DMSG_HMI_TRRRDRSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TRRRDRSET_finalize_ex(
        DMSG_HMI_TRRRDRSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRRDRSET_copy(
        DMSG_HMI_TRRRDRSET* dst,
        const DMSG_HMI_TRRRDRSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TRRVIDEOSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TRRVIDEOSET
{
    DDS_Char  byAScopeSTC;
    DDS_Char  byAScopeVideo;
    DDS_Char  byNoiseThreshold;
    DDS_Char  byDisplayThreshold;

} DMSG_HMI_TRRVIDEOSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TRRVIDEOSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TRRVIDEOSETSeq, DMSG_HMI_TRRVIDEOSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRVIDEOSET_initialize(
        DMSG_HMI_TRRVIDEOSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRVIDEOSET_initialize_ex(
        DMSG_HMI_TRRVIDEOSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TRRVIDEOSET_finalize(
        DMSG_HMI_TRRVIDEOSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TRRVIDEOSET_finalize_ex(
        DMSG_HMI_TRRVIDEOSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRVIDEOSET_copy(
        DMSG_HMI_TRRVIDEOSET* dst,
        const DMSG_HMI_TRRVIDEOSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TRRMANAGESETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TRRMANAGESET
{
    DDS_Long  nInitAltitude;
    DDS_Long  nShipTrackAltitude;
    DDS_Char  bySeaState;
    DDS_Long  nMaxAltitude;

} DMSG_HMI_TRRMANAGESET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TRRMANAGESET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TRRMANAGESETSeq, DMSG_HMI_TRRMANAGESET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRMANAGESET_initialize(
        DMSG_HMI_TRRMANAGESET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRMANAGESET_initialize_ex(
        DMSG_HMI_TRRMANAGESET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TRRMANAGESET_finalize(
        DMSG_HMI_TRRMANAGESET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TRRMANAGESET_finalize_ex(
        DMSG_HMI_TRRMANAGESET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRMANAGESET_copy(
        DMSG_HMI_TRRMANAGESET* dst,
        const DMSG_HMI_TRRMANAGESET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TRRCAUTIONSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TRRCAUTIONSET
{
    DDS_Boolean  bMissileCaution;
    DDS_Boolean  bJammerTracking;

} DMSG_HMI_TRRCAUTIONSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TRRCAUTIONSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TRRCAUTIONSETSeq, DMSG_HMI_TRRCAUTIONSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRCAUTIONSET_initialize(
        DMSG_HMI_TRRCAUTIONSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRCAUTIONSET_initialize_ex(
        DMSG_HMI_TRRCAUTIONSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TRRCAUTIONSET_finalize(
        DMSG_HMI_TRRCAUTIONSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TRRCAUTIONSET_finalize_ex(
        DMSG_HMI_TRRCAUTIONSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRCAUTIONSET_copy(
        DMSG_HMI_TRRCAUTIONSET* dst,
        const DMSG_HMI_TRRCAUTIONSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TRREQUIPMENTSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TRREQUIPMENTSET
{
    DDS_Char  byTWTPower;
    DDS_Char  byEmergencyManageMode;
    DDS_Char  byRadiationControl;
    DDS_Char  byRadarSilence;
    DDS_Char  byDirector;
    DDS_Char  byJoystick;

} DMSG_HMI_TRREQUIPMENTSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TRREQUIPMENTSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TRREQUIPMENTSETSeq, DMSG_HMI_TRREQUIPMENTSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRREQUIPMENTSET_initialize(
        DMSG_HMI_TRREQUIPMENTSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRREQUIPMENTSET_initialize_ex(
        DMSG_HMI_TRREQUIPMENTSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TRREQUIPMENTSET_finalize(
        DMSG_HMI_TRREQUIPMENTSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TRREQUIPMENTSET_finalize_ex(
        DMSG_HMI_TRREQUIPMENTSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRREQUIPMENTSET_copy(
        DMSG_HMI_TRREQUIPMENTSET* dst,
        const DMSG_HMI_TRREQUIPMENTSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TRRTRACKINGSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TRRTRACKINGSET
{
    DDS_Char  byHandTracking;
    DDS_Char  byHandRegulation;
    DDS_Char  bySecondaryTarget;
    DDS_Long  nRangeGateMoveCtr;
    DDS_Char  byRangeGateCtr;
    DDS_Char  byLowAltitudeTracking;
    DDS_Char  byFlightTarget;
    DDS_Char  byFilter;

} DMSG_HMI_TRRTRACKINGSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TRRTRACKINGSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TRRTRACKINGSETSeq, DMSG_HMI_TRRTRACKINGSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRTRACKINGSET_initialize(
        DMSG_HMI_TRRTRACKINGSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRTRACKINGSET_initialize_ex(
        DMSG_HMI_TRRTRACKINGSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TRRTRACKINGSET_finalize(
        DMSG_HMI_TRRTRACKINGSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TRRTRACKINGSET_finalize_ex(
        DMSG_HMI_TRRTRACKINGSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRTRACKINGSET_copy(
        DMSG_HMI_TRRTRACKINGSET* dst,
        const DMSG_HMI_TRRTRACKINGSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TRRVIDEOREQTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TRRVIDEOREQ
{
    DDS_Char  cRequestVideo;

} DMSG_HMI_TRRVIDEOREQ;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TRRVIDEOREQ_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TRRVIDEOREQSeq, DMSG_HMI_TRRVIDEOREQ);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRVIDEOREQ_initialize(
        DMSG_HMI_TRRVIDEOREQ* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRVIDEOREQ_initialize_ex(
        DMSG_HMI_TRRVIDEOREQ* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TRRVIDEOREQ_finalize(
        DMSG_HMI_TRRVIDEOREQ* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TRRVIDEOREQ_finalize_ex(
        DMSG_HMI_TRRVIDEOREQ* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRVIDEOREQ_copy(
        DMSG_HMI_TRRVIDEOREQ* dst,
        const DMSG_HMI_TRRVIDEOREQ* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* DDS_TRRMMI_1980992815_h */
