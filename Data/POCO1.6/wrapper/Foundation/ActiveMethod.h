#ifndef X1_ActiveMethod_INCLUDED
#define X1_ActiveMethod_INCLUDED

#include "../../Foundation/include/Poco/ActiveMethod.h"


namespace X1 {

template < class ResultType, class ArgType, class OwnerType, class StarterType = Poco::ActiveStarter<OwnerType> >

class ActiveMethod 
	: public Poco::ActiveMethod<ResultType, ArgType, OwnerType, StarterType>
{
public:

	typedef ResultType (OwnerType::*Callback)(const ArgType&);

	ActiveMethod(OwnerType* pOwner, Callback method) :
		Poco::ActiveMethod<ResultType, ArgType, OwnerType, StarterType>(pOwner, method)
	{
	}
		
	ActiveMethod(const ActiveMethod& other) :
		Poco::ActiveMethod<ResultType, ArgType, OwnerType, StarterType>(other)
	{
	}

private:
	ActiveMethod();
};

template < class ResultType, class OwnerType, class StarterType>
class ActiveMethod <ResultType, void, OwnerType, StarterType> 
	: public Poco::ActiveMethod<ResultType, OwnerType, StarterType>
{
public:
	typedef ResultType (OwnerType::*Callback)(void);

	ActiveMethod(OwnerType* pOwner, Callback method) :
		Poco::ActiveMethod<ResultType, OwnerType, StarterType>(pOwner, method)
	{
	}
	
	ActiveMethod(const ActiveMethod& other) :
		Poco::ActiveMethod<ResultType, OwnerType, StarterType>(other)
	{
	}

private:
	ActiveMethod();
};


} // namespace X1


#endif // Foundation_ActiveMethod_INCLUDED
