#pragma once
#include "Framework\console.h"
#include "Enemy.h"
#include "string"

class Item : public Enemy
{
protected:
	std::string name;
	int Heal;
	int addDmg;
	int itemChance;
	std::string Status;
	Enemy* Drops[2];

public:
	Item();
	void setItemName(std::string n);
	std::string getItemName();
	void setHealing(int h);
	int getHealing();
	void setNoStatus(std::string s);
	std::string getNoStatus();
	void itemDrops(Enemy* d);
	void setDmgBoost(int a);
	int getDmgBoost();
	~Item();
	void Barrel(Console& g_Console);
	void Box(Console& g_Console);
};