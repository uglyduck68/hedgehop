#include "StdAfx.h"
#include "OneRule.h"


OneRule::OneRule(Deck* pDeck) //: m_pDeck(pDeck)
{
}


OneRule::~OneRule(void)
{
}

int OneRule::SetFirstCard(Card& playerCard, Card& bankerCard)
{
	m_Result.PlayerCard[0]	= playerCard;
	m_Result.BankerCard[0]	= bankerCard;

	return RET_OK;
}

int OneRule::SetSecondCard(Card& playerCard, Card& bankerCard)
{
	m_Result.PlayerCard[1]	= playerCard;
	m_Result.BankerCard[1]	= bankerCard;

	return RET_OK;
}

int OneRule::IsMorePlayerCard()
{
	int		nSum	= m_Result.PlayerCard[0].Get() +  m_Result.PlayerCard[1].Get();

	if (nSum >= 6)
		// player is standzone or natural
		return 0;

	return 1;
}

int	OneRule::IsMoreBankerCard()
{
	return RET_OK;
}