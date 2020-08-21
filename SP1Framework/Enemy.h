#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy();
	~Enemy();
	void setEnemy(const char n);
	int getD();
	int getH();
	int getX();
	int getY();
	char getName();
};

