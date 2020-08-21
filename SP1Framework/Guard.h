#pragma once
#include "Enemy.h"
#include "Framework/console.h"

class Guard : public Enemy
{
	Guard();
	void Attack();
	void Drop(Console& g_Console);
	void Damaged();
	~Guard();
};