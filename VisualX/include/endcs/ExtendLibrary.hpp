#include "interface/ICommandInterfaceDDS.h"
#include "msg/rmOPV_Protocol.hpp"
#define DOMAIN_ID 2
ADD_DDSCommand(2,SC_SIM_OWNSHIP);
ADD_DDSCommand(2,SC_SIM_ENTITY);
ADD_DDSCommand(2,SC_SIM_ENTITY_STATE);
ADD_DDSCommand(2,SC_SIM_OWNSHIP_STATE);
ADD_DDSCommand(2,SC_SIM_ENVIRONMENT);