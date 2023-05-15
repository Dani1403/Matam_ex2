#include <iostream>
#include "Player.h"


Player::Player(const char* name, int maxHp, int force) : m_maxHp(maxHp), m_force(force), m_healthPoints(maxHp), m_coins(0), m_level(1)
{
	this->m_name = new char[strlen(name) + 1];
	strcpy(this->m_name, name);
}

Player::Player(const Player& other) :
	m_maxHp(other.m_maxHp), m_force(other.m_force), m_healthPoints(other.m_healthPoints), m_coins(other.m_coins), m_level(other.m_level)
{
	this->m_name = new char[strlen(other.m_name) + 1];
	strcpy(this->m_name, other.m_name);
}

Player& Player::operator=(const Player& other)
{
	if (this != &other)
	{
		delete[] this->m_name;
		this->m_name = new char[strlen(other.m_name) + 1];
		strcpy(this->m_name, other.m_name);
		this->m_level = other.m_level;
		this->m_force = other.m_force;
		this->m_healthPoints = other.m_healthPoints;
		this->m_coins = other.m_coins;
	}
	return *this;
}

Player::~Player()
{
	delete[] this->m_name;
}

void Player::printInfo() const
{
	printPlayerInfo(this->m_name, this->m_level, this->m_force, this->m_healthPoints, this->m_coins);
}

void Player::levelUp()
{
	this->m_level++;
}

int Player::getLevel()
{
	return this->m_level;
}

void Player::buff(const int force)
{
	this->m_force += force;
}

void Player::heal(const int hp)
{
	if (hp > 0)
	{
		this->m_healthPoints += hp;
		if (this->m_healthPoints > this->m_maxHp)
		{
			this->m_healthPoints = this->m_maxHp;
		}
	}
}

void Player::damage(const int hp)
{
	if (hp > 0)
	{
		this->m_healthPoints -= hp;
		if (this->m_healthPoints < 0)
		{
			this->m_healthPoints = 0;
		}
	}
}

bool Player::isKnockedOut() const
{
	return this->m_healthPoints == 0;
}

void Player::addCoins(const int coins)
{
	if (coins > 0)
	{
		this->m_coins += coins;
	}
}

bool Player::pay(const int coins)
{
	if (coins > 0 && this->m_coins >= coins)
	{
		this->m_coins -= coins;
		return true;
	}
	return false;
}

int Player::getAttackStrength() const
{
	return this->m_force + this->m_level;
}

int main()
{
	Player player2("Gandalf", 300);
	std::cout << "Player 2 created successfully\n" << std::endl;
	player2.printInfo();
	player2.levelUp();
	player2.buff(1);
	player2.heal(10);
	player2.damage(20);
	if (player2.isKnockedOut())
	{
		std::cout << "Player 2 is knocked out" << std::endl;
	}
	else
	{
		std::cout << "Player 2 is not knocked out" << std::endl;
	}
	player2.addCoins(100);
	if (!player2.pay(10))
	{
		std::cout << "Player 2 doesn't have enough coins to pay" << std::endl;
	}
	else
	{
		std::cout << "Player 2 paid successfully" << std::endl;
	}
	std::cout << "the player's level is: " << player2.getLevel() << std::endl;
	std::cout << "the player's attack strength is: " << player2.getAttackStrength() << std::endl;
	player2.printInfo();
	return 0;
}