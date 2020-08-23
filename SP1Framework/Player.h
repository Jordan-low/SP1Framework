#pragma once
#include "Entity.h"

class Player : public Entity

{
public:
	Player();
	~Player();
	void setPlayer(int x, int y, int health, int dmg, const char n);
	int GetDmg();
	int GetHealth();
	int GetXcoord();
	int GetYcoord();
	char GetPlayerName();
	void Attack();
	void Heal();
	void Equipment();
};


