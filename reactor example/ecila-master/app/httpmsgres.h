#pragma once


#include <ecila/timer.h>
#include <ecila/buffer.h>
#include <map>
#include <string>

#include "http.h"







class HttpMsgRes
{
public:
	 HttpMsgRes();
	~HttpMsgRes();


	bool_t PutContext (const char_t *context, int32_t context_len);
	bool_t PutHeader  (const char_t *name, const char_t *value);
	bool_t Serialize  (NS_ECILA::Buffer *buffer);


	bool_t Status     (int32_t status);
	bool_t Version    (int32_t major, int32_t minor);

private:

	typedef std::map< std::string /* name */, std::string /* value */ > MAP_T;
	typedef MAP_T::iterator												ITER_T;


	int32_t http_ver_major_;
	int32_t http_ver_minor_;

	int32_t status_;
	int32_t content_length_;

	//response header
	MAP_T header_;

	char_t *context_;

	bool_t AssembleResponse      (NS_ECILA::Buffer *buffer);
	bool_t AssembleDateTimeHeader(NS_ECILA::Buffer *buffer);
	bool_t AssembleResponseHeader(NS_ECILA::Buffer *buffer);
	bool_t AssembleEntityBody    (NS_ECILA::Buffer *buffer);
};

