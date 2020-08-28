#include "Cutscenes.h"

void Cutscenes::animate(Console& g_Console)
{
	printmap(g_Console); 
}

void Cutscenes::nextdialogue(Console& g_Console)
{
	printmap(g_Console);
}

void Cutscenes::drawgrid(Console& g_Console, int x, int y, char chara)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = chara, 0x04);
}

void Cutscenes::drawgridG(Console& g_Console, int x, int y, char chara)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = chara, 0x0A);
}

void Cutscenes::drawgridLaserRight(Console& g_Console, int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '\\', 0x04);
	c.X = x - 3;
	c.Y = y - 3;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x04);
}

void Cutscenes::drawgridLaserLeft(Console& g_Console, int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '/', 0x04);
	c.X = x + 3;
	c.Y = y - 3;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x04);
}

void Cutscenes::drawgridLaserUp(Console& g_Console, int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = '^', 0x04);
	c.X = x;
	c.Y = y - 1;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x04);
}


void Cutscenes::cleargrid(Console& g_Console, int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x0A);
}

void Cutscenes::clearSprite(Console& g_Console)
{
	COORD c;
	for (int j = 2; j < 16; j++)
	{
		for (int i = 35; i < 78; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x0A);
		}
	}
}

void Cutscenes::clearRobertSprite(Console& g_Console)
{
	COORD c;
	for (int j = 3; j < 16; j++)
	{
		for (int i = 3; i < 27; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x0A);
		}
	}
}

void Cutscenes::clearSpriteLine(Console& g_Console, int y)
{
	COORD c;
	for (int i = 35; i < 78; i++)
	{
		c.X = i;
		c.Y = y;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x0A);
	}
}

void Cutscenes::clearRobertSpriteLine(Console& g_Console, int y)
{
	COORD c;
	for (int i = 3; i < 27; i++)
	{
		c.X = i;
		c.Y = y;
		g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x0A);
	}
}

void Cutscenes::clearScreen(Console& g_Console)
{
	COORD c;
	for (int j = 2; j <= 22; j++)
	{
		for (int i = 2; i <= 77; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c,' ', 0x00);
		}
	}
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
	drawgrid(g_Console, 9, 7, (char)12);
	animate(g_Console); 
	cleargrid(g_Console, 9, 7);
	drawgrid(g_Console, 13, 7, (char)12);
	animate(g_Console); 
	cleargrid(g_Console, 13, 7);
	drawgrid(g_Console, 11, 7, (char)12);
	printmap(g_Console);
	
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
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Caretaker: Argh!!");
	nextdialogue(g_Console);
	g_Console.writeToBuffer(c, "Caretaker: Save the children!! Take the fire extinguisher...");
	nextdialogue(g_Console);
	g_Console.writeToBuffer(c, "Objective: Take the fire extinguisher and put out the fire!");
	//system("pause");
}

void Cutscenes::CrowdStandstill(Console& g_Console)
{
	for (j = 11; j < 22; (j = j + 2))
	{
		for (i = 19; i < 60; (i = i + 2))
		{
			drawgrid(g_Console, i, j, (char)12);
		}
	}
	//even rows
	for (j = 12; j < 21; (j = j + 2))
	{
		for (i = 18; i < 61; (i = i + 2))
		{
			drawgrid(g_Console, i, j, (char)12);
		}
	}
}

void Cutscenes::CrowdStandstillclear(Console& g_Console)
{
	for (j = 11; j < 22; (j = j + 2))
	{
		for (i = 19; i < 60; (i = i + 2))
		{
			cleargrid(g_Console, i, j);
		}
	}
	//even rows
	for (j = 12; j < 21; (j = j + 2))
	{
		for (i = 18; i < 61; (i = i + 2))
		{
			cleargrid(g_Console, i, j);
		}
	}
}

void Cutscenes::CrowdMoveLeft(Console& g_Console)
{
	for (j = 11; j < 22; (j = j + 2))
	{
		for (i = 18; i < 59; (i = i + 2))
		{
			drawgrid(g_Console, i, j, (char)12);
		}
	}
	//even rows
	for (j = 12; j < 21; (j = j + 2))
	{
		for (i = 19; i < 62; (i = i + 2))
		{
			drawgrid(g_Console, i, j, (char)12);
		}
	}
}

void Cutscenes::CrowdMoveLeftclear(Console& g_Console)
{
	for (j = 11; j < 22; (j = j + 2))
	{
		for (i = 18; i < 59; (i = i + 2))
		{
			cleargrid(g_Console, i, j);
		}
	}
	//even rows
	for (j = 12; j < 21; (j = j + 2))
	{
		for (i = 19; i < 62; (i = i + 2))
		{
			cleargrid(g_Console, i, j);
		}
	}
}

void Cutscenes::CrowdMoveRight(Console& g_Console)
{
	for (j = 11; j < 22; (j = j + 2))
	{
		for (i = 20; i < 61; (i = i + 2))
		{
			drawgrid(g_Console, i, j, (char)12);
		}
	}
	//even rows
	for (j = 12; j < 21; (j = j + 2))
	{
		for (i = 17; i < 60; (i = i + 2))
		{
			drawgrid(g_Console, i, j, (char)12);
		}
	}
}

void Cutscenes::CrowdMoveRightclear(Console& g_Console)
{
	for (j = 11; j < 22; (j = j + 2))
	{
		for (i = 20; i < 61; (i = i + 2))
		{
			cleargrid(g_Console, i, j);
		}
	}
	//even rows
	for (j = 12; j < 21; (j = j + 2))
	{
		for (i = 17; i < 60; (i = i + 2))
		{
			cleargrid(g_Console, i, j);
		}
	}
}

void Cutscenes::medical_breakIn(Console& g_Console)
{
	COORD c;
	insideMedicalFacility(g_Console);
	//ref
	drawgrid(g_Console, 34, 12, 'H'); //Robert (Hero)
	drawgrid(g_Console, 34, 13, 'E'); //Ell

	//breaking in
	drawgrid(g_Console, 2, 12, (char)12);
	drawgrid(g_Console, 2, 13, (char)12);
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Ell: The hornets have broken in!");
	nextdialogue(g_Console);
	cleargrid(g_Console, 2, 12);
	cleargrid(g_Console, 2, 13);

	drawgrid(g_Console, 4, 11, (char)12);
	drawgrid(g_Console, 4, 14, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 4, 11);
	cleargrid(g_Console, 4, 14);

	drawgrid(g_Console, 6, 10, (char)12);
	drawgrid(g_Console, 6, 15, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 6, 10);
	cleargrid(g_Console, 6, 15);

	drawgrid(g_Console, 8, 9, (char)12);
	drawgrid(g_Console, 8, 16, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 8, 9);
	cleargrid(g_Console, 8, 16);

	drawgrid(g_Console, 10, 8, (char)12);
	drawgrid(g_Console, 10, 17, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 10, 8);
	cleargrid(g_Console, 10, 17);

	drawgrid(g_Console, 12, 7, (char)12);
	drawgrid(g_Console, 12, 18, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 12, 7);
	cleargrid(g_Console, 12, 18);

	drawgrid(g_Console, 14, 6, (char)12);
	drawgrid(g_Console, 14, 19, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 14, 6);
	cleargrid(g_Console, 14, 19);

	drawgrid(g_Console, 16, 5, (char)12);
	drawgrid(g_Console, 16, 20, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 16, 5);
	cleargrid(g_Console, 16, 20);

	drawgrid(g_Console, 18, 4, (char)12);
	drawgrid(g_Console, 18, 21, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 18, 4);
	cleargrid(g_Console, 18, 21);

	drawgrid(g_Console, 20, 3, (char)12);
	drawgrid(g_Console, 20, 22, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 20, 3);
	cleargrid(g_Console, 20, 22);

	//drawgrid(22, 2, (char)12);
	//drawgrid(21, 23, (char)12);
	//animate();
	//cleargrid(21, 1);
	//cleargrid(21, 23);

	//drawgrid(23, 0, (char)12);
	//drawgrid(23, 24, (char)12);
	//animate();
	//cleargrid(23, 0);
	//cleargrid(23, 24);

	//surround
	drawgrid(g_Console, 21, 4, (char)12);
	drawgrid(g_Console, 21, 21, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 21, 4);
	cleargrid(g_Console, 21, 21);

	drawgrid(g_Console, 22, 5, (char)12);
	drawgrid(g_Console, 22, 20, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 22, 5);
	cleargrid(g_Console, 22, 20);

	drawgrid(g_Console, 23, 6, (char)12);
	drawgrid(g_Console, 23, 19, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 23, 6);
	cleargrid(g_Console, 23, 19);

	drawgrid(g_Console, 24, 7, (char)12);
	drawgrid(g_Console, 24, 18, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 24, 7);
	cleargrid(g_Console, 24, 18);

	drawgrid(g_Console, 25, 8, (char)12);
	drawgrid(g_Console, 25, 17, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 25, 8);
	cleargrid(g_Console, 25, 17);

	drawgrid(g_Console, 27, 9, (char)12);
	drawgrid(g_Console, 26, 16, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 27, 9);
	cleargrid(g_Console, 26, 16);

	drawgrid(g_Console, 29, 10, (char)12);
	drawgrid(g_Console, 29, 15, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 29, 10);
	cleargrid(g_Console, 29, 15);

	drawgrid(g_Console, 31, 11, (char)12);
	drawgrid(g_Console, 31, 14, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 31, 11);
	cleargrid(g_Console, 31, 14);

	drawgrid(g_Console, 33, 12, (char)12);
	drawgrid(g_Console, 33, 13, (char)12);
	g_Console.writeToBuffer(c, "Robert: We have no choice but to fight them and buy some time for the patients to escape.");
	nextdialogue(g_Console);

	//battle screen

	//assume patients ran during battle
	cleargrid(g_Console, 33, 10); //bee 1
	cleargrid(g_Console, 33, 14); //bee 2
	cleargrid(g_Console, 35, 12); //1
	drawgrid(g_Console, 36, 12, (char)12); //change position for 1
	cleargrid(g_Console, 34, 11); //patient 2
	cleargrid(g_Console, 34, 14); //3
	cleargrid(g_Console, 35, 11); //4
	cleargrid(g_Console, 35, 14); //5
	cleargrid(g_Console, 35, 10); //6
	cleargrid(g_Console, 35, 15); //7
	cleargrid(g_Console, 35, 16); //Nurse
}
void Cutscenes::medical_breakIn_part2(Console& g_Console)
{
	COORD c;
	drawgrid(g_Console, 34, 12, 'H'); //Robert (Hero)
	drawgrid(g_Console, 34, 13, 'E'); //Ell
	//after battle, more bees break in
	drawgrid(g_Console, 32, 11, (char)12);
	drawgrid(g_Console, 32, 12, (char)12);
	drawgrid(g_Console, 32, 13, (char)12);
	drawgrid(g_Console, 32, 14, (char)12);
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Ell: There's more! They must have came while we were fighting!");
	nextdialogue(g_Console);

	//patient 1 push robert
	cleargrid(g_Console, 36, 12);
	drawgrid(g_Console, 35, 12, (char)12);
	cleargrid(g_Console, 34, 12);
	drawgrid(g_Console, 35, 12, 'H');
	animate(g_Console);

	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Ell: Robert!");
	nextdialogue(g_Console);
	//battle screen
	//assume patient 1 ran away
	//duibuqimafannile
}
//medical_fight cutscene was added to medical_breakIn cutscene

void Cutscenes::medical_fight(Console& g_Console)
{
	COORD c;
	//ref
	drawgrid(g_Console, 2, 12, 'H'); //Robert (Hero)
	drawgrid(g_Console, 2, 13, 'E'); //Ell
	drawgrid(g_Console, 35, 12, (char)12); //Patient 1
	drawgrid(g_Console, 36, 9, (char)12); //Patient 2
	drawgrid(g_Console, 36, 16, (char)12); //Patient 3
	drawgrid(g_Console, 46, 9, (char)12); //Patient 4
	drawgrid(g_Console, 46, 16, (char)12); //Patient 5
	drawgrid(g_Console, 56, 9, (char)12); //Patient 6
	drawgrid(g_Console, 56, 16, (char)12); //Patient 7
	drawgrid(g_Console, 23, 13, (char)12); //nurse
	animate(g_Console);

	//Robert walks to a patient 1 and gives medicine
	
	//drawgrid(g_Console, 34, 12, 'H'); //Robert (Hero)
	//drawgrid(g_Console, 34, 13, 'E'); //Ell
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Patient 1: Thank you so much!");
	nextdialogue(g_Console);

	//Patient 2 walks to Hero (34,11)
	cleargrid(g_Console, 36, 9);
	drawgrid(g_Console, 35, 10, (char)12); //Patient 2
	animate(g_Console);
	cleargrid(g_Console, 35, 10);

	drawgrid(g_Console, 34, 11, (char)12); //Patient 2
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Patient 2: You have so much medicine and you kept it from us? How shameless of you!");
	nextdialogue(g_Console);

	g_Console.writeToBuffer(c, "Patient 2: Give it to me! I'm obviously need it more than that bastard!");
	nextdialogue(g_Console);

	//Patient 3 walks to Hero (34,14)
	cleargrid(g_Console, 36, 16);
	drawgrid(g_Console, 35, 15, (char)12); //Patient 3
	animate(g_Console);
	cleargrid(g_Console, 35, 15);

	drawgrid(g_Console, 34, 14, (char)12); //Patient 3
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Patient 3: Please! I beg you, please give my daughter some medicine or she'll die!");
	nextdialogue(g_Console);

	//Patient 4 walks to Patient 1 (35,11)
	//Patient 1 (35,12)
	cleargrid(g_Console, 46, 9);
	drawgrid(g_Console, 42, 9, (char)12); //Patient 4
	animate(g_Console);
	cleargrid(g_Console, 42, 9);

	drawgrid(g_Console, 38, 10, (char)12); //Patient 4
	animate(g_Console);
	cleargrid(g_Console, 38, 10);

	drawgrid(g_Console, 35, 11, (char)12); //Patient 4
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Patient 4: Give that to me! I deserve that more than you!");
	nextdialogue(g_Console);

	g_Console.writeToBuffer(c, "Patient 1: Hands off! They're mine!");
	nextdialogue(g_Console);

	//Patient 5 walks to patient 1 / Hero (35,14)
	cleargrid(g_Console, 46, 16);
	drawgrid(g_Console, 42, 16, (char)12); //Patient 5
	animate(g_Console);
	cleargrid(g_Console, 42, 16);

	drawgrid(g_Console, 38, 15, (char)12); //Patient 5
	animate(g_Console);
	cleargrid(g_Console, 38, 15);

	drawgrid(g_Console, 35, 14, (char)12); //Patient 5
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Patient 5: You selfish prick, you are in such a healthy condition but you hog all the meds for yourself?");
	c.Y = 25;
	g_Console.writeToBuffer(c, "You don't even need it!");
	nextdialogue(g_Console);

	//Patient 6 walks to Hero (35,10)
	cleargrid(g_Console, 56, 9);
	drawgrid(g_Console, 52, 9, (char)12); //Patient 6
	animate(g_Console);
	cleargrid(g_Console, 52, 9);

	drawgrid(g_Console, 48, 9, (char)12); //Patient 6
	animate(g_Console);
	cleargrid(g_Console, 48, 9);

	drawgrid(g_Console, 44, 9, (char)12); //Patient 6
	animate(g_Console);
	cleargrid(g_Console, 44, 9);

	drawgrid(g_Console, 40, 9, (char)12); //Patient 6
	animate(g_Console);
	cleargrid(g_Console, 40, 9);

	drawgrid(g_Console, 35, 10, (char)12); //Patient 6
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Patient 6: Why do you have som muc medicine? You must have stolen it from us!");

	//Patient 7 walks to Hero (35,15)
	cleargrid(g_Console, 56, 16);
	drawgrid(g_Console, 52, 16, (char)12); //Patient 7
	animate(g_Console);
	cleargrid(g_Console, 52, 16);

	drawgrid(g_Console, 48, 16, (char)12); //Patient 7
	animate(g_Console);
	cleargrid(g_Console, 48, 16);

	drawgrid(g_Console, 44, 16, (char)12); //Patient 7
	animate(g_Console);
	cleargrid(g_Console, 44, 16);

	drawgrid(g_Console, 40, 16, (char)12); //Patient 7
	animate(g_Console);
	cleargrid(g_Console, 40, 16);

	drawgrid(g_Console, 35, 15, (char)12); //Patient 7
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Patient 7: Thief! Give it back!");

	//nurse tries to stop fight (35,16)
	cleargrid(g_Console, 23, 13);
	drawgrid(g_Console, 27, 14, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 27, 14);

	drawgrid(g_Console, 31, 15, (char)12);
	animate(g_Console);
	cleargrid(g_Console, 31, 15);
	
	drawgrid(g_Console, 35, 16, (char)12);
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Nurse: Everyone, please calm down!");

	//Oh no!! bees break in!! time to die
}

void Cutscenes::stealth3Dialogue(Console& g_Console)
{
	COORD c;
	dungeon_stealth3(g_Console);
	drawgrid(g_Console, 38, 12, 'R'); //Raymond
	drawgrid(g_Console, 40, 12, 'L'); //Robot/Lackey

	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Raymond: I want you to keep this secret between us, if anyone suspect or knows that");
	c.Y = 25;
	g_Console.writeToBuffer(c, "I am behind all this, I want you to eliminate them understand? ");
	nextdialogue(g_Console);

	c.Y = 24;
	g_Console.writeToBuffer(c, "Raymond: This secret is a matter of life and death, it MUST not get exposed.");
	nextdialogue(g_Console);

	g_Console.writeToBuffer(c, "Raymond: If this ever gets out, my plans to rule the world will be ruined.");
	nextdialogue(g_Console);

	g_Console.writeToBuffer(c, "Raymond: Anyways, I thought that I managed to get rid of that idiot of a security");
	c.Y = 25;
	g_Console.writeToBuffer(c, "guard during that break out in the abandoned facility.");
	nextdialogue(g_Console);

	c.Y = 24;
	g_Console.writeToBuffer(c, "Raymond: However, it seems like a young kid had saved him and now he has turned his back on us.");
	nextdialogue(g_Console);

	g_Console.writeToBuffer(c, "Raymond: I want you to find him and bring him to me. I want to show you what I do to traitors.");
	nextdialogue(g_Console);

	g_Console.writeToBuffer(c, "Raymond: I will get rid of anyone who stands in my way.");
	nextdialogue(g_Console);

	g_Console.writeToBuffer(c, "Raymond: I'll be waiting for your good news at the top floor of this building.");
	nextdialogue(g_Console);

	//walking away
	cleargrid(g_Console, 38, 12);
	cleargrid(g_Console, 40, 12);

	drawgrid(g_Console, 33, 11, 'R'); //Raymond
	drawgrid(g_Console, 43, 12, 'L'); //Robot/Lackey
	animate(g_Console);
	cleargrid(g_Console, 33, 11);
	cleargrid(g_Console, 43, 12);

	drawgrid(g_Console, 29, 10, 'R');
	drawgrid(g_Console, 46, 12, 'L');
	animate(g_Console);
	cleargrid(g_Console, 29, 10);
	cleargrid(g_Console, 46, 12);

	drawgrid(g_Console, 24, 9, 'R');
	drawgrid(g_Console, 49, 12, 'L');
	animate(g_Console);
	cleargrid(g_Console, 24, 9);
	cleargrid(g_Console, 49, 12);

	drawgrid(g_Console, 20, 8, 'R');
	drawgrid(g_Console, 52, 12, 'L');
	animate(g_Console);
	cleargrid(g_Console, 20, 8);
	cleargrid(g_Console, 52, 12);

	drawgrid(g_Console, 16, 7, 'R');
	drawgrid(g_Console, 55, 12, 'L');
	animate(g_Console);
	cleargrid(g_Console, 16, 7);
	cleargrid(g_Console, 55, 12);

	drawgrid(g_Console, 12, 6, 'R');
	drawgrid(g_Console, 58, 12, 'L');
	animate(g_Console);
	cleargrid(g_Console, 12, 6);
	cleargrid(g_Console, 58, 12);

	drawgrid(g_Console, 9, 5, 'R');
	drawgrid(g_Console, 61, 11, 'L');
	animate(g_Console);
	cleargrid(g_Console, 9, 5);
	cleargrid(g_Console, 61, 11);

	drawgrid(g_Console, 5, 4, 'R');
	drawgrid(g_Console, 61, 9, 'L');
	animate(g_Console);
	cleargrid(g_Console, 5, 4);
	cleargrid(g_Console, 61, 9);

	drawgrid(g_Console, 61, 7, 'L');
	animate(g_Console);
	cleargrid(g_Console, 61, 7);

	drawgrid(g_Console, 61, 5, 'L');
	animate(g_Console);
	cleargrid(g_Console, 61, 5);

	drawgrid(g_Console, 61, 3, 'L');
	animate(g_Console);
	cleargrid(g_Console, 61, 3);

	//drawgrid(63, 1, 'L');
	//animate();
	//cleargrid(63, 1);

	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "It seems like mayor Raymond was the mastermind behind all these incidents.");
	nextdialogue(g_Console);
	g_Console.writeToBuffer(c, "I should prepare before confronting him.");
}

void Cutscenes::bossBattleDialogue(Console& g_Console)
{
	//Raymond walks to Hero while talking
	COORD c;
	boss_room(g_Console);
	drawgrid(g_Console, 40, 21, 'H'); //Robert(Hero)

	drawgrid(g_Console, 60, 14, 'R');
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Raymond: It seems that the person I have been searching for came to me instead.");
	nextdialogue(g_Console);
	cleargrid(g_Console, 60, 14);

	drawgrid(g_Console, 57, 15, 'R');
	animate(g_Console);
	cleargrid(g_Console, 57, 15);

	drawgrid(g_Console, 55, 16, 'R');
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Raymond: I should thank you for saving me the trouble.");
	nextdialogue(g_Console);
	cleargrid(g_Console, 55, 16);

	drawgrid(g_Console, 52, 17, 'R');
	animate(g_Console);
	cleargrid(g_Console, 52, 17);

	drawgrid(g_Console, 50, 18, 'R');
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Raymond: So... have you came here to surrender?");
	nextdialogue(g_Console);
	cleargrid(g_Console, 50, 18);

	drawgrid(g_Console, 47, 19, 'R');
	animate(g_Console);
	cleargrid(g_Console, 47, 19);

	drawgrid(g_Console, 45, 20, 'R');
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Raymond: Why don't you join me and we can rule the world together?");
	nextdialogue(g_Console);
	cleargrid(g_Console, 45, 20);

	drawgrid(g_Console, 42, 21, 'R');
	animate(g_Console);
	cleargrid(g_Console, 42, 21);

	drawgrid(g_Console, 40, 20, 'R');
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Raymond: Actually nah, that's a bad idea. Only I can rule the world!!");
	nextdialogue(g_Console);
	cleargrid(g_Console, 40, 20);
}
//aaaa