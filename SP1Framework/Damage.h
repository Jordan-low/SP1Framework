#pragma once
#include "Entity.h"
class Damage : public Entity
{
private:
	int dmg;
	bool attacked;
	bool attack;

public:
	Damage();
	~Damage();
	void setDamage(int x);
	int getDamage();
	float Hit(float Eh, float Pd);
	float beenHit(float Ph, float Ed);
};
