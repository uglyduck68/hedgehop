
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from rmOPV_Protocol.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/

#include "rmOPV_ProtocolSupport.h"
#include "rmOPV_ProtocolPlugin.h"



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

   Configure and implement 'ST_POSITION' support classes.

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
#define TTYPENAME   ST_POSITIONTYPENAME

/* Defines */
#define TDataWriter ST_POSITIONDataWriter
#define TData       ST_POSITION


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
#define TTYPENAME   ST_POSITIONTYPENAME

/* Defines */
#define TDataReader ST_POSITIONDataReader
#define TDataSeq    ST_POSITIONSeq
#define TData       ST_POSITION


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
#define TTYPENAME    ST_POSITIONTYPENAME
#define TPlugin_new  ST_POSITIONPlugin_new
#define TPlugin_delete  ST_POSITIONPlugin_delete

/* Defines */
#define TTypeSupport ST_POSITIONTypeSupport
#define TData        ST_POSITION
#define TDataReader  ST_POSITIONDataReader
#define TDataWriter  ST_POSITIONDataWriter
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

   Configure and implement 'ST_ENTITY_STATE' support classes.

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
#define TTYPENAME   ST_ENTITY_STATETYPENAME

/* Defines */
#define TDataWriter ST_ENTITY_STATEDataWriter
#define TData       ST_ENTITY_STATE


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
#define TTYPENAME   ST_ENTITY_STATETYPENAME

/* Defines */
#define TDataReader ST_ENTITY_STATEDataReader
#define TDataSeq    ST_ENTITY_STATESeq
#define TData       ST_ENTITY_STATE


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
#define TTYPENAME    ST_ENTITY_STATETYPENAME
#define TPlugin_new  ST_ENTITY_STATEPlugin_new
#define TPlugin_delete  ST_ENTITY_STATEPlugin_delete

/* Defines */
#define TTypeSupport ST_ENTITY_STATETypeSupport
#define TData        ST_ENTITY_STATE
#define TDataReader  ST_ENTITY_STATEDataReader
#define TDataWriter  ST_ENTITY_STATEDataWriter
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

   Configure and implement 'ST_ENTITY_INFO' support classes.

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
#define TTYPENAME   ST_ENTITY_INFOTYPENAME

/* Defines */
#define TDataWriter ST_ENTITY_INFODataWriter
#define TData       ST_ENTITY_INFO


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
#define TTYPENAME   ST_ENTITY_INFOTYPENAME

/* Defines */
#define TDataReader ST_ENTITY_INFODataReader
#define TDataSeq    ST_ENTITY_INFOSeq
#define TData       ST_ENTITY_INFO


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
#define TTYPENAME    ST_ENTITY_INFOTYPENAME
#define TPlugin_new  ST_ENTITY_INFOPlugin_new
#define TPlugin_delete  ST_ENTITY_INFOPlugin_delete

/* Defines */
#define TTypeSupport ST_ENTITY_INFOTypeSupport
#define TData        ST_ENTITY_INFO
#define TDataReader  ST_ENTITY_INFODataReader
#define TDataWriter  ST_ENTITY_INFODataWriter
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

   Configure and implement 'ST_ENTITY_ATTRIBUTE' support classes.

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
#define TTYPENAME   ST_ENTITY_ATTRIBUTETYPENAME

/* Defines */
#define TDataWriter ST_ENTITY_ATTRIBUTEDataWriter
#define TData       ST_ENTITY_ATTRIBUTE


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
#define TTYPENAME   ST_ENTITY_ATTRIBUTETYPENAME

/* Defines */
#define TDataReader ST_ENTITY_ATTRIBUTEDataReader
#define TDataSeq    ST_ENTITY_ATTRIBUTESeq
#define TData       ST_ENTITY_ATTRIBUTE


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
#define TTYPENAME    ST_ENTITY_ATTRIBUTETYPENAME
#define TPlugin_new  ST_ENTITY_ATTRIBUTEPlugin_new
#define TPlugin_delete  ST_ENTITY_ATTRIBUTEPlugin_delete

/* Defines */
#define TTypeSupport ST_ENTITY_ATTRIBUTETypeSupport
#define TData        ST_ENTITY_ATTRIBUTE
#define TDataReader  ST_ENTITY_ATTRIBUTEDataReader
#define TDataWriter  ST_ENTITY_ATTRIBUTEDataWriter
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

   Configure and implement 'ST_MISSILE_DATA' support classes.

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
#define TTYPENAME   ST_MISSILE_DATATYPENAME

/* Defines */
#define TDataWriter ST_MISSILE_DATADataWriter
#define TData       ST_MISSILE_DATA


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
#define TTYPENAME   ST_MISSILE_DATATYPENAME

/* Defines */
#define TDataReader ST_MISSILE_DATADataReader
#define TDataSeq    ST_MISSILE_DATASeq
#define TData       ST_MISSILE_DATA


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
#define TTYPENAME    ST_MISSILE_DATATYPENAME
#define TPlugin_new  ST_MISSILE_DATAPlugin_new
#define TPlugin_delete  ST_MISSILE_DATAPlugin_delete

/* Defines */
#define TTypeSupport ST_MISSILE_DATATypeSupport
#define TData        ST_MISSILE_DATA
#define TDataReader  ST_MISSILE_DATADataReader
#define TDataWriter  ST_MISSILE_DATADataWriter
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

   Configure and implement 'ST_AMMUNITION_DATA' support classes.

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
#define TTYPENAME   ST_AMMUNITION_DATATYPENAME

/* Defines */
#define TDataWriter ST_AMMUNITION_DATADataWriter
#define TData       ST_AMMUNITION_DATA


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
#define TTYPENAME   ST_AMMUNITION_DATATYPENAME

/* Defines */
#define TDataReader ST_AMMUNITION_DATADataReader
#define TDataSeq    ST_AMMUNITION_DATASeq
#define TData       ST_AMMUNITION_DATA


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
#define TTYPENAME    ST_AMMUNITION_DATATYPENAME
#define TPlugin_new  ST_AMMUNITION_DATAPlugin_new
#define TPlugin_delete  ST_AMMUNITION_DATAPlugin_delete

/* Defines */
#define TTypeSupport ST_AMMUNITION_DATATypeSupport
#define TData        ST_AMMUNITION_DATA
#define TDataReader  ST_AMMUNITION_DATADataReader
#define TDataWriter  ST_AMMUNITION_DATADataWriter
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

   Configure and implement 'SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK' support classes.

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
#define TTYPENAME   SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKTYPENAME

/* Defines */
#define TDataWriter SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKDataWriter
#define TData       SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK


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
#define TTYPENAME   SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKTYPENAME

/* Defines */
#define TDataReader SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKDataReader
#define TDataSeq    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKSeq
#define TData       SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK


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
#define TTYPENAME    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKTYPENAME
#define TPlugin_new  SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_new
#define TPlugin_delete  SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_delete

/* Defines */
#define TTypeSupport SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKTypeSupport
#define TData        SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK
#define TDataReader  SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKDataReader
#define TDataWriter  SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKDataWriter
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

   Configure and implement 'SIM_SC_SIMULATOR_STATUS_REPORT' support classes.

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
#define TTYPENAME   SIM_SC_SIMULATOR_STATUS_REPORTTYPENAME

/* Defines */
#define TDataWriter SIM_SC_SIMULATOR_STATUS_REPORTDataWriter
#define TData       SIM_SC_SIMULATOR_STATUS_REPORT


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
#define TTYPENAME   SIM_SC_SIMULATOR_STATUS_REPORTTYPENAME

/* Defines */
#define TDataReader SIM_SC_SIMULATOR_STATUS_REPORTDataReader
#define TDataSeq    SIM_SC_SIMULATOR_STATUS_REPORTSeq
#define TData       SIM_SC_SIMULATOR_STATUS_REPORT


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
#define TTYPENAME    SIM_SC_SIMULATOR_STATUS_REPORTTYPENAME
#define TPlugin_new  SIM_SC_SIMULATOR_STATUS_REPORTPlugin_new
#define TPlugin_delete  SIM_SC_SIMULATOR_STATUS_REPORTPlugin_delete

/* Defines */
#define TTypeSupport SIM_SC_SIMULATOR_STATUS_REPORTTypeSupport
#define TData        SIM_SC_SIMULATOR_STATUS_REPORT
#define TDataReader  SIM_SC_SIMULATOR_STATUS_REPORTDataReader
#define TDataWriter  SIM_SC_SIMULATOR_STATUS_REPORTDataWriter
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

   Configure and implement 'SC_SER_LINK_CONNECTION_COMMAND' support classes.

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
#define TTYPENAME   SC_SER_LINK_CONNECTION_COMMANDTYPENAME

/* Defines */
#define TDataWriter SC_SER_LINK_CONNECTION_COMMANDDataWriter
#define TData       SC_SER_LINK_CONNECTION_COMMAND


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
#define TTYPENAME   SC_SER_LINK_CONNECTION_COMMANDTYPENAME

/* Defines */
#define TDataReader SC_SER_LINK_CONNECTION_COMMANDDataReader
#define TDataSeq    SC_SER_LINK_CONNECTION_COMMANDSeq
#define TData       SC_SER_LINK_CONNECTION_COMMAND


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
#define TTYPENAME    SC_SER_LINK_CONNECTION_COMMANDTYPENAME
#define TPlugin_new  SC_SER_LINK_CONNECTION_COMMANDPlugin_new
#define TPlugin_delete  SC_SER_LINK_CONNECTION_COMMANDPlugin_delete

/* Defines */
#define TTypeSupport SC_SER_LINK_CONNECTION_COMMANDTypeSupport
#define TData        SC_SER_LINK_CONNECTION_COMMAND
#define TDataReader  SC_SER_LINK_CONNECTION_COMMANDDataReader
#define TDataWriter  SC_SER_LINK_CONNECTION_COMMANDDataWriter
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

   Configure and implement 'SER_SC_LINK_CONNECTION_COMMAND_ACK' support classes.

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
#define TTYPENAME   SER_SC_LINK_CONNECTION_COMMAND_ACKTYPENAME

/* Defines */
#define TDataWriter SER_SC_LINK_CONNECTION_COMMAND_ACKDataWriter
#define TData       SER_SC_LINK_CONNECTION_COMMAND_ACK


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
#define TTYPENAME   SER_SC_LINK_CONNECTION_COMMAND_ACKTYPENAME

/* Defines */
#define TDataReader SER_SC_LINK_CONNECTION_COMMAND_ACKDataReader
#define TDataSeq    SER_SC_LINK_CONNECTION_COMMAND_ACKSeq
#define TData       SER_SC_LINK_CONNECTION_COMMAND_ACK


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
#define TTYPENAME    SER_SC_LINK_CONNECTION_COMMAND_ACKTYPENAME
#define TPlugin_new  SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_new
#define TPlugin_delete  SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_delete

/* Defines */
#define TTypeSupport SER_SC_LINK_CONNECTION_COMMAND_ACKTypeSupport
#define TData        SER_SC_LINK_CONNECTION_COMMAND_ACK
#define TDataReader  SER_SC_LINK_CONNECTION_COMMAND_ACKDataReader
#define TDataWriter  SER_SC_LINK_CONNECTION_COMMAND_ACKDataWriter
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

   Configure and implement 'SC_SIM_SIMULATION_MANAGEMENT_COMMAND' support classes.

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
#define TTYPENAME   SC_SIM_SIMULATION_MANAGEMENT_COMMANDTYPENAME

/* Defines */
#define TDataWriter SC_SIM_SIMULATION_MANAGEMENT_COMMANDDataWriter
#define TData       SC_SIM_SIMULATION_MANAGEMENT_COMMAND


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
#define TTYPENAME   SC_SIM_SIMULATION_MANAGEMENT_COMMANDTYPENAME

/* Defines */
#define TDataReader SC_SIM_SIMULATION_MANAGEMENT_COMMANDDataReader
#define TDataSeq    SC_SIM_SIMULATION_MANAGEMENT_COMMANDSeq
#define TData       SC_SIM_SIMULATION_MANAGEMENT_COMMAND


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
#define TTYPENAME    SC_SIM_SIMULATION_MANAGEMENT_COMMANDTYPENAME
#define TPlugin_new  SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_new
#define TPlugin_delete  SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_delete

/* Defines */
#define TTypeSupport SC_SIM_SIMULATION_MANAGEMENT_COMMANDTypeSupport
#define TData        SC_SIM_SIMULATION_MANAGEMENT_COMMAND
#define TDataReader  SC_SIM_SIMULATION_MANAGEMENT_COMMANDDataReader
#define TDataWriter  SC_SIM_SIMULATION_MANAGEMENT_COMMANDDataWriter
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

   Configure and implement 'SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK' support classes.

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
#define TTYPENAME   SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKTYPENAME

/* Defines */
#define TDataWriter SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKDataWriter
#define TData       SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK


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
#define TTYPENAME   SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKTYPENAME

/* Defines */
#define TDataReader SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKDataReader
#define TDataSeq    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKSeq
#define TData       SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK


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
#define TTYPENAME    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKTYPENAME
#define TPlugin_new  SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_new
#define TPlugin_delete  SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_delete

/* Defines */
#define TTypeSupport SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKTypeSupport
#define TData        SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK
#define TDataReader  SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKDataReader
#define TDataWriter  SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKDataWriter
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

   Configure and implement 'SC_SIM_PARAMETER_DISTRIBUTION_COMMAND' support classes.

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
#define TTYPENAME   SC_SIM_PARAMETER_DISTRIBUTION_COMMANDTYPENAME

/* Defines */
#define TDataWriter SC_SIM_PARAMETER_DISTRIBUTION_COMMANDDataWriter
#define TData       SC_SIM_PARAMETER_DISTRIBUTION_COMMAND


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
#define TTYPENAME   SC_SIM_PARAMETER_DISTRIBUTION_COMMANDTYPENAME

/* Defines */
#define TDataReader SC_SIM_PARAMETER_DISTRIBUTION_COMMANDDataReader
#define TDataSeq    SC_SIM_PARAMETER_DISTRIBUTION_COMMANDSeq
#define TData       SC_SIM_PARAMETER_DISTRIBUTION_COMMAND


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
#define TTYPENAME    SC_SIM_PARAMETER_DISTRIBUTION_COMMANDTYPENAME
#define TPlugin_new  SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_new
#define TPlugin_delete  SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_delete

/* Defines */
#define TTypeSupport SC_SIM_PARAMETER_DISTRIBUTION_COMMANDTypeSupport
#define TData        SC_SIM_PARAMETER_DISTRIBUTION_COMMAND
#define TDataReader  SC_SIM_PARAMETER_DISTRIBUTION_COMMANDDataReader
#define TDataWriter  SC_SIM_PARAMETER_DISTRIBUTION_COMMANDDataWriter
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

   Configure and implement 'SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK' support classes.

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
#define TTYPENAME   SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKTYPENAME

/* Defines */
#define TDataWriter SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKDataWriter
#define TData       SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK


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
#define TTYPENAME   SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKTYPENAME

/* Defines */
#define TDataReader SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKDataReader
#define TDataSeq    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKSeq
#define TData       SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK


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
#define TTYPENAME    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKTYPENAME
#define TPlugin_new  SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_new
#define TPlugin_delete  SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_delete

/* Defines */
#define TTypeSupport SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKTypeSupport
#define TData        SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK
#define TDataReader  SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKDataReader
#define TDataWriter  SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKDataWriter
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

   Configure and implement 'SC_SIM_SIMULATOR_PARAMETER' support classes.

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
#define TTYPENAME   SC_SIM_SIMULATOR_PARAMETERTYPENAME

/* Defines */
#define TDataWriter SC_SIM_SIMULATOR_PARAMETERDataWriter
#define TData       SC_SIM_SIMULATOR_PARAMETER


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
#define TTYPENAME   SC_SIM_SIMULATOR_PARAMETERTYPENAME

/* Defines */
#define TDataReader SC_SIM_SIMULATOR_PARAMETERDataReader
#define TDataSeq    SC_SIM_SIMULATOR_PARAMETERSeq
#define TData       SC_SIM_SIMULATOR_PARAMETER


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
#define TTYPENAME    SC_SIM_SIMULATOR_PARAMETERTYPENAME
#define TPlugin_new  SC_SIM_SIMULATOR_PARAMETERPlugin_new
#define TPlugin_delete  SC_SIM_SIMULATOR_PARAMETERPlugin_delete

/* Defines */
#define TTypeSupport SC_SIM_SIMULATOR_PARAMETERTypeSupport
#define TData        SC_SIM_SIMULATOR_PARAMETER
#define TDataReader  SC_SIM_SIMULATOR_PARAMETERDataReader
#define TDataWriter  SC_SIM_SIMULATOR_PARAMETERDataWriter
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

   Configure and implement 'SIM_SC_SIMULATOR_PARAMETER_ACK' support classes.

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
#define TTYPENAME   SIM_SC_SIMULATOR_PARAMETER_ACKTYPENAME

/* Defines */
#define TDataWriter SIM_SC_SIMULATOR_PARAMETER_ACKDataWriter
#define TData       SIM_SC_SIMULATOR_PARAMETER_ACK


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
#define TTYPENAME   SIM_SC_SIMULATOR_PARAMETER_ACKTYPENAME

/* Defines */
#define TDataReader SIM_SC_SIMULATOR_PARAMETER_ACKDataReader
#define TDataSeq    SIM_SC_SIMULATOR_PARAMETER_ACKSeq
#define TData       SIM_SC_SIMULATOR_PARAMETER_ACK


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
#define TTYPENAME    SIM_SC_SIMULATOR_PARAMETER_ACKTYPENAME
#define TPlugin_new  SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_new
#define TPlugin_delete  SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_delete

/* Defines */
#define TTypeSupport SIM_SC_SIMULATOR_PARAMETER_ACKTypeSupport
#define TData        SIM_SC_SIMULATOR_PARAMETER_ACK
#define TDataReader  SIM_SC_SIMULATOR_PARAMETER_ACKDataReader
#define TDataWriter  SIM_SC_SIMULATOR_PARAMETER_ACKDataWriter
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

   Configure and implement 'SC_SIM_ENVIRONMENT' support classes.

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
#define TTYPENAME   SC_SIM_ENVIRONMENTTYPENAME

/* Defines */
#define TDataWriter SC_SIM_ENVIRONMENTDataWriter
#define TData       SC_SIM_ENVIRONMENT


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
#define TTYPENAME   SC_SIM_ENVIRONMENTTYPENAME

/* Defines */
#define TDataReader SC_SIM_ENVIRONMENTDataReader
#define TDataSeq    SC_SIM_ENVIRONMENTSeq
#define TData       SC_SIM_ENVIRONMENT


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
#define TTYPENAME    SC_SIM_ENVIRONMENTTYPENAME
#define TPlugin_new  SC_SIM_ENVIRONMENTPlugin_new
#define TPlugin_delete  SC_SIM_ENVIRONMENTPlugin_delete

/* Defines */
#define TTypeSupport SC_SIM_ENVIRONMENTTypeSupport
#define TData        SC_SIM_ENVIRONMENT
#define TDataReader  SC_SIM_ENVIRONMENTDataReader
#define TDataWriter  SC_SIM_ENVIRONMENTDataWriter
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

   Configure and implement 'SC_SIM_ENTITY' support classes.

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
#define TTYPENAME   SC_SIM_ENTITYTYPENAME

/* Defines */
#define TDataWriter SC_SIM_ENTITYDataWriter
#define TData       SC_SIM_ENTITY


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
#define TTYPENAME   SC_SIM_ENTITYTYPENAME

/* Defines */
#define TDataReader SC_SIM_ENTITYDataReader
#define TDataSeq    SC_SIM_ENTITYSeq
#define TData       SC_SIM_ENTITY


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
#define TTYPENAME    SC_SIM_ENTITYTYPENAME
#define TPlugin_new  SC_SIM_ENTITYPlugin_new
#define TPlugin_delete  SC_SIM_ENTITYPlugin_delete

/* Defines */
#define TTypeSupport SC_SIM_ENTITYTypeSupport
#define TData        SC_SIM_ENTITY
#define TDataReader  SC_SIM_ENTITYDataReader
#define TDataWriter  SC_SIM_ENTITYDataWriter
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

   Configure and implement 'SC_SIM_ENTITY_STATE' support classes.

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
#define TTYPENAME   SC_SIM_ENTITY_STATETYPENAME

/* Defines */
#define TDataWriter SC_SIM_ENTITY_STATEDataWriter
#define TData       SC_SIM_ENTITY_STATE


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
#define TTYPENAME   SC_SIM_ENTITY_STATETYPENAME

/* Defines */
#define TDataReader SC_SIM_ENTITY_STATEDataReader
#define TDataSeq    SC_SIM_ENTITY_STATESeq
#define TData       SC_SIM_ENTITY_STATE


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
#define TTYPENAME    SC_SIM_ENTITY_STATETYPENAME
#define TPlugin_new  SC_SIM_ENTITY_STATEPlugin_new
#define TPlugin_delete  SC_SIM_ENTITY_STATEPlugin_delete

/* Defines */
#define TTypeSupport SC_SIM_ENTITY_STATETypeSupport
#define TData        SC_SIM_ENTITY_STATE
#define TDataReader  SC_SIM_ENTITY_STATEDataReader
#define TDataWriter  SC_SIM_ENTITY_STATEDataWriter
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

   Configure and implement 'SC_SIM_OWNSHIP' support classes.

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
#define TTYPENAME   SC_SIM_OWNSHIPTYPENAME

/* Defines */
#define TDataWriter SC_SIM_OWNSHIPDataWriter
#define TData       SC_SIM_OWNSHIP


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
#define TTYPENAME   SC_SIM_OWNSHIPTYPENAME

/* Defines */
#define TDataReader SC_SIM_OWNSHIPDataReader
#define TDataSeq    SC_SIM_OWNSHIPSeq
#define TData       SC_SIM_OWNSHIP


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
#define TTYPENAME    SC_SIM_OWNSHIPTYPENAME
#define TPlugin_new  SC_SIM_OWNSHIPPlugin_new
#define TPlugin_delete  SC_SIM_OWNSHIPPlugin_delete

/* Defines */
#define TTypeSupport SC_SIM_OWNSHIPTypeSupport
#define TData        SC_SIM_OWNSHIP
#define TDataReader  SC_SIM_OWNSHIPDataReader
#define TDataWriter  SC_SIM_OWNSHIPDataWriter
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

   Configure and implement 'SC_SIM_OWNSHIP_STATE' support classes.

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
#define TTYPENAME   SC_SIM_OWNSHIP_STATETYPENAME

/* Defines */
#define TDataWriter SC_SIM_OWNSHIP_STATEDataWriter
#define TData       SC_SIM_OWNSHIP_STATE


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
#define TTYPENAME   SC_SIM_OWNSHIP_STATETYPENAME

/* Defines */
#define TDataReader SC_SIM_OWNSHIP_STATEDataReader
#define TDataSeq    SC_SIM_OWNSHIP_STATESeq
#define TData       SC_SIM_OWNSHIP_STATE


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
#define TTYPENAME    SC_SIM_OWNSHIP_STATETYPENAME
#define TPlugin_new  SC_SIM_OWNSHIP_STATEPlugin_new
#define TPlugin_delete  SC_SIM_OWNSHIP_STATEPlugin_delete

/* Defines */
#define TTypeSupport SC_SIM_OWNSHIP_STATETypeSupport
#define TData        SC_SIM_OWNSHIP_STATE
#define TDataReader  SC_SIM_OWNSHIP_STATEDataReader
#define TDataWriter  SC_SIM_OWNSHIP_STATEDataWriter
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

   Configure and implement 'SIM_SC_MISSILE_CREATION' support classes.

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
#define TTYPENAME   SIM_SC_MISSILE_CREATIONTYPENAME

/* Defines */
#define TDataWriter SIM_SC_MISSILE_CREATIONDataWriter
#define TData       SIM_SC_MISSILE_CREATION


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
#define TTYPENAME   SIM_SC_MISSILE_CREATIONTYPENAME

/* Defines */
#define TDataReader SIM_SC_MISSILE_CREATIONDataReader
#define TDataSeq    SIM_SC_MISSILE_CREATIONSeq
#define TData       SIM_SC_MISSILE_CREATION


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
#define TTYPENAME    SIM_SC_MISSILE_CREATIONTYPENAME
#define TPlugin_new  SIM_SC_MISSILE_CREATIONPlugin_new
#define TPlugin_delete  SIM_SC_MISSILE_CREATIONPlugin_delete

/* Defines */
#define TTypeSupport SIM_SC_MISSILE_CREATIONTypeSupport
#define TData        SIM_SC_MISSILE_CREATION
#define TDataReader  SIM_SC_MISSILE_CREATIONDataReader
#define TDataWriter  SIM_SC_MISSILE_CREATIONDataWriter
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

   Configure and implement 'SIM_SC_SHELL_CREATION' support classes.

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
#define TTYPENAME   SIM_SC_SHELL_CREATIONTYPENAME

/* Defines */
#define TDataWriter SIM_SC_SHELL_CREATIONDataWriter
#define TData       SIM_SC_SHELL_CREATION


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
#define TTYPENAME   SIM_SC_SHELL_CREATIONTYPENAME

/* Defines */
#define TDataReader SIM_SC_SHELL_CREATIONDataReader
#define TDataSeq    SIM_SC_SHELL_CREATIONSeq
#define TData       SIM_SC_SHELL_CREATION


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
#define TTYPENAME    SIM_SC_SHELL_CREATIONTYPENAME
#define TPlugin_new  SIM_SC_SHELL_CREATIONPlugin_new
#define TPlugin_delete  SIM_SC_SHELL_CREATIONPlugin_delete

/* Defines */
#define TTypeSupport SIM_SC_SHELL_CREATIONTypeSupport
#define TData        SIM_SC_SHELL_CREATION
#define TDataReader  SIM_SC_SHELL_CREATIONDataReader
#define TDataWriter  SIM_SC_SHELL_CREATIONDataWriter
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


