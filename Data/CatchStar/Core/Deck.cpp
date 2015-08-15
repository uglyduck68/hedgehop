/**
 * @file		Deck.cpp
 * @brief		implementation file for Deck class
 *				I implements simple playing for testing the odds change
 *				according to the position of the indicator card
 * @date		2015/08/14
 * @author		sean kim<uglyduck68@gmail.com>
 */
#include "StdAfx.h"

#include <assert.h>

#include "Deck.h"


Deck::Deck(void) : m_nDeckOfCards(DFT_NODECK), m_nCurrCard(0)
{
	Init();
}

Deck::Deck(int nDeckOfCards) : m_nDeckOfCards(nDeckOfCards), m_nCurrCard(0)
{
	Init();
}

Deck::~Deck(void)
{
}

void Deck::Init()
{
	// clear previous cards
	m_vecDeck.clear();

	if(m_vecDeck.size() > 0)
	{
		// *MUST* exception
		return;
	}

	for(int i = 0; i < m_nDeckOfCards; i++)
	{
		for(int j = 0; j < DEF_NOCARD_SHAPE; j++)
		{
			for(int k = 0; k < DFT_NOCARD_NUMBER; k++)
			{
				m_Cards[i*(DEF_NOCARD_SHAPE+DFT_NOCARD_NUMBER)+j*DFT_NOCARD_NUMBER+k].SetShape(j);
				m_Cards[i*(DEF_NOCARD_SHAPE+DFT_NOCARD_NUMBER)+j*DFT_NOCARD_NUMBER+k].SetNumber(k);

				// insert card into deck
				m_vecDeck.push_back(m_Cards[i*(DEF_NOCARD_SHAPE+DFT_NOCARD_NUMBER)+j*DFT_NOCARD_NUMBER+k]);
			}
		}
	}

}

int Deck::Shuffle()
{
	std::srand(unsigned(std::time(0)));

	std::random_shuffle(m_vecDeck.begin(), m_vecDeck.end());

	return 0;
}


int Deck::SetIndicateCard(int nControl)
{
	if (nControl == 0)
	{
		// make the last card to indicator
		m_vecDeck.at(m_vecDeck.size()-1).SetIndicator(1);
		return m_vecDeck.size() - 1;
	}
	else if (nControl > 1)
	{
		m_vecDeck.at(nControl).SetIndicator(1);

		return nControl;
	}

	double		dPosition	= -1.0;

	///////////////////////////////////////////////////////////////////////////
	// calculate the indicator position
	///////////////////////////////////////////////////////////////////////////
	std::srand(unsigned(std::time(0)));	// use current time as seed for random generator
	int		nRandom	= std::rand();

	// indicator는 70% 이후 부분에 위치 시킨다.
	dPosition	= MIN_INDICATOR + (double)nRandom / RAND_MAX * (1.0 - MIN_INDICATOR);

	dPosition	*= (m_nDeckOfCards * DFT_NOCARD);

	///////////////////////////////////////////////////////////////////////////
	// copy the rest of the card depending on the indicator position
	///////////////////////////////////////////////////////////////////////////
	if(dPosition >= (m_nDeckOfCards * DFT_NOCARD)-1)
	{
		// if indicator is over the range of vector, 
		// the last card is indicator
		m_vecDeck.at(m_vecDeck.size()-1).SetIndicator(1);
	}
	else
	{
//		m_vecDeck.at((int)dPosition).SetIndicator(1);

		std::vector<Card>	m_vecTemp1;
		std::vector<Card>::iterator		itr	= m_vecDeck.begin() + (int)dPosition+1;
		std::vector<Card>::iterator		itr2;

		m_vecTemp1.resize(m_vecDeck.size());

		// copy cards located behind the indicator to the front position
		for(size_t i = (int)dPosition, j = 0; i < m_vecDeck.size(); i++, j++)
		{
			m_vecTemp1[j]	= m_vecDeck[i];
		}
//		std::copy(itr, m_vecDeck.end(), m_vecTemp1.begin());

		for(size_t i = 0; i < (size_t)dPosition; i++)
		{
			int	ii	= m_vecDeck.size() - (int)dPosition;

			m_vecTemp1[ii+i]	= m_vecDeck[i];
		}


//		itr2	= m_vecTemp1.begin() + (int)dPosition+1;

		// copy cards located before the indicator
//		std::copy(m_vecDeck.begin(), itr, itr2);

		std::copy(m_vecTemp1.begin(), m_vecTemp1.end(), m_vecDeck.begin());

		// set indicator card
		m_vecDeck.at((int)dPosition).SetIndicator(1);

		assert(m_vecTemp1.size() == m_vecDeck.size());

		if (CheckValidation() == 1)
		{
			std::cout << "Error: after set indicator, validation fails" << std::endl;
		}
	}

	return (int)dPosition;
}

/**
* @function		CheckValidation
* @brief		validate the deck
*/
int Deck::CheckValidation()
{
	Card	Item;
	int		nHit	= 0;	// no of found
	int		nError	= 0;	// no error

	for(int i = 0; i < DFT_NOCARD; i++)
	{
		nHit	= 0;
		Item.SetShapeNumber(i);

		for(size_t j = 0; j < m_vecDeck.size(); j++)
		{
			Card	c;

			c	= m_vecDeck[j];

			if(c == Item)
				nHit++;
		}

		if(nHit != m_nDeckOfCards)
		{
			nError	= 1;
			break;
		}
	}

	return nError;
}

int Deck::GetNextCard(Card& card, int& bEnd)
{
	Card	c	= m_vecDeck[m_nCurrCard];

	if(c.GetIndicator() == 1/*true*/)
	{
		bEnd	= true;

		// I can't give you next because next card is indicator
		return RET_ERROR;
	}

	card	= c;

	m_nCurrCard++;

	return RET_OK;
}

	
int Deck::GetFirstTwoCard(Card& p1, Card& p2, Card& b1, Card& b2)
{
	int		bEnd	= RET_OK;

	// get the first card of player
	if (GetNextCard(p1, bEnd) == RET_ERROR)
	{
		// this game is the last
		bEnd	= RET_ERROR;
	}

	// get the first card of banker
	if (GetNextCard(b1, bEnd) == RET_ERROR)
	{
		// this game is the last
		bEnd	= RET_ERROR;
	}

	// get the second card of player
	if (GetNextCard(p2, bEnd) == RET_ERROR)
	{
		// this game is the last
		bEnd	= RET_ERROR;
	}

	// get the second card of banker
	if (GetNextCard(b2, bEnd) == RET_ERROR)
	{
		// this game is the last
		bEnd	= RET_ERROR;
	}

	return bEnd;
}

#define		LOG_VERBOSE	1

void Deck::Play(const char* pcLogFile)
{
	std::ofstream	Out;
	time_t			Now;
	struct tm*		pTm;

	time(&Now);
	pTm	= localtime(&Now);

	if (pcLogFile != NULL)
	{
		Out.open(pcLogFile, std::ios::out | std::ios::app);

		Out << asctime(pTm) << ": Game start" << std::endl;
	}

	Card	p1, p2, p3;
	Card	b1, b2, b3;
	ScoreBoard	score;
	int		nSumPlayer, nSumBanker;		// sum of the first two cards of player and banker
	int		bEnd			= false;	// true if this game is the last
	bool	bNatural		= false;	// true if any one of player or banker is natural
	bool	bPlayerStand	= false;	// true if player is stand

	// clear static variables
	score.Init();

	// set initial position of current card's index
	m_nCurrCard		= 0;

	while(!this->IsEnd() && !bEnd)
	{
		nSumPlayer	= nSumBanker	= 0;
		bNatural	= bPlayerStand	= false;

		///////////////////////////////////////////////////////////////////////
		// First Two Card of Player and Banker
		///////////////////////////////////////////////////////////////////////
		if (GetFirstTwoCard(p1, p2, b1, b2) == RET_ERROR)
				bEnd	= true;


		p1.Get(nSumPlayer);
		p2.Get(nSumPlayer);

		b1.Get(nSumBanker);
		b2.Get(nSumBanker);

		if (IS_NATURAL(nSumPlayer) || IS_NATURAL(nSumBanker))
			bNatural	= true;

#if	LOG_VERBOSE
			Out << "(" << p1.Get() << "," << p2.Get();
#endif
		///////////////////////////////////////////////////////////////////////
		// Third Card of Player
		///////////////////////////////////////////////////////////////////////
		if (IS_PLAYER_STAND(nSumPlayer))
		{
			// player stand
			bPlayerStand	= true;
		}
		else if(IS_NATURAL(nSumPlayer))
		{
			// player natural
		}
		else
		{
			// player's card is 0 ~ 5.

			if (!bNatural)
			{
				// get the third card of player if banker is *NOT* natural.
				GetNextCard(p3, bEnd);

				p3.Get(nSumPlayer);

#if	LOG_VERBOSE
				Out << "," << p3.Get();
#endif
			}
		}

#if	LOG_VERBOSE
	Out << "), (" << b1.Get() << "," << b2.Get();
#endif
		///////////////////////////////////////////////////////////////////////
		// Third Card of Banker
		///////////////////////////////////////////////////////////////////////
		// get the third card of banker if player or banker is *NOT* natural 
		// and banker is *NOT* stand(7).
		if(!bNatural)
		{
			if ((nSumBanker <= 2))
			{
				// get the third card of banker
				GetNextCard(b3, bEnd);

				b3.Get(nSumBanker);
#if	LOG_VERBOSE
			Out << "," << b3.Get();
#endif
			}
			else if	((nSumBanker == 3) && (bPlayerStand || !bPlayerStand && p3.Get() != 8))
			{
				// get the third card of banker
				GetNextCard(b3, bEnd);

				b3.Get(nSumBanker);
				
#if	LOG_VERBOSE
			Out << "," << b3.Get();
#endif
			}
			else if	((nSumBanker == 4) && (bPlayerStand || !bPlayerStand && (2 <= p3.Get() && p3.Get() <= 7)))
			{
				// get the third card of banker
				GetNextCard(b3, bEnd);

				b3.Get(nSumBanker);
#if	LOG_VERBOSE
			Out << "," << b3.Get();
#endif
			}
			else if	((nSumBanker == 5) && (bPlayerStand || !bPlayerStand && (4 <= p3.Get() && p3.Get() <= 7)))
			{
				// get the third card of banker
				GetNextCard(b3, bEnd);

				b3.Get(nSumBanker);
#if	LOG_VERBOSE
			Out << "," << b3.Get();
#endif
			}
			else if ((nSumBanker == 6) && (bPlayerStand || !bPlayerStand && (6 <= p3.Get() && p3.Get() <= 7)))
			{
				// get the third card of banker
				GetNextCard(b3, bEnd);

				b3.Get(nSumBanker);
#if	LOG_VERBOSE
			Out << "," << b3.Get();
#endif
			}
		}

#if	LOG_VERBOSE
		Out << ") ->";

		if (nSumPlayer == nSumBanker)
		{
			// tie
			Out << "TIE: " << nSumPlayer << ", " << nSumBanker << std::endl;
		}
		else if (nSumPlayer < nSumBanker)
		{
			// banker win
			Out << "BANKER WIN: " << nSumPlayer << ", " << nSumBanker << std::endl;
		}
		else
		{
			// player win
			Out << "PLAYER WIN: " << nSumPlayer << ", " << nSumBanker << std::endl;
		}
#endif

		// set score and insert it into the vector
		score.SetScore(p1, p2, b1, b2, nSumPlayer, nSumBanker);

		m_vecScoreBoard.push_back(score);

	}	// end of while

#if	LOG_VERBOSE
	Out << "Current indicator is " << m_nCurrCard << "/" << m_vecDeck.size() << std::endl;
#endif

	// print the statistics of game
	score.Log(Out);

	Out.close();
}
