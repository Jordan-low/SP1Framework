#pragma once
#include "Poison.h"

class TutEnemy : public Poison
{
private:
	int chance;

public:
	TutEnemy();
	void Attack();
	void Debuff();
	void Damaged();
	~TutEnemy();
};