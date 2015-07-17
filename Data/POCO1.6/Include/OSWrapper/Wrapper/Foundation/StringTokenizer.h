
#ifndef X1_StringTokenizer_INCLUDED
#define X1_StringTokenizer_INCLUDED


#include "Poco/StringTokenizer.h"

namespace X1 {

class StringTokenizer : public Poco::StringTokenizer
{
public:
	
	StringTokenizer(const std::string& str, const std::string& separators, int options = 0)
		: Poco::StringTokenizer(str, separators, options)
	{}

	virtual ~StringTokenizer() 
	{}

private:
	StringTokenizer(const StringTokenizer&)
	{}
	StringTokenizer& operator = (const StringTokenizer&)
	{}
};


#endif // Foundation_StringTokenizer_INCLUDED
