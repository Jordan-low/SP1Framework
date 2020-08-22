#pragma once
#include "Entity.h"

class Ally : public Entity
{
public:
	Ally();
	void setAlly(float x, float y, float health, float dmg, const char n);
	int getDmg();
	int getHealth();
	int getXCoords();
	int getYCoords();
	char getNamed();
	//int getAlly();
	~Ally();

};
