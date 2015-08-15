/**
 * @file		Card.h
 * @brief		header file for Card class
 * @date		2015/08/14
 * @author		sean kim<uglyduck68@gmail.com>
 */
#include <assert.h>

#pragma once

enum ESHAPE { NO_SHAPE = -1, SPADES = 0, DIAMONDS, HEARTS, CLUBS };

const int DFT_NOCARD		= 52;
const int DEF_NOCARD_SHAPE	= 4;
const int DFT_NOCARD_NUMBER	= 13;
const int NO_NUM			= -1;

/**
* @class		Card
* @brief		means one card with shape and number
*/
class Card
{
public:
	Card(void);
	Card(int n);
	~Card(void);

	void	SetShape(int nShape)
	{
		m_eShape		= static_cast<ESHAPE>(nShape);
	}

	void	SetNumber(int nNumber)
	{
		m_nNum		= 1 + nNumber;
	}

	void	SetShapeNumber(int nNo)
	{
		int		n		= nNo % DFT_NOCARD;
		int		nShape	= n / DFT_NOCARD_NUMBER;
		int		nNumber	= 1 + (n % DFT_NOCARD_NUMBER);

		m_eShape	= static_cast<ESHAPE>(nShape);
		m_nNum		= nNumber;
	}

	void	Get(int& nShape, int& nNumber)
	{
		nShape	= m_eShape;
		nNumber	= m_nNum;
	}

	/**
	 * @function		Get
	 * @return			return the number of card
	 */
	int		Get()
	{
		assert(1 <= m_nNum && m_nNum <= 13);

		if (m_nNum >= 10)
			return 0;

		return m_nNum;
	}

	void	Get(int& Sum)
	{
		int		n	= Get();

		Sum	+= n;

		if (Sum >= 10)
			Sum -= 10;
	}

	/** for find function */
	int operator==(Card rhs)
	{
		int			s;
		int			n;

		rhs.Get(s, n);

		if( this->m_eShape == s && this->m_nNum == n)
			return 1;

		return 0;
	}

	void	SetIndicator(int n)
	{
		m_bIndicator	= n;
	}

	int	GetIndicator()
	{
		return m_bIndicator;
	}

protected:
	ESHAPE		m_eShape;	// shape of card
	int			m_nNum;		// # of card
	int			m_bIndicator;	// this card is indicator card
								// next game is final game.
	
};

