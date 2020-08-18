#pragma once
#include "Enemy.h"

class Pig : public Enemy
{
private:
	Pig();
	void Attack();
	void Drop();
	~Pig();
};
