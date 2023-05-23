#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
	m_player(playerName, DEFAULT_MAX_HP, DEFAULT_FORCE)
{
	m_gameStatus = GameStatus::MidGame;
	m_numOfCards = numOfCards;
	m_cardsArray = new Card[m_numOfCards];
	for (int card = 0; card < m_numOfCards; card++)
	{
		m_cardsArray[card] = cardsArray[card];
	}
	m_currentCard = 0;
}

Mtmchkin::~Mtmchkin()
{
	delete[] m_cardsArray;
}


void Mtmchkin::playNextCard()
{
	if (m_currentCard == m_numOfCards)
	{
		m_currentCard = 0;
	}
	m_cardsArray[m_currentCard].printInfo();
	m_cardsArray[m_currentCard].applyEncounter(m_player);
	m_player.printInfo();
	m_currentCard++;
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