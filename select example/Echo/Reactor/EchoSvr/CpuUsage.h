#ifndef _CPUUSAGE_H
#define _CPUUSAGE_H

#include <windows.h>

// for WMI
#include <comdef.h>
#include <Wbemidl.h>


class CCpuUsage
{
public:
	CCpuUsage(bool bWMI = 1);
	virtual ~CCpuUsage();

// Methods
	int GetCpuUsage();
	int GetCpuUsage(LPCTSTR pProcessName);
	int GetCpuUsage(DWORD dwProcessID);

	BOOL EnablePerformaceCounters(BOOL bEnable = TRUE);

	/**
	* WMI must be initialized.
	* return current bandwidth
	*/
	int	GetBandwidth();

// Attributes
private:

	bool			m_bFirstTime;
	LONGLONG		m_lnOldValue ;
	LARGE_INTEGER	m_OldPerfTime100nSec;

	/**
	* for WMI
	*	This also has some differencs when compared to Task Manager
	*/
	int	InitWMI();
	int FiniWMI();
	int GetCpuUsageWMI();
	IWbemLocator*			pLoc;
	IWbemServices*			pSvc;
	IEnumWbemClassObject*	pEnumerator;
	IWbemClassObject*		pclsObj;

	bool			m_bWMI;

	int				m_nBytesTotalOld;
	LONGLONG		m_nTimeOld;

};


#endif