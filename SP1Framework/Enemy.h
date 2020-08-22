#pragma once
#include "Entity.h"
//j
class Enemy : public Entity
{
public:
	bool attacked;
	bool attack;
	Enemy();
	~Enemy();
	void setEnemy(const char n);
	int getD();
	int getH();
	int getX();
	int getY();
	char getName();
	float Hit(float Eh, float Pd);
	float beenHit(float Ph, float Ed);
};
