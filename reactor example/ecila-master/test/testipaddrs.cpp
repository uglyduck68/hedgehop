#include "testipaddrs.h"


#include <ecila/ipaddrs.h>







void TestIPAddrs::Do()
{
	std::string ip = "192.168.0.1";

	IPAddrs ipaddrs;

	assertEquals(TRUE, ipaddrs.Init(ip.c_str(), 10));
	assertEquals(ip, ipaddrs.Ip());
	assertEquals(10, ipaddrs.Port());
}

