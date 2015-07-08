
#ifndef X1_ActiveResult_INCLUDED
#define X1_ActiveResult_INCLUDED


#include "../../Foundation/include/Poco/ActiveResult.h"

namespace X1 {

template <class ResultType>
class ActiveResultHolder : public Poco::ActiveResultHolder<ResultType>
{
public:
	ActiveResultHolder(): Poco::ActiveResultHolder<ResultType>()
	{
	}
		
	virtual ~ActiveResultHolder()
	{
	}

};

template <>
class ActiveResultHolder<void> : public Poco::ActiveResultHolder<void>
{
public:

	ActiveResultHolder(): Poco::ActiveResultHolder<void>()
	{
	}	
	~ActiveResultHolder()
	{
	}
};


template <class RT>
class ActiveResult : public Poco::ActiveResult<RT>
{
public:
	typedef RT ResultType;
	typedef ActiveResultHolder<ResultType> ActiveResultHolderType;

	ActiveResult(ActiveResultHolderType* pHolder) : Poco::ActiveResult<RT>(pHolder)
	{
	}
	
	ActiveResult(const ActiveResult& result) : Poco::ActiveResult<RT>(result)
	{
	}

	//casting
	ActiveResult(const Poco::ActiveResult<RT>& result) : Poco::ActiveResult<RT>(result)
	{
	}
		
	virtual ~ActiveResult()
	{
	}
	
private:
	ActiveResult();
};


template <>
class ActiveResult<void> : public Poco::ActiveResult<void>
{
public:

	typedef ActiveResultHolder<void> ActiveResultHolderType;

	ActiveResult(ActiveResultHolderType* pHolder) : Poco::ActiveResult<void>(pHolder)
	{
	}
	
	ActiveResult(const ActiveResult& result) : Poco::ActiveResult<void>(result)
	{
	}

	ActiveResult(const Poco::ActiveResult<void>& result) : Poco::ActiveResult<void>(result)
	{
	}
	
	virtual ~ActiveResult()
		/// Destroys the result.
	{
	}
	
private:
	ActiveResult();
};


} // namespace X1


#endif // Foundation_ActiveResult_INCLUDED

