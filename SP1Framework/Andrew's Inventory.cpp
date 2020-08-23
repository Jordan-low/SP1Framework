#include "Andrew's Inventory.h"

using namespace std;

Inventory::Inventory()
{
	items = new Item * [300];
	Quantity = 0;
	name = " ";
	pickup = false;
}

void Inventory::setInventory(string n, int q)
{
	const char* Items[8] = { "Raw Meat",  "Bread", "Burger", "Taco", "Cake", "Stinger", "Guard Armor", "Medicine" };
	name = n;
	Quantity = q;
}

string Inventory::getNameID()
{
	return name;
}

int Inventory::getQuantity()
{
	return Quantity;
}

void Inventory::updateInventory()
{
	while (pickup == true)
	{
		if ("Raw Meat")
		{
			Quantity++;
			getQuantity();
		}

		else if ("Bread")
		{
			Quantity++;
			getQuantity();
		}

		else if ("Burger")
		{
			Quantity++;
			getQuantity();
		}

		else if ("Taco")
		{
			Quantity++;
			getQuantity();
		}

		else if ("Cake")
		{
			Quantity++;
			getQuantity();
		}

		else if ("Stinger")
		{
			Quantity++;
			getQuantity();
		}

		else if ("Guard Armor")
		{
			Quantity++;
			getQuantity();
		}

		else if ("Medicine")
		{
			Quantity++;
			getQuantity();
		}

	}
}
	

Inventory::~Inventory()
{

}