#pragma once
#include <windows.h>
class QTimer
{
public:
	QTimer(void);
	~QTimer(void);

	void Start();
	__int64 Stop();
	double GetElapsedTimeInSec();
	double GetElapsedTimeInMicroSec();
	double GetElapsedTimeInMilliSec();
	double GetElapsedTimeInNanoSec();
private:
	QTimer(const QTimer &);
	const QTimer& operator =(const QTimer&);

	LARGE_INTEGER m_Start;
	LARGE_INTEGER m_End;
	LARGE_INTEGER m_Freq;
};

