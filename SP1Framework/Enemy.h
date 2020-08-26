#pragma once
#include "Entity.h"
#include "Framework/console.h"
//j
class Enemy : public Entity
{
private:
	bool attackEnemy;
	bool attackPlayer;
	int Chance;
public:
	Enemy();
	~Enemy();
	void setEnemy(int x, int y, int health, int dmg, const char n);
	int getD();
	int getH();
	int getX();
	int getY();
	char getName();
	int Hit(int Eh, int Pd);
	int beenHit(int Ph, int Ed);
	void Drop(Console& g_Console);
	bool Poison(Console& g_Console);
};
