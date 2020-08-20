#pragma once
#include "Enemy.h"
#include "Poison.h"

class MutantWasp : public Enemy
{
private:
	int chance;
public:
	MutantWasp();
	void Attack();
	void Debuff();
	void Drop();
	void Damaged();
	~MutantWasp();
};

