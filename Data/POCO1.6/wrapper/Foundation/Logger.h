
#ifndef X1_Logger_INCLUDED
#define X1_Logger_INCLUDED

#include "../../Foundation/include/Poco/Logger.h"


namespace X1 {

class Logger: public Poco::Logger
{
private:
	Logger()
	{}
	Logger(const Logger&)
	{}
	Logger& operator = (const Logger&)
	{}
};


} // namespace X1


#endif // Foundation_Logger_INCLUDED
