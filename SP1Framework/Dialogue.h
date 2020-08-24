#pragma once
#include "Cutscenes.h"
#include "Framework\console.h"

class Dialogue :
    public Cutscenes
{
public:
    void Jerry(Console& g_Console);
    void Tom(Console& g_Console);
    void Bobby(Console& g_Console);
    void Harry(Console& g_Console);
    void Sam(Console& g_Console);
    void Emmanuel(Console& g_Console);
    void Charles(Console& g_Console);
};

