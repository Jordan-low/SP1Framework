#pragma once
#include "Entity.h"
#include "Framework/console.h"
//j
class Enemy : public Entity
{
public:
	bool attacked;
	bool attack;
	int Chance;
	Enemy();
	~Enemy();
	void setEnemy(int x, int y, int health, int dmg, const char n);
	int getD();
	int getH();
	int getX();
	int getY();
	char getName();
	//float Hit(float Eh, float Pd);
	//float beenHit(float Ph, float Ed);
	void Drop(Console& g_Console);
	void Poison(Console& g_Console);
};
