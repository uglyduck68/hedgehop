#include "X1.h"
#include "Log.h"
#include "Lock.h"

namespace X1
{
	Log* volatile Log::m_pLog	= NULL;
	long Log::m_lMode			= 0;

	Log::Log(void)
	{
		m_pLog	= NULL;
		m_pFile	= NULL;
		m_lMode	= LOG_USE_STDOUT;
	}


	Log::~Log(void)
	{
		Close();

		DEL(m_pLog);
	}

	int Log::SetMode(long lMode)
	{
		long	lModeOld	= m_lMode;

		m_lMode		= lMode;

		return lModeOld;
	}

	Log* Log::GetInstance()
	{
		/**
		 * NOTE: should apply Double Checked Locking
		 */
		if (m_pLog == NULL)
		{
			Lock		lock;	// scoped locking -> change to use Guard
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

	int	Log::Open(FILE* pFile /* = stdout */)
	{
		if (pFile)
			m_pFile	= pFile;

		return X1_OK;
	}

	int	Log::Open(char* cpFileName)
	{
		if (cpFileName)
		{
			m_pFile	= fopen(cpFileName, "a");

			if (m_pFile)
				fseek(m_pFile, 0, SEEK_END);
			else
				return X1_EFILEOPEN;
		}

		return X1_OK;
	}

	int	Log::Close()
	{
		if (m_pFile)
		{
			fclose(m_pFile);
			m_pFile		= NULL;
		}

		return X1_OK;
	}

	int Log::Write(char* cpType, char* cpFilename, int nLineno, char* cpFormat, ...)
	{
		if (m_lMode & LOG_SILENT)
			return X1_OK;

		va_list		marker;

//		char	caTimeStamp[64];
		char	caLine[1024];
		int		nRet;

		// FIXME: lock is required to protect file writing in multi threading

//		GetTimeStamp(caTimeStamp);

		va_start(marker, cpFormat);
		vsprintf(caLine, cpFormat, marker);
		va_end(marker);

		if (m_pFile)
		{
			nRet = fprintf(m_pFile, "[%s %s]:%s: @(%s:%d): %s", 
				__DATE__, __TIME__, cpType, cpFilename, nLineno, caLine);

			fflush(m_pFile);
		}
		
		if (m_lMode & LOG_USE_STDOUT)
		{
			/// default logging use stdout
			nRet = fprintf(stdout, "[%s %s]:%s: @(%s:%d): %s", 
				__DATE__, __TIME__, cpType, cpFilename, nLineno, caLine);

			fflush(stdout);
		}


		return nRet;;
	}
}
