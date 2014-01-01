#pragma once

#include "Config.h"
#include "Types.h"
#include "Defines.h"
#include "Debug.h"
#include "Log.h"

NS_X1_START
/**
 * @class	X1
 * @brief	X1 library initializer
 */
class Lib
{
protected:
	int		m_nComponents;
public:
	static int Init();

	static int Fin();
};

NS_X1_END