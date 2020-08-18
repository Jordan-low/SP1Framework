#pragma once
#include "Enemy.h"

class Raymond : public Enemy
{
	Raymond();
	void Attack();
	void Talk();
	void Damaged();
	~Raymond();
};