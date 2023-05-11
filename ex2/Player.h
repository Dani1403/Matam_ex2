#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include "utilities.h"

class Player
{
	char* name;
	int level;
	int force;
	const int maxHp;
	int healthPoints;
	int coins;
public:
	Player(const char* name, int maxHp = 100, int force = 5);
	Player(const Player& other);
	~Player();
	Player& operator=(const Player& other);
	void printInfo() const;
	void levelUp();
	int getLevel();
	void buff(const int force);
	void heal(const int hp);
	void damage(const int hp);
	bool isKnockedOut() const;
	void addCoins(const int coins);
	bool pay(const int coins);
	int getAttackStrength() const;
};


#endif