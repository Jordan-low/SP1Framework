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
    void animate();
    void nextdialogue();
    char getgrid(int i, int j, char c);
    char cleargrid(int i, int j);
};

