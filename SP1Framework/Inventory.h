#pragma once
#include "Items.h"

class Inventory
{
private:
	Items **items;

public:
	Inventory();
	virtual ~Inventory();
};

