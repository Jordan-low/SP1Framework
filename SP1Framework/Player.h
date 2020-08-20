#pragma once
#include "Entity.h"

class Player :
	public Entity
{
public:
	Player();
	~Player();
	void setPlayer();
	int GetDmg();
	int GetHealth();
	int GetXcoord();
	int GetYcoord();
	char GetPlayerName();
	void Attack();
};


