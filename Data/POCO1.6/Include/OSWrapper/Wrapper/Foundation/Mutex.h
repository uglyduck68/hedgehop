#ifndef X1_Mutex_INCLUDED
#define X1_Mutex_INCLUDED


#include "Poco/Mutex.h"


namespace X1 {

class Mutex: public Poco::Mutex
{
public:
	
	Mutex() : Poco::Mutex()
	{}
		
	virtual ~Mutex()
	{}
	
private:
	Mutex(const Mutex&)
	{}
//	Mutex& operator = (const Mutex&)
//	{}
};

class FastMutex: public Poco::FastMutex 
{
public:
	FastMutex() : Poco::FastMutex()
	{}
		
	virtual ~FastMutex()
	{}
	
private:
	FastMutex(const FastMutex&)
	{}
//	FastMutex& operator = (const FastMutex&)
//	{}
};


class NullMutex : public Poco::NullMutex
{
public:
	NullMutex()
	{
	}
		
	~NullMutex()
	{
	}

};



} // namespace X1


#endif // Foundation_Mutex_INCLUDED
