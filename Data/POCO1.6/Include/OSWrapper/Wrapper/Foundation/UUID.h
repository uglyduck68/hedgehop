#ifndef X1_UUID_INCLUDED
#define X1_UUID_INCLUDED


#include "Poco/UUID.h"


namespace X1 {


class UUID : public Poco::UUID
{
public:
	UUID() : Poco:UUID()
	{}
		
	UUID(const UUID& uuid) : Poco:UUID(uuid)
	{}
		/// Copy constructor.

	explicit UUID(const std::string& uuid) : Poco:UUID(uuid)
	{}
		/// Parses the UUID from a string.
		
	explicit UUID(const char* uuid) : Poco:UUID(uuid)
	{}
		/// Parses the UUID from a string.

	virtual ~UUID()
	{}
		/// Destroys the UUID.

//	UUID& operator = (const UUID& uuid);
		/// Assignment operator.
	
	friend class UUIDGenerator;
};


} // namespace X1


#endif // Foundation_UUID_INCLUDED
