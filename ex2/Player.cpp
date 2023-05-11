#include <iostream>
#include "Player.h"

/*
* Constructor
*/
Player::Player(const char* name, int maxHp, int force) : maxHp(maxHp)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->level = 1;
	this->force = force;
	this->healthPoints = maxHp;
	this->coins = 0;
}

/*
* Copy Constructor
*/
Player::Player(const Player& other) : maxHp(other.maxHp)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->level = other.level;
	this->force = other.force;
	this->healthPoints = other.healthPoints;
	this->coins = other.coins;
}

/*
* Assignment Operator
*/
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

/*
* Destructor
*/
Player::~Player()
{
	delete[] this->name;
}

/*
* Prints the player's info
* Uses the printPlayerInfo function from utilities.h
*/
void Player::printInfo() const
{
	printPlayerInfo(this->name, this->level, this->force, this->healthPoints, this->coins);
}

/*
* Levels up the player
* */
void Player::levelUp()
{
	this->level++;
}

/*
* @return the player's level
*/
int Player::getLevel()
{
	return this->level;
}

/*
* Buffs the player's force
* @param force - the amount of force to add
*/
void Player::buff(const int force)
{
	this->force += force;
}

/*
* Heals the player
* @param hp - the amount of hp to heal
*/
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

/*
* Damages the player
* @param hp - the amount of hp to damage
*/
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

/*
* Checks if the player is knocked out
*/
bool Player::isKnockedOut() const
{
	return this->healthPoints == 0;
}

/*
* Adds coins to the player
* @param coins - the amount of coins to add
*/
void Player::addCoins(const int coins)
{
	if (coins > 0)
	{
		this->coins += coins;
	}
}

/*
* Pays coins from the player
* @param coins - the amount of coins to pay
* @return true if the player has enough coins to pay, false otherwise
* if the player doesn't have enough coins, the function does nothing
* if the player has enough coins, the function removes them from the player count
*/
bool Player::pay(const int coins)
{
	if (coins > 0 && this->coins >= coins)
	{
		this->coins -= coins;
		return true;
	}
	return false;
}

/*
* @return the player's attack strength
*/
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