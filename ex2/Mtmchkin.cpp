#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
	m_player(Player(playerName)), m_numOfCards(numOfCards), 
	m_gameStatus(GameStatus::MidGame), m_cardsArray(cardsArray), m_currentCard(0) 
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
	Card cards[4];
	CardStats stats(3, 40, 10, 30, 1, 20);
	cards[0] = Card(CardType::Treasure, stats);
	cards[1] = Card(CardType::Buff, stats);
	cards[2] = Card(CardType::Battle, stats);
	cards[3] = Card(CardType::Heal, stats);
	Mtmchkin game("Daniel", cards, 4);
	while (!game.isOver())
	{
		game.playNextCard();
	}
	if (game.getGameStatus() == GameStatus::Win)
	{
		std::cout << "The Plater defeated all monsters";
	}
	return 0;
}
