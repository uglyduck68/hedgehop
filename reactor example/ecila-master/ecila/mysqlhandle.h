#pragma once


#include "idbhandle.h"
#include <mysql.h>
#include <map>
#include <string>


#if defined OS_WINDOWS
	#pragma comment(lib, "libmysql.lib")
#endif








NS_ECILA_START

class DECL_SPEC_DLL MySQLHandle
:	public IDBHandle
{
public:
	enum ENUM_DEFAULT { DEFAULT_PORT = 3306, };

			 MySQLHandle();
	virtual ~MySQLHandle();



private:
	typedef std::map<std::string /* column name */, uint32_t /* column index */> MAP_T;
	typedef MAP_T::iterator														 ITER_T;

	MYSQL			handle_;
	MYSQL_RES		*result_;
	MYSQL_ROW		row_;
	MYSQL_FIELD		*field_;
	MAP_T			field_asoc_;

	virtual bool_t	Connect		(DBConnI &dbci);
	virtual bool_t	Disconnect	();
	virtual bool_t	Execute		(const char_t *fmt, ...);
	virtual bool_t	Fetch		();
	virtual char_t*	GetValue	(uint32_t idx);
	virtual char_t* GetValue    (const char_t* field_name);


	void	Clear		();
	bool_t	FetchRow	();
	bool_t	FetchField	();
};

NS_ECILA_END

