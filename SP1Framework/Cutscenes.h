#pragma once
#include "Map.h"
#include "Framework\console.h"
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>

class Cutscenes :
    public Map
{
    char c;
    void animate(Console& g_Console);
    void nextdialogue(Console& g_Console);
    char getgrid(Console& g_Console, int x, int y, char c);
    char cleargrid(Console& g_Console, int x, int y);

    void orphanageCaretakerCutscene(Console& g_Console, int x, int y, char c);
};

