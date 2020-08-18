#pragma once
#include "Enemy.h"
#include "Damage.h"

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