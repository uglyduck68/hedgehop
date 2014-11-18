#include "StdAfx.h"
#include "AtomicCounter.h"


CAtomicCounter::CAtomicCounter(void)
{
	Counter = 0;
}


CAtomicCounter::~CAtomicCounter(void)
{
}

const int CAtomicCounter::Increment()
{
	return Counter++;
}
const int CAtomicCounter::Decrement()
{
	return Counter--;
}
const int CAtomicCounter::GetValue()
{
	return Counter;
}