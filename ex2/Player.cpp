#include <iostream>
#include "Player.h"


Player::Player(const char* name, int maxHp, int force)
{
	m_name = name;
	m_level = START_LEVEL;
	m_coins = START_COINS;
	if (maxHp <= 0)
	{
		m_maxHp = DEFAULT_MAX_HP;
		m_healthPoints = DEFAULT_MAX_HP;
	}
	else
	{
		m_maxHp = maxHp;
		m_healthPoints = maxHp;
	}
	if (force <= 0)
	{
		m_force = DEFAULT_FORCE;
	}
	else
	{
		m_force = force;
	}
}

void Player::printInfo() const
{
	printPlayerInfo(m_name.c_str(), m_level, m_force, m_healthPoints, m_coins);
}

void Player::levelUp()
{
	if (m_level < MAX_LEVEL)
	{
		m_level++;
	}
}

int Player::getLevel() const 
{
	return m_level;
}

void Player::buff(const int force)
{
	if (force > 0)
{
		m_force += force;
	}
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
	return m_healthPoints <= 0;
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
	if (m_coins - coins < 0)
	{
		return false;
	}
	m_coins -= coins;
	return true;
}

int Player::getAttackStrength() const
{
	return m_force + m_level;
}