#include "httpmsgreq.h"

#include <ecila/tokenizer.h>






US_ECILA

HttpMsgReq::HttpMsgReq()
{
	method_         = METHOD_NONE;
	memset(uri_, 0, sizeof(uri_));
	http_ver_major_ = 0;
	http_ver_minor_ = 0;


	memset(host_, 0, sizeof(host_));
	port_           = 0;


	content_length_ = 0;


	status_			= HTTP::STATUS_UNKNOWN;
}








HttpMsgReq::~HttpMsgReq()
{
}








bool_t HttpMsgReq::Parse(char_t *context, int32_t context_len)
{
	bool_t ret = FALSE;

	char_t *postvalue = strstr(context, "\r\n\r\n");
	context[postvalue - context] = '\0';
	postvalue += 4;

	Tokenizer tk;
	uint32_t line_count = tk.STokenize(context, "\r\n");
	if(line_count < 1) { ECILA_TRACE(); status_ = HTTP::STATUS_BAD_REQUEST; return FALSE; }

	ret = ParseRequest(tk.Token(0));
	if(!ret) { ECILA_TRACE(); status_ = HTTP::STATUS_BAD_REQUEST; return FALSE; }

	for(uint32_t i=1; i<line_count; i++)
	{
		ret = ParseRequestHeader(tk.Token(i));
		if(!ret) { ECILA_TRACE(); status_ = HTTP::STATUS_BAD_REQUEST; return FALSE; }
	}

	ret = ParseEntityBody(postvalue);
	if(!ret) { ECILA_TRACE(); status_ = HTTP::STATUS_BAD_REQUEST; return FALSE; }

	status_ = HTTP::STATUS_OK;
	return TRUE;
}








int32_t HttpMsgReq::Status()
{
	return status_;
}








const char_t* HttpMsgReq::Uri()
{
	return uri_;
}








bool_t HttpMsgReq::ParseRequest(char_t *line)
{
	bool_t ret = FALSE;

	Tokenizer tk;
	uint32_t count = tk.CTokenize(line, " ");
	if(count != 3) { ECILA_TRACE(); return FALSE; }

	if(ecila_strnicmp(tk.Token(0), "GET", 3) == 0)
	{
		method_ = METHOD_GET;
	}
	else if(ecila_strnicmp(tk.Token(0), "POST", 4) == 0)
	{
		method_ = METHOD_POST;
	}
	else
	{
		ECILA_TRACE(); return FALSE;
	}

	ret = ParseRequestUri(tk.Token(1));
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = ParseRequestHttpVer(tk.Token(2));
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t HttpMsgReq::ParseRequestHeader(char_t *line)
{
	return TRUE;
}








bool_t HttpMsgReq::ParseEntityBody(char_t *line)
{
	bool_t ret = FALSE;

	if(method_ != METHOD_POST) { return TRUE; }

	ret = ParseNameValueLine(PARAM_POST, line);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t HttpMsgReq::ParseRequestUri(char_t *line)
{
	bool_t ret = FALSE;
	Tokenizer tk;
	uint32_t count = tk.CTokenize(line, "?");
	if(count < 1 || count > 2) { ECILA_TRACE(); return FALSE; }

	if(ecila_strlen(tk.Token(0)) == 0)
	{
		uri_[0] = '/';
	}
	else
	{
		ecila_strncpy(uri_, tk.Token(0), sizeof(uri_));
	}

	if(count == 2)
	{
		ret = ParseNameValueLine(PARAM_GET, tk.Token(1));
		if(!ret) { ECILA_TRACE(); return FALSE; }
	}

	return TRUE;
}








bool_t HttpMsgReq::ParseRequestHttpVer(char_t *line)
{
	Tokenizer tk;
	uint32_t count = tk.CTokenize(line, "/.");
	if(count != 3) { ECILA_TRACE(); return FALSE; }

	http_ver_major_ = ecila_atoi32(tk.Token(1));
	http_ver_minor_ = ecila_atoi32(tk.Token(2));

	return TRUE;
}








bool_t HttpMsgReq::ParseNameValueLine(PARAM param, char_t *line)
{
	bool_t ret = FALSE;

	Tokenizer tk;
	uint32_t count = tk.CTokenize(line, "&");

	for(uint32_t i=0; i<count; i++)
	{
		Tokenizer tk2;
		uint32_t count2 = tk2.CTokenize(tk.Token(i), "=");
		if(count2 < 1 || count2 > 2) { ECILA_TRACE(); return FALSE; }

		if(count2 == 1)
		{
			ret = RegisterNameValue(param, tk2.Token(0), "");
			if(!ret) { ECILA_TRACE(); return FALSE; }
		}
		else
		{
			ret = RegisterNameValue(param, tk2.Token(0), tk2.Token(1));
			if(!ret) { ECILA_TRACE(); return FALSE; }
		}
	}

	return TRUE;
}








bool_t HttpMsgReq::RegisterNameValue(PARAM param, const char_t *name, const char_t *value)
{
	bool_t ret = FALSE;

	if(param == PARAM_GET)
	{
		ret = RegisterNameValue(get_, name, value);
		if(!ret) { ECILA_TRACE(); return FALSE; }

		ret = RegisterNameValue(request_, name, value);
		if(!ret) { ECILA_TRACE(); return FALSE; }
	}
	else if(param == PARAM_POST)
	{
		ret = RegisterNameValue(post_, name, value);
		if(!ret) { ECILA_TRACE(); return FALSE; }

		ret = RegisterNameValue(request_, name, value);
		if(!ret) { ECILA_TRACE(); return FALSE; }
	}
	else if(param == PARAM_COOKIE)
	{
		ret = RegisterNameValue(cookie_, name, value);
		if(!ret) { ECILA_TRACE(); return FALSE; }
	}
	else
	{
		ECILA_TRACE(); return FALSE;
	}

	return TRUE;
}








bool_t HttpMsgReq::RegisterNameValue(MAP_T &map, const char_t *name, const char_t *value)
{
	ITER_T iter = map.find(name);
	if(iter != map.end()) { ECILA_TRACE(); return FALSE; }

	map[name] = value;
	return TRUE;
}

