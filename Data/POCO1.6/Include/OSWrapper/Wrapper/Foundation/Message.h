#ifndef X1_Message_INCLUDED
#define X1_Message_INCLUDED


#include "Poco/Message.h"

namespace X1 {


class Message : public Poco::Message
{
public:
	
	Message() : Poco::Message()
	{}
		
	Message(const std::string& source, const std::string& text, Priority prio): Poco::Message(source, text, prio)
	{}

	Message(const std::string& source, const std::string& text, Priority prio, const char* file, int line)
		: Poco::Message(source, text, prio, file, line)
	{}
	
	Message(const Message& msg) : Poco::Message(msg)
	{}
	
	Message(const Message& msg, const std::string& text) : Poco::Message(msg, text)
	{}
		
	virtual ~Message()
	{}
	
};

} // namespace X1


#endif // Foundation_Message_INCLUDED
