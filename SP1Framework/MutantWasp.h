#pragma once
#include "Poison.h"
#include "Framework/console.h"

class MutantWasp : public Poison
{
private:
	int chance;
public:
	MutantWasp();
	void Attack();
	void Debuff();
	void Drop(Console& g_Console);
	void Damaged();
	~MutantWasp();
};

