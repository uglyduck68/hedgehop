#ifndef X1_AutoPtr_INCLUDED
#define X1_AutoPtr_INCLUDED

#include "../../Foundation/include/Poco/AutoPtr.h"


namespace X1 {

template <class C>
class AutoPtr : public Poco::AutoPtr<C>
{
public:
	AutoPtr(): Poco::AutoPtr<C>()
	{
	}

	AutoPtr(C* ptr): Poco::AutoPtr<C>(ptr)
	{
	}
	
	AutoPtr(C* ptr, bool shared): Poco::AutoPtr<C>(ptr, shared)
	{
	}

	//type castiing
	AutoPtr(const AutoPtr& ptr): Poco::AutoPtr<C>((Poco::AutoPtr<C>)ptr)
	{
	}

	//type castiing
	AutoPtr(const Poco::AutoPtr<C>& ptr): Poco::AutoPtr<C>(ptr)
	{
	}

	template <class Other>
	AutoPtr(const Poco::AutoPtr<Other>& ptr) : Poco::AutoPtr<C>(ptr)
	{
	}

	//to do something .......
	template <class Other> 
	AutoPtr(const AutoPtr<Other>& ptr): Poco::AutoPtr<C>((Poco::AutoPtr<Other>)ptr)
	{
	}

	virtual ~AutoPtr()
	{
	}
	
};

} // namespace X1


#endif // Foundation_AutoPtr_INCLUDED
