
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_CMS.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef DDS_CMS_1867575076_h
#define DDS_CMS_1867575076_h

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

        
extern const char *TrkNoSysTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct TrkNoSys
{
    DDS_UnsignedShort  trkNo;
    DDS_UnsignedShort  trkNoLINK;
    DDS_UnsignedShort  trkNoTDSR;
    DDS_Char  trkNoTRR;
    DDS_Char  trkNoEOTS;
    DDS_Char  trkNoEW;
    DDS_Char  trkNoPERI;
    DDS_Char  trkNoOMS;
    DDS_Char  trkNoNAVR;
    DDS_Char  trkNoSONAR;
    DDS_Char  trkNoMAN;

} TrkNoSys;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* TrkNoSys_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(TrkNoSysSeq, TrkNoSys);
        
NDDSUSERDllExport
RTIBool TrkNoSys_initialize(
        TrkNoSys* self);
        
NDDSUSERDllExport
RTIBool TrkNoSys_initialize_ex(
        TrkNoSys* self,RTIBool allocatePointers);

NDDSUSERDllExport
void TrkNoSys_finalize(
        TrkNoSys* self);
                        
NDDSUSERDllExport
void TrkNoSys_finalize_ex(
        TrkNoSys* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool TrkNoSys_copy(
        TrkNoSys* dst,
        const TrkNoSys* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *stDateTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct stDate
{
    DDS_UnsignedShort  yy;
    DDS_Char  mm;
    DDS_Char  dd;

} stDate;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* stDate_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(stDateSeq, stDate);
        
NDDSUSERDllExport
RTIBool stDate_initialize(
        stDate* self);
        
NDDSUSERDllExport
RTIBool stDate_initialize_ex(
        stDate* self,RTIBool allocatePointers);

NDDSUSERDllExport
void stDate_finalize(
        stDate* self);
                        
NDDSUSERDllExport
void stDate_finalize_ex(
        stDate* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool stDate_copy(
        stDate* dst,
        const stDate* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *stTimeTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct stTime
{
    DDS_Char  hh;
    DDS_Char  mm;

} stTime;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* stTime_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(stTimeSeq, stTime);
        
NDDSUSERDllExport
RTIBool stTime_initialize(
        stTime* self);
        
NDDSUSERDllExport
RTIBool stTime_initialize_ex(
        stTime* self,RTIBool allocatePointers);

NDDSUSERDllExport
void stTime_finalize(
        stTime* self);
                        
NDDSUSERDllExport
void stTime_finalize_ex(
        stTime* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool stTime_copy(
        stTime* dst,
        const stTime* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *time1TYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct time1
{
    DDS_Char  hh;
    DDS_Char  mm;
    DDS_Char  ss;

} time1;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* time1_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(time1Seq, time1);
        
NDDSUSERDllExport
RTIBool time1_initialize(
        time1* self);
        
NDDSUSERDllExport
RTIBool time1_initialize_ex(
        time1* self,RTIBool allocatePointers);

NDDSUSERDllExport
void time1_finalize(
        time1* self);
                        
NDDSUSERDllExport
void time1_finalize_ex(
        time1* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool time1_copy(
        time1* dst,
        const time1* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *time2TYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct time2
{
    DDS_Char  hh;
    DDS_Char  mm;
    DDS_Char  ss;
    DDS_Char  ms;

} time2;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* time2_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(time2Seq, time2);
        
NDDSUSERDllExport
RTIBool time2_initialize(
        time2* self);
        
NDDSUSERDllExport
RTIBool time2_initialize_ex(
        time2* self,RTIBool allocatePointers);

NDDSUSERDllExport
void time2_finalize(
        time2* self);
                        
NDDSUSERDllExport
void time2_finalize_ex(
        time2* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool time2_copy(
        time2* dst,
        const time2* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *coordiSysTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct coordiSys
{
    DDS_Double  latitude;
    DDS_Double  longitude;

} coordiSys;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* coordiSys_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(coordiSysSeq, coordiSys);
        
NDDSUSERDllExport
RTIBool coordiSys_initialize(
        coordiSys* self);
        
NDDSUSERDllExport
RTIBool coordiSys_initialize_ex(
        coordiSys* self,RTIBool allocatePointers);

NDDSUSERDllExport
void coordiSys_finalize(
        coordiSys* self);
                        
NDDSUSERDllExport
void coordiSys_finalize_ex(
        coordiSys* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool coordiSys_copy(
        coordiSys* dst,
        const coordiSys* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *coordiHSysTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct coordiHSys
{
    DDS_Double  latitude;
    DDS_Double  longitude;
    DDS_Double  hgt;

} coordiHSys;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* coordiHSys_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(coordiHSysSeq, coordiHSys);
        
NDDSUSERDllExport
RTIBool coordiHSys_initialize(
        coordiHSys* self);
        
NDDSUSERDllExport
RTIBool coordiHSys_initialize_ex(
        coordiHSys* self,RTIBool allocatePointers);

NDDSUSERDllExport
void coordiHSys_finalize(
        coordiHSys* self);
                        
NDDSUSERDllExport
void coordiHSys_finalize_ex(
        coordiHSys* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool coordiHSys_copy(
        coordiHSys* dst,
        const coordiHSys* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *coordiRSysTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct coordiRSys
{
    DDS_Double  latitude;
    DDS_Double  longitude;
    DDS_UnsignedShort  radius;

} coordiRSys;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* coordiRSys_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(coordiRSysSeq, coordiRSys);
        
NDDSUSERDllExport
RTIBool coordiRSys_initialize(
        coordiRSys* self);
        
NDDSUSERDllExport
RTIBool coordiRSys_initialize_ex(
        coordiRSys* self,RTIBool allocatePointers);

NDDSUSERDllExport
void coordiRSys_finalize(
        coordiRSys* self);
                        
NDDSUSERDllExport
void coordiRSys_finalize_ex(
        coordiRSys* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool coordiRSys_copy(
        coordiRSys* dst,
        const coordiRSys* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *rectSysTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct rectSys
{
    DDS_Double  x;
    DDS_Double  z;

} rectSys;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* rectSys_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(rectSysSeq, rectSys);
        
NDDSUSERDllExport
RTIBool rectSys_initialize(
        rectSys* self);
        
NDDSUSERDllExport
RTIBool rectSys_initialize_ex(
        rectSys* self,RTIBool allocatePointers);

NDDSUSERDllExport
void rectSys_finalize(
        rectSys* self);
                        
NDDSUSERDllExport
void rectSys_finalize_ex(
        rectSys* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool rectSys_copy(
        rectSys* dst,
        const rectSys* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *rectHSysTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct rectHSys
{
    DDS_Double  x;
    DDS_Double  y;
    DDS_Double  z;

} rectHSys;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* rectHSys_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(rectHSysSeq, rectHSys);
        
NDDSUSERDllExport
RTIBool rectHSys_initialize(
        rectHSys* self);
        
NDDSUSERDllExport
RTIBool rectHSys_initialize_ex(
        rectHSys* self,RTIBool allocatePointers);

NDDSUSERDllExport
void rectHSys_finalize(
        rectHSys* self);
                        
NDDSUSERDllExport
void rectHSys_finalize_ex(
        rectHSys* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool rectHSys_copy(
        rectHSys* dst,
        const rectHSys* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *rectRSysTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct rectRSys
{
    DDS_Double  x;
    DDS_Double  z;
    DDS_UnsignedShort  radius;

} rectRSys;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* rectRSys_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(rectRSysSeq, rectRSys);
        
NDDSUSERDllExport
RTIBool rectRSys_initialize(
        rectRSys* self);
        
NDDSUSERDllExport
RTIBool rectRSys_initialize_ex(
        rectRSys* self,RTIBool allocatePointers);

NDDSUSERDllExport
void rectRSys_finalize(
        rectRSys* self);
                        
NDDSUSERDllExport
void rectRSys_finalize_ex(
        rectRSys* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool rectRSys_copy(
        rectRSys* dst,
        const rectRSys* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *velocity3DTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct velocity3D
{
    DDS_Double  hh;
    DDS_Double  mm;

} velocity3D;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* velocity3D_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(velocity3DSeq, velocity3D);
        
NDDSUSERDllExport
RTIBool velocity3D_initialize(
        velocity3D* self);
        
NDDSUSERDllExport
RTIBool velocity3D_initialize_ex(
        velocity3D* self,RTIBool allocatePointers);

NDDSUSERDllExport
void velocity3D_finalize(
        velocity3D* self);
                        
NDDSUSERDllExport
void velocity3D_finalize_ex(
        velocity3D* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool velocity3D_copy(
        velocity3D* dst,
        const velocity3D* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *SonarTrackTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct SonarTrack
{
    DDS_Char  cSensor;
    DDS_Char  cTargetState;
    DDS_Char  cTrackingMode;
    DDS_Float  fBearing;
    DDS_Float  fBearingRate;
    DDS_Float  fSignalToNoiseRation;
    DDS_Float  fRange;
    DDS_Float  fCourse;
    DDS_Float  fSpeed;

} SonarTrack;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* SonarTrack_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(SonarTrackSeq, SonarTrack);
        
NDDSUSERDllExport
RTIBool SonarTrack_initialize(
        SonarTrack* self);
        
NDDSUSERDllExport
RTIBool SonarTrack_initialize_ex(
        SonarTrack* self,RTIBool allocatePointers);

NDDSUSERDllExport
void SonarTrack_finalize(
        SonarTrack* self);
                        
NDDSUSERDllExport
void SonarTrack_finalize_ex(
        SonarTrack* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool SonarTrack_copy(
        SonarTrack* dst,
        const SonarTrack* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *stWakeTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct stWake
{
    DDS_Double  dLat[30];
    DDS_Double  dLon[30];
    DDS_Long  nLatIndex;
    DDS_Long  nLonIndex;

} stWake;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* stWake_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(stWakeSeq, stWake);
        
NDDSUSERDllExport
RTIBool stWake_initialize(
        stWake* self);
        
NDDSUSERDllExport
RTIBool stWake_initialize_ex(
        stWake* self,RTIBool allocatePointers);

NDDSUSERDllExport
void stWake_finalize(
        stWake* self);
                        
NDDSUSERDllExport
void stWake_finalize_ex(
        stWake* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool stWake_copy(
        stWake* dst,
        const stWake* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *stSubSysTrackIDTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct stSubSysTrackID
{
    DDS_UnsignedLong  nTrkNo;
    DDS_UnsignedLong  nPrsTrkNo;
    DDS_UnsignedLong  nCasBdtTrkNo;
    DDS_UnsignedLong  nFasBdtTrkNo;
    DDS_UnsignedLong  nCasDemTrkNo;
    DDS_UnsignedLong  nFasLdtTrkNo;
    DDS_UnsignedLong  nFasDemTrkNo;
    DDS_UnsignedLong  nNavrTrkNo;
    DDS_UnsignedLong  nPeriTrkNo;
    DDS_UnsignedLong  nOmsTrkNo;
    DDS_UnsignedLong  nManTrkNo;
    DDS_UnsignedLong  nTorpTrkNo;
    DDS_UnsignedLong  nIpsTrkNo;
    DDS_UnsignedLong  nEsmTrkNo;
    DDS_UnsignedLong  nLinkTrkNo;

} stSubSysTrackID;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* stSubSysTrackID_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(stSubSysTrackIDSeq, stSubSysTrackID);
        
NDDSUSERDllExport
RTIBool stSubSysTrackID_initialize(
        stSubSysTrackID* self);
        
NDDSUSERDllExport
RTIBool stSubSysTrackID_initialize_ex(
        stSubSysTrackID* self,RTIBool allocatePointers);

NDDSUSERDllExport
void stSubSysTrackID_finalize(
        stSubSysTrackID* self);
                        
NDDSUSERDllExport
void stSubSysTrackID_finalize_ex(
        stSubSysTrackID* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool stSubSysTrackID_copy(
        stSubSysTrackID* dst,
        const stSubSysTrackID* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *stFullTimeTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct stFullTime
{
    DDS_UnsignedShort  year;
    DDS_Char  month;
    DDS_Char  day;
    DDS_Char  hour;
    DDS_Char  minute;
    DDS_Char  sec;
    DDS_Char  msec;

} stFullTime;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* stFullTime_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(stFullTimeSeq, stFullTime);
        
NDDSUSERDllExport
RTIBool stFullTime_initialize(
        stFullTime* self);
        
NDDSUSERDllExport
RTIBool stFullTime_initialize_ex(
        stFullTime* self,RTIBool allocatePointers);

NDDSUSERDllExport
void stFullTime_finalize(
        stFullTime* self);
                        
NDDSUSERDllExport
void stFullTime_finalize_ex(
        stFullTime* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool stFullTime_copy(
        stFullTime* dst,
        const stFullTime* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_OSM_SENSORSTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_OSM_SENSORSTATE
{
    DDS_Long  nTrackRadarID;
    DDS_Boolean  bInterFaceInfo;
    DDS_Boolean  bAvailable;
    DDS_Boolean  bCh1_available;
    DDS_Boolean  bCh2_available;

} DMSG_OSM_SENSORSTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_OSM_SENSORSTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_OSM_SENSORSTATESeq, DMSG_OSM_SENSORSTATE);
        
NDDSUSERDllExport
RTIBool DMSG_OSM_SENSORSTATE_initialize(
        DMSG_OSM_SENSORSTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_OSM_SENSORSTATE_initialize_ex(
        DMSG_OSM_SENSORSTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_OSM_SENSORSTATE_finalize(
        DMSG_OSM_SENSORSTATE* self);
                        
NDDSUSERDllExport
void DMSG_OSM_SENSORSTATE_finalize_ex(
        DMSG_OSM_SENSORSTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_OSM_SENSORSTATE_copy(
        DMSG_OSM_SENSORSTATE* dst,
        const DMSG_OSM_SENSORSTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_OSM_WEAPONSTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_OSM_WEAPONSTATE
{
    DDS_Long  nWeaponID;
    DDS_Boolean  bInterFace;
    DDS_Boolean  bAvailable;

} DMSG_OSM_WEAPONSTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_OSM_WEAPONSTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_OSM_WEAPONSTATESeq, DMSG_OSM_WEAPONSTATE);
        
NDDSUSERDllExport
RTIBool DMSG_OSM_WEAPONSTATE_initialize(
        DMSG_OSM_WEAPONSTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_OSM_WEAPONSTATE_initialize_ex(
        DMSG_OSM_WEAPONSTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_OSM_WEAPONSTATE_finalize(
        DMSG_OSM_WEAPONSTATE* self);
                        
NDDSUSERDllExport
void DMSG_OSM_WEAPONSTATE_finalize_ex(
        DMSG_OSM_WEAPONSTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_OSM_WEAPONSTATE_copy(
        DMSG_OSM_WEAPONSTATE* dst,
        const DMSG_OSM_WEAPONSTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_REQMISSILEENGAGEPLANTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_REQMISSILEENGAGEPLAN
{
    DDS_Char  cConsoleID;
    DDS_Char  cTubeID;
    TrkNoSys  trkNo;

} DMSG_HMI_REQMISSILEENGAGEPLAN;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_REQMISSILEENGAGEPLAN_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_REQMISSILEENGAGEPLANSeq, DMSG_HMI_REQMISSILEENGAGEPLAN);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_REQMISSILEENGAGEPLAN_initialize(
        DMSG_HMI_REQMISSILEENGAGEPLAN* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_REQMISSILEENGAGEPLAN_initialize_ex(
        DMSG_HMI_REQMISSILEENGAGEPLAN* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_REQMISSILEENGAGEPLAN_finalize(
        DMSG_HMI_REQMISSILEENGAGEPLAN* self);
                        
NDDSUSERDllExport
void DMSG_HMI_REQMISSILEENGAGEPLAN_finalize_ex(
        DMSG_HMI_REQMISSILEENGAGEPLAN* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_REQMISSILEENGAGEPLAN_copy(
        DMSG_HMI_REQMISSILEENGAGEPLAN* dst,
        const DMSG_HMI_REQMISSILEENGAGEPLAN* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_SUBHMI_SYSCTRLMODETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_SUBHMI_SYSCTRLMODE
{
    DDS_UnsignedLong  consoleID;
    DDS_UnsignedLong  mode;

} DMSG_SUBHMI_SYSCTRLMODE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_SUBHMI_SYSCTRLMODE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_SUBHMI_SYSCTRLMODESeq, DMSG_SUBHMI_SYSCTRLMODE);
        
NDDSUSERDllExport
RTIBool DMSG_SUBHMI_SYSCTRLMODE_initialize(
        DMSG_SUBHMI_SYSCTRLMODE* self);
        
NDDSUSERDllExport
RTIBool DMSG_SUBHMI_SYSCTRLMODE_initialize_ex(
        DMSG_SUBHMI_SYSCTRLMODE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_SUBHMI_SYSCTRLMODE_finalize(
        DMSG_SUBHMI_SYSCTRLMODE* self);
                        
NDDSUSERDllExport
void DMSG_SUBHMI_SYSCTRLMODE_finalize_ex(
        DMSG_SUBHMI_SYSCTRLMODE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_SUBHMI_SYSCTRLMODE_copy(
        DMSG_SUBHMI_SYSCTRLMODE* dst,
        const DMSG_SUBHMI_SYSCTRLMODE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_WEAPONLIMITSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_WEAPONLIMITSET
{
    DDS_UnsignedLong  trkNo;
    DDS_Char  cWeaponLimit;

} DMSG_HMI_WEAPONLIMITSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_WEAPONLIMITSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_WEAPONLIMITSETSeq, DMSG_HMI_WEAPONLIMITSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONLIMITSET_initialize(
        DMSG_HMI_WEAPONLIMITSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONLIMITSET_initialize_ex(
        DMSG_HMI_WEAPONLIMITSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_WEAPONLIMITSET_finalize(
        DMSG_HMI_WEAPONLIMITSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_WEAPONLIMITSET_finalize_ex(
        DMSG_HMI_WEAPONLIMITSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONLIMITSET_copy(
        DMSG_HMI_WEAPONLIMITSET* dst,
        const DMSG_HMI_WEAPONLIMITSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_CREATEMANUALTRACKTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_CREATEMANUALTRACK
{
    DDS_Char  cTrackForm;
    DDS_Char  cTrackType;
    DDS_Char  cTrackIdentity;
    DDS_Char  cTrackCategory;
    DDS_UnsignedShort  sIdentificationDetailType;
    DDS_UnsignedShort  sIdentificationDetailMajor;
    DDS_UnsignedShort  sIdentificationDetailMinor;
    DDS_Float  fCourse;
    DDS_Float  fSpeed;
    coordiHSys  positionCHSys;

} DMSG_HMI_CREATEMANUALTRACK;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_CREATEMANUALTRACK_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_CREATEMANUALTRACKSeq, DMSG_HMI_CREATEMANUALTRACK);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_CREATEMANUALTRACK_initialize(
        DMSG_HMI_CREATEMANUALTRACK* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_CREATEMANUALTRACK_initialize_ex(
        DMSG_HMI_CREATEMANUALTRACK* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_CREATEMANUALTRACK_finalize(
        DMSG_HMI_CREATEMANUALTRACK* self);
                        
NDDSUSERDllExport
void DMSG_HMI_CREATEMANUALTRACK_finalize_ex(
        DMSG_HMI_CREATEMANUALTRACK* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_CREATEMANUALTRACK_copy(
        DMSG_HMI_CREATEMANUALTRACK* dst,
        const DMSG_HMI_CREATEMANUALTRACK* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TARGETIDENTITYSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TARGETIDENTITYSET
{
    DDS_UnsignedLong  trkNo;
    DDS_Char  cTrackIdentity;

} DMSG_HMI_TARGETIDENTITYSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TARGETIDENTITYSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TARGETIDENTITYSETSeq, DMSG_HMI_TARGETIDENTITYSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TARGETIDENTITYSET_initialize(
        DMSG_HMI_TARGETIDENTITYSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TARGETIDENTITYSET_initialize_ex(
        DMSG_HMI_TARGETIDENTITYSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TARGETIDENTITYSET_finalize(
        DMSG_HMI_TARGETIDENTITYSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TARGETIDENTITYSET_finalize_ex(
        DMSG_HMI_TARGETIDENTITYSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TARGETIDENTITYSET_copy(
        DMSG_HMI_TARGETIDENTITYSET* dst,
        const DMSG_HMI_TARGETIDENTITYSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TARGETCATEGORYSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TARGETCATEGORYSET
{
    DDS_UnsignedLong  trkNo;
    DDS_Char  cTrackCategory;

} DMSG_HMI_TARGETCATEGORYSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TARGETCATEGORYSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TARGETCATEGORYSETSeq, DMSG_HMI_TARGETCATEGORYSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TARGETCATEGORYSET_initialize(
        DMSG_HMI_TARGETCATEGORYSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TARGETCATEGORYSET_initialize_ex(
        DMSG_HMI_TARGETCATEGORYSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TARGETCATEGORYSET_finalize(
        DMSG_HMI_TARGETCATEGORYSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TARGETCATEGORYSET_finalize_ex(
        DMSG_HMI_TARGETCATEGORYSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TARGETCATEGORYSET_copy(
        DMSG_HMI_TARGETCATEGORYSET* dst,
        const DMSG_HMI_TARGETCATEGORYSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TARGETNAMESETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TARGETNAMESET
{
    DDS_UnsignedLong  trkNo;
    DDS_Char  cTrackName[30];

} DMSG_HMI_TARGETNAMESET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TARGETNAMESET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TARGETNAMESETSeq, DMSG_HMI_TARGETNAMESET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TARGETNAMESET_initialize(
        DMSG_HMI_TARGETNAMESET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TARGETNAMESET_initialize_ex(
        DMSG_HMI_TARGETNAMESET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TARGETNAMESET_finalize(
        DMSG_HMI_TARGETNAMESET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TARGETNAMESET_finalize_ex(
        DMSG_HMI_TARGETNAMESET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TARGETNAMESET_copy(
        DMSG_HMI_TARGETNAMESET* dst,
        const DMSG_HMI_TARGETNAMESET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_ENGAGESETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_ENGAGESET
{
    DDS_UnsignedLong  trkNo;
    DDS_Char  cEngageState;

} DMSG_HMI_ENGAGESET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_ENGAGESET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_ENGAGESETSeq, DMSG_HMI_ENGAGESET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGESET_initialize(
        DMSG_HMI_ENGAGESET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGESET_initialize_ex(
        DMSG_HMI_ENGAGESET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_ENGAGESET_finalize(
        DMSG_HMI_ENGAGESET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_ENGAGESET_finalize_ex(
        DMSG_HMI_ENGAGESET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGESET_copy(
        DMSG_HMI_ENGAGESET* dst,
        const DMSG_HMI_ENGAGESET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_MANUALSELECTSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_MANUALSELECTSET
{
    DDS_UnsignedLong  trkNo;
    DDS_Char  cThreatEvaluation;

} DMSG_HMI_MANUALSELECTSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_MANUALSELECTSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_MANUALSELECTSETSeq, DMSG_HMI_MANUALSELECTSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_MANUALSELECTSET_initialize(
        DMSG_HMI_MANUALSELECTSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_MANUALSELECTSET_initialize_ex(
        DMSG_HMI_MANUALSELECTSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_MANUALSELECTSET_finalize(
        DMSG_HMI_MANUALSELECTSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_MANUALSELECTSET_finalize_ex(
        DMSG_HMI_MANUALSELECTSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_MANUALSELECTSET_copy(
        DMSG_HMI_MANUALSELECTSET* dst,
        const DMSG_HMI_MANUALSELECTSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_IDENTITYDETAILSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_IDENTITYDETAILSET
{
    DDS_UnsignedLong  trkNo;
    DDS_UnsignedShort  sIdentificationDetailType;
    DDS_UnsignedShort  sIdentificationDetailMajor;
    DDS_UnsignedShort  sIdentificationDetailMinor;

} DMSG_HMI_IDENTITYDETAILSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_IDENTITYDETAILSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_IDENTITYDETAILSETSeq, DMSG_HMI_IDENTITYDETAILSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_IDENTITYDETAILSET_initialize(
        DMSG_HMI_IDENTITYDETAILSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_IDENTITYDETAILSET_initialize_ex(
        DMSG_HMI_IDENTITYDETAILSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_IDENTITYDETAILSET_finalize(
        DMSG_HMI_IDENTITYDETAILSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_IDENTITYDETAILSET_finalize_ex(
        DMSG_HMI_IDENTITYDETAILSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_IDENTITYDETAILSET_copy(
        DMSG_HMI_IDENTITYDETAILSET* dst,
        const DMSG_HMI_IDENTITYDETAILSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_WEAPONCAPABILITYSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_WEAPONCAPABILITYSET
{
    DDS_UnsignedLong  trkNo;
    DDS_UnsignedShort  sWeaponCapability;
    DDS_Float  fWeaponMaxRange;

} DMSG_HMI_WEAPONCAPABILITYSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_WEAPONCAPABILITYSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_WEAPONCAPABILITYSETSeq, DMSG_HMI_WEAPONCAPABILITYSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONCAPABILITYSET_initialize(
        DMSG_HMI_WEAPONCAPABILITYSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONCAPABILITYSET_initialize_ex(
        DMSG_HMI_WEAPONCAPABILITYSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_WEAPONCAPABILITYSET_finalize(
        DMSG_HMI_WEAPONCAPABILITYSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_WEAPONCAPABILITYSET_finalize_ex(
        DMSG_HMI_WEAPONCAPABILITYSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONCAPABILITYSET_copy(
        DMSG_HMI_WEAPONCAPABILITYSET* dst,
        const DMSG_HMI_WEAPONCAPABILITYSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_DATUMSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_DATUMSET
{
    DDS_UnsignedLong  trkNo;
    DDS_Float  fDatumSpd;
    DDS_Float  fDatumErr;

} DMSG_HMI_DATUMSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_DATUMSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_DATUMSETSeq, DMSG_HMI_DATUMSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_DATUMSET_initialize(
        DMSG_HMI_DATUMSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_DATUMSET_initialize_ex(
        DMSG_HMI_DATUMSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_DATUMSET_finalize(
        DMSG_HMI_DATUMSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_DATUMSET_finalize_ex(
        DMSG_HMI_DATUMSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_DATUMSET_copy(
        DMSG_HMI_DATUMSET* dst,
        const DMSG_HMI_DATUMSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_SYSTRACKDELTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_SYSTRACKDEL
{
    DDS_UnsignedLong  DelTrkNo;

} DMSG_HMI_SYSTRACKDEL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_SYSTRACKDEL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_SYSTRACKDELSeq, DMSG_HMI_SYSTRACKDEL);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SYSTRACKDEL_initialize(
        DMSG_HMI_SYSTRACKDEL* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SYSTRACKDEL_initialize_ex(
        DMSG_HMI_SYSTRACKDEL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_SYSTRACKDEL_finalize(
        DMSG_HMI_SYSTRACKDEL* self);
                        
NDDSUSERDllExport
void DMSG_HMI_SYSTRACKDEL_finalize_ex(
        DMSG_HMI_SYSTRACKDEL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SYSTRACKDEL_copy(
        DMSG_HMI_SYSTRACKDEL* dst,
        const DMSG_HMI_SYSTRACKDEL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_PAIRINGSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_PAIRINGSET
{
    DDS_Char  cPairingType;
    TrkNoSys  PairingTrkNo;
    TrkNoSys  NetTrkNo;

} DMSG_HMI_PAIRINGSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_PAIRINGSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_PAIRINGSETSeq, DMSG_HMI_PAIRINGSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_PAIRINGSET_initialize(
        DMSG_HMI_PAIRINGSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_PAIRINGSET_initialize_ex(
        DMSG_HMI_PAIRINGSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_PAIRINGSET_finalize(
        DMSG_HMI_PAIRINGSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_PAIRINGSET_finalize_ex(
        DMSG_HMI_PAIRINGSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_PAIRINGSET_copy(
        DMSG_HMI_PAIRINGSET* dst,
        const DMSG_HMI_PAIRINGSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_ASSOCIATIONSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_ASSOCIATIONSET
{
    DDS_Char  cAssociationType;
    TrkNoSys  MainTrkNo;
    TrkNoSys  MinortrkNo;

} DMSG_HMI_ASSOCIATIONSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_ASSOCIATIONSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_ASSOCIATIONSETSeq, DMSG_HMI_ASSOCIATIONSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ASSOCIATIONSET_initialize(
        DMSG_HMI_ASSOCIATIONSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ASSOCIATIONSET_initialize_ex(
        DMSG_HMI_ASSOCIATIONSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_ASSOCIATIONSET_finalize(
        DMSG_HMI_ASSOCIATIONSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_ASSOCIATIONSET_finalize_ex(
        DMSG_HMI_ASSOCIATIONSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ASSOCIATIONSET_copy(
        DMSG_HMI_ASSOCIATIONSET* dst,
        const DMSG_HMI_ASSOCIATIONSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_CORRELATIONSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_CORRELATIONSET
{
    TrkNoSys  KeeptrkNo;
    TrkNoSys  DeltrkNo;

} DMSG_HMI_CORRELATIONSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_CORRELATIONSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_CORRELATIONSETSeq, DMSG_HMI_CORRELATIONSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_CORRELATIONSET_initialize(
        DMSG_HMI_CORRELATIONSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_CORRELATIONSET_initialize_ex(
        DMSG_HMI_CORRELATIONSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_CORRELATIONSET_finalize(
        DMSG_HMI_CORRELATIONSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_CORRELATIONSET_finalize_ex(
        DMSG_HMI_CORRELATIONSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_CORRELATIONSET_copy(
        DMSG_HMI_CORRELATIONSET* dst,
        const DMSG_HMI_CORRELATIONSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_CORRELATIONCLEARTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_CORRELATIONCLEAR
{
    TrkNoSys  trkNo;

} DMSG_HMI_CORRELATIONCLEAR;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_CORRELATIONCLEAR_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_CORRELATIONCLEARSeq, DMSG_HMI_CORRELATIONCLEAR);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_CORRELATIONCLEAR_initialize(
        DMSG_HMI_CORRELATIONCLEAR* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_CORRELATIONCLEAR_initialize_ex(
        DMSG_HMI_CORRELATIONCLEAR* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_CORRELATIONCLEAR_finalize(
        DMSG_HMI_CORRELATIONCLEAR* self);
                        
NDDSUSERDllExport
void DMSG_HMI_CORRELATIONCLEAR_finalize_ex(
        DMSG_HMI_CORRELATIONCLEAR* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_CORRELATIONCLEAR_copy(
        DMSG_HMI_CORRELATIONCLEAR* dst,
        const DMSG_HMI_CORRELATIONCLEAR* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TRACECHANGETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TRACECHANGE
{
    DDS_UnsignedLong  trkNo;
    DDS_UnsignedLong  nSensorType;

} DMSG_HMI_TRACECHANGE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TRACECHANGE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TRACECHANGESeq, DMSG_HMI_TRACECHANGE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRACECHANGE_initialize(
        DMSG_HMI_TRACECHANGE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRACECHANGE_initialize_ex(
        DMSG_HMI_TRACECHANGE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TRACECHANGE_finalize(
        DMSG_HMI_TRACECHANGE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TRACECHANGE_finalize_ex(
        DMSG_HMI_TRACECHANGE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRACECHANGE_copy(
        DMSG_HMI_TRACECHANGE* dst,
        const DMSG_HMI_TRACECHANGE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TRACKWEAPONRANGETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TRACKWEAPONRANGE
{
    TrkNoSys  trkNo;
    DDS_Float  fRange;

} DMSG_HMI_TRACKWEAPONRANGE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TRACKWEAPONRANGE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TRACKWEAPONRANGESeq, DMSG_HMI_TRACKWEAPONRANGE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRACKWEAPONRANGE_initialize(
        DMSG_HMI_TRACKWEAPONRANGE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRACKWEAPONRANGE_initialize_ex(
        DMSG_HMI_TRACKWEAPONRANGE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TRACKWEAPONRANGE_finalize(
        DMSG_HMI_TRACKWEAPONRANGE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TRACKWEAPONRANGE_finalize_ex(
        DMSG_HMI_TRACKWEAPONRANGE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRACKWEAPONRANGE_copy(
        DMSG_HMI_TRACKWEAPONRANGE* dst,
        const DMSG_HMI_TRACKWEAPONRANGE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TRACKSENSORRANGETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TRACKSENSORRANGE
{
    TrkNoSys  trkNo;
    DDS_Float  fRange;

} DMSG_HMI_TRACKSENSORRANGE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TRACKSENSORRANGE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TRACKSENSORRANGESeq, DMSG_HMI_TRACKSENSORRANGE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRACKSENSORRANGE_initialize(
        DMSG_HMI_TRACKSENSORRANGE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRACKSENSORRANGE_initialize_ex(
        DMSG_HMI_TRACKSENSORRANGE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TRACKSENSORRANGE_finalize(
        DMSG_HMI_TRACKSENSORRANGE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TRACKSENSORRANGE_finalize_ex(
        DMSG_HMI_TRACKSENSORRANGE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRACKSENSORRANGE_copy(
        DMSG_HMI_TRACKSENSORRANGE* dst,
        const DMSG_HMI_TRACKSENSORRANGE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_ANTIWEAPONWEIGHTTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_ANTIWEAPONWEIGHT
{
    TrkNoSys  trkNo;
    DDS_Long  nWeight;

} DMSG_HMI_ANTIWEAPONWEIGHT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_ANTIWEAPONWEIGHT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_ANTIWEAPONWEIGHTSeq, DMSG_HMI_ANTIWEAPONWEIGHT);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ANTIWEAPONWEIGHT_initialize(
        DMSG_HMI_ANTIWEAPONWEIGHT* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ANTIWEAPONWEIGHT_initialize_ex(
        DMSG_HMI_ANTIWEAPONWEIGHT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_ANTIWEAPONWEIGHT_finalize(
        DMSG_HMI_ANTIWEAPONWEIGHT* self);
                        
NDDSUSERDllExport
void DMSG_HMI_ANTIWEAPONWEIGHT_finalize_ex(
        DMSG_HMI_ANTIWEAPONWEIGHT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ANTIWEAPONWEIGHT_copy(
        DMSG_HMI_ANTIWEAPONWEIGHT* dst,
        const DMSG_HMI_ANTIWEAPONWEIGHT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TAGSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TAGSET
{
    DDS_UnsignedLong  trkNo;
    DDS_Char  cTagSet[6];

} DMSG_HMI_TAGSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TAGSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TAGSETSeq, DMSG_HMI_TAGSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TAGSET_initialize(
        DMSG_HMI_TAGSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TAGSET_initialize_ex(
        DMSG_HMI_TAGSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TAGSET_finalize(
        DMSG_HMI_TAGSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TAGSET_finalize_ex(
        DMSG_HMI_TAGSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TAGSET_copy(
        DMSG_HMI_TAGSET* dst,
        const DMSG_HMI_TAGSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_SONARSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_SONARSET
{
    DDS_UnsignedLong  trkNo;
    DDS_Char  cValid;
    DDS_Float  fRange;

} DMSG_HMI_SONARSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_SONARSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_SONARSETSeq, DMSG_HMI_SONARSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SONARSET_initialize(
        DMSG_HMI_SONARSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SONARSET_initialize_ex(
        DMSG_HMI_SONARSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_SONARSET_finalize(
        DMSG_HMI_SONARSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_SONARSET_finalize_ex(
        DMSG_HMI_SONARSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SONARSET_copy(
        DMSG_HMI_SONARSET* dst,
        const DMSG_HMI_SONARSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_WEAPONSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_WEAPONSET
{
    DDS_UnsignedLong  trkNo;
    DDS_Char  cValid;
    DDS_Float  fRange;

} DMSG_HMI_WEAPONSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_WEAPONSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_WEAPONSETSeq, DMSG_HMI_WEAPONSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONSET_initialize(
        DMSG_HMI_WEAPONSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONSET_initialize_ex(
        DMSG_HMI_WEAPONSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_WEAPONSET_finalize(
        DMSG_HMI_WEAPONSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_WEAPONSET_finalize_ex(
        DMSG_HMI_WEAPONSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONSET_copy(
        DMSG_HMI_WEAPONSET* dst,
        const DMSG_HMI_WEAPONSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_SUBCORRELATIONSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_SUBCORRELATIONSET
{
    DDS_UnsignedLong  KeeptrkNo;
    DDS_UnsignedLong  DeltrkNo;

} DMSG_HMI_SUBCORRELATIONSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_SUBCORRELATIONSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_SUBCORRELATIONSETSeq, DMSG_HMI_SUBCORRELATIONSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SUBCORRELATIONSET_initialize(
        DMSG_HMI_SUBCORRELATIONSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SUBCORRELATIONSET_initialize_ex(
        DMSG_HMI_SUBCORRELATIONSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_SUBCORRELATIONSET_finalize(
        DMSG_HMI_SUBCORRELATIONSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_SUBCORRELATIONSET_finalize_ex(
        DMSG_HMI_SUBCORRELATIONSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SUBCORRELATIONSET_copy(
        DMSG_HMI_SUBCORRELATIONSET* dst,
        const DMSG_HMI_SUBCORRELATIONSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_SUBCORRELATIONCLEARTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_SUBCORRELATIONCLEAR
{
    stSubSysTrackID  sSysTrkID;

} DMSG_HMI_SUBCORRELATIONCLEAR;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_SUBCORRELATIONCLEAR_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_SUBCORRELATIONCLEARSeq, DMSG_HMI_SUBCORRELATIONCLEAR);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SUBCORRELATIONCLEAR_initialize(
        DMSG_HMI_SUBCORRELATIONCLEAR* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SUBCORRELATIONCLEAR_initialize_ex(
        DMSG_HMI_SUBCORRELATIONCLEAR* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_SUBCORRELATIONCLEAR_finalize(
        DMSG_HMI_SUBCORRELATIONCLEAR* self);
                        
NDDSUSERDllExport
void DMSG_HMI_SUBCORRELATIONCLEAR_finalize_ex(
        DMSG_HMI_SUBCORRELATIONCLEAR* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SUBCORRELATIONCLEAR_copy(
        DMSG_HMI_SUBCORRELATIONCLEAR* dst,
        const DMSG_HMI_SUBCORRELATIONCLEAR* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TM_SYSTRACKDELTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TM_SYSTRACKDEL
{
    TrkNoSys  trkNo;

} DMSG_TM_SYSTRACKDEL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TM_SYSTRACKDEL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TM_SYSTRACKDELSeq, DMSG_TM_SYSTRACKDEL);
        
NDDSUSERDllExport
RTIBool DMSG_TM_SYSTRACKDEL_initialize(
        DMSG_TM_SYSTRACKDEL* self);
        
NDDSUSERDllExport
RTIBool DMSG_TM_SYSTRACKDEL_initialize_ex(
        DMSG_TM_SYSTRACKDEL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TM_SYSTRACKDEL_finalize(
        DMSG_TM_SYSTRACKDEL* self);
                        
NDDSUSERDllExport
void DMSG_TM_SYSTRACKDEL_finalize_ex(
        DMSG_TM_SYSTRACKDEL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TM_SYSTRACKDEL_copy(
        DMSG_TM_SYSTRACKDEL* dst,
        const DMSG_TM_SYSTRACKDEL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TM_SYSTRACKTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TM_SYSTRACK
{
    TrkNoSys  trkNo;
    DDS_Char  cWeaponLimit;
    DDS_Char  cEngageState;
    DDS_Char  cThreatEvaluation;
    DDS_Char  cEngageResult;
    DDS_UnsignedLong  nCreatedTimeTag;
    DDS_UnsignedLong  nUpdatedTimeTag;
    DDS_Char  cTrackType;
    DDS_Char  cTrackCategory;
    DDS_Char  cTrackIdentity;
    DDS_Char  cIFFMode1;
    DDS_UnsignedShort  sIFFMode2;
    DDS_UnsignedShort  sIFFMode3;
    DDS_UnsignedShort  sIFFModeC;
    DDS_Char  cIFFMode4;
    DDS_Char  cTrackName[30];
    DDS_UnsignedShort  sTrackNationality;
    DDS_Char  cTrackForm;
    rectHSys  position;
    coordiHSys  positionCHSys;
    DDS_Char  cTrackQuality;
    DDS_Char  cWeaponCapability;
    DDS_Float  fWeaponMaxRange;
    DDS_Float  fDatumSpd;
    DDS_Float  fDatumErr;
    DDS_UnsignedShort  sIdentificationDetailType;
    DDS_UnsignedShort  sIdentificationDetailMajor;
    DDS_UnsignedShort  sIdentificationDetailMinor;
    DDS_Float  fBearing;
    DDS_Float  fRange;
    DDS_Float  fCourse;
    DDS_Float  fSpeed;
    DDS_Char  ctag[6];
    DDS_Char  cLinkAlert;
    DDS_Char  cMissleCheck;
    DDS_Float  fElevation;
    DDS_Float  fBearingRate;
    DDS_Char  cSensorType;
    DDS_Float  fROC;
    DDS_Char  cLinkState;
    TrkNoSys  pairingTrk[4];
    TrkNoSys  associationTrk[4];

} DMSG_TM_SYSTRACK;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TM_SYSTRACK_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TM_SYSTRACKSeq, DMSG_TM_SYSTRACK);
        
NDDSUSERDllExport
RTIBool DMSG_TM_SYSTRACK_initialize(
        DMSG_TM_SYSTRACK* self);
        
NDDSUSERDllExport
RTIBool DMSG_TM_SYSTRACK_initialize_ex(
        DMSG_TM_SYSTRACK* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TM_SYSTRACK_finalize(
        DMSG_TM_SYSTRACK* self);
                        
NDDSUSERDllExport
void DMSG_TM_SYSTRACK_finalize_ex(
        DMSG_TM_SYSTRACK* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TM_SYSTRACK_copy(
        DMSG_TM_SYSTRACK* dst,
        const DMSG_TM_SYSTRACK* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TM_SWSTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TM_SWSTATE
{
    DDS_Char  cSoftwareState;

} DMSG_TM_SWSTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TM_SWSTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TM_SWSTATESeq, DMSG_TM_SWSTATE);
        
NDDSUSERDllExport
RTIBool DMSG_TM_SWSTATE_initialize(
        DMSG_TM_SWSTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_TM_SWSTATE_initialize_ex(
        DMSG_TM_SWSTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TM_SWSTATE_finalize(
        DMSG_TM_SWSTATE* self);
                        
NDDSUSERDllExport
void DMSG_TM_SWSTATE_finalize_ex(
        DMSG_TM_SWSTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TM_SWSTATE_copy(
        DMSG_TM_SWSTATE* dst,
        const DMSG_TM_SWSTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TM_SUBSYSTEMTRACKTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TM_SUBSYSTEMTRACK
{
    stSubSysTrackID  sSysTrkID;
    DDS_Long  nRepresentativeSensor;
    DDS_Char  cLinkState;
    stFullTime  sCreatedTime;
    stFullTime  sUpdatedTime;
    DDS_Char  nTrackSource;
    DDS_Char  nTrackType;
    DDS_Char  cTrackCategory;
    DDS_Char  cTrackIdentity;
    DDS_Char  cTrackName[30];
    DDS_UnsignedShort  sIdentificationDetailType;
    DDS_UnsignedShort  sIdentificationDetailMajor;
    DDS_UnsignedShort  sIdentificationDetailMinor;
    DDS_Char  cTag[6];
    DDS_Float  fBearing;
    DDS_Float  fBearingRate;
    DDS_Float  fRange;
    DDS_Float  fCourse;
    DDS_Float  fSpeed;
    coordiHSys  positionCHSys;
    DDS_Char  cSNRatio;
    DDS_Char  cPulseLv;
    DDS_Float  fAOB;
    DDS_Char  cSonarValid;
    DDS_Float  fSonarRange;
    DDS_Char  cWeaponValid;
    DDS_Float  fWeaponRange;

} DMSG_TM_SUBSYSTEMTRACK;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TM_SUBSYSTEMTRACK_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TM_SUBSYSTEMTRACKSeq, DMSG_TM_SUBSYSTEMTRACK);
        
NDDSUSERDllExport
RTIBool DMSG_TM_SUBSYSTEMTRACK_initialize(
        DMSG_TM_SUBSYSTEMTRACK* self);
        
NDDSUSERDllExport
RTIBool DMSG_TM_SUBSYSTEMTRACK_initialize_ex(
        DMSG_TM_SUBSYSTEMTRACK* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TM_SUBSYSTEMTRACK_finalize(
        DMSG_TM_SUBSYSTEMTRACK* self);
                        
NDDSUSERDllExport
void DMSG_TM_SUBSYSTEMTRACK_finalize_ex(
        DMSG_TM_SUBSYSTEMTRACK* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TM_SUBSYSTEMTRACK_copy(
        DMSG_TM_SUBSYSTEMTRACK* dst,
        const DMSG_TM_SUBSYSTEMTRACK* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TM_SUBSYSTRACKDELTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TM_SUBSYSTRACKDEL
{
    stSubSysTrackID  sSysTrkID;

} DMSG_TM_SUBSYSTRACKDEL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TM_SUBSYSTRACKDEL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TM_SUBSYSTRACKDELSeq, DMSG_TM_SUBSYSTRACKDEL);
        
NDDSUSERDllExport
RTIBool DMSG_TM_SUBSYSTRACKDEL_initialize(
        DMSG_TM_SUBSYSTRACKDEL* self);
        
NDDSUSERDllExport
RTIBool DMSG_TM_SUBSYSTRACKDEL_initialize_ex(
        DMSG_TM_SUBSYSTRACKDEL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TM_SUBSYSTRACKDEL_finalize(
        DMSG_TM_SUBSYSTRACKDEL* self);
                        
NDDSUSERDllExport
void DMSG_TM_SUBSYSTRACKDEL_finalize_ex(
        DMSG_TM_SUBSYSTRACKDEL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TM_SUBSYSTRACKDEL_copy(
        DMSG_TM_SUBSYSTRACKDEL* dst,
        const DMSG_TM_SUBSYSTRACKDEL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_WEAPONCTRLTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_WEAPONCTRL
{
    DDS_Char  cWeaponCtrl;

} DMSG_HMI_WEAPONCTRL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_WEAPONCTRL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_WEAPONCTRLSeq, DMSG_HMI_WEAPONCTRL);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONCTRL_initialize(
        DMSG_HMI_WEAPONCTRL* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONCTRL_initialize_ex(
        DMSG_HMI_WEAPONCTRL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_WEAPONCTRL_finalize(
        DMSG_HMI_WEAPONCTRL* self);
                        
NDDSUSERDllExport
void DMSG_HMI_WEAPONCTRL_finalize_ex(
        DMSG_HMI_WEAPONCTRL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONCTRL_copy(
        DMSG_HMI_WEAPONCTRL* dst,
        const DMSG_HMI_WEAPONCTRL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_FASTRESPONSEMODETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_FASTRESPONSEMODE
{
    DDS_Char  cFastResponseMode;

} DMSG_HMI_FASTRESPONSEMODE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_FASTRESPONSEMODE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_FASTRESPONSEMODESeq, DMSG_HMI_FASTRESPONSEMODE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FASTRESPONSEMODE_initialize(
        DMSG_HMI_FASTRESPONSEMODE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FASTRESPONSEMODE_initialize_ex(
        DMSG_HMI_FASTRESPONSEMODE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_FASTRESPONSEMODE_finalize(
        DMSG_HMI_FASTRESPONSEMODE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_FASTRESPONSEMODE_finalize_ex(
        DMSG_HMI_FASTRESPONSEMODE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FASTRESPONSEMODE_copy(
        DMSG_HMI_FASTRESPONSEMODE* dst,
        const DMSG_HMI_FASTRESPONSEMODE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_WEAPONUSELIMITTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_WEAPONUSELIMIT
{
    TrkNoSys  trkNo;
    DDS_Char  cWeaponLimit;

} DMSG_HMI_WEAPONUSELIMIT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_WEAPONUSELIMIT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_WEAPONUSELIMITSeq, DMSG_HMI_WEAPONUSELIMIT);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONUSELIMIT_initialize(
        DMSG_HMI_WEAPONUSELIMIT* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONUSELIMIT_initialize_ex(
        DMSG_HMI_WEAPONUSELIMIT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_WEAPONUSELIMIT_finalize(
        DMSG_HMI_WEAPONUSELIMIT* self);
                        
NDDSUSERDllExport
void DMSG_HMI_WEAPONUSELIMIT_finalize_ex(
        DMSG_HMI_WEAPONUSELIMIT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONUSELIMIT_copy(
        DMSG_HMI_WEAPONUSELIMIT* dst,
        const DMSG_HMI_WEAPONUSELIMIT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_ENGAGEMODESETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_ENGAGEMODESET
{
    DDS_Char  cMode;

} DMSG_HMI_ENGAGEMODESET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_ENGAGEMODESET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_ENGAGEMODESETSeq, DMSG_HMI_ENGAGEMODESET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGEMODESET_initialize(
        DMSG_HMI_ENGAGEMODESET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGEMODESET_initialize_ex(
        DMSG_HMI_ENGAGEMODESET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_ENGAGEMODESET_finalize(
        DMSG_HMI_ENGAGEMODESET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_ENGAGEMODESET_finalize_ex(
        DMSG_HMI_ENGAGEMODESET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGEMODESET_copy(
        DMSG_HMI_ENGAGEMODESET* dst,
        const DMSG_HMI_ENGAGEMODESET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_ENGAGEADVICEREQTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_ENGAGEADVICEREQ
{
    DDS_Char  cEngageType;
    TrkNoSys  trkNo;

} DMSG_HMI_ENGAGEADVICEREQ;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_ENGAGEADVICEREQ_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_ENGAGEADVICEREQSeq, DMSG_HMI_ENGAGEADVICEREQ);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGEADVICEREQ_initialize(
        DMSG_HMI_ENGAGEADVICEREQ* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGEADVICEREQ_initialize_ex(
        DMSG_HMI_ENGAGEADVICEREQ* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_ENGAGEADVICEREQ_finalize(
        DMSG_HMI_ENGAGEADVICEREQ* self);
                        
NDDSUSERDllExport
void DMSG_HMI_ENGAGEADVICEREQ_finalize_ex(
        DMSG_HMI_ENGAGEADVICEREQ* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGEADVICEREQ_copy(
        DMSG_HMI_ENGAGEADVICEREQ* dst,
        const DMSG_HMI_ENGAGEADVICEREQ* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_THREATDICISIONTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_THREATDICISION
{
    DDS_Char  cEngageType;
    DDS_Char  cTrackIdentity;
    DDS_Float  fMinRange;
    DDS_Float  fMaxRange;
    DDS_Float  fMinBearing;
    DDS_Float  fMaxBearing;
    DDS_Float  fMinSpd;
    DDS_Float  fMaxSpd;
    DDS_Float  fElevation;

} DMSG_HMI_THREATDICISION;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_THREATDICISION_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_THREATDICISIONSeq, DMSG_HMI_THREATDICISION);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_THREATDICISION_initialize(
        DMSG_HMI_THREATDICISION* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_THREATDICISION_initialize_ex(
        DMSG_HMI_THREATDICISION* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_THREATDICISION_finalize(
        DMSG_HMI_THREATDICISION* self);
                        
NDDSUSERDllExport
void DMSG_HMI_THREATDICISION_finalize_ex(
        DMSG_HMI_THREATDICISION* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_THREATDICISION_copy(
        DMSG_HMI_THREATDICISION* dst,
        const DMSG_HMI_THREATDICISION* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_WEAPONRANGETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_WEAPONRANGE
{
    DDS_Char  cWeaponID;
    DDS_UnsignedShort  sAirMinRange;
    DDS_UnsignedShort  sAirMaxRange;
    DDS_UnsignedShort  sMinRange;
    DDS_UnsignedShort  sMaxRange;
    DDS_UnsignedShort  sMaxFireRate;
    DDS_UnsignedShort  sMaxInventory;

} DMSG_HMI_WEAPONRANGE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_WEAPONRANGE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_WEAPONRANGESeq, DMSG_HMI_WEAPONRANGE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONRANGE_initialize(
        DMSG_HMI_WEAPONRANGE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONRANGE_initialize_ex(
        DMSG_HMI_WEAPONRANGE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_WEAPONRANGE_finalize(
        DMSG_HMI_WEAPONRANGE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_WEAPONRANGE_finalize_ex(
        DMSG_HMI_WEAPONRANGE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_WEAPONRANGE_copy(
        DMSG_HMI_WEAPONRANGE* dst,
        const DMSG_HMI_WEAPONRANGE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_SENSORRANGETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_SENSORRANGE
{
    DDS_Char  cSensorID;
    DDS_UnsignedShort  sAirMinRange;
    DDS_UnsignedShort  sAirMaxRange;
    DDS_UnsignedShort  sMinRange;
    DDS_UnsignedShort  sMaxRange;
    DDS_UnsignedShort  sAntenna;
    DDS_UnsignedShort  sFrequency;
    DDS_UnsignedShort  sPulsePeriod;
    DDS_UnsignedShort  sPulseWidth;

} DMSG_HMI_SENSORRANGE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_SENSORRANGE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_SENSORRANGESeq, DMSG_HMI_SENSORRANGE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SENSORRANGE_initialize(
        DMSG_HMI_SENSORRANGE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SENSORRANGE_initialize_ex(
        DMSG_HMI_SENSORRANGE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_SENSORRANGE_finalize(
        DMSG_HMI_SENSORRANGE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_SENSORRANGE_finalize_ex(
        DMSG_HMI_SENSORRANGE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SENSORRANGE_copy(
        DMSG_HMI_SENSORRANGE* dst,
        const DMSG_HMI_SENSORRANGE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_ENGAGEADVICEMODIFYTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_ENGAGEADVICEMODIFY
{
    TrkNoSys  trkNo;
    DDS_Char  cEngageType;
    DDS_Char  cTrackRdrID;
    DDS_Char  cRdrType;
    DDS_Char  cChannelID;
    DDS_Char  cWeaponID;
    DDS_Char  cConsoleID;

} DMSG_HMI_ENGAGEADVICEMODIFY;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_ENGAGEADVICEMODIFY_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_ENGAGEADVICEMODIFYSeq, DMSG_HMI_ENGAGEADVICEMODIFY);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGEADVICEMODIFY_initialize(
        DMSG_HMI_ENGAGEADVICEMODIFY* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGEADVICEMODIFY_initialize_ex(
        DMSG_HMI_ENGAGEADVICEMODIFY* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_ENGAGEADVICEMODIFY_finalize(
        DMSG_HMI_ENGAGEADVICEMODIFY* self);
                        
NDDSUSERDllExport
void DMSG_HMI_ENGAGEADVICEMODIFY_finalize_ex(
        DMSG_HMI_ENGAGEADVICEMODIFY* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGEADVICEMODIFY_copy(
        DMSG_HMI_ENGAGEADVICEMODIFY* dst,
        const DMSG_HMI_ENGAGEADVICEMODIFY* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_CLEARENGAGEASSIGNTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_CLEARENGAGEASSIGN
{
    DDS_Char  cEngageType;
    TrkNoSys  trkNo;
    DDS_Char  cReleaseType;
    DDS_Char  cTrackRdrID;
    DDS_Char  cRdrType;
    DDS_Char  cChannelID;
    DDS_Char  cWeaponID;
    DDS_Char  cConsoleID;
    DDS_Boolean  bUnit;
    DDS_Char  cUnitID;

} DMSG_HMI_CLEARENGAGEASSIGN;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_CLEARENGAGEASSIGN_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_CLEARENGAGEASSIGNSeq, DMSG_HMI_CLEARENGAGEASSIGN);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_CLEARENGAGEASSIGN_initialize(
        DMSG_HMI_CLEARENGAGEASSIGN* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_CLEARENGAGEASSIGN_initialize_ex(
        DMSG_HMI_CLEARENGAGEASSIGN* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_CLEARENGAGEASSIGN_finalize(
        DMSG_HMI_CLEARENGAGEASSIGN* self);
                        
NDDSUSERDllExport
void DMSG_HMI_CLEARENGAGEASSIGN_finalize_ex(
        DMSG_HMI_CLEARENGAGEASSIGN* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_CLEARENGAGEASSIGN_copy(
        DMSG_HMI_CLEARENGAGEASSIGN* dst,
        const DMSG_HMI_CLEARENGAGEASSIGN* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_THREATWEIGHTTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_THREATWEIGHT
{
    TrkNoSys  trkNo;
    DDS_Char  cWeight;

} DMSG_HMI_THREATWEIGHT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_THREATWEIGHT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_THREATWEIGHTSeq, DMSG_HMI_THREATWEIGHT);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_THREATWEIGHT_initialize(
        DMSG_HMI_THREATWEIGHT* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_THREATWEIGHT_initialize_ex(
        DMSG_HMI_THREATWEIGHT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_THREATWEIGHT_finalize(
        DMSG_HMI_THREATWEIGHT* self);
                        
NDDSUSERDllExport
void DMSG_HMI_THREATWEIGHT_finalize_ex(
        DMSG_HMI_THREATWEIGHT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_THREATWEIGHT_copy(
        DMSG_HMI_THREATWEIGHT* dst,
        const DMSG_HMI_THREATWEIGHT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_DEFENSEMODETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_DEFENSEMODE
{
    DDS_Char  cDefenseMode;

} DMSG_HMI_DEFENSEMODE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_DEFENSEMODE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_DEFENSEMODESeq, DMSG_HMI_DEFENSEMODE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_DEFENSEMODE_initialize(
        DMSG_HMI_DEFENSEMODE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_DEFENSEMODE_initialize_ex(
        DMSG_HMI_DEFENSEMODE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_DEFENSEMODE_finalize(
        DMSG_HMI_DEFENSEMODE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_DEFENSEMODE_finalize_ex(
        DMSG_HMI_DEFENSEMODE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_DEFENSEMODE_copy(
        DMSG_HMI_DEFENSEMODE* dst,
        const DMSG_HMI_DEFENSEMODE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_FIREPERMITTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_FIREPERMIT
{
    DDS_Char  cWeaponID;
    DDS_Char  cFire;

} DMSG_HMI_FIREPERMIT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_FIREPERMIT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_FIREPERMITSeq, DMSG_HMI_FIREPERMIT);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIREPERMIT_initialize(
        DMSG_HMI_FIREPERMIT* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIREPERMIT_initialize_ex(
        DMSG_HMI_FIREPERMIT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_FIREPERMIT_finalize(
        DMSG_HMI_FIREPERMIT* self);
                        
NDDSUSERDllExport
void DMSG_HMI_FIREPERMIT_finalize_ex(
        DMSG_HMI_FIREPERMIT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIREPERMIT_copy(
        DMSG_HMI_FIREPERMIT* dst,
        const DMSG_HMI_FIREPERMIT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_ENGAGECANCELTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_ENGAGECANCEL
{
    DDS_UnsignedShort  AssignNum;

} DMSG_HMI_ENGAGECANCEL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_ENGAGECANCEL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_ENGAGECANCELSeq, DMSG_HMI_ENGAGECANCEL);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGECANCEL_initialize(
        DMSG_HMI_ENGAGECANCEL* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGECANCEL_initialize_ex(
        DMSG_HMI_ENGAGECANCEL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_ENGAGECANCEL_finalize(
        DMSG_HMI_ENGAGECANCEL* self);
                        
NDDSUSERDllExport
void DMSG_HMI_ENGAGECANCEL_finalize_ex(
        DMSG_HMI_ENGAGECANCEL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGECANCEL_copy(
        DMSG_HMI_ENGAGECANCEL* dst,
        const DMSG_HMI_ENGAGECANCEL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_HITEVALUATIONSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_HITEVALUATIONSET
{
    TrkNoSys  trkNo;
    DDS_UnsignedShort  AssignNum;
    DDS_Char  cKillResult;

} DMSG_HMI_HITEVALUATIONSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_HITEVALUATIONSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_HITEVALUATIONSETSeq, DMSG_HMI_HITEVALUATIONSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_HITEVALUATIONSET_initialize(
        DMSG_HMI_HITEVALUATIONSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_HITEVALUATIONSET_initialize_ex(
        DMSG_HMI_HITEVALUATIONSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_HITEVALUATIONSET_finalize(
        DMSG_HMI_HITEVALUATIONSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_HITEVALUATIONSET_finalize_ex(
        DMSG_HMI_HITEVALUATIONSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_HITEVALUATIONSET_copy(
        DMSG_HMI_HITEVALUATIONSET* dst,
        const DMSG_HMI_HITEVALUATIONSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_ASSIGNCONSOLETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_ASSIGNCONSOLE
{
    DDS_Char  cConsoleID;
    DDS_Char  byTube;
    DDS_Char  byTubeNum;

} DMSG_HMI_ASSIGNCONSOLE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_ASSIGNCONSOLE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_ASSIGNCONSOLESeq, DMSG_HMI_ASSIGNCONSOLE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ASSIGNCONSOLE_initialize(
        DMSG_HMI_ASSIGNCONSOLE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ASSIGNCONSOLE_initialize_ex(
        DMSG_HMI_ASSIGNCONSOLE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_ASSIGNCONSOLE_finalize(
        DMSG_HMI_ASSIGNCONSOLE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_ASSIGNCONSOLE_finalize_ex(
        DMSG_HMI_ASSIGNCONSOLE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ASSIGNCONSOLE_copy(
        DMSG_HMI_ASSIGNCONSOLE* dst,
        const DMSG_HMI_ASSIGNCONSOLE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_GUIDEDWEAPONPERMITTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_GUIDEDWEAPONPERMIT
{
    DDS_Char  cConsoleID;
    DDS_Char  cTubeID;
    DDS_Char  byFireOk;

} DMSG_HMI_GUIDEDWEAPONPERMIT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_GUIDEDWEAPONPERMIT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_GUIDEDWEAPONPERMITSeq, DMSG_HMI_GUIDEDWEAPONPERMIT);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_GUIDEDWEAPONPERMIT_initialize(
        DMSG_HMI_GUIDEDWEAPONPERMIT* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_GUIDEDWEAPONPERMIT_initialize_ex(
        DMSG_HMI_GUIDEDWEAPONPERMIT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_GUIDEDWEAPONPERMIT_finalize(
        DMSG_HMI_GUIDEDWEAPONPERMIT* self);
                        
NDDSUSERDllExport
void DMSG_HMI_GUIDEDWEAPONPERMIT_finalize_ex(
        DMSG_HMI_GUIDEDWEAPONPERMIT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_GUIDEDWEAPONPERMIT_copy(
        DMSG_HMI_GUIDEDWEAPONPERMIT* dst,
        const DMSG_HMI_GUIDEDWEAPONPERMIT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_ASSIGNTUBETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_ASSIGNTUBE
{
    DDS_Char  cConsoleID;
    TrkNoSys  trkNo;
    DDS_Char  byTube;
    DDS_Char  byTubeNum;

} DMSG_HMI_ASSIGNTUBE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_ASSIGNTUBE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_ASSIGNTUBESeq, DMSG_HMI_ASSIGNTUBE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ASSIGNTUBE_initialize(
        DMSG_HMI_ASSIGNTUBE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ASSIGNTUBE_initialize_ex(
        DMSG_HMI_ASSIGNTUBE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_ASSIGNTUBE_finalize(
        DMSG_HMI_ASSIGNTUBE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_ASSIGNTUBE_finalize_ex(
        DMSG_HMI_ASSIGNTUBE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ASSIGNTUBE_copy(
        DMSG_HMI_ASSIGNTUBE* dst,
        const DMSG_HMI_ASSIGNTUBE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_ENGAGEPLANSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_ENGAGEPLANSET
{
    DDS_Char  cEngagePlanCtrl;
    TrkNoSys  trkNo;

} DMSG_HMI_ENGAGEPLANSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_ENGAGEPLANSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_ENGAGEPLANSETSeq, DMSG_HMI_ENGAGEPLANSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGEPLANSET_initialize(
        DMSG_HMI_ENGAGEPLANSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGEPLANSET_initialize_ex(
        DMSG_HMI_ENGAGEPLANSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_ENGAGEPLANSET_finalize(
        DMSG_HMI_ENGAGEPLANSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_ENGAGEPLANSET_finalize_ex(
        DMSG_HMI_ENGAGEPLANSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGEPLANSET_copy(
        DMSG_HMI_ENGAGEPLANSET* dst,
        const DMSG_HMI_ENGAGEPLANSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_FIREPERMITKEYSTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_FIREPERMITKEYSTATE
{
    DDS_Char  cFirePermitKey;

} DMSG_HMI_FIREPERMITKEYSTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_FIREPERMITKEYSTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_FIREPERMITKEYSTATESeq, DMSG_HMI_FIREPERMITKEYSTATE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIREPERMITKEYSTATE_initialize(
        DMSG_HMI_FIREPERMITKEYSTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIREPERMITKEYSTATE_initialize_ex(
        DMSG_HMI_FIREPERMITKEYSTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_FIREPERMITKEYSTATE_finalize(
        DMSG_HMI_FIREPERMITKEYSTATE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_FIREPERMITKEYSTATE_finalize_ex(
        DMSG_HMI_FIREPERMITKEYSTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIREPERMITKEYSTATE_copy(
        DMSG_HMI_FIREPERMITKEYSTATE* dst,
        const DMSG_HMI_FIREPERMITKEYSTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_FIREPERMITBTNSTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_FIREPERMITBTNSTATE
{
    DDS_Char  cFirePermitBtn;

} DMSG_HMI_FIREPERMITBTNSTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_FIREPERMITBTNSTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_FIREPERMITBTNSTATESeq, DMSG_HMI_FIREPERMITBTNSTATE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIREPERMITBTNSTATE_initialize(
        DMSG_HMI_FIREPERMITBTNSTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIREPERMITBTNSTATE_initialize_ex(
        DMSG_HMI_FIREPERMITBTNSTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_FIREPERMITBTNSTATE_finalize(
        DMSG_HMI_FIREPERMITBTNSTATE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_FIREPERMITBTNSTATE_finalize_ex(
        DMSG_HMI_FIREPERMITBTNSTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIREPERMITBTNSTATE_copy(
        DMSG_HMI_FIREPERMITBTNSTATE* dst,
        const DMSG_HMI_FIREPERMITBTNSTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_FIRECMDTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_FIRECMD
{
    DDS_Char  byConsoleID;
    DDS_Char  byTubeNum;
    DDS_Char  byLinkTubeNum;
    DDS_Char  byTubeType;
    DDS_Char  byFirectrl;

} DMSG_HMI_FIRECMD;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_FIRECMD_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_FIRECMDSeq, DMSG_HMI_FIRECMD);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIRECMD_initialize(
        DMSG_HMI_FIRECMD* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIRECMD_initialize_ex(
        DMSG_HMI_FIRECMD* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_FIRECMD_finalize(
        DMSG_HMI_FIRECMD* self);
                        
NDDSUSERDllExport
void DMSG_HMI_FIRECMD_finalize_ex(
        DMSG_HMI_FIRECMD* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIRECMD_copy(
        DMSG_HMI_FIRECMD* dst,
        const DMSG_HMI_FIRECMD* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_ENGAGEASSIGNCMDTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_ENGAGEASSIGNCMD
{
    TrkNoSys  trkNo;
    DDS_Long  nAssignmentPlanID;

} DMSG_HMI_ENGAGEASSIGNCMD;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_ENGAGEASSIGNCMD_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_ENGAGEASSIGNCMDSeq, DMSG_HMI_ENGAGEASSIGNCMD);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGEASSIGNCMD_initialize(
        DMSG_HMI_ENGAGEASSIGNCMD* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGEASSIGNCMD_initialize_ex(
        DMSG_HMI_ENGAGEASSIGNCMD* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_ENGAGEASSIGNCMD_finalize(
        DMSG_HMI_ENGAGEASSIGNCMD* self);
                        
NDDSUSERDllExport
void DMSG_HMI_ENGAGEASSIGNCMD_finalize_ex(
        DMSG_HMI_ENGAGEASSIGNCMD* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ENGAGEASSIGNCMD_copy(
        DMSG_HMI_ENGAGEASSIGNCMD* dst,
        const DMSG_HMI_ENGAGEASSIGNCMD* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_FIRINGCMDTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_FIRINGCMD
{
    DDS_UnsignedLong  trkNo;
    DDS_Char  cWeaponID;
    DDS_Char  cFireCommand;

} DMSG_HMI_FIRINGCMD;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_FIRINGCMD_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_FIRINGCMDSeq, DMSG_HMI_FIRINGCMD);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIRINGCMD_initialize(
        DMSG_HMI_FIRINGCMD* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIRINGCMD_initialize_ex(
        DMSG_HMI_FIRINGCMD* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_FIRINGCMD_finalize(
        DMSG_HMI_FIRINGCMD* self);
                        
NDDSUSERDllExport
void DMSG_HMI_FIRINGCMD_finalize_ex(
        DMSG_HMI_FIRINGCMD* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIRINGCMD_copy(
        DMSG_HMI_FIRINGCMD* dst,
        const DMSG_HMI_FIRINGCMD* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_ENGAGEDELTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_ENGAGEDEL
{
    TrkNoSys  trkNo;
    DDS_UnsignedShort  AssignNum;

} DMSG_EC_ENGAGEDEL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_ENGAGEDEL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_ENGAGEDELSeq, DMSG_EC_ENGAGEDEL);
        
NDDSUSERDllExport
RTIBool DMSG_EC_ENGAGEDEL_initialize(
        DMSG_EC_ENGAGEDEL* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_ENGAGEDEL_initialize_ex(
        DMSG_EC_ENGAGEDEL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_ENGAGEDEL_finalize(
        DMSG_EC_ENGAGEDEL* self);
                        
NDDSUSERDllExport
void DMSG_EC_ENGAGEDEL_finalize_ex(
        DMSG_EC_ENGAGEDEL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_ENGAGEDEL_copy(
        DMSG_EC_ENGAGEDEL* dst,
        const DMSG_EC_ENGAGEDEL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_MANUALENGAGEASSIGNTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_MANUALENGAGEASSIGN
{
    DDS_Char  cEngageType;
    TrkNoSys  trkNo;
    DDS_Char  cTrackRdrID;
    DDS_Char  cRdrType;
    DDS_Char  cChannelID;
    DDS_Char  cWeaponID;
    DDS_Char  cConsoleID;
    time1  EngageTime[6];

} DMSG_HMI_MANUALENGAGEASSIGN;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_MANUALENGAGEASSIGN_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_MANUALENGAGEASSIGNSeq, DMSG_HMI_MANUALENGAGEASSIGN);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_MANUALENGAGEASSIGN_initialize(
        DMSG_HMI_MANUALENGAGEASSIGN* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_MANUALENGAGEASSIGN_initialize_ex(
        DMSG_HMI_MANUALENGAGEASSIGN* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_MANUALENGAGEASSIGN_finalize(
        DMSG_HMI_MANUALENGAGEASSIGN* self);
                        
NDDSUSERDllExport
void DMSG_HMI_MANUALENGAGEASSIGN_finalize_ex(
        DMSG_HMI_MANUALENGAGEASSIGN* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_MANUALENGAGEASSIGN_copy(
        DMSG_HMI_MANUALENGAGEASSIGN* dst,
        const DMSG_HMI_MANUALENGAGEASSIGN* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_EMERGENCYFIRETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_EMERGENCYFIRE
{
    TrkNoSys  trkNo;
    DDS_Char  weapon_id;

} DMSG_HMI_EMERGENCYFIRE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_EMERGENCYFIRE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_EMERGENCYFIRESeq, DMSG_HMI_EMERGENCYFIRE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_EMERGENCYFIRE_initialize(
        DMSG_HMI_EMERGENCYFIRE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_EMERGENCYFIRE_initialize_ex(
        DMSG_HMI_EMERGENCYFIRE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_EMERGENCYFIRE_finalize(
        DMSG_HMI_EMERGENCYFIRE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_EMERGENCYFIRE_finalize_ex(
        DMSG_HMI_EMERGENCYFIRE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_EMERGENCYFIRE_copy(
        DMSG_HMI_EMERGENCYFIRE* dst,
        const DMSG_HMI_EMERGENCYFIRE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_SAMTARGETDESIGTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_SAMTARGETDESIG
{
    DDS_Long  nSysTrackNum;
    DDS_Char  byMissileCnt;
    DDS_Char  byAttackMode;
    DDS_Char  byLaunchMode;
    DDS_Char  byAttackType;
    DDS_Char  byAttackTimeType;
    DDS_Char  byAttackTimeHour;
    DDS_Char  byAttackTimeMin;
    DDS_Char  byEngagementMode;
    DDS_Char  byEngagementCommand;
    DDS_Char  byPositionValid;
    DDS_Double  dLat;
    DDS_Double  dLon;
    DDS_Char  byBearingValid;
    DDS_Float  fBearing;
    DDS_Char  byRangeValid;
    DDS_Float  fRange;
    DDS_Char  byCourseValid;
    DDS_Float  fCourse;
    DDS_Char  bySpeedValid;
    DDS_Float  fSpeed;
    DDS_Char  byTargetForm;
    DDS_Char  byTargetType;
    DDS_Char  byDetectSource;
    DDS_Char  byPlatform[10];

} DMSG_HMI_SAMTARGETDESIG;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_SAMTARGETDESIG_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_SAMTARGETDESIGSeq, DMSG_HMI_SAMTARGETDESIG);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SAMTARGETDESIG_initialize(
        DMSG_HMI_SAMTARGETDESIG* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SAMTARGETDESIG_initialize_ex(
        DMSG_HMI_SAMTARGETDESIG* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_SAMTARGETDESIG_finalize(
        DMSG_HMI_SAMTARGETDESIG* self);
                        
NDDSUSERDllExport
void DMSG_HMI_SAMTARGETDESIG_finalize_ex(
        DMSG_HMI_SAMTARGETDESIG* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SAMTARGETDESIG_copy(
        DMSG_HMI_SAMTARGETDESIG* dst,
        const DMSG_HMI_SAMTARGETDESIG* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_GUIDEDWEAPONPERMITTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_GUIDEDWEAPONPERMIT
{
    DDS_Char  byTubeNum;
    DDS_Char  byFireOk;

} DMSG_EC_GUIDEDWEAPONPERMIT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_GUIDEDWEAPONPERMIT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_GUIDEDWEAPONPERMITSeq, DMSG_EC_GUIDEDWEAPONPERMIT);
        
NDDSUSERDllExport
RTIBool DMSG_EC_GUIDEDWEAPONPERMIT_initialize(
        DMSG_EC_GUIDEDWEAPONPERMIT* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_GUIDEDWEAPONPERMIT_initialize_ex(
        DMSG_EC_GUIDEDWEAPONPERMIT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_GUIDEDWEAPONPERMIT_finalize(
        DMSG_EC_GUIDEDWEAPONPERMIT* self);
                        
NDDSUSERDllExport
void DMSG_EC_GUIDEDWEAPONPERMIT_finalize_ex(
        DMSG_EC_GUIDEDWEAPONPERMIT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_GUIDEDWEAPONPERMIT_copy(
        DMSG_EC_GUIDEDWEAPONPERMIT* dst,
        const DMSG_EC_GUIDEDWEAPONPERMIT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TRRTRACKINGCMDTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TRRTRACKINGCMD
{
    TrkNoSys  trkNo;
    DDS_Char  byTrackingStatus;
    DDS_Double  dBearing;
    DDS_Double  dElevation;
    DDS_Double  dDistance;

} DMSG_HMI_TRRTRACKINGCMD;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TRRTRACKINGCMD_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TRRTRACKINGCMDSeq, DMSG_HMI_TRRTRACKINGCMD);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRTRACKINGCMD_initialize(
        DMSG_HMI_TRRTRACKINGCMD* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRTRACKINGCMD_initialize_ex(
        DMSG_HMI_TRRTRACKINGCMD* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TRRTRACKINGCMD_finalize(
        DMSG_HMI_TRRTRACKINGCMD* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TRRTRACKINGCMD_finalize_ex(
        DMSG_HMI_TRRTRACKINGCMD* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TRRTRACKINGCMD_copy(
        DMSG_HMI_TRRTRACKINGCMD* dst,
        const DMSG_HMI_TRRTRACKINGCMD* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_EOTSSUBTRACKINGSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_EOTSSUBTRACKINGSET
{
    TrkNoSys  trkNo;
    DDS_Char  bySubTracking;
    DDS_Double  dBearing;
    DDS_Double  dAltitude;
    DDS_Char  bySubTrackingSensor;

} DMSG_HMI_EOTSSUBTRACKINGSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_EOTSSUBTRACKINGSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_EOTSSUBTRACKINGSETSeq, DMSG_HMI_EOTSSUBTRACKINGSET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_EOTSSUBTRACKINGSET_initialize(
        DMSG_HMI_EOTSSUBTRACKINGSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_EOTSSUBTRACKINGSET_initialize_ex(
        DMSG_HMI_EOTSSUBTRACKINGSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_EOTSSUBTRACKINGSET_finalize(
        DMSG_HMI_EOTSSUBTRACKINGSET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_EOTSSUBTRACKINGSET_finalize_ex(
        DMSG_HMI_EOTSSUBTRACKINGSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_EOTSSUBTRACKINGSET_copy(
        DMSG_HMI_EOTSSUBTRACKINGSET* dst,
        const DMSG_HMI_EOTSSUBTRACKINGSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TDSRTWSTARGETDESIGTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TDSRTWSTARGETDESIG
{
    TrkNoSys  trkNo;
    DDS_Char  byTrackingStatus;
    DDS_Char  TrackingChannel;
    DDS_Double  dPosX;
    DDS_Double  dPosY;
    DDS_Double  dPosZ;

} DMSG_HMI_TDSRTWSTARGETDESIG;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TDSRTWSTARGETDESIG_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TDSRTWSTARGETDESIGSeq, DMSG_HMI_TDSRTWSTARGETDESIG);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRTWSTARGETDESIG_initialize(
        DMSG_HMI_TDSRTWSTARGETDESIG* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRTWSTARGETDESIG_initialize_ex(
        DMSG_HMI_TDSRTWSTARGETDESIG* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TDSRTWSTARGETDESIG_finalize(
        DMSG_HMI_TDSRTWSTARGETDESIG* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TDSRTWSTARGETDESIG_finalize_ex(
        DMSG_HMI_TDSRTWSTARGETDESIG* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TDSRTWSTARGETDESIG_copy(
        DMSG_HMI_TDSRTWSTARGETDESIG* dst,
        const DMSG_HMI_TDSRTWSTARGETDESIG* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMISUB_ENGAGECANCELTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMISUB_ENGAGECANCEL
{
    TrkNoSys  trkNo;
    DDS_Char  byTubeID;
    DDS_Char  byTube;

} DMSG_HMISUB_ENGAGECANCEL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMISUB_ENGAGECANCEL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMISUB_ENGAGECANCELSeq, DMSG_HMISUB_ENGAGECANCEL);
        
NDDSUSERDllExport
RTIBool DMSG_HMISUB_ENGAGECANCEL_initialize(
        DMSG_HMISUB_ENGAGECANCEL* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMISUB_ENGAGECANCEL_initialize_ex(
        DMSG_HMISUB_ENGAGECANCEL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMISUB_ENGAGECANCEL_finalize(
        DMSG_HMISUB_ENGAGECANCEL* self);
                        
NDDSUSERDllExport
void DMSG_HMISUB_ENGAGECANCEL_finalize_ex(
        DMSG_HMISUB_ENGAGECANCEL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMISUB_ENGAGECANCEL_copy(
        DMSG_HMISUB_ENGAGECANCEL* dst,
        const DMSG_HMISUB_ENGAGECANCEL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_SUBENGAGEDELTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_SUBENGAGEDEL
{
    TrkNoSys  trkNo;
    DDS_Char  byTubeID;
    DDS_Char  byTube;

} DMSG_EC_SUBENGAGEDEL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_SUBENGAGEDEL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_SUBENGAGEDELSeq, DMSG_EC_SUBENGAGEDEL);
        
NDDSUSERDllExport
RTIBool DMSG_EC_SUBENGAGEDEL_initialize(
        DMSG_EC_SUBENGAGEDEL* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_SUBENGAGEDEL_initialize_ex(
        DMSG_EC_SUBENGAGEDEL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_SUBENGAGEDEL_finalize(
        DMSG_EC_SUBENGAGEDEL* self);
                        
NDDSUSERDllExport
void DMSG_EC_SUBENGAGEDEL_finalize_ex(
        DMSG_EC_SUBENGAGEDEL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_SUBENGAGEDEL_copy(
        DMSG_EC_SUBENGAGEDEL* dst,
        const DMSG_EC_SUBENGAGEDEL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_FIREMODETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_FIREMODE
{
    DDS_Char  cMode;

} DMSG_HMI_FIREMODE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_FIREMODE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_FIREMODESeq, DMSG_HMI_FIREMODE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIREMODE_initialize(
        DMSG_HMI_FIREMODE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIREMODE_initialize_ex(
        DMSG_HMI_FIREMODE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_FIREMODE_finalize(
        DMSG_HMI_FIREMODE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_FIREMODE_finalize_ex(
        DMSG_HMI_FIREMODE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_FIREMODE_copy(
        DMSG_HMI_FIREMODE* dst,
        const DMSG_HMI_FIREMODE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_ASSIGNSLTSTUBETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_ASSIGNSLTSTUBE
{
    DDS_Char  cTubeID;
    DDS_Char  cTubeDirection;

} DMSG_HMI_ASSIGNSLTSTUBE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_ASSIGNSLTSTUBE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_ASSIGNSLTSTUBESeq, DMSG_HMI_ASSIGNSLTSTUBE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ASSIGNSLTSTUBE_initialize(
        DMSG_HMI_ASSIGNSLTSTUBE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ASSIGNSLTSTUBE_initialize_ex(
        DMSG_HMI_ASSIGNSLTSTUBE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_ASSIGNSLTSTUBE_finalize(
        DMSG_HMI_ASSIGNSLTSTUBE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_ASSIGNSLTSTUBE_finalize_ex(
        DMSG_HMI_ASSIGNSLTSTUBE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_ASSIGNSLTSTUBE_copy(
        DMSG_HMI_ASSIGNSLTSTUBE* dst,
        const DMSG_HMI_ASSIGNSLTSTUBE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TEWA_ENGAGEADVICEDELTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TEWA_ENGAGEADVICEDEL
{
    TrkNoSys  trkNo;

} DMSG_TEWA_ENGAGEADVICEDEL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TEWA_ENGAGEADVICEDEL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TEWA_ENGAGEADVICEDELSeq, DMSG_TEWA_ENGAGEADVICEDEL);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_ENGAGEADVICEDEL_initialize(
        DMSG_TEWA_ENGAGEADVICEDEL* self);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_ENGAGEADVICEDEL_initialize_ex(
        DMSG_TEWA_ENGAGEADVICEDEL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TEWA_ENGAGEADVICEDEL_finalize(
        DMSG_TEWA_ENGAGEADVICEDEL* self);
                        
NDDSUSERDllExport
void DMSG_TEWA_ENGAGEADVICEDEL_finalize_ex(
        DMSG_TEWA_ENGAGEADVICEDEL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_ENGAGEADVICEDEL_copy(
        DMSG_TEWA_ENGAGEADVICEDEL* dst,
        const DMSG_TEWA_ENGAGEADVICEDEL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TEWA_FASTRESPONSECHANNELTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TEWA_FASTRESPONSECHANNEL
{
    DDS_Char  cEngageType;
    TrkNoSys  trkNo;
    DDS_Char  cTrackRdrID;
    DDS_Char  cChannelID;
    DDS_Char  cWeaponID;
    DDS_Char  cConsoleID;

} DMSG_TEWA_FASTRESPONSECHANNEL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TEWA_FASTRESPONSECHANNEL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TEWA_FASTRESPONSECHANNELSeq, DMSG_TEWA_FASTRESPONSECHANNEL);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_FASTRESPONSECHANNEL_initialize(
        DMSG_TEWA_FASTRESPONSECHANNEL* self);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_FASTRESPONSECHANNEL_initialize_ex(
        DMSG_TEWA_FASTRESPONSECHANNEL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TEWA_FASTRESPONSECHANNEL_finalize(
        DMSG_TEWA_FASTRESPONSECHANNEL* self);
                        
NDDSUSERDllExport
void DMSG_TEWA_FASTRESPONSECHANNEL_finalize_ex(
        DMSG_TEWA_FASTRESPONSECHANNEL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_FASTRESPONSECHANNEL_copy(
        DMSG_TEWA_FASTRESPONSECHANNEL* dst,
        const DMSG_TEWA_FASTRESPONSECHANNEL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TEWA_ENGAGEADVICETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TEWA_ENGAGEADVICE
{
    DDS_Char  cEngageType;
    TrkNoSys  trkNo;
    DDS_Char  cEngageAvailability;
    DDS_Char  cTrackRdrID;
    DDS_Char  cChannelID;
    DDS_Char  cWeaponID;
    DDS_Char  cConsoleID;
    DDS_Char  cPriority;
    time1  EngageTime[6];

} DMSG_TEWA_ENGAGEADVICE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TEWA_ENGAGEADVICE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TEWA_ENGAGEADVICESeq, DMSG_TEWA_ENGAGEADVICE);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_ENGAGEADVICE_initialize(
        DMSG_TEWA_ENGAGEADVICE* self);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_ENGAGEADVICE_initialize_ex(
        DMSG_TEWA_ENGAGEADVICE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TEWA_ENGAGEADVICE_finalize(
        DMSG_TEWA_ENGAGEADVICE* self);
                        
NDDSUSERDllExport
void DMSG_TEWA_ENGAGEADVICE_finalize_ex(
        DMSG_TEWA_ENGAGEADVICE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_ENGAGEADVICE_copy(
        DMSG_TEWA_ENGAGEADVICE* dst,
        const DMSG_TEWA_ENGAGEADVICE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TEWA_THREATDELTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TEWA_THREATDEL
{
    TrkNoSys  trkNo;

} DMSG_TEWA_THREATDEL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TEWA_THREATDEL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TEWA_THREATDELSeq, DMSG_TEWA_THREATDEL);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_THREATDEL_initialize(
        DMSG_TEWA_THREATDEL* self);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_THREATDEL_initialize_ex(
        DMSG_TEWA_THREATDEL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TEWA_THREATDEL_finalize(
        DMSG_TEWA_THREATDEL* self);
                        
NDDSUSERDllExport
void DMSG_TEWA_THREATDEL_finalize_ex(
        DMSG_TEWA_THREATDEL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_THREATDEL_copy(
        DMSG_TEWA_THREATDEL* dst,
        const DMSG_TEWA_THREATDEL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TEWA_AIRTHREATEVALUATIONTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TEWA_AIRTHREATEVALUATION
{
    TrkNoSys  trkNo;
    DDS_Char  cEngageType;
    DDS_Char  cPriority;
    DDS_UnsignedShort  sScore;
    DDS_UnsignedShort  sWeight;
    DDS_UnsignedShort  sTimeToGo;
    DDS_Char  cEngageAvailability;

} DMSG_TEWA_AIRTHREATEVALUATION;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TEWA_AIRTHREATEVALUATION_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TEWA_AIRTHREATEVALUATIONSeq, DMSG_TEWA_AIRTHREATEVALUATION);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_AIRTHREATEVALUATION_initialize(
        DMSG_TEWA_AIRTHREATEVALUATION* self);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_AIRTHREATEVALUATION_initialize_ex(
        DMSG_TEWA_AIRTHREATEVALUATION* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TEWA_AIRTHREATEVALUATION_finalize(
        DMSG_TEWA_AIRTHREATEVALUATION* self);
                        
NDDSUSERDllExport
void DMSG_TEWA_AIRTHREATEVALUATION_finalize_ex(
        DMSG_TEWA_AIRTHREATEVALUATION* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_AIRTHREATEVALUATION_copy(
        DMSG_TEWA_AIRTHREATEVALUATION* dst,
        const DMSG_TEWA_AIRTHREATEVALUATION* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TEWA_SHIPTHREATEVALUATIONTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TEWA_SHIPTHREATEVALUATION
{
    TrkNoSys  trkNo;
    DDS_Char  cEngageType;
    DDS_Char  cPriority;
    DDS_Float  fMaxEffectiveRange;
    DDS_UnsignedShort  sWeaponCapability[10];
    DDS_Float  fRange;
    DDS_Char  cEngageAvailability;

} DMSG_TEWA_SHIPTHREATEVALUATION;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TEWA_SHIPTHREATEVALUATION_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TEWA_SHIPTHREATEVALUATIONSeq, DMSG_TEWA_SHIPTHREATEVALUATION);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_SHIPTHREATEVALUATION_initialize(
        DMSG_TEWA_SHIPTHREATEVALUATION* self);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_SHIPTHREATEVALUATION_initialize_ex(
        DMSG_TEWA_SHIPTHREATEVALUATION* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TEWA_SHIPTHREATEVALUATION_finalize(
        DMSG_TEWA_SHIPTHREATEVALUATION* self);
                        
NDDSUSERDllExport
void DMSG_TEWA_SHIPTHREATEVALUATION_finalize_ex(
        DMSG_TEWA_SHIPTHREATEVALUATION* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_SHIPTHREATEVALUATION_copy(
        DMSG_TEWA_SHIPTHREATEVALUATION* dst,
        const DMSG_TEWA_SHIPTHREATEVALUATION* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TEWA_SUBTHREATEVALUATIONTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TEWA_SUBTHREATEVALUATION
{
    TrkNoSys  trkNo;
    DDS_Char  cEngageType;
    DDS_Char  cPriority;
    DDS_Char  cThreatType;
    DDS_Float  fRange;
    DDS_Float  fDoppler;
    DDS_UnsignedShort  sIdentity;
    DDS_Char  cEngageAvailability;
    DDS_Float  fBearing;
    DDS_UnsignedLong  nFirstOccurenceTime;

} DMSG_TEWA_SUBTHREATEVALUATION;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TEWA_SUBTHREATEVALUATION_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TEWA_SUBTHREATEVALUATIONSeq, DMSG_TEWA_SUBTHREATEVALUATION);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_SUBTHREATEVALUATION_initialize(
        DMSG_TEWA_SUBTHREATEVALUATION* self);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_SUBTHREATEVALUATION_initialize_ex(
        DMSG_TEWA_SUBTHREATEVALUATION* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TEWA_SUBTHREATEVALUATION_finalize(
        DMSG_TEWA_SUBTHREATEVALUATION* self);
                        
NDDSUSERDllExport
void DMSG_TEWA_SUBTHREATEVALUATION_finalize_ex(
        DMSG_TEWA_SUBTHREATEVALUATION* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_SUBTHREATEVALUATION_copy(
        DMSG_TEWA_SUBTHREATEVALUATION* dst,
        const DMSG_TEWA_SUBTHREATEVALUATION* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TEWA_ENGAGEPOSSIBILITYTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TEWA_ENGAGEPOSSIBILITY
{
    DDS_Char  TBD;

} DMSG_TEWA_ENGAGEPOSSIBILITY;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TEWA_ENGAGEPOSSIBILITY_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TEWA_ENGAGEPOSSIBILITYSeq, DMSG_TEWA_ENGAGEPOSSIBILITY);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_ENGAGEPOSSIBILITY_initialize(
        DMSG_TEWA_ENGAGEPOSSIBILITY* self);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_ENGAGEPOSSIBILITY_initialize_ex(
        DMSG_TEWA_ENGAGEPOSSIBILITY* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TEWA_ENGAGEPOSSIBILITY_finalize(
        DMSG_TEWA_ENGAGEPOSSIBILITY* self);
                        
NDDSUSERDllExport
void DMSG_TEWA_ENGAGEPOSSIBILITY_finalize_ex(
        DMSG_TEWA_ENGAGEPOSSIBILITY* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_ENGAGEPOSSIBILITY_copy(
        DMSG_TEWA_ENGAGEPOSSIBILITY* dst,
        const DMSG_TEWA_ENGAGEPOSSIBILITY* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TEWA_SWSTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TEWA_SWSTATE
{
    DDS_Char  cSoftwareState;

} DMSG_TEWA_SWSTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TEWA_SWSTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TEWA_SWSTATESeq, DMSG_TEWA_SWSTATE);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_SWSTATE_initialize(
        DMSG_TEWA_SWSTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_SWSTATE_initialize_ex(
        DMSG_TEWA_SWSTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TEWA_SWSTATE_finalize(
        DMSG_TEWA_SWSTATE* self);
                        
NDDSUSERDllExport
void DMSG_TEWA_SWSTATE_finalize_ex(
        DMSG_TEWA_SWSTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_SWSTATE_copy(
        DMSG_TEWA_SWSTATE* dst,
        const DMSG_TEWA_SWSTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TEWA_TORPEDOALERTTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TEWA_TORPEDOALERT
{
    TrkNoSys  trkNo;
    DDS_Boolean  bAlert;

} DMSG_TEWA_TORPEDOALERT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TEWA_TORPEDOALERT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TEWA_TORPEDOALERTSeq, DMSG_TEWA_TORPEDOALERT);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_TORPEDOALERT_initialize(
        DMSG_TEWA_TORPEDOALERT* self);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_TORPEDOALERT_initialize_ex(
        DMSG_TEWA_TORPEDOALERT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TEWA_TORPEDOALERT_finalize(
        DMSG_TEWA_TORPEDOALERT* self);
                        
NDDSUSERDllExport
void DMSG_TEWA_TORPEDOALERT_finalize_ex(
        DMSG_TEWA_TORPEDOALERT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_TORPEDOALERT_copy(
        DMSG_TEWA_TORPEDOALERT* dst,
        const DMSG_TEWA_TORPEDOALERT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TEWA_DIRECTENGAGEADVICETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TEWA_DIRECTENGAGEADVICE
{
    DDS_Long  nWeaponID;
    DDS_Long  nTrackRadarID;
    DDS_Short  sRadarType;
    DDS_Long  nChannelID;
    DDS_Double  dLat;
    DDS_Double  dLong;
    DDS_Double  dAlt;
    DDS_UnsignedShort  wEngagement_Availability;

} DMSG_TEWA_DIRECTENGAGEADVICE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TEWA_DIRECTENGAGEADVICE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TEWA_DIRECTENGAGEADVICESeq, DMSG_TEWA_DIRECTENGAGEADVICE);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_DIRECTENGAGEADVICE_initialize(
        DMSG_TEWA_DIRECTENGAGEADVICE* self);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_DIRECTENGAGEADVICE_initialize_ex(
        DMSG_TEWA_DIRECTENGAGEADVICE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TEWA_DIRECTENGAGEADVICE_finalize(
        DMSG_TEWA_DIRECTENGAGEADVICE* self);
                        
NDDSUSERDllExport
void DMSG_TEWA_DIRECTENGAGEADVICE_finalize_ex(
        DMSG_TEWA_DIRECTENGAGEADVICE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_DIRECTENGAGEADVICE_copy(
        DMSG_TEWA_DIRECTENGAGEADVICE* dst,
        const DMSG_TEWA_DIRECTENGAGEADVICE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TEWA_SENSORWEAPONREQTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TEWA_SENSORWEAPONREQ
{
    DDS_Long  nWeaponID;
    DDS_Long  nSensorID;

} DMSG_TEWA_SENSORWEAPONREQ;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TEWA_SENSORWEAPONREQ_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TEWA_SENSORWEAPONREQSeq, DMSG_TEWA_SENSORWEAPONREQ);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_SENSORWEAPONREQ_initialize(
        DMSG_TEWA_SENSORWEAPONREQ* self);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_SENSORWEAPONREQ_initialize_ex(
        DMSG_TEWA_SENSORWEAPONREQ* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TEWA_SENSORWEAPONREQ_finalize(
        DMSG_TEWA_SENSORWEAPONREQ* self);
                        
NDDSUSERDllExport
void DMSG_TEWA_SENSORWEAPONREQ_finalize_ex(
        DMSG_TEWA_SENSORWEAPONREQ* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TEWA_SENSORWEAPONREQ_copy(
        DMSG_TEWA_SENSORWEAPONREQ* dst,
        const DMSG_TEWA_SENSORWEAPONREQ* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_HITEVALUATIONSRESULTTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_HITEVALUATIONSRESULT
{
    TrkNoSys  trkNo;
    DDS_Char  cKillResult;

} DMSG_EC_HITEVALUATIONSRESULT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_HITEVALUATIONSRESULT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_HITEVALUATIONSRESULTSeq, DMSG_EC_HITEVALUATIONSRESULT);
        
NDDSUSERDllExport
RTIBool DMSG_EC_HITEVALUATIONSRESULT_initialize(
        DMSG_EC_HITEVALUATIONSRESULT* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_HITEVALUATIONSRESULT_initialize_ex(
        DMSG_EC_HITEVALUATIONSRESULT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_HITEVALUATIONSRESULT_finalize(
        DMSG_EC_HITEVALUATIONSRESULT* self);
                        
NDDSUSERDllExport
void DMSG_EC_HITEVALUATIONSRESULT_finalize_ex(
        DMSG_EC_HITEVALUATIONSRESULT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_HITEVALUATIONSRESULT_copy(
        DMSG_EC_HITEVALUATIONSRESULT* dst,
        const DMSG_EC_HITEVALUATIONSRESULT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_ENGAGEINFOTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_ENGAGEINFO
{
    DDS_Char  cEngageType;
    TrkNoSys  trkNo;
    DDS_UnsignedShort  assignNum;
    DDS_Char  cTrackRdrID;
    DDS_Char  cRdrType;
    DDS_Char  cChannelID;
    DDS_Char  cWeaponID;
    DDS_Char  cConsoleID;
    DDS_Char  cEngageInfo;
    time1  EngageTime[6];

} DMSG_EC_ENGAGEINFO;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_ENGAGEINFO_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_ENGAGEINFOSeq, DMSG_EC_ENGAGEINFO);
        
NDDSUSERDllExport
RTIBool DMSG_EC_ENGAGEINFO_initialize(
        DMSG_EC_ENGAGEINFO* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_ENGAGEINFO_initialize_ex(
        DMSG_EC_ENGAGEINFO* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_ENGAGEINFO_finalize(
        DMSG_EC_ENGAGEINFO* self);
                        
NDDSUSERDllExport
void DMSG_EC_ENGAGEINFO_finalize_ex(
        DMSG_EC_ENGAGEINFO* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_ENGAGEINFO_copy(
        DMSG_EC_ENGAGEINFO* dst,
        const DMSG_EC_ENGAGEINFO* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_ENGAGEASSIGNTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_ENGAGEASSIGN
{
    DDS_Char  cEngageType;
    TrkNoSys  trkNo;
    DDS_UnsignedShort  assignNum;
    DDS_Char  cTrackRdrID;
    DDS_Char  cRdrType;
    DDS_Char  cChannelID;
    DDS_Char  cWeaponID;
    DDS_Char  cConsoleID;
    time1  EngageTime[6];
    DDS_Double  dLatitude;
    DDS_Double  dLongitude;
    DDS_Double  dAltitude;
    DDS_Float  fRange;
    DDS_Float  fBearing;

} DMSG_EC_ENGAGEASSIGN;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_ENGAGEASSIGN_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_ENGAGEASSIGNSeq, DMSG_EC_ENGAGEASSIGN);
        
NDDSUSERDllExport
RTIBool DMSG_EC_ENGAGEASSIGN_initialize(
        DMSG_EC_ENGAGEASSIGN* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_ENGAGEASSIGN_initialize_ex(
        DMSG_EC_ENGAGEASSIGN* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_ENGAGEASSIGN_finalize(
        DMSG_EC_ENGAGEASSIGN* self);
                        
NDDSUSERDllExport
void DMSG_EC_ENGAGEASSIGN_finalize_ex(
        DMSG_EC_ENGAGEASSIGN* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_ENGAGEASSIGN_copy(
        DMSG_EC_ENGAGEASSIGN* dst,
        const DMSG_EC_ENGAGEASSIGN* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_ENGAGEPLANSETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_ENGAGEPLANSET
{
    DDS_Char  cEngagePlanCtrl;
    TrkNoSys  trkNo;

} DMSG_EC_ENGAGEPLANSET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_ENGAGEPLANSET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_ENGAGEPLANSETSeq, DMSG_EC_ENGAGEPLANSET);
        
NDDSUSERDllExport
RTIBool DMSG_EC_ENGAGEPLANSET_initialize(
        DMSG_EC_ENGAGEPLANSET* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_ENGAGEPLANSET_initialize_ex(
        DMSG_EC_ENGAGEPLANSET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_ENGAGEPLANSET_finalize(
        DMSG_EC_ENGAGEPLANSET* self);
                        
NDDSUSERDllExport
void DMSG_EC_ENGAGEPLANSET_finalize_ex(
        DMSG_EC_ENGAGEPLANSET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_ENGAGEPLANSET_copy(
        DMSG_EC_ENGAGEPLANSET* dst,
        const DMSG_EC_ENGAGEPLANSET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_FIREPERMITKEYSTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_FIREPERMITKEYSTATE
{
    DDS_Char  cFirePermitKey;

} DMSG_EC_FIREPERMITKEYSTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_FIREPERMITKEYSTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_FIREPERMITKEYSTATESeq, DMSG_EC_FIREPERMITKEYSTATE);
        
NDDSUSERDllExport
RTIBool DMSG_EC_FIREPERMITKEYSTATE_initialize(
        DMSG_EC_FIREPERMITKEYSTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_FIREPERMITKEYSTATE_initialize_ex(
        DMSG_EC_FIREPERMITKEYSTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_FIREPERMITKEYSTATE_finalize(
        DMSG_EC_FIREPERMITKEYSTATE* self);
                        
NDDSUSERDllExport
void DMSG_EC_FIREPERMITKEYSTATE_finalize_ex(
        DMSG_EC_FIREPERMITKEYSTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_FIREPERMITKEYSTATE_copy(
        DMSG_EC_FIREPERMITKEYSTATE* dst,
        const DMSG_EC_FIREPERMITKEYSTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_ENGAGESTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_ENGAGESTATE
{
    TrkNoSys  trkNo;
    DDS_Char  byTube;
    DDS_Char  byTubeNum;
    DDS_Char  byEngageState;

} DMSG_EC_ENGAGESTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_ENGAGESTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_ENGAGESTATESeq, DMSG_EC_ENGAGESTATE);
        
NDDSUSERDllExport
RTIBool DMSG_EC_ENGAGESTATE_initialize(
        DMSG_EC_ENGAGESTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_ENGAGESTATE_initialize_ex(
        DMSG_EC_ENGAGESTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_ENGAGESTATE_finalize(
        DMSG_EC_ENGAGESTATE* self);
                        
NDDSUSERDllExport
void DMSG_EC_ENGAGESTATE_finalize_ex(
        DMSG_EC_ENGAGESTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_ENGAGESTATE_copy(
        DMSG_EC_ENGAGESTATE* dst,
        const DMSG_EC_ENGAGESTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_SWSTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_SWSTATE
{
    DDS_Char  cSoftwareState;

} DMSG_EC_SWSTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_SWSTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_SWSTATESeq, DMSG_EC_SWSTATE);
        
NDDSUSERDllExport
RTIBool DMSG_EC_SWSTATE_initialize(
        DMSG_EC_SWSTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_SWSTATE_initialize_ex(
        DMSG_EC_SWSTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_SWSTATE_finalize(
        DMSG_EC_SWSTATE* self);
                        
NDDSUSERDllExport
void DMSG_EC_SWSTATE_finalize_ex(
        DMSG_EC_SWSTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_SWSTATE_copy(
        DMSG_EC_SWSTATE* dst,
        const DMSG_EC_SWSTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_WEAPONCTRLMODETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_WEAPONCTRLMODE
{
    DDS_Char  cControlMode;

} DMSG_EC_WEAPONCTRLMODE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_WEAPONCTRLMODE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_WEAPONCTRLMODESeq, DMSG_EC_WEAPONCTRLMODE);
        
NDDSUSERDllExport
RTIBool DMSG_EC_WEAPONCTRLMODE_initialize(
        DMSG_EC_WEAPONCTRLMODE* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_WEAPONCTRLMODE_initialize_ex(
        DMSG_EC_WEAPONCTRLMODE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_WEAPONCTRLMODE_finalize(
        DMSG_EC_WEAPONCTRLMODE* self);
                        
NDDSUSERDllExport
void DMSG_EC_WEAPONCTRLMODE_finalize_ex(
        DMSG_EC_WEAPONCTRLMODE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_WEAPONCTRLMODE_copy(
        DMSG_EC_WEAPONCTRLMODE* dst,
        const DMSG_EC_WEAPONCTRLMODE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_HORTUBEASSIGNTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_HORTUBEASSIGN
{
    DDS_Char  cConsoleID;
    TrkNoSys  trkNo;
    DDS_Char  byTubeNum;

} DMSG_EC_HORTUBEASSIGN;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_HORTUBEASSIGN_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_HORTUBEASSIGNSeq, DMSG_EC_HORTUBEASSIGN);
        
NDDSUSERDllExport
RTIBool DMSG_EC_HORTUBEASSIGN_initialize(
        DMSG_EC_HORTUBEASSIGN* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_HORTUBEASSIGN_initialize_ex(
        DMSG_EC_HORTUBEASSIGN* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_HORTUBEASSIGN_finalize(
        DMSG_EC_HORTUBEASSIGN* self);
                        
NDDSUSERDllExport
void DMSG_EC_HORTUBEASSIGN_finalize_ex(
        DMSG_EC_HORTUBEASSIGN* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_HORTUBEASSIGN_copy(
        DMSG_EC_HORTUBEASSIGN* dst,
        const DMSG_EC_HORTUBEASSIGN* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_VERTUBEASSIGNTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_VERTUBEASSIGN
{
    DDS_Char  cConsoleID;
    TrkNoSys  trkNo;
    DDS_Char  byLauncherNum;

} DMSG_EC_VERTUBEASSIGN;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_VERTUBEASSIGN_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_VERTUBEASSIGNSeq, DMSG_EC_VERTUBEASSIGN);
        
NDDSUSERDllExport
RTIBool DMSG_EC_VERTUBEASSIGN_initialize(
        DMSG_EC_VERTUBEASSIGN* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_VERTUBEASSIGN_initialize_ex(
        DMSG_EC_VERTUBEASSIGN* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_VERTUBEASSIGN_finalize(
        DMSG_EC_VERTUBEASSIGN* self);
                        
NDDSUSERDllExport
void DMSG_EC_VERTUBEASSIGN_finalize_ex(
        DMSG_EC_VERTUBEASSIGN* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_VERTUBEASSIGN_copy(
        DMSG_EC_VERTUBEASSIGN* dst,
        const DMSG_EC_VERTUBEASSIGN* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_WEAPONFIRESTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_WEAPONFIRESTATE
{
    DDS_Char  cWeaponID;
    DDS_Char  cFireState;

} DMSG_EC_WEAPONFIRESTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_WEAPONFIRESTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_WEAPONFIRESTATESeq, DMSG_EC_WEAPONFIRESTATE);
        
NDDSUSERDllExport
RTIBool DMSG_EC_WEAPONFIRESTATE_initialize(
        DMSG_EC_WEAPONFIRESTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_WEAPONFIRESTATE_initialize_ex(
        DMSG_EC_WEAPONFIRESTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_WEAPONFIRESTATE_finalize(
        DMSG_EC_WEAPONFIRESTATE* self);
                        
NDDSUSERDllExport
void DMSG_EC_WEAPONFIRESTATE_finalize_ex(
        DMSG_EC_WEAPONFIRESTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_WEAPONFIRESTATE_copy(
        DMSG_EC_WEAPONFIRESTATE* dst,
        const DMSG_EC_WEAPONFIRESTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_FIRECMDTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_FIRECMD
{
    DDS_Char  cConsoleID;
    DDS_Char  cLauncherNum;
    DDS_Char  cLinkLauncherNum;
    DDS_Char  cFireCmd;

} DMSG_EC_FIRECMD;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_FIRECMD_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_FIRECMDSeq, DMSG_EC_FIRECMD);
        
NDDSUSERDllExport
RTIBool DMSG_EC_FIRECMD_initialize(
        DMSG_EC_FIRECMD* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_FIRECMD_initialize_ex(
        DMSG_EC_FIRECMD* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_FIRECMD_finalize(
        DMSG_EC_FIRECMD* self);
                        
NDDSUSERDllExport
void DMSG_EC_FIRECMD_finalize_ex(
        DMSG_EC_FIRECMD* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_FIRECMD_copy(
        DMSG_EC_FIRECMD* dst,
        const DMSG_EC_FIRECMD* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TACTICORDERTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TACTICORDER
{
    DDS_Long  nTacticOrder;

} DMSG_HMI_TACTICORDER;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TACTICORDER_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TACTICORDERSeq, DMSG_HMI_TACTICORDER);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TACTICORDER_initialize(
        DMSG_HMI_TACTICORDER* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TACTICORDER_initialize_ex(
        DMSG_HMI_TACTICORDER* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TACTICORDER_finalize(
        DMSG_HMI_TACTICORDER* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TACTICORDER_finalize_ex(
        DMSG_HMI_TACTICORDER* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TACTICORDER_copy(
        DMSG_HMI_TACTICORDER* dst,
        const DMSG_HMI_TACTICORDER* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_DCOYLAUNCHMODETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_DCOYLAUNCHMODE
{
    DDS_Long  nDecoyLaunchMode;

} DMSG_HMI_DCOYLAUNCHMODE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_DCOYLAUNCHMODE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_DCOYLAUNCHMODESeq, DMSG_HMI_DCOYLAUNCHMODE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_DCOYLAUNCHMODE_initialize(
        DMSG_HMI_DCOYLAUNCHMODE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_DCOYLAUNCHMODE_initialize_ex(
        DMSG_HMI_DCOYLAUNCHMODE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_DCOYLAUNCHMODE_finalize(
        DMSG_HMI_DCOYLAUNCHMODE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_DCOYLAUNCHMODE_finalize_ex(
        DMSG_HMI_DCOYLAUNCHMODE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_DCOYLAUNCHMODE_copy(
        DMSG_HMI_DCOYLAUNCHMODE* dst,
        const DMSG_HMI_DCOYLAUNCHMODE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_DCOYTUBESETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_DCOYTUBESET
{
    DDS_Char  cLauncherID;
    DDS_Char  cTubeID;

} DMSG_HMI_DCOYTUBESET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_DCOYTUBESET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_DCOYTUBESETSeq, DMSG_HMI_DCOYTUBESET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_DCOYTUBESET_initialize(
        DMSG_HMI_DCOYTUBESET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_DCOYTUBESET_initialize_ex(
        DMSG_HMI_DCOYTUBESET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_DCOYTUBESET_finalize(
        DMSG_HMI_DCOYTUBESET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_DCOYTUBESET_finalize_ex(
        DMSG_HMI_DCOYTUBESET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_DCOYTUBESET_copy(
        DMSG_HMI_DCOYTUBESET* dst,
        const DMSG_HMI_DCOYTUBESET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_MISSILECTRLTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_MISSILECTRL
{
    DDS_Char  byLauncherNum;
    DDS_Char  byCtrlCmd;

} DMSG_HMI_MISSILECTRL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_MISSILECTRL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_MISSILECTRLSeq, DMSG_HMI_MISSILECTRL);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_MISSILECTRL_initialize(
        DMSG_HMI_MISSILECTRL* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_MISSILECTRL_initialize_ex(
        DMSG_HMI_MISSILECTRL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_MISSILECTRL_finalize(
        DMSG_HMI_MISSILECTRL* self);
                        
NDDSUSERDllExport
void DMSG_HMI_MISSILECTRL_finalize_ex(
        DMSG_HMI_MISSILECTRL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_MISSILECTRL_copy(
        DMSG_HMI_MISSILECTRL* dst,
        const DMSG_HMI_MISSILECTRL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_MISSILEENGAGEPLANTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_MISSILEENGAGEPLAN
{
    DDS_Char  cConsoleID;
    DDS_Char  byMissileNum;
    DDS_Char  cTubeID;
    DDS_Long  nWpCnt;
    TrkNoSys  trkNo;
    DDS_Double  dWP1Lat;
    DDS_Double  dWP1Lon;
    DDS_Double  dWP2Lat;
    DDS_Double  dWP2Lon;
    DDS_Double  dWP3Lat;
    DDS_Double  dWP3Lon;
    DDS_Double  dWP4Lat;
    DDS_Double  dWP4Lon;
    DDS_Double  dWP5Lat;
    DDS_Double  dWP5Lon;
    DDS_Double  dWP6Lat;
    DDS_Double  dWP6Lon;
    DDS_Double  dWP7Lat;
    DDS_Double  dWP7Lon;
    DDS_Double  dWP8Lat;
    DDS_Double  dWP8Lon;
    DDS_Long  nStaccatoVolley;
    DDS_Long  nAttackMissileCnt;
    DDS_Long  nAttackMode;
    DDS_Long  nSearchType;
    DDS_Long  nAttackType;

} DMSG_HMI_MISSILEENGAGEPLAN;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_MISSILEENGAGEPLAN_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_MISSILEENGAGEPLANSeq, DMSG_HMI_MISSILEENGAGEPLAN);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_MISSILEENGAGEPLAN_initialize(
        DMSG_HMI_MISSILEENGAGEPLAN* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_MISSILEENGAGEPLAN_initialize_ex(
        DMSG_HMI_MISSILEENGAGEPLAN* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_MISSILEENGAGEPLAN_finalize(
        DMSG_HMI_MISSILEENGAGEPLAN* self);
                        
NDDSUSERDllExport
void DMSG_HMI_MISSILEENGAGEPLAN_finalize_ex(
        DMSG_HMI_MISSILEENGAGEPLAN* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_MISSILEENGAGEPLAN_copy(
        DMSG_HMI_MISSILEENGAGEPLAN* dst,
        const DMSG_HMI_MISSILEENGAGEPLAN* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TORPEDOENGAGEPLANTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TORPEDOENGAGEPLAN
{
    TrkNoSys  trkNo;
    DDS_Char  cTargetType;
    DDS_Char  cInductionMode;
    DDS_Char  cGuidanceMode;
    DDS_Long  nRouteNum;
    DDS_Float  fRouteLat;
    DDS_Float  fRouteLon;
    DDS_Float  fRouteDepth;
    DDS_Float  fRouteSpeed;
    DDS_Float  fTorpDepth;
    DDS_Float  fDounLimitDepth;
    DDS_Float  fUpLimitDepth;
    DDS_Float  fRunDepth;
    DDS_Float  fPreOderSpeed;
    DDS_Float  fDetectionRange;
    DDS_Float  fDefaultRange;
    DDS_Float  fSearchSector;
    DDS_Float  fLinkDetectionRange;
    DDS_Float  fLinkDefaultRange;
    DDS_Float  fLinkSearchSector;
    DDS_Boolean  bSonarOder;
    DDS_Boolean  bRouteSensorOder;
    DDS_Boolean  bHitEvasionSet;
    DDS_Boolean  bTropLinkFire;
    DDS_Float  fHorLinkOffset;
    DDS_Float  fVerLinkOffset;
    DDS_Long  nTorpExpectFiretimeMin;
    DDS_Long  nTorpExpectFiretimeSec;
    DDS_Long  nTorpRuntimeMin;
    DDS_Long  nTorpRuntimeSec;
    DDS_Char  cTubeID;
    DDS_Char  cConsoleID;
    DDS_Boolean  bLinkedLaunch;
    DDS_Long  nLinkedDistance;
    DDS_Long  nLinkedTime;
    DDS_Long  n2ndTubeNum;

} DMSG_HMI_TORPEDOENGAGEPLAN;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TORPEDOENGAGEPLAN_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TORPEDOENGAGEPLANSeq, DMSG_HMI_TORPEDOENGAGEPLAN);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TORPEDOENGAGEPLAN_initialize(
        DMSG_HMI_TORPEDOENGAGEPLAN* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TORPEDOENGAGEPLAN_initialize_ex(
        DMSG_HMI_TORPEDOENGAGEPLAN* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TORPEDOENGAGEPLAN_finalize(
        DMSG_HMI_TORPEDOENGAGEPLAN* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TORPEDOENGAGEPLAN_finalize_ex(
        DMSG_HMI_TORPEDOENGAGEPLAN* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TORPEDOENGAGEPLAN_copy(
        DMSG_HMI_TORPEDOENGAGEPLAN* dst,
        const DMSG_HMI_TORPEDOENGAGEPLAN* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_RESERVEDENGAGEPLANTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_RESERVEDENGAGEPLAN
{
    TrkNoSys  trkNo;
    DDS_Char  cTargetType;
    DDS_Char  cInductionMode;
    DDS_Char  cGuidanceMode;
    DDS_Long  nRouteNum;
    DDS_Float  fRouteLat;
    DDS_Float  fRouteLon;
    DDS_Float  fRouteDepth;
    DDS_Float  fRouteSpeed;
    DDS_Float  fTorpDepth;
    DDS_Float  fDounLimitDepth;
    DDS_Float  fUpLimitDepth;
    DDS_Float  fRunDepth;
    DDS_Float  fPreOderSpeed;
    DDS_Float  fDetectionRange;
    DDS_Float  fDefaultRange;
    DDS_Float  fSearchSector;
    DDS_Float  fLinkDetectionRange;
    DDS_Float  fLinkDefaultRange;
    DDS_Float  fLinkSearchSector;
    DDS_Boolean  bSonarOder;
    DDS_Boolean  bRouteSensorOder;
    DDS_Boolean  bHitEvasionSet;
    DDS_Boolean  bTropLinkFire;
    DDS_Float  fHorLinkOffset;
    DDS_Float  fVerLinkOffset;
    DDS_Long  nTorpExpectFiretimeMin;
    DDS_Long  nTorpExpectFiretimeSec;
    DDS_Long  nTorpRuntimeMin;
    DDS_Long  nTorpRuntimeSec;
    DDS_Char  cTubeID;
    DDS_Char  cConsoleID;
    DDS_Boolean  bLinkedLaunch;
    DDS_Long  nLinkedDistance;
    DDS_Long  nLinkedTime;
    DDS_Long  n2ndTubeNum;

} DMSG_HMI_RESERVEDENGAGEPLAN;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_RESERVEDENGAGEPLAN_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_RESERVEDENGAGEPLANSeq, DMSG_HMI_RESERVEDENGAGEPLAN);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_RESERVEDENGAGEPLAN_initialize(
        DMSG_HMI_RESERVEDENGAGEPLAN* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_RESERVEDENGAGEPLAN_initialize_ex(
        DMSG_HMI_RESERVEDENGAGEPLAN* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_RESERVEDENGAGEPLAN_finalize(
        DMSG_HMI_RESERVEDENGAGEPLAN* self);
                        
NDDSUSERDllExport
void DMSG_HMI_RESERVEDENGAGEPLAN_finalize_ex(
        DMSG_HMI_RESERVEDENGAGEPLAN* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_RESERVEDENGAGEPLAN_copy(
        DMSG_HMI_RESERVEDENGAGEPLAN* dst,
        const DMSG_HMI_RESERVEDENGAGEPLAN* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TORPCTRLTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TORPCTRL
{
    DDS_Char  cTubeID;
    DDS_Char  cTorpCtrl;

} DMSG_HMI_TORPCTRL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TORPCTRL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TORPCTRLSeq, DMSG_HMI_TORPCTRL);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TORPCTRL_initialize(
        DMSG_HMI_TORPCTRL* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TORPCTRL_initialize_ex(
        DMSG_HMI_TORPCTRL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TORPCTRL_finalize(
        DMSG_HMI_TORPCTRL* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TORPCTRL_finalize_ex(
        DMSG_HMI_TORPCTRL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TORPCTRL_copy(
        DMSG_HMI_TORPCTRL* dst,
        const DMSG_HMI_TORPCTRL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_SHOOTMODIFYTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_SHOOTMODIFY
{
    DDS_Double  dBearingError;
    DDS_Long  nDistanceError;

} DMSG_HMI_SHOOTMODIFY;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_SHOOTMODIFY_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_SHOOTMODIFYSeq, DMSG_HMI_SHOOTMODIFY);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SHOOTMODIFY_initialize(
        DMSG_HMI_SHOOTMODIFY* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SHOOTMODIFY_initialize_ex(
        DMSG_HMI_SHOOTMODIFY* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_SHOOTMODIFY_finalize(
        DMSG_HMI_SHOOTMODIFY* self);
                        
NDDSUSERDllExport
void DMSG_HMI_SHOOTMODIFY_finalize_ex(
        DMSG_HMI_SHOOTMODIFY* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SHOOTMODIFY_copy(
        DMSG_HMI_SHOOTMODIFY* dst,
        const DMSG_HMI_SHOOTMODIFY* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_CORRECTTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_CORRECT
{
    DDS_Double  dBearing;
    DDS_Double  dAltitude;

} DMSG_HMI_CORRECT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_CORRECT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_CORRECTSeq, DMSG_HMI_CORRECT);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_CORRECT_initialize(
        DMSG_HMI_CORRECT* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_CORRECT_initialize_ex(
        DMSG_HMI_CORRECT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_CORRECT_finalize(
        DMSG_HMI_CORRECT* self);
                        
NDDSUSERDllExport
void DMSG_HMI_CORRECT_finalize_ex(
        DMSG_HMI_CORRECT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_CORRECT_copy(
        DMSG_HMI_CORRECT* dst,
        const DMSG_HMI_CORRECT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_SENSORWEAPONPOSTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_SENSORWEAPONPOS
{
    DDS_Char  bySensorCategory;
    DDS_Char  bySensorPos;
    DDS_Char  byWeaponPos;

} DMSG_HMI_SENSORWEAPONPOS;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_SENSORWEAPONPOS_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_SENSORWEAPONPOSSeq, DMSG_HMI_SENSORWEAPONPOS);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SENSORWEAPONPOS_initialize(
        DMSG_HMI_SENSORWEAPONPOS* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SENSORWEAPONPOS_initialize_ex(
        DMSG_HMI_SENSORWEAPONPOS* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_SENSORWEAPONPOS_finalize(
        DMSG_HMI_SENSORWEAPONPOS* self);
                        
NDDSUSERDllExport
void DMSG_HMI_SENSORWEAPONPOS_finalize_ex(
        DMSG_HMI_SENSORWEAPONPOS* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SENSORWEAPONPOS_copy(
        DMSG_HMI_SENSORWEAPONPOS* dst,
        const DMSG_HMI_SENSORWEAPONPOS* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_BLINDNESSFIRETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_BLINDNESSFIRE
{
    DDS_Double  dPosX;
    DDS_Double  dPosY;
    DDS_Double  dPosZ;

} DMSG_HMI_BLINDNESSFIRE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_BLINDNESSFIRE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_BLINDNESSFIRESeq, DMSG_HMI_BLINDNESSFIRE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_BLINDNESSFIRE_initialize(
        DMSG_HMI_BLINDNESSFIRE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_BLINDNESSFIRE_initialize_ex(
        DMSG_HMI_BLINDNESSFIRE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_BLINDNESSFIRE_finalize(
        DMSG_HMI_BLINDNESSFIRE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_BLINDNESSFIRE_finalize_ex(
        DMSG_HMI_BLINDNESSFIRE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_BLINDNESSFIRE_copy(
        DMSG_HMI_BLINDNESSFIRE* dst,
        const DMSG_HMI_BLINDNESSFIRE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_DIRECTFIRETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_DIRECTFIRE
{
    DDS_Double  dLat;
    DDS_Double  dLong;
    DDS_Double  dAlt;

} DMSG_HMI_DIRECTFIRE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_DIRECTFIRE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_DIRECTFIRESeq, DMSG_HMI_DIRECTFIRE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_DIRECTFIRE_initialize(
        DMSG_HMI_DIRECTFIRE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_DIRECTFIRE_initialize_ex(
        DMSG_HMI_DIRECTFIRE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_DIRECTFIRE_finalize(
        DMSG_HMI_DIRECTFIRE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_DIRECTFIRE_finalize_ex(
        DMSG_HMI_DIRECTFIRE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_DIRECTFIRE_copy(
        DMSG_HMI_DIRECTFIRE* dst,
        const DMSG_HMI_DIRECTFIRE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TORPMANUALWAYPOINTTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TORPMANUALWAYPOINT
{
    DDS_Char  byTorpNum;
    DDS_Long  nWpCnt;
    TrkNoSys  trkNo;
    DDS_Double  dWP1Lat;
    DDS_Double  dWP1Lon;
    DDS_Double  dWP2Lat;
    DDS_Double  dWP2Lon;
    DDS_Double  dWP3Lat;
    DDS_Double  dWP3Lon;
    DDS_Double  dWP4Lat;
    DDS_Double  dWP4Lon;
    DDS_Double  dWP5Lat;
    DDS_Double  dWP5Lon;
    DDS_Double  dWP6Lat;
    DDS_Double  dWP6Lon;
    DDS_Double  dWP7Lat;
    DDS_Double  dWP7Lon;
    DDS_Double  dWP8Lat;
    DDS_Double  dWP8Lon;
    DDS_Long  nStaccatoVolley;
    DDS_Char  cTubeID;
    DDS_Char  cConsoleID;

} DMSG_HMI_TORPMANUALWAYPOINT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TORPMANUALWAYPOINT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TORPMANUALWAYPOINTSeq, DMSG_HMI_TORPMANUALWAYPOINT);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TORPMANUALWAYPOINT_initialize(
        DMSG_HMI_TORPMANUALWAYPOINT* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TORPMANUALWAYPOINT_initialize_ex(
        DMSG_HMI_TORPMANUALWAYPOINT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TORPMANUALWAYPOINT_finalize(
        DMSG_HMI_TORPMANUALWAYPOINT* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TORPMANUALWAYPOINT_finalize_ex(
        DMSG_HMI_TORPMANUALWAYPOINT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TORPMANUALWAYPOINT_copy(
        DMSG_HMI_TORPMANUALWAYPOINT* dst,
        const DMSG_HMI_TORPMANUALWAYPOINT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_TORPBREAKENGAGETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_TORPBREAKENGAGE
{
    DDS_Char  byTorpNum;
    DDS_Char  byAction;

} DMSG_HMI_TORPBREAKENGAGE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_TORPBREAKENGAGE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_TORPBREAKENGAGESeq, DMSG_HMI_TORPBREAKENGAGE);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TORPBREAKENGAGE_initialize(
        DMSG_HMI_TORPBREAKENGAGE* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TORPBREAKENGAGE_initialize_ex(
        DMSG_HMI_TORPBREAKENGAGE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_TORPBREAKENGAGE_finalize(
        DMSG_HMI_TORPBREAKENGAGE* self);
                        
NDDSUSERDllExport
void DMSG_HMI_TORPBREAKENGAGE_finalize_ex(
        DMSG_HMI_TORPBREAKENGAGE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_TORPBREAKENGAGE_copy(
        DMSG_HMI_TORPBREAKENGAGE* dst,
        const DMSG_HMI_TORPBREAKENGAGE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_RESERVEDCOPYTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_RESERVEDCOPY
{
    DDS_Char  cConsoleID;
    DDS_Char  cTubeID;
    DDS_Char  cCopy;

} DMSG_HMI_RESERVEDCOPY;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_RESERVEDCOPY_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_RESERVEDCOPYSeq, DMSG_HMI_RESERVEDCOPY);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_RESERVEDCOPY_initialize(
        DMSG_HMI_RESERVEDCOPY* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_RESERVEDCOPY_initialize_ex(
        DMSG_HMI_RESERVEDCOPY* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_RESERVEDCOPY_finalize(
        DMSG_HMI_RESERVEDCOPY* self);
                        
NDDSUSERDllExport
void DMSG_HMI_RESERVEDCOPY_finalize_ex(
        DMSG_HMI_RESERVEDCOPY* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_RESERVEDCOPY_copy(
        DMSG_HMI_RESERVEDCOPY* dst,
        const DMSG_HMI_RESERVEDCOPY* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TFC_FIRINGDATATYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TFC_FIRINGDATA
{
    DDS_UnsignedShort  nConsoleID;
    DDS_Char  byTorpNum;
    DDS_Boolean  bLinkedLaunch;
    DDS_Float  fTorpCommLine;
    DDS_Float  fShipCommLine;
    DDS_Float  fTorpCommLineMax;
    DDS_Float  fShipCommLineMax;
    DDS_Long  nBattery;
    DDS_Float  fBatteryDistance;
    DDS_Long  nTropFireMin;
    DDS_Long  nTropFireSec;
    DDS_Char  TBD;
    DDS_Long  nReAttackNum;
    DDS_Float  fAdviceCrs;
    DDS_Float  fHitRange;
    DDS_Long  nHitTime;
    DDS_Float  fTgtObtainProbability;
    coordiHSys  HitPt;
    coordiHSys  AQPt;
    DDS_Float  fAQDistance;
    DDS_Float  fTorpDistance;
    DDS_Float  fExpcLat[4];
    DDS_Float  fExpcLon[4];
    DDS_Float  fExpcDepth[4];
    DDS_Long  nPtCount;
    DDS_Float  fTorpRouteLat[1000];
    DDS_Float  fTorpRouteLon[1000];
    DDS_Float  fTorpRouteDepth[1000];
    DDS_Long  nBatteryTime;
    DDS_Long  nOwnShipWireTime;
    DDS_Long  nTorpWireTime;
    DDS_Float  fRemainHitRange;
    DDS_Boolean  bReservedPlan;
    DDS_UnsignedLong  nRunningTime;

} DMSG_TFC_FIRINGDATA;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TFC_FIRINGDATA_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TFC_FIRINGDATASeq, DMSG_TFC_FIRINGDATA);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_FIRINGDATA_initialize(
        DMSG_TFC_FIRINGDATA* self);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_FIRINGDATA_initialize_ex(
        DMSG_TFC_FIRINGDATA* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TFC_FIRINGDATA_finalize(
        DMSG_TFC_FIRINGDATA* self);
                        
NDDSUSERDllExport
void DMSG_TFC_FIRINGDATA_finalize_ex(
        DMSG_TFC_FIRINGDATA* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_FIRINGDATA_copy(
        DMSG_TFC_FIRINGDATA* dst,
        const DMSG_TFC_FIRINGDATA* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TFC_TORPSTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TFC_TORPSTATE
{
    DDS_Char  byImpressedPower;
    DDS_Char  byFireSignal;
    DDS_Char  cTorpConnect;
    DDS_Char  cTorpSetState;
    DDS_Float  fTropCeiling;
    DDS_Float  fTropFloor;

} DMSG_TFC_TORPSTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TFC_TORPSTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TFC_TORPSTATESeq, DMSG_TFC_TORPSTATE);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_TORPSTATE_initialize(
        DMSG_TFC_TORPSTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_TORPSTATE_initialize_ex(
        DMSG_TFC_TORPSTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TFC_TORPSTATE_finalize(
        DMSG_TFC_TORPSTATE* self);
                        
NDDSUSERDllExport
void DMSG_TFC_TORPSTATE_finalize_ex(
        DMSG_TFC_TORPSTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_TORPSTATE_copy(
        DMSG_TFC_TORPSTATE* dst,
        const DMSG_TFC_TORPSTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TFC_TORPMANEUVERTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TFC_TORPMANEUVER
{
    DDS_Float  fLat;
    DDS_Float  fLon;
    DDS_Float  fCourse;
    DDS_Float  fDepth;
    DDS_Float  fSpeed;

} DMSG_TFC_TORPMANEUVER;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TFC_TORPMANEUVER_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TFC_TORPMANEUVERSeq, DMSG_TFC_TORPMANEUVER);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_TORPMANEUVER_initialize(
        DMSG_TFC_TORPMANEUVER* self);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_TORPMANEUVER_initialize_ex(
        DMSG_TFC_TORPMANEUVER* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TFC_TORPMANEUVER_finalize(
        DMSG_TFC_TORPMANEUVER* self);
                        
NDDSUSERDllExport
void DMSG_TFC_TORPMANEUVER_finalize_ex(
        DMSG_TFC_TORPMANEUVER* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_TORPMANEUVER_copy(
        DMSG_TFC_TORPMANEUVER* dst,
        const DMSG_TFC_TORPMANEUVER* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TFC_CHECKRESULTTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TFC_CHECKRESULT
{
    DDS_Char  byErr;
    DDS_Char  byPartState[16];

} DMSG_TFC_CHECKRESULT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TFC_CHECKRESULT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TFC_CHECKRESULTSeq, DMSG_TFC_CHECKRESULT);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_CHECKRESULT_initialize(
        DMSG_TFC_CHECKRESULT* self);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_CHECKRESULT_initialize_ex(
        DMSG_TFC_CHECKRESULT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TFC_CHECKRESULT_finalize(
        DMSG_TFC_CHECKRESULT* self);
                        
NDDSUSERDllExport
void DMSG_TFC_CHECKRESULT_finalize_ex(
        DMSG_TFC_CHECKRESULT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_CHECKRESULT_copy(
        DMSG_TFC_CHECKRESULT* dst,
        const DMSG_TFC_CHECKRESULT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TFC_INTERLOCKTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TFC_INTERLOCK
{
    DDS_Char  cDiscreteSig_Err;
    DDS_Char  cTargetAssignInfo_Err;
    DDS_Char  cBattlePlan_Data_Err;
    DDS_Char  cLimitDepth_Err;
    DDS_Char  cBattleSolution_Err;
    DDS_Char  cWeaponControl_Err;
    DDS_Char  cCommunication_Err;
    DDS_Char  cPower_Err;
    DDS_Char  cPreFire_Err;
    DDS_Char  cHorizonStatus_Err;
    DDS_Char  cHorizonControlStatus_Err;
    DDS_Char  cOwnshipSafe_Err;
    DDS_Char  cFirePermit_Key_Err;
    DDS_Char  cOtherWeapon_Fire;
    DDS_Char  cLinkWeapon_FireRady_Err;
    DDS_Char  cFireStep_Err;
    DDS_Char  cOverride;

} DMSG_TFC_INTERLOCK;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TFC_INTERLOCK_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TFC_INTERLOCKSeq, DMSG_TFC_INTERLOCK);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_INTERLOCK_initialize(
        DMSG_TFC_INTERLOCK* self);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_INTERLOCK_initialize_ex(
        DMSG_TFC_INTERLOCK* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TFC_INTERLOCK_finalize(
        DMSG_TFC_INTERLOCK* self);
                        
NDDSUSERDllExport
void DMSG_TFC_INTERLOCK_finalize_ex(
        DMSG_TFC_INTERLOCK* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_INTERLOCK_copy(
        DMSG_TFC_INTERLOCK* dst,
        const DMSG_TFC_INTERLOCK* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TFC_TORPSONARTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TFC_TORPSONAR
{
    DDS_Char  cTropedoSonarState;
    DDS_Char  cSonarSignal[16];

} DMSG_TFC_TORPSONAR;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TFC_TORPSONAR_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TFC_TORPSONARSeq, DMSG_TFC_TORPSONAR);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_TORPSONAR_initialize(
        DMSG_TFC_TORPSONAR* self);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_TORPSONAR_initialize_ex(
        DMSG_TFC_TORPSONAR* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TFC_TORPSONAR_finalize(
        DMSG_TFC_TORPSONAR* self);
                        
NDDSUSERDllExport
void DMSG_TFC_TORPSONAR_finalize_ex(
        DMSG_TFC_TORPSONAR* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_TORPSONAR_copy(
        DMSG_TFC_TORPSONAR* dst,
        const DMSG_TFC_TORPSONAR* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TFC_TORPTARGETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TFC_TORPTARGET
{
    DDS_Char  byTargetID;
    DDS_Char  byTargetType;
    DDS_Float  fTargetAltitude;
    DDS_Float  fTargetBearing;
    DDS_Char  bySonarBeam[16];

} DMSG_TFC_TORPTARGET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TFC_TORPTARGET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TFC_TORPTARGETSeq, DMSG_TFC_TORPTARGET);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_TORPTARGET_initialize(
        DMSG_TFC_TORPTARGET* self);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_TORPTARGET_initialize_ex(
        DMSG_TFC_TORPTARGET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TFC_TORPTARGET_finalize(
        DMSG_TFC_TORPTARGET* self);
                        
NDDSUSERDllExport
void DMSG_TFC_TORPTARGET_finalize_ex(
        DMSG_TFC_TORPTARGET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_TORPTARGET_copy(
        DMSG_TFC_TORPTARGET* dst,
        const DMSG_TFC_TORPTARGET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TFC_TORPEDOAVAILABILITYTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TFC_TORPEDOAVAILABILITY
{
    DDS_Char  cState;
    DDS_Char  cTubeNum;

} DMSG_TFC_TORPEDOAVAILABILITY;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TFC_TORPEDOAVAILABILITY_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TFC_TORPEDOAVAILABILITYSeq, DMSG_TFC_TORPEDOAVAILABILITY);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_TORPEDOAVAILABILITY_initialize(
        DMSG_TFC_TORPEDOAVAILABILITY* self);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_TORPEDOAVAILABILITY_initialize_ex(
        DMSG_TFC_TORPEDOAVAILABILITY* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TFC_TORPEDOAVAILABILITY_finalize(
        DMSG_TFC_TORPEDOAVAILABILITY* self);
                        
NDDSUSERDllExport
void DMSG_TFC_TORPEDOAVAILABILITY_finalize_ex(
        DMSG_TFC_TORPEDOAVAILABILITY* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_TORPEDOAVAILABILITY_copy(
        DMSG_TFC_TORPEDOAVAILABILITY* dst,
        const DMSG_TFC_TORPEDOAVAILABILITY* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TFC_ENGAGESTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TFC_ENGAGESTATE
{
    TrkNoSys  trkNo;
    DDS_Char  cTubeNum;
    DDS_Char  cEngageState;

} DMSG_TFC_ENGAGESTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TFC_ENGAGESTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TFC_ENGAGESTATESeq, DMSG_TFC_ENGAGESTATE);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_ENGAGESTATE_initialize(
        DMSG_TFC_ENGAGESTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_ENGAGESTATE_initialize_ex(
        DMSG_TFC_ENGAGESTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TFC_ENGAGESTATE_finalize(
        DMSG_TFC_ENGAGESTATE* self);
                        
NDDSUSERDllExport
void DMSG_TFC_ENGAGESTATE_finalize_ex(
        DMSG_TFC_ENGAGESTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_ENGAGESTATE_copy(
        DMSG_TFC_ENGAGESTATE* dst,
        const DMSG_TFC_ENGAGESTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TFC_SWSTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TFC_SWSTATE
{
    DDS_Char  cSoftwareState;

} DMSG_TFC_SWSTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TFC_SWSTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TFC_SWSTATESeq, DMSG_TFC_SWSTATE);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_SWSTATE_initialize(
        DMSG_TFC_SWSTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_SWSTATE_initialize_ex(
        DMSG_TFC_SWSTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TFC_SWSTATE_finalize(
        DMSG_TFC_SWSTATE* self);
                        
NDDSUSERDllExport
void DMSG_TFC_SWSTATE_finalize_ex(
        DMSG_TFC_SWSTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_SWSTATE_copy(
        DMSG_TFC_SWSTATE* dst,
        const DMSG_TFC_SWSTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_TFC_HLTCTRLTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_TFC_HLTCTRL
{
    DDS_Char  byTubeNum;
    DDS_Char  byCtrlCmd;

} DMSG_TFC_HLTCTRL;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_TFC_HLTCTRL_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_TFC_HLTCTRLSeq, DMSG_TFC_HLTCTRL);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_HLTCTRL_initialize(
        DMSG_TFC_HLTCTRL* self);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_HLTCTRL_initialize_ex(
        DMSG_TFC_HLTCTRL* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_TFC_HLTCTRL_finalize(
        DMSG_TFC_HLTCTRL* self);
                        
NDDSUSERDllExport
void DMSG_TFC_HLTCTRL_finalize_ex(
        DMSG_TFC_HLTCTRL* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_TFC_HLTCTRL_copy(
        DMSG_TFC_HLTCTRL* dst,
        const DMSG_TFC_HLTCTRL* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_MFC_SUMSTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_MFC_SUMSTATE
{
    DDS_Char  byPower;
    DDS_Char  byFireSig;
    DDS_Char  byFire;

} DMSG_MFC_SUMSTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_MFC_SUMSTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_MFC_SUMSTATESeq, DMSG_MFC_SUMSTATE);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_SUMSTATE_initialize(
        DMSG_MFC_SUMSTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_SUMSTATE_initialize_ex(
        DMSG_MFC_SUMSTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_MFC_SUMSTATE_finalize(
        DMSG_MFC_SUMSTATE* self);
                        
NDDSUSERDllExport
void DMSG_MFC_SUMSTATE_finalize_ex(
        DMSG_MFC_SUMSTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_SUMSTATE_copy(
        DMSG_MFC_SUMSTATE* dst,
        const DMSG_MFC_SUMSTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_MFC_FIRINGDATATYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_MFC_FIRINGDATA
{
    DDS_Double  dTgtLat;
    DDS_Double  dTgtLon;
    DDS_Long  nFlightTime;
    DDS_Double  dFireAvailableLat;
    DDS_Double  dFireAvailableLon;
    DDS_Double  dAdvicedCrs;
    DDS_Double  dExpectFlightLat;
    DDS_Double  dExpectFlightLon;
    DDS_Double  dFlightLat;
    DDS_Double  dFlightLon;

} DMSG_MFC_FIRINGDATA;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_MFC_FIRINGDATA_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_MFC_FIRINGDATASeq, DMSG_MFC_FIRINGDATA);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_FIRINGDATA_initialize(
        DMSG_MFC_FIRINGDATA* self);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_FIRINGDATA_initialize_ex(
        DMSG_MFC_FIRINGDATA* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_MFC_FIRINGDATA_finalize(
        DMSG_MFC_FIRINGDATA* self);
                        
NDDSUSERDllExport
void DMSG_MFC_FIRINGDATA_finalize_ex(
        DMSG_MFC_FIRINGDATA* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_FIRINGDATA_copy(
        DMSG_MFC_FIRINGDATA* dst,
        const DMSG_MFC_FIRINGDATA* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_MFC_INTERLOCKTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_MFC_INTERLOCK
{
    DDS_Char  cOverRideSet;
    DDS_Char  cDiscreteSig_Err;
    DDS_Char  cMissionPermit;
    DDS_Char  cSwitch_Err;
    DDS_Char  cPower_Err;
    DDS_Char  cFlightCrs_Err;
    DDS_Char  cPreFire_Err;
    DDS_Char  cVLTStatus_Err;
    DDS_Char  cFirePassWord_Err;
    DDS_Char  cShipSafeCondition_Err;
    DDS_Char  cFirePermit_Key_Err;
    DDS_Char  cFireStep_Err;
    DDS_Char  cLauncherNum;

} DMSG_MFC_INTERLOCK;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_MFC_INTERLOCK_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_MFC_INTERLOCKSeq, DMSG_MFC_INTERLOCK);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_INTERLOCK_initialize(
        DMSG_MFC_INTERLOCK* self);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_INTERLOCK_initialize_ex(
        DMSG_MFC_INTERLOCK* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_MFC_INTERLOCK_finalize(
        DMSG_MFC_INTERLOCK* self);
                        
NDDSUSERDllExport
void DMSG_MFC_INTERLOCK_finalize_ex(
        DMSG_MFC_INTERLOCK* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_INTERLOCK_copy(
        DMSG_MFC_INTERLOCK* dst,
        const DMSG_MFC_INTERLOCK* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_MFC_SAFETYSWITCHSTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_MFC_SAFETYSWITCHSTATE
{
    DDS_Char  cLauncherNum;
    DDS_Char  cSwitchState;

} DMSG_MFC_SAFETYSWITCHSTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_MFC_SAFETYSWITCHSTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_MFC_SAFETYSWITCHSTATESeq, DMSG_MFC_SAFETYSWITCHSTATE);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_SAFETYSWITCHSTATE_initialize(
        DMSG_MFC_SAFETYSWITCHSTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_SAFETYSWITCHSTATE_initialize_ex(
        DMSG_MFC_SAFETYSWITCHSTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_MFC_SAFETYSWITCHSTATE_finalize(
        DMSG_MFC_SAFETYSWITCHSTATE* self);
                        
NDDSUSERDllExport
void DMSG_MFC_SAFETYSWITCHSTATE_finalize_ex(
        DMSG_MFC_SAFETYSWITCHSTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_SAFETYSWITCHSTATE_copy(
        DMSG_MFC_SAFETYSWITCHSTATE* dst,
        const DMSG_MFC_SAFETYSWITCHSTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_MFC_SUMTESTRESULTTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_MFC_SUMTESTRESULT
{
    DDS_Char  cErr;

} DMSG_MFC_SUMTESTRESULT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_MFC_SUMTESTRESULT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_MFC_SUMTESTRESULTSeq, DMSG_MFC_SUMTESTRESULT);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_SUMTESTRESULT_initialize(
        DMSG_MFC_SUMTESTRESULT* self);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_SUMTESTRESULT_initialize_ex(
        DMSG_MFC_SUMTESTRESULT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_MFC_SUMTESTRESULT_finalize(
        DMSG_MFC_SUMTESTRESULT* self);
                        
NDDSUSERDllExport
void DMSG_MFC_SUMTESTRESULT_finalize_ex(
        DMSG_MFC_SUMTESTRESULT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_SUMTESTRESULT_copy(
        DMSG_MFC_SUMTESTRESULT* dst,
        const DMSG_MFC_SUMTESTRESULT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_MFC_ENGAGESTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_MFC_ENGAGESTATE
{
    TrkNoSys  trkNo;
    DDS_Char  cTubeNum;
    DDS_Char  cEngageState;

} DMSG_MFC_ENGAGESTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_MFC_ENGAGESTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_MFC_ENGAGESTATESeq, DMSG_MFC_ENGAGESTATE);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_ENGAGESTATE_initialize(
        DMSG_MFC_ENGAGESTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_ENGAGESTATE_initialize_ex(
        DMSG_MFC_ENGAGESTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_MFC_ENGAGESTATE_finalize(
        DMSG_MFC_ENGAGESTATE* self);
                        
NDDSUSERDllExport
void DMSG_MFC_ENGAGESTATE_finalize_ex(
        DMSG_MFC_ENGAGESTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_ENGAGESTATE_copy(
        DMSG_MFC_ENGAGESTATE* dst,
        const DMSG_MFC_ENGAGESTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_MFC_MISSILEAVAILABILITYTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_MFC_MISSILEAVAILABILITY
{
    DDS_Char  cTubeNum;
    DDS_Char  cTubeState;

} DMSG_MFC_MISSILEAVAILABILITY;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_MFC_MISSILEAVAILABILITY_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_MFC_MISSILEAVAILABILITYSeq, DMSG_MFC_MISSILEAVAILABILITY);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_MISSILEAVAILABILITY_initialize(
        DMSG_MFC_MISSILEAVAILABILITY* self);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_MISSILEAVAILABILITY_initialize_ex(
        DMSG_MFC_MISSILEAVAILABILITY* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_MFC_MISSILEAVAILABILITY_finalize(
        DMSG_MFC_MISSILEAVAILABILITY* self);
                        
NDDSUSERDllExport
void DMSG_MFC_MISSILEAVAILABILITY_finalize_ex(
        DMSG_MFC_MISSILEAVAILABILITY* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_MISSILEAVAILABILITY_copy(
        DMSG_MFC_MISSILEAVAILABILITY* dst,
        const DMSG_MFC_MISSILEAVAILABILITY* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_MFC_SWSTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_MFC_SWSTATE
{
    DDS_Char  cSoftwareState;

} DMSG_MFC_SWSTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_MFC_SWSTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_MFC_SWSTATESeq, DMSG_MFC_SWSTATE);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_SWSTATE_initialize(
        DMSG_MFC_SWSTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_SWSTATE_initialize_ex(
        DMSG_MFC_SWSTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_MFC_SWSTATE_finalize(
        DMSG_MFC_SWSTATE* self);
                        
NDDSUSERDllExport
void DMSG_MFC_SWSTATE_finalize_ex(
        DMSG_MFC_SWSTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_SWSTATE_copy(
        DMSG_MFC_SWSTATE* dst,
        const DMSG_MFC_SWSTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_MFC_COUNTDOWNSTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_MFC_COUNTDOWNSTATE
{
    DDS_Char  cConsoleID;
    DDS_Char  cTubeNum;
    DDS_Char  byCountdown1;
    DDS_Char  byCountdown2;
    DDS_Char  byCountdown3;
    DDS_Char  byCountdown4;
    DDS_Char  byCountdown5;
    DDS_Char  byCountdown6;
    DDS_Char  byCountdown7;
    DDS_Char  byCountdown8;

} DMSG_MFC_COUNTDOWNSTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_MFC_COUNTDOWNSTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_MFC_COUNTDOWNSTATESeq, DMSG_MFC_COUNTDOWNSTATE);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_COUNTDOWNSTATE_initialize(
        DMSG_MFC_COUNTDOWNSTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_COUNTDOWNSTATE_initialize_ex(
        DMSG_MFC_COUNTDOWNSTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_MFC_COUNTDOWNSTATE_finalize(
        DMSG_MFC_COUNTDOWNSTATE* self);
                        
NDDSUSERDllExport
void DMSG_MFC_COUNTDOWNSTATE_finalize_ex(
        DMSG_MFC_COUNTDOWNSTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_MFC_COUNTDOWNSTATE_copy(
        DMSG_MFC_COUNTDOWNSTATE* dst,
        const DMSG_MFC_COUNTDOWNSTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_DFC_MANOEUVRETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_DFC_MANOEUVRE
{
    DDS_Double  dManoeuvreTime[5];
    DDS_Double  dManoeuvreHeading[5];
    DDS_Double  dManoeuvreSpd[5];
    DDS_Double  dManoeuvreDepth[5];

} DMSG_DFC_MANOEUVRE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_DFC_MANOEUVRE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_DFC_MANOEUVRESeq, DMSG_DFC_MANOEUVRE);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_MANOEUVRE_initialize(
        DMSG_DFC_MANOEUVRE* self);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_MANOEUVRE_initialize_ex(
        DMSG_DFC_MANOEUVRE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_DFC_MANOEUVRE_finalize(
        DMSG_DFC_MANOEUVRE* self);
                        
NDDSUSERDllExport
void DMSG_DFC_MANOEUVRE_finalize_ex(
        DMSG_DFC_MANOEUVRE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_MANOEUVRE_copy(
        DMSG_DFC_MANOEUVRE* dst,
        const DMSG_DFC_MANOEUVRE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_DFC_TACTICINFOTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_DFC_TACTICINFO
{
    DDS_Long  nTacticListID;
    DDS_Char  chTacticName[20];

} DMSG_DFC_TACTICINFO;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_DFC_TACTICINFO_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_DFC_TACTICINFOSeq, DMSG_DFC_TACTICINFO);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_TACTICINFO_initialize(
        DMSG_DFC_TACTICINFO* self);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_TACTICINFO_initialize_ex(
        DMSG_DFC_TACTICINFO* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_DFC_TACTICINFO_finalize(
        DMSG_DFC_TACTICINFO* self);
                        
NDDSUSERDllExport
void DMSG_DFC_TACTICINFO_finalize_ex(
        DMSG_DFC_TACTICINFO* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_TACTICINFO_copy(
        DMSG_DFC_TACTICINFO* dst,
        const DMSG_DFC_TACTICINFO* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_DFC_LOADINGTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_DFC_LOADING
{
    DDS_Char  cLauncherID[4][9];
    DDS_Char  cTubeID[4][9];
    DDS_Char  cDecoyType[4][9];
    DDS_Char  cTubeState[4][9];
    DDS_Char  cAcouMode[4][9];
    DDS_Long  nDecoySetDepth[4][9];
    DDS_Char  cMDMobileType[4][9];
    DDS_Long  nDecoyLifeTime[4][9];

} DMSG_DFC_LOADING;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_DFC_LOADING_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_DFC_LOADINGSeq, DMSG_DFC_LOADING);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_LOADING_initialize(
        DMSG_DFC_LOADING* self);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_LOADING_initialize_ex(
        DMSG_DFC_LOADING* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_DFC_LOADING_finalize(
        DMSG_DFC_LOADING* self);
                        
NDDSUSERDllExport
void DMSG_DFC_LOADING_finalize_ex(
        DMSG_DFC_LOADING* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_LOADING_copy(
        DMSG_DFC_LOADING* dst,
        const DMSG_DFC_LOADING* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_DFC_PREDICTPOSTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_DFC_PREDICTPOS
{
    DDS_Long  nLaunchNum;
    DDS_Char  cLcDecoyType;
    DDS_Double  dLcPredictPosLat;
    DDS_Double  dLcPredictPosLon;
    DDS_Long  nLcPredictDepth;

} DMSG_DFC_PREDICTPOS;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_DFC_PREDICTPOS_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_DFC_PREDICTPOSSeq, DMSG_DFC_PREDICTPOS);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_PREDICTPOS_initialize(
        DMSG_DFC_PREDICTPOS* self);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_PREDICTPOS_initialize_ex(
        DMSG_DFC_PREDICTPOS* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_DFC_PREDICTPOS_finalize(
        DMSG_DFC_PREDICTPOS* self);
                        
NDDSUSERDllExport
void DMSG_DFC_PREDICTPOS_finalize_ex(
        DMSG_DFC_PREDICTPOS* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_PREDICTPOS_copy(
        DMSG_DFC_PREDICTPOS* dst,
        const DMSG_DFC_PREDICTPOS* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_DFC_PERFORMTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_DFC_PERFORM
{
    DDS_Double  dPerformLBound[8];
    DDS_Double  dPerformUBound[8];
    DDS_Char  cPerformLv[8];
    DDS_Long  nPerformEff[8];

} DMSG_DFC_PERFORM;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_DFC_PERFORM_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_DFC_PERFORMSeq, DMSG_DFC_PERFORM);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_PERFORM_initialize(
        DMSG_DFC_PERFORM* self);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_PERFORM_initialize_ex(
        DMSG_DFC_PERFORM* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_DFC_PERFORM_finalize(
        DMSG_DFC_PERFORM* self);
                        
NDDSUSERDllExport
void DMSG_DFC_PERFORM_finalize_ex(
        DMSG_DFC_PERFORM* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_PERFORM_copy(
        DMSG_DFC_PERFORM* dst,
        const DMSG_DFC_PERFORM* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_DFC_EXPECTROUTETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_DFC_EXPECTROUTE
{
    DDS_Long  nLauncherID;
    DDS_Long  nTubeID;
    DDS_Float  fExpecLat[100];
    DDS_Float  fExpecLon[100];
    DDS_Float  fExpecDepth[100];

} DMSG_DFC_EXPECTROUTE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_DFC_EXPECTROUTE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_DFC_EXPECTROUTESeq, DMSG_DFC_EXPECTROUTE);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_EXPECTROUTE_initialize(
        DMSG_DFC_EXPECTROUTE* self);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_EXPECTROUTE_initialize_ex(
        DMSG_DFC_EXPECTROUTE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_DFC_EXPECTROUTE_finalize(
        DMSG_DFC_EXPECTROUTE* self);
                        
NDDSUSERDllExport
void DMSG_DFC_EXPECTROUTE_finalize_ex(
        DMSG_DFC_EXPECTROUTE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_EXPECTROUTE_copy(
        DMSG_DFC_EXPECTROUTE* dst,
        const DMSG_DFC_EXPECTROUTE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_DFC_SUBDCOYFIREPLANTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_DFC_SUBDCOYFIREPLAN
{
    DDS_Char  cLauncherID;
    DDS_Char  cTubeID;
    DDS_Char  cDecoyType;

} DMSG_DFC_SUBDCOYFIREPLAN;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_DFC_SUBDCOYFIREPLAN_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_DFC_SUBDCOYFIREPLANSeq, DMSG_DFC_SUBDCOYFIREPLAN);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_SUBDCOYFIREPLAN_initialize(
        DMSG_DFC_SUBDCOYFIREPLAN* self);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_SUBDCOYFIREPLAN_initialize_ex(
        DMSG_DFC_SUBDCOYFIREPLAN* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_DFC_SUBDCOYFIREPLAN_finalize(
        DMSG_DFC_SUBDCOYFIREPLAN* self);
                        
NDDSUSERDllExport
void DMSG_DFC_SUBDCOYFIREPLAN_finalize_ex(
        DMSG_DFC_SUBDCOYFIREPLAN* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_SUBDCOYFIREPLAN_copy(
        DMSG_DFC_SUBDCOYFIREPLAN* dst,
        const DMSG_DFC_SUBDCOYFIREPLAN* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_DFC_ENGAGESTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_DFC_ENGAGESTATE
{
    DDS_Char  cLaunchDecoy;

} DMSG_DFC_ENGAGESTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_DFC_ENGAGESTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_DFC_ENGAGESTATESeq, DMSG_DFC_ENGAGESTATE);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_ENGAGESTATE_initialize(
        DMSG_DFC_ENGAGESTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_ENGAGESTATE_initialize_ex(
        DMSG_DFC_ENGAGESTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_DFC_ENGAGESTATE_finalize(
        DMSG_DFC_ENGAGESTATE* self);
                        
NDDSUSERDllExport
void DMSG_DFC_ENGAGESTATE_finalize_ex(
        DMSG_DFC_ENGAGESTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_DFC_ENGAGESTATE_copy(
        DMSG_DFC_ENGAGESTATE* dst,
        const DMSG_DFC_ENGAGESTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_SELECTEDSENSORTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_SELECTEDSENSOR
{
    DDS_Char  cConsoleID;
    DDS_Char  cSensorNum;

} DMSG_HMI_SELECTEDSENSOR;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_SELECTEDSENSOR_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_SELECTEDSENSORSeq, DMSG_HMI_SELECTEDSENSOR);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SELECTEDSENSOR_initialize(
        DMSG_HMI_SELECTEDSENSOR* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SELECTEDSENSOR_initialize_ex(
        DMSG_HMI_SELECTEDSENSOR* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_SELECTEDSENSOR_finalize(
        DMSG_HMI_SELECTEDSENSOR* self);
                        
NDDSUSERDllExport
void DMSG_HMI_SELECTEDSENSOR_finalize_ex(
        DMSG_HMI_SELECTEDSENSOR* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SELECTEDSENSOR_copy(
        DMSG_HMI_SELECTEDSENSOR* dst,
        const DMSG_HMI_SELECTEDSENSOR* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_SELECTEDWEAPONTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_SELECTEDWEAPON
{
    DDS_Char  cConsoleID;
    DDS_Char  cWeaponNum;

} DMSG_HMI_SELECTEDWEAPON;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_SELECTEDWEAPON_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_SELECTEDWEAPONSeq, DMSG_HMI_SELECTEDWEAPON);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SELECTEDWEAPON_initialize(
        DMSG_HMI_SELECTEDWEAPON* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SELECTEDWEAPON_initialize_ex(
        DMSG_HMI_SELECTEDWEAPON* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_SELECTEDWEAPON_finalize(
        DMSG_HMI_SELECTEDWEAPON* self);
                        
NDDSUSERDllExport
void DMSG_HMI_SELECTEDWEAPON_finalize_ex(
        DMSG_HMI_SELECTEDWEAPON* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SELECTEDWEAPON_copy(
        DMSG_HMI_SELECTEDWEAPON* dst,
        const DMSG_HMI_SELECTEDWEAPON* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_PA_SENSORRANGERESULTTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_PA_SENSORRANGERESULT
{
    DDS_Char  cConsoleID;
    DDS_Char  cSensorNum;
    DDS_Long  nResult;

} DMSG_PA_SENSORRANGERESULT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_PA_SENSORRANGERESULT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_PA_SENSORRANGERESULTSeq, DMSG_PA_SENSORRANGERESULT);
        
NDDSUSERDllExport
RTIBool DMSG_PA_SENSORRANGERESULT_initialize(
        DMSG_PA_SENSORRANGERESULT* self);
        
NDDSUSERDllExport
RTIBool DMSG_PA_SENSORRANGERESULT_initialize_ex(
        DMSG_PA_SENSORRANGERESULT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_PA_SENSORRANGERESULT_finalize(
        DMSG_PA_SENSORRANGERESULT* self);
                        
NDDSUSERDllExport
void DMSG_PA_SENSORRANGERESULT_finalize_ex(
        DMSG_PA_SENSORRANGERESULT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_PA_SENSORRANGERESULT_copy(
        DMSG_PA_SENSORRANGERESULT* dst,
        const DMSG_PA_SENSORRANGERESULT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_PA_WEAPONRANGERESULTTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_PA_WEAPONRANGERESULT
{
    DDS_Char  cConsoleID;
    DDS_Char  cWeaponNum;
    DDS_Long  nResult;

} DMSG_PA_WEAPONRANGERESULT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_PA_WEAPONRANGERESULT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_PA_WEAPONRANGERESULTSeq, DMSG_PA_WEAPONRANGERESULT);
        
NDDSUSERDllExport
RTIBool DMSG_PA_WEAPONRANGERESULT_initialize(
        DMSG_PA_WEAPONRANGERESULT* self);
        
NDDSUSERDllExport
RTIBool DMSG_PA_WEAPONRANGERESULT_initialize_ex(
        DMSG_PA_WEAPONRANGERESULT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_PA_WEAPONRANGERESULT_finalize(
        DMSG_PA_WEAPONRANGERESULT* self);
                        
NDDSUSERDllExport
void DMSG_PA_WEAPONRANGERESULT_finalize_ex(
        DMSG_PA_WEAPONRANGERESULT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_PA_WEAPONRANGERESULT_copy(
        DMSG_PA_WEAPONRANGERESULT* dst,
        const DMSG_PA_WEAPONRANGERESULT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_SMS_CONNECTTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_SMS_CONNECT
{
    DDS_Long  nID;
    DDS_Char  cIsConnect;

} DMSG_SMS_CONNECT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_SMS_CONNECT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_SMS_CONNECTSeq, DMSG_SMS_CONNECT);
        
NDDSUSERDllExport
RTIBool DMSG_SMS_CONNECT_initialize(
        DMSG_SMS_CONNECT* self);
        
NDDSUSERDllExport
RTIBool DMSG_SMS_CONNECT_initialize_ex(
        DMSG_SMS_CONNECT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_SMS_CONNECT_finalize(
        DMSG_SMS_CONNECT* self);
                        
NDDSUSERDllExport
void DMSG_SMS_CONNECT_finalize_ex(
        DMSG_SMS_CONNECT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_SMS_CONNECT_copy(
        DMSG_SMS_CONNECT* dst,
        const DMSG_SMS_CONNECT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_MMI_CONNECTREPLYTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_MMI_CONNECTREPLY
{
    DDS_Long  nID;
    DDS_Char  cConnectReply;

} DMSG_MMI_CONNECTREPLY;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_MMI_CONNECTREPLY_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_MMI_CONNECTREPLYSeq, DMSG_MMI_CONNECTREPLY);
        
NDDSUSERDllExport
RTIBool DMSG_MMI_CONNECTREPLY_initialize(
        DMSG_MMI_CONNECTREPLY* self);
        
NDDSUSERDllExport
RTIBool DMSG_MMI_CONNECTREPLY_initialize_ex(
        DMSG_MMI_CONNECTREPLY* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_MMI_CONNECTREPLY_finalize(
        DMSG_MMI_CONNECTREPLY* self);
                        
NDDSUSERDllExport
void DMSG_MMI_CONNECTREPLY_finalize_ex(
        DMSG_MMI_CONNECTREPLY* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_MMI_CONNECTREPLY_copy(
        DMSG_MMI_CONNECTREPLY* dst,
        const DMSG_MMI_CONNECTREPLY* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_SMS_INITTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_SMS_INIT
{
    DDS_Boolean  bInit;

} DMSG_SMS_INIT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_SMS_INIT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_SMS_INITSeq, DMSG_SMS_INIT);
        
NDDSUSERDllExport
RTIBool DMSG_SMS_INIT_initialize(
        DMSG_SMS_INIT* self);
        
NDDSUSERDllExport
RTIBool DMSG_SMS_INIT_initialize_ex(
        DMSG_SMS_INIT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_SMS_INIT_finalize(
        DMSG_SMS_INIT* self);
                        
NDDSUSERDllExport
void DMSG_SMS_INIT_finalize_ex(
        DMSG_SMS_INIT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_SMS_INIT_copy(
        DMSG_SMS_INIT* dst,
        const DMSG_SMS_INIT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_SMS_DDSTESTTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_SMS_DDSTEST
{
    DDS_Long  nRecvID;
    DDS_Long  nSendID;
    DDS_Boolean  bcheck;

} DMSG_SMS_DDSTEST;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_SMS_DDSTEST_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_SMS_DDSTESTSeq, DMSG_SMS_DDSTEST);
        
NDDSUSERDllExport
RTIBool DMSG_SMS_DDSTEST_initialize(
        DMSG_SMS_DDSTEST* self);
        
NDDSUSERDllExport
RTIBool DMSG_SMS_DDSTEST_initialize_ex(
        DMSG_SMS_DDSTEST* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_SMS_DDSTEST_finalize(
        DMSG_SMS_DDSTEST* self);
                        
NDDSUSERDllExport
void DMSG_SMS_DDSTEST_finalize_ex(
        DMSG_SMS_DDSTEST* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_SMS_DDSTEST_copy(
        DMSG_SMS_DDSTEST* dst,
        const DMSG_SMS_DDSTEST* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_HMI_SAVECYCLESETTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_HMI_SAVECYCLESET
{
    DDS_UnsignedLong  nSec;

} DMSG_HMI_SAVECYCLESET;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_HMI_SAVECYCLESET_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_HMI_SAVECYCLESETSeq, DMSG_HMI_SAVECYCLESET);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SAVECYCLESET_initialize(
        DMSG_HMI_SAVECYCLESET* self);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SAVECYCLESET_initialize_ex(
        DMSG_HMI_SAVECYCLESET* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_HMI_SAVECYCLESET_finalize(
        DMSG_HMI_SAVECYCLESET* self);
                        
NDDSUSERDllExport
void DMSG_HMI_SAVECYCLESET_finalize_ex(
        DMSG_HMI_SAVECYCLESET* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_HMI_SAVECYCLESET_copy(
        DMSG_HMI_SAVECYCLESET* dst,
        const DMSG_HMI_SAVECYCLESET* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* DDS_CMS_1867575076_h */
