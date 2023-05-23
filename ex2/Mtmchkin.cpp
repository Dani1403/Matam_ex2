#include "Mtmchkin.h"
const int MAX_LEVEL = 10;

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
	m_player(playerName)
{
	m_gameStatus = GameStatus::MidGame;
	m_numOfCards = numOfCards;
	m_cardsArray = new Card[numOfCards];
	for (int card = 0; card < numOfCards; card++)
	{
		m_cardsArray[card] = cardsArray[card];
	}
	m_currentCard = 0;
}


void Mtmchkin::playNextCard()
{
	m_cardsArray[m_currentCard].printInfo();
	m_cardsArray[m_currentCard].applyEncounter(m_player);
	m_currentCard++;
	if (m_currentCard == m_numOfCards)
	{
		m_currentCard = 0;
	}
	m_player.printInfo();
}

bool Mtmchkin::isOver() const 
{
	return getGameStatus() != GameStatus::MidGame;
}

GameStatus Mtmchkin::getGameStatus() const
{
	if (m_player.isKnockedOut())
	{
		return GameStatus::Loss;
	}
	else if (m_player.getLevel() == MAX_LEVEL)
	{
		return GameStatus::Win;
	}
	else
	{
		return GameStatus::MidGame;
	}
}