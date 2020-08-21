#pragma once
#include <iostream>
#include "Windows.h"
#include "Enemy.h"
using namespace std;

class Poison : public Enemy
{
private:
	char Poisoned;

public:
	Poison();
	void setPoison();
	char getPoison();
	~Poison();
};

