#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) {}


void Mtmchkin::playNextCard(){}

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
