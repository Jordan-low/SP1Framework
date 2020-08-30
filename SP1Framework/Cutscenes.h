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
    void drawgrid(Console& g_Console, int x, int y, char chara); //draws in red
    void drawgridG(Console& g_Console, int x, int y, char chara); //draws in green
    void drawgridY(Console& g_Console, int x, int y, char chara); //draws in green
    void drawgridW(Console& g_Console, int x, int y, char chara);
    void drawPatients(Console& g_Console, int x, int y, char chara); // draw pink patients
    void cleargrid(Console& g_Console, int x, int y);
    void clearSprite(Console& g_Console);
    void clearRobertSprite(Console& g_Console);
    void clearSpriteLine(Console& g_Console, int y);
    void clearRobertSpriteLine(Console& g_Console, int y);
    void clearRaymondSpriteLine(Console& g_Console, int y);
    void clearScreen(Console& g_Console);

    //animations for raymond battle phase 2
    void drawgridLaserRight(Console& g_Console, int x, int y);
    void drawgridLaserLeft(Console& g_Console, int x, int y);
    void drawgridLaserUp(Console& g_Console, int x, int y);
    void stickmanLeft(Console& g_Console, int x, int y);
    void movingBlock(Console& g_Console, int x, int y);
    void breakFloor(Console& g_Console, int x, int y);

    //crowd animations for protest area
    void CrowdStandstill(Console& g_Console);
    void CrowdStandstillclear(Console& g_Console);
    void CrowdMoveLeft(Console& g_Console);
    void CrowdMoveLeftclear(Console& g_Console);
    void CrowdMoveRight(Console& g_Console);
    void CrowdMoveRightclear(Console& g_Console);
};

