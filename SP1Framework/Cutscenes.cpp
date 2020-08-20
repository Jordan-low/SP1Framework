#include "Cutscenes.h"
#include "Map.h"

Map Maps;
void Cutscenes::animate(Console& g_Console)
{
	Maps.printmap(g_Console); 
	std::this_thread::sleep_for(std::chrono::milliseconds(300));
	system("cls"); //this shows the press any key thing
}

void Cutscenes::nextdialogue(Console& g_Console)
{
	system("pause");
	system("cls");
	Maps.printmap(g_Console);
}

char Cutscenes::getgrid(Console& g_Console, int x, int y, char chara)
{
	return (Grid[x][y] = chara);
}

char Cutscenes::cleargrid(Console& g_Console, int x, int y)
{
	return (Grid[x][y] = ' ');
}

void Cutscenes::orphanageCaretakerCutscene(Console& g_Console, int x, int y, char chara)
{
	
	Maps.initialise(g_Console);
	Maps.orphanage(g_Console);
	Maps.printmap(g_Console);
	COORD c;
	c.X = x;
	c.Y = y;
	x = 11;
	for (y = 0; y < 7; (y = y + 2))
	{
		(Grid[c.X][c.Y] = '|');
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x1A);
		animate(g_Console); //here
		
		cleargrid(g_Console, x, y);
	}
	cleargrid(g_Console, 11, 7);
	getgrid(g_Console, 9, 7, 'O');
	animate(g_Console); 
	cleargrid(g_Console, 9, 7);
	getgrid(g_Console, 13, 7, 'O');
	animate(g_Console); 
	cleargrid(g_Console, 13, 7);
	getgrid(g_Console, 11, 7, 'O');
	Maps.printmap(g_Console);
	
	c.X = 1;
	c.Y = 25;
	g_Console.writeToBuffer(c, "Caretaker: Argh!!");
	nextdialogue(g_Console);
	g_Console.writeToBuffer(c, "Caretaker: Save the children!! Take the fire extinguisher...");
	nextdialogue(g_Console);
	g_Console.writeToBuffer(c, "Objective: Take the fire extinguisher and put out the fire!");
	system("pause");
}

