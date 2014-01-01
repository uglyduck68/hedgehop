#pragma once


#include <ecila/ecila.h>
#include <map>
#include <string>

#include "http.h"








class HttpMsgReq
{
public:

	enum METHOD
	{
		METHOD_NONE = 0,
		METHOD_GET,
		METHOD_POST,
	};

	enum PARAM
	{
		PARAM_GET,
		PARAM_POST,
		PARAM_COOKIE,
	};

	 HttpMsgReq();
	~HttpMsgReq();

	bool_t Parse(char_t *context, int32_t context_len);

	int32_t Status();
	const char_t* Uri();


private:

	typedef std::map< std::string /* name */, std::string /* value */ > MAP_T;
	typedef MAP_T::iterator												ITER_T;

	//request header
	METHOD  method_;
	char_t  uri_[256];
	int32_t http_ver_major_;
	int32_t http_ver_minor_;

	//host header
	char_t  host_[256];
	int32_t port_;

	//content-length header
	int32_t content_length_;

	//
	int32_t status_;

	//parameter
	MAP_T post_;
	MAP_T get_;
	MAP_T cookie_;
	MAP_T request_; //post_ + get_


	bool_t ParseRequest       (char_t *line);
	bool_t ParseRequestHeader (char_t *line);
	bool_t ParseEntityBody    (char_t *line);

	//ParseRequest
	bool_t ParseRequestUri    (char_t *line);
	bool_t ParseRequestHttpVer(char_t *line);

	//ParseRequest & ParseEntityBody
	bool_t ParseNameValueLine (PARAM method, char_t *line);
	bool_t RegisterNameValue  (PARAM method, const char_t *name, const char_t *value);
	bool_t RegisterNameValue  (MAP_T &map,   const char_t *name, const char_t *value);
	


};
