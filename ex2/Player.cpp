#include <iostream>
#include "Player.h"


Player::Player(const char* name, int maxHp, int force) : maxHp(maxHp)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->level = 1;
	this->force = force;
	this->healthPoints = maxHp;
	this->coins = 0;
}

Player::Player(const Player& other) : maxHp(other.maxHp)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->level = other.level;
	this->force = other.force;
	this->healthPoints = other.healthPoints;
	this->coins = other.coins;
}

Player& Player::operator=(const Player& other)
{
	if (this != &other)
	{
		delete[] this->name;
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
		this->level = other.level;
		this->force = other.force;
		this->healthPoints = other.healthPoints;
		this->coins = other.coins;
	}
	return *this;
}

Player::~Player()
{
	delete[] this->name;
}

void Player::printInfo() const
{
	printPlayerInfo(this->name, this->level, this->force, this->healthPoints, this->coins);
}

void Player::levelUp()
{
	this->level++;
}

int Player::getLevel()
{
	return this->level;
}

void Player::buff(const int force)
{
	this->force += force;
}

void Player::heal(const int hp)
{
	if (hp > 0)
	{
		this->healthPoints += hp;
		if (this->healthPoints > this->maxHp)
		{
			this->healthPoints = this->maxHp;
		}
	}
}

void Player::damage(const int hp)
{
	if (hp > 0)
	{
		this->healthPoints -= hp;
		if (this->healthPoints < 0)
		{
			this->healthPoints = 0;
		}
	}
}

bool Player::isKnockedOut() const
{
	return this->healthPoints == 0;
}

void Player::addCoins(const int coins)
{
	if (coins > 0)
	{
		this->coins += coins;
	}
}

bool Player::pay(const int coins)
{
	if (coins > 0 && this->coins >= coins)
	{
		this->coins -= coins;
		return true;
	}
	return false;
}

int Player::getAttackStrength() const
{
	return this->force + this->level;
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