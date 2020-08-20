#pragma once
#include "Enemy.h"
#include "Poison.h"

class TutEnemy : public Enemy
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