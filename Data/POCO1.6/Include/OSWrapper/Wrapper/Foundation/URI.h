
#ifndef X1_URI_INCLUDED
#define X1_URI_INCLUDED


#include "Poco/URI.h"

namespace X1 {

class URI : public Poco::URI
{
public:

	URI() : Poco::URI()
	{}
		/// Creates an empty URI.

	explicit URI(const std::string& uri) : Poco::URI(uri)
	{}
		
	explicit URI(const char* uri) : Poco::URI(uri)
	{}		
	
	URI(const std::string& scheme, const std::string& pathEtc) : Poco::URI(scheme, pathEtc)
	{}
		
	URI(const std::string& scheme, const std::string& authority, const std::string& pathEtc) : Poco::URI(scheme, authority, pathEtc)
	{}

	URI(const std::string& scheme, const std::string& authority, const std::string& path, const std::string& query)
		: Poco::URI(scheme, authority, path, query)
	{}
	
	URI(const std::string& scheme, const std::string& authority, const std::string& path, const std::string& query, const std::string& fragment)
		: Poco::URI(scheme, authority, path, query)
	{}

	URI(const URI& uri);
		: Poco::URI(uri)
	{}
		
	URI(const URI& baseURI, const std::string& relativeURI)
		: Poco::URI(baseURI, relativeURI)
	{}

	explicit URI(const Path& path) : Poco::URI(path)
	{}
		/// Creates a URI from a path.
		///
		/// The path will be made absolute, and a file:// URI
		/// will be built from it.

	virtual ~URI()
	{}
		/// Destroys the URI.
	
};

} // namespace X1


#endif // Foundation_URI_INCLUDED
