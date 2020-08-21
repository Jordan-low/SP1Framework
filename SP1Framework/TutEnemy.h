#pragma once
#include "Poison.h"

class TutEnemy : public Poison
{
private:
	int chance;

public:
	TutEnemy();
	void Attack();
	void Debuff(Console& g_Console);
	void Damaged();
	~TutEnemy();
};