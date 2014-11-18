
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_OSSMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#include "DDS_OSSMMISupport.h"
#include "DDS_OSSMMIPlugin.h"



#ifdef __cplusplus  
    #ifndef dds_c_log_impl_h              
         #include "dds_c/dds_c_log_impl.h"                                
    #endif        
#endif        




/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
              TDataReader,
              TTypeSupport

   Configure and implement 'DMSG_OSSMMI_SENSORSTATE' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_SENSORSTATETYPENAME

/* Defines */
#define TDataWriter DMSG_OSSMMI_SENSORSTATEDataWriter
#define TData       DMSG_OSSMMI_SENSORSTATE


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_SENSORSTATETYPENAME

/* Defines */
#define TDataReader DMSG_OSSMMI_SENSORSTATEDataReader
#define TDataSeq    DMSG_OSSMMI_SENSORSTATESeq
#define TData       DMSG_OSSMMI_SENSORSTATE


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
              TPlugin_delete
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    DMSG_OSSMMI_SENSORSTATETYPENAME
#define TPlugin_new  DMSG_OSSMMI_SENSORSTATEPlugin_new
#define TPlugin_delete  DMSG_OSSMMI_SENSORSTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_OSSMMI_SENSORSTATETypeSupport
#define TData        DMSG_OSSMMI_SENSORSTATE
#define TDataReader  DMSG_OSSMMI_SENSORSTATEDataReader
#define TDataWriter  DMSG_OSSMMI_SENSORSTATEDataWriter
#ifdef __cplusplus



#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"



#else
#include "dds_c/generic/dds_c_data_TTypeSupport.gen"
#endif
#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter

#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete





/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
              TDataReader,
              TTypeSupport

   Configure and implement 'DMSG_OSSMMI_GPS' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_GPSTYPENAME

/* Defines */
#define TDataWriter DMSG_OSSMMI_GPSDataWriter
#define TData       DMSG_OSSMMI_GPS


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_GPSTYPENAME

/* Defines */
#define TDataReader DMSG_OSSMMI_GPSDataReader
#define TDataSeq    DMSG_OSSMMI_GPSSeq
#define TData       DMSG_OSSMMI_GPS


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
              TPlugin_delete
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    DMSG_OSSMMI_GPSTYPENAME
#define TPlugin_new  DMSG_OSSMMI_GPSPlugin_new
#define TPlugin_delete  DMSG_OSSMMI_GPSPlugin_delete

/* Defines */
#define TTypeSupport DMSG_OSSMMI_GPSTypeSupport
#define TData        DMSG_OSSMMI_GPS
#define TDataReader  DMSG_OSSMMI_GPSDataReader
#define TDataWriter  DMSG_OSSMMI_GPSDataWriter
#ifdef __cplusplus



#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"



#else
#include "dds_c/generic/dds_c_data_TTypeSupport.gen"
#endif
#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter

#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete





/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
              TDataReader,
              TTypeSupport

   Configure and implement 'DMSG_OSSMMI_GYRO' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_GYROTYPENAME

/* Defines */
#define TDataWriter DMSG_OSSMMI_GYRODataWriter
#define TData       DMSG_OSSMMI_GYRO


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_GYROTYPENAME

/* Defines */
#define TDataReader DMSG_OSSMMI_GYRODataReader
#define TDataSeq    DMSG_OSSMMI_GYROSeq
#define TData       DMSG_OSSMMI_GYRO


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
              TPlugin_delete
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    DMSG_OSSMMI_GYROTYPENAME
#define TPlugin_new  DMSG_OSSMMI_GYROPlugin_new
#define TPlugin_delete  DMSG_OSSMMI_GYROPlugin_delete

/* Defines */
#define TTypeSupport DMSG_OSSMMI_GYROTypeSupport
#define TData        DMSG_OSSMMI_GYRO
#define TDataReader  DMSG_OSSMMI_GYRODataReader
#define TDataWriter  DMSG_OSSMMI_GYRODataWriter
#ifdef __cplusplus



#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"



#else
#include "dds_c/generic/dds_c_data_TTypeSupport.gen"
#endif
#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter

#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete





/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
              TDataReader,
              TTypeSupport

   Configure and implement 'DMSG_OSSMMI_EMLOG' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_EMLOGTYPENAME

/* Defines */
#define TDataWriter DMSG_OSSMMI_EMLOGDataWriter
#define TData       DMSG_OSSMMI_EMLOG


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_EMLOGTYPENAME

/* Defines */
#define TDataReader DMSG_OSSMMI_EMLOGDataReader
#define TDataSeq    DMSG_OSSMMI_EMLOGSeq
#define TData       DMSG_OSSMMI_EMLOG


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
              TPlugin_delete
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    DMSG_OSSMMI_EMLOGTYPENAME
#define TPlugin_new  DMSG_OSSMMI_EMLOGPlugin_new
#define TPlugin_delete  DMSG_OSSMMI_EMLOGPlugin_delete

/* Defines */
#define TTypeSupport DMSG_OSSMMI_EMLOGTypeSupport
#define TData        DMSG_OSSMMI_EMLOG
#define TDataReader  DMSG_OSSMMI_EMLOGDataReader
#define TDataWriter  DMSG_OSSMMI_EMLOGDataWriter
#ifdef __cplusplus



#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"



#else
#include "dds_c/generic/dds_c_data_TTypeSupport.gen"
#endif
#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter

#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete





/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
              TDataReader,
              TTypeSupport

   Configure and implement 'DMSG_OSSMMI_WIND' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_WINDTYPENAME

/* Defines */
#define TDataWriter DMSG_OSSMMI_WINDDataWriter
#define TData       DMSG_OSSMMI_WIND


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_WINDTYPENAME

/* Defines */
#define TDataReader DMSG_OSSMMI_WINDDataReader
#define TDataSeq    DMSG_OSSMMI_WINDSeq
#define TData       DMSG_OSSMMI_WIND


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
              TPlugin_delete
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    DMSG_OSSMMI_WINDTYPENAME
#define TPlugin_new  DMSG_OSSMMI_WINDPlugin_new
#define TPlugin_delete  DMSG_OSSMMI_WINDPlugin_delete

/* Defines */
#define TTypeSupport DMSG_OSSMMI_WINDTypeSupport
#define TData        DMSG_OSSMMI_WIND
#define TDataReader  DMSG_OSSMMI_WINDDataReader
#define TDataWriter  DMSG_OSSMMI_WINDDataWriter
#ifdef __cplusplus



#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"



#else
#include "dds_c/generic/dds_c_data_TTypeSupport.gen"
#endif
#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter

#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete





/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
              TDataReader,
              TTypeSupport

   Configure and implement 'DMSG_OSSMMI_TEMP' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_TEMPTYPENAME

/* Defines */
#define TDataWriter DMSG_OSSMMI_TEMPDataWriter
#define TData       DMSG_OSSMMI_TEMP


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_TEMPTYPENAME

/* Defines */
#define TDataReader DMSG_OSSMMI_TEMPDataReader
#define TDataSeq    DMSG_OSSMMI_TEMPSeq
#define TData       DMSG_OSSMMI_TEMP


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
              TPlugin_delete
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    DMSG_OSSMMI_TEMPTYPENAME
#define TPlugin_new  DMSG_OSSMMI_TEMPPlugin_new
#define TPlugin_delete  DMSG_OSSMMI_TEMPPlugin_delete

/* Defines */
#define TTypeSupport DMSG_OSSMMI_TEMPTypeSupport
#define TData        DMSG_OSSMMI_TEMP
#define TDataReader  DMSG_OSSMMI_TEMPDataReader
#define TDataWriter  DMSG_OSSMMI_TEMPDataWriter
#ifdef __cplusplus



#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"



#else
#include "dds_c/generic/dds_c_data_TTypeSupport.gen"
#endif
#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter

#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete





/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
              TDataReader,
              TTypeSupport

   Configure and implement 'DMSG_OSSMMI_ECHO' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_ECHOTYPENAME

/* Defines */
#define TDataWriter DMSG_OSSMMI_ECHODataWriter
#define TData       DMSG_OSSMMI_ECHO


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_ECHOTYPENAME

/* Defines */
#define TDataReader DMSG_OSSMMI_ECHODataReader
#define TDataSeq    DMSG_OSSMMI_ECHOSeq
#define TData       DMSG_OSSMMI_ECHO


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
              TPlugin_delete
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    DMSG_OSSMMI_ECHOTYPENAME
#define TPlugin_new  DMSG_OSSMMI_ECHOPlugin_new
#define TPlugin_delete  DMSG_OSSMMI_ECHOPlugin_delete

/* Defines */
#define TTypeSupport DMSG_OSSMMI_ECHOTypeSupport
#define TData        DMSG_OSSMMI_ECHO
#define TDataReader  DMSG_OSSMMI_ECHODataReader
#define TDataWriter  DMSG_OSSMMI_ECHODataWriter
#ifdef __cplusplus



#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"



#else
#include "dds_c/generic/dds_c_data_TTypeSupport.gen"
#endif
#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter

#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete





/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
              TDataReader,
              TTypeSupport

   Configure and implement 'DMSG_OSSMMI_PLATFORM' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_PLATFORMTYPENAME

/* Defines */
#define TDataWriter DMSG_OSSMMI_PLATFORMDataWriter
#define TData       DMSG_OSSMMI_PLATFORM


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_PLATFORMTYPENAME

/* Defines */
#define TDataReader DMSG_OSSMMI_PLATFORMDataReader
#define TDataSeq    DMSG_OSSMMI_PLATFORMSeq
#define TData       DMSG_OSSMMI_PLATFORM


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
              TPlugin_delete
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    DMSG_OSSMMI_PLATFORMTYPENAME
#define TPlugin_new  DMSG_OSSMMI_PLATFORMPlugin_new
#define TPlugin_delete  DMSG_OSSMMI_PLATFORMPlugin_delete

/* Defines */
#define TTypeSupport DMSG_OSSMMI_PLATFORMTypeSupport
#define TData        DMSG_OSSMMI_PLATFORM
#define TDataReader  DMSG_OSSMMI_PLATFORMDataReader
#define TDataWriter  DMSG_OSSMMI_PLATFORMDataWriter
#ifdef __cplusplus



#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"



#else
#include "dds_c/generic/dds_c_data_TTypeSupport.gen"
#endif
#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter

#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete





/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
              TDataReader,
              TTypeSupport

   Configure and implement 'DMSG_OSSMMI_PLATFORMREQ' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_PLATFORMREQTYPENAME

/* Defines */
#define TDataWriter DMSG_OSSMMI_PLATFORMREQDataWriter
#define TData       DMSG_OSSMMI_PLATFORMREQ


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   DMSG_OSSMMI_PLATFORMREQTYPENAME

/* Defines */
#define TDataReader DMSG_OSSMMI_PLATFORMREQDataReader
#define TDataSeq    DMSG_OSSMMI_PLATFORMREQSeq
#define TData       DMSG_OSSMMI_PLATFORMREQ


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
              TPlugin_delete
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    DMSG_OSSMMI_PLATFORMREQTYPENAME
#define TPlugin_new  DMSG_OSSMMI_PLATFORMREQPlugin_new
#define TPlugin_delete  DMSG_OSSMMI_PLATFORMREQPlugin_delete

/* Defines */
#define TTypeSupport DMSG_OSSMMI_PLATFORMREQTypeSupport
#define TData        DMSG_OSSMMI_PLATFORMREQ
#define TDataReader  DMSG_OSSMMI_PLATFORMREQDataReader
#define TDataWriter  DMSG_OSSMMI_PLATFORMREQDataWriter
#ifdef __cplusplus



#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"



#else
#include "dds_c/generic/dds_c_data_TTypeSupport.gen"
#endif
#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter

#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete


