//
// FPEnvironment_C99.h
//
// $Id: //poco/1.4/Foundation/include/Poco/FPEnvironment_C99.h#1 $
//
// Library: Foundation
// Package: Core
// Module:  FPEnvironment
//
// Definitions of class FPEnvironmentImpl for C99.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_FPEnvironment_C99_INCLUDED
#define Foundation_FPEnvironment_C99_INCLUDED


#include "Poco/Foundation.h"
#include <fenv.h>
#include <cmath>


namespace Poco {


class FPEnvironmentImpl
{
protected:
	enum RoundingModeImpl
	{
		FP_ROUND_DOWNWARD_IMPL   = FE_DOWNWARD,
		FP_ROUND_UPWARD_IMPL     = FE_UPWARD,
		FP_ROUND_TONEAREST_IMPL  = FE_TONEAREST,
		FP_ROUND_TOWARDZERO_IMPL = FE_TOWARDZERO
	};
	enum FlagImpl
	{
		FP_DIVIDE_BY_ZERO_IMPL = FE_DIVBYZERO,
		FP_INEXACT_IMPL        = FE_INEXACT,
		FP_OVERFLOW_IMPL       = FE_OVERFLOW,
		FP_UNDERFLOW_IMPL      = FE_UNDERFLOW,
		FP_INVALID_IMPL        = FE_INVALID
	};
	FPEnvironmentImpl();
	FPEnvironmentImpl(const FPEnvironmentImpl& env);
	~FPEnvironmentImpl();
	FPEnvironmentImpl& operator = (const FPEnvironmentImpl& env);
	void keepCurrentImpl();		
	static void clearFlagsImpl();
	static bool isFlagImpl(FlagImpl flag);	
	static void setRoundingModeImpl(RoundingModeImpl mode);
	static RoundingModeImpl getRoundingModeImpl();
	static long double copySignImpl(long double target, long double source);

	//hy.lee	lignex1 
	//	static bool isInfiniteImpl(float value);		
	//	static bool isInfiniteImpl(double value);
	//	static bool isInfiniteImpl(long double value);
//	static bool isNaNImpl(float value);		
//	static bool isNaNImpl(double value);
//	static bool isNaNImpl(long double value);
//	static float copySignImpl(float target, float source);		
//	static double copySignImpl(double target, double source);

	//
	// inlines
	//
	static inline bool isInfiniteImpl(float value)
	{
		//@ vxworks-6.8 compiler version is 4.1
#if defined(POCO_COMPILER_GCC) && (((__GNUC__ * 100) + __GNUC_MINOR__) >= 406)
		return std::isinf(value) != 0;
#else
		return isinf(value) != 0;
#endif
	}


	static inline bool isInfiniteImpl(double value)
	{
		//@ vxworks-6.8 compiler version is 4.1
#if defined(POCO_COMPILER_GCC) && (((__GNUC__ * 100) + __GNUC_MINOR__) >= 406)
		return std::isinf(value) != 0;
#else
		return isinf(value) != 0;
#endif
	}


	static inline bool isInfiniteImpl(long double value)
	{
		//@ vxworks-6.8 compiler version is 4.1
#if defined(POCO_COMPILER_GCC) && (((__GNUC__ * 100) + __GNUC_MINOR__) >= 406)
		return std::isinf((double) value) != 0;
#else
		return isinf((double) value) != 0;
#endif
	}


	static inline bool isNaNImpl(float value)
	{
		//@ vxworks-6.8 compiler version is 4.1
#if defined(POCO_COMPILER_GCC) && (((__GNUC__ * 100) + __GNUC_MINOR__) >= 406)
		return std::isnan(value) != 0;
#else
		return isnan(value) != 0;
#endif
	}


	static inline bool isNaNImpl(double value)
	{
		//@ vxworks-6.8 compiler version is 4.1
#if defined(POCO_COMPILER_GCC) && (((__GNUC__ * 100) + __GNUC_MINOR__) >= 406)
		return std::isnan(value) != 0;
#else
		return isnan(value) != 0;
#endif
	}


	static inline bool isNaNImpl(long double value)
	{
		//@ vxworks-6.8 compiler version is 4.1
#if defined(POCO_COMPILER_GCC) && (((__GNUC__ * 100) + __GNUC_MINOR__) >= 406)
		return std::isnan((double) value) != 0;
#else
		return isnan((double) value) != 0;
#endif
	}


	static inline float copySignImpl(float target, float source)
	{
		return copysignf(target, source);
	}


	static inline double copySignImpl(double target, double source)
	{
		return copysign(target, source);
	}

private:
	fenv_t _env;
};



} // namespace Poco


#endif // Foundation_FPEnvironment_C99_INCLUDED
