#include "X1.h"
#include "Log.h"
#include "Lock.h"

namespace X1
{
	Log* volatile Log::m_pLog	= NULL;

	Log::Log(void)
	{
		m_pLog	= NULL;
		m_pFile	= NULL;
	}


	Log::~Log(void)
	{
		delete this;
	}

	Log* Log::GetInstance()
	{
		/**
		 * NOTE: should apply Double Checked Locking
		 */
		if (m_pLog == NULL)
		{
			Lock		lock;	// scoped locking
			if (m_pLog == NULL)
				m_pLog	= new Log;
		}

		return m_pLog;
	}

	void	Log::GetTimeStamp(char *cpTime)
	{
#if	defined(_X1_WINDOWS_)
		SYSTEMTIME		st;

		GetLocalTime(&st);

		sprintf(cpTime, "%04d%02d%02d, %02d:%02d:%02d", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
#elif	defined(_X1_LINUX_)
		time_t		t;
		struct tm	*tp;

		t	= time(NULL);
		tp	= localtime(&t);

		sprintf(cpTime, "%02d:%02d:%02d", tp->tm_hour, tp->tm_min, tp->tm_sec);
#endif
	}

	int Log::Write(char* cpFormat, ...)
	{
		va_list		marker;

		char	caTimeStamp[64];
		char	caLine[1024];
		int		nRet;

//		if(OpenLogFile(m_caFileName) == 0)
//			return 0;

		GetTimeStamp(caTimeStamp);

		va_start(marker, cpFormat);
		vsprintf(caLine, cpFormat, marker);
		va_end(marker);

		nRet = fprintf(m_pFile, "%s\n", caLine);

		fflush(m_pFile);

		return nRet;		return 0;
	}
}
