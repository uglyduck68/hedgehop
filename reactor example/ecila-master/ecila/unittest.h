#pragma once

#include "ecila.h"

#include <cassert>
#include <sstream>





#if defined (OS_WINDOWS)
	#define assertEquals(x, y)		do { this->ResultInst()->AssertEquals	(__FUNCTION__, __LINE__, #x, #y, x, y); }	while(0,0);
	#define assertNotEquals(x, y)	do { this->ResultInst()->AssertNotEquals(__FUNCTION__, __LINE__, #x, #y, x, y); }	while(0,0);
	#define assertNull(x)			do { this->ResultInst()->AssertNull		(__FUNCTION__, __LINE__, #x, x); }			while(0,0);
	#define assertNotNull(x)		do { this->ResultInst()->AssertNotNull	(__FUNCTION__, __LINE__, #x, x); }			while(0,0);
#else
	#define assertEquals(x, y)		do { this->ResultInst()->AssertEquals	(__PRETTY_FUNCTION__, __LINE__, #x, #y, x, y); }	while(0);
	#define assertNotEquals(x, y)	do { this->ResultInst()->AssertNotEquals(__PRETTY_FUNCTION__, __LINE__, #x, #y, x, y); }	while(0);
	#define assertNull(x)			do { this->ResultInst()->AssertNull		(__PRETTY_FUNCTION__, __LINE__, #x, x); }			while(0);
	#define assertNotNull(x)		do { this->ResultInst()->AssertNotNull	(__PRETTY_FUNCTION__, __LINE__, #x, x); }			while(0);
#endif






NS_ECILA_START

class TestResult
{
public:
	uint32_t			success_cnt_;
	uint32_t			failure_cnt_;
	std::stringstream	failure_str_;


public:
	 TestResult() { success_cnt_ = 0; failure_cnt_ = 0; }
	~TestResult() { }

	template < typename EXPECTED_V, typename ACTUALLY_V >
	void AssertEquals(const char_t	*function,
					  uint32_t		line,
					  const char_t	*e_exp,
					  const char_t	*a_exp,
					  EXPECTED_V	e_val,
					  ACTUALLY_V	a_val)
	{
		if(e_val != a_val)
		{
			failure_cnt_++;

			failure_str_ << "Failure [" << function << ":" << line << "] :" << std::endl;
			failure_str_ << "\t expression [" << e_exp << " == " << a_exp << "], ";
			failure_str_ << "expected [" << e_val << "], actually [" << a_val << "]" << std::endl;
		}
		else
		{
			success_cnt_++;
		}
	}

	template < typename EXPECTED_V, typename ACTUALLY_V >
	void AssertNotEquals(const char_t	*function,
						 uint32_t		line,
						 const char_t	*e_exp,
						 const char_t	*a_exp,
						 EXPECTED_V		e_val,
						 ACTUALLY_V		a_val)
	{
		if(e_val == a_val)
		{
			failure_cnt_++;

			failure_str_ << "Failure [" << function << ":" << line << "] :" << std::endl;
			failure_str_ << "\t expression [" << e_exp << " != " << a_exp << "], ";
			failure_str_ << "expected [NOT " << e_val << "], actually [" << a_val << "]" << std::endl;
		}
		else
		{
			success_cnt_++;
		}
	}

	template < typename ACTUALLY_V >
	void AssertNull(const char_t	*function,
					uint32_t		line,
					const char_t	*a_exp,
					ACTUALLY_V		a_val)
	{
		if(NULL != a_val)
		{
			failure_cnt_++;

			char_t pointer[80] = {0, };
			ecila_sprintf(pointer, sizeof(pointer), "0x%p", a_val);

			failure_str_ << "Failure [" << function << ":" << line << "] :" << std::endl;
			failure_str_ <<"\t expression [NULL == " << a_exp << "], ";
			failure_str_ <<"expected [NULL], actually [" << pointer << "]" << std::endl;
		}
		else
		{
			success_cnt_++;
		}
	}

	template < typename ACTUALLY_V >
	void AssertNotNull(const char_t *function, uint32_t line, const char_t *a_exp, ACTUALLY_V a_val)
	{
		if(NULL == a_val)
		{
			failure_cnt_++;

			failure_str_ << "Failure [" << function << ":" << line << "] :" << std::endl;
			failure_str_ << "\t expression [NULL != " << a_exp << "], ";
			failure_str_ << "expected [NOT NULL], actually [NULL]" << std::endl;
		}
		else
		{
			success_cnt_++;
		}
	}
};







class UnitTest
{
private:
	enum ENUM_MAX { MAX_NAME_LEN = 255, };

protected:
	char_t			name_[MAX_NAME_LEN + 1];
	bool_t			was_run_;
	TestResult		result_;


public:
	UnitTest(const char_t *name = "UnitTest")
	{
		memset(name_, 0, sizeof(name_));
		ecila_strncpy(name_, name, sizeof(name_));

		was_run_ = 0;
	}

	virtual ~UnitTest() {}


public:

	void Run()
	{
		SetUp	();
		Do		();
		TearDown();

		was_run_ = TRUE;
	}

	TestResult*		ResultInst()	{ return &result_; }

	virtual void SetUp		() {}
	virtual void TearDown	() {}
	virtual void Do			() = 0;

};

NS_ECILA_END

