#include "stdafx.h"
#include <atlbase.h>	// for CRegKey use
#include "CpuUsage.h"

#pragma pack(push,8)
#include "PerfCounters.h"
#pragma pack(pop)


# pragma comment(lib, "wbemuuid.lib")

#define SYSTEM_OBJECT_INDEX					2		// 'System' object
#define PROCESS_OBJECT_INDEX				230		// 'Process' object
#define PROCESSOR_OBJECT_INDEX				238		// 'Processor' object
#define TOTAL_PROCESSOR_TIME_COUNTER_INDEX	240		// '% Total processor time' counter (valid in WinNT under 'System' object)
#define PROCESSOR_TIME_COUNTER_INDEX		6		// '% processor time' counter (for Win2K/XP)

///////////////////////////////////////////////////////////////////
//
//		GetCpuUsage uses the performance counters to retrieve the
//		system cpu usage.
//		The cpu usage counter is of type PERF_100NSEC_TIMER_INV
//		which as the following calculation:
//
//		Element		Value 
//		=======		===========
//		X			CounterData 
//		Y			100NsTime 
//		Data Size	8 Bytes
//		Time base	100Ns
//		Calculation 100*(1-(X1-X0)/(Y1-Y0)) 
//
//      where the denominator (Y) represents the total elapsed time of the 
//      sample interval and the numerator (X) represents the time during 
//      the interval when the monitored components were inactive.
//
//
//		Note:
//		====
//		On windows NT, cpu usage counter is '% Total processor time'
//		under 'System' object. However, in Win2K/XP Microsoft moved
//		that counter to '% processor time' under '_Total' instance
//		of 'Processor' object.
//		Read 'INFO: Percent Total Performance Counter Changes on Windows 2000'
//		Q259390 in MSDN.
//
///////////////////////////////////////////////////////////////////

typedef enum
{
	WINNT,	WIN2K_XP, WIN9X, UNKNOWN
}PLATFORM;

PLATFORM GetPlatform()
{
	OSVERSIONINFO osvi;
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	if (!GetVersionEx(&osvi))
		return UNKNOWN;
	switch (osvi.dwPlatformId)
	{
	case VER_PLATFORM_WIN32_WINDOWS:
		return WIN9X;
	case VER_PLATFORM_WIN32_NT:
		if (osvi.dwMajorVersion == 4)
			return WINNT;
		else
			return WIN2K_XP;
	}
	return UNKNOWN;
}

int	CCpuUsage::InitWMI()
{
	HRESULT hres;

	// Step 1: --------------------------------------------------
	// Initialize COM. ------------------------------------------

	hres =  CoInitializeEx(0, COINIT_MULTITHREADED); 
	if (FAILED(hres))
	{
		return 1;                  // Program has failed.
	}

	// Step 2: --------------------------------------------------
	// Set general COM security levels --------------------------

	hres =  CoInitializeSecurity(
		NULL, 
		-1,                          // COM authentication
		NULL,                        // Authentication services
		NULL,                        // Reserved
		RPC_C_AUTHN_LEVEL_DEFAULT,   // Default authentication 
		RPC_C_IMP_LEVEL_IMPERSONATE, // Default Impersonation  
		NULL,                        // Authentication info
		EOAC_NONE,                   // Additional capabilities 
		NULL                         // Reserved
		);


	if (FAILED(hres))
	{
		CoUninitialize();
		return 1;                    // Program has failed.
	}

	// Step 3: ---------------------------------------------------
	// Obtain the initial locator to WMI -------------------------

	pLoc = NULL;

	hres = CoCreateInstance(
		CLSID_WbemLocator,             
		0, 
		CLSCTX_INPROC_SERVER, 
		IID_IWbemLocator, (LPVOID *) &pLoc);

	if (FAILED(hres))
	{
		CoUninitialize();
		return 1;                 // Program has failed.
	}

	// Step 4: -----------------------------------------------------
	// Connect to WMI through the IWbemLocator::ConnectServer method

	pSvc = NULL;

	// Connect to the root\cimv2 namespace with
	// the current user and obtain pointer pSvc
	// to make IWbemServices calls.
	hres = pLoc->ConnectServer(
		_bstr_t(L"ROOT\\CIMV2"), // Object path of WMI namespace
		NULL,                    // User name. NULL = current user
		NULL,                    // User password. NULL = current
		0,                       // Locale. NULL indicates current
		NULL,                    // Security flags.
		0,                       // Authority (for example, Kerberos)
		0,                       // Context object 
		&pSvc                    // pointer to IWbemServices proxy
		);

	if (FAILED(hres))
	{
		pLoc->Release();     
		CoUninitialize();
		return 1;                // Program has failed.
	}


	// Step 5: --------------------------------------------------
	// Set security levels on the proxy -------------------------

	hres = CoSetProxyBlanket(
		pSvc,                        // Indicates the proxy to set
		RPC_C_AUTHN_WINNT,           // RPC_C_AUTHN_xxx
		RPC_C_AUTHZ_NONE,            // RPC_C_AUTHZ_xxx
		NULL,                        // Server principal name 
		RPC_C_AUTHN_LEVEL_CALL,      // RPC_C_AUTHN_LEVEL_xxx 
		RPC_C_IMP_LEVEL_IMPERSONATE, // RPC_C_IMP_LEVEL_xxx
		NULL,                        // client identity
		EOAC_NONE                    // proxy capabilities 
		);

	if (FAILED(hres))
	{
		pSvc->Release();
		pLoc->Release();     
		CoUninitialize();
		return 1;               // Program has failed.
	}

	// get the initial bytes total from NIC
	GetBandwidth();

	return 0;
}

int CCpuUsage::FiniWMI()
{
    // Cleanup
    // ========
    
    pSvc->Release();
    pLoc->Release();
    pEnumerator->Release();
    if(!pclsObj) pclsObj->Release();
    CoUninitialize();

	return 0;
}

int CCpuUsage::GetCpuUsageWMI()
{
	HRESULT hr;
	// Step 6: --------------------------------------------------
	// Use the IWbemServices pointer to make requests of WMI ----

	// For example, get the name of the operating system
	pEnumerator = NULL;

	hr = pSvc->ExecQuery(
		bstr_t("WQL"), 
//        bstr_t("SELECT * FROM Win32_OperatingSystem"),
//        bstr_t("SELECT * FROM Win32_Process"),
		bstr_t("SELECT * FROM Win32_Processor"),
		//        bstr_t("SELECT * FROM Win32_PerfRawData_PerfOS_Processor WHERE Name = '_Total'"),
		WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, 
		NULL,
		&pEnumerator);

	if (FAILED(hr))
	{
		pSvc->Release();
		pLoc->Release();
		CoUninitialize();
		return 1;               // Program has failed.
	}

	// Step 7: -------------------------------------------------
	// Get the data from the query in step 6 -------------------
	ULONG uReturn = 0;

	while (pEnumerator)
	{
		VARIANT vtProp;

		HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1, 
				&pclsObj, &uReturn);

		if (FAILED(hr))
		{
			pclsObj->Release();
			return -1;
		}

		if(0 == uReturn)
		{
			return -1;
		}

		// Get the value of the Name property
		VariantClear(&vtProp);

		/*
		* get CPU load percentage
		*/
		hr	= pclsObj->Get(L"LoadPercentage", 0L, &vtProp, 0, 0);
		
		return vtProp.lVal;
	}

	return -1;
}

int CCpuUsage::GetBandwidth()
{
	HRESULT hr;
	// Step 6: --------------------------------------------------
	// Use the IWbemServices pointer to make requests of WMI ----

	// For example, get the name of the operating system
	pEnumerator = NULL;

	hr = pSvc->ExecQuery(
		bstr_t("WQL"), 
//        bstr_t("SELECT * FROM Win32_OperatingSystem"),
//        bstr_t("SELECT * FROM Win32_Process"),
		bstr_t("SELECT * FROM  Win32_PerfRawData_Tcpip_NetworkInterface"),// WHERE name = 'Intel_R__82579V_Gigabit_Network_Connection'"),
		//        bstr_t("SELECT * FROM Win32_PerfRawData_PerfOS_Processor WHERE Name = '_Total'"),
		WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, 
		NULL,
		&pEnumerator);

	if (FAILED(hr))
	{
		pSvc->Release();
		pLoc->Release();
		CoUninitialize();
		return 1;               // Program has failed.
	}

	// Step 7: -------------------------------------------------
	// Get the data from the query in step 6 -------------------
	ULONG uReturn	= 0;
	int		nTotal	= 0;;

	while (pEnumerator)
	{
		VARIANT vtProp;
		VARIANT	vtCurrentBandwidth;
		VARIANT	vtTimestamp_Sys100NS;

		HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1, 
				&pclsObj, &uReturn);

		if (FAILED(hr))
		{
			pclsObj->Release();
			return -1;
		}

		if(0 == uReturn)
		{
			return -1;
		}

		// Get the value of the Name property
		VariantClear(&vtProp);
		VariantClear(&vtCurrentBandwidth);


		/*
		* get byte total that always increase.
		* byte total also has the lose packet.
		*/
		hr	= pclsObj->Get(L"BytesTotalPersec", 0L, &vtProp, 0, 0);
		hr	= pclsObj->Get(L"CurrentBandwidth", 0L, &vtCurrentBandwidth, 0, 0);
		hr	= pclsObj->Get(L"Timestamp_Sys100NS", 0L, &vtTimestamp_Sys100NS, 0, 0);

#if	0
		printf("bytes total per sec: %d    %d\n", vtProp.lVal, vtProp.lVal - m_nBytesTotalOld);
		printf("current bandwidth  : %d\n", vtCurrentBandwidth.lVal);

		// 2008 한국정보처리학회 추계학술발표대회 논문집 제15권 제2호
		// But 정확하게 계산이 되지 않는다.
		printf("calc bandwidth     : %6.3f\n", (1.0 - (double)vtProp.lVal / (vtCurrentBandwidth.lVal * 8.0)) * 100.0);
#endif

		if(m_nBytesTotalOld > -1)
		{
			// calc. the bytes between 2 periods
			nTotal	= vtProp.lVal - m_nBytesTotalOld;
		}


		// save the previous bytes total
		m_nBytesTotalOld	= vtProp.lVal;
		m_nTimeOld			= vtTimestamp_Sys100NS.llVal;

		if (nTotal < 0)
			// byte total always increase
			return -1;

		// calc. the percentage in Mbps unit
		// printf("bandwidth is %6.2f%%\n", (cpu.GetBandwidth() * 8 * 100) / (100.0*MEGA));

		return nTotal;
	}

	return -1;
}

CCpuUsage::CCpuUsage(bool bWMI) : m_bWMI(bWMI)
{
	m_bFirstTime = true;
	m_lnOldValue = 0;
	memset(&m_OldPerfTime100nSec, 0, sizeof(m_OldPerfTime100nSec));

	if (m_bWMI)
	{
		InitWMI();
	}
	
	m_nBytesTotalOld	= -1;
}

CCpuUsage::~CCpuUsage()
{
	if (m_bWMI)
	{
		FiniWMI();
	}
}

BOOL CCpuUsage::EnablePerformaceCounters(BOOL bEnable)
{
	if (GetPlatform() != WIN2K_XP)
		return TRUE;

	CRegKey regKey;
	if (regKey.Open(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Services\\PerfOS\\Performance") != ERROR_SUCCESS)
		return FALSE;

	regKey.SetValue(!bEnable, "Disable Performance Counters");
	regKey.Close();

	if (regKey.Open(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Services\\PerfProc\\Performance") != ERROR_SUCCESS)
		return FALSE;

	regKey.SetValue(!bEnable, "Disable Performance Counters");
	regKey.Close();

	return TRUE;
}

//
//	GetCpuUsage returns the system-wide cpu usage.
//	Since we calculate the cpu usage by two samplings, the first
//	call to GetCpuUsage() returns 0 and keeps the values for the next
//	sampling.
//  Read the comment at the beginning of this file for the formula.
//
int CCpuUsage::GetCpuUsage()
{
	if (m_bWMI)
		return GetCpuUsageWMI();

	static PLATFORM Platform = GetPlatform();

	if (m_bFirstTime)
		EnablePerformaceCounters();
	
	// Cpu usage counter is 8 byte length.
	CPerfCounters<LONGLONG> PerfCounters;
	char szInstance[256] = {0};

//		Note:
//		====
//		On windows NT, cpu usage counter is '% Total processor time'
//		under 'System' object. However, in Win2K/XP Microsoft moved
//		that counter to '% processor time' under '_Total' instance
//		of 'Processor' object.
//		Read 'INFO: Percent Total Performance Counter Changes on Windows 2000'
//		Q259390 in MSDN.

	DWORD dwObjectIndex;
	DWORD dwCpuUsageIndex;
	switch (Platform)
	{
	case WINNT:
		dwObjectIndex = SYSTEM_OBJECT_INDEX;
		dwCpuUsageIndex = TOTAL_PROCESSOR_TIME_COUNTER_INDEX;
		break;
	case WIN2K_XP:
		dwObjectIndex = PROCESSOR_OBJECT_INDEX;
		dwCpuUsageIndex = PROCESSOR_TIME_COUNTER_INDEX;
		strcpy(szInstance,"_Total");
		break;
	default:
		return -1;
	}

	int				CpuUsage = 0;
	LONGLONG		lnNewValue = 0;
	PPERF_DATA_BLOCK pPerfData = NULL;
	LARGE_INTEGER	NewPerfTime100nSec = {0};

	lnNewValue = PerfCounters.GetCounterValue(&pPerfData, dwObjectIndex, dwCpuUsageIndex, szInstance);
	NewPerfTime100nSec = pPerfData->PerfTime100nSec;

	if (m_bFirstTime)
	{
		m_bFirstTime = false;
		m_lnOldValue = lnNewValue;
		m_OldPerfTime100nSec = NewPerfTime100nSec;
		return 0;
	}

	LONGLONG lnValueDelta = lnNewValue - m_lnOldValue;
	double DeltaPerfTime100nSec = (double)NewPerfTime100nSec.QuadPart - (double)m_OldPerfTime100nSec.QuadPart;

	m_lnOldValue = lnNewValue;
	m_OldPerfTime100nSec = NewPerfTime100nSec;

	double a = (double)lnValueDelta / DeltaPerfTime100nSec;

	double f = (1.0 - a) * 100.0;
	CpuUsage = (int)(f + 0.5);	// rounding the result
	if (CpuUsage < 0)
		return 0;
	return CpuUsage;
}

int CCpuUsage::GetCpuUsage(LPCTSTR pProcessName)
{
	static PLATFORM Platform = GetPlatform();
	
	if (m_bFirstTime)
		EnablePerformaceCounters();

	// Cpu usage counter is 8 byte length.
	CPerfCounters<LONGLONG> PerfCounters;
	char szInstance[256] = {0};


	DWORD dwObjectIndex = PROCESS_OBJECT_INDEX;
	DWORD dwCpuUsageIndex = PROCESSOR_TIME_COUNTER_INDEX;
	strcpy(szInstance,pProcessName);

	int				CpuUsage = 0;
	LONGLONG		lnNewValue = 0;
	PPERF_DATA_BLOCK pPerfData = NULL;
	LARGE_INTEGER	NewPerfTime100nSec = {0};

	lnNewValue = PerfCounters.GetCounterValue(&pPerfData, dwObjectIndex, dwCpuUsageIndex, szInstance);
	NewPerfTime100nSec = pPerfData->PerfTime100nSec;

	if (m_bFirstTime)
	{
		m_bFirstTime = false;
		m_lnOldValue = lnNewValue;
		m_OldPerfTime100nSec = NewPerfTime100nSec;
		return 0;
	}

	LONGLONG lnValueDelta = lnNewValue - m_lnOldValue;
	double DeltaPerfTime100nSec = (double)NewPerfTime100nSec.QuadPart - (double)m_OldPerfTime100nSec.QuadPart;

	m_lnOldValue = lnNewValue;
	m_OldPerfTime100nSec = NewPerfTime100nSec;

	double a = (double)lnValueDelta / DeltaPerfTime100nSec;

	CpuUsage = (int) (a*100);
	if (CpuUsage < 0)
		return 0;
	return CpuUsage;
}


int CCpuUsage::GetCpuUsage(DWORD dwProcessID)
{
	static PLATFORM Platform = GetPlatform();
	
	if (m_bFirstTime)
		EnablePerformaceCounters();

	// Cpu usage counter is 8 byte length.
	CPerfCounters<LONGLONG> PerfCounters;


	DWORD dwObjectIndex = PROCESS_OBJECT_INDEX;
	DWORD dwCpuUsageIndex = PROCESSOR_TIME_COUNTER_INDEX;

	int				CpuUsage = 0;
	LONGLONG		lnNewValue = 0;
	PPERF_DATA_BLOCK pPerfData = NULL;
	LARGE_INTEGER	NewPerfTime100nSec = {0};

	lnNewValue = PerfCounters.GetCounterValueForProcessID(&pPerfData, dwObjectIndex, dwCpuUsageIndex, dwProcessID);
	NewPerfTime100nSec = pPerfData->PerfTime100nSec;

	if (m_bFirstTime)
	{
		m_bFirstTime = false;
		m_lnOldValue = lnNewValue;
		m_OldPerfTime100nSec = NewPerfTime100nSec;
		return 0;
	}

	LONGLONG lnValueDelta = lnNewValue - m_lnOldValue;
	double DeltaPerfTime100nSec = (double)NewPerfTime100nSec.QuadPart - (double)m_OldPerfTime100nSec.QuadPart;

	m_lnOldValue = lnNewValue;
	m_OldPerfTime100nSec = NewPerfTime100nSec;

	double a = (double)lnValueDelta / DeltaPerfTime100nSec;

	CpuUsage = (int) (a*100);
	if (CpuUsage < 0)
		return 0;
	return CpuUsage;
}

