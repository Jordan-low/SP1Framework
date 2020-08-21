#pragma once
#include "Enemy.h"
#include "Framework/console.h"

class Pig : public Enemy
{
private:
	Pig();
	void Attack();
	void Drop(Console& g_Console);
	void Damaged();
	~Pig();
};
//i
