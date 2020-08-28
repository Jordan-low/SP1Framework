#pragma once
#include "Cutscenes.h"
class Minigame :
    public Cutscenes
{
public:
    void wire_game(Console& g_Console);
    void skull_game(Console& g_Console);
    void trueSkull(Console& g_Console);
    void letter(Console& g_Console);
};

