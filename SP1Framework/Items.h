#pragma once

#include <string>
//j
using std::string;

enum ItemsType { Armour, Weapons };

class Items {
private:
    string IName;
    int Iint;
    ItemsType IType;
    string Name;
    int addhealth;

public:
    // Default Constructor
    Items();

    int GetHeal();

    void setItems(char* nameid);


};

class Items
{
};
