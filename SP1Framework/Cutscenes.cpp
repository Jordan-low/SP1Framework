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

char Cutscenes::getgrid(Console& g_Console, int x, int y, char c)
{
	return (Grid[i][j] = c);
}

char Cutscenes::cleargrid(Console& g_Console, int x, int y)
{
	return (Grid[i][j] = ' ');
}
