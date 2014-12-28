
#include "Entity.h"
#include <boost/foreach.hpp>

Entity::Entity()
	: Id( -1 ), OgreEntity( NULL )
{}

Entity::Entity( const std::string& Name )
	: Name( Name ), Id( -1 ), OgreEntity( NULL )
{}

Entity::Entity( int id )
	: Id( id ), OgreEntity( NULL )
{}

Entity::Entity( const std::string& Name, int id )
	: Name( Name ), Id( id ), OgreEntity( NULL )
{}

Entity::~Entity()
{}

void Entity::SetName( const std::string& Rhs )
{
	if ( this->Name == Rhs )
		return;

	this->Name = Rhs;

	BOOST_FOREACH( EntityObserver * x, Observer )
	x->OnEntityNameChanged( this );
}

void Entity::SetId( int newId )
{
	this->Id = newId;
}

void Entity::SetAttribute( const std::string& Name, const VariantType& Rhs )
{
	VariantType& Attrib=Attribute[Name];
	Attrib=Rhs;
	Changed( Name,&Attrib );
}

const Entity::VariantType* Entity::GetAttribute( const std::string& Name )
const
{
	AttributeType::const_iterator Node = Attribute.find( Name );

	if ( Node == Attribute.end() )
		return 0;
	else
		return &Node->second;
}

std::vector< std::string > Entity::GetAttributeNames() const
{
	AttributeType::const_iterator it = Attribute.begin();

	std::vector< std::string > attrNames;

	while(it != Attribute.end())
	{
		attrNames.push_back((*it).first);
		it++;
	}

	return attrNames;
}

void Entity::Changed( const std::string& Name, const VariantType* Attrib )
{
	BOOST_FOREACH( EntityObserver * x, Observer )
	x->OnEntityAttributeChanged( this, Name, Attrib );
}

bool Entity::RemoveAttribute( const std::string& Name )
{
	AttributeType::iterator Node = Attribute.find( Name );

	if ( Node == Attribute.end() )
		return false;

	Attribute.erase( Node );
	this->Changed( Name,0 );
	return true;
}
