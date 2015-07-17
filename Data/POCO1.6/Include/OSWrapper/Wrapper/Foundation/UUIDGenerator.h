#ifndef X1_UUIDGenerator_INCLUDED
#define X1_UUIDGenerator_INCLUDED

#include "Poco/UUID.h"

namespace X1 {


class UUIDGenerator : public Poco::UUIDGenerator
{
public:
	UUIDGenerator() : Poco::UUIDGenerator()
	{}

	virtual ~UUIDGenerator()
	{}

private:
	UUIDGenerator(const UUIDGenerator&)
	{}
	UUIDGenerator& operator = (const UUIDGenerator&)
	{}
};


} // namespace X1


#endif // Foundation_UUIDGenerator_INCLUDED
