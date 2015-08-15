/**
 * @file		Deck.h
 * @brief		header file for Deck class
 *				Deck means the holder has some bunchs of cards.
 * @date		2015/08/14
 * @author		sean kim<uglyduck68@gmail.com>
 */
#pragma once

#include <algorithm>	// for random shuffle
#include <vector>
#include <ctime>		// std::time
#include <iostream>		// 
#include <fstream>		// for debugging

#include "Card.h"
#include "ScoreBoard.h"



const int		DFT_NODECK		= 8;	/// default bunchs of cards
const double	MIN_INDICATOR	= 0.7;	/// indicator is always above 70%

class Deck
{
public:
	Deck(void);
	Deck(int nCards);
	~Deck(void);

	/**
	 * @function	Shuffle
	 * @brief		random shuffle 
	 */
	int Shuffle();

	/**
	 * @function	SetIndicateCard
	 * @brief		set indicator card in deck
	 * @param		nControl that control the position of indicator
	 *				0 : the last card is indicator
	 *				1 : make random indicator
	 *				other value means the position of indicator
	 * @return		location of indicator card in deck
	 */
	int SetIndicateCard(int nControl);

	/**
	 * @function	CheckValidation
	 * @brief		check the validation of deck after shuffle
	 */
	int CheckValidation();


	/**
	 * @function		GetNextCard
	 * @brief			return next card
	 * @param			card that is returned next card
	 * @param			bEnd that is set to 1 if this card is final card(indicator)
	 */
	int GetNextCard(Card& card, int& bEnd);

	/**
	 * @function		GetFirstTwoCard
	 * @brief			get the first two card of player and banker
	 * @return			RET_ERROR if any card of 4 is indicator
	 */
	int GetFirstTwoCard(Card& p1, Card& p2, Card& b1, Card& b2);


	void Print(const char* pcFileName = NULL)
	{
		std::ofstream	Out;
		time_t			Now;
		struct tm*		pTm;

		time(&Now);
		pTm	= localtime(&Now);

		if (pcFileName != NULL)
		{
			Out.open(pcFileName, std::ios::out | std::ios::app);

			Out << asctime(pTm) << std::endl;
		}
		else
			std::cout << asctime(pTm) << std::endl;

		for(size_t i = 0; i < m_vecDeck.size(); i++)
		{
			int	nShape	= -1;
			int nNum	= -1;
			Card	c;

			c	= m_vecDeck[i];	// why NOT m_vecDeck[i].Get(...) in VS2010???
			c.Get(nShape, nNum);

			if (pcFileName == NULL)
				std::cout << i << " : " << "shape: " << nShape << " num: " << nNum << std::endl;
			else
				Out << i << " : " << "shape: " << nShape << " num: " << nNum << std::endl;

		}
	}

	/**
	* @function		IsEnd
	* @return		1 if current card is indicator
	*/
	int	IsEnd()
	{
		return m_vecDeck.at(m_nCurrCard).GetIndicator();
	}

	void Backup()
	{
		m_vecBackup.resize(m_vecDeck.size());

		std::copy(m_vecDeck.begin(), m_vecDeck.end(), m_vecBackup.begin());
	}

	void Rollback()
	{
		std::copy(m_vecBackup.begin(), m_vecBackup.end(), m_vecDeck.begin());

		CheckValidation();

		m_nCurrCard	= 0;
	}

	/**
	* @function		Play
	* @brief		play simulation using m_vecDeck
	*				make its result to log file
	*/
	void Play(const char* pcLogFile);

protected:
	int		m_nDeckOfCards;		// # of cards (8 or 6 decks)
	int		m_nCurrCard;	// index of current card

	/**
	 *@function		Init
	 * @brief		initialize the cards in deck
	 */
	void Init();

	std::vector<Card>	m_vecDeck;

	/// 
	std::vector<Card>	m_vecBackup;

	/// score board
	std::vector<ScoreBoard>		m_vecScoreBoard;

	Card	m_Cards[DFT_NODECK * DFT_NOCARD];
};

