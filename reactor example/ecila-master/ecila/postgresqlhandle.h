#pragma once


#include "idbhandle.h"
#include <libpq-fe.h>


#if defined OS_WINDOWS
	#pragma comment(lib, "libpq.lib")
#endif








NS_ECILA_START

class DECL_SPEC_DLL PostgreSQLHandle
:	public IDBHandle
{
public:
	enum { DEFAULT_PORT		= 5432, };
	
			 PostgreSQLHandle();
	virtual ~PostgreSQLHandle();


private:
	PGconn		*handle_;
	PGresult	*result_;
	int32_t		row_index_;

	virtual bool_t	Connect		(DBConnI &dbci);
	virtual bool_t	Disconnect	();
	virtual bool_t	Execute		(const char_t *fmt, ...);
	virtual bool_t	Fetch		();
	virtual char_t*	GetValue	(uint32_t idx);
	virtual char_t* GetValue    (const char_t *field_name) { ECILA_TRACE(); return 0; }

	void Clear();
};

NS_ECILA_END

