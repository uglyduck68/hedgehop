#ifndef X1_Thread_INCLUDED
#define X1_Thread_INCLUDED

#include "../../Foundation/include/Poco/Thread.h"


namespace X1 {

class Thread: public Poco::Thread
{
public:	
	Thread()
	{}
	
	Thread(const std::string& name) : Poco::Thread(name)
	{}
	
	virtual ~Thread()
	{}

private:
	Thread(const Thread&)
	{}
	Thread& operator = (const Thread&)
	{}

};

}


#endif // Foundation_Thread_INCLUDED
