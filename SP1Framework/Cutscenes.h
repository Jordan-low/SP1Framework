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
    
    //crowd animations for protest area
    void CrowdStandstill(Console& g_Console);
    void CrowdStandstillclear(Console& g_Console);
    void CrowdMoveLeft(Console& g_Console);
    void CrowdMoveLeftclear(Console& g_Console);
    void CrowdMoveRight(Console& g_Console);
    void CrowdMoveRightclear(Console& g_Console);

    void medical_breakIn(Console& g_Console);
    void medical_fight(Console& g_Console);
    void stealth3Dialogue(Console& g_Console);
    void bossBattleDialogue(Console& g_Console);
};

