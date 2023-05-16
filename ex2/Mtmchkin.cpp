#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards){}
void Mtmchkin::playNextCard(){}
bool Mtmchkin::isOver() const 
{
	return true;
}
GameStatus Mtmchkin::getGameStatus() const
{
	return GameStatus::Win;
}
