#pragma once
#include "Entity.h"

class Ally : public Entity
{
public:
	Ally();
	void setAlly();
	int getDmg();
	int getHealth();
	int getXCoords();
	int getYCoords();
	char getNamed();
	int getAlly();
	~Ally();

};
