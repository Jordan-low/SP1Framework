#pragma once
#include "Poison.h"

class MutantWasp : public Poison
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

