#pragma once
#include "Damage.h"
#include <string>
#include <iostream>

using namespace std;

class Enemy : public Entity
{
private:
	string name;

public:
	Enemy();
	~Enemy();
	void setEnemy(string n);
	int getEnemy();
	string getName();
};

