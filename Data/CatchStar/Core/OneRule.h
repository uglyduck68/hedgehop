#pragma once

#include "Deck.h"

class OneRule
{
	enum EPLAY_RESULT {
		ENO_PLAY		= -1,
		EPLAYER_WIN		= 1,
		EBANKER_WIN		= 2,
		ETIE			= 3,
		EPLAYER_PAIR	= 4,
		EBANKER_PAIR	= 8
	};

	typedef struct tagResult
	{
		EPLAY_RESULT		nResult;	// 
		Card	PlayerCard[3];
		Card	BankerCard[3];
	} Result;

public:
	OneRule(Deck*);

	~OneRule(void);

	int SetFirstCard(Card& playerCard, Card& bankerCard);
	int SetSecondCard(Card& playerCard, Card& bankerCard);

	int IsMorePlayerCard();
	int	IsMoreBankerCard();

	int	Start(Deck* pDeck);
	int DoJudge();
	int	SendResult(Result& result);
	int End();

protected:
//	Deck*	m_pDeck;

	Result	m_Result;

};

