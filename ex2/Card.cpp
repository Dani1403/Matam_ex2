#include "Card.h"

Card::Card(CardType type, const CardStats& stats) : m_effect(type), m_stats(stats) {}

void Card::applyEncounter(Player& player) const
{
	int playerAttack = player.getAttackStrength();
	switch (this->m_effect)
	{
		case CardType::Battle:
			printBattleCardInfo(this->m_stats);
			if (playerAttack >= this->m_stats.force)
			{
				player.levelUp();
				player.addCoins(this->m_stats.loot);
				printBattleResult(true);
			}
			else
			{
				player.damage(this->m_stats.hpLossOnDefeat);
				printBattleResult(false);
			}
			break;
		case CardType::Buff:
			printBuffCardInfo(this->m_stats);
			if (player.pay(this->m_stats.cost))
			{
				player.buff(this->m_stats.buff);
			}
			break;
		case CardType::Heal:
			printHealCardInfo(this->m_stats);
			if (player.pay(this->m_stats.cost))
			{
				player.heal(this->m_stats.heal);
			}
			break;
		case CardType::Treasure:
			printTreasureCardInfo(this->m_stats);
			player.addCoins(this->m_stats.loot);
			break;
		default:
			break;
	}
}

void Card::printInfo() const
{
	switch (this->m_effect)
	{
		case CardType::Battle:
			printBattleCardInfo(this->m_stats);
			break;
		case CardType::Buff:
			printBuffCardInfo(this->m_stats);
			break;
		case CardType::Heal:
			printHealCardInfo(this->m_stats);
			break;
		case CardType::Treasure:
			printTreasureCardInfo(this->m_stats);
			break;
		default:
			break;
	}
}

//create a main function to test the class
//create a player and some cards and test the class

int main()
{
	Player player("Pesho", 100, 100);
	player.printInfo();
	CardStats stats(100, 100, 100, 100, 100, 35);
	Card card(CardType::Battle, stats);
	card.applyEncounter(player);
	player.printInfo();
	Card card2(CardType::Buff, stats);
	card2.applyEncounter(player);
	player.printInfo();
	Card card3(CardType::Heal, stats);
	card3.applyEncounter(player);
	player.printInfo();
	Card card4(CardType::Treasure, stats);
	card4.applyEncounter(player);
	player.printInfo();
	return 0;
}