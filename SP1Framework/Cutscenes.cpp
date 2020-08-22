#include "Cutscenes.h"

void Cutscenes::animate(Console& g_Console)
{
	printmap(g_Console); 
	//std::this_thread::sleep_for(std::chrono::milliseconds(300));
	//system("cls"); 
}

void Cutscenes::nextdialogue(Console& g_Console)
{
	//system("pause");
	//system("cls");
	printmap(g_Console);
}

void Cutscenes::drawgrid(Console& g_Console, int x, int y, char chara)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = chara, 0x1A);
}

void Cutscenes::cleargrid(Console& g_Console, int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x1A);
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


void Cutscenes::medical_breakIn(Console& g_Console)
{
	COORD c;
	insideMedicalFacility(g_Console);

	drawgrid(g_Console, 34, 12, 'R'); //Robert
	drawgrid(g_Console, 34, 13, 'E'); //Ell

	//breaking in
	drawgrid(g_Console, 2, 12, 'O');
	drawgrid(g_Console, 2, 13, 'O');
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Ell: The hornets have broken in!");
	nextdialogue(g_Console);
	cleargrid(g_Console, 2, 12);
	cleargrid(g_Console, 2, 13);

	drawgrid(g_Console, 4, 11, 'O');
	drawgrid(g_Console, 4, 14, 'O');
	animate(g_Console);
	cleargrid(g_Console, 4, 11);
	cleargrid(g_Console, 4, 14);

	drawgrid(g_Console, 6, 10, 'O');
	drawgrid(g_Console, 6, 15, 'O');
	animate(g_Console);
	cleargrid(g_Console, 6, 10);
	cleargrid(g_Console, 6, 15);

	drawgrid(g_Console, 8, 9, 'O');
	drawgrid(g_Console, 8, 16, 'O');
	animate(g_Console);
	cleargrid(g_Console, 8, 9);
	cleargrid(g_Console, 8, 16);

	drawgrid(g_Console, 10, 8, 'O');
	drawgrid(g_Console, 10, 17, 'O');
	animate(g_Console);
	cleargrid(g_Console, 10, 8);
	cleargrid(g_Console, 10, 17);

	drawgrid(g_Console, 12, 7, 'O');
	drawgrid(g_Console, 12, 18, 'O');
	animate(g_Console);
	cleargrid(g_Console, 12, 7);
	cleargrid(g_Console, 12, 18);

	drawgrid(g_Console, 14, 6, 'O');
	drawgrid(g_Console, 14, 19, 'O');
	animate(g_Console);
	cleargrid(g_Console, 14, 6);
	cleargrid(g_Console, 14, 19);

	drawgrid(g_Console, 16, 5, 'O');
	drawgrid(g_Console, 16, 20, 'O');
	animate(g_Console);
	cleargrid(g_Console, 16, 5);
	cleargrid(g_Console, 16, 20);

	drawgrid(g_Console, 18, 4, 'O');
	drawgrid(g_Console, 18, 21, 'O');
	animate(g_Console);
	cleargrid(g_Console, 18, 4);
	cleargrid(g_Console, 18, 21);

	drawgrid(g_Console, 20, 3, 'O');
	drawgrid(g_Console, 20, 22, 'O');
	animate(g_Console);
	cleargrid(g_Console, 20, 3);
	cleargrid(g_Console, 20, 22);

	//drawgrid(22, 2, 'O');
	//drawgrid(21, 23, 'O');
	//animate();
	//cleargrid(21, 1);
	//cleargrid(21, 23);

	//drawgrid(23, 0, 'O');
	//drawgrid(23, 24, 'O');
	//animate();
	//cleargrid(23, 0);
	//cleargrid(23, 24);

	//surround
	drawgrid(g_Console, 21, 4, 'O');
	drawgrid(g_Console, 21, 21, 'O');
	animate(g_Console);
	cleargrid(g_Console, 21, 4);
	cleargrid(g_Console, 21, 21);

	drawgrid(g_Console, 22, 5, 'O');
	drawgrid(g_Console, 22, 20, 'O');
	animate(g_Console);
	cleargrid(g_Console, 22, 5);
	cleargrid(g_Console, 22, 20);

	drawgrid(g_Console, 23, 6, 'O');
	drawgrid(g_Console, 23, 19, 'O');
	animate(g_Console);
	cleargrid(g_Console, 23, 6);
	cleargrid(g_Console, 23, 19);

	drawgrid(g_Console, 24, 7, 'O');
	drawgrid(g_Console, 24, 18, 'O');
	animate(g_Console);
	cleargrid(g_Console, 24, 7);
	cleargrid(g_Console, 24, 18);

	drawgrid(g_Console, 25, 8, 'O');
	drawgrid(g_Console, 25, 17, 'O');
	animate(g_Console);
	cleargrid(g_Console, 25, 8);
	cleargrid(g_Console, 25, 17);

	drawgrid(g_Console, 26, 9, 'O');
	drawgrid(g_Console, 26, 16, 'O');
	animate(g_Console);
	cleargrid(g_Console, 26, 9);
	cleargrid(g_Console, 26, 16);

	drawgrid(g_Console, 27, 10, 'O');
	drawgrid(g_Console, 27, 15, 'O');
	animate(g_Console);
	cleargrid(g_Console, 27, 10);
	cleargrid(g_Console, 27, 15);

	drawgrid(g_Console, 28, 11, 'O');
	drawgrid(g_Console, 28, 14, 'O');
	c.X = 5;
	c.Y = 24;
	g_Console.writeToBuffer(c, "Ell: Oh no! We're surrounded!");
	nextdialogue(g_Console);
	cleargrid(g_Console, 28, 11);
	cleargrid(g_Console, 28, 14);

	//drawgrid(32, 9, 'O');
	//drawgrid(32, 15, 'O');
	//animate();
	//cleargrid(32, 9);
	//cleargrid(32, 15);

	//drawgrid(33, 10, 'O');
	//drawgrid(33, 14, 'O');
	//animate();
	//cleargrid(33, 10);
	//cleargrid(33, 14);

	//drawgrid(34, 11, 'O');
	//drawgrid(34, 14, 'O');
	//nextdialogue("Ell : Oh no! We're surrounded!");
	//cleargrid(34, 11);
	//cleargrid(34, 14);
}

void Cutscenes::stealth3Dialogue(Console& g_Console)
{
	COORD c;
	dungeon_stealth3(g_Console);
	drawgrid(g_Console, 38, 12, 'O'); //Raymond
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

	drawgrid(g_Console, 33, 11, 'O'); //Raymond
	drawgrid(g_Console, 43, 12, 'L'); //Robot/Lackey
	animate(g_Console);
	cleargrid(g_Console, 33, 11);
	cleargrid(g_Console, 43, 12);

	drawgrid(g_Console, 29, 10, 'O');
	drawgrid(g_Console, 46, 12, 'L');
	animate(g_Console);
	cleargrid(g_Console, 29, 10);
	cleargrid(g_Console, 46, 12);

	drawgrid(g_Console, 24, 9, 'O');
	drawgrid(g_Console, 49, 12, 'L');
	animate(g_Console);
	cleargrid(g_Console, 24, 9);
	cleargrid(g_Console, 49, 12);

	drawgrid(g_Console, 20, 8, 'O');
	drawgrid(g_Console, 52, 12, 'L');
	animate(g_Console);
	cleargrid(g_Console, 20, 8);
	cleargrid(g_Console, 52, 12);

	drawgrid(g_Console, 16, 7, 'O');
	drawgrid(g_Console, 55, 12, 'L');
	animate(g_Console);
	cleargrid(g_Console, 16, 7);
	cleargrid(g_Console, 55, 12);

	drawgrid(g_Console, 12, 6, 'O');
	drawgrid(g_Console, 58, 12, 'L');
	animate(g_Console);
	cleargrid(g_Console, 12, 6);
	cleargrid(g_Console, 58, 12);

	drawgrid(g_Console, 9, 5, 'O');
	drawgrid(g_Console, 61, 11, 'L');
	animate(g_Console);
	cleargrid(g_Console, 9, 5);
	cleargrid(g_Console, 61, 11);

	drawgrid(g_Console, 5, 4, 'O');
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
//aaaa