#pragma once

#include <string>//j

using std::string;

enum ConsumableType { Food, Potion, };

class Consumable {
private:
    string mName;
    int mHeal;
    ConsumableType mType;
    string Name;
    int Heal;

public:
    // Default Constructor
    Consumable();

    int GetHeal();


};

class Consumable
{
};
