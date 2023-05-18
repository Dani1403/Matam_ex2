#include "Card.h"

Card::Card(CardType type, const CardStats& stats) : m_effect(type), m_stats(stats) {}

void Card::applyEncounter(Player& player) const
{
	int playerAttack = player.getAttackStrength();
	switch (m_effect)
	{
		case CardType::Battle:
			if (playerAttack >= m_stats.force)
			{
				player.levelUp();
				player.addCoins(m_stats.loot);
				printBattleResult(true);
			}
			else
			{
				player.damage(m_stats.hpLossOnDefeat);
				printBattleResult(false);
			}
			break;
		case CardType::Buff:
			if (player.pay(m_stats.cost))
			{
				player.buff(m_stats.buff);
			}
			break;
		case CardType::Heal:
			if (player.pay(m_stats.cost))
			{
				player.heal(m_stats.heal);
			}
			break;
		case CardType::Treasure:
			player.addCoins(m_stats.loot);
			break;
		default:
			break;
	}
}

void Card::printInfo() const
{
	switch (m_effect)
	{
		case CardType::Battle:
			printBattleCardInfo(m_stats);
			break;
		case CardType::Buff:
			printBuffCardInfo(m_stats);
			break;
		case CardType::Heal:
			printHealCardInfo(m_stats);
			break;
		case CardType::Treasure:
			printTreasureCardInfo(m_stats);
			break;
		default:
			break;
	}
}

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
	Player player2 = player;
	player2.printInfo();
	return 0;
}