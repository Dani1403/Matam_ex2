#include <iostream>
#include "Player.h"


Player::Player(const char* name, int maxHp, int force) : 
	m_name(std::string(name)), m_maxHp(maxHp), m_healthPoints(maxHp), m_force(force), m_level(1), m_coins(0)
{
}

void Player::printInfo() const
{
	printPlayerInfo(m_name.c_str(), m_level, m_force, m_healthPoints, m_coins);
}

void Player::levelUp()
{
	m_level++;
}

int Player::getLevel() const 
{
	return m_level;
}

void Player::buff(const int force)
{
	m_force += force;
}

void Player::heal(const int hp)
{
	if (hp > 0)
	{
		m_healthPoints += hp;
		if (m_healthPoints > m_maxHp)
		{
			m_healthPoints = m_maxHp;
		}
	}
}

void Player::damage(const int hp)
{
	if (hp > 0)
	{
		m_healthPoints -= hp;
		if (m_healthPoints < 0)
		{
			m_healthPoints = 0;
		}
	}
}

bool Player::isKnockedOut() const
{
	return m_healthPoints == 0;
}

void Player::addCoins(const int coins)
{
	if (coins > 0)
	{
		m_coins += coins;
	}
}

bool Player::pay(const int coins)
{
	if (coins > 0 && m_coins >= coins)
	{
		m_coins -= coins;
		return true;
	}
	return false;
}

int Player::getAttackStrength() const
{
	return m_force + m_level;
}