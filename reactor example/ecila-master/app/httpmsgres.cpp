#include "httpmsgres.h"








US_ECILA

HttpMsgRes::HttpMsgRes()
{
	http_ver_major_  = 0;
	http_ver_minor_  = 0;

	status_          = HTTP::STATUS_UNKNOWN;
	content_length_  = 0;

	context_         = 0;

}







HttpMsgRes::~HttpMsgRes()
{
}








bool_t HttpMsgRes::PutContext(const char_t *context, int32_t context_len)
{
	bool_t  ret = FALSE;
	int32_t len = 0;
	char_t  value[256] = {0, };

	context_        = (char_t*)context;
	content_length_ = context_len;

	len = ecila_sprintf(value, sizeof(value), "%d", context_len);
	if(len <= 0) { ECILA_TRACE(); return FALSE; }

	ret = PutHeader("Content-Length", value);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t HttpMsgRes::PutHeader(const char_t *name, const char_t *value)
{
	ITER_T iter = header_.find(name);
	if(iter != header_.end()) { ECILA_TRACE(); return FALSE; }

	header_[name] = value;
	return TRUE;
}








bool_t HttpMsgRes::Serialize(Buffer *buffer)
{
	bool_t ret = FALSE;

	ret = AssembleResponse(buffer);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = AssembleDateTimeHeader(buffer);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = AssembleResponseHeader(buffer);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = AssembleEntityBody(buffer);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t HttpMsgRes::Status(int32_t status)
{
	status_ = status;
	return TRUE;
}








bool_t HttpMsgRes::Version(int32_t major, int32_t minor)
{
	http_ver_major_ = major;
	http_ver_minor_ = minor;

	return TRUE;
}







bool_t HttpMsgRes::AssembleResponse(Buffer *buffer)
{
	bool_t  ret = FALSE;
	int32_t len = 0;
	char_t  line[256] = {0, };

	len = ecila_sprintf(line, sizeof(line), "HTTP/%d.%d %s\r\n",
						http_ver_major_,
						http_ver_minor_,
						HTTP::Status(status_));
	if(len <= 0) { ECILA_TRACE(); return FALSE; }

	ret = buffer->PutBinary(line, (uint32_t)len);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t HttpMsgRes::AssembleDateTimeHeader(Buffer *buffer)
{
	bool_t ret = FALSE;
	int32_t len = 0;
	char_t  line[256] = {0, };

	DateTimeValue dtv;
	ret = Time::GetGMTDateTimeValue(dtv);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	len = HTTP::AssembleGMTDateTime(dtv, line, sizeof(line));
	if(len <= 0) { ECILA_TRACE(); return FALSE; }

	ret = buffer->PutBinary((char_t*)"Date: ", 6);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = buffer->PutBinary(line, len);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = buffer->PutBinary((char_t*)"\r\n", 2);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t HttpMsgRes::AssembleResponseHeader(Buffer *buffer)
{
	bool_t ret = FALSE;

	for(ITER_T iter = header_.begin(); iter != header_.end(); ++iter)
	{
		ret = buffer->PutBinary((char_t*)iter->first.c_str(), iter->first.length());
		if(!ret) { ECILA_TRACE(); return FALSE; }

		ret = buffer->PutBinary((char_t*)": ", 2);
		if(!ret) { ECILA_TRACE(); return FALSE; }

		ret = buffer->PutBinary((char_t*)iter->second.c_str(), iter->second.length());
		if(!ret) { ECILA_TRACE(); return FALSE; }

		ret = buffer->PutBinary((char_t*)"\r\n", 2);
		if(!ret) { ECILA_TRACE(); return FALSE; }
	}

	return TRUE;
}







bool_t HttpMsgRes::AssembleEntityBody(Buffer *buffer)
{
	bool_t ret = FALSE;

	ret = buffer->PutBinary((char_t*)"\r\n", 2);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	if(content_length_ > 0)
	{
		ret = buffer->PutBinary(context_, content_length_);
		if(!ret) { ECILA_TRACE(); return FALSE; }
	}

	return TRUE;
}

