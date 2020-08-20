#include "Cutscenes.h"


void Cutscenes::animate()
{
	Border(g_Console);
	std::this_thread::sleep_for(std::chrono::milliseconds(300));
	system("cls");
}

void Cutscenes::nextdialogue()
{
	system("pause");
	system("cls");
	Border(g_Console);
}

char Cutscenes::getgrid(int i, int j, char c)
{
	return (Grid[i][j] = c);
}

char Cutscenes::cleargrid(int i, int j)
{
	return (Grid[i][j] = ' ');
}
