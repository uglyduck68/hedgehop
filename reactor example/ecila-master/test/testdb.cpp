#include "testdb.h"

#include <ecila/postgresqlhandle.h>
#include <ecila/mysqlhandle.h>







void TestDb::Do()
{
	DBConnI dbci;
	//dbci.Set("192.168.3.15", "5432", "postgres", "qwer4321", "postgres");
	//IDBHandle *h = new PostgreSQLHandle();
	dbci.Set("192.168.1.138", "3306", "candoit", "cingyu", "tcsng_game");
	IDBHandle *h = new MySQLHandle();

	assertEquals(TRUE, h->Connect(dbci));
	//assertEquals(TRUE, h->Execute("call select_sum(1,2,@s)"));
	assertEquals(TRUE, h->Execute("INSERT INTO tbl_msgs VALUES(0,0,0,'한글','ちちちち','abc',NOW(),NOW())"));
	//assertEquals(TRUE, h->Fetch());

//	while(h->Fetch())
//	{
//		printf("%s %s %s\n", h->GetValue("deck_uidx"), h->GetValue("user_uidx"), h->GetValue("deck_name"), h->GetValue("c_date"));
//	}
	//assertEquals(4, h->GetValueI32(0));
	//assertEquals(3, h->GetValueI32(0));
	//assertEquals(TRUE, h->Disconnect());


	ECILA_SAFE_DELETE(h);
}

