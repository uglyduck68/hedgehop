/***************************************************************
 *
 * Copyright (C) 1990-2007, Condor Team, Computer Sciences Department,
 * University of Wisconsin-Madison, WI.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License.  You may
 * obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************/


#ifndef _ORACLEDATABASE_H_
#define _ORACLEDATABASE_H_

#include "condor_common.h"
#include "sqlquery.h"
#include "jobqueuedatabase.h"
#include "quill_enums.h"
#include "occi.h"
#include "MyString.h"

#define QUILL_ORACLE_TIMESTAMP_FORAMT "MM/DD/YYYY HH24:MI:SS TZD"

using oracle::occi::Environment;
using oracle::occi::Connection;
using oracle::occi::Statement;
using oracle::occi::ResultSet;
using oracle::occi::SQLException;
using oracle::occi::MetaData;
using oracle::occi::Clob;

//! ORACLEDataabse: Job Queue Database for Oracle
//
class ORACLEDatabase : public JobQueueDatabase
{
public:
	
	ORACLEDatabase(const char *connect);
	~ORACLEDatabase();

		// connection method
	QuillErrCode         connectDB();
	QuillErrCode		 disconnectDB();
    QuillErrCode         checkConnection();
	QuillErrCode         resetConnection();

		// transaction methods
	QuillErrCode		 beginTransaction();
	QuillErrCode 		 commitTransaction();
	QuillErrCode 		 rollbackTransaction();

		// update methods
	QuillErrCode 	 	 execCommand(const char* sql, 
									 int &num_result);
	QuillErrCode 	 	 execCommand(const char* sql);
	QuillErrCode		 execCommandWithBind(const char* sql,
											 int bnd_cnt,
											 const char** val_arr,
											 QuillAttrDataType *typ_arr);

		// query methods
	QuillErrCode 	 	 execQuery(const char* sql);
	QuillErrCode 	 	 execQuery(const char* sql,
								   ResultSet*& result,
								   Statement *& stmt,
								   int &num_result);
	QuillErrCode         execQuery(const char* sql,
								   int &num_result);	
	QuillErrCode		 execQueryWithBind(const char* sql,
										   int bnd_cnt,
										   const char **val_arr,
										   QuillAttrDataType *typ_arr,
										   int &num_result);

	QuillErrCode         releaseQueryResult();

	const char*          getHistoryHorFieldName(int col);
	int            getHistoryHorNumFields();
	QuillErrCode		 releaseHistoryResults();		

	       // cursor declaration and reclamation routines
    QuillErrCode         openCursorsHistory(SQLQuery *,
                                            SQLQuery *,
                                            bool);

    QuillErrCode         closeCursorsHistory(SQLQuery *,
                                             SQLQuery *,
                                             bool);

	QuillErrCode         releaseJobQueueResults();

	QuillErrCode		 getJobQueueDB(int *, int, int *, int, bool fullscan, 
									   const char *scheddName,
									   int& procAdsHorRes_num,  
									   int& procAdsVerRes_num, 
									   int& clusterAdsHorRes_num, 
									   int& clusterAdsVerRes_num);

	const char*		 	 getJobQueueProcHorFieldName(int col);
	int			 getJobQueueProcHorNumFields();

	const char*			 getJobQueueClusterHorFieldName(int col);
	int			 getJobQueueClusterHorNumFields();

		// The values returned by the following methods must be copied out
		// before a subsequent call to any of the following methods. This
		// is because the returned value points to the same area of buffer
		// that's shared for all of them.
	const char*	         getJobQueueProcAds_HorValue(int row, int col);
	const char*	         getJobQueueProcAds_VerValue(int row, int col);
	const char*	         getJobQueueClusterAds_HorValue(int row, int col);
	const char*	         getJobQueueClusterAds_VerValue(int row, int col);

	QuillErrCode         getHistoryHorValue(SQLQuery *queryhor, int row, int col, const char **value);
	QuillErrCode         getHistoryVerValue(SQLQuery *queryver, int row, int col, const char **value);

		//QuillErrCode   		 fetchNext();
	const char*	         getValue(int row, int col);
		//int  			 getIntValue(int col);
	
	//! get a DBMS error message
	const char*			 getDBError();

private:
		// database connection parameters
	char *userName;
	char *password;
	char *connectString;

		// database processing variables
	Environment *env;
	Connection *conn;
	bool in_tranx;
	Statement *stmt;
	MyString cv;

	FILE *sqllog_fp;

	Statement *queryStmt;
	ResultSet *queryRes;
	int     queryResCursor;

		// only for history tables retrieval
	ResultSet  *historyHorRes;
	Statement  *historyHorStmt;
	int         historyHorResCursor;  
	
	ResultSet  *historyVerRes;
	Statement  *historyVerStmt;
	int         historyVerResCursor;

		// only for job queue tables retrieval
		//!< result for ProcAds_Horizontal table
	ResultSet  *procAdsHorRes;      
	Statement  *procAdsHorStmt;
	int         procAdsHorResCursor;

	ResultSet  *procAdsVerRes;      //!< result for ProcAds_Ver table
	Statement  *procAdsVerStmt;
	int         procAdsVerResCursor;

	ResultSet  *clusterAdsHorRes;//!< result for ClusterAds_Str table
	Statement  *clusterAdsHorStmt;
	int         clusterAdsHorResCursor;

	ResultSet  *clusterAdsVerRes;//!< result for ClusterAds_num table
	Statement  *clusterAdsVerStmt;
	int         clusterAdsVerResCursor;
	MyString    errorMsg;
};

#endif /* _PGSQLDATABSE_H_ */
