#include "StdAfx.h"
#include "ScoreBoard.h"

int	ScoreBoard::m_nPlayerWinTotal	= 0;
int	ScoreBoard::m_nBankerWinTotal	= 0;
int	ScoreBoard::m_nGameNumber		= 0;
int	ScoreBoard::m_nTieNumber		= 0;
int	ScoreBoard::m_nPlayerDoizzi		= 0;
int	ScoreBoard::m_nBankerDoizzi		= 0;

ScoreBoard::ScoreBoard(void) : m_nSumPlayer(-1), m_nSumBanker(-1), m_nDoizzi(-1),
	m_nTie(-1)
{

}


ScoreBoard::~ScoreBoard(void)
{
}

void ScoreBoard::CheckDoizzi(Card& p1, Card& p2, Card& b1, Card& b2)
{
	if (p1 == p2)
		m_nDoizzi	= PLAYER_DOIZZI;

	if (b1 == b2)
	{
		if (m_nDoizzi == PLAYER_DOIZZI)
			m_nDoizzi	= BOTH_DOIZZI;
		else
			m_nDoizzi	= BANKER_DOIZZI;
	}

}

void ScoreBoard::CheckTie(int nSumPlayer, int nSumBanker)
{
	if (nSumPlayer == nSumBanker)
	{
		m_nTie	= nSumPlayer;

		m_nTieNumber++;
	}
	else
		m_nTie	= -1;
}

void ScoreBoard::SetScore(Card& p1, Card& p2, Card& b1, Card& b2, int nSumPlayer, int nSumBanker)
{
	CheckDoizzi(p1, p2, b1, b2);
	CheckTie(nSumPlayer, nSumBanker);

	m_nSumPlayer	= nSumPlayer;
	m_nSumBanker	= nSumBanker;

	if (m_nSumPlayer > m_nSumBanker)
		m_nPlayerWinTotal++;
	else if(m_nSumPlayer < m_nSumBanker)
		m_nBankerWinTotal++;

	m_nGameNumber++;
}

void ScoreBoard::Log(std::ofstream& file)
{
	file << "Total Game Number is " << m_nGameNumber << std::endl;
	file << "Tie   Game Number is " << m_nTieNumber << std::endl;
	file << "Player Win Number is " << m_nPlayerWinTotal << std::endl;
	file << "Banker Win Number is " << m_nBankerWinTotal << std::endl;
	file << "Player Doz Number is " << m_nPlayerDoizzi << std::endl;
	file << "Banker Doz Number is " << m_nBankerDoizzi << std::endl;
}