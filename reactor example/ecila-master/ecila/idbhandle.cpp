#include "idbhandle.h"








US_ECILA

IDBHandle::IDBHandle()
{
	connected_		= 0;
	errno_			= 0;

	num_rows_		= 0;
	num_fields_		= 0;
	len_query_		= 0;
	memset(query_buffer_, 0, sizeof(query_buffer_));
}








IDBHandle::~IDBHandle()
{
}








bool_t	IDBHandle::IsConnected()
{
	return connected_;
}








int32_t IDBHandle::Error()
{
	return errno_;
}








uint64_t IDBHandle::RowCount()
{
	return num_rows_;
}








uint32_t IDBHandle::FieldCount()
{
	return num_fields_;
}
