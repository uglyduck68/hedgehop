#ifndef X1_Timestamp_INCLUDED
#define X1_Timestamp_INCLUDED


#include "../../Foundation/include/Poco/Timestamp.h"
#include <ctime>


namespace X1 {

class Timestamp : public Poco::Timestamp
{
public:
	typedef long long TimeVal; 
	typedef long long UtcTimeVal; 
	typedef long long TimeDiff;

	Timestamp()
	{}
		
	Timestamp(TimeVal tv) : Poco::Timestamp(tv)
	{}

	Timestamp(const Timestamp& other) : Poco::Timestamp(other)
	{}

	Timestamp(const Poco::Timestamp& other) : Poco::Timestamp(other)
	{}
		
	~Timestamp()
	{}
};


} // namespace Poco


#endif // Foundation_Timestamp_INCLUDED
