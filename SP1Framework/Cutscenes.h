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
public:
    int i; int j;
    void animate(Console& g_Console);
    void nextdialogue(Console& g_Console);
    void drawgrid(Console& g_Console, int x, int y, char chara);
    void cleargrid(Console& g_Console, int x, int y);
    void orphanageCaretakerCutscene(Console& g_Console);
};

