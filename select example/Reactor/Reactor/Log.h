#pragma once

#include <stdio.h>
#include <stdlib.h>

namespace X1
{
	class Log
	{
		enum 
		{
			LOG_SILENT		= (1 << 0),
			LOG_USE_STDOUT	= (1 << 1),
		};
	private:
		static Log*	volatile m_pLog;
		FILE*		m_pFile;
		static long		m_lMode;

	protected:
		Log(void);
		void GetTimeStamp(char *cpTime);

	public:
		~Log(void);

		static Log* GetInstance();

		int	Open(char* cpFileName);
		int	Open(FILE* pFile = stdout);
		int	Close();
		int Write(char* cpType, char* cpFilename, int nLineno, char *cpFormat, ...);

		int SetMode(long lMode);
	};

}


#define LOG_INFO(format,...)	Log::GetInstance()->Write("Info", __FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_WARNING(format,...)	Log::GetInstance()->Write("Warn", __FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_ERROR(format,...)	Log::GetInstance()->Write("Error", __FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_FATAL(format,...)	Log::GetInstance()->Write("Fatal", __FILE__, __LINE__, format, ##__VA_ARGS__)

#define LOG_INIT(filename)	do	\
	{	\
		if (Log::GetInstance()->Open(filename) != X1_OK)	\
		{	\
			printf("Error: fail to open %s. logging use stdout. reason is ", filename);	\
			perror("");	\
		}\
		else\
		{\
			LOG_INFO("### Logging Start ###\n");\
		}\
	} while (0);