#pragma once

#include <stdio.h>
#include <stdlib.h>

namespace X1
{
	class Log
	{
	private:
		static Log*	volatile m_pLog;
		FILE*		m_pFile;
		char		m_caFilePath[_MAX_PATH];
	protected:
		Log(void);

	public:
		~Log(void);

		static Log* GetInstance();
		void GetTimeStamp(char *cpTime);
		int Write(char *cpFormat, ...);
	};

}

