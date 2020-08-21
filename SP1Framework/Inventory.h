#pragma once
#include "Items.h"
//j
class Inventory
{
private:
	Items **items;

public:
	Inventory();
	virtual ~Inventory();
};

