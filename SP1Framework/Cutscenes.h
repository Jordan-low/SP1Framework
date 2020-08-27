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
    void cleargrid(Console& g_Console, int x, int y);
    void clearSprite(Console& g_Console);
    void clearRobertSprite(Console& g_Console);
    void clearSpriteLine(Console& g_Console, int y);
    void clearRobertSpriteLine(Console& g_Console, int y);
    void orphanageCaretakerCutscene(Console& g_Console);
    
    //crowd animations for protest area
    void CrowdStandstill(Console& g_Console);
    void CrowdStandstillclear(Console& g_Console);
    void CrowdMoveLeft(Console& g_Console);
    void CrowdMoveLeftclear(Console& g_Console);
    void CrowdMoveRight(Console& g_Console);
    void CrowdMoveRightclear(Console& g_Console);

    void medical_breakIn(Console& g_Console); //2 bees break in
    void medical_breakIn_part2(Console& g_Console); //more bees break in, robert pushed by patient 1
    void medical_fight(Console& g_Console);
    void stealth3Dialogue(Console& g_Console);
    void bossBattleDialogue(Console& g_Console);
};

