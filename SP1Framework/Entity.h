#pragma once
#include "Damage.h"
#include "Item.h"
//#include "game.h"
//j
using namespace std;

class Entity : public Damage
{
protected:
	//int x, y;
	int h, d;
	char name;
public:
	Entity();
	~Entity();
	virtual char GetName(); // for naming convention 
	//int GetX(); // get x coord
	//int GetY(); // get y coord
	int GetH(); // get health
	int GetD(); // get damage
	void SetD(int dmg);
	void SetH(int health);
	//void SetX(int x_coord);
	//void SetY(int y_coord);
	int randNum();
};