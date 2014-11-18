#pragma once
class CAtomicCounter
{
public:
	CAtomicCounter(void);
	~CAtomicCounter(void);
	const int Increment();
	const int Decrement();
	const int GetValue();
private:
	int Counter;
};

