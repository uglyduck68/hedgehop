#ifndef X1_Stopwatch_INCLUDED
#define X1_Stopwatch_INCLUDED


#include "Poco/Stopwatch.h"

namespace X1 {

class Stopwatch : public Poco::Stopwatch
{
public:
	Stopwatch()
	{}
	~Stopwatch()
	{}

private:
	Stopwatch(const Stopwatch&)
	{}
//	Stopwatch& operator = (const Stopwatch&)
//	{}
};

}
#endif // Foundation_Stopwatch_INCLUDED
