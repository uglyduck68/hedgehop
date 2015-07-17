#ifndef X1_NotificationQueue_INCLUDED
#define X1_NotificationQueue_INCLUDED


#include "Poco/NotificationQueue.h"

namespace X1 {

class NotificationQueue : public Poco::NotificationQueue
{
public:
	NotificationQueue() : Poco::NotificationQueue()
	{}

	virtual ~NotificationQueue()
	{}

};

} // namespace X1


#endif // Foundation_NotificationQueue_INCLUDED
