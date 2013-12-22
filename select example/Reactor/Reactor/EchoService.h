#pragma once

#include	"EventHandler.h"

/**
 * @class	EchoService
 * @brief	This class is just for sample of reactor
 */
class EchoService :public EventHandler
{
public:
	EchoService(void);
	~EchoService(void);
};

