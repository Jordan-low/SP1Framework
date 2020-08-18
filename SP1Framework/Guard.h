#pragma once
#include "Enemy.h"

class Guard : public Enemy
{
	Guard();
	void Attack();
	void Drop();
	void Damaged();
	~Guard();
};