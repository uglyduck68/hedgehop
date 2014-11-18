#pragma once
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define DEBUG_PRINT(x) printf("%s - Value : %ld[0x%lx], Address : 0x%lx\n",#x,x,x,&x)

class CConsole
{
public:
	CConsole(void);
	~CConsole(void);

	void OpenConsole();
	void CloseConsole();
};

