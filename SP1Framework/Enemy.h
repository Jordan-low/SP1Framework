#pragma once
#include "Damage.h"
#include <string>
#include <iostream>

using namespace std;

class Enemy : public Damage
{
public:
	short HP;
	short Atk;
	string name;
	Enemy();
	~Enemy();
	void setEnemy(int h, int d, string n);
	short getEnemy();
	string getName();
};