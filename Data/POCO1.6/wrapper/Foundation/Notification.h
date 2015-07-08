
#ifndef X1_Notification_INCLUDED
#define X1_Notification_INCLUDED


#include "../../Foundation/include/Poco/Notification.h"

namespace X1 {

class Notification: public Poco::Notification
{
public:
	Notification() : Poco::Notification()
	{}

protected:
	virtual ~Notification()
	{}
};


} // namespace X1


#endif // Foundation_Notification_INCLUDED
