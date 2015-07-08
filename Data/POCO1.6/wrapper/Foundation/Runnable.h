
#ifndef X1_Runnable_INCLUDED
#define X1_Runnable_INCLUDED


#include "../../Foundation/include/Poco/Runnable.h"


namespace X1 {

class Runnable : public Poco::Runnable
{
public:	
	Runnable() : Poco::Runnable()
	{}
	virtual ~Runnable()
	{}
};


} // namespace X1


#endif // Foundation_Runnable_INCLUDED
