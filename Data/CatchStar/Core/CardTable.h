#pragma once
#include <vector>

#include "Deck.h"
#include "OneRule.h"
#include "ScoreBoard.h"
#include "Player.h"

class CardTable
{
public:
	CardTable(void);
	~CardTable(void);

	/**
	 * @function		PrepareTable
	 * @brief			table setting before player log-in
	 */
	void	PrepareTable();
	void	Login(Player* pPlayer);
	void	Start();
	void	PlayerBet();
	void	DealCards();
	void	CalcBalance();
	void	WriteScoreBoard();


protected:
	Deck*					m_pDeck;
	OneRule*				m_pRule;
	ScoreBoard*				m_pScoreBoard;
	std::vector<Player*>	m_vecPlayers;
};

