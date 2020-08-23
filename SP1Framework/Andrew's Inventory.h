#pragma once
#include "Andrew's Item.h"
#include <iostream>
#include "string"

class Inventory : public Item
{
private:
	Item** items;
	int Quantity;
	std::string name;
	bool pickup;

public:
	Inventory();
	void setInventory(std::string n, int q);
	std::string getNameID();
	int getQuantity();
	void updateInventory();
	~Inventory();
};