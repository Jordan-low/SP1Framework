#pragma once
#include <iostream>
#include "Windows.h"
#include "Entity.h"
using namespace std;

class Poison : public Entity
{
private:
	char Poisoned;

public:
	Poison();
	void setPoison();
	char getPoison();
	~Poison();
};

