#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
	m_gameStatus(GameStatus::MidGame), m_cardsArray(cardsArray), m_player(Player(playerName)), m_numOfCards(numOfCards),
	  m_currentCard(0) 
{}


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
	else if (m_player.getLevel() == 10)
	{
		return GameStatus::Win;
	}
	else
	{
		return GameStatus::MidGame;
	}
}

int main()
{
	return 0;
}