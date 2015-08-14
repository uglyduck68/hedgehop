#include "StdAfx.h"
#include "CardTable.h"


CardTable::CardTable(void) : m_pDeck(nullptr), m_pRule(nullptr), m_pScoreBoard(nullptr)
{
}


CardTable::~CardTable(void)
{
}

void	CardTable::PrepareTable()
{
	// create 8 decks
	m_pDeck			= new Deck(8);
	m_pRule			= new OneRule(m_pDeck);
	m_pScoreBoard	= new ScoreBoard();
}

void	CardTable::Start()
{
	// shuffle cards
	m_pDeck->Shuffle();

	// set indicator
	m_pDeck->SetIndicateCard(1);

	// players bet
	PlayerBet();

	// deal the cards
	DealCards();

	// calculate balance
	CalcBalance();

	// write the result to scoreboard
}

void CardTable::PlayerBet()
{
}

void	CardTable::DealCards()
{
	if(m_pRule && m_pDeck)
	{
		m_pDeck->DealCards(m_pRule);
	}

}

void	CardTable::CalcBalance()
{
}

void	CardTable::WriteScoreBoard()
{
}