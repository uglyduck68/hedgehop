
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_CMS.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#include "DDS_CMSSupport.h"
#include "DDS_CMSPlugin.h"



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

   Configure and implement 'TrkNoSys' support classes.

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
#define TTYPENAME   TrkNoSysTYPENAME

/* Defines */
#define TDataWriter TrkNoSysDataWriter
#define TData       TrkNoSys


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
#define TTYPENAME   TrkNoSysTYPENAME

/* Defines */
#define TDataReader TrkNoSysDataReader
#define TDataSeq    TrkNoSysSeq
#define TData       TrkNoSys


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
#define TTYPENAME    TrkNoSysTYPENAME
#define TPlugin_new  TrkNoSysPlugin_new
#define TPlugin_delete  TrkNoSysPlugin_delete

/* Defines */
#define TTypeSupport TrkNoSysTypeSupport
#define TData        TrkNoSys
#define TDataReader  TrkNoSysDataReader
#define TDataWriter  TrkNoSysDataWriter
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

   Configure and implement 'stDate' support classes.

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
#define TTYPENAME   stDateTYPENAME

/* Defines */
#define TDataWriter stDateDataWriter
#define TData       stDate


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
#define TTYPENAME   stDateTYPENAME

/* Defines */
#define TDataReader stDateDataReader
#define TDataSeq    stDateSeq
#define TData       stDate


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
#define TTYPENAME    stDateTYPENAME
#define TPlugin_new  stDatePlugin_new
#define TPlugin_delete  stDatePlugin_delete

/* Defines */
#define TTypeSupport stDateTypeSupport
#define TData        stDate
#define TDataReader  stDateDataReader
#define TDataWriter  stDateDataWriter
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

   Configure and implement 'stTime' support classes.

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
#define TTYPENAME   stTimeTYPENAME

/* Defines */
#define TDataWriter stTimeDataWriter
#define TData       stTime


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
#define TTYPENAME   stTimeTYPENAME

/* Defines */
#define TDataReader stTimeDataReader
#define TDataSeq    stTimeSeq
#define TData       stTime


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
#define TTYPENAME    stTimeTYPENAME
#define TPlugin_new  stTimePlugin_new
#define TPlugin_delete  stTimePlugin_delete

/* Defines */
#define TTypeSupport stTimeTypeSupport
#define TData        stTime
#define TDataReader  stTimeDataReader
#define TDataWriter  stTimeDataWriter
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

   Configure and implement 'time1' support classes.

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
#define TTYPENAME   time1TYPENAME

/* Defines */
#define TDataWriter time1DataWriter
#define TData       time1


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
#define TTYPENAME   time1TYPENAME

/* Defines */
#define TDataReader time1DataReader
#define TDataSeq    time1Seq
#define TData       time1


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
#define TTYPENAME    time1TYPENAME
#define TPlugin_new  time1Plugin_new
#define TPlugin_delete  time1Plugin_delete

/* Defines */
#define TTypeSupport time1TypeSupport
#define TData        time1
#define TDataReader  time1DataReader
#define TDataWriter  time1DataWriter
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

   Configure and implement 'time2' support classes.

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
#define TTYPENAME   time2TYPENAME

/* Defines */
#define TDataWriter time2DataWriter
#define TData       time2


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
#define TTYPENAME   time2TYPENAME

/* Defines */
#define TDataReader time2DataReader
#define TDataSeq    time2Seq
#define TData       time2


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
#define TTYPENAME    time2TYPENAME
#define TPlugin_new  time2Plugin_new
#define TPlugin_delete  time2Plugin_delete

/* Defines */
#define TTypeSupport time2TypeSupport
#define TData        time2
#define TDataReader  time2DataReader
#define TDataWriter  time2DataWriter
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

   Configure and implement 'coordiSys' support classes.

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
#define TTYPENAME   coordiSysTYPENAME

/* Defines */
#define TDataWriter coordiSysDataWriter
#define TData       coordiSys


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
#define TTYPENAME   coordiSysTYPENAME

/* Defines */
#define TDataReader coordiSysDataReader
#define TDataSeq    coordiSysSeq
#define TData       coordiSys


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
#define TTYPENAME    coordiSysTYPENAME
#define TPlugin_new  coordiSysPlugin_new
#define TPlugin_delete  coordiSysPlugin_delete

/* Defines */
#define TTypeSupport coordiSysTypeSupport
#define TData        coordiSys
#define TDataReader  coordiSysDataReader
#define TDataWriter  coordiSysDataWriter
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

   Configure and implement 'coordiHSys' support classes.

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
#define TTYPENAME   coordiHSysTYPENAME

/* Defines */
#define TDataWriter coordiHSysDataWriter
#define TData       coordiHSys


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
#define TTYPENAME   coordiHSysTYPENAME

/* Defines */
#define TDataReader coordiHSysDataReader
#define TDataSeq    coordiHSysSeq
#define TData       coordiHSys


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
#define TTYPENAME    coordiHSysTYPENAME
#define TPlugin_new  coordiHSysPlugin_new
#define TPlugin_delete  coordiHSysPlugin_delete

/* Defines */
#define TTypeSupport coordiHSysTypeSupport
#define TData        coordiHSys
#define TDataReader  coordiHSysDataReader
#define TDataWriter  coordiHSysDataWriter
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

   Configure and implement 'coordiRSys' support classes.

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
#define TTYPENAME   coordiRSysTYPENAME

/* Defines */
#define TDataWriter coordiRSysDataWriter
#define TData       coordiRSys


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
#define TTYPENAME   coordiRSysTYPENAME

/* Defines */
#define TDataReader coordiRSysDataReader
#define TDataSeq    coordiRSysSeq
#define TData       coordiRSys


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
#define TTYPENAME    coordiRSysTYPENAME
#define TPlugin_new  coordiRSysPlugin_new
#define TPlugin_delete  coordiRSysPlugin_delete

/* Defines */
#define TTypeSupport coordiRSysTypeSupport
#define TData        coordiRSys
#define TDataReader  coordiRSysDataReader
#define TDataWriter  coordiRSysDataWriter
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

   Configure and implement 'rectSys' support classes.

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
#define TTYPENAME   rectSysTYPENAME

/* Defines */
#define TDataWriter rectSysDataWriter
#define TData       rectSys


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
#define TTYPENAME   rectSysTYPENAME

/* Defines */
#define TDataReader rectSysDataReader
#define TDataSeq    rectSysSeq
#define TData       rectSys


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
#define TTYPENAME    rectSysTYPENAME
#define TPlugin_new  rectSysPlugin_new
#define TPlugin_delete  rectSysPlugin_delete

/* Defines */
#define TTypeSupport rectSysTypeSupport
#define TData        rectSys
#define TDataReader  rectSysDataReader
#define TDataWriter  rectSysDataWriter
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

   Configure and implement 'rectHSys' support classes.

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
#define TTYPENAME   rectHSysTYPENAME

/* Defines */
#define TDataWriter rectHSysDataWriter
#define TData       rectHSys


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
#define TTYPENAME   rectHSysTYPENAME

/* Defines */
#define TDataReader rectHSysDataReader
#define TDataSeq    rectHSysSeq
#define TData       rectHSys


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
#define TTYPENAME    rectHSysTYPENAME
#define TPlugin_new  rectHSysPlugin_new
#define TPlugin_delete  rectHSysPlugin_delete

/* Defines */
#define TTypeSupport rectHSysTypeSupport
#define TData        rectHSys
#define TDataReader  rectHSysDataReader
#define TDataWriter  rectHSysDataWriter
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

   Configure and implement 'rectRSys' support classes.

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
#define TTYPENAME   rectRSysTYPENAME

/* Defines */
#define TDataWriter rectRSysDataWriter
#define TData       rectRSys


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
#define TTYPENAME   rectRSysTYPENAME

/* Defines */
#define TDataReader rectRSysDataReader
#define TDataSeq    rectRSysSeq
#define TData       rectRSys


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
#define TTYPENAME    rectRSysTYPENAME
#define TPlugin_new  rectRSysPlugin_new
#define TPlugin_delete  rectRSysPlugin_delete

/* Defines */
#define TTypeSupport rectRSysTypeSupport
#define TData        rectRSys
#define TDataReader  rectRSysDataReader
#define TDataWriter  rectRSysDataWriter
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

   Configure and implement 'velocity3D' support classes.

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
#define TTYPENAME   velocity3DTYPENAME

/* Defines */
#define TDataWriter velocity3DDataWriter
#define TData       velocity3D


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
#define TTYPENAME   velocity3DTYPENAME

/* Defines */
#define TDataReader velocity3DDataReader
#define TDataSeq    velocity3DSeq
#define TData       velocity3D


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
#define TTYPENAME    velocity3DTYPENAME
#define TPlugin_new  velocity3DPlugin_new
#define TPlugin_delete  velocity3DPlugin_delete

/* Defines */
#define TTypeSupport velocity3DTypeSupport
#define TData        velocity3D
#define TDataReader  velocity3DDataReader
#define TDataWriter  velocity3DDataWriter
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

   Configure and implement 'SonarTrack' support classes.

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
#define TTYPENAME   SonarTrackTYPENAME

/* Defines */
#define TDataWriter SonarTrackDataWriter
#define TData       SonarTrack


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
#define TTYPENAME   SonarTrackTYPENAME

/* Defines */
#define TDataReader SonarTrackDataReader
#define TDataSeq    SonarTrackSeq
#define TData       SonarTrack


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
#define TTYPENAME    SonarTrackTYPENAME
#define TPlugin_new  SonarTrackPlugin_new
#define TPlugin_delete  SonarTrackPlugin_delete

/* Defines */
#define TTypeSupport SonarTrackTypeSupport
#define TData        SonarTrack
#define TDataReader  SonarTrackDataReader
#define TDataWriter  SonarTrackDataWriter
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

   Configure and implement 'stWake' support classes.

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
#define TTYPENAME   stWakeTYPENAME

/* Defines */
#define TDataWriter stWakeDataWriter
#define TData       stWake


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
#define TTYPENAME   stWakeTYPENAME

/* Defines */
#define TDataReader stWakeDataReader
#define TDataSeq    stWakeSeq
#define TData       stWake


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
#define TTYPENAME    stWakeTYPENAME
#define TPlugin_new  stWakePlugin_new
#define TPlugin_delete  stWakePlugin_delete

/* Defines */
#define TTypeSupport stWakeTypeSupport
#define TData        stWake
#define TDataReader  stWakeDataReader
#define TDataWriter  stWakeDataWriter
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

   Configure and implement 'stSubSysTrackID' support classes.

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
#define TTYPENAME   stSubSysTrackIDTYPENAME

/* Defines */
#define TDataWriter stSubSysTrackIDDataWriter
#define TData       stSubSysTrackID


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
#define TTYPENAME   stSubSysTrackIDTYPENAME

/* Defines */
#define TDataReader stSubSysTrackIDDataReader
#define TDataSeq    stSubSysTrackIDSeq
#define TData       stSubSysTrackID


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
#define TTYPENAME    stSubSysTrackIDTYPENAME
#define TPlugin_new  stSubSysTrackIDPlugin_new
#define TPlugin_delete  stSubSysTrackIDPlugin_delete

/* Defines */
#define TTypeSupport stSubSysTrackIDTypeSupport
#define TData        stSubSysTrackID
#define TDataReader  stSubSysTrackIDDataReader
#define TDataWriter  stSubSysTrackIDDataWriter
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

   Configure and implement 'stFullTime' support classes.

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
#define TTYPENAME   stFullTimeTYPENAME

/* Defines */
#define TDataWriter stFullTimeDataWriter
#define TData       stFullTime


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
#define TTYPENAME   stFullTimeTYPENAME

/* Defines */
#define TDataReader stFullTimeDataReader
#define TDataSeq    stFullTimeSeq
#define TData       stFullTime


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
#define TTYPENAME    stFullTimeTYPENAME
#define TPlugin_new  stFullTimePlugin_new
#define TPlugin_delete  stFullTimePlugin_delete

/* Defines */
#define TTypeSupport stFullTimeTypeSupport
#define TData        stFullTime
#define TDataReader  stFullTimeDataReader
#define TDataWriter  stFullTimeDataWriter
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

   Configure and implement 'DMSG_OSM_SENSORSTATE' support classes.

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
#define TTYPENAME   DMSG_OSM_SENSORSTATETYPENAME

/* Defines */
#define TDataWriter DMSG_OSM_SENSORSTATEDataWriter
#define TData       DMSG_OSM_SENSORSTATE


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
#define TTYPENAME   DMSG_OSM_SENSORSTATETYPENAME

/* Defines */
#define TDataReader DMSG_OSM_SENSORSTATEDataReader
#define TDataSeq    DMSG_OSM_SENSORSTATESeq
#define TData       DMSG_OSM_SENSORSTATE


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
#define TTYPENAME    DMSG_OSM_SENSORSTATETYPENAME
#define TPlugin_new  DMSG_OSM_SENSORSTATEPlugin_new
#define TPlugin_delete  DMSG_OSM_SENSORSTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_OSM_SENSORSTATETypeSupport
#define TData        DMSG_OSM_SENSORSTATE
#define TDataReader  DMSG_OSM_SENSORSTATEDataReader
#define TDataWriter  DMSG_OSM_SENSORSTATEDataWriter
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

   Configure and implement 'DMSG_OSM_WEAPONSTATE' support classes.

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
#define TTYPENAME   DMSG_OSM_WEAPONSTATETYPENAME

/* Defines */
#define TDataWriter DMSG_OSM_WEAPONSTATEDataWriter
#define TData       DMSG_OSM_WEAPONSTATE


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
#define TTYPENAME   DMSG_OSM_WEAPONSTATETYPENAME

/* Defines */
#define TDataReader DMSG_OSM_WEAPONSTATEDataReader
#define TDataSeq    DMSG_OSM_WEAPONSTATESeq
#define TData       DMSG_OSM_WEAPONSTATE


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
#define TTYPENAME    DMSG_OSM_WEAPONSTATETYPENAME
#define TPlugin_new  DMSG_OSM_WEAPONSTATEPlugin_new
#define TPlugin_delete  DMSG_OSM_WEAPONSTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_OSM_WEAPONSTATETypeSupport
#define TData        DMSG_OSM_WEAPONSTATE
#define TDataReader  DMSG_OSM_WEAPONSTATEDataReader
#define TDataWriter  DMSG_OSM_WEAPONSTATEDataWriter
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

   Configure and implement 'DMSG_HMI_REQMISSILEENGAGEPLAN' support classes.

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
#define TTYPENAME   DMSG_HMI_REQMISSILEENGAGEPLANTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_REQMISSILEENGAGEPLANDataWriter
#define TData       DMSG_HMI_REQMISSILEENGAGEPLAN


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
#define TTYPENAME   DMSG_HMI_REQMISSILEENGAGEPLANTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_REQMISSILEENGAGEPLANDataReader
#define TDataSeq    DMSG_HMI_REQMISSILEENGAGEPLANSeq
#define TData       DMSG_HMI_REQMISSILEENGAGEPLAN


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
#define TTYPENAME    DMSG_HMI_REQMISSILEENGAGEPLANTYPENAME
#define TPlugin_new  DMSG_HMI_REQMISSILEENGAGEPLANPlugin_new
#define TPlugin_delete  DMSG_HMI_REQMISSILEENGAGEPLANPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_REQMISSILEENGAGEPLANTypeSupport
#define TData        DMSG_HMI_REQMISSILEENGAGEPLAN
#define TDataReader  DMSG_HMI_REQMISSILEENGAGEPLANDataReader
#define TDataWriter  DMSG_HMI_REQMISSILEENGAGEPLANDataWriter
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

   Configure and implement 'DMSG_SUBHMI_SYSCTRLMODE' support classes.

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
#define TTYPENAME   DMSG_SUBHMI_SYSCTRLMODETYPENAME

/* Defines */
#define TDataWriter DMSG_SUBHMI_SYSCTRLMODEDataWriter
#define TData       DMSG_SUBHMI_SYSCTRLMODE


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
#define TTYPENAME   DMSG_SUBHMI_SYSCTRLMODETYPENAME

/* Defines */
#define TDataReader DMSG_SUBHMI_SYSCTRLMODEDataReader
#define TDataSeq    DMSG_SUBHMI_SYSCTRLMODESeq
#define TData       DMSG_SUBHMI_SYSCTRLMODE


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
#define TTYPENAME    DMSG_SUBHMI_SYSCTRLMODETYPENAME
#define TPlugin_new  DMSG_SUBHMI_SYSCTRLMODEPlugin_new
#define TPlugin_delete  DMSG_SUBHMI_SYSCTRLMODEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_SUBHMI_SYSCTRLMODETypeSupport
#define TData        DMSG_SUBHMI_SYSCTRLMODE
#define TDataReader  DMSG_SUBHMI_SYSCTRLMODEDataReader
#define TDataWriter  DMSG_SUBHMI_SYSCTRLMODEDataWriter
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

   Configure and implement 'DMSG_HMI_WEAPONLIMITSET' support classes.

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
#define TTYPENAME   DMSG_HMI_WEAPONLIMITSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_WEAPONLIMITSETDataWriter
#define TData       DMSG_HMI_WEAPONLIMITSET


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
#define TTYPENAME   DMSG_HMI_WEAPONLIMITSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_WEAPONLIMITSETDataReader
#define TDataSeq    DMSG_HMI_WEAPONLIMITSETSeq
#define TData       DMSG_HMI_WEAPONLIMITSET


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
#define TTYPENAME    DMSG_HMI_WEAPONLIMITSETTYPENAME
#define TPlugin_new  DMSG_HMI_WEAPONLIMITSETPlugin_new
#define TPlugin_delete  DMSG_HMI_WEAPONLIMITSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_WEAPONLIMITSETTypeSupport
#define TData        DMSG_HMI_WEAPONLIMITSET
#define TDataReader  DMSG_HMI_WEAPONLIMITSETDataReader
#define TDataWriter  DMSG_HMI_WEAPONLIMITSETDataWriter
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

   Configure and implement 'DMSG_HMI_CREATEMANUALTRACK' support classes.

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
#define TTYPENAME   DMSG_HMI_CREATEMANUALTRACKTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_CREATEMANUALTRACKDataWriter
#define TData       DMSG_HMI_CREATEMANUALTRACK


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
#define TTYPENAME   DMSG_HMI_CREATEMANUALTRACKTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_CREATEMANUALTRACKDataReader
#define TDataSeq    DMSG_HMI_CREATEMANUALTRACKSeq
#define TData       DMSG_HMI_CREATEMANUALTRACK


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
#define TTYPENAME    DMSG_HMI_CREATEMANUALTRACKTYPENAME
#define TPlugin_new  DMSG_HMI_CREATEMANUALTRACKPlugin_new
#define TPlugin_delete  DMSG_HMI_CREATEMANUALTRACKPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_CREATEMANUALTRACKTypeSupport
#define TData        DMSG_HMI_CREATEMANUALTRACK
#define TDataReader  DMSG_HMI_CREATEMANUALTRACKDataReader
#define TDataWriter  DMSG_HMI_CREATEMANUALTRACKDataWriter
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

   Configure and implement 'DMSG_HMI_TARGETIDENTITYSET' support classes.

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
#define TTYPENAME   DMSG_HMI_TARGETIDENTITYSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TARGETIDENTITYSETDataWriter
#define TData       DMSG_HMI_TARGETIDENTITYSET


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
#define TTYPENAME   DMSG_HMI_TARGETIDENTITYSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TARGETIDENTITYSETDataReader
#define TDataSeq    DMSG_HMI_TARGETIDENTITYSETSeq
#define TData       DMSG_HMI_TARGETIDENTITYSET


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
#define TTYPENAME    DMSG_HMI_TARGETIDENTITYSETTYPENAME
#define TPlugin_new  DMSG_HMI_TARGETIDENTITYSETPlugin_new
#define TPlugin_delete  DMSG_HMI_TARGETIDENTITYSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TARGETIDENTITYSETTypeSupport
#define TData        DMSG_HMI_TARGETIDENTITYSET
#define TDataReader  DMSG_HMI_TARGETIDENTITYSETDataReader
#define TDataWriter  DMSG_HMI_TARGETIDENTITYSETDataWriter
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

   Configure and implement 'DMSG_HMI_TARGETCATEGORYSET' support classes.

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
#define TTYPENAME   DMSG_HMI_TARGETCATEGORYSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TARGETCATEGORYSETDataWriter
#define TData       DMSG_HMI_TARGETCATEGORYSET


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
#define TTYPENAME   DMSG_HMI_TARGETCATEGORYSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TARGETCATEGORYSETDataReader
#define TDataSeq    DMSG_HMI_TARGETCATEGORYSETSeq
#define TData       DMSG_HMI_TARGETCATEGORYSET


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
#define TTYPENAME    DMSG_HMI_TARGETCATEGORYSETTYPENAME
#define TPlugin_new  DMSG_HMI_TARGETCATEGORYSETPlugin_new
#define TPlugin_delete  DMSG_HMI_TARGETCATEGORYSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TARGETCATEGORYSETTypeSupport
#define TData        DMSG_HMI_TARGETCATEGORYSET
#define TDataReader  DMSG_HMI_TARGETCATEGORYSETDataReader
#define TDataWriter  DMSG_HMI_TARGETCATEGORYSETDataWriter
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

   Configure and implement 'DMSG_HMI_TARGETNAMESET' support classes.

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
#define TTYPENAME   DMSG_HMI_TARGETNAMESETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TARGETNAMESETDataWriter
#define TData       DMSG_HMI_TARGETNAMESET


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
#define TTYPENAME   DMSG_HMI_TARGETNAMESETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TARGETNAMESETDataReader
#define TDataSeq    DMSG_HMI_TARGETNAMESETSeq
#define TData       DMSG_HMI_TARGETNAMESET


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
#define TTYPENAME    DMSG_HMI_TARGETNAMESETTYPENAME
#define TPlugin_new  DMSG_HMI_TARGETNAMESETPlugin_new
#define TPlugin_delete  DMSG_HMI_TARGETNAMESETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TARGETNAMESETTypeSupport
#define TData        DMSG_HMI_TARGETNAMESET
#define TDataReader  DMSG_HMI_TARGETNAMESETDataReader
#define TDataWriter  DMSG_HMI_TARGETNAMESETDataWriter
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

   Configure and implement 'DMSG_HMI_ENGAGESET' support classes.

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
#define TTYPENAME   DMSG_HMI_ENGAGESETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_ENGAGESETDataWriter
#define TData       DMSG_HMI_ENGAGESET


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
#define TTYPENAME   DMSG_HMI_ENGAGESETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_ENGAGESETDataReader
#define TDataSeq    DMSG_HMI_ENGAGESETSeq
#define TData       DMSG_HMI_ENGAGESET


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
#define TTYPENAME    DMSG_HMI_ENGAGESETTYPENAME
#define TPlugin_new  DMSG_HMI_ENGAGESETPlugin_new
#define TPlugin_delete  DMSG_HMI_ENGAGESETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_ENGAGESETTypeSupport
#define TData        DMSG_HMI_ENGAGESET
#define TDataReader  DMSG_HMI_ENGAGESETDataReader
#define TDataWriter  DMSG_HMI_ENGAGESETDataWriter
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

   Configure and implement 'DMSG_HMI_MANUALSELECTSET' support classes.

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
#define TTYPENAME   DMSG_HMI_MANUALSELECTSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_MANUALSELECTSETDataWriter
#define TData       DMSG_HMI_MANUALSELECTSET


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
#define TTYPENAME   DMSG_HMI_MANUALSELECTSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_MANUALSELECTSETDataReader
#define TDataSeq    DMSG_HMI_MANUALSELECTSETSeq
#define TData       DMSG_HMI_MANUALSELECTSET


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
#define TTYPENAME    DMSG_HMI_MANUALSELECTSETTYPENAME
#define TPlugin_new  DMSG_HMI_MANUALSELECTSETPlugin_new
#define TPlugin_delete  DMSG_HMI_MANUALSELECTSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_MANUALSELECTSETTypeSupport
#define TData        DMSG_HMI_MANUALSELECTSET
#define TDataReader  DMSG_HMI_MANUALSELECTSETDataReader
#define TDataWriter  DMSG_HMI_MANUALSELECTSETDataWriter
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

   Configure and implement 'DMSG_HMI_IDENTITYDETAILSET' support classes.

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
#define TTYPENAME   DMSG_HMI_IDENTITYDETAILSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_IDENTITYDETAILSETDataWriter
#define TData       DMSG_HMI_IDENTITYDETAILSET


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
#define TTYPENAME   DMSG_HMI_IDENTITYDETAILSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_IDENTITYDETAILSETDataReader
#define TDataSeq    DMSG_HMI_IDENTITYDETAILSETSeq
#define TData       DMSG_HMI_IDENTITYDETAILSET


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
#define TTYPENAME    DMSG_HMI_IDENTITYDETAILSETTYPENAME
#define TPlugin_new  DMSG_HMI_IDENTITYDETAILSETPlugin_new
#define TPlugin_delete  DMSG_HMI_IDENTITYDETAILSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_IDENTITYDETAILSETTypeSupport
#define TData        DMSG_HMI_IDENTITYDETAILSET
#define TDataReader  DMSG_HMI_IDENTITYDETAILSETDataReader
#define TDataWriter  DMSG_HMI_IDENTITYDETAILSETDataWriter
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

   Configure and implement 'DMSG_HMI_WEAPONCAPABILITYSET' support classes.

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
#define TTYPENAME   DMSG_HMI_WEAPONCAPABILITYSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_WEAPONCAPABILITYSETDataWriter
#define TData       DMSG_HMI_WEAPONCAPABILITYSET


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
#define TTYPENAME   DMSG_HMI_WEAPONCAPABILITYSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_WEAPONCAPABILITYSETDataReader
#define TDataSeq    DMSG_HMI_WEAPONCAPABILITYSETSeq
#define TData       DMSG_HMI_WEAPONCAPABILITYSET


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
#define TTYPENAME    DMSG_HMI_WEAPONCAPABILITYSETTYPENAME
#define TPlugin_new  DMSG_HMI_WEAPONCAPABILITYSETPlugin_new
#define TPlugin_delete  DMSG_HMI_WEAPONCAPABILITYSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_WEAPONCAPABILITYSETTypeSupport
#define TData        DMSG_HMI_WEAPONCAPABILITYSET
#define TDataReader  DMSG_HMI_WEAPONCAPABILITYSETDataReader
#define TDataWriter  DMSG_HMI_WEAPONCAPABILITYSETDataWriter
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

   Configure and implement 'DMSG_HMI_DATUMSET' support classes.

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
#define TTYPENAME   DMSG_HMI_DATUMSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_DATUMSETDataWriter
#define TData       DMSG_HMI_DATUMSET


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
#define TTYPENAME   DMSG_HMI_DATUMSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_DATUMSETDataReader
#define TDataSeq    DMSG_HMI_DATUMSETSeq
#define TData       DMSG_HMI_DATUMSET


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
#define TTYPENAME    DMSG_HMI_DATUMSETTYPENAME
#define TPlugin_new  DMSG_HMI_DATUMSETPlugin_new
#define TPlugin_delete  DMSG_HMI_DATUMSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_DATUMSETTypeSupport
#define TData        DMSG_HMI_DATUMSET
#define TDataReader  DMSG_HMI_DATUMSETDataReader
#define TDataWriter  DMSG_HMI_DATUMSETDataWriter
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

   Configure and implement 'DMSG_HMI_SYSTRACKDEL' support classes.

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
#define TTYPENAME   DMSG_HMI_SYSTRACKDELTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_SYSTRACKDELDataWriter
#define TData       DMSG_HMI_SYSTRACKDEL


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
#define TTYPENAME   DMSG_HMI_SYSTRACKDELTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_SYSTRACKDELDataReader
#define TDataSeq    DMSG_HMI_SYSTRACKDELSeq
#define TData       DMSG_HMI_SYSTRACKDEL


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
#define TTYPENAME    DMSG_HMI_SYSTRACKDELTYPENAME
#define TPlugin_new  DMSG_HMI_SYSTRACKDELPlugin_new
#define TPlugin_delete  DMSG_HMI_SYSTRACKDELPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_SYSTRACKDELTypeSupport
#define TData        DMSG_HMI_SYSTRACKDEL
#define TDataReader  DMSG_HMI_SYSTRACKDELDataReader
#define TDataWriter  DMSG_HMI_SYSTRACKDELDataWriter
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

   Configure and implement 'DMSG_HMI_PAIRINGSET' support classes.

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
#define TTYPENAME   DMSG_HMI_PAIRINGSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_PAIRINGSETDataWriter
#define TData       DMSG_HMI_PAIRINGSET


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
#define TTYPENAME   DMSG_HMI_PAIRINGSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_PAIRINGSETDataReader
#define TDataSeq    DMSG_HMI_PAIRINGSETSeq
#define TData       DMSG_HMI_PAIRINGSET


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
#define TTYPENAME    DMSG_HMI_PAIRINGSETTYPENAME
#define TPlugin_new  DMSG_HMI_PAIRINGSETPlugin_new
#define TPlugin_delete  DMSG_HMI_PAIRINGSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_PAIRINGSETTypeSupport
#define TData        DMSG_HMI_PAIRINGSET
#define TDataReader  DMSG_HMI_PAIRINGSETDataReader
#define TDataWriter  DMSG_HMI_PAIRINGSETDataWriter
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

   Configure and implement 'DMSG_HMI_ASSOCIATIONSET' support classes.

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
#define TTYPENAME   DMSG_HMI_ASSOCIATIONSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_ASSOCIATIONSETDataWriter
#define TData       DMSG_HMI_ASSOCIATIONSET


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
#define TTYPENAME   DMSG_HMI_ASSOCIATIONSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_ASSOCIATIONSETDataReader
#define TDataSeq    DMSG_HMI_ASSOCIATIONSETSeq
#define TData       DMSG_HMI_ASSOCIATIONSET


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
#define TTYPENAME    DMSG_HMI_ASSOCIATIONSETTYPENAME
#define TPlugin_new  DMSG_HMI_ASSOCIATIONSETPlugin_new
#define TPlugin_delete  DMSG_HMI_ASSOCIATIONSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_ASSOCIATIONSETTypeSupport
#define TData        DMSG_HMI_ASSOCIATIONSET
#define TDataReader  DMSG_HMI_ASSOCIATIONSETDataReader
#define TDataWriter  DMSG_HMI_ASSOCIATIONSETDataWriter
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

   Configure and implement 'DMSG_HMI_CORRELATIONSET' support classes.

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
#define TTYPENAME   DMSG_HMI_CORRELATIONSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_CORRELATIONSETDataWriter
#define TData       DMSG_HMI_CORRELATIONSET


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
#define TTYPENAME   DMSG_HMI_CORRELATIONSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_CORRELATIONSETDataReader
#define TDataSeq    DMSG_HMI_CORRELATIONSETSeq
#define TData       DMSG_HMI_CORRELATIONSET


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
#define TTYPENAME    DMSG_HMI_CORRELATIONSETTYPENAME
#define TPlugin_new  DMSG_HMI_CORRELATIONSETPlugin_new
#define TPlugin_delete  DMSG_HMI_CORRELATIONSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_CORRELATIONSETTypeSupport
#define TData        DMSG_HMI_CORRELATIONSET
#define TDataReader  DMSG_HMI_CORRELATIONSETDataReader
#define TDataWriter  DMSG_HMI_CORRELATIONSETDataWriter
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

   Configure and implement 'DMSG_HMI_CORRELATIONCLEAR' support classes.

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
#define TTYPENAME   DMSG_HMI_CORRELATIONCLEARTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_CORRELATIONCLEARDataWriter
#define TData       DMSG_HMI_CORRELATIONCLEAR


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
#define TTYPENAME   DMSG_HMI_CORRELATIONCLEARTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_CORRELATIONCLEARDataReader
#define TDataSeq    DMSG_HMI_CORRELATIONCLEARSeq
#define TData       DMSG_HMI_CORRELATIONCLEAR


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
#define TTYPENAME    DMSG_HMI_CORRELATIONCLEARTYPENAME
#define TPlugin_new  DMSG_HMI_CORRELATIONCLEARPlugin_new
#define TPlugin_delete  DMSG_HMI_CORRELATIONCLEARPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_CORRELATIONCLEARTypeSupport
#define TData        DMSG_HMI_CORRELATIONCLEAR
#define TDataReader  DMSG_HMI_CORRELATIONCLEARDataReader
#define TDataWriter  DMSG_HMI_CORRELATIONCLEARDataWriter
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

   Configure and implement 'DMSG_HMI_TRACECHANGE' support classes.

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
#define TTYPENAME   DMSG_HMI_TRACECHANGETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TRACECHANGEDataWriter
#define TData       DMSG_HMI_TRACECHANGE


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
#define TTYPENAME   DMSG_HMI_TRACECHANGETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TRACECHANGEDataReader
#define TDataSeq    DMSG_HMI_TRACECHANGESeq
#define TData       DMSG_HMI_TRACECHANGE


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
#define TTYPENAME    DMSG_HMI_TRACECHANGETYPENAME
#define TPlugin_new  DMSG_HMI_TRACECHANGEPlugin_new
#define TPlugin_delete  DMSG_HMI_TRACECHANGEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TRACECHANGETypeSupport
#define TData        DMSG_HMI_TRACECHANGE
#define TDataReader  DMSG_HMI_TRACECHANGEDataReader
#define TDataWriter  DMSG_HMI_TRACECHANGEDataWriter
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

   Configure and implement 'DMSG_HMI_TRACKWEAPONRANGE' support classes.

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
#define TTYPENAME   DMSG_HMI_TRACKWEAPONRANGETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TRACKWEAPONRANGEDataWriter
#define TData       DMSG_HMI_TRACKWEAPONRANGE


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
#define TTYPENAME   DMSG_HMI_TRACKWEAPONRANGETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TRACKWEAPONRANGEDataReader
#define TDataSeq    DMSG_HMI_TRACKWEAPONRANGESeq
#define TData       DMSG_HMI_TRACKWEAPONRANGE


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
#define TTYPENAME    DMSG_HMI_TRACKWEAPONRANGETYPENAME
#define TPlugin_new  DMSG_HMI_TRACKWEAPONRANGEPlugin_new
#define TPlugin_delete  DMSG_HMI_TRACKWEAPONRANGEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TRACKWEAPONRANGETypeSupport
#define TData        DMSG_HMI_TRACKWEAPONRANGE
#define TDataReader  DMSG_HMI_TRACKWEAPONRANGEDataReader
#define TDataWriter  DMSG_HMI_TRACKWEAPONRANGEDataWriter
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

   Configure and implement 'DMSG_HMI_TRACKSENSORRANGE' support classes.

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
#define TTYPENAME   DMSG_HMI_TRACKSENSORRANGETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TRACKSENSORRANGEDataWriter
#define TData       DMSG_HMI_TRACKSENSORRANGE


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
#define TTYPENAME   DMSG_HMI_TRACKSENSORRANGETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TRACKSENSORRANGEDataReader
#define TDataSeq    DMSG_HMI_TRACKSENSORRANGESeq
#define TData       DMSG_HMI_TRACKSENSORRANGE


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
#define TTYPENAME    DMSG_HMI_TRACKSENSORRANGETYPENAME
#define TPlugin_new  DMSG_HMI_TRACKSENSORRANGEPlugin_new
#define TPlugin_delete  DMSG_HMI_TRACKSENSORRANGEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TRACKSENSORRANGETypeSupport
#define TData        DMSG_HMI_TRACKSENSORRANGE
#define TDataReader  DMSG_HMI_TRACKSENSORRANGEDataReader
#define TDataWriter  DMSG_HMI_TRACKSENSORRANGEDataWriter
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

   Configure and implement 'DMSG_HMI_ANTIWEAPONWEIGHT' support classes.

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
#define TTYPENAME   DMSG_HMI_ANTIWEAPONWEIGHTTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_ANTIWEAPONWEIGHTDataWriter
#define TData       DMSG_HMI_ANTIWEAPONWEIGHT


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
#define TTYPENAME   DMSG_HMI_ANTIWEAPONWEIGHTTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_ANTIWEAPONWEIGHTDataReader
#define TDataSeq    DMSG_HMI_ANTIWEAPONWEIGHTSeq
#define TData       DMSG_HMI_ANTIWEAPONWEIGHT


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
#define TTYPENAME    DMSG_HMI_ANTIWEAPONWEIGHTTYPENAME
#define TPlugin_new  DMSG_HMI_ANTIWEAPONWEIGHTPlugin_new
#define TPlugin_delete  DMSG_HMI_ANTIWEAPONWEIGHTPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_ANTIWEAPONWEIGHTTypeSupport
#define TData        DMSG_HMI_ANTIWEAPONWEIGHT
#define TDataReader  DMSG_HMI_ANTIWEAPONWEIGHTDataReader
#define TDataWriter  DMSG_HMI_ANTIWEAPONWEIGHTDataWriter
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

   Configure and implement 'DMSG_HMI_TAGSET' support classes.

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
#define TTYPENAME   DMSG_HMI_TAGSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TAGSETDataWriter
#define TData       DMSG_HMI_TAGSET


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
#define TTYPENAME   DMSG_HMI_TAGSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TAGSETDataReader
#define TDataSeq    DMSG_HMI_TAGSETSeq
#define TData       DMSG_HMI_TAGSET


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
#define TTYPENAME    DMSG_HMI_TAGSETTYPENAME
#define TPlugin_new  DMSG_HMI_TAGSETPlugin_new
#define TPlugin_delete  DMSG_HMI_TAGSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TAGSETTypeSupport
#define TData        DMSG_HMI_TAGSET
#define TDataReader  DMSG_HMI_TAGSETDataReader
#define TDataWriter  DMSG_HMI_TAGSETDataWriter
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

   Configure and implement 'DMSG_HMI_SONARSET' support classes.

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
#define TTYPENAME   DMSG_HMI_SONARSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_SONARSETDataWriter
#define TData       DMSG_HMI_SONARSET


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
#define TTYPENAME   DMSG_HMI_SONARSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_SONARSETDataReader
#define TDataSeq    DMSG_HMI_SONARSETSeq
#define TData       DMSG_HMI_SONARSET


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
#define TTYPENAME    DMSG_HMI_SONARSETTYPENAME
#define TPlugin_new  DMSG_HMI_SONARSETPlugin_new
#define TPlugin_delete  DMSG_HMI_SONARSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_SONARSETTypeSupport
#define TData        DMSG_HMI_SONARSET
#define TDataReader  DMSG_HMI_SONARSETDataReader
#define TDataWriter  DMSG_HMI_SONARSETDataWriter
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

   Configure and implement 'DMSG_HMI_WEAPONSET' support classes.

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
#define TTYPENAME   DMSG_HMI_WEAPONSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_WEAPONSETDataWriter
#define TData       DMSG_HMI_WEAPONSET


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
#define TTYPENAME   DMSG_HMI_WEAPONSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_WEAPONSETDataReader
#define TDataSeq    DMSG_HMI_WEAPONSETSeq
#define TData       DMSG_HMI_WEAPONSET


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
#define TTYPENAME    DMSG_HMI_WEAPONSETTYPENAME
#define TPlugin_new  DMSG_HMI_WEAPONSETPlugin_new
#define TPlugin_delete  DMSG_HMI_WEAPONSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_WEAPONSETTypeSupport
#define TData        DMSG_HMI_WEAPONSET
#define TDataReader  DMSG_HMI_WEAPONSETDataReader
#define TDataWriter  DMSG_HMI_WEAPONSETDataWriter
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

   Configure and implement 'DMSG_HMI_SUBCORRELATIONSET' support classes.

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
#define TTYPENAME   DMSG_HMI_SUBCORRELATIONSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_SUBCORRELATIONSETDataWriter
#define TData       DMSG_HMI_SUBCORRELATIONSET


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
#define TTYPENAME   DMSG_HMI_SUBCORRELATIONSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_SUBCORRELATIONSETDataReader
#define TDataSeq    DMSG_HMI_SUBCORRELATIONSETSeq
#define TData       DMSG_HMI_SUBCORRELATIONSET


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
#define TTYPENAME    DMSG_HMI_SUBCORRELATIONSETTYPENAME
#define TPlugin_new  DMSG_HMI_SUBCORRELATIONSETPlugin_new
#define TPlugin_delete  DMSG_HMI_SUBCORRELATIONSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_SUBCORRELATIONSETTypeSupport
#define TData        DMSG_HMI_SUBCORRELATIONSET
#define TDataReader  DMSG_HMI_SUBCORRELATIONSETDataReader
#define TDataWriter  DMSG_HMI_SUBCORRELATIONSETDataWriter
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

   Configure and implement 'DMSG_HMI_SUBCORRELATIONCLEAR' support classes.

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
#define TTYPENAME   DMSG_HMI_SUBCORRELATIONCLEARTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_SUBCORRELATIONCLEARDataWriter
#define TData       DMSG_HMI_SUBCORRELATIONCLEAR


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
#define TTYPENAME   DMSG_HMI_SUBCORRELATIONCLEARTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_SUBCORRELATIONCLEARDataReader
#define TDataSeq    DMSG_HMI_SUBCORRELATIONCLEARSeq
#define TData       DMSG_HMI_SUBCORRELATIONCLEAR


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
#define TTYPENAME    DMSG_HMI_SUBCORRELATIONCLEARTYPENAME
#define TPlugin_new  DMSG_HMI_SUBCORRELATIONCLEARPlugin_new
#define TPlugin_delete  DMSG_HMI_SUBCORRELATIONCLEARPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_SUBCORRELATIONCLEARTypeSupport
#define TData        DMSG_HMI_SUBCORRELATIONCLEAR
#define TDataReader  DMSG_HMI_SUBCORRELATIONCLEARDataReader
#define TDataWriter  DMSG_HMI_SUBCORRELATIONCLEARDataWriter
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

   Configure and implement 'DMSG_TM_SYSTRACKDEL' support classes.

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
#define TTYPENAME   DMSG_TM_SYSTRACKDELTYPENAME

/* Defines */
#define TDataWriter DMSG_TM_SYSTRACKDELDataWriter
#define TData       DMSG_TM_SYSTRACKDEL


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
#define TTYPENAME   DMSG_TM_SYSTRACKDELTYPENAME

/* Defines */
#define TDataReader DMSG_TM_SYSTRACKDELDataReader
#define TDataSeq    DMSG_TM_SYSTRACKDELSeq
#define TData       DMSG_TM_SYSTRACKDEL


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
#define TTYPENAME    DMSG_TM_SYSTRACKDELTYPENAME
#define TPlugin_new  DMSG_TM_SYSTRACKDELPlugin_new
#define TPlugin_delete  DMSG_TM_SYSTRACKDELPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TM_SYSTRACKDELTypeSupport
#define TData        DMSG_TM_SYSTRACKDEL
#define TDataReader  DMSG_TM_SYSTRACKDELDataReader
#define TDataWriter  DMSG_TM_SYSTRACKDELDataWriter
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

   Configure and implement 'DMSG_TM_SYSTRACK' support classes.

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
#define TTYPENAME   DMSG_TM_SYSTRACKTYPENAME

/* Defines */
#define TDataWriter DMSG_TM_SYSTRACKDataWriter
#define TData       DMSG_TM_SYSTRACK


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
#define TTYPENAME   DMSG_TM_SYSTRACKTYPENAME

/* Defines */
#define TDataReader DMSG_TM_SYSTRACKDataReader
#define TDataSeq    DMSG_TM_SYSTRACKSeq
#define TData       DMSG_TM_SYSTRACK


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
#define TTYPENAME    DMSG_TM_SYSTRACKTYPENAME
#define TPlugin_new  DMSG_TM_SYSTRACKPlugin_new
#define TPlugin_delete  DMSG_TM_SYSTRACKPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TM_SYSTRACKTypeSupport
#define TData        DMSG_TM_SYSTRACK
#define TDataReader  DMSG_TM_SYSTRACKDataReader
#define TDataWriter  DMSG_TM_SYSTRACKDataWriter
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

   Configure and implement 'DMSG_TM_SWSTATE' support classes.

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
#define TTYPENAME   DMSG_TM_SWSTATETYPENAME

/* Defines */
#define TDataWriter DMSG_TM_SWSTATEDataWriter
#define TData       DMSG_TM_SWSTATE


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
#define TTYPENAME   DMSG_TM_SWSTATETYPENAME

/* Defines */
#define TDataReader DMSG_TM_SWSTATEDataReader
#define TDataSeq    DMSG_TM_SWSTATESeq
#define TData       DMSG_TM_SWSTATE


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
#define TTYPENAME    DMSG_TM_SWSTATETYPENAME
#define TPlugin_new  DMSG_TM_SWSTATEPlugin_new
#define TPlugin_delete  DMSG_TM_SWSTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TM_SWSTATETypeSupport
#define TData        DMSG_TM_SWSTATE
#define TDataReader  DMSG_TM_SWSTATEDataReader
#define TDataWriter  DMSG_TM_SWSTATEDataWriter
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

   Configure and implement 'DMSG_TM_SUBSYSTEMTRACK' support classes.

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
#define TTYPENAME   DMSG_TM_SUBSYSTEMTRACKTYPENAME

/* Defines */
#define TDataWriter DMSG_TM_SUBSYSTEMTRACKDataWriter
#define TData       DMSG_TM_SUBSYSTEMTRACK


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
#define TTYPENAME   DMSG_TM_SUBSYSTEMTRACKTYPENAME

/* Defines */
#define TDataReader DMSG_TM_SUBSYSTEMTRACKDataReader
#define TDataSeq    DMSG_TM_SUBSYSTEMTRACKSeq
#define TData       DMSG_TM_SUBSYSTEMTRACK


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
#define TTYPENAME    DMSG_TM_SUBSYSTEMTRACKTYPENAME
#define TPlugin_new  DMSG_TM_SUBSYSTEMTRACKPlugin_new
#define TPlugin_delete  DMSG_TM_SUBSYSTEMTRACKPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TM_SUBSYSTEMTRACKTypeSupport
#define TData        DMSG_TM_SUBSYSTEMTRACK
#define TDataReader  DMSG_TM_SUBSYSTEMTRACKDataReader
#define TDataWriter  DMSG_TM_SUBSYSTEMTRACKDataWriter
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

   Configure and implement 'DMSG_TM_SUBSYSTRACKDEL' support classes.

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
#define TTYPENAME   DMSG_TM_SUBSYSTRACKDELTYPENAME

/* Defines */
#define TDataWriter DMSG_TM_SUBSYSTRACKDELDataWriter
#define TData       DMSG_TM_SUBSYSTRACKDEL


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
#define TTYPENAME   DMSG_TM_SUBSYSTRACKDELTYPENAME

/* Defines */
#define TDataReader DMSG_TM_SUBSYSTRACKDELDataReader
#define TDataSeq    DMSG_TM_SUBSYSTRACKDELSeq
#define TData       DMSG_TM_SUBSYSTRACKDEL


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
#define TTYPENAME    DMSG_TM_SUBSYSTRACKDELTYPENAME
#define TPlugin_new  DMSG_TM_SUBSYSTRACKDELPlugin_new
#define TPlugin_delete  DMSG_TM_SUBSYSTRACKDELPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TM_SUBSYSTRACKDELTypeSupport
#define TData        DMSG_TM_SUBSYSTRACKDEL
#define TDataReader  DMSG_TM_SUBSYSTRACKDELDataReader
#define TDataWriter  DMSG_TM_SUBSYSTRACKDELDataWriter
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

   Configure and implement 'DMSG_HMI_WEAPONCTRL' support classes.

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
#define TTYPENAME   DMSG_HMI_WEAPONCTRLTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_WEAPONCTRLDataWriter
#define TData       DMSG_HMI_WEAPONCTRL


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
#define TTYPENAME   DMSG_HMI_WEAPONCTRLTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_WEAPONCTRLDataReader
#define TDataSeq    DMSG_HMI_WEAPONCTRLSeq
#define TData       DMSG_HMI_WEAPONCTRL


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
#define TTYPENAME    DMSG_HMI_WEAPONCTRLTYPENAME
#define TPlugin_new  DMSG_HMI_WEAPONCTRLPlugin_new
#define TPlugin_delete  DMSG_HMI_WEAPONCTRLPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_WEAPONCTRLTypeSupport
#define TData        DMSG_HMI_WEAPONCTRL
#define TDataReader  DMSG_HMI_WEAPONCTRLDataReader
#define TDataWriter  DMSG_HMI_WEAPONCTRLDataWriter
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

   Configure and implement 'DMSG_HMI_FASTRESPONSEMODE' support classes.

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
#define TTYPENAME   DMSG_HMI_FASTRESPONSEMODETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_FASTRESPONSEMODEDataWriter
#define TData       DMSG_HMI_FASTRESPONSEMODE


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
#define TTYPENAME   DMSG_HMI_FASTRESPONSEMODETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_FASTRESPONSEMODEDataReader
#define TDataSeq    DMSG_HMI_FASTRESPONSEMODESeq
#define TData       DMSG_HMI_FASTRESPONSEMODE


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
#define TTYPENAME    DMSG_HMI_FASTRESPONSEMODETYPENAME
#define TPlugin_new  DMSG_HMI_FASTRESPONSEMODEPlugin_new
#define TPlugin_delete  DMSG_HMI_FASTRESPONSEMODEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_FASTRESPONSEMODETypeSupport
#define TData        DMSG_HMI_FASTRESPONSEMODE
#define TDataReader  DMSG_HMI_FASTRESPONSEMODEDataReader
#define TDataWriter  DMSG_HMI_FASTRESPONSEMODEDataWriter
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

   Configure and implement 'DMSG_HMI_WEAPONUSELIMIT' support classes.

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
#define TTYPENAME   DMSG_HMI_WEAPONUSELIMITTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_WEAPONUSELIMITDataWriter
#define TData       DMSG_HMI_WEAPONUSELIMIT


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
#define TTYPENAME   DMSG_HMI_WEAPONUSELIMITTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_WEAPONUSELIMITDataReader
#define TDataSeq    DMSG_HMI_WEAPONUSELIMITSeq
#define TData       DMSG_HMI_WEAPONUSELIMIT


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
#define TTYPENAME    DMSG_HMI_WEAPONUSELIMITTYPENAME
#define TPlugin_new  DMSG_HMI_WEAPONUSELIMITPlugin_new
#define TPlugin_delete  DMSG_HMI_WEAPONUSELIMITPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_WEAPONUSELIMITTypeSupport
#define TData        DMSG_HMI_WEAPONUSELIMIT
#define TDataReader  DMSG_HMI_WEAPONUSELIMITDataReader
#define TDataWriter  DMSG_HMI_WEAPONUSELIMITDataWriter
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

   Configure and implement 'DMSG_HMI_ENGAGEMODESET' support classes.

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
#define TTYPENAME   DMSG_HMI_ENGAGEMODESETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_ENGAGEMODESETDataWriter
#define TData       DMSG_HMI_ENGAGEMODESET


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
#define TTYPENAME   DMSG_HMI_ENGAGEMODESETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_ENGAGEMODESETDataReader
#define TDataSeq    DMSG_HMI_ENGAGEMODESETSeq
#define TData       DMSG_HMI_ENGAGEMODESET


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
#define TTYPENAME    DMSG_HMI_ENGAGEMODESETTYPENAME
#define TPlugin_new  DMSG_HMI_ENGAGEMODESETPlugin_new
#define TPlugin_delete  DMSG_HMI_ENGAGEMODESETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_ENGAGEMODESETTypeSupport
#define TData        DMSG_HMI_ENGAGEMODESET
#define TDataReader  DMSG_HMI_ENGAGEMODESETDataReader
#define TDataWriter  DMSG_HMI_ENGAGEMODESETDataWriter
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

   Configure and implement 'DMSG_HMI_ENGAGEADVICEREQ' support classes.

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
#define TTYPENAME   DMSG_HMI_ENGAGEADVICEREQTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_ENGAGEADVICEREQDataWriter
#define TData       DMSG_HMI_ENGAGEADVICEREQ


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
#define TTYPENAME   DMSG_HMI_ENGAGEADVICEREQTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_ENGAGEADVICEREQDataReader
#define TDataSeq    DMSG_HMI_ENGAGEADVICEREQSeq
#define TData       DMSG_HMI_ENGAGEADVICEREQ


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
#define TTYPENAME    DMSG_HMI_ENGAGEADVICEREQTYPENAME
#define TPlugin_new  DMSG_HMI_ENGAGEADVICEREQPlugin_new
#define TPlugin_delete  DMSG_HMI_ENGAGEADVICEREQPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_ENGAGEADVICEREQTypeSupport
#define TData        DMSG_HMI_ENGAGEADVICEREQ
#define TDataReader  DMSG_HMI_ENGAGEADVICEREQDataReader
#define TDataWriter  DMSG_HMI_ENGAGEADVICEREQDataWriter
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

   Configure and implement 'DMSG_HMI_THREATDICISION' support classes.

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
#define TTYPENAME   DMSG_HMI_THREATDICISIONTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_THREATDICISIONDataWriter
#define TData       DMSG_HMI_THREATDICISION


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
#define TTYPENAME   DMSG_HMI_THREATDICISIONTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_THREATDICISIONDataReader
#define TDataSeq    DMSG_HMI_THREATDICISIONSeq
#define TData       DMSG_HMI_THREATDICISION


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
#define TTYPENAME    DMSG_HMI_THREATDICISIONTYPENAME
#define TPlugin_new  DMSG_HMI_THREATDICISIONPlugin_new
#define TPlugin_delete  DMSG_HMI_THREATDICISIONPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_THREATDICISIONTypeSupport
#define TData        DMSG_HMI_THREATDICISION
#define TDataReader  DMSG_HMI_THREATDICISIONDataReader
#define TDataWriter  DMSG_HMI_THREATDICISIONDataWriter
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

   Configure and implement 'DMSG_HMI_WEAPONRANGE' support classes.

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
#define TTYPENAME   DMSG_HMI_WEAPONRANGETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_WEAPONRANGEDataWriter
#define TData       DMSG_HMI_WEAPONRANGE


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
#define TTYPENAME   DMSG_HMI_WEAPONRANGETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_WEAPONRANGEDataReader
#define TDataSeq    DMSG_HMI_WEAPONRANGESeq
#define TData       DMSG_HMI_WEAPONRANGE


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
#define TTYPENAME    DMSG_HMI_WEAPONRANGETYPENAME
#define TPlugin_new  DMSG_HMI_WEAPONRANGEPlugin_new
#define TPlugin_delete  DMSG_HMI_WEAPONRANGEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_WEAPONRANGETypeSupport
#define TData        DMSG_HMI_WEAPONRANGE
#define TDataReader  DMSG_HMI_WEAPONRANGEDataReader
#define TDataWriter  DMSG_HMI_WEAPONRANGEDataWriter
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

   Configure and implement 'DMSG_HMI_SENSORRANGE' support classes.

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
#define TTYPENAME   DMSG_HMI_SENSORRANGETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_SENSORRANGEDataWriter
#define TData       DMSG_HMI_SENSORRANGE


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
#define TTYPENAME   DMSG_HMI_SENSORRANGETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_SENSORRANGEDataReader
#define TDataSeq    DMSG_HMI_SENSORRANGESeq
#define TData       DMSG_HMI_SENSORRANGE


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
#define TTYPENAME    DMSG_HMI_SENSORRANGETYPENAME
#define TPlugin_new  DMSG_HMI_SENSORRANGEPlugin_new
#define TPlugin_delete  DMSG_HMI_SENSORRANGEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_SENSORRANGETypeSupport
#define TData        DMSG_HMI_SENSORRANGE
#define TDataReader  DMSG_HMI_SENSORRANGEDataReader
#define TDataWriter  DMSG_HMI_SENSORRANGEDataWriter
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

   Configure and implement 'DMSG_HMI_ENGAGEADVICEMODIFY' support classes.

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
#define TTYPENAME   DMSG_HMI_ENGAGEADVICEMODIFYTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_ENGAGEADVICEMODIFYDataWriter
#define TData       DMSG_HMI_ENGAGEADVICEMODIFY


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
#define TTYPENAME   DMSG_HMI_ENGAGEADVICEMODIFYTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_ENGAGEADVICEMODIFYDataReader
#define TDataSeq    DMSG_HMI_ENGAGEADVICEMODIFYSeq
#define TData       DMSG_HMI_ENGAGEADVICEMODIFY


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
#define TTYPENAME    DMSG_HMI_ENGAGEADVICEMODIFYTYPENAME
#define TPlugin_new  DMSG_HMI_ENGAGEADVICEMODIFYPlugin_new
#define TPlugin_delete  DMSG_HMI_ENGAGEADVICEMODIFYPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_ENGAGEADVICEMODIFYTypeSupport
#define TData        DMSG_HMI_ENGAGEADVICEMODIFY
#define TDataReader  DMSG_HMI_ENGAGEADVICEMODIFYDataReader
#define TDataWriter  DMSG_HMI_ENGAGEADVICEMODIFYDataWriter
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

   Configure and implement 'DMSG_HMI_CLEARENGAGEASSIGN' support classes.

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
#define TTYPENAME   DMSG_HMI_CLEARENGAGEASSIGNTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_CLEARENGAGEASSIGNDataWriter
#define TData       DMSG_HMI_CLEARENGAGEASSIGN


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
#define TTYPENAME   DMSG_HMI_CLEARENGAGEASSIGNTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_CLEARENGAGEASSIGNDataReader
#define TDataSeq    DMSG_HMI_CLEARENGAGEASSIGNSeq
#define TData       DMSG_HMI_CLEARENGAGEASSIGN


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
#define TTYPENAME    DMSG_HMI_CLEARENGAGEASSIGNTYPENAME
#define TPlugin_new  DMSG_HMI_CLEARENGAGEASSIGNPlugin_new
#define TPlugin_delete  DMSG_HMI_CLEARENGAGEASSIGNPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_CLEARENGAGEASSIGNTypeSupport
#define TData        DMSG_HMI_CLEARENGAGEASSIGN
#define TDataReader  DMSG_HMI_CLEARENGAGEASSIGNDataReader
#define TDataWriter  DMSG_HMI_CLEARENGAGEASSIGNDataWriter
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

   Configure and implement 'DMSG_HMI_THREATWEIGHT' support classes.

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
#define TTYPENAME   DMSG_HMI_THREATWEIGHTTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_THREATWEIGHTDataWriter
#define TData       DMSG_HMI_THREATWEIGHT


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
#define TTYPENAME   DMSG_HMI_THREATWEIGHTTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_THREATWEIGHTDataReader
#define TDataSeq    DMSG_HMI_THREATWEIGHTSeq
#define TData       DMSG_HMI_THREATWEIGHT


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
#define TTYPENAME    DMSG_HMI_THREATWEIGHTTYPENAME
#define TPlugin_new  DMSG_HMI_THREATWEIGHTPlugin_new
#define TPlugin_delete  DMSG_HMI_THREATWEIGHTPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_THREATWEIGHTTypeSupport
#define TData        DMSG_HMI_THREATWEIGHT
#define TDataReader  DMSG_HMI_THREATWEIGHTDataReader
#define TDataWriter  DMSG_HMI_THREATWEIGHTDataWriter
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

   Configure and implement 'DMSG_HMI_DEFENSEMODE' support classes.

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
#define TTYPENAME   DMSG_HMI_DEFENSEMODETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_DEFENSEMODEDataWriter
#define TData       DMSG_HMI_DEFENSEMODE


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
#define TTYPENAME   DMSG_HMI_DEFENSEMODETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_DEFENSEMODEDataReader
#define TDataSeq    DMSG_HMI_DEFENSEMODESeq
#define TData       DMSG_HMI_DEFENSEMODE


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
#define TTYPENAME    DMSG_HMI_DEFENSEMODETYPENAME
#define TPlugin_new  DMSG_HMI_DEFENSEMODEPlugin_new
#define TPlugin_delete  DMSG_HMI_DEFENSEMODEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_DEFENSEMODETypeSupport
#define TData        DMSG_HMI_DEFENSEMODE
#define TDataReader  DMSG_HMI_DEFENSEMODEDataReader
#define TDataWriter  DMSG_HMI_DEFENSEMODEDataWriter
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

   Configure and implement 'DMSG_HMI_FIREPERMIT' support classes.

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
#define TTYPENAME   DMSG_HMI_FIREPERMITTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_FIREPERMITDataWriter
#define TData       DMSG_HMI_FIREPERMIT


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
#define TTYPENAME   DMSG_HMI_FIREPERMITTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_FIREPERMITDataReader
#define TDataSeq    DMSG_HMI_FIREPERMITSeq
#define TData       DMSG_HMI_FIREPERMIT


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
#define TTYPENAME    DMSG_HMI_FIREPERMITTYPENAME
#define TPlugin_new  DMSG_HMI_FIREPERMITPlugin_new
#define TPlugin_delete  DMSG_HMI_FIREPERMITPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_FIREPERMITTypeSupport
#define TData        DMSG_HMI_FIREPERMIT
#define TDataReader  DMSG_HMI_FIREPERMITDataReader
#define TDataWriter  DMSG_HMI_FIREPERMITDataWriter
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

   Configure and implement 'DMSG_HMI_ENGAGECANCEL' support classes.

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
#define TTYPENAME   DMSG_HMI_ENGAGECANCELTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_ENGAGECANCELDataWriter
#define TData       DMSG_HMI_ENGAGECANCEL


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
#define TTYPENAME   DMSG_HMI_ENGAGECANCELTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_ENGAGECANCELDataReader
#define TDataSeq    DMSG_HMI_ENGAGECANCELSeq
#define TData       DMSG_HMI_ENGAGECANCEL


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
#define TTYPENAME    DMSG_HMI_ENGAGECANCELTYPENAME
#define TPlugin_new  DMSG_HMI_ENGAGECANCELPlugin_new
#define TPlugin_delete  DMSG_HMI_ENGAGECANCELPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_ENGAGECANCELTypeSupport
#define TData        DMSG_HMI_ENGAGECANCEL
#define TDataReader  DMSG_HMI_ENGAGECANCELDataReader
#define TDataWriter  DMSG_HMI_ENGAGECANCELDataWriter
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

   Configure and implement 'DMSG_HMI_HITEVALUATIONSET' support classes.

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
#define TTYPENAME   DMSG_HMI_HITEVALUATIONSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_HITEVALUATIONSETDataWriter
#define TData       DMSG_HMI_HITEVALUATIONSET


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
#define TTYPENAME   DMSG_HMI_HITEVALUATIONSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_HITEVALUATIONSETDataReader
#define TDataSeq    DMSG_HMI_HITEVALUATIONSETSeq
#define TData       DMSG_HMI_HITEVALUATIONSET


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
#define TTYPENAME    DMSG_HMI_HITEVALUATIONSETTYPENAME
#define TPlugin_new  DMSG_HMI_HITEVALUATIONSETPlugin_new
#define TPlugin_delete  DMSG_HMI_HITEVALUATIONSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_HITEVALUATIONSETTypeSupport
#define TData        DMSG_HMI_HITEVALUATIONSET
#define TDataReader  DMSG_HMI_HITEVALUATIONSETDataReader
#define TDataWriter  DMSG_HMI_HITEVALUATIONSETDataWriter
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

   Configure and implement 'DMSG_HMI_ASSIGNCONSOLE' support classes.

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
#define TTYPENAME   DMSG_HMI_ASSIGNCONSOLETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_ASSIGNCONSOLEDataWriter
#define TData       DMSG_HMI_ASSIGNCONSOLE


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
#define TTYPENAME   DMSG_HMI_ASSIGNCONSOLETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_ASSIGNCONSOLEDataReader
#define TDataSeq    DMSG_HMI_ASSIGNCONSOLESeq
#define TData       DMSG_HMI_ASSIGNCONSOLE


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
#define TTYPENAME    DMSG_HMI_ASSIGNCONSOLETYPENAME
#define TPlugin_new  DMSG_HMI_ASSIGNCONSOLEPlugin_new
#define TPlugin_delete  DMSG_HMI_ASSIGNCONSOLEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_ASSIGNCONSOLETypeSupport
#define TData        DMSG_HMI_ASSIGNCONSOLE
#define TDataReader  DMSG_HMI_ASSIGNCONSOLEDataReader
#define TDataWriter  DMSG_HMI_ASSIGNCONSOLEDataWriter
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

   Configure and implement 'DMSG_HMI_GUIDEDWEAPONPERMIT' support classes.

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
#define TTYPENAME   DMSG_HMI_GUIDEDWEAPONPERMITTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_GUIDEDWEAPONPERMITDataWriter
#define TData       DMSG_HMI_GUIDEDWEAPONPERMIT


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
#define TTYPENAME   DMSG_HMI_GUIDEDWEAPONPERMITTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_GUIDEDWEAPONPERMITDataReader
#define TDataSeq    DMSG_HMI_GUIDEDWEAPONPERMITSeq
#define TData       DMSG_HMI_GUIDEDWEAPONPERMIT


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
#define TTYPENAME    DMSG_HMI_GUIDEDWEAPONPERMITTYPENAME
#define TPlugin_new  DMSG_HMI_GUIDEDWEAPONPERMITPlugin_new
#define TPlugin_delete  DMSG_HMI_GUIDEDWEAPONPERMITPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_GUIDEDWEAPONPERMITTypeSupport
#define TData        DMSG_HMI_GUIDEDWEAPONPERMIT
#define TDataReader  DMSG_HMI_GUIDEDWEAPONPERMITDataReader
#define TDataWriter  DMSG_HMI_GUIDEDWEAPONPERMITDataWriter
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

   Configure and implement 'DMSG_HMI_ASSIGNTUBE' support classes.

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
#define TTYPENAME   DMSG_HMI_ASSIGNTUBETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_ASSIGNTUBEDataWriter
#define TData       DMSG_HMI_ASSIGNTUBE


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
#define TTYPENAME   DMSG_HMI_ASSIGNTUBETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_ASSIGNTUBEDataReader
#define TDataSeq    DMSG_HMI_ASSIGNTUBESeq
#define TData       DMSG_HMI_ASSIGNTUBE


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
#define TTYPENAME    DMSG_HMI_ASSIGNTUBETYPENAME
#define TPlugin_new  DMSG_HMI_ASSIGNTUBEPlugin_new
#define TPlugin_delete  DMSG_HMI_ASSIGNTUBEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_ASSIGNTUBETypeSupport
#define TData        DMSG_HMI_ASSIGNTUBE
#define TDataReader  DMSG_HMI_ASSIGNTUBEDataReader
#define TDataWriter  DMSG_HMI_ASSIGNTUBEDataWriter
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

   Configure and implement 'DMSG_HMI_ENGAGEPLANSET' support classes.

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
#define TTYPENAME   DMSG_HMI_ENGAGEPLANSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_ENGAGEPLANSETDataWriter
#define TData       DMSG_HMI_ENGAGEPLANSET


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
#define TTYPENAME   DMSG_HMI_ENGAGEPLANSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_ENGAGEPLANSETDataReader
#define TDataSeq    DMSG_HMI_ENGAGEPLANSETSeq
#define TData       DMSG_HMI_ENGAGEPLANSET


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
#define TTYPENAME    DMSG_HMI_ENGAGEPLANSETTYPENAME
#define TPlugin_new  DMSG_HMI_ENGAGEPLANSETPlugin_new
#define TPlugin_delete  DMSG_HMI_ENGAGEPLANSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_ENGAGEPLANSETTypeSupport
#define TData        DMSG_HMI_ENGAGEPLANSET
#define TDataReader  DMSG_HMI_ENGAGEPLANSETDataReader
#define TDataWriter  DMSG_HMI_ENGAGEPLANSETDataWriter
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

   Configure and implement 'DMSG_HMI_FIREPERMITKEYSTATE' support classes.

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
#define TTYPENAME   DMSG_HMI_FIREPERMITKEYSTATETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_FIREPERMITKEYSTATEDataWriter
#define TData       DMSG_HMI_FIREPERMITKEYSTATE


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
#define TTYPENAME   DMSG_HMI_FIREPERMITKEYSTATETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_FIREPERMITKEYSTATEDataReader
#define TDataSeq    DMSG_HMI_FIREPERMITKEYSTATESeq
#define TData       DMSG_HMI_FIREPERMITKEYSTATE


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
#define TTYPENAME    DMSG_HMI_FIREPERMITKEYSTATETYPENAME
#define TPlugin_new  DMSG_HMI_FIREPERMITKEYSTATEPlugin_new
#define TPlugin_delete  DMSG_HMI_FIREPERMITKEYSTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_FIREPERMITKEYSTATETypeSupport
#define TData        DMSG_HMI_FIREPERMITKEYSTATE
#define TDataReader  DMSG_HMI_FIREPERMITKEYSTATEDataReader
#define TDataWriter  DMSG_HMI_FIREPERMITKEYSTATEDataWriter
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

   Configure and implement 'DMSG_HMI_FIREPERMITBTNSTATE' support classes.

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
#define TTYPENAME   DMSG_HMI_FIREPERMITBTNSTATETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_FIREPERMITBTNSTATEDataWriter
#define TData       DMSG_HMI_FIREPERMITBTNSTATE


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
#define TTYPENAME   DMSG_HMI_FIREPERMITBTNSTATETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_FIREPERMITBTNSTATEDataReader
#define TDataSeq    DMSG_HMI_FIREPERMITBTNSTATESeq
#define TData       DMSG_HMI_FIREPERMITBTNSTATE


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
#define TTYPENAME    DMSG_HMI_FIREPERMITBTNSTATETYPENAME
#define TPlugin_new  DMSG_HMI_FIREPERMITBTNSTATEPlugin_new
#define TPlugin_delete  DMSG_HMI_FIREPERMITBTNSTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_FIREPERMITBTNSTATETypeSupport
#define TData        DMSG_HMI_FIREPERMITBTNSTATE
#define TDataReader  DMSG_HMI_FIREPERMITBTNSTATEDataReader
#define TDataWriter  DMSG_HMI_FIREPERMITBTNSTATEDataWriter
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

   Configure and implement 'DMSG_HMI_FIRECMD' support classes.

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
#define TTYPENAME   DMSG_HMI_FIRECMDTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_FIRECMDDataWriter
#define TData       DMSG_HMI_FIRECMD


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
#define TTYPENAME   DMSG_HMI_FIRECMDTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_FIRECMDDataReader
#define TDataSeq    DMSG_HMI_FIRECMDSeq
#define TData       DMSG_HMI_FIRECMD


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
#define TTYPENAME    DMSG_HMI_FIRECMDTYPENAME
#define TPlugin_new  DMSG_HMI_FIRECMDPlugin_new
#define TPlugin_delete  DMSG_HMI_FIRECMDPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_FIRECMDTypeSupport
#define TData        DMSG_HMI_FIRECMD
#define TDataReader  DMSG_HMI_FIRECMDDataReader
#define TDataWriter  DMSG_HMI_FIRECMDDataWriter
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

   Configure and implement 'DMSG_HMI_ENGAGEASSIGNCMD' support classes.

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
#define TTYPENAME   DMSG_HMI_ENGAGEASSIGNCMDTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_ENGAGEASSIGNCMDDataWriter
#define TData       DMSG_HMI_ENGAGEASSIGNCMD


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
#define TTYPENAME   DMSG_HMI_ENGAGEASSIGNCMDTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_ENGAGEASSIGNCMDDataReader
#define TDataSeq    DMSG_HMI_ENGAGEASSIGNCMDSeq
#define TData       DMSG_HMI_ENGAGEASSIGNCMD


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
#define TTYPENAME    DMSG_HMI_ENGAGEASSIGNCMDTYPENAME
#define TPlugin_new  DMSG_HMI_ENGAGEASSIGNCMDPlugin_new
#define TPlugin_delete  DMSG_HMI_ENGAGEASSIGNCMDPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_ENGAGEASSIGNCMDTypeSupport
#define TData        DMSG_HMI_ENGAGEASSIGNCMD
#define TDataReader  DMSG_HMI_ENGAGEASSIGNCMDDataReader
#define TDataWriter  DMSG_HMI_ENGAGEASSIGNCMDDataWriter
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

   Configure and implement 'DMSG_HMI_FIRINGCMD' support classes.

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
#define TTYPENAME   DMSG_HMI_FIRINGCMDTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_FIRINGCMDDataWriter
#define TData       DMSG_HMI_FIRINGCMD


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
#define TTYPENAME   DMSG_HMI_FIRINGCMDTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_FIRINGCMDDataReader
#define TDataSeq    DMSG_HMI_FIRINGCMDSeq
#define TData       DMSG_HMI_FIRINGCMD


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
#define TTYPENAME    DMSG_HMI_FIRINGCMDTYPENAME
#define TPlugin_new  DMSG_HMI_FIRINGCMDPlugin_new
#define TPlugin_delete  DMSG_HMI_FIRINGCMDPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_FIRINGCMDTypeSupport
#define TData        DMSG_HMI_FIRINGCMD
#define TDataReader  DMSG_HMI_FIRINGCMDDataReader
#define TDataWriter  DMSG_HMI_FIRINGCMDDataWriter
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

   Configure and implement 'DMSG_EC_ENGAGEDEL' support classes.

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
#define TTYPENAME   DMSG_EC_ENGAGEDELTYPENAME

/* Defines */
#define TDataWriter DMSG_EC_ENGAGEDELDataWriter
#define TData       DMSG_EC_ENGAGEDEL


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
#define TTYPENAME   DMSG_EC_ENGAGEDELTYPENAME

/* Defines */
#define TDataReader DMSG_EC_ENGAGEDELDataReader
#define TDataSeq    DMSG_EC_ENGAGEDELSeq
#define TData       DMSG_EC_ENGAGEDEL


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
#define TTYPENAME    DMSG_EC_ENGAGEDELTYPENAME
#define TPlugin_new  DMSG_EC_ENGAGEDELPlugin_new
#define TPlugin_delete  DMSG_EC_ENGAGEDELPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_ENGAGEDELTypeSupport
#define TData        DMSG_EC_ENGAGEDEL
#define TDataReader  DMSG_EC_ENGAGEDELDataReader
#define TDataWriter  DMSG_EC_ENGAGEDELDataWriter
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

   Configure and implement 'DMSG_HMI_MANUALENGAGEASSIGN' support classes.

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
#define TTYPENAME   DMSG_HMI_MANUALENGAGEASSIGNTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_MANUALENGAGEASSIGNDataWriter
#define TData       DMSG_HMI_MANUALENGAGEASSIGN


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
#define TTYPENAME   DMSG_HMI_MANUALENGAGEASSIGNTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_MANUALENGAGEASSIGNDataReader
#define TDataSeq    DMSG_HMI_MANUALENGAGEASSIGNSeq
#define TData       DMSG_HMI_MANUALENGAGEASSIGN


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
#define TTYPENAME    DMSG_HMI_MANUALENGAGEASSIGNTYPENAME
#define TPlugin_new  DMSG_HMI_MANUALENGAGEASSIGNPlugin_new
#define TPlugin_delete  DMSG_HMI_MANUALENGAGEASSIGNPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_MANUALENGAGEASSIGNTypeSupport
#define TData        DMSG_HMI_MANUALENGAGEASSIGN
#define TDataReader  DMSG_HMI_MANUALENGAGEASSIGNDataReader
#define TDataWriter  DMSG_HMI_MANUALENGAGEASSIGNDataWriter
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

   Configure and implement 'DMSG_HMI_EMERGENCYFIRE' support classes.

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
#define TTYPENAME   DMSG_HMI_EMERGENCYFIRETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_EMERGENCYFIREDataWriter
#define TData       DMSG_HMI_EMERGENCYFIRE


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
#define TTYPENAME   DMSG_HMI_EMERGENCYFIRETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_EMERGENCYFIREDataReader
#define TDataSeq    DMSG_HMI_EMERGENCYFIRESeq
#define TData       DMSG_HMI_EMERGENCYFIRE


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
#define TTYPENAME    DMSG_HMI_EMERGENCYFIRETYPENAME
#define TPlugin_new  DMSG_HMI_EMERGENCYFIREPlugin_new
#define TPlugin_delete  DMSG_HMI_EMERGENCYFIREPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_EMERGENCYFIRETypeSupport
#define TData        DMSG_HMI_EMERGENCYFIRE
#define TDataReader  DMSG_HMI_EMERGENCYFIREDataReader
#define TDataWriter  DMSG_HMI_EMERGENCYFIREDataWriter
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

   Configure and implement 'DMSG_HMI_SAMTARGETDESIG' support classes.

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
#define TTYPENAME   DMSG_HMI_SAMTARGETDESIGTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_SAMTARGETDESIGDataWriter
#define TData       DMSG_HMI_SAMTARGETDESIG


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
#define TTYPENAME   DMSG_HMI_SAMTARGETDESIGTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_SAMTARGETDESIGDataReader
#define TDataSeq    DMSG_HMI_SAMTARGETDESIGSeq
#define TData       DMSG_HMI_SAMTARGETDESIG


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
#define TTYPENAME    DMSG_HMI_SAMTARGETDESIGTYPENAME
#define TPlugin_new  DMSG_HMI_SAMTARGETDESIGPlugin_new
#define TPlugin_delete  DMSG_HMI_SAMTARGETDESIGPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_SAMTARGETDESIGTypeSupport
#define TData        DMSG_HMI_SAMTARGETDESIG
#define TDataReader  DMSG_HMI_SAMTARGETDESIGDataReader
#define TDataWriter  DMSG_HMI_SAMTARGETDESIGDataWriter
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

   Configure and implement 'DMSG_EC_GUIDEDWEAPONPERMIT' support classes.

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
#define TTYPENAME   DMSG_EC_GUIDEDWEAPONPERMITTYPENAME

/* Defines */
#define TDataWriter DMSG_EC_GUIDEDWEAPONPERMITDataWriter
#define TData       DMSG_EC_GUIDEDWEAPONPERMIT


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
#define TTYPENAME   DMSG_EC_GUIDEDWEAPONPERMITTYPENAME

/* Defines */
#define TDataReader DMSG_EC_GUIDEDWEAPONPERMITDataReader
#define TDataSeq    DMSG_EC_GUIDEDWEAPONPERMITSeq
#define TData       DMSG_EC_GUIDEDWEAPONPERMIT


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
#define TTYPENAME    DMSG_EC_GUIDEDWEAPONPERMITTYPENAME
#define TPlugin_new  DMSG_EC_GUIDEDWEAPONPERMITPlugin_new
#define TPlugin_delete  DMSG_EC_GUIDEDWEAPONPERMITPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_GUIDEDWEAPONPERMITTypeSupport
#define TData        DMSG_EC_GUIDEDWEAPONPERMIT
#define TDataReader  DMSG_EC_GUIDEDWEAPONPERMITDataReader
#define TDataWriter  DMSG_EC_GUIDEDWEAPONPERMITDataWriter
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

   Configure and implement 'DMSG_HMI_TRRTRACKINGCMD' support classes.

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
#define TTYPENAME   DMSG_HMI_TRRTRACKINGCMDTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TRRTRACKINGCMDDataWriter
#define TData       DMSG_HMI_TRRTRACKINGCMD


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
#define TTYPENAME   DMSG_HMI_TRRTRACKINGCMDTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TRRTRACKINGCMDDataReader
#define TDataSeq    DMSG_HMI_TRRTRACKINGCMDSeq
#define TData       DMSG_HMI_TRRTRACKINGCMD


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
#define TTYPENAME    DMSG_HMI_TRRTRACKINGCMDTYPENAME
#define TPlugin_new  DMSG_HMI_TRRTRACKINGCMDPlugin_new
#define TPlugin_delete  DMSG_HMI_TRRTRACKINGCMDPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TRRTRACKINGCMDTypeSupport
#define TData        DMSG_HMI_TRRTRACKINGCMD
#define TDataReader  DMSG_HMI_TRRTRACKINGCMDDataReader
#define TDataWriter  DMSG_HMI_TRRTRACKINGCMDDataWriter
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

   Configure and implement 'DMSG_HMI_EOTSSUBTRACKINGSET' support classes.

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
#define TTYPENAME   DMSG_HMI_EOTSSUBTRACKINGSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_EOTSSUBTRACKINGSETDataWriter
#define TData       DMSG_HMI_EOTSSUBTRACKINGSET


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
#define TTYPENAME   DMSG_HMI_EOTSSUBTRACKINGSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_EOTSSUBTRACKINGSETDataReader
#define TDataSeq    DMSG_HMI_EOTSSUBTRACKINGSETSeq
#define TData       DMSG_HMI_EOTSSUBTRACKINGSET


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
#define TTYPENAME    DMSG_HMI_EOTSSUBTRACKINGSETTYPENAME
#define TPlugin_new  DMSG_HMI_EOTSSUBTRACKINGSETPlugin_new
#define TPlugin_delete  DMSG_HMI_EOTSSUBTRACKINGSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_EOTSSUBTRACKINGSETTypeSupport
#define TData        DMSG_HMI_EOTSSUBTRACKINGSET
#define TDataReader  DMSG_HMI_EOTSSUBTRACKINGSETDataReader
#define TDataWriter  DMSG_HMI_EOTSSUBTRACKINGSETDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRTWSTARGETDESIG' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRTWSTARGETDESIGTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRTWSTARGETDESIGDataWriter
#define TData       DMSG_HMI_TDSRTWSTARGETDESIG


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
#define TTYPENAME   DMSG_HMI_TDSRTWSTARGETDESIGTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRTWSTARGETDESIGDataReader
#define TDataSeq    DMSG_HMI_TDSRTWSTARGETDESIGSeq
#define TData       DMSG_HMI_TDSRTWSTARGETDESIG


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
#define TTYPENAME    DMSG_HMI_TDSRTWSTARGETDESIGTYPENAME
#define TPlugin_new  DMSG_HMI_TDSRTWSTARGETDESIGPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRTWSTARGETDESIGPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRTWSTARGETDESIGTypeSupport
#define TData        DMSG_HMI_TDSRTWSTARGETDESIG
#define TDataReader  DMSG_HMI_TDSRTWSTARGETDESIGDataReader
#define TDataWriter  DMSG_HMI_TDSRTWSTARGETDESIGDataWriter
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

   Configure and implement 'DMSG_HMISUB_ENGAGECANCEL' support classes.

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
#define TTYPENAME   DMSG_HMISUB_ENGAGECANCELTYPENAME

/* Defines */
#define TDataWriter DMSG_HMISUB_ENGAGECANCELDataWriter
#define TData       DMSG_HMISUB_ENGAGECANCEL


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
#define TTYPENAME   DMSG_HMISUB_ENGAGECANCELTYPENAME

/* Defines */
#define TDataReader DMSG_HMISUB_ENGAGECANCELDataReader
#define TDataSeq    DMSG_HMISUB_ENGAGECANCELSeq
#define TData       DMSG_HMISUB_ENGAGECANCEL


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
#define TTYPENAME    DMSG_HMISUB_ENGAGECANCELTYPENAME
#define TPlugin_new  DMSG_HMISUB_ENGAGECANCELPlugin_new
#define TPlugin_delete  DMSG_HMISUB_ENGAGECANCELPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMISUB_ENGAGECANCELTypeSupport
#define TData        DMSG_HMISUB_ENGAGECANCEL
#define TDataReader  DMSG_HMISUB_ENGAGECANCELDataReader
#define TDataWriter  DMSG_HMISUB_ENGAGECANCELDataWriter
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

   Configure and implement 'DMSG_EC_SUBENGAGEDEL' support classes.

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
#define TTYPENAME   DMSG_EC_SUBENGAGEDELTYPENAME

/* Defines */
#define TDataWriter DMSG_EC_SUBENGAGEDELDataWriter
#define TData       DMSG_EC_SUBENGAGEDEL


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
#define TTYPENAME   DMSG_EC_SUBENGAGEDELTYPENAME

/* Defines */
#define TDataReader DMSG_EC_SUBENGAGEDELDataReader
#define TDataSeq    DMSG_EC_SUBENGAGEDELSeq
#define TData       DMSG_EC_SUBENGAGEDEL


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
#define TTYPENAME    DMSG_EC_SUBENGAGEDELTYPENAME
#define TPlugin_new  DMSG_EC_SUBENGAGEDELPlugin_new
#define TPlugin_delete  DMSG_EC_SUBENGAGEDELPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_SUBENGAGEDELTypeSupport
#define TData        DMSG_EC_SUBENGAGEDEL
#define TDataReader  DMSG_EC_SUBENGAGEDELDataReader
#define TDataWriter  DMSG_EC_SUBENGAGEDELDataWriter
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

   Configure and implement 'DMSG_HMI_FIREMODE' support classes.

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
#define TTYPENAME   DMSG_HMI_FIREMODETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_FIREMODEDataWriter
#define TData       DMSG_HMI_FIREMODE


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
#define TTYPENAME   DMSG_HMI_FIREMODETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_FIREMODEDataReader
#define TDataSeq    DMSG_HMI_FIREMODESeq
#define TData       DMSG_HMI_FIREMODE


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
#define TTYPENAME    DMSG_HMI_FIREMODETYPENAME
#define TPlugin_new  DMSG_HMI_FIREMODEPlugin_new
#define TPlugin_delete  DMSG_HMI_FIREMODEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_FIREMODETypeSupport
#define TData        DMSG_HMI_FIREMODE
#define TDataReader  DMSG_HMI_FIREMODEDataReader
#define TDataWriter  DMSG_HMI_FIREMODEDataWriter
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

   Configure and implement 'DMSG_HMI_ASSIGNSLTSTUBE' support classes.

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
#define TTYPENAME   DMSG_HMI_ASSIGNSLTSTUBETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_ASSIGNSLTSTUBEDataWriter
#define TData       DMSG_HMI_ASSIGNSLTSTUBE


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
#define TTYPENAME   DMSG_HMI_ASSIGNSLTSTUBETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_ASSIGNSLTSTUBEDataReader
#define TDataSeq    DMSG_HMI_ASSIGNSLTSTUBESeq
#define TData       DMSG_HMI_ASSIGNSLTSTUBE


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
#define TTYPENAME    DMSG_HMI_ASSIGNSLTSTUBETYPENAME
#define TPlugin_new  DMSG_HMI_ASSIGNSLTSTUBEPlugin_new
#define TPlugin_delete  DMSG_HMI_ASSIGNSLTSTUBEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_ASSIGNSLTSTUBETypeSupport
#define TData        DMSG_HMI_ASSIGNSLTSTUBE
#define TDataReader  DMSG_HMI_ASSIGNSLTSTUBEDataReader
#define TDataWriter  DMSG_HMI_ASSIGNSLTSTUBEDataWriter
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

   Configure and implement 'DMSG_TEWA_ENGAGEADVICEDEL' support classes.

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
#define TTYPENAME   DMSG_TEWA_ENGAGEADVICEDELTYPENAME

/* Defines */
#define TDataWriter DMSG_TEWA_ENGAGEADVICEDELDataWriter
#define TData       DMSG_TEWA_ENGAGEADVICEDEL


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
#define TTYPENAME   DMSG_TEWA_ENGAGEADVICEDELTYPENAME

/* Defines */
#define TDataReader DMSG_TEWA_ENGAGEADVICEDELDataReader
#define TDataSeq    DMSG_TEWA_ENGAGEADVICEDELSeq
#define TData       DMSG_TEWA_ENGAGEADVICEDEL


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
#define TTYPENAME    DMSG_TEWA_ENGAGEADVICEDELTYPENAME
#define TPlugin_new  DMSG_TEWA_ENGAGEADVICEDELPlugin_new
#define TPlugin_delete  DMSG_TEWA_ENGAGEADVICEDELPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TEWA_ENGAGEADVICEDELTypeSupport
#define TData        DMSG_TEWA_ENGAGEADVICEDEL
#define TDataReader  DMSG_TEWA_ENGAGEADVICEDELDataReader
#define TDataWriter  DMSG_TEWA_ENGAGEADVICEDELDataWriter
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

   Configure and implement 'DMSG_TEWA_FASTRESPONSECHANNEL' support classes.

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
#define TTYPENAME   DMSG_TEWA_FASTRESPONSECHANNELTYPENAME

/* Defines */
#define TDataWriter DMSG_TEWA_FASTRESPONSECHANNELDataWriter
#define TData       DMSG_TEWA_FASTRESPONSECHANNEL


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
#define TTYPENAME   DMSG_TEWA_FASTRESPONSECHANNELTYPENAME

/* Defines */
#define TDataReader DMSG_TEWA_FASTRESPONSECHANNELDataReader
#define TDataSeq    DMSG_TEWA_FASTRESPONSECHANNELSeq
#define TData       DMSG_TEWA_FASTRESPONSECHANNEL


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
#define TTYPENAME    DMSG_TEWA_FASTRESPONSECHANNELTYPENAME
#define TPlugin_new  DMSG_TEWA_FASTRESPONSECHANNELPlugin_new
#define TPlugin_delete  DMSG_TEWA_FASTRESPONSECHANNELPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TEWA_FASTRESPONSECHANNELTypeSupport
#define TData        DMSG_TEWA_FASTRESPONSECHANNEL
#define TDataReader  DMSG_TEWA_FASTRESPONSECHANNELDataReader
#define TDataWriter  DMSG_TEWA_FASTRESPONSECHANNELDataWriter
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

   Configure and implement 'DMSG_TEWA_ENGAGEADVICE' support classes.

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
#define TTYPENAME   DMSG_TEWA_ENGAGEADVICETYPENAME

/* Defines */
#define TDataWriter DMSG_TEWA_ENGAGEADVICEDataWriter
#define TData       DMSG_TEWA_ENGAGEADVICE


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
#define TTYPENAME   DMSG_TEWA_ENGAGEADVICETYPENAME

/* Defines */
#define TDataReader DMSG_TEWA_ENGAGEADVICEDataReader
#define TDataSeq    DMSG_TEWA_ENGAGEADVICESeq
#define TData       DMSG_TEWA_ENGAGEADVICE


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
#define TTYPENAME    DMSG_TEWA_ENGAGEADVICETYPENAME
#define TPlugin_new  DMSG_TEWA_ENGAGEADVICEPlugin_new
#define TPlugin_delete  DMSG_TEWA_ENGAGEADVICEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TEWA_ENGAGEADVICETypeSupport
#define TData        DMSG_TEWA_ENGAGEADVICE
#define TDataReader  DMSG_TEWA_ENGAGEADVICEDataReader
#define TDataWriter  DMSG_TEWA_ENGAGEADVICEDataWriter
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

   Configure and implement 'DMSG_TEWA_THREATDEL' support classes.

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
#define TTYPENAME   DMSG_TEWA_THREATDELTYPENAME

/* Defines */
#define TDataWriter DMSG_TEWA_THREATDELDataWriter
#define TData       DMSG_TEWA_THREATDEL


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
#define TTYPENAME   DMSG_TEWA_THREATDELTYPENAME

/* Defines */
#define TDataReader DMSG_TEWA_THREATDELDataReader
#define TDataSeq    DMSG_TEWA_THREATDELSeq
#define TData       DMSG_TEWA_THREATDEL


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
#define TTYPENAME    DMSG_TEWA_THREATDELTYPENAME
#define TPlugin_new  DMSG_TEWA_THREATDELPlugin_new
#define TPlugin_delete  DMSG_TEWA_THREATDELPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TEWA_THREATDELTypeSupport
#define TData        DMSG_TEWA_THREATDEL
#define TDataReader  DMSG_TEWA_THREATDELDataReader
#define TDataWriter  DMSG_TEWA_THREATDELDataWriter
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

   Configure and implement 'DMSG_TEWA_AIRTHREATEVALUATION' support classes.

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
#define TTYPENAME   DMSG_TEWA_AIRTHREATEVALUATIONTYPENAME

/* Defines */
#define TDataWriter DMSG_TEWA_AIRTHREATEVALUATIONDataWriter
#define TData       DMSG_TEWA_AIRTHREATEVALUATION


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
#define TTYPENAME   DMSG_TEWA_AIRTHREATEVALUATIONTYPENAME

/* Defines */
#define TDataReader DMSG_TEWA_AIRTHREATEVALUATIONDataReader
#define TDataSeq    DMSG_TEWA_AIRTHREATEVALUATIONSeq
#define TData       DMSG_TEWA_AIRTHREATEVALUATION


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
#define TTYPENAME    DMSG_TEWA_AIRTHREATEVALUATIONTYPENAME
#define TPlugin_new  DMSG_TEWA_AIRTHREATEVALUATIONPlugin_new
#define TPlugin_delete  DMSG_TEWA_AIRTHREATEVALUATIONPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TEWA_AIRTHREATEVALUATIONTypeSupport
#define TData        DMSG_TEWA_AIRTHREATEVALUATION
#define TDataReader  DMSG_TEWA_AIRTHREATEVALUATIONDataReader
#define TDataWriter  DMSG_TEWA_AIRTHREATEVALUATIONDataWriter
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

   Configure and implement 'DMSG_TEWA_SHIPTHREATEVALUATION' support classes.

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
#define TTYPENAME   DMSG_TEWA_SHIPTHREATEVALUATIONTYPENAME

/* Defines */
#define TDataWriter DMSG_TEWA_SHIPTHREATEVALUATIONDataWriter
#define TData       DMSG_TEWA_SHIPTHREATEVALUATION


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
#define TTYPENAME   DMSG_TEWA_SHIPTHREATEVALUATIONTYPENAME

/* Defines */
#define TDataReader DMSG_TEWA_SHIPTHREATEVALUATIONDataReader
#define TDataSeq    DMSG_TEWA_SHIPTHREATEVALUATIONSeq
#define TData       DMSG_TEWA_SHIPTHREATEVALUATION


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
#define TTYPENAME    DMSG_TEWA_SHIPTHREATEVALUATIONTYPENAME
#define TPlugin_new  DMSG_TEWA_SHIPTHREATEVALUATIONPlugin_new
#define TPlugin_delete  DMSG_TEWA_SHIPTHREATEVALUATIONPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TEWA_SHIPTHREATEVALUATIONTypeSupport
#define TData        DMSG_TEWA_SHIPTHREATEVALUATION
#define TDataReader  DMSG_TEWA_SHIPTHREATEVALUATIONDataReader
#define TDataWriter  DMSG_TEWA_SHIPTHREATEVALUATIONDataWriter
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

   Configure and implement 'DMSG_TEWA_SUBTHREATEVALUATION' support classes.

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
#define TTYPENAME   DMSG_TEWA_SUBTHREATEVALUATIONTYPENAME

/* Defines */
#define TDataWriter DMSG_TEWA_SUBTHREATEVALUATIONDataWriter
#define TData       DMSG_TEWA_SUBTHREATEVALUATION


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
#define TTYPENAME   DMSG_TEWA_SUBTHREATEVALUATIONTYPENAME

/* Defines */
#define TDataReader DMSG_TEWA_SUBTHREATEVALUATIONDataReader
#define TDataSeq    DMSG_TEWA_SUBTHREATEVALUATIONSeq
#define TData       DMSG_TEWA_SUBTHREATEVALUATION


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
#define TTYPENAME    DMSG_TEWA_SUBTHREATEVALUATIONTYPENAME
#define TPlugin_new  DMSG_TEWA_SUBTHREATEVALUATIONPlugin_new
#define TPlugin_delete  DMSG_TEWA_SUBTHREATEVALUATIONPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TEWA_SUBTHREATEVALUATIONTypeSupport
#define TData        DMSG_TEWA_SUBTHREATEVALUATION
#define TDataReader  DMSG_TEWA_SUBTHREATEVALUATIONDataReader
#define TDataWriter  DMSG_TEWA_SUBTHREATEVALUATIONDataWriter
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

   Configure and implement 'DMSG_TEWA_ENGAGEPOSSIBILITY' support classes.

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
#define TTYPENAME   DMSG_TEWA_ENGAGEPOSSIBILITYTYPENAME

/* Defines */
#define TDataWriter DMSG_TEWA_ENGAGEPOSSIBILITYDataWriter
#define TData       DMSG_TEWA_ENGAGEPOSSIBILITY


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
#define TTYPENAME   DMSG_TEWA_ENGAGEPOSSIBILITYTYPENAME

/* Defines */
#define TDataReader DMSG_TEWA_ENGAGEPOSSIBILITYDataReader
#define TDataSeq    DMSG_TEWA_ENGAGEPOSSIBILITYSeq
#define TData       DMSG_TEWA_ENGAGEPOSSIBILITY


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
#define TTYPENAME    DMSG_TEWA_ENGAGEPOSSIBILITYTYPENAME
#define TPlugin_new  DMSG_TEWA_ENGAGEPOSSIBILITYPlugin_new
#define TPlugin_delete  DMSG_TEWA_ENGAGEPOSSIBILITYPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TEWA_ENGAGEPOSSIBILITYTypeSupport
#define TData        DMSG_TEWA_ENGAGEPOSSIBILITY
#define TDataReader  DMSG_TEWA_ENGAGEPOSSIBILITYDataReader
#define TDataWriter  DMSG_TEWA_ENGAGEPOSSIBILITYDataWriter
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

   Configure and implement 'DMSG_TEWA_SWSTATE' support classes.

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
#define TTYPENAME   DMSG_TEWA_SWSTATETYPENAME

/* Defines */
#define TDataWriter DMSG_TEWA_SWSTATEDataWriter
#define TData       DMSG_TEWA_SWSTATE


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
#define TTYPENAME   DMSG_TEWA_SWSTATETYPENAME

/* Defines */
#define TDataReader DMSG_TEWA_SWSTATEDataReader
#define TDataSeq    DMSG_TEWA_SWSTATESeq
#define TData       DMSG_TEWA_SWSTATE


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
#define TTYPENAME    DMSG_TEWA_SWSTATETYPENAME
#define TPlugin_new  DMSG_TEWA_SWSTATEPlugin_new
#define TPlugin_delete  DMSG_TEWA_SWSTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TEWA_SWSTATETypeSupport
#define TData        DMSG_TEWA_SWSTATE
#define TDataReader  DMSG_TEWA_SWSTATEDataReader
#define TDataWriter  DMSG_TEWA_SWSTATEDataWriter
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

   Configure and implement 'DMSG_TEWA_TORPEDOALERT' support classes.

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
#define TTYPENAME   DMSG_TEWA_TORPEDOALERTTYPENAME

/* Defines */
#define TDataWriter DMSG_TEWA_TORPEDOALERTDataWriter
#define TData       DMSG_TEWA_TORPEDOALERT


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
#define TTYPENAME   DMSG_TEWA_TORPEDOALERTTYPENAME

/* Defines */
#define TDataReader DMSG_TEWA_TORPEDOALERTDataReader
#define TDataSeq    DMSG_TEWA_TORPEDOALERTSeq
#define TData       DMSG_TEWA_TORPEDOALERT


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
#define TTYPENAME    DMSG_TEWA_TORPEDOALERTTYPENAME
#define TPlugin_new  DMSG_TEWA_TORPEDOALERTPlugin_new
#define TPlugin_delete  DMSG_TEWA_TORPEDOALERTPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TEWA_TORPEDOALERTTypeSupport
#define TData        DMSG_TEWA_TORPEDOALERT
#define TDataReader  DMSG_TEWA_TORPEDOALERTDataReader
#define TDataWriter  DMSG_TEWA_TORPEDOALERTDataWriter
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

   Configure and implement 'DMSG_TEWA_DIRECTENGAGEADVICE' support classes.

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
#define TTYPENAME   DMSG_TEWA_DIRECTENGAGEADVICETYPENAME

/* Defines */
#define TDataWriter DMSG_TEWA_DIRECTENGAGEADVICEDataWriter
#define TData       DMSG_TEWA_DIRECTENGAGEADVICE


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
#define TTYPENAME   DMSG_TEWA_DIRECTENGAGEADVICETYPENAME

/* Defines */
#define TDataReader DMSG_TEWA_DIRECTENGAGEADVICEDataReader
#define TDataSeq    DMSG_TEWA_DIRECTENGAGEADVICESeq
#define TData       DMSG_TEWA_DIRECTENGAGEADVICE


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
#define TTYPENAME    DMSG_TEWA_DIRECTENGAGEADVICETYPENAME
#define TPlugin_new  DMSG_TEWA_DIRECTENGAGEADVICEPlugin_new
#define TPlugin_delete  DMSG_TEWA_DIRECTENGAGEADVICEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TEWA_DIRECTENGAGEADVICETypeSupport
#define TData        DMSG_TEWA_DIRECTENGAGEADVICE
#define TDataReader  DMSG_TEWA_DIRECTENGAGEADVICEDataReader
#define TDataWriter  DMSG_TEWA_DIRECTENGAGEADVICEDataWriter
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

   Configure and implement 'DMSG_TEWA_SENSORWEAPONREQ' support classes.

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
#define TTYPENAME   DMSG_TEWA_SENSORWEAPONREQTYPENAME

/* Defines */
#define TDataWriter DMSG_TEWA_SENSORWEAPONREQDataWriter
#define TData       DMSG_TEWA_SENSORWEAPONREQ


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
#define TTYPENAME   DMSG_TEWA_SENSORWEAPONREQTYPENAME

/* Defines */
#define TDataReader DMSG_TEWA_SENSORWEAPONREQDataReader
#define TDataSeq    DMSG_TEWA_SENSORWEAPONREQSeq
#define TData       DMSG_TEWA_SENSORWEAPONREQ


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
#define TTYPENAME    DMSG_TEWA_SENSORWEAPONREQTYPENAME
#define TPlugin_new  DMSG_TEWA_SENSORWEAPONREQPlugin_new
#define TPlugin_delete  DMSG_TEWA_SENSORWEAPONREQPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TEWA_SENSORWEAPONREQTypeSupport
#define TData        DMSG_TEWA_SENSORWEAPONREQ
#define TDataReader  DMSG_TEWA_SENSORWEAPONREQDataReader
#define TDataWriter  DMSG_TEWA_SENSORWEAPONREQDataWriter
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

   Configure and implement 'DMSG_EC_HITEVALUATIONSRESULT' support classes.

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
#define TTYPENAME   DMSG_EC_HITEVALUATIONSRESULTTYPENAME

/* Defines */
#define TDataWriter DMSG_EC_HITEVALUATIONSRESULTDataWriter
#define TData       DMSG_EC_HITEVALUATIONSRESULT


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
#define TTYPENAME   DMSG_EC_HITEVALUATIONSRESULTTYPENAME

/* Defines */
#define TDataReader DMSG_EC_HITEVALUATIONSRESULTDataReader
#define TDataSeq    DMSG_EC_HITEVALUATIONSRESULTSeq
#define TData       DMSG_EC_HITEVALUATIONSRESULT


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
#define TTYPENAME    DMSG_EC_HITEVALUATIONSRESULTTYPENAME
#define TPlugin_new  DMSG_EC_HITEVALUATIONSRESULTPlugin_new
#define TPlugin_delete  DMSG_EC_HITEVALUATIONSRESULTPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_HITEVALUATIONSRESULTTypeSupport
#define TData        DMSG_EC_HITEVALUATIONSRESULT
#define TDataReader  DMSG_EC_HITEVALUATIONSRESULTDataReader
#define TDataWriter  DMSG_EC_HITEVALUATIONSRESULTDataWriter
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

   Configure and implement 'DMSG_EC_ENGAGEINFO' support classes.

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
#define TTYPENAME   DMSG_EC_ENGAGEINFOTYPENAME

/* Defines */
#define TDataWriter DMSG_EC_ENGAGEINFODataWriter
#define TData       DMSG_EC_ENGAGEINFO


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
#define TTYPENAME   DMSG_EC_ENGAGEINFOTYPENAME

/* Defines */
#define TDataReader DMSG_EC_ENGAGEINFODataReader
#define TDataSeq    DMSG_EC_ENGAGEINFOSeq
#define TData       DMSG_EC_ENGAGEINFO


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
#define TTYPENAME    DMSG_EC_ENGAGEINFOTYPENAME
#define TPlugin_new  DMSG_EC_ENGAGEINFOPlugin_new
#define TPlugin_delete  DMSG_EC_ENGAGEINFOPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_ENGAGEINFOTypeSupport
#define TData        DMSG_EC_ENGAGEINFO
#define TDataReader  DMSG_EC_ENGAGEINFODataReader
#define TDataWriter  DMSG_EC_ENGAGEINFODataWriter
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

   Configure and implement 'DMSG_EC_ENGAGEASSIGN' support classes.

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
#define TTYPENAME   DMSG_EC_ENGAGEASSIGNTYPENAME

/* Defines */
#define TDataWriter DMSG_EC_ENGAGEASSIGNDataWriter
#define TData       DMSG_EC_ENGAGEASSIGN


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
#define TTYPENAME   DMSG_EC_ENGAGEASSIGNTYPENAME

/* Defines */
#define TDataReader DMSG_EC_ENGAGEASSIGNDataReader
#define TDataSeq    DMSG_EC_ENGAGEASSIGNSeq
#define TData       DMSG_EC_ENGAGEASSIGN


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
#define TTYPENAME    DMSG_EC_ENGAGEASSIGNTYPENAME
#define TPlugin_new  DMSG_EC_ENGAGEASSIGNPlugin_new
#define TPlugin_delete  DMSG_EC_ENGAGEASSIGNPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_ENGAGEASSIGNTypeSupport
#define TData        DMSG_EC_ENGAGEASSIGN
#define TDataReader  DMSG_EC_ENGAGEASSIGNDataReader
#define TDataWriter  DMSG_EC_ENGAGEASSIGNDataWriter
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

   Configure and implement 'DMSG_EC_ENGAGEPLANSET' support classes.

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
#define TTYPENAME   DMSG_EC_ENGAGEPLANSETTYPENAME

/* Defines */
#define TDataWriter DMSG_EC_ENGAGEPLANSETDataWriter
#define TData       DMSG_EC_ENGAGEPLANSET


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
#define TTYPENAME   DMSG_EC_ENGAGEPLANSETTYPENAME

/* Defines */
#define TDataReader DMSG_EC_ENGAGEPLANSETDataReader
#define TDataSeq    DMSG_EC_ENGAGEPLANSETSeq
#define TData       DMSG_EC_ENGAGEPLANSET


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
#define TTYPENAME    DMSG_EC_ENGAGEPLANSETTYPENAME
#define TPlugin_new  DMSG_EC_ENGAGEPLANSETPlugin_new
#define TPlugin_delete  DMSG_EC_ENGAGEPLANSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_ENGAGEPLANSETTypeSupport
#define TData        DMSG_EC_ENGAGEPLANSET
#define TDataReader  DMSG_EC_ENGAGEPLANSETDataReader
#define TDataWriter  DMSG_EC_ENGAGEPLANSETDataWriter
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

   Configure and implement 'DMSG_EC_FIREPERMITKEYSTATE' support classes.

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
#define TTYPENAME   DMSG_EC_FIREPERMITKEYSTATETYPENAME

/* Defines */
#define TDataWriter DMSG_EC_FIREPERMITKEYSTATEDataWriter
#define TData       DMSG_EC_FIREPERMITKEYSTATE


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
#define TTYPENAME   DMSG_EC_FIREPERMITKEYSTATETYPENAME

/* Defines */
#define TDataReader DMSG_EC_FIREPERMITKEYSTATEDataReader
#define TDataSeq    DMSG_EC_FIREPERMITKEYSTATESeq
#define TData       DMSG_EC_FIREPERMITKEYSTATE


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
#define TTYPENAME    DMSG_EC_FIREPERMITKEYSTATETYPENAME
#define TPlugin_new  DMSG_EC_FIREPERMITKEYSTATEPlugin_new
#define TPlugin_delete  DMSG_EC_FIREPERMITKEYSTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_FIREPERMITKEYSTATETypeSupport
#define TData        DMSG_EC_FIREPERMITKEYSTATE
#define TDataReader  DMSG_EC_FIREPERMITKEYSTATEDataReader
#define TDataWriter  DMSG_EC_FIREPERMITKEYSTATEDataWriter
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

   Configure and implement 'DMSG_EC_ENGAGESTATE' support classes.

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
#define TTYPENAME   DMSG_EC_ENGAGESTATETYPENAME

/* Defines */
#define TDataWriter DMSG_EC_ENGAGESTATEDataWriter
#define TData       DMSG_EC_ENGAGESTATE


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
#define TTYPENAME   DMSG_EC_ENGAGESTATETYPENAME

/* Defines */
#define TDataReader DMSG_EC_ENGAGESTATEDataReader
#define TDataSeq    DMSG_EC_ENGAGESTATESeq
#define TData       DMSG_EC_ENGAGESTATE


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
#define TTYPENAME    DMSG_EC_ENGAGESTATETYPENAME
#define TPlugin_new  DMSG_EC_ENGAGESTATEPlugin_new
#define TPlugin_delete  DMSG_EC_ENGAGESTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_ENGAGESTATETypeSupport
#define TData        DMSG_EC_ENGAGESTATE
#define TDataReader  DMSG_EC_ENGAGESTATEDataReader
#define TDataWriter  DMSG_EC_ENGAGESTATEDataWriter
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

   Configure and implement 'DMSG_EC_SWSTATE' support classes.

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
#define TTYPENAME   DMSG_EC_SWSTATETYPENAME

/* Defines */
#define TDataWriter DMSG_EC_SWSTATEDataWriter
#define TData       DMSG_EC_SWSTATE


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
#define TTYPENAME   DMSG_EC_SWSTATETYPENAME

/* Defines */
#define TDataReader DMSG_EC_SWSTATEDataReader
#define TDataSeq    DMSG_EC_SWSTATESeq
#define TData       DMSG_EC_SWSTATE


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
#define TTYPENAME    DMSG_EC_SWSTATETYPENAME
#define TPlugin_new  DMSG_EC_SWSTATEPlugin_new
#define TPlugin_delete  DMSG_EC_SWSTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_SWSTATETypeSupport
#define TData        DMSG_EC_SWSTATE
#define TDataReader  DMSG_EC_SWSTATEDataReader
#define TDataWriter  DMSG_EC_SWSTATEDataWriter
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

   Configure and implement 'DMSG_EC_WEAPONCTRLMODE' support classes.

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
#define TTYPENAME   DMSG_EC_WEAPONCTRLMODETYPENAME

/* Defines */
#define TDataWriter DMSG_EC_WEAPONCTRLMODEDataWriter
#define TData       DMSG_EC_WEAPONCTRLMODE


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
#define TTYPENAME   DMSG_EC_WEAPONCTRLMODETYPENAME

/* Defines */
#define TDataReader DMSG_EC_WEAPONCTRLMODEDataReader
#define TDataSeq    DMSG_EC_WEAPONCTRLMODESeq
#define TData       DMSG_EC_WEAPONCTRLMODE


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
#define TTYPENAME    DMSG_EC_WEAPONCTRLMODETYPENAME
#define TPlugin_new  DMSG_EC_WEAPONCTRLMODEPlugin_new
#define TPlugin_delete  DMSG_EC_WEAPONCTRLMODEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_WEAPONCTRLMODETypeSupport
#define TData        DMSG_EC_WEAPONCTRLMODE
#define TDataReader  DMSG_EC_WEAPONCTRLMODEDataReader
#define TDataWriter  DMSG_EC_WEAPONCTRLMODEDataWriter
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

   Configure and implement 'DMSG_EC_HORTUBEASSIGN' support classes.

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
#define TTYPENAME   DMSG_EC_HORTUBEASSIGNTYPENAME

/* Defines */
#define TDataWriter DMSG_EC_HORTUBEASSIGNDataWriter
#define TData       DMSG_EC_HORTUBEASSIGN


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
#define TTYPENAME   DMSG_EC_HORTUBEASSIGNTYPENAME

/* Defines */
#define TDataReader DMSG_EC_HORTUBEASSIGNDataReader
#define TDataSeq    DMSG_EC_HORTUBEASSIGNSeq
#define TData       DMSG_EC_HORTUBEASSIGN


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
#define TTYPENAME    DMSG_EC_HORTUBEASSIGNTYPENAME
#define TPlugin_new  DMSG_EC_HORTUBEASSIGNPlugin_new
#define TPlugin_delete  DMSG_EC_HORTUBEASSIGNPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_HORTUBEASSIGNTypeSupport
#define TData        DMSG_EC_HORTUBEASSIGN
#define TDataReader  DMSG_EC_HORTUBEASSIGNDataReader
#define TDataWriter  DMSG_EC_HORTUBEASSIGNDataWriter
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

   Configure and implement 'DMSG_EC_VERTUBEASSIGN' support classes.

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
#define TTYPENAME   DMSG_EC_VERTUBEASSIGNTYPENAME

/* Defines */
#define TDataWriter DMSG_EC_VERTUBEASSIGNDataWriter
#define TData       DMSG_EC_VERTUBEASSIGN


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
#define TTYPENAME   DMSG_EC_VERTUBEASSIGNTYPENAME

/* Defines */
#define TDataReader DMSG_EC_VERTUBEASSIGNDataReader
#define TDataSeq    DMSG_EC_VERTUBEASSIGNSeq
#define TData       DMSG_EC_VERTUBEASSIGN


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
#define TTYPENAME    DMSG_EC_VERTUBEASSIGNTYPENAME
#define TPlugin_new  DMSG_EC_VERTUBEASSIGNPlugin_new
#define TPlugin_delete  DMSG_EC_VERTUBEASSIGNPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_VERTUBEASSIGNTypeSupport
#define TData        DMSG_EC_VERTUBEASSIGN
#define TDataReader  DMSG_EC_VERTUBEASSIGNDataReader
#define TDataWriter  DMSG_EC_VERTUBEASSIGNDataWriter
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

   Configure and implement 'DMSG_EC_WEAPONFIRESTATE' support classes.

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
#define TTYPENAME   DMSG_EC_WEAPONFIRESTATETYPENAME

/* Defines */
#define TDataWriter DMSG_EC_WEAPONFIRESTATEDataWriter
#define TData       DMSG_EC_WEAPONFIRESTATE


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
#define TTYPENAME   DMSG_EC_WEAPONFIRESTATETYPENAME

/* Defines */
#define TDataReader DMSG_EC_WEAPONFIRESTATEDataReader
#define TDataSeq    DMSG_EC_WEAPONFIRESTATESeq
#define TData       DMSG_EC_WEAPONFIRESTATE


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
#define TTYPENAME    DMSG_EC_WEAPONFIRESTATETYPENAME
#define TPlugin_new  DMSG_EC_WEAPONFIRESTATEPlugin_new
#define TPlugin_delete  DMSG_EC_WEAPONFIRESTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_WEAPONFIRESTATETypeSupport
#define TData        DMSG_EC_WEAPONFIRESTATE
#define TDataReader  DMSG_EC_WEAPONFIRESTATEDataReader
#define TDataWriter  DMSG_EC_WEAPONFIRESTATEDataWriter
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

   Configure and implement 'DMSG_EC_FIRECMD' support classes.

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
#define TTYPENAME   DMSG_EC_FIRECMDTYPENAME

/* Defines */
#define TDataWriter DMSG_EC_FIRECMDDataWriter
#define TData       DMSG_EC_FIRECMD


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
#define TTYPENAME   DMSG_EC_FIRECMDTYPENAME

/* Defines */
#define TDataReader DMSG_EC_FIRECMDDataReader
#define TDataSeq    DMSG_EC_FIRECMDSeq
#define TData       DMSG_EC_FIRECMD


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
#define TTYPENAME    DMSG_EC_FIRECMDTYPENAME
#define TPlugin_new  DMSG_EC_FIRECMDPlugin_new
#define TPlugin_delete  DMSG_EC_FIRECMDPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_FIRECMDTypeSupport
#define TData        DMSG_EC_FIRECMD
#define TDataReader  DMSG_EC_FIRECMDDataReader
#define TDataWriter  DMSG_EC_FIRECMDDataWriter
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

   Configure and implement 'DMSG_HMI_TACTICORDER' support classes.

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
#define TTYPENAME   DMSG_HMI_TACTICORDERTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TACTICORDERDataWriter
#define TData       DMSG_HMI_TACTICORDER


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
#define TTYPENAME   DMSG_HMI_TACTICORDERTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TACTICORDERDataReader
#define TDataSeq    DMSG_HMI_TACTICORDERSeq
#define TData       DMSG_HMI_TACTICORDER


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
#define TTYPENAME    DMSG_HMI_TACTICORDERTYPENAME
#define TPlugin_new  DMSG_HMI_TACTICORDERPlugin_new
#define TPlugin_delete  DMSG_HMI_TACTICORDERPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TACTICORDERTypeSupport
#define TData        DMSG_HMI_TACTICORDER
#define TDataReader  DMSG_HMI_TACTICORDERDataReader
#define TDataWriter  DMSG_HMI_TACTICORDERDataWriter
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

   Configure and implement 'DMSG_HMI_DCOYLAUNCHMODE' support classes.

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
#define TTYPENAME   DMSG_HMI_DCOYLAUNCHMODETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_DCOYLAUNCHMODEDataWriter
#define TData       DMSG_HMI_DCOYLAUNCHMODE


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
#define TTYPENAME   DMSG_HMI_DCOYLAUNCHMODETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_DCOYLAUNCHMODEDataReader
#define TDataSeq    DMSG_HMI_DCOYLAUNCHMODESeq
#define TData       DMSG_HMI_DCOYLAUNCHMODE


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
#define TTYPENAME    DMSG_HMI_DCOYLAUNCHMODETYPENAME
#define TPlugin_new  DMSG_HMI_DCOYLAUNCHMODEPlugin_new
#define TPlugin_delete  DMSG_HMI_DCOYLAUNCHMODEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_DCOYLAUNCHMODETypeSupport
#define TData        DMSG_HMI_DCOYLAUNCHMODE
#define TDataReader  DMSG_HMI_DCOYLAUNCHMODEDataReader
#define TDataWriter  DMSG_HMI_DCOYLAUNCHMODEDataWriter
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

   Configure and implement 'DMSG_HMI_DCOYTUBESET' support classes.

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
#define TTYPENAME   DMSG_HMI_DCOYTUBESETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_DCOYTUBESETDataWriter
#define TData       DMSG_HMI_DCOYTUBESET


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
#define TTYPENAME   DMSG_HMI_DCOYTUBESETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_DCOYTUBESETDataReader
#define TDataSeq    DMSG_HMI_DCOYTUBESETSeq
#define TData       DMSG_HMI_DCOYTUBESET


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
#define TTYPENAME    DMSG_HMI_DCOYTUBESETTYPENAME
#define TPlugin_new  DMSG_HMI_DCOYTUBESETPlugin_new
#define TPlugin_delete  DMSG_HMI_DCOYTUBESETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_DCOYTUBESETTypeSupport
#define TData        DMSG_HMI_DCOYTUBESET
#define TDataReader  DMSG_HMI_DCOYTUBESETDataReader
#define TDataWriter  DMSG_HMI_DCOYTUBESETDataWriter
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

   Configure and implement 'DMSG_HMI_MISSILECTRL' support classes.

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
#define TTYPENAME   DMSG_HMI_MISSILECTRLTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_MISSILECTRLDataWriter
#define TData       DMSG_HMI_MISSILECTRL


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
#define TTYPENAME   DMSG_HMI_MISSILECTRLTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_MISSILECTRLDataReader
#define TDataSeq    DMSG_HMI_MISSILECTRLSeq
#define TData       DMSG_HMI_MISSILECTRL


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
#define TTYPENAME    DMSG_HMI_MISSILECTRLTYPENAME
#define TPlugin_new  DMSG_HMI_MISSILECTRLPlugin_new
#define TPlugin_delete  DMSG_HMI_MISSILECTRLPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_MISSILECTRLTypeSupport
#define TData        DMSG_HMI_MISSILECTRL
#define TDataReader  DMSG_HMI_MISSILECTRLDataReader
#define TDataWriter  DMSG_HMI_MISSILECTRLDataWriter
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

   Configure and implement 'DMSG_HMI_MISSILEENGAGEPLAN' support classes.

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
#define TTYPENAME   DMSG_HMI_MISSILEENGAGEPLANTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_MISSILEENGAGEPLANDataWriter
#define TData       DMSG_HMI_MISSILEENGAGEPLAN


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
#define TTYPENAME   DMSG_HMI_MISSILEENGAGEPLANTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_MISSILEENGAGEPLANDataReader
#define TDataSeq    DMSG_HMI_MISSILEENGAGEPLANSeq
#define TData       DMSG_HMI_MISSILEENGAGEPLAN


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
#define TTYPENAME    DMSG_HMI_MISSILEENGAGEPLANTYPENAME
#define TPlugin_new  DMSG_HMI_MISSILEENGAGEPLANPlugin_new
#define TPlugin_delete  DMSG_HMI_MISSILEENGAGEPLANPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_MISSILEENGAGEPLANTypeSupport
#define TData        DMSG_HMI_MISSILEENGAGEPLAN
#define TDataReader  DMSG_HMI_MISSILEENGAGEPLANDataReader
#define TDataWriter  DMSG_HMI_MISSILEENGAGEPLANDataWriter
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

   Configure and implement 'DMSG_HMI_TORPEDOENGAGEPLAN' support classes.

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
#define TTYPENAME   DMSG_HMI_TORPEDOENGAGEPLANTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TORPEDOENGAGEPLANDataWriter
#define TData       DMSG_HMI_TORPEDOENGAGEPLAN


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
#define TTYPENAME   DMSG_HMI_TORPEDOENGAGEPLANTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TORPEDOENGAGEPLANDataReader
#define TDataSeq    DMSG_HMI_TORPEDOENGAGEPLANSeq
#define TData       DMSG_HMI_TORPEDOENGAGEPLAN


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
#define TTYPENAME    DMSG_HMI_TORPEDOENGAGEPLANTYPENAME
#define TPlugin_new  DMSG_HMI_TORPEDOENGAGEPLANPlugin_new
#define TPlugin_delete  DMSG_HMI_TORPEDOENGAGEPLANPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TORPEDOENGAGEPLANTypeSupport
#define TData        DMSG_HMI_TORPEDOENGAGEPLAN
#define TDataReader  DMSG_HMI_TORPEDOENGAGEPLANDataReader
#define TDataWriter  DMSG_HMI_TORPEDOENGAGEPLANDataWriter
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

   Configure and implement 'DMSG_HMI_RESERVEDENGAGEPLAN' support classes.

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
#define TTYPENAME   DMSG_HMI_RESERVEDENGAGEPLANTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_RESERVEDENGAGEPLANDataWriter
#define TData       DMSG_HMI_RESERVEDENGAGEPLAN


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
#define TTYPENAME   DMSG_HMI_RESERVEDENGAGEPLANTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_RESERVEDENGAGEPLANDataReader
#define TDataSeq    DMSG_HMI_RESERVEDENGAGEPLANSeq
#define TData       DMSG_HMI_RESERVEDENGAGEPLAN


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
#define TTYPENAME    DMSG_HMI_RESERVEDENGAGEPLANTYPENAME
#define TPlugin_new  DMSG_HMI_RESERVEDENGAGEPLANPlugin_new
#define TPlugin_delete  DMSG_HMI_RESERVEDENGAGEPLANPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_RESERVEDENGAGEPLANTypeSupport
#define TData        DMSG_HMI_RESERVEDENGAGEPLAN
#define TDataReader  DMSG_HMI_RESERVEDENGAGEPLANDataReader
#define TDataWriter  DMSG_HMI_RESERVEDENGAGEPLANDataWriter
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

   Configure and implement 'DMSG_HMI_TORPCTRL' support classes.

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
#define TTYPENAME   DMSG_HMI_TORPCTRLTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TORPCTRLDataWriter
#define TData       DMSG_HMI_TORPCTRL


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
#define TTYPENAME   DMSG_HMI_TORPCTRLTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TORPCTRLDataReader
#define TDataSeq    DMSG_HMI_TORPCTRLSeq
#define TData       DMSG_HMI_TORPCTRL


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
#define TTYPENAME    DMSG_HMI_TORPCTRLTYPENAME
#define TPlugin_new  DMSG_HMI_TORPCTRLPlugin_new
#define TPlugin_delete  DMSG_HMI_TORPCTRLPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TORPCTRLTypeSupport
#define TData        DMSG_HMI_TORPCTRL
#define TDataReader  DMSG_HMI_TORPCTRLDataReader
#define TDataWriter  DMSG_HMI_TORPCTRLDataWriter
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

   Configure and implement 'DMSG_HMI_SHOOTMODIFY' support classes.

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
#define TTYPENAME   DMSG_HMI_SHOOTMODIFYTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_SHOOTMODIFYDataWriter
#define TData       DMSG_HMI_SHOOTMODIFY


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
#define TTYPENAME   DMSG_HMI_SHOOTMODIFYTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_SHOOTMODIFYDataReader
#define TDataSeq    DMSG_HMI_SHOOTMODIFYSeq
#define TData       DMSG_HMI_SHOOTMODIFY


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
#define TTYPENAME    DMSG_HMI_SHOOTMODIFYTYPENAME
#define TPlugin_new  DMSG_HMI_SHOOTMODIFYPlugin_new
#define TPlugin_delete  DMSG_HMI_SHOOTMODIFYPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_SHOOTMODIFYTypeSupport
#define TData        DMSG_HMI_SHOOTMODIFY
#define TDataReader  DMSG_HMI_SHOOTMODIFYDataReader
#define TDataWriter  DMSG_HMI_SHOOTMODIFYDataWriter
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

   Configure and implement 'DMSG_HMI_CORRECT' support classes.

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
#define TTYPENAME   DMSG_HMI_CORRECTTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_CORRECTDataWriter
#define TData       DMSG_HMI_CORRECT


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
#define TTYPENAME   DMSG_HMI_CORRECTTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_CORRECTDataReader
#define TDataSeq    DMSG_HMI_CORRECTSeq
#define TData       DMSG_HMI_CORRECT


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
#define TTYPENAME    DMSG_HMI_CORRECTTYPENAME
#define TPlugin_new  DMSG_HMI_CORRECTPlugin_new
#define TPlugin_delete  DMSG_HMI_CORRECTPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_CORRECTTypeSupport
#define TData        DMSG_HMI_CORRECT
#define TDataReader  DMSG_HMI_CORRECTDataReader
#define TDataWriter  DMSG_HMI_CORRECTDataWriter
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

   Configure and implement 'DMSG_HMI_SENSORWEAPONPOS' support classes.

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
#define TTYPENAME   DMSG_HMI_SENSORWEAPONPOSTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_SENSORWEAPONPOSDataWriter
#define TData       DMSG_HMI_SENSORWEAPONPOS


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
#define TTYPENAME   DMSG_HMI_SENSORWEAPONPOSTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_SENSORWEAPONPOSDataReader
#define TDataSeq    DMSG_HMI_SENSORWEAPONPOSSeq
#define TData       DMSG_HMI_SENSORWEAPONPOS


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
#define TTYPENAME    DMSG_HMI_SENSORWEAPONPOSTYPENAME
#define TPlugin_new  DMSG_HMI_SENSORWEAPONPOSPlugin_new
#define TPlugin_delete  DMSG_HMI_SENSORWEAPONPOSPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_SENSORWEAPONPOSTypeSupport
#define TData        DMSG_HMI_SENSORWEAPONPOS
#define TDataReader  DMSG_HMI_SENSORWEAPONPOSDataReader
#define TDataWriter  DMSG_HMI_SENSORWEAPONPOSDataWriter
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

   Configure and implement 'DMSG_HMI_BLINDNESSFIRE' support classes.

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
#define TTYPENAME   DMSG_HMI_BLINDNESSFIRETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_BLINDNESSFIREDataWriter
#define TData       DMSG_HMI_BLINDNESSFIRE


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
#define TTYPENAME   DMSG_HMI_BLINDNESSFIRETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_BLINDNESSFIREDataReader
#define TDataSeq    DMSG_HMI_BLINDNESSFIRESeq
#define TData       DMSG_HMI_BLINDNESSFIRE


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
#define TTYPENAME    DMSG_HMI_BLINDNESSFIRETYPENAME
#define TPlugin_new  DMSG_HMI_BLINDNESSFIREPlugin_new
#define TPlugin_delete  DMSG_HMI_BLINDNESSFIREPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_BLINDNESSFIRETypeSupport
#define TData        DMSG_HMI_BLINDNESSFIRE
#define TDataReader  DMSG_HMI_BLINDNESSFIREDataReader
#define TDataWriter  DMSG_HMI_BLINDNESSFIREDataWriter
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

   Configure and implement 'DMSG_HMI_DIRECTFIRE' support classes.

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
#define TTYPENAME   DMSG_HMI_DIRECTFIRETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_DIRECTFIREDataWriter
#define TData       DMSG_HMI_DIRECTFIRE


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
#define TTYPENAME   DMSG_HMI_DIRECTFIRETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_DIRECTFIREDataReader
#define TDataSeq    DMSG_HMI_DIRECTFIRESeq
#define TData       DMSG_HMI_DIRECTFIRE


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
#define TTYPENAME    DMSG_HMI_DIRECTFIRETYPENAME
#define TPlugin_new  DMSG_HMI_DIRECTFIREPlugin_new
#define TPlugin_delete  DMSG_HMI_DIRECTFIREPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_DIRECTFIRETypeSupport
#define TData        DMSG_HMI_DIRECTFIRE
#define TDataReader  DMSG_HMI_DIRECTFIREDataReader
#define TDataWriter  DMSG_HMI_DIRECTFIREDataWriter
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

   Configure and implement 'DMSG_HMI_TORPMANUALWAYPOINT' support classes.

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
#define TTYPENAME   DMSG_HMI_TORPMANUALWAYPOINTTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TORPMANUALWAYPOINTDataWriter
#define TData       DMSG_HMI_TORPMANUALWAYPOINT


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
#define TTYPENAME   DMSG_HMI_TORPMANUALWAYPOINTTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TORPMANUALWAYPOINTDataReader
#define TDataSeq    DMSG_HMI_TORPMANUALWAYPOINTSeq
#define TData       DMSG_HMI_TORPMANUALWAYPOINT


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
#define TTYPENAME    DMSG_HMI_TORPMANUALWAYPOINTTYPENAME
#define TPlugin_new  DMSG_HMI_TORPMANUALWAYPOINTPlugin_new
#define TPlugin_delete  DMSG_HMI_TORPMANUALWAYPOINTPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TORPMANUALWAYPOINTTypeSupport
#define TData        DMSG_HMI_TORPMANUALWAYPOINT
#define TDataReader  DMSG_HMI_TORPMANUALWAYPOINTDataReader
#define TDataWriter  DMSG_HMI_TORPMANUALWAYPOINTDataWriter
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

   Configure and implement 'DMSG_HMI_TORPBREAKENGAGE' support classes.

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
#define TTYPENAME   DMSG_HMI_TORPBREAKENGAGETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TORPBREAKENGAGEDataWriter
#define TData       DMSG_HMI_TORPBREAKENGAGE


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
#define TTYPENAME   DMSG_HMI_TORPBREAKENGAGETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TORPBREAKENGAGEDataReader
#define TDataSeq    DMSG_HMI_TORPBREAKENGAGESeq
#define TData       DMSG_HMI_TORPBREAKENGAGE


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
#define TTYPENAME    DMSG_HMI_TORPBREAKENGAGETYPENAME
#define TPlugin_new  DMSG_HMI_TORPBREAKENGAGEPlugin_new
#define TPlugin_delete  DMSG_HMI_TORPBREAKENGAGEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TORPBREAKENGAGETypeSupport
#define TData        DMSG_HMI_TORPBREAKENGAGE
#define TDataReader  DMSG_HMI_TORPBREAKENGAGEDataReader
#define TDataWriter  DMSG_HMI_TORPBREAKENGAGEDataWriter
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

   Configure and implement 'DMSG_HMI_RESERVEDCOPY' support classes.

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
#define TTYPENAME   DMSG_HMI_RESERVEDCOPYTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_RESERVEDCOPYDataWriter
#define TData       DMSG_HMI_RESERVEDCOPY


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
#define TTYPENAME   DMSG_HMI_RESERVEDCOPYTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_RESERVEDCOPYDataReader
#define TDataSeq    DMSG_HMI_RESERVEDCOPYSeq
#define TData       DMSG_HMI_RESERVEDCOPY


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
#define TTYPENAME    DMSG_HMI_RESERVEDCOPYTYPENAME
#define TPlugin_new  DMSG_HMI_RESERVEDCOPYPlugin_new
#define TPlugin_delete  DMSG_HMI_RESERVEDCOPYPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_RESERVEDCOPYTypeSupport
#define TData        DMSG_HMI_RESERVEDCOPY
#define TDataReader  DMSG_HMI_RESERVEDCOPYDataReader
#define TDataWriter  DMSG_HMI_RESERVEDCOPYDataWriter
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

   Configure and implement 'DMSG_TFC_FIRINGDATA' support classes.

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
#define TTYPENAME   DMSG_TFC_FIRINGDATATYPENAME

/* Defines */
#define TDataWriter DMSG_TFC_FIRINGDATADataWriter
#define TData       DMSG_TFC_FIRINGDATA


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
#define TTYPENAME   DMSG_TFC_FIRINGDATATYPENAME

/* Defines */
#define TDataReader DMSG_TFC_FIRINGDATADataReader
#define TDataSeq    DMSG_TFC_FIRINGDATASeq
#define TData       DMSG_TFC_FIRINGDATA


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
#define TTYPENAME    DMSG_TFC_FIRINGDATATYPENAME
#define TPlugin_new  DMSG_TFC_FIRINGDATAPlugin_new
#define TPlugin_delete  DMSG_TFC_FIRINGDATAPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TFC_FIRINGDATATypeSupport
#define TData        DMSG_TFC_FIRINGDATA
#define TDataReader  DMSG_TFC_FIRINGDATADataReader
#define TDataWriter  DMSG_TFC_FIRINGDATADataWriter
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

   Configure and implement 'DMSG_TFC_TORPSTATE' support classes.

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
#define TTYPENAME   DMSG_TFC_TORPSTATETYPENAME

/* Defines */
#define TDataWriter DMSG_TFC_TORPSTATEDataWriter
#define TData       DMSG_TFC_TORPSTATE


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
#define TTYPENAME   DMSG_TFC_TORPSTATETYPENAME

/* Defines */
#define TDataReader DMSG_TFC_TORPSTATEDataReader
#define TDataSeq    DMSG_TFC_TORPSTATESeq
#define TData       DMSG_TFC_TORPSTATE


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
#define TTYPENAME    DMSG_TFC_TORPSTATETYPENAME
#define TPlugin_new  DMSG_TFC_TORPSTATEPlugin_new
#define TPlugin_delete  DMSG_TFC_TORPSTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TFC_TORPSTATETypeSupport
#define TData        DMSG_TFC_TORPSTATE
#define TDataReader  DMSG_TFC_TORPSTATEDataReader
#define TDataWriter  DMSG_TFC_TORPSTATEDataWriter
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

   Configure and implement 'DMSG_TFC_TORPMANEUVER' support classes.

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
#define TTYPENAME   DMSG_TFC_TORPMANEUVERTYPENAME

/* Defines */
#define TDataWriter DMSG_TFC_TORPMANEUVERDataWriter
#define TData       DMSG_TFC_TORPMANEUVER


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
#define TTYPENAME   DMSG_TFC_TORPMANEUVERTYPENAME

/* Defines */
#define TDataReader DMSG_TFC_TORPMANEUVERDataReader
#define TDataSeq    DMSG_TFC_TORPMANEUVERSeq
#define TData       DMSG_TFC_TORPMANEUVER


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
#define TTYPENAME    DMSG_TFC_TORPMANEUVERTYPENAME
#define TPlugin_new  DMSG_TFC_TORPMANEUVERPlugin_new
#define TPlugin_delete  DMSG_TFC_TORPMANEUVERPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TFC_TORPMANEUVERTypeSupport
#define TData        DMSG_TFC_TORPMANEUVER
#define TDataReader  DMSG_TFC_TORPMANEUVERDataReader
#define TDataWriter  DMSG_TFC_TORPMANEUVERDataWriter
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

   Configure and implement 'DMSG_TFC_CHECKRESULT' support classes.

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
#define TTYPENAME   DMSG_TFC_CHECKRESULTTYPENAME

/* Defines */
#define TDataWriter DMSG_TFC_CHECKRESULTDataWriter
#define TData       DMSG_TFC_CHECKRESULT


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
#define TTYPENAME   DMSG_TFC_CHECKRESULTTYPENAME

/* Defines */
#define TDataReader DMSG_TFC_CHECKRESULTDataReader
#define TDataSeq    DMSG_TFC_CHECKRESULTSeq
#define TData       DMSG_TFC_CHECKRESULT


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
#define TTYPENAME    DMSG_TFC_CHECKRESULTTYPENAME
#define TPlugin_new  DMSG_TFC_CHECKRESULTPlugin_new
#define TPlugin_delete  DMSG_TFC_CHECKRESULTPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TFC_CHECKRESULTTypeSupport
#define TData        DMSG_TFC_CHECKRESULT
#define TDataReader  DMSG_TFC_CHECKRESULTDataReader
#define TDataWriter  DMSG_TFC_CHECKRESULTDataWriter
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

   Configure and implement 'DMSG_TFC_INTERLOCK' support classes.

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
#define TTYPENAME   DMSG_TFC_INTERLOCKTYPENAME

/* Defines */
#define TDataWriter DMSG_TFC_INTERLOCKDataWriter
#define TData       DMSG_TFC_INTERLOCK


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
#define TTYPENAME   DMSG_TFC_INTERLOCKTYPENAME

/* Defines */
#define TDataReader DMSG_TFC_INTERLOCKDataReader
#define TDataSeq    DMSG_TFC_INTERLOCKSeq
#define TData       DMSG_TFC_INTERLOCK


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
#define TTYPENAME    DMSG_TFC_INTERLOCKTYPENAME
#define TPlugin_new  DMSG_TFC_INTERLOCKPlugin_new
#define TPlugin_delete  DMSG_TFC_INTERLOCKPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TFC_INTERLOCKTypeSupport
#define TData        DMSG_TFC_INTERLOCK
#define TDataReader  DMSG_TFC_INTERLOCKDataReader
#define TDataWriter  DMSG_TFC_INTERLOCKDataWriter
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

   Configure and implement 'DMSG_TFC_TORPSONAR' support classes.

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
#define TTYPENAME   DMSG_TFC_TORPSONARTYPENAME

/* Defines */
#define TDataWriter DMSG_TFC_TORPSONARDataWriter
#define TData       DMSG_TFC_TORPSONAR


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
#define TTYPENAME   DMSG_TFC_TORPSONARTYPENAME

/* Defines */
#define TDataReader DMSG_TFC_TORPSONARDataReader
#define TDataSeq    DMSG_TFC_TORPSONARSeq
#define TData       DMSG_TFC_TORPSONAR


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
#define TTYPENAME    DMSG_TFC_TORPSONARTYPENAME
#define TPlugin_new  DMSG_TFC_TORPSONARPlugin_new
#define TPlugin_delete  DMSG_TFC_TORPSONARPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TFC_TORPSONARTypeSupport
#define TData        DMSG_TFC_TORPSONAR
#define TDataReader  DMSG_TFC_TORPSONARDataReader
#define TDataWriter  DMSG_TFC_TORPSONARDataWriter
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

   Configure and implement 'DMSG_TFC_TORPTARGET' support classes.

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
#define TTYPENAME   DMSG_TFC_TORPTARGETTYPENAME

/* Defines */
#define TDataWriter DMSG_TFC_TORPTARGETDataWriter
#define TData       DMSG_TFC_TORPTARGET


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
#define TTYPENAME   DMSG_TFC_TORPTARGETTYPENAME

/* Defines */
#define TDataReader DMSG_TFC_TORPTARGETDataReader
#define TDataSeq    DMSG_TFC_TORPTARGETSeq
#define TData       DMSG_TFC_TORPTARGET


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
#define TTYPENAME    DMSG_TFC_TORPTARGETTYPENAME
#define TPlugin_new  DMSG_TFC_TORPTARGETPlugin_new
#define TPlugin_delete  DMSG_TFC_TORPTARGETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TFC_TORPTARGETTypeSupport
#define TData        DMSG_TFC_TORPTARGET
#define TDataReader  DMSG_TFC_TORPTARGETDataReader
#define TDataWriter  DMSG_TFC_TORPTARGETDataWriter
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

   Configure and implement 'DMSG_TFC_TORPEDOAVAILABILITY' support classes.

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
#define TTYPENAME   DMSG_TFC_TORPEDOAVAILABILITYTYPENAME

/* Defines */
#define TDataWriter DMSG_TFC_TORPEDOAVAILABILITYDataWriter
#define TData       DMSG_TFC_TORPEDOAVAILABILITY


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
#define TTYPENAME   DMSG_TFC_TORPEDOAVAILABILITYTYPENAME

/* Defines */
#define TDataReader DMSG_TFC_TORPEDOAVAILABILITYDataReader
#define TDataSeq    DMSG_TFC_TORPEDOAVAILABILITYSeq
#define TData       DMSG_TFC_TORPEDOAVAILABILITY


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
#define TTYPENAME    DMSG_TFC_TORPEDOAVAILABILITYTYPENAME
#define TPlugin_new  DMSG_TFC_TORPEDOAVAILABILITYPlugin_new
#define TPlugin_delete  DMSG_TFC_TORPEDOAVAILABILITYPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TFC_TORPEDOAVAILABILITYTypeSupport
#define TData        DMSG_TFC_TORPEDOAVAILABILITY
#define TDataReader  DMSG_TFC_TORPEDOAVAILABILITYDataReader
#define TDataWriter  DMSG_TFC_TORPEDOAVAILABILITYDataWriter
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

   Configure and implement 'DMSG_TFC_ENGAGESTATE' support classes.

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
#define TTYPENAME   DMSG_TFC_ENGAGESTATETYPENAME

/* Defines */
#define TDataWriter DMSG_TFC_ENGAGESTATEDataWriter
#define TData       DMSG_TFC_ENGAGESTATE


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
#define TTYPENAME   DMSG_TFC_ENGAGESTATETYPENAME

/* Defines */
#define TDataReader DMSG_TFC_ENGAGESTATEDataReader
#define TDataSeq    DMSG_TFC_ENGAGESTATESeq
#define TData       DMSG_TFC_ENGAGESTATE


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
#define TTYPENAME    DMSG_TFC_ENGAGESTATETYPENAME
#define TPlugin_new  DMSG_TFC_ENGAGESTATEPlugin_new
#define TPlugin_delete  DMSG_TFC_ENGAGESTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TFC_ENGAGESTATETypeSupport
#define TData        DMSG_TFC_ENGAGESTATE
#define TDataReader  DMSG_TFC_ENGAGESTATEDataReader
#define TDataWriter  DMSG_TFC_ENGAGESTATEDataWriter
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

   Configure and implement 'DMSG_TFC_SWSTATE' support classes.

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
#define TTYPENAME   DMSG_TFC_SWSTATETYPENAME

/* Defines */
#define TDataWriter DMSG_TFC_SWSTATEDataWriter
#define TData       DMSG_TFC_SWSTATE


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
#define TTYPENAME   DMSG_TFC_SWSTATETYPENAME

/* Defines */
#define TDataReader DMSG_TFC_SWSTATEDataReader
#define TDataSeq    DMSG_TFC_SWSTATESeq
#define TData       DMSG_TFC_SWSTATE


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
#define TTYPENAME    DMSG_TFC_SWSTATETYPENAME
#define TPlugin_new  DMSG_TFC_SWSTATEPlugin_new
#define TPlugin_delete  DMSG_TFC_SWSTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TFC_SWSTATETypeSupport
#define TData        DMSG_TFC_SWSTATE
#define TDataReader  DMSG_TFC_SWSTATEDataReader
#define TDataWriter  DMSG_TFC_SWSTATEDataWriter
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

   Configure and implement 'DMSG_TFC_HLTCTRL' support classes.

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
#define TTYPENAME   DMSG_TFC_HLTCTRLTYPENAME

/* Defines */
#define TDataWriter DMSG_TFC_HLTCTRLDataWriter
#define TData       DMSG_TFC_HLTCTRL


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
#define TTYPENAME   DMSG_TFC_HLTCTRLTYPENAME

/* Defines */
#define TDataReader DMSG_TFC_HLTCTRLDataReader
#define TDataSeq    DMSG_TFC_HLTCTRLSeq
#define TData       DMSG_TFC_HLTCTRL


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
#define TTYPENAME    DMSG_TFC_HLTCTRLTYPENAME
#define TPlugin_new  DMSG_TFC_HLTCTRLPlugin_new
#define TPlugin_delete  DMSG_TFC_HLTCTRLPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TFC_HLTCTRLTypeSupport
#define TData        DMSG_TFC_HLTCTRL
#define TDataReader  DMSG_TFC_HLTCTRLDataReader
#define TDataWriter  DMSG_TFC_HLTCTRLDataWriter
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

   Configure and implement 'DMSG_MFC_SUMSTATE' support classes.

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
#define TTYPENAME   DMSG_MFC_SUMSTATETYPENAME

/* Defines */
#define TDataWriter DMSG_MFC_SUMSTATEDataWriter
#define TData       DMSG_MFC_SUMSTATE


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
#define TTYPENAME   DMSG_MFC_SUMSTATETYPENAME

/* Defines */
#define TDataReader DMSG_MFC_SUMSTATEDataReader
#define TDataSeq    DMSG_MFC_SUMSTATESeq
#define TData       DMSG_MFC_SUMSTATE


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
#define TTYPENAME    DMSG_MFC_SUMSTATETYPENAME
#define TPlugin_new  DMSG_MFC_SUMSTATEPlugin_new
#define TPlugin_delete  DMSG_MFC_SUMSTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_MFC_SUMSTATETypeSupport
#define TData        DMSG_MFC_SUMSTATE
#define TDataReader  DMSG_MFC_SUMSTATEDataReader
#define TDataWriter  DMSG_MFC_SUMSTATEDataWriter
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

   Configure and implement 'DMSG_MFC_FIRINGDATA' support classes.

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
#define TTYPENAME   DMSG_MFC_FIRINGDATATYPENAME

/* Defines */
#define TDataWriter DMSG_MFC_FIRINGDATADataWriter
#define TData       DMSG_MFC_FIRINGDATA


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
#define TTYPENAME   DMSG_MFC_FIRINGDATATYPENAME

/* Defines */
#define TDataReader DMSG_MFC_FIRINGDATADataReader
#define TDataSeq    DMSG_MFC_FIRINGDATASeq
#define TData       DMSG_MFC_FIRINGDATA


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
#define TTYPENAME    DMSG_MFC_FIRINGDATATYPENAME
#define TPlugin_new  DMSG_MFC_FIRINGDATAPlugin_new
#define TPlugin_delete  DMSG_MFC_FIRINGDATAPlugin_delete

/* Defines */
#define TTypeSupport DMSG_MFC_FIRINGDATATypeSupport
#define TData        DMSG_MFC_FIRINGDATA
#define TDataReader  DMSG_MFC_FIRINGDATADataReader
#define TDataWriter  DMSG_MFC_FIRINGDATADataWriter
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

   Configure and implement 'DMSG_MFC_INTERLOCK' support classes.

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
#define TTYPENAME   DMSG_MFC_INTERLOCKTYPENAME

/* Defines */
#define TDataWriter DMSG_MFC_INTERLOCKDataWriter
#define TData       DMSG_MFC_INTERLOCK


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
#define TTYPENAME   DMSG_MFC_INTERLOCKTYPENAME

/* Defines */
#define TDataReader DMSG_MFC_INTERLOCKDataReader
#define TDataSeq    DMSG_MFC_INTERLOCKSeq
#define TData       DMSG_MFC_INTERLOCK


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
#define TTYPENAME    DMSG_MFC_INTERLOCKTYPENAME
#define TPlugin_new  DMSG_MFC_INTERLOCKPlugin_new
#define TPlugin_delete  DMSG_MFC_INTERLOCKPlugin_delete

/* Defines */
#define TTypeSupport DMSG_MFC_INTERLOCKTypeSupport
#define TData        DMSG_MFC_INTERLOCK
#define TDataReader  DMSG_MFC_INTERLOCKDataReader
#define TDataWriter  DMSG_MFC_INTERLOCKDataWriter
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

   Configure and implement 'DMSG_MFC_SAFETYSWITCHSTATE' support classes.

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
#define TTYPENAME   DMSG_MFC_SAFETYSWITCHSTATETYPENAME

/* Defines */
#define TDataWriter DMSG_MFC_SAFETYSWITCHSTATEDataWriter
#define TData       DMSG_MFC_SAFETYSWITCHSTATE


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
#define TTYPENAME   DMSG_MFC_SAFETYSWITCHSTATETYPENAME

/* Defines */
#define TDataReader DMSG_MFC_SAFETYSWITCHSTATEDataReader
#define TDataSeq    DMSG_MFC_SAFETYSWITCHSTATESeq
#define TData       DMSG_MFC_SAFETYSWITCHSTATE


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
#define TTYPENAME    DMSG_MFC_SAFETYSWITCHSTATETYPENAME
#define TPlugin_new  DMSG_MFC_SAFETYSWITCHSTATEPlugin_new
#define TPlugin_delete  DMSG_MFC_SAFETYSWITCHSTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_MFC_SAFETYSWITCHSTATETypeSupport
#define TData        DMSG_MFC_SAFETYSWITCHSTATE
#define TDataReader  DMSG_MFC_SAFETYSWITCHSTATEDataReader
#define TDataWriter  DMSG_MFC_SAFETYSWITCHSTATEDataWriter
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

   Configure and implement 'DMSG_MFC_SUMTESTRESULT' support classes.

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
#define TTYPENAME   DMSG_MFC_SUMTESTRESULTTYPENAME

/* Defines */
#define TDataWriter DMSG_MFC_SUMTESTRESULTDataWriter
#define TData       DMSG_MFC_SUMTESTRESULT


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
#define TTYPENAME   DMSG_MFC_SUMTESTRESULTTYPENAME

/* Defines */
#define TDataReader DMSG_MFC_SUMTESTRESULTDataReader
#define TDataSeq    DMSG_MFC_SUMTESTRESULTSeq
#define TData       DMSG_MFC_SUMTESTRESULT


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
#define TTYPENAME    DMSG_MFC_SUMTESTRESULTTYPENAME
#define TPlugin_new  DMSG_MFC_SUMTESTRESULTPlugin_new
#define TPlugin_delete  DMSG_MFC_SUMTESTRESULTPlugin_delete

/* Defines */
#define TTypeSupport DMSG_MFC_SUMTESTRESULTTypeSupport
#define TData        DMSG_MFC_SUMTESTRESULT
#define TDataReader  DMSG_MFC_SUMTESTRESULTDataReader
#define TDataWriter  DMSG_MFC_SUMTESTRESULTDataWriter
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

   Configure and implement 'DMSG_MFC_ENGAGESTATE' support classes.

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
#define TTYPENAME   DMSG_MFC_ENGAGESTATETYPENAME

/* Defines */
#define TDataWriter DMSG_MFC_ENGAGESTATEDataWriter
#define TData       DMSG_MFC_ENGAGESTATE


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
#define TTYPENAME   DMSG_MFC_ENGAGESTATETYPENAME

/* Defines */
#define TDataReader DMSG_MFC_ENGAGESTATEDataReader
#define TDataSeq    DMSG_MFC_ENGAGESTATESeq
#define TData       DMSG_MFC_ENGAGESTATE


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
#define TTYPENAME    DMSG_MFC_ENGAGESTATETYPENAME
#define TPlugin_new  DMSG_MFC_ENGAGESTATEPlugin_new
#define TPlugin_delete  DMSG_MFC_ENGAGESTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_MFC_ENGAGESTATETypeSupport
#define TData        DMSG_MFC_ENGAGESTATE
#define TDataReader  DMSG_MFC_ENGAGESTATEDataReader
#define TDataWriter  DMSG_MFC_ENGAGESTATEDataWriter
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

   Configure and implement 'DMSG_MFC_MISSILEAVAILABILITY' support classes.

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
#define TTYPENAME   DMSG_MFC_MISSILEAVAILABILITYTYPENAME

/* Defines */
#define TDataWriter DMSG_MFC_MISSILEAVAILABILITYDataWriter
#define TData       DMSG_MFC_MISSILEAVAILABILITY


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
#define TTYPENAME   DMSG_MFC_MISSILEAVAILABILITYTYPENAME

/* Defines */
#define TDataReader DMSG_MFC_MISSILEAVAILABILITYDataReader
#define TDataSeq    DMSG_MFC_MISSILEAVAILABILITYSeq
#define TData       DMSG_MFC_MISSILEAVAILABILITY


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
#define TTYPENAME    DMSG_MFC_MISSILEAVAILABILITYTYPENAME
#define TPlugin_new  DMSG_MFC_MISSILEAVAILABILITYPlugin_new
#define TPlugin_delete  DMSG_MFC_MISSILEAVAILABILITYPlugin_delete

/* Defines */
#define TTypeSupport DMSG_MFC_MISSILEAVAILABILITYTypeSupport
#define TData        DMSG_MFC_MISSILEAVAILABILITY
#define TDataReader  DMSG_MFC_MISSILEAVAILABILITYDataReader
#define TDataWriter  DMSG_MFC_MISSILEAVAILABILITYDataWriter
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

   Configure and implement 'DMSG_MFC_SWSTATE' support classes.

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
#define TTYPENAME   DMSG_MFC_SWSTATETYPENAME

/* Defines */
#define TDataWriter DMSG_MFC_SWSTATEDataWriter
#define TData       DMSG_MFC_SWSTATE


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
#define TTYPENAME   DMSG_MFC_SWSTATETYPENAME

/* Defines */
#define TDataReader DMSG_MFC_SWSTATEDataReader
#define TDataSeq    DMSG_MFC_SWSTATESeq
#define TData       DMSG_MFC_SWSTATE


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
#define TTYPENAME    DMSG_MFC_SWSTATETYPENAME
#define TPlugin_new  DMSG_MFC_SWSTATEPlugin_new
#define TPlugin_delete  DMSG_MFC_SWSTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_MFC_SWSTATETypeSupport
#define TData        DMSG_MFC_SWSTATE
#define TDataReader  DMSG_MFC_SWSTATEDataReader
#define TDataWriter  DMSG_MFC_SWSTATEDataWriter
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

   Configure and implement 'DMSG_MFC_COUNTDOWNSTATE' support classes.

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
#define TTYPENAME   DMSG_MFC_COUNTDOWNSTATETYPENAME

/* Defines */
#define TDataWriter DMSG_MFC_COUNTDOWNSTATEDataWriter
#define TData       DMSG_MFC_COUNTDOWNSTATE


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
#define TTYPENAME   DMSG_MFC_COUNTDOWNSTATETYPENAME

/* Defines */
#define TDataReader DMSG_MFC_COUNTDOWNSTATEDataReader
#define TDataSeq    DMSG_MFC_COUNTDOWNSTATESeq
#define TData       DMSG_MFC_COUNTDOWNSTATE


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
#define TTYPENAME    DMSG_MFC_COUNTDOWNSTATETYPENAME
#define TPlugin_new  DMSG_MFC_COUNTDOWNSTATEPlugin_new
#define TPlugin_delete  DMSG_MFC_COUNTDOWNSTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_MFC_COUNTDOWNSTATETypeSupport
#define TData        DMSG_MFC_COUNTDOWNSTATE
#define TDataReader  DMSG_MFC_COUNTDOWNSTATEDataReader
#define TDataWriter  DMSG_MFC_COUNTDOWNSTATEDataWriter
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

   Configure and implement 'DMSG_DFC_MANOEUVRE' support classes.

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
#define TTYPENAME   DMSG_DFC_MANOEUVRETYPENAME

/* Defines */
#define TDataWriter DMSG_DFC_MANOEUVREDataWriter
#define TData       DMSG_DFC_MANOEUVRE


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
#define TTYPENAME   DMSG_DFC_MANOEUVRETYPENAME

/* Defines */
#define TDataReader DMSG_DFC_MANOEUVREDataReader
#define TDataSeq    DMSG_DFC_MANOEUVRESeq
#define TData       DMSG_DFC_MANOEUVRE


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
#define TTYPENAME    DMSG_DFC_MANOEUVRETYPENAME
#define TPlugin_new  DMSG_DFC_MANOEUVREPlugin_new
#define TPlugin_delete  DMSG_DFC_MANOEUVREPlugin_delete

/* Defines */
#define TTypeSupport DMSG_DFC_MANOEUVRETypeSupport
#define TData        DMSG_DFC_MANOEUVRE
#define TDataReader  DMSG_DFC_MANOEUVREDataReader
#define TDataWriter  DMSG_DFC_MANOEUVREDataWriter
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

   Configure and implement 'DMSG_DFC_TACTICINFO' support classes.

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
#define TTYPENAME   DMSG_DFC_TACTICINFOTYPENAME

/* Defines */
#define TDataWriter DMSG_DFC_TACTICINFODataWriter
#define TData       DMSG_DFC_TACTICINFO


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
#define TTYPENAME   DMSG_DFC_TACTICINFOTYPENAME

/* Defines */
#define TDataReader DMSG_DFC_TACTICINFODataReader
#define TDataSeq    DMSG_DFC_TACTICINFOSeq
#define TData       DMSG_DFC_TACTICINFO


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
#define TTYPENAME    DMSG_DFC_TACTICINFOTYPENAME
#define TPlugin_new  DMSG_DFC_TACTICINFOPlugin_new
#define TPlugin_delete  DMSG_DFC_TACTICINFOPlugin_delete

/* Defines */
#define TTypeSupport DMSG_DFC_TACTICINFOTypeSupport
#define TData        DMSG_DFC_TACTICINFO
#define TDataReader  DMSG_DFC_TACTICINFODataReader
#define TDataWriter  DMSG_DFC_TACTICINFODataWriter
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

   Configure and implement 'DMSG_DFC_LOADING' support classes.

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
#define TTYPENAME   DMSG_DFC_LOADINGTYPENAME

/* Defines */
#define TDataWriter DMSG_DFC_LOADINGDataWriter
#define TData       DMSG_DFC_LOADING


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
#define TTYPENAME   DMSG_DFC_LOADINGTYPENAME

/* Defines */
#define TDataReader DMSG_DFC_LOADINGDataReader
#define TDataSeq    DMSG_DFC_LOADINGSeq
#define TData       DMSG_DFC_LOADING


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
#define TTYPENAME    DMSG_DFC_LOADINGTYPENAME
#define TPlugin_new  DMSG_DFC_LOADINGPlugin_new
#define TPlugin_delete  DMSG_DFC_LOADINGPlugin_delete

/* Defines */
#define TTypeSupport DMSG_DFC_LOADINGTypeSupport
#define TData        DMSG_DFC_LOADING
#define TDataReader  DMSG_DFC_LOADINGDataReader
#define TDataWriter  DMSG_DFC_LOADINGDataWriter
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

   Configure and implement 'DMSG_DFC_PREDICTPOS' support classes.

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
#define TTYPENAME   DMSG_DFC_PREDICTPOSTYPENAME

/* Defines */
#define TDataWriter DMSG_DFC_PREDICTPOSDataWriter
#define TData       DMSG_DFC_PREDICTPOS


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
#define TTYPENAME   DMSG_DFC_PREDICTPOSTYPENAME

/* Defines */
#define TDataReader DMSG_DFC_PREDICTPOSDataReader
#define TDataSeq    DMSG_DFC_PREDICTPOSSeq
#define TData       DMSG_DFC_PREDICTPOS


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
#define TTYPENAME    DMSG_DFC_PREDICTPOSTYPENAME
#define TPlugin_new  DMSG_DFC_PREDICTPOSPlugin_new
#define TPlugin_delete  DMSG_DFC_PREDICTPOSPlugin_delete

/* Defines */
#define TTypeSupport DMSG_DFC_PREDICTPOSTypeSupport
#define TData        DMSG_DFC_PREDICTPOS
#define TDataReader  DMSG_DFC_PREDICTPOSDataReader
#define TDataWriter  DMSG_DFC_PREDICTPOSDataWriter
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

   Configure and implement 'DMSG_DFC_PERFORM' support classes.

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
#define TTYPENAME   DMSG_DFC_PERFORMTYPENAME

/* Defines */
#define TDataWriter DMSG_DFC_PERFORMDataWriter
#define TData       DMSG_DFC_PERFORM


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
#define TTYPENAME   DMSG_DFC_PERFORMTYPENAME

/* Defines */
#define TDataReader DMSG_DFC_PERFORMDataReader
#define TDataSeq    DMSG_DFC_PERFORMSeq
#define TData       DMSG_DFC_PERFORM


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
#define TTYPENAME    DMSG_DFC_PERFORMTYPENAME
#define TPlugin_new  DMSG_DFC_PERFORMPlugin_new
#define TPlugin_delete  DMSG_DFC_PERFORMPlugin_delete

/* Defines */
#define TTypeSupport DMSG_DFC_PERFORMTypeSupport
#define TData        DMSG_DFC_PERFORM
#define TDataReader  DMSG_DFC_PERFORMDataReader
#define TDataWriter  DMSG_DFC_PERFORMDataWriter
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

   Configure and implement 'DMSG_DFC_EXPECTROUTE' support classes.

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
#define TTYPENAME   DMSG_DFC_EXPECTROUTETYPENAME

/* Defines */
#define TDataWriter DMSG_DFC_EXPECTROUTEDataWriter
#define TData       DMSG_DFC_EXPECTROUTE


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
#define TTYPENAME   DMSG_DFC_EXPECTROUTETYPENAME

/* Defines */
#define TDataReader DMSG_DFC_EXPECTROUTEDataReader
#define TDataSeq    DMSG_DFC_EXPECTROUTESeq
#define TData       DMSG_DFC_EXPECTROUTE


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
#define TTYPENAME    DMSG_DFC_EXPECTROUTETYPENAME
#define TPlugin_new  DMSG_DFC_EXPECTROUTEPlugin_new
#define TPlugin_delete  DMSG_DFC_EXPECTROUTEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_DFC_EXPECTROUTETypeSupport
#define TData        DMSG_DFC_EXPECTROUTE
#define TDataReader  DMSG_DFC_EXPECTROUTEDataReader
#define TDataWriter  DMSG_DFC_EXPECTROUTEDataWriter
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

   Configure and implement 'DMSG_DFC_SUBDCOYFIREPLAN' support classes.

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
#define TTYPENAME   DMSG_DFC_SUBDCOYFIREPLANTYPENAME

/* Defines */
#define TDataWriter DMSG_DFC_SUBDCOYFIREPLANDataWriter
#define TData       DMSG_DFC_SUBDCOYFIREPLAN


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
#define TTYPENAME   DMSG_DFC_SUBDCOYFIREPLANTYPENAME

/* Defines */
#define TDataReader DMSG_DFC_SUBDCOYFIREPLANDataReader
#define TDataSeq    DMSG_DFC_SUBDCOYFIREPLANSeq
#define TData       DMSG_DFC_SUBDCOYFIREPLAN


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
#define TTYPENAME    DMSG_DFC_SUBDCOYFIREPLANTYPENAME
#define TPlugin_new  DMSG_DFC_SUBDCOYFIREPLANPlugin_new
#define TPlugin_delete  DMSG_DFC_SUBDCOYFIREPLANPlugin_delete

/* Defines */
#define TTypeSupport DMSG_DFC_SUBDCOYFIREPLANTypeSupport
#define TData        DMSG_DFC_SUBDCOYFIREPLAN
#define TDataReader  DMSG_DFC_SUBDCOYFIREPLANDataReader
#define TDataWriter  DMSG_DFC_SUBDCOYFIREPLANDataWriter
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

   Configure and implement 'DMSG_DFC_ENGAGESTATE' support classes.

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
#define TTYPENAME   DMSG_DFC_ENGAGESTATETYPENAME

/* Defines */
#define TDataWriter DMSG_DFC_ENGAGESTATEDataWriter
#define TData       DMSG_DFC_ENGAGESTATE


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
#define TTYPENAME   DMSG_DFC_ENGAGESTATETYPENAME

/* Defines */
#define TDataReader DMSG_DFC_ENGAGESTATEDataReader
#define TDataSeq    DMSG_DFC_ENGAGESTATESeq
#define TData       DMSG_DFC_ENGAGESTATE


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
#define TTYPENAME    DMSG_DFC_ENGAGESTATETYPENAME
#define TPlugin_new  DMSG_DFC_ENGAGESTATEPlugin_new
#define TPlugin_delete  DMSG_DFC_ENGAGESTATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_DFC_ENGAGESTATETypeSupport
#define TData        DMSG_DFC_ENGAGESTATE
#define TDataReader  DMSG_DFC_ENGAGESTATEDataReader
#define TDataWriter  DMSG_DFC_ENGAGESTATEDataWriter
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

   Configure and implement 'DMSG_HMI_SELECTEDSENSOR' support classes.

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
#define TTYPENAME   DMSG_HMI_SELECTEDSENSORTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_SELECTEDSENSORDataWriter
#define TData       DMSG_HMI_SELECTEDSENSOR


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
#define TTYPENAME   DMSG_HMI_SELECTEDSENSORTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_SELECTEDSENSORDataReader
#define TDataSeq    DMSG_HMI_SELECTEDSENSORSeq
#define TData       DMSG_HMI_SELECTEDSENSOR


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
#define TTYPENAME    DMSG_HMI_SELECTEDSENSORTYPENAME
#define TPlugin_new  DMSG_HMI_SELECTEDSENSORPlugin_new
#define TPlugin_delete  DMSG_HMI_SELECTEDSENSORPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_SELECTEDSENSORTypeSupport
#define TData        DMSG_HMI_SELECTEDSENSOR
#define TDataReader  DMSG_HMI_SELECTEDSENSORDataReader
#define TDataWriter  DMSG_HMI_SELECTEDSENSORDataWriter
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

   Configure and implement 'DMSG_HMI_SELECTEDWEAPON' support classes.

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
#define TTYPENAME   DMSG_HMI_SELECTEDWEAPONTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_SELECTEDWEAPONDataWriter
#define TData       DMSG_HMI_SELECTEDWEAPON


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
#define TTYPENAME   DMSG_HMI_SELECTEDWEAPONTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_SELECTEDWEAPONDataReader
#define TDataSeq    DMSG_HMI_SELECTEDWEAPONSeq
#define TData       DMSG_HMI_SELECTEDWEAPON


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
#define TTYPENAME    DMSG_HMI_SELECTEDWEAPONTYPENAME
#define TPlugin_new  DMSG_HMI_SELECTEDWEAPONPlugin_new
#define TPlugin_delete  DMSG_HMI_SELECTEDWEAPONPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_SELECTEDWEAPONTypeSupport
#define TData        DMSG_HMI_SELECTEDWEAPON
#define TDataReader  DMSG_HMI_SELECTEDWEAPONDataReader
#define TDataWriter  DMSG_HMI_SELECTEDWEAPONDataWriter
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

   Configure and implement 'DMSG_PA_SENSORRANGERESULT' support classes.

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
#define TTYPENAME   DMSG_PA_SENSORRANGERESULTTYPENAME

/* Defines */
#define TDataWriter DMSG_PA_SENSORRANGERESULTDataWriter
#define TData       DMSG_PA_SENSORRANGERESULT


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
#define TTYPENAME   DMSG_PA_SENSORRANGERESULTTYPENAME

/* Defines */
#define TDataReader DMSG_PA_SENSORRANGERESULTDataReader
#define TDataSeq    DMSG_PA_SENSORRANGERESULTSeq
#define TData       DMSG_PA_SENSORRANGERESULT


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
#define TTYPENAME    DMSG_PA_SENSORRANGERESULTTYPENAME
#define TPlugin_new  DMSG_PA_SENSORRANGERESULTPlugin_new
#define TPlugin_delete  DMSG_PA_SENSORRANGERESULTPlugin_delete

/* Defines */
#define TTypeSupport DMSG_PA_SENSORRANGERESULTTypeSupport
#define TData        DMSG_PA_SENSORRANGERESULT
#define TDataReader  DMSG_PA_SENSORRANGERESULTDataReader
#define TDataWriter  DMSG_PA_SENSORRANGERESULTDataWriter
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

   Configure and implement 'DMSG_PA_WEAPONRANGERESULT' support classes.

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
#define TTYPENAME   DMSG_PA_WEAPONRANGERESULTTYPENAME

/* Defines */
#define TDataWriter DMSG_PA_WEAPONRANGERESULTDataWriter
#define TData       DMSG_PA_WEAPONRANGERESULT


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
#define TTYPENAME   DMSG_PA_WEAPONRANGERESULTTYPENAME

/* Defines */
#define TDataReader DMSG_PA_WEAPONRANGERESULTDataReader
#define TDataSeq    DMSG_PA_WEAPONRANGERESULTSeq
#define TData       DMSG_PA_WEAPONRANGERESULT


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
#define TTYPENAME    DMSG_PA_WEAPONRANGERESULTTYPENAME
#define TPlugin_new  DMSG_PA_WEAPONRANGERESULTPlugin_new
#define TPlugin_delete  DMSG_PA_WEAPONRANGERESULTPlugin_delete

/* Defines */
#define TTypeSupport DMSG_PA_WEAPONRANGERESULTTypeSupport
#define TData        DMSG_PA_WEAPONRANGERESULT
#define TDataReader  DMSG_PA_WEAPONRANGERESULTDataReader
#define TDataWriter  DMSG_PA_WEAPONRANGERESULTDataWriter
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

   Configure and implement 'DMSG_SMS_CONNECT' support classes.

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
#define TTYPENAME   DMSG_SMS_CONNECTTYPENAME

/* Defines */
#define TDataWriter DMSG_SMS_CONNECTDataWriter
#define TData       DMSG_SMS_CONNECT


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
#define TTYPENAME   DMSG_SMS_CONNECTTYPENAME

/* Defines */
#define TDataReader DMSG_SMS_CONNECTDataReader
#define TDataSeq    DMSG_SMS_CONNECTSeq
#define TData       DMSG_SMS_CONNECT


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
#define TTYPENAME    DMSG_SMS_CONNECTTYPENAME
#define TPlugin_new  DMSG_SMS_CONNECTPlugin_new
#define TPlugin_delete  DMSG_SMS_CONNECTPlugin_delete

/* Defines */
#define TTypeSupport DMSG_SMS_CONNECTTypeSupport
#define TData        DMSG_SMS_CONNECT
#define TDataReader  DMSG_SMS_CONNECTDataReader
#define TDataWriter  DMSG_SMS_CONNECTDataWriter
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

   Configure and implement 'DMSG_MMI_CONNECTREPLY' support classes.

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
#define TTYPENAME   DMSG_MMI_CONNECTREPLYTYPENAME

/* Defines */
#define TDataWriter DMSG_MMI_CONNECTREPLYDataWriter
#define TData       DMSG_MMI_CONNECTREPLY


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
#define TTYPENAME   DMSG_MMI_CONNECTREPLYTYPENAME

/* Defines */
#define TDataReader DMSG_MMI_CONNECTREPLYDataReader
#define TDataSeq    DMSG_MMI_CONNECTREPLYSeq
#define TData       DMSG_MMI_CONNECTREPLY


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
#define TTYPENAME    DMSG_MMI_CONNECTREPLYTYPENAME
#define TPlugin_new  DMSG_MMI_CONNECTREPLYPlugin_new
#define TPlugin_delete  DMSG_MMI_CONNECTREPLYPlugin_delete

/* Defines */
#define TTypeSupport DMSG_MMI_CONNECTREPLYTypeSupport
#define TData        DMSG_MMI_CONNECTREPLY
#define TDataReader  DMSG_MMI_CONNECTREPLYDataReader
#define TDataWriter  DMSG_MMI_CONNECTREPLYDataWriter
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

   Configure and implement 'DMSG_SMS_INIT' support classes.

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
#define TTYPENAME   DMSG_SMS_INITTYPENAME

/* Defines */
#define TDataWriter DMSG_SMS_INITDataWriter
#define TData       DMSG_SMS_INIT


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
#define TTYPENAME   DMSG_SMS_INITTYPENAME

/* Defines */
#define TDataReader DMSG_SMS_INITDataReader
#define TDataSeq    DMSG_SMS_INITSeq
#define TData       DMSG_SMS_INIT


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
#define TTYPENAME    DMSG_SMS_INITTYPENAME
#define TPlugin_new  DMSG_SMS_INITPlugin_new
#define TPlugin_delete  DMSG_SMS_INITPlugin_delete

/* Defines */
#define TTypeSupport DMSG_SMS_INITTypeSupport
#define TData        DMSG_SMS_INIT
#define TDataReader  DMSG_SMS_INITDataReader
#define TDataWriter  DMSG_SMS_INITDataWriter
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

   Configure and implement 'DMSG_SMS_DDSTEST' support classes.

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
#define TTYPENAME   DMSG_SMS_DDSTESTTYPENAME

/* Defines */
#define TDataWriter DMSG_SMS_DDSTESTDataWriter
#define TData       DMSG_SMS_DDSTEST


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
#define TTYPENAME   DMSG_SMS_DDSTESTTYPENAME

/* Defines */
#define TDataReader DMSG_SMS_DDSTESTDataReader
#define TDataSeq    DMSG_SMS_DDSTESTSeq
#define TData       DMSG_SMS_DDSTEST


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
#define TTYPENAME    DMSG_SMS_DDSTESTTYPENAME
#define TPlugin_new  DMSG_SMS_DDSTESTPlugin_new
#define TPlugin_delete  DMSG_SMS_DDSTESTPlugin_delete

/* Defines */
#define TTypeSupport DMSG_SMS_DDSTESTTypeSupport
#define TData        DMSG_SMS_DDSTEST
#define TDataReader  DMSG_SMS_DDSTESTDataReader
#define TDataWriter  DMSG_SMS_DDSTESTDataWriter
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

   Configure and implement 'DMSG_HMI_SAVECYCLESET' support classes.

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
#define TTYPENAME   DMSG_HMI_SAVECYCLESETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_SAVECYCLESETDataWriter
#define TData       DMSG_HMI_SAVECYCLESET


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
#define TTYPENAME   DMSG_HMI_SAVECYCLESETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_SAVECYCLESETDataReader
#define TDataSeq    DMSG_HMI_SAVECYCLESETSeq
#define TData       DMSG_HMI_SAVECYCLESET


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
#define TTYPENAME    DMSG_HMI_SAVECYCLESETTYPENAME
#define TPlugin_new  DMSG_HMI_SAVECYCLESETPlugin_new
#define TPlugin_delete  DMSG_HMI_SAVECYCLESETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_SAVECYCLESETTypeSupport
#define TData        DMSG_HMI_SAVECYCLESET
#define TDataReader  DMSG_HMI_SAVECYCLESETDataReader
#define TDataWriter  DMSG_HMI_SAVECYCLESETDataWriter
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


