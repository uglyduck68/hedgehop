#include <vector>

#include "Defines.h"

#include "Request_Handler.h"

using namespace		std;

int	Request_Handler::AddConnectedList(Request_Handler* Handler)
{
	ConnectedList.insert( RHPair(Handler, Handler) );

	return UG_OK;
}