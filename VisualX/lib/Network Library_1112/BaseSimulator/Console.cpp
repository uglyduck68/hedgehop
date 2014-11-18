#include "StdAfx.h"
#include "Console.h"


CConsole::CConsole(void)
{
	// 초기화
	AllocConsole();
	int hCrtout = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE),_O_TEXT);
	FILE *hout = _fdopen(hCrtout,"w");
	*stdout = *hout;
	int hCrtin = _open_osfhandle((long)GetStdHandle(STD_INPUT_HANDLE),O_TEXT);
	FILE *hin = _fdopen(hCrtin,"r");
	*stdin = *hin;
	setvbuf(stdin, NULL,_IONBF,0);
	FreeConsole();
}


CConsole::~CConsole(void)
{
	// 해제
	_fcloseall();
}


void CConsole::OpenConsole()
{
	if(AllocConsole()){
		SetConsoleTitle("Log Console");
		printf("Console Log System \n");
	}
}
void CConsole::CloseConsole()
{
	FreeConsole();
}