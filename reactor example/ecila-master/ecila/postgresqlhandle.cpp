#include "postgresqlhandle.h"






US_ECILA

PostgreSQLHandle::PostgreSQLHandle()
:	IDBHandle()
{
	handle_		= 0;
	result_		= 0;
	row_index_	= -1;
}






PostgreSQLHandle::~PostgreSQLHandle()
{
	Disconnect();
}






bool_t PostgreSQLHandle::Connect(DBConnI &dbci)
{
	handle_ = PQsetdbLogin(dbci.host_, dbci.port_, NULL, NULL, dbci.db_, dbci.user_, dbci.passwd_);
	if(!handle_) { ECILA_TRACE(); return FALSE; }

	if(PQstatus(handle_) == CONNECTION_BAD) { ECILA_TRACE(); return FALSE; }

	//cache db connect info & connected flag
	dbci_		= dbci;
	connected_	= TRUE;

	return true;
}






bool_t PostgreSQLHandle::Disconnect()
{
	Clear();
	
	if(connected_) { PQfinish(handle_); }

	connected_ = FALSE;
	return TRUE;
}








bool_t PostgreSQLHandle::Execute(const char_t *fmt, ...)
{
	int32_t res = 0;

	Clear();

	va_list vars;
	va_start(vars, fmt);
	len_query_ = ecila_vsprintf(query_buffer_, sizeof(query_buffer_), fmt, vars);
	va_end(vars);


	result_ = PQexec(handle_, query_buffer_);
	if(!result_) { ECILA_TRACE(); return FALSE; }

	res = PQresultStatus(result_);
	if(res == PGRES_TUPLES_OK)
	{
		num_rows_	= PQntuples(result_);
		num_fields_ = PQnfields(result_);
	}
	else if(res == PGRES_COMMAND_OK)
	{
		num_rows_ = ecila_atoi64(PQcmdTuples(result_));
	}
	else 
	{
		ECILA_TRACE(); return FALSE;
	}

	return TRUE;
}





bool_t PostgreSQLHandle::Fetch()
{
	row_index_++;

	if(!result_ || (uint64_t)row_index_ >= num_rows_) { ECILA_TRACE(); return FALSE; }

	return true;
}






char_t* PostgreSQLHandle::GetValue(uint32_t idx)
{
	if(!result_ || idx >= num_fields_) { ECILA_TRACE(); return 0; }

	return PQgetvalue(result_, row_index_, idx);
}








void PostgreSQLHandle::Clear()
{
	//reset pgsql_result
	if(result_) PQclear(result_);

	result_		= 0;
	row_index_	= -1;
	num_rows_	= 0;
	num_fields_	= 0;

	len_query_	= 0;
	memset(query_buffer_, 0, sizeof(query_buffer_));
}

