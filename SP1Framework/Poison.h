#pragma once
#include <iostream>
#include "Windows.h"
#include "Framework/console.h"
#include "Enemy.h"//j
using namespace std;

class Poison : public Enemy
{
private:
	char Poisoned;

public:
	Poison();
	//void setPoison(Console& g_Console);
	//char getPoison();
	~Poison();
};

