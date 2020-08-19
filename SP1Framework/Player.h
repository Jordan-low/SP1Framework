#pragma once
#include "Entity.h"

class Player :
	public Entity
{
public:
	Player();
	~Player();
	void setPlayer();
	int getPlayer();
	char GetName();
	void Attack();
};


