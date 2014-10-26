#pragma once
#include <windows.h>
class QTimer
{
public:
	QTimer(void);
	~QTimer(void);

	void Start();
	void Stop();
	double GetElapsedTimeInSec();
	double GetElapsedTimeInMicroSec();
	double GetElapsedTimeInMilliSec();

private:
	LARGE_INTEGER m_Start;
	LARGE_INTEGER m_End;
	LARGE_INTEGER m_Freq;

	double m_StartTimeInMicroSec;
	double m_EndTimeInMicroSec;
	bool m_Stopped;
};

