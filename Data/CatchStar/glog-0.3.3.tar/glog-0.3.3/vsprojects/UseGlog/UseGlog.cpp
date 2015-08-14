// UseGlog.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <config.h>
#include <glog/logging.h>

using namespace	google;


struct NullLogger : public base::Logger 
{
	virtual void Write(bool should_flush,
		time_t timestamp,
		const char* message,
		int length) 
	{
	}

	virtual void Flush() { }

	virtual uint32 LogSize() { return 0; }
};

void SetMyLogger(int severity, base::Logger* logger)
{
	base::Logger* old_logger = base::GetLogger(severity);
	base::SetLogger(severity, logger);
	FlushLogFiles(severity);
}

void	SetAllLogToFile(const char* pcLogFile)
{
	for (google::LogSeverity s = INFO/*WARNING*/; s < google::NUM_SEVERITIES; s++)
		google::SetLogDestination(s, "");

	google::SetLogDestination(INFO, pcLogFile);
}

int _tmain(int argc, _TCHAR* argv[])
{
	google::InitGoogleLogging(argv[0]);
	NullLogger null_logger;


#if	0
	SetLogDestination(INFO, "c:\\temp\\aa.log"); 

	SetMyLogger(WARNING, &null_logger);
	SetMyLogger(ERROR, &null_logger);
	SetMyLogger(FATAL, &null_logger);
#endif

	// following make "bb.log.log-...
	//	-> I modify "LogFileObject::CreateLogfile"
	SetLogFilenameExtension(".log");

	// add all logs to one file
	//	-> fail. just info log is written
	//	-> pass. modify some code
	SetAllLogToFile("c:\\bb-");

	// ...
	LOG(INFO) << "Found : INFO" << " cookies";
	LOG(WARNING) << "Found : WARNING" << " cookies";
	LOG(ERROR) << "Found : ERROR" << " cookies";	// only this is out to stderr & file!!!
//	LOG(FATAL) << "Found : FATAL" << " cookies";	// this cause stack trace error

	for(int i = 0; i < 20; i++)
	{
		LOG_IF(INFO, i > 10) << "LOG_IF: INFO: i is " << i;

		// 
		LOG_EVERY_N(INFO, 10) << "LOG_EVERY_N: i is " << i << " counter: " << google::COUNTER;

		LOG_IF_EVERY_N(INFO, i > 10, 10) << "LOG_IF_EVERY_N: i is " << i << " counter: " << google::COUNTER;
	}

	return 0;
}

