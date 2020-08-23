#pragma once
#include "Andrew's Item.h"
#include "string"

class Inventory : public Item
{
private:
	const char** items;
	int Quantity;
	std::string name;
	bool pickup;

public:
	Inventory();
	void setInventory(std::string n, int q);
	std::string getNameID();
	int getQuantity();
	void updateInventory();
	void checkInventory();
	~Inventory();
};