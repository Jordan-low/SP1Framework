#pragma once

#include <string>

using std::string;

enum ItemsType { Armour, Weapons };

class Items {
private:
    string IName;
    int Iint;
    ItemsType IType;
    string Name;
    int Heal;

public:
    // Default Constructor
    Items();

    int GetHeal();

    void setItems(char* nameid);


};