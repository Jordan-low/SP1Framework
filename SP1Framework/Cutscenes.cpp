#include "Cutscenes.h"
#include "Map.h"

Map Maps;

void Cutscenes::animate(Console& g_Console)
{
	Maps.Border(g_Console);
	std::this_thread::sleep_for(std::chrono::milliseconds(300));
	system("cls");
}

void Cutscenes::nextdialogue(Console& g_Console)
{
	system("pause");
	system("cls");
	Maps.Border(g_Console);
}
//ack stonks
char Cutscenes::getgrid(Console& g_Console, int x, int y, char c)
{
	return (Grid[i][j] = c);
}

char Cutscenes::cleargrid(Console& g_Console, int x, int y)
{
	return (Grid[i][j] = ' ');
}

void Cutscenes::orphanageCaretakerCutscene(Console& g_Console, int x, int y, char chara)
{
	COORD c;
	x = 11;
	for (y = 0; y < 7; (y = y + 2))
	{
		(Grid[x][y] = '|');
		getgrid(g_Console, x, y, chara);
		animate(g_Console);
		cleargrid(g_Console, x, y);
		c.X = x;
		c.Y = y;
	}
	//help
	//MyMap.orphan6(); 
	animate(g_Console); 
	//MyMap.orphan7(); 
	animate(g_Console); 
	//MyMap.orphan8(); 
	Maps.Border(g_Console);
	g_Console.writeToBuffer(c, "Caretaker: Argh!!");
	nextdialogue(g_Console);
	g_Console.writeToBuffer(c, "Caretaker: Save the children!! Take the fire extinguisher...");
	nextdialogue(g_Console);
	g_Console.writeToBuffer(c, "Objective: Take the fire extinguisher and put out the fire!");
	system("pause");
}

