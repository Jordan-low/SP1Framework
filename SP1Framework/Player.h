#pragma once
#include "Entity.h"
//j
class Player :
	public Entity
{
public:
	Player();
	~Player();
	void setPlayer(float x, float y, float health, float dmg, const char n);
	int GetDmg();
	int GetHealth();
	int GetXcoord();
	int GetYcoord();
	char GetPlayerName();
	void Attack();
};


