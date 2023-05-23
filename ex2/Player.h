#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include "utilities.h"
const int DEFAULT_FORCE = 5;
const int DEFAULT_MAX_HP = 100;
const int START_LEVEL = 1;
const int START_COINS = 0;
const int MAX_LEVEL = 10;

class Player
{

public:
	/*
	* Constructor of Player class
	* @param name - The name of the player.
	* @param maxHp - The maximum health points of the player.
	* @param force - The force of the player.
	* @return
	*	     A new instance of Player.
	*/
	Player(const char* name, int maxHp = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);

	/*
	* Copy Constructor of Player class
	* @param other - The player to copy.
	* @return
	*      A new instance of Player.
	*/
	Player(const Player& other) = default;

	/*
	* Destructor of Player class
	*/
	~Player() = default;

	/*
	* Assignment Operator
	* @param other - The player to copy.
	* @return
	*      A reference to this instance of Player.
	*/
	Player& operator=(const Player& other) = default;

	/*
	* Prints the player's info
	*/
	void printInfo() const;

	/*
	* Level up the player
	*/
	void levelUp();

	/*
	* Get the level of the player
	* @return
	*      The level of the player.
	*/
	int getLevel() const;

	/*
	* Calculates the attack strength of the player
	* @return
	*      The attack strength of the player.
	*/
	int getAttackStrength() const;

	/*
	* Buffs the player's force by 'force' points
	* @param force - The number of points to buff.
	*/
	void buff(const int force);

	/*
	* Heals the player's health points by 'hp' points
	* @param hp - The number of points to heal.
	*/
	void heal(const int hp);

	/*
	* Damages the player's health points by 'hp' points
	* @param hp - The number of points to damage.
	*/
	void damage(const int hp);

	/*
	* Checks if the player is knocked out
	* @return true if the player is knocked out, false otherwise.
	*/
	bool isKnockedOut() const;

	/*
	* Add coins to the player
	* @param coins - The number of coins to add.
	*/
	void addCoins(const int coins);

	/*
	* Pay coins from the player
	* @param coins - The number of coins to pay.
	* @return true if the player has enough coins, false otherwise.
	*/
	bool pay(const int coins);

private: 
	std::string m_name;
	int m_maxHp;
	int m_healthPoints;
	int m_force;
	int m_level;
	int m_coins;
};
#endif