// Core.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>

#include "Deck.h"

using namespace	std;

Deck		g_Deck;

int _tmain(int argc, _TCHAR* argv[])
{
#if	1
	// print the shape and # of card
	std::cout << "After initializing the DECK..." << std::endl;

	g_Deck.Print("Init.log");
#endif

	// shuffle the deck
	g_Deck.Shuffle();

#if	1
	// print the shape and # of card
	std::cout << "After shuffling the DECK..." << std::endl;

	g_Deck.Print("Shuffle.log");
#endif

	if(g_Deck.CheckValidation() != 0)
	{
		std::cout << "fail to validate" << std::endl;
		return -1;
	}

	/// backup the deck to compare
	g_Deck.Backup();

	// set indicator card
	int		nIndicator	= g_Deck.SetIndicateCard(1);

	std::cout << "indicator is " << nIndicator << std::endl;
	

	/// simulation play
	g_Deck.Play("play.log");


	g_Deck.Rollback();

	// set indicator as the same position
	g_Deck.SetIndicateCard(nIndicator);

	g_Deck.Play("Play2.log");

	return 0;
}

