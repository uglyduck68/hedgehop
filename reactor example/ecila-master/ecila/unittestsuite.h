#pragma once


#include <list>
#include <iostream>
#include "unittest.h"
#include "timer.h"







NS_ECILA_START

class UnitTestSuite
{
private:
	enum ENUM_MAX { MAX_NAME_LEN = 255, };

	typedef std::list< UnitTest * >		LIST_T;
	typedef LIST_T::iterator			ITER_T;

	LIST_T			list_;
	char_t			name_[MAX_NAME_LEN + 1];
	TestResult		result_;
	Time::TICK32	elapsed_time_;


public:
	UnitTestSuite(const char_t *name = "UnitTestSuite")
	{
		memset(name_, 0, sizeof(name_));
		ecila_strncpy(name_, name, sizeof(name_));
		elapsed_time_	= 0;
	}

	~UnitTestSuite()
	{
		for(ITER_T iter = list_.begin(); iter != list_.end(); ++iter)
		{
			UnitTest *tc = (UnitTest *)*iter;

			ECILA_SAFE_DELETE(tc);
		}

		list_.clear();
	}

	bool_t Register(UnitTest *tc)
	{
		if(!tc) { ECILA_TRACE(); return FALSE; }

		list_.push_back(tc);
		return TRUE;
	}
	 
	void Run()
	{
		for(ITER_T iter = list_.begin(); iter != list_.end(); ++iter)
		{
			UnitTest *tc = (UnitTest *)*iter;
			if(!tc) { ECILA_TRACE(); continue; }

			Timer32 timer;
			timer.Start();
			tc->Run();
			timer.End();

			result_.success_cnt_	+= tc->ResultInst()->success_cnt_;
			result_.failure_cnt_	+= tc->ResultInst()->failure_cnt_;
			elapsed_time_			+= timer.ElapsedTick();

			if(tc->ResultInst()->failure_cnt_ > 0)
			{
				std::cout << tc->ResultInst()->failure_str_.str();
			}
		}

		std::cout << "\r\n\r\nResult [" << name_ << "], TestCase[" << list_.size() << "] success [" << result_.success_cnt_ << "], failure [" << result_.failure_cnt_ << "] " << "elapsed time [" << elapsed_time_ << " ms]"  << std::endl;
	}
};

NS_ECILA_END

