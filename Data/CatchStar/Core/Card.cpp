/**
 * @file		Card.h
 * @brief		implementation file for Card class
 * @date		2015/08/14
 * @author		sean kim<uglyduck68@gmail.com>
 */
#include "StdAfx.h"
#include "Card.h"


Card::Card(void) : m_bIndicator(false),
	m_eShape(NO_SHAPE), m_nNum(NO_NUM)
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
