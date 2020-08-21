#include "Cutscenes.h"
#include "Map.h"

Map Maps;
void Cutscenes::animate(Console& g_Console)
{
	Maps.printmap(g_Console); 
	std::this_thread::sleep_for(std::chrono::milliseconds(300));
	system("cls"); 
}

void Cutscenes::nextdialogue(Console& g_Console)
{
	system("pause");
	system("cls");
	Maps.printmap(g_Console);
}

void Cutscenes::drawgrid(Console& g_Console, int x, int y, char chara)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, chara, 0x1A);
}

void Cutscenes::cleargrid(Console& g_Console, int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c,' ', 0x1A);
}

void Cutscenes::orphanageCaretakerCutscene(Console& g_Console)
{
	COORD c;
	orphanage(g_Console);

	//spike hitting caretaker
	drawgrid(g_Console, 11, 0, '|');
	animate(g_Console);
	cleargrid(g_Console, 11, 0);
	drawgrid(g_Console, 11, 2, '|');
	animate(g_Console);
	cleargrid(g_Console, 11, 2);
	drawgrid(g_Console, 11, 4, '|');
	animate(g_Console);
	cleargrid(g_Console, 11, 4);
	drawgrid(g_Console, 11, 6, '|');
	animate(g_Console);
	cleargrid(g_Console, 11, 6);

	//caretaker stumbling
	cleargrid(g_Console, 11, 7);
	drawgrid(g_Console, 9, 7, 'O');
	animate(g_Console); 
	cleargrid(g_Console, 9, 7);
	drawgrid(g_Console, 13, 7, 'O');
	animate(g_Console); 
	cleargrid(g_Console, 13, 7);
	drawgrid(g_Console, 11, 7, 'O');
	Maps.printmap(g_Console);
	
	//fire appearing
	//fire appearing
	j = 6;
	for (i = 9; i < 14; i++)
	{
		drawgrid(g_Console, i, j, '-');
	}
	animate(g_Console);
	j = 8;
	for (i = 9; i < 14; i++)
	{
		drawgrid(g_Console, i, j, '-');
	}
	animate(g_Console);
	drawgrid(g_Console, 9, 7, '|');
	animate(g_Console);
	drawgrid(g_Console, 13, 7, '|');
	printmap(g_Console);
	//dialogue
	c.X = 1;
	c.Y = 25;
	g_Console.writeToBuffer(c, "Caretaker: Argh!!");
	nextdialogue(g_Console);
	g_Console.writeToBuffer(c, "Caretaker: Save the children!! Take the fire extinguisher...");
	nextdialogue(g_Console);
	g_Console.writeToBuffer(c, "Objective: Take the fire extinguisher and put out the fire!");
	system("pause");
}
//aaaa