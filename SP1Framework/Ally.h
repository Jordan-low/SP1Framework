#pragma once
#include "Entity.h"

class Ally : public Entity
{
public:
	Ally();
	void setAlly(int x, int y, int health, int dmg, const char n);
	int getDmg();
	int getHealth();
	int getXCoords();
	int getYCoords();
	char getNamed();
	//int getAlly();
	~Ally();

};
