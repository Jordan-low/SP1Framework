#pragma once
#include "Damage.h"
#include <string>

using namespace std;

class Entity
{
protected:
	int x, y, h, d;
	char name;
	bool attack;
	bool attacked;
public:
	Entity();
	~Entity();
	virtual char GetName(); // for naming convention 
	int GetX(); // get x coord
	int GetY(); // get y coord
	int GetH(); // get health
	int GetD(); // get damage
	void SetD(int dmg);
	void SetH(int health);
	void SetX(int x_coord);
	void SetY(int y_coord);
};