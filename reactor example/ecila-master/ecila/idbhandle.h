#pragma once


#include "ecila.h"








NS_ECILA_START

class DECL_SPEC_DLL DBConnI
{
public:
	enum ENUM_MAX { MAX_STRING_LEN = 80, };

	char_t	host_	[MAX_STRING_LEN + 1];
	char_t	port_	[MAX_STRING_LEN + 1];
	char_t	user_	[MAX_STRING_LEN + 1];
	char_t	passwd_	[MAX_STRING_LEN + 1];
	char_t	db_		[MAX_STRING_LEN + 1];
	char_t	charset_[MAX_STRING_LEN + 1];



	DBConnI()
	{
		memset(host_,		0, sizeof(host_));
		memset(port_,		0, sizeof(port_));
		memset(user_,		0, sizeof(user_));
		memset(passwd_,		0, sizeof(passwd_));
		memset(db_,			0, sizeof(db_));
		memset(charset_,	0, sizeof(charset_));
	}

	 ~DBConnI() {}

	void Set(const char_t *host,	const char_t *port,
			 const char_t *user,	const char_t *passwd, 
			 const char_t *db,		const char_t *charset = "UTF8")
	{
		ecila_sprintf(host_,		sizeof(host_),		"%s", host);
		ecila_sprintf(port_,		sizeof(port_),		"%s", port);
		ecila_sprintf(user_,		sizeof(user_),		"%s", user);
		ecila_sprintf(passwd_,	sizeof(passwd_),	"%s", passwd);
		ecila_sprintf(db_,		sizeof(db_),		"%s", db);
		ecila_sprintf(charset_,	sizeof(charset_),	"%s", charset);
	}

	void operator =(DBConnI &ref)
	{
		ecila_strncpy(host_,		ref.host_,		sizeof(host_));
		ecila_strncpy(port_,		ref.port_,		sizeof(port_));
		ecila_strncpy(user_,		ref.user_,		sizeof(user_));
		ecila_strncpy(passwd_,	ref.passwd_,	sizeof(passwd_));
		ecila_strncpy(db_,		ref.db_,		sizeof(db_));
		ecila_strncpy(charset_,	ref.charset_,	sizeof(charset_));
	}
};








class DECL_SPEC_DLL IDBHandle
{
public:
    enum ENUM_MAX { MAX_QUERY_BUFFER_LEN = 4096, };

             IDBHandle();
    virtual ~IDBHandle();

    
    bool_t      IsConnected();
    int32_t     Error();
    uint64_t    RowCount();
    uint32_t    FieldCount();


    virtual bool_t    Connect     (DBConnI &dbci)             = 0;
    virtual bool_t    Disconnect  ()                          = 0;
    virtual bool_t    Execute     (const char_t *fmt, ...)    = 0;
    virtual bool_t    Fetch       ()                          = 0;
    virtual char_t*   GetValue    (uint32_t idx)              = 0;
	virtual char_t*   GetValue    (const char_t *field_name)  = 0;
    
    //Get Value Function
	int32_t  GetValueI32  (uint32_t idx) { char_t *ret = GetValue(idx); if(!ret) { ECILA_TRACE(); return 0; } else { return ecila_atoi32  (ret); } }
    uint32_t GetValueUI32 (uint32_t idx) { char_t *ret = GetValue(idx); if(!ret) { ECILA_TRACE(); return 0; } else { return ecila_atoui32 (ret); } }
    int64_t  GetValueI64  (uint32_t idx) { char_t *ret = GetValue(idx); if(!ret) { ECILA_TRACE(); return 0; } else { return ecila_atoi64  (ret); } }
    uint64_t GetValueUI64 (uint32_t idx) { char_t *ret = GetValue(idx); if(!ret) { ECILA_TRACE(); return 0; } else { return ecila_atoui64 (ret); } }
    float_t  GetValueF32  (uint32_t idx) { char_t *ret = GetValue(idx); if(!ret) { ECILA_TRACE(); return 0.0f; } else { return ecila_atof32  (ret); } }
    double_t GetValueF64  (uint32_t idx) { char_t *ret = GetValue(idx); if(!ret) { ECILA_TRACE(); return 0.0f; } else { return ecila_atof64  (ret); } }




protected:
    
    bool_t     connected_;
    int32_t    errno_;
    DBConnI    dbci_;

    uint64_t    num_rows_;
    uint32_t    num_fields_;
    uint32_t    len_query_;
    char_t      query_buffer_[MAX_QUERY_BUFFER_LEN + 1];

    bool        SetQuery(va_list args);
};

NS_ECILA_END
