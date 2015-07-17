#ifndef X1_Random_INCLUDED
#define X1_INCLUDED

#include "Poco/Random.h"

namespace X1 {


class Random : public Poco::Random
{
public:
	Random(int stateSize = 256) : Poco::Random(stateSize)
	{
	}

	virtual ~Random()
	{}
};

} // namespace Poco


#endif // Foundation_Random_INCLUDED
