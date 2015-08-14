#include "StdAfx.h"
#include "Card.h"


Card::Card(void) : m_bIndicator(false),
	m_eShape(NO_SHAPE), m_nNum(-1)
{

}

/**
 * @brief	ctor that determine the shape and number using one integer parameter
 */
Card::Card(int n) : m_bIndicator(false)
{
	SetShapeNumber(n);
}

Card::~Card(void)
{
}
