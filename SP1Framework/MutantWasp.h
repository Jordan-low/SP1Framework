#pragma once
#include "Enemy.h"

class MutantWasp : public Enemy
{
private:
	int chance;
public:
	MutantWasp();
	void Attack();
	void Debuff();
	void Drop();
	~MutantWasp();
};