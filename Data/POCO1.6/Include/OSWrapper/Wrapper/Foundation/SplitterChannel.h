
#ifndef X1_SplitterChannel_INCLUDED
#define X1_SplitterChannel_INCLUDED


#include "Poco/SplitterChannel.h"

namespace X1 {

class SplitterChannel: public Poco::SplitterChannel
{
public:
	SplitterChannel() : Poco::SplitterChannel()
	{}

protected:
	~SplitterChannel()
	{}

};


} // namespace X1


#endif // Foundation_SplitterChannel_INCLUDED
