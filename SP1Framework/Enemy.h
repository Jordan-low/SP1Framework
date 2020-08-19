#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy();
	~Enemy();
	void setEnemy(const char n);
	short getEnemy();
	void Hit();
	void beenHit();
};

