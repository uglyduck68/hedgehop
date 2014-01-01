#include "mysqlhandle.h"








US_ECILA

MySQLHandle::MySQLHandle()
:	IDBHandle()
{
	result_			= 0;
	row_			= 0;
	field_			= 0;
}







MySQLHandle::~MySQLHandle()
{
	Disconnect();
}








bool_t MySQLHandle::Connect(DBConnI &dbci)
{
	int32_t iret = 0;
	MYSQL	*ret = 0;
	bool_t	b_value = TRUE;

	ret = mysql_init(&handle_);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = mysql_real_connect(&handle_, dbci.host_, dbci.user_, dbci.passwd_, dbci.db_, ecila_atoi32(dbci.port_), 0, CLIENT_MULTI_RESULTS | CLIENT_MULTI_STATEMENTS);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	iret = mysql_options(&handle_, MYSQL_OPT_RECONNECT, &b_value);
	if(iret) { ECILA_TRACE(); return FALSE; }

	iret = mysql_set_character_set(&handle_, dbci.charset_);
	if(iret) { ECILA_TRACE(); return FALSE; }

	//cache db connect info & connected flag
	dbci_		= dbci;
	connected_	= TRUE;

	return TRUE;
}








bool_t MySQLHandle::Disconnect()
{
	Clear();

	if(connected_) { mysql_close(&handle_); }

	connected_ = FALSE;
	return TRUE;
}








bool_t MySQLHandle::Execute(const char_t* fmt, ...)
{
	int32_t ret = 0;

	Clear();

	va_list vars;
	va_start(vars, fmt);
	len_query_ = ecila_vsprintf(query_buffer_, sizeof(query_buffer_), fmt, vars);
	va_end(vars);

	ret = mysql_real_query(&handle_, query_buffer_, len_query_);
	if(ret) { ECILA_TRACE(); return FALSE; }

	result_ = mysql_store_result(&handle_);
	if(result_)
	{
		num_rows_	= mysql_num_rows(result_);
		num_fields_ = mysql_num_fields(result_);
	}
	else
	{
		if(mysql_field_count(&handle_) == 0)
		{
			num_rows_ = mysql_affected_rows(&handle_);
		}
		else
		{
			ECILA_TRACE(); return FALSE;
		}
	}

	return TRUE;
}








bool_t MySQLHandle::Fetch()
{
	bool_t ret = FALSE;
	
	ret = FetchRow();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = FetchField();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








char* MySQLHandle::GetValue(uint32_t idx)
{
	if(!result_ || !row_ || num_rows_ <= idx) { ECILA_TRACE(); return 0; }

	return row_[idx];
}







char* MySQLHandle::GetValue(const char_t* field_name)
{
	if(!result_ || !row_ || !field_name) { ECILA_TRACE(); return 0; }

	ITER_T iter = field_asoc_.find(field_name);
	if(iter == field_asoc_.end()) { ECILA_TRACE(); return 0; }

	return GetValue(iter->second);
}








void MySQLHandle::Clear()
{
	//reset mysql_result
	if(result_) mysql_free_result(result_);

	result_		= 0;
	row_		= 0;
	field_		= 0;
	field_asoc_.clear();
	num_rows_	= 0;
	num_fields_	= 0;

	len_query_	= 0;
	memset(query_buffer_, 0, sizeof(query_buffer_));
}








bool_t MySQLHandle::FetchRow()
{
	if(!result_) { ECILA_TRACE(); return FALSE; }

	row_ = mysql_fetch_row(result_);
	if(!row_) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t MySQLHandle::FetchField()
{
	if(!result_) { ECILA_TRACE(); return FALSE; }
	if(field_)   { return TRUE; }

	field_ = mysql_fetch_field(result_);
	if(!field_) { ECILA_TRACE(); return FALSE; }

	for(uint32_t i=0; i<num_fields_; i++)
	{
		field_asoc_[field_[i].name] = i;
	}

	return TRUE;
}

