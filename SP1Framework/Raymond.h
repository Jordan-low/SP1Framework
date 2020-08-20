#pragma once
#include "Enemy.h"
#include "Windows.h"

class Raymond : public Enemy
{
	Raymond();
	void Attack();
	void Talk();
	void Damaged();
	~Raymond();
};