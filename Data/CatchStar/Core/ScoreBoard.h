#pragma once
#include <fstream>

#include "Card.h"

class ScoreBoard
{
public:
	ScoreBoard(void);
	~ScoreBoard(void);

	enum EDOIZZI 
	{
		PLAYER_DOIZZI	= 1,
		BANKER_DOIZZI,
		BOTH_DOIZZI
	};

	short	m_nSumPlayer;
	short	m_nSumBanker;
	short	m_nDoizzi;	/// if doizzi, has one of EDOZZI
	short	m_nTie;		/// if tie, has 1 between 10

	static int	m_nPlayerWinTotal;
	static int	m_nBankerWinTotal;
	static int	m_nGameNumber;		/// # of games
	static int	m_nTieNumber;		/// # of ties
	static int	m_nPlayerDoizzi;	/// # of player's doizzi
	static int	m_nBankerDoizzi;	/// # of player's doizzi


	void CheckDoizzi(Card& p1, Card& p2, Card& b1, Card& b2);
	void CheckTie(int nSumPlayer, int nSumBanker);

	void SetScore(Card& p1, Card& p2, Card& b1, Card& b2, int nSumPlayer, int nSumBanker);

	/// init. the static variables
	void Init()
	{
		m_nPlayerWinTotal = m_nBankerWinTotal = m_nGameNumber = 
		m_nTieNumber = m_nPlayerDoizzi = m_nBankerDoizzi	= 0;
	}

	void Log(std::ofstream& file);
};

