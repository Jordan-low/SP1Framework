// This is the main file for the game logic and function
//1
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Map.h"
#include "Andrew's Item.h"
#include "Andrew's Inventory.h"
#include "Cutscenes.h"
#include "Dialogue.h"
#include "drawSprites.h"

using namespace std;

double g_dElapsedTime;
double g_dChildrenTime;
double g_dProtestTime;
double g_dDungeonTime;
double g_dPathTime;
double g_dIAF3Time;
double g_dDeltaTime;
double g_dMedicalFightTime;
double g_dMedicalTime;
double g_dMedical2Time;
double g_dDungeonStealth3Time;
double g_dBossTime;
double g_dslashGuard;
double g_dkillGuard;
double GuardDetectTime;
double startTime;
double resetTime;
double playerDMGTime;
double enemyDMGTime;
double InvenTime;


SKeyEvent g_skKeyEvent[K_COUNT];
SMouseEvent g_mouseEvent;

// Game specific variables here
SGameChar   g_sChar;
SGameChar   g_sTutEnemy;
SGameChar   g_sPig;
SGameChar   g_sPig2;
SGameChar   g_sPig3;
SGameChar   g_sGuard;
SGameChar   g_sGuard2;
SGameChar   g_sGuard3;
SGameChar   g_sGuard4; 
SGameChar   g_sGuard5;
SGameChar   g_sGuard6;
SGameChar   g_sGuard7;
SGameChar   g_sMutantWasp;
SGameChar   g_sMutantWasp2;
SGameChar   g_sMutantWasp3;
SGameChar   g_sRaymond;
SGameChar   g_sNPC1;
SGameChar   g_sNPC2;
SGameChar   g_sNPC3;
SGameChar   g_sNPC4;
SGameChar   g_sNPC5;
SGameChar   g_sNPC6;
SGameChar   g_sNPC7;
SGameChar   g_sInven;
EGAMESTATES g_eGameState; // game states

// Console object
Console g_Console(80, 30, "Robert's Rescue");
// Map object
Map rMap;
Map eMap;
drawSprites Sprites;
Cutscenes Cutscene;
Dialogue Dialogues;
Enemy Guardz;
//Inventory Stuff
Inventory PlayerInv;
Item* item1 = new Item;
Item* item2 = new Item;
Item* item3 = new Item;
Item* item4 = new Item;
Item* item5 = new Item;
Item* item6 = new Item;
Item* item7 = new Item;
Item* item8 = new Item;

//--------------------------------------------------------------
// Purpose  : Initialisation function
//            Initialize variables, allocate memory, load data from file, etc. 
//            This is called once before entering into your main loop
// Input    : void
// Output   : void
//--------------------------------------------------------------
void init(void)
{
    g_sGuard4.startTimer = true;
    g_sChar.faceLeft = true;
    g_sChar.faceRight = false;
    g_sGuard.enemyDie = false;
    g_sGuard2.enemyDie = false;
    g_sGuard3.enemyDie = false;

    g_sGuard.fightGuard = false;
    g_sGuard2.fightGuard = false;
    g_sGuard3.fightGuard = false;

    g_sChar.count = 0;
    g_sChar.unlockDoorDS1 = false;
    g_sChar.showEnemyDMG = false;
    g_sChar.showPlayerDMG = false;
    g_sChar.startTimer = true;
    g_sChar.resetTimer = false;

    /*
    TutEnemy.setEnemy(1, 1, 10, 2, 'E');
    Pig.setEnemy(1, 1, 15, 3, 'E');
    MutantWasp.setEnemy(1, 1, 25, 5, 'E');
    Guard.setEnemy(1, 1, 40, 15, 'E');
    Raymond.setEnemy(1, 1, 120, 25, 'E');
    */
    g_sChar.SetH(5);
    g_sChar.SetD(5);
    g_sGuard.SetD(15);
    g_sGuard.SetH(40);
    g_sGuard2.SetD(15);
    g_sGuard2.SetH(40);
    g_sGuard3.SetD(15);
    g_sGuard3.SetH(40);
    g_sPig.SetH(15);
    g_sPig.SetD(3);
    g_sTutEnemy.SetH(10);
    g_sTutEnemy.SetD(2);
    g_sMutantWasp.SetH(25);
    g_sMutantWasp.SetD(5);

    g_sChar.Poison = false;
    g_sRaymond.SetH(120);
    g_sRaymond.SetD(25);
    g_sChar.InvenActive = false;
    g_sChar.itemActive = false;
    g_sInven.startTimer = false;
    /*g_sTutEnemy.setEnemy(10, 2, 'E');
    g_sPig.setEnemy(15, 3, 'E');
    g_sMutantWasp.setEnemy(25, 5, 'E');
    g_sGuard.setEnemy(40, 15, 'E');
    g_sRaymond.setEnemy(120, 25, 'E');*/

    g_sNPC1.talked = false;
    g_sNPC2.talked = false;
    g_sNPC3.talked = false;
    g_sNPC4.talked = false;
    g_sNPC5.talked = false;
    g_sNPC6.talked = false;
    g_sNPC7.talked = false;

    g_sGuard.xLeft = false;
    g_sGuard.xRight = false;
    g_sGuard.xDown = false;
    g_sGuard.xUp = false;

    g_sGuard2.xLeft = false;
    g_sGuard2.xRight = false;
    g_sGuard2.xDown = false;
    g_sGuard2.xUp = false;

    g_sGuard3.xLeft = false;
    g_sGuard3.xRight = false;
    g_sGuard3.xDown = false;
    g_sGuard3.xUp = false;

    g_sChar.counter = false;
    g_sChar.fire = false;
    g_sChar.fireOut = false;
    g_sChar.Orp_Obj1 = false;
    g_sChar.Orp_Obj2 = false;
    g_sChar.takenBackpack = false;
    g_sChar.takenExtinguisher = false;
    g_sChar.Orp_Dialogue = false;
    // Set precision for floating point output
    g_dProtestTime = 0.0;

    // sets the initial state for the game
    g_eGameState = S_Game_Over;

    g_sChar.m_cLocation.X = 4;// 4  g_Console.getConsoleSize().X / 2;
    g_sChar.m_cLocation.Y = 18;// 18   g_Console.getConsoleSize().Y / 2;
    g_sChar.m_bActive = true;

    g_sGuard3.m_cLocation.X = 40;
    g_sGuard3.m_cLocation.Y = 19;

    g_sGuard2.m_cLocation.X = 22;
    g_sGuard2.m_cLocation.Y = 15;

    g_sGuard.m_cLocation.X = 44;
    g_sGuard.m_cLocation.Y = 10;

    // sets the width, height and the font name to use in the console
    g_Console.setConsoleFont(0, 16, L"Consolas");

    // remember to set your keyboard handler, so that your functions can be notified of input events
    g_Console.setKeyboardHandler(keyboardHandler);
    g_Console.setMouseHandler(mouseHandler);
}

//--------------------------------------------------------------
// Purpose  : Reset before exiting the program
//            Do your clean up of memory here
//            This is called once just before the game exits
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void shutdown(void)
{
    // Reset to white text on black background
    colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    g_Console.clearBuffer();
}

//--------------------------------------------------------------
// Purpose  : Get all the console input events
//            This function sets up the keyboard and mouse input from the console.
//            We will need to reset all the keyboard status, because no events will be sent if no keys are pressed.
//
//            Remember to set the handlers for keyboard and mouse events.
//            The function prototype of the handler is a function that takes in a const reference to the event struct
//            and returns nothing. 
//            void pfKeyboardHandler(const KEY_EVENT_RECORD&);
//            void pfMouseHandlerconst MOUSE_EVENT_RECORD&);
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void getInput(void)
{
    // resets all the keyboard events
    memset(g_skKeyEvent, 0, K_COUNT * sizeof(*g_skKeyEvent));
    // then call the console to detect input from user
    g_Console.readConsoleInput();
}

//--------------------------------------------------------------
// Purpose  : This is the handler for the keyboard input. Whenever there is a keyboard event, this function will be called.
//            Ideally, you should pass the key event to a specific function to handle the event.
//            This is because in some states, some keys would be disabled. Hence, to reduce your code complexity, 
//            it would be wise to split your keyboard input handlers separately.
//            
//            The KEY_EVENT_RECORD struct has more attributes that you can use, if you are adventurous enough.
//
//            In this case, we are not handling any keyboard event in the Splashscreen state
//            
// Input    : const KEY_EVENT_RECORD& keyboardEvent - reference to a key event struct
// Output   : void
//--------------------------------------------------------------
void keyboardHandler(const KEY_EVENT_RECORD& keyboardEvent)
{
    switch (g_eGameState)
    {
    case S_MENU_UI: gameplayKBHandler(keyboardEvent);
        break;
    case S_Game_Over: gameplayKBHandler(keyboardEvent);
        break;
    case S_SPLASHSCREEN: // don't handle anything for the splash screen
        break;
    case S_GAME: gameplayKBHandler(keyboardEvent); // handle gameplay keyboard event 
        break;
    case S_Townsquare: gameplayKBHandler(keyboardEvent);
        break;
    case S_Protest_Area: gameplayKBHandler(keyboardEvent);
        break;
    case S_Path_Area: gameplayKBHandler(keyboardEvent);
        break;
    case S_OAF: gameplayKBHandler(keyboardEvent);
        break;
    case S_IAF1: gameplayKBHandler(keyboardEvent);
        break;
    case S_IAF2: gameplayKBHandler(keyboardEvent);
        break;
    case S_IAF3: gameplayKBHandler(keyboardEvent);
        break;
    case S_IAF4: gameplayKBHandler(keyboardEvent);
        break;
    case S_Inside_Medical_Facility: gameplayKBHandler(keyboardEvent);
        break;
    case S_Dungeon_Cell: gameplayKBHandler(keyboardEvent);
        break;
    case S_Orphanage_Animation: gameplayKBHandler(keyboardEvent);
        break;
    case S_Dungeon_Stealth_1: gameplayKBHandler(keyboardEvent);
        break;
    case S_Dungeon_Stealth_2: gameplayKBHandler(keyboardEvent);
        break;
    case S_Dungeon_Stealth_3: gameplayKBHandler(keyboardEvent);
        break;
    case S_Boss_Battle_Room: gameplayKBHandler(keyboardEvent);
        break;
    case S_BattleScreen: gameplayKBHandler(keyboardEvent);
        break;
    }
}

//--------------------------------------------------------------
// Purpose  : This is the handler for the mouse input. Whenever there is a mouse event, this function will be called.
//            Ideally, you should pass the key event to a specific function to handle the event.
//            This is because in some states, some keys would be disabled. Hence, to reduce your code complexity, 
//            it would be wise to split your keyboard input handlers separately.
//            
//            For the mouse event, if the mouse is not moved, no event will be sent, hence you should not reset the mouse status.
//            However, if the mouse goes out of the window, you would not be able to know either. 
//
//            The MOUSE_EVENT_RECORD struct has more attributes that you can use, if you are adventurous enough.
//
//            In this case, we are not handling any mouse event in the Splashscreen state
//            
// Input    : const MOUSE_EVENT_RECORD& mouseEvent - reference to a mouse event struct
// Output   : void
//--------------------------------------------------------------
void mouseHandler(const MOUSE_EVENT_RECORD& mouseEvent)
{
    switch (g_eGameState)
    {
    case S_MENU_UI: gameplayMouseHandler(mouseEvent);
        break;
    case S_Game_Over: gameplayMouseHandler(mouseEvent); // handle gameplay mouse event
        break;
    case S_SPLASHSCREEN: // don't handle anything for the splash screen
        break;
    case S_GAME: gameplayMouseHandler(mouseEvent); // handle gameplay mouse event
        break;
    case S_Townsquare: gameplayMouseHandler(mouseEvent);
        break;
    case S_Protest_Area: gameplayMouseHandler(mouseEvent);
        break;
    case S_Path_Area: gameplayMouseHandler(mouseEvent);
        break;
    case S_OAF: gameplayMouseHandler(mouseEvent);
        break;
    case S_IAF1: gameplayMouseHandler(mouseEvent);
        break;
    case S_IAF2: gameplayMouseHandler(mouseEvent);
        break;
    case S_IAF3: gameplayMouseHandler(mouseEvent);
        break;
    case S_IAF4: gameplayMouseHandler(mouseEvent);
        break;
    case S_Inside_Medical_Facility: gameplayMouseHandler(mouseEvent);
        break;
    case S_Dungeon_Cell: gameplayMouseHandler(mouseEvent);
        break;
    case S_Orphanage_Animation: gameplayMouseHandler(mouseEvent);
        break;
    case S_Dungeon_Stealth_1: gameplayMouseHandler(mouseEvent);
        break;
    case S_Dungeon_Stealth_2: gameplayMouseHandler(mouseEvent);
        break;
    case S_Dungeon_Stealth_3: gameplayMouseHandler(mouseEvent);
        break;
    case S_Boss_Battle_Room: gameplayMouseHandler(mouseEvent);
        break;
    case S_BattleScreen: gameplayMouseHandler(mouseEvent);
        break;
    }
}

//--------------------------------------------------------------
// Purpose  : This is the keyboard handler in the game state. Whenever there is a keyboard event in the game state, this function will be called.
//            
//            Add more keys to the enum in game.h if you need to detect more keys
//            To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
//            For Alphanumeric keys, the values are their ascii values (uppercase).
// Input    : const KEY_EVENT_RECORD& keyboardEvent
// Output   : void
//---------------------------------------------------------------
void gameplayKBHandler(const KEY_EVENT_RECORD& keyboardEvent)
{
    // here, we map the key to our enums
    EKEYS key = K_COUNT;
    switch (keyboardEvent.wVirtualKeyCode)
    {
    case VK_UP: key = K_UP; break;
    case VK_DOWN: key = K_DOWN; break;
    case VK_LEFT: key = K_LEFT; break;
    case VK_RIGHT: key = K_RIGHT; break;
    case VK_SPACE: key = K_SPACE; break;
    case VK_RETURN: key = K_RETURN; break;
    case VK_ESCAPE: key = K_ESCAPE; break;
    }
    // a key pressed event would be one with bKeyDown == true
    // a key released event would be one with bKeyDown == false
    // if no key is pressed, no event would be fired.
    // so we are tracking if a key is either pressed, or released
    if (key != K_COUNT)
    {
        g_skKeyEvent[key].keyDown = keyboardEvent.bKeyDown;
        g_skKeyEvent[key].keyReleased = !keyboardEvent.bKeyDown;
    }
}

//--------------------------------------------------------------
// Purpose  : This is the mouse handler in the game state. Whenever there is a mouse event in the game state, this function will be called.
//            
//            If mouse clicks are detected, the corresponding bit for that mouse button will be set.
//            mouse wheel, 
//            
// Input    : const KEY_EVENT_RECORD& keyboardEvent
// Output   : void
//--------------------------------------------------------------
void gameplayMouseHandler(const MOUSE_EVENT_RECORD& mouseEvent)
{
    if (mouseEvent.dwEventFlags & MOUSE_MOVED) // update the mouse position if there are no events
    {
        g_mouseEvent.mousePosition = mouseEvent.dwMousePosition;
    }
    g_mouseEvent.buttonState = mouseEvent.dwButtonState;
    g_mouseEvent.eventFlags = mouseEvent.dwEventFlags;
}

//--------------------------------------------------------------
// Purpose  : Update function
//            This is the update function
//            double dt - This is the amount of time in seconds since the previous call was made
//
//            Game logic should be done here.
//            Such as collision checks, determining the position of your game characters, status updates, etc
//            If there are any calls to write to the console here, then you are doing it wrong.
//
//            If your game has multiple states, you should determine the current state, and call the relevant function here.
//
// Input    : dt = deltatime
// Output   : void
//--------------------------------------------------------------
void update(double dt)
{
    // get the delta time
    g_dElapsedTime += dt;
    g_dDeltaTime = dt;
    g_dChildrenTime += dt;
    g_dProtestTime += dt;
    g_dDungeonTime += dt;
    g_dPathTime += dt;
    g_dIAF3Time += dt;
    g_dMedicalFightTime += dt;
    g_dMedicalTime += dt;
    g_dMedical2Time += dt;
    g_dDungeonStealth3Time += dt;
    g_dBossTime += dt;
    g_dslashGuard += dt;
    g_dkillGuard += dt;
    GuardDetectTime += dt;
    startTime += dt;
    resetTime += dt;
    playerDMGTime += dt;
    enemyDMGTime += dt;
    InvenTime += dt;

    switch (g_eGameState)
    {
    case S_MENU_UI: Update_Menu();
        break;
    case S_Game_Over: UpdateGameOver();
        break;
    case S_SPLASHSCREEN: splashScreenWait(); // game logic for the splash screen
        break;
    case S_Orphanage_Animation: Update_Orphanage_Animation();
        break;
    case S_Orphanage_Children_Animation: Update_Orphanage_Animation2();
        break;
    case S_GAME: updateGame();
        break;
    //Areas of the game
    case S_Townsquare: updateGame();
        break;
    case S_Protest_Area: updateGame();
        break;
    case S_Path_Area: updateGame();
        break;
    case S_OAF: updateGame();
        break;
    case S_IAF1: updateGame();
        break;
    case S_IAF2: updateGame();
        break;
    case S_IAF3: updateGame();
        break;
    case S_IAF4: updateGame();
        break;
    case S_Inside_Medical_Facility: updateGame();
        break;
    case S_Dungeon_Cell: updateGame();
        break;
    case S_Dungeon_Stealth_1: updateGame();
        break;
    case S_Dungeon_Stealth_2: update_GuardDirection();
        break;
    case S_Dungeon_Stealth_3: updateGame();
        break;
    case S_Boss_Battle_Room: updateGame();
        break;


    //Animations
    case S_Path_Area_Animation: Update_Path_Area();
        break;
    case S_Dungeon_Cell_Animation: Update_Dungeon_Cell();
        break;
    case S_IAF3_Animation: Update_IAF3();
        break;
    case S_Medical_Fight_Animation: Update_Medical_Fight_Animation();
        break;
    case S_Medical_Facility_Animation: Update_Medical_Facility_Animation();
        break;
    case  S_Medical_Facility_Part2_Animation: Update_Medical_Facility_Part2_Animation();
        break;
    case S_Dungeon_Stealth3_Animation: Update_Dungeon_Stealth3_Animation();
        break;
    case S_Boss_Room_Animation: Update_Boss_Room_Animation();
        break;
    case S_BattleScreen: UpdateBattleScreen();
        break;

    //Battle Animations
    case S_SlashGuard: Update_slashGuard();
        break;
    }
}
void Update_Menu()
{
    g_sChar.counter = true;
}
void UpdateGameOver()
{
    g_sChar.counter = true;
}

//Animated Cutscenes here
void Update_Orphanage_Animation()
{
    if (g_dElapsedTime > 22)
    {
        g_eGameState = S_GAME;
    }
    processUserInput();
}
void Orphanage_Animation()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.orphanage(g_Console);
    COORD c;
    renderCharacter();
    c.X = 5;
    c.Y = 26;
    Cutscene.drawgrid(g_Console, 11, 5, '|');
    if (g_dElapsedTime > 1.3)
    {
        Cutscene.cleargrid(g_Console, 11, 5);
        Cutscene.drawgrid(g_Console, 11, 10, '|');
        if (g_dElapsedTime > 1.6)
        {
            Cutscene.cleargrid(g_Console, 11, 10);
            Cutscene.drawgrid(g_Console, 11, 4, '|');
            if (g_dElapsedTime > 1.9)
            {
                Cutscene.cleargrid(g_Console, 11, 4);
                Cutscene.drawgrid(g_Console, 11, 6, '|');
                if (g_dElapsedTime > 2.1)
                {
                    Cutscene.cleargrid(g_Console, 11, 6);
                    Cutscene.drawgrid(g_Console, 11, 7, (char)12);
                    if (g_dElapsedTime > 2.4)
                    {
                        Cutscene.cleargrid(g_Console, 11, 7);
                        Cutscene.drawgrid(g_Console, 9, 7, (char)12);
                        if (g_dElapsedTime > 2.7)
                        {
                            Cutscene.cleargrid(g_Console, 9, 7);
                            Cutscene.drawgrid(g_Console, 13, 7, (char)12);
                            if (g_dElapsedTime > 3.0)
                            {
                                Cutscene.cleargrid(g_Console, 13, 7);
                                Cutscene.drawgrid(g_Console, 11, 7, (char)12);
                                int j = 6;
                                for (int i = 9; i < 14; i++)
                                {
                                    Cutscene.drawgrid(g_Console, i, j, '-');
                                }
                                if (g_dElapsedTime > 3.3)
                                {
                                    j = 8;
                                    for (int i = 9; i < 14; i++)
                                    {
                                        Cutscene.drawgrid(g_Console, i, j, '-');
                                    }
                                    if (g_dElapsedTime > 3.6)
                                    {
                                        Cutscene.drawgrid(g_Console, 9, 7, '|');
                                        if (g_dElapsedTime > 3.9)
                                        {
                                            Cutscene.drawgrid(g_Console, 13, 7, '|');
                                            if (g_dElapsedTime > 4.2)
                                            {
                                                g_Console.writeToBuffer(c, "Caretaker: Argh!!!", 0x0F, 100);
                                                if (g_dElapsedTime > 10)
                                                {
                                                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                    g_Console.writeToBuffer(c, "Caretaker: Save the children!! Take the fire extinguisher...", 0x0F, 100);
                                                    if (g_dElapsedTime > 16)
                                                    {
                                                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                        g_Console.writeToBuffer(c, "Objective: Take the fire extinguisher and put out the fire!", 0x0F, 100);
                                                        g_sChar.Orp_Obj1 = true;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void Update_Orphanage_Animation2()
{

    if (g_dChildrenTime > 39)
    {
        g_sChar.Orp_Dialogue = true;
        g_sChar.fire = false;
        g_sChar.Orp_Obj2 = true;
        g_eGameState = S_GAME;
    }
    processUserInput();
}
void Orphanage_Children_Animation()
{
    rMap.initialise(g_Console);
    rMap.drawAnimation(g_Console, 33, 22, 'B');
    rMap.Animation(g_Console, 11, 7, (char)12);
    rMap.Animation(g_Console, 9, 7, (char)12);
    rMap.Animation(g_Console, 13, 7, (char)12);
    rMap.Animation(g_Console, 11, 7, (char)12);
    int j = 6;
    for (int i = 9; i < 14; i++)
    {
        rMap.Animation(g_Console, i, j, '-');
    }
    j = 8;
    for (int i = 9; i < 14; i++)
    {
        rMap.Animation(g_Console, i, j, '-');
    }
    rMap.Animation(g_Console, 9, 7, '|');
    rMap.Animation(g_Console, 13, 7, '|');

    rMap.drawChildren(g_Console);
    rMap.Border(g_Console);
    renderCharacter();
    COORD c; COORD d; COORD e;
    c.X = 5;
    c.Y = 26;
    d.X = 5;
    d.Y = 27;
    e.X = 5;
    e.Y = 28;
    g_Console.writeToBuffer(c, "                                                                                                               ", 0x00, 100);
    g_Console.writeToBuffer(d, "                                                                                                               ", 0x00, 100);
    g_Console.writeToBuffer(e, "                                                                                                                ", 0x00, 100);
    //g_dDeltaTime = 0;  
    if (g_dChildrenTime > 1)
    {
        g_Console.writeToBuffer(c, "Robert: !!!", 0x0F, 100);
        if (g_dChildrenTime > 5)
        {
            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
            g_Console.writeToBuffer(c, "Robert: Nooooo!!!!", 0x0F, 100);
            if (g_dChildrenTime > 9)
            {
                Cutscene.drawgrid(g_Console, 52, 16, '_');
                if (g_dChildrenTime > 9.3)
                {
                    Cutscene.drawgrid(g_Console, 53, 16, '_');
                    if (g_dChildrenTime > 9.6)
                    {
                        Cutscene.drawgrid(g_Console, 54, 16, '_');
                        if (g_dChildrenTime > 9.9)
                        {
                            Cutscene.drawgrid(g_Console, 55, 16, '_');
                            if (g_dChildrenTime > 10.2)
                            {
                                int j = 16;
                                for (int i = 56; i < 64; i++)
                                {
                                    Cutscene.drawgrid(g_Console, i, j, '_');
                                }
                                if (g_dChildrenTime > 10.5)
                                {
                                    Cutscene.drawgrid(g_Console, 51, 17, '|');
                                    Cutscene.drawgrid(g_Console, 64, 17, '|');
                                    if (g_dChildrenTime > 10.8)
                                    {
                                        Cutscene.drawgrid(g_Console, 50, 17, '_');
                                        Cutscene.drawgrid(g_Console, 65, 17, '_');
                                        if (g_dChildrenTime > 11.1)
                                        {
                                            Cutscene.drawgrid(g_Console, 49, 18, '|');
                                            Cutscene.drawgrid(g_Console, 66, 18, '|');
                                            if (g_dChildrenTime > 11.4)
                                            {
                                                Cutscene.drawgrid(g_Console, 48, 18, '_');
                                                Cutscene.drawgrid(g_Console, 67, 18, '_');
                                                if (g_dChildrenTime > 11.7)
                                                {
                                                    int i = 47;
                                                    for (int j = 19; j < 23; j++)
                                                    {
                                                        Cutscene.drawgrid(g_Console, i, j, '|');
                                                    }
                                                    i = 68;
                                                    for (j = 19; j < 23; j++)
                                                    {
                                                        Cutscene.drawgrid(g_Console, i, j, '|');
                                                    }
                                                    if (g_dChildrenTime > 12)
                                                    {
                                                        Cutscene.cleargrid(g_Console, 56, 22);
                                                        Cutscene.cleargrid(g_Console, 64, 20);
                                                        Cutscene.cleargrid(g_Console, 62, 17);
                                                        Cutscene.cleargrid(g_Console, 54, 17);
                                                        Cutscene.cleargrid(g_Console, 50, 20);
                                                        Cutscene.drawgrid(g_Console, 56, 22, (char)12);
                                                        Cutscene.drawgrid(g_Console, 64, 21, (char)12);
                                                        Cutscene.drawgrid(g_Console, 62, 18, (char)12);
                                                        Cutscene.drawgrid(g_Console, 54, 18, (char)12);
                                                        Cutscene.drawgrid(g_Console, 50, 21, (char)12);
                                                        if (g_dChildrenTime > 12.3)
                                                        {
                                                            Cutscene.cleargrid(g_Console, 56, 22);
                                                            Cutscene.cleargrid(g_Console, 64, 21);
                                                            Cutscene.cleargrid(g_Console, 62, 18);
                                                            Cutscene.cleargrid(g_Console, 54, 18);
                                                            Cutscene.cleargrid(g_Console, 50, 21);
                                                            Cutscene.drawgrid(g_Console, 56, 22, (char)12);
                                                            Cutscene.drawgrid(g_Console, 64, 22, (char)12);
                                                            Cutscene.drawgrid(g_Console, 62, 19, (char)12);
                                                            Cutscene.drawgrid(g_Console, 54, 19, (char)12);
                                                            Cutscene.drawgrid(g_Console, 50, 22, (char)12);
                                                            if (g_dChildrenTime > 12.6)
                                                            {
                                                                Cutscene.cleargrid(g_Console, 56, 22);
                                                                Cutscene.cleargrid(g_Console, 64, 22);
                                                                Cutscene.cleargrid(g_Console, 62, 19);
                                                                Cutscene.cleargrid(g_Console, 54, 19);
                                                                Cutscene.cleargrid(g_Console, 50, 22);
                                                                Cutscene.drawgrid(g_Console, 64, 22, (char)12);
                                                                Cutscene.drawgrid(g_Console, 62, 20, (char)12);
                                                                Cutscene.drawgrid(g_Console, 54, 20, (char)12);
                                                                Cutscene.drawgrid(g_Console, 50, 22, (char)12);
                                                                if (g_dChildrenTime > 12.9)
                                                                {
                                                                    Cutscene.cleargrid(g_Console, 64, 22);
                                                                    Cutscene.cleargrid(g_Console, 62, 20);
                                                                    Cutscene.cleargrid(g_Console, 54, 20);
                                                                    Cutscene.cleargrid(g_Console, 50, 22);
                                                                    Cutscene.drawgrid(g_Console, 64, 22, (char)12);
                                                                    Cutscene.drawgrid(g_Console, 62, 21, (char)12);
                                                                    Cutscene.drawgrid(g_Console, 54, 21, (char)12);
                                                                    Cutscene.drawgrid(g_Console, 50, 22, (char)12);
                                                                    if (g_dChildrenTime > 13.2)
                                                                    {
                                                                        Cutscene.cleargrid(g_Console, 64, 22);
                                                                        Cutscene.cleargrid(g_Console, 62, 21);
                                                                        Cutscene.cleargrid(g_Console, 54, 21);
                                                                        Cutscene.cleargrid(g_Console, 50, 22);
                                                                        Cutscene.drawgrid(g_Console, 62, 22, (char)12);
                                                                        Cutscene.drawgrid(g_Console, 54, 22, (char)12);
                                                                        if (g_dChildrenTime > 13.5)
                                                                        {
                                                                            Cutscene.cleargrid(g_Console, 62, 22);
                                                                            Cutscene.cleargrid(g_Console, 54, 22);
                                                                            Cutscene.drawgrid(g_Console, 62, 22, (char)12);
                                                                            Cutscene.drawgrid(g_Console, 54, 22, (char)12);
                                                                            if (g_dChildrenTime > 13.8)
                                                                            {
                                                                                Cutscene.cleargrid(g_Console, 62, 22);
                                                                                Cutscene.cleargrid(g_Console, 54, 22);
                                                                                Cutscene.drawgrid(g_Console, 62, 22, (char)12);
                                                                                Cutscene.drawgrid(g_Console, 54, 22, (char)12);
                                                                                if (g_dChildrenTime > 14.1)
                                                                                {
                                                                                    Cutscene.cleargrid(g_Console, 62, 22);
                                                                                    Cutscene.cleargrid(g_Console, 54, 22);
                                                                                    if (g_dChildrenTime > 14.4)
                                                                                    {
                                                                                        g_Console.writeToBuffer(c, "Robert: ...", 0x0F, 100);
                                                                                        if (g_dChildrenTime > 15)
                                                                                        {
                                                                                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                            g_Console.writeToBuffer(c, "Caretaker: Robert... Leave the Orphanage now!..", 0x0F, 100);
                                                                                            if (g_dChildrenTime > 21)
                                                                                            {
                                                                                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                g_Console.writeToBuffer(c, "Caretaker: It's better that at least one of us comes out alive..", 0x0F, 100);
                                                                                                if (g_dChildrenTime > 27)
                                                                                                {
                                                                                                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                    g_Console.writeToBuffer(c, "Caretaker: Take the backpack and leave... Don't look back Robert..", 0x0F, 100);
                                                                                                    if (g_dChildrenTime > 33)
                                                                                                    {
                                                                                                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                        g_Console.writeToBuffer(c, "Objective: Take the backpack before leaving the burning house!", 0x0F, 100);
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

        }
    }
}

void Update_Protest_Area()
{

    if (g_dProtestTime > 83.6)
    {
        g_eGameState = S_Protest_Area;
    }
    processUserInput();
}
void Protest_Area_Animation()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.protest_area(g_Console);
    COORD c;
    COORD d;
    c.X = 5;
    c.Y = 26;
    d.X = 5;
    d.Y = 27;
    renderCharacter();
    Cutscene.CrowdStandstill(g_Console);
    Cutscene.drawgrid(g_Console, 62, 4, '/');
    if (g_dProtestTime > 0.3)
    {
        Cutscene.drawgrid(g_Console, 62, 4, '-');
        if (g_dProtestTime > 0.6)
        {
            Cutscene.cleargrid(g_Console, 62, 4);
            Cutscene.drawgrid(g_Console, 62, 5, '\\');
            if (g_dProtestTime > 0.9)
            {
                Cutscene.drawgrid(g_Console, 62, 4, (char)12);
                if (g_dProtestTime > 1.2)
                {
                    Cutscene.cleargrid(g_Console, 62, 4);
                    Cutscene.drawgrid(g_Console, 63, 4, (char)12);
                    if (g_dProtestTime > 1.5)
                    {
                        Cutscene.cleargrid(g_Console, 63, 4);
                        Cutscene.drawgrid(g_Console, 63, 5, (char)12);
                        if (g_dProtestTime > 1.8)
                        {
                            Cutscene.cleargrid(g_Console, 63, 5);
                            Cutscene.drawgrid(g_Console, 63, 6, (char)12);
                            if (g_dProtestTime > 2.1)
                            {
                                Cutscene.cleargrid(g_Console, 63, 6);
                                Cutscene.drawgrid(g_Console, 63, 7, (char)12);
                                if (g_dProtestTime > 2.4)
                                {
                                    Cutscene.cleargrid(g_Console, 63, 7);
                                    Cutscene.drawgrid(g_Console, 62, 8, (char)12);
                                    if (g_dProtestTime > 2.7)
                                    {
                                        Cutscene.cleargrid(g_Console, 62, 8);
                                        Cutscene.drawgrid(g_Console, 60, 8, (char)12);
                                        if (g_dProtestTime > 3.0)
                                        {
                                            Cutscene.cleargrid(g_Console, 60, 8);
                                            Cutscene.drawgrid(g_Console, 57, 8, (char)12);
                                            if (g_dProtestTime > 3.3)
                                            {
                                                Cutscene.cleargrid(g_Console, 57, 8);
                                                Cutscene.drawgrid(g_Console, 54, 8, (char)12);
                                                if (g_dProtestTime > 3.6)
                                                {
                                                    Cutscene.cleargrid(g_Console, 54, 8);
                                                    Cutscene.drawgrid(g_Console, 51, 8, (char)12);
                                                    if (g_dProtestTime > 3.9)
                                                    {
                                                        Cutscene.cleargrid(g_Console, 51, 8);
                                                        Cutscene.drawgrid(g_Console, 48, 8, (char)12);
                                                        if (g_dProtestTime > 4.2)
                                                        {
                                                            Cutscene.cleargrid(g_Console, 48, 8);
                                                            Cutscene.drawgrid(g_Console, 45, 8, (char)12);
                                                            if (g_dProtestTime > 4.5)
                                                            {
                                                                Cutscene.cleargrid(g_Console, 45, 8);
                                                                Cutscene.drawgrid(g_Console, 42, 8, (char)12);
                                                                if (g_dProtestTime > 4.8)
                                                                {
                                                                    Cutscene.cleargrid(g_Console, 42, 8);
                                                                    Cutscene.drawgrid(g_Console, 39, 8, (char)12);
                                                                    if (g_dProtestTime > 5.1)
                                                                    {
                                                                        //g_Console.writeToBuffer(c, "                                                                                                     ", 0x0A, 100);
                                                                        g_Console.writeToBuffer(c, "Raymond: Hello citizens of Harmonis,", 0x0F, 100);
                                                                        if (g_dProtestTime > 11.0)
                                                                        {
                                                                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                            g_Console.writeToBuffer(c, "Raymond:  I know you guys are very worried about this situation.", 0x0F, 100);
                                                                            if (g_dProtestTime > 17.0)
                                                                            {
                                                                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                g_Console.writeToBuffer(c, "Raymond: We are trying our best to keep them contained. Please stay calm.", 0x0F, 100);
                                                                                if (g_dProtestTime > 23.0)
                                                                                {
                                                                                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                    g_Console.writeToBuffer(c, "Raymond: But in the mean time you can have tacos from Bob on the left,", 0x0F, 100);
                                                                                    if (g_dProtestTime > 29.0)
                                                                                    {
                                                                                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                        g_Console.writeToBuffer(c, "Raymond: So just please calm down while we figure out what is going on.", 0x0F, 100);
                                                                                        if (g_dProtestTime > 35.0)
                                                                                        {
                                                                                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                            g_Console.writeToBuffer(c, "Raymond: If you do not like tacos, ", 0x0F, 100);
                                                                                            g_Console.writeToBuffer(d, "         you can get burgers from Tim on the right.", 0x0F, 100);
                                                                                            if (g_dProtestTime > 41.0)
                                                                                            {
                                                                                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                                                                                                g_Console.writeToBuffer(c, "Raymond: Do not worry, we have plenty enough for everybody.", 0x0F, 100);
                                                                                                if (g_dProtestTime > 47.0)
                                                                                                {
                                                                                                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                    g_Console.writeToBuffer(c, "Raymond: And that concludes my speech.", 0x0F, 100);
                                                                                                    if (g_dProtestTime > 53.0)
                                                                                                    {
                                                                                                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                        g_Console.writeToBuffer(c, "Raymond: Ketchup and other condiments can be found in your fridges,", 0x0F, 100);
                                                                                                        if (g_dProtestTime > 59.0)
                                                                                                        {
                                                                                                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                            g_Console.writeToBuffer(c, "Raymond: free from yours truly,", 0x0F, 100);
                                                                                                            if (g_dProtestTime > 62.0)
                                                                                                            {
                                                                                                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                                g_Console.writeToBuffer(c, "Raymond: who asked secret FBI agents", 0x0F, 100);
                                                                                                                g_Console.writeToBuffer(d, "         to break in to specially place these packets.", 0x0F, 100);
                                                                                                                if (g_dProtestTime > 68.0)
                                                                                                                {
                                                                                                                    g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                                                                                                                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                                    g_Console.writeToBuffer(c, "Raymond: Truly wonderful I know I know, so long citizens of Harmonis.", 0x0F, 100);
                                                                                                                    if (g_dProtestTime > 74.0)
                                                                                                                    {
                                                                                                                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                                        Cutscene.drawgrid(g_Console, 39, 8, '_');
                                                                                                                        Cutscene.drawgrid(g_Console, 42, 8, (char)12);
                                                                                                                        if (g_dProtestTime > 74.3)
                                                                                                                        {
                                                                                                                            Cutscene.cleargrid(g_Console, 42, 8);
                                                                                                                            Cutscene.drawgrid(g_Console, 45, 8, (char)12);
                                                                                                                            if (g_dProtestTime > 74.6)
                                                                                                                            {
                                                                                                                                Cutscene.cleargrid(g_Console, 45, 8);
                                                                                                                                Cutscene.drawgrid(g_Console, 48, 8, (char)12);
                                                                                                                                if (g_dProtestTime > 74.9)
                                                                                                                                {
                                                                                                                                    Cutscene.cleargrid(g_Console, 48, 8);
                                                                                                                                    Cutscene.drawgrid(g_Console, 51, 8, (char)12);
                                                                                                                                    if (g_dProtestTime > 75.2)
                                                                                                                                    {
                                                                                                                                        Cutscene.cleargrid(g_Console, 51, 8);
                                                                                                                                        Cutscene.drawgrid(g_Console, 54, 8, (char)12);
                                                                                                                                        if (g_dProtestTime > 75.5)
                                                                                                                                        {
                                                                                                                                            Cutscene.cleargrid(g_Console, 54, 8);
                                                                                                                                            Cutscene.drawgrid(g_Console, 57, 8, (char)12);
                                                                                                                                            if (g_dProtestTime > 75.8)
                                                                                                                                            {
                                                                                                                                                Cutscene.cleargrid(g_Console, 57, 8);
                                                                                                                                                Cutscene.drawgrid(g_Console, 60, 8, (char)12);
                                                                                                                                                if (g_dProtestTime > 76.1)
                                                                                                                                                {
                                                                                                                                                    Cutscene.cleargrid(g_Console, 60, 8);
                                                                                                                                                    Cutscene.drawgrid(g_Console, 62, 8, (char)12);
                                                                                                                                                    if (g_dProtestTime > 76.4)
                                                                                                                                                    {
                                                                                                                                                        Cutscene.cleargrid(g_Console, 62, 8);
                                                                                                                                                        Cutscene.drawgrid(g_Console, 63, 7, (char)12);
                                                                                                                                                        if (g_dProtestTime > 76.7)
                                                                                                                                                        {
                                                                                                                                                            Cutscene.cleargrid(g_Console, 63, 7);
                                                                                                                                                            Cutscene.drawgrid(g_Console, 63, 6, (char)12);
                                                                                                                                                            if (g_dProtestTime > 77.0)
                                                                                                                                                            {
                                                                                                                                                                Cutscene.cleargrid(g_Console, 63, 6);
                                                                                                                                                                Cutscene.drawgrid(g_Console, 63, 5, (char)12);
                                                                                                                                                                if (g_dProtestTime > 77.3)
                                                                                                                                                                {
                                                                                                                                                                    Cutscene.cleargrid(g_Console, 63, 5);
                                                                                                                                                                    Cutscene.drawgrid(g_Console, 63, 4, (char)12);
                                                                                                                                                                    if (g_dProtestTime > 77.6)
                                                                                                                                                                    {
                                                                                                                                                                        Cutscene.cleargrid(g_Console, 63, 4);
                                                                                                                                                                        Cutscene.drawgrid(g_Console, 62, 4, (char)12);
                                                                                                                                                                        if (g_dProtestTime > 77.9)
                                                                                                                                                                        {
                                                                                                                                                                            Cutscene.cleargrid(g_Console, 63, 4);
                                                                                                                                                                            Cutscene.drawgrid(g_Console, 62, 4, (char)12);
                                                                                                                                                                            if (g_dProtestTime > 78.2)
                                                                                                                                                                            {
                                                                                                                                                                                Cutscene.cleargrid(g_Console, 62, 4);
                                                                                                                                                                                if (g_dProtestTime > 78.5)
                                                                                                                                                                                {
                                                                                                                                                                                    Cutscene.cleargrid(g_Console, 62, 5);
                                                                                                                                                                                    Cutscene.drawgrid(g_Console, 62, 4, '-');
                                                                                                                                                                                    if (g_dProtestTime > 78.8)
                                                                                                                                                                                    {
                                                                                                                                                                                        Cutscene.drawgrid(g_Console, 62, 4, '/');
                                                                                                                                                                                        if (g_dProtestTime > 79.1)
                                                                                                                                                                                        {
                                                                                                                                                                                            Cutscene.drawgrid(g_Console, 62, 4, '/');
                                                                                                                                                                                            if (g_dProtestTime > 79.4)
                                                                                                                                                                                            {
                                                                                                                                                                                                Cutscene.cleargrid(g_Console, 62, 4);
                                                                                                                                                                                                if (g_dProtestTime > 79.7)
                                                                                                                                                                                                {
                                                                                                                                                                                                    Cutscene.CrowdStandstillclear(g_Console);
                                                                                                                                                                                                    Cutscene.CrowdMoveLeft(g_Console);
                                                                                                                                                                                                    if (g_dProtestTime > 80.0)
                                                                                                                                                                                                    {
                                                                                                                                                                                                        Cutscene.CrowdMoveLeftclear(g_Console);
                                                                                                                                                                                                        Cutscene.CrowdStandstill(g_Console);
                                                                                                                                                                                                        if (g_dProtestTime > 80.3)
                                                                                                                                                                                                        {
                                                                                                                                                                                                            Cutscene.CrowdStandstillclear(g_Console);
                                                                                                                                                                                                            Cutscene.CrowdMoveRight(g_Console);
                                                                                                                                                                                                            if (g_dProtestTime > 80.6)
                                                                                                                                                                                                            {
                                                                                                                                                                                                                Cutscene.CrowdMoveRightclear(g_Console);
                                                                                                                                                                                                                Cutscene.CrowdStandstill(g_Console);
                                                                                                                                                                                                                if (g_dProtestTime > 80.9)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                    Cutscene.CrowdStandstillclear(g_Console);
                                                                                                                                                                                                                    Cutscene.CrowdMoveLeft(g_Console);
                                                                                                                                                                                                                    if (g_dProtestTime > 81.2)
                                                                                                                                                                                                                    {
                                                                                                                                                                                                                        Cutscene.CrowdMoveLeftclear(g_Console);
                                                                                                                                                                                                                        Cutscene.CrowdStandstill(g_Console);
                                                                                                                                                                                                                        if (g_dProtestTime > 81.5)
                                                                                                                                                                                                                        {
                                                                                                                                                                                                                            Cutscene.CrowdStandstillclear(g_Console);
                                                                                                                                                                                                                            Cutscene.CrowdMoveRight(g_Console);
                                                                                                                                                                                                                            if (g_dProtestTime > 81.8)
                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                Cutscene.CrowdMoveRightclear(g_Console);
                                                                                                                                                                                                                                Cutscene.CrowdStandstill(g_Console);
                                                                                                                                                                                                                                if (g_dProtestTime > 82.1)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                    Cutscene.CrowdStandstillclear(g_Console);
                                                                                                                                                                                                                                    Cutscene.CrowdMoveLeft(g_Console);
                                                                                                                                                                                                                                    if (g_dProtestTime > 82.4)
                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                        Cutscene.CrowdMoveLeftclear(g_Console);
                                                                                                                                                                                                                                        Cutscene.CrowdStandstill(g_Console);
                                                                                                                                                                                                                                        if (g_dProtestTime > 82.7)
                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                            Cutscene.CrowdStandstillclear(g_Console);
                                                                                                                                                                                                                                            Cutscene.CrowdMoveRight(g_Console);
                                                                                                                                                                                                                                            if (g_dProtestTime > 83.0)
                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                Cutscene.CrowdMoveRightclear(g_Console);
                                                                                                                                                                                                                                                Cutscene.CrowdStandstill(g_Console);
                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                        }
                                                                                                                                                                                                                    }
                                                                                                                                                                                                                }
                                                                                                                                                                                                            }
                                                                                                                                                                                                        }
                                                                                                                                                                                                    }
                                                                                                                                                                                                }
                                                                                                                                                                                            }
                                                                                                                                                                                        }
                                                                                                                                                                                    }
                                                                                                                                                                                }
                                                                                                                                                                            }
                                                                                                                                                                        }
                                                                                                                                                                    }
                                                                                                                                                                }
                                                                                                                                                            }
                                                                                                                                                        }
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                }
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}

//Have not put timedt into its rendered area yet, have not changed to robert's sprite O-|--<, have not added in skeletons
void Update_Dungeon_Cell()
{
    if (g_dDungeonTime > 38.7)
    {
        g_eGameState = S_GAME;
    }
    processUserInput();
}
void Dungeon_Cell_Animation()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.dungeon_cell(g_Console);
    COORD c;
    COORD d;
    renderCharacter();
    c.X = 5;
    c.Y = 26;
    d.X = 5;
    d.Y = 27;
    //drawing Robert
    Cutscene.drawgrid(g_Console, 40, 13, (char)12);
    if (g_dDungeonTime > 0.3)
    {
        //drawing Ell
        Cutscene.drawgrid(g_Console, 4, 3, (char)12);
        if (g_dDungeonTime > 0.6)
        {
            g_Console.writeToBuffer(c, "Robert: ...Where am I?", 0x0F, 100);
            if (g_dDungeonTime > 3.6)
            {
                g_Console.writeToBuffer(c, "                                                                                                     ", 0x0A, 100);
                g_Console.writeToBuffer(c, "Robert: Wasn't I at the medical facility?", 0x0F, 100);
                if (g_dDungeonTime > 7.6)
                {
                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x0A, 100);
                    Cutscene.drawgrid(g_Console, 41, 12, '!');
                    if (g_dDungeonTime > 8.0)
                    {
                        g_Console.writeToBuffer(c, "Robert: ! Is that Ell?", 0x0F, 100);
                        if (g_dDungeonTime > 8.3)
                        {
                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x0A, 100);
                            Cutscene.cleargrid(g_Console, 41, 12);
                            Cutscene.cleargrid(g_Console, 4, 1);
                            Cutscene.drawgrid(g_Console, 4, 3, (char)12);
                            if (g_dDungeonTime > 8.6)
                            {
                                Cutscene.cleargrid(g_Console, 4, 3);
                                Cutscene.drawgrid(g_Console, 4, 5, (char)12);
                                if (g_dDungeonTime > 8.9)
                                {
                                    Cutscene.cleargrid(g_Console, 4, 5);
                                    Cutscene.drawgrid(g_Console, 6, 5, (char)12);
                                    if (g_dDungeonTime > 9.2)
                                    {
                                        Cutscene.cleargrid(g_Console, 6, 5);
                                        Cutscene.drawgrid(g_Console, 9, 5, (char)12);
                                        if (g_dDungeonTime > 9.5)
                                        {
                                            Cutscene.cleargrid(g_Console, 9, 5);
                                            Cutscene.drawgrid(g_Console, 12, 5, (char)12);
                                            if (g_dDungeonTime > 9.8)
                                            {
                                                Cutscene.cleargrid(g_Console, 12, 5);
                                                Cutscene.drawgrid(g_Console, 15, 5, (char)12);
                                                if (g_dDungeonTime > 10.1)
                                                {
                                                    Cutscene.cleargrid(g_Console, 15, 5);
                                                    Cutscene.cleargrid(g_Console, 40, 13);
                                                    Cutscene.drawgrid(g_Console, 18, 5, (char)12);
                                                    Cutscene.drawgrid(g_Console, 38, 13, (char)12);
                                                    if (g_dDungeonTime > 10.4)
                                                    {
                                                        Cutscene.cleargrid(g_Console, 18, 5);
                                                        Cutscene.cleargrid(g_Console, 38, 13);
                                                        Cutscene.drawgrid(g_Console, 21, 5, (char)12);
                                                        Cutscene.drawgrid(g_Console, 36, 13, (char)12);
                                                        if (g_dDungeonTime > 10.7)
                                                        {
                                                            Cutscene.cleargrid(g_Console, 21, 5);
                                                            Cutscene.cleargrid(g_Console, 36, 13);
                                                            Cutscene.drawgrid(g_Console, 24, 5, (char)12);
                                                            Cutscene.drawgrid(g_Console, 34, 13, (char)12);
                                                            if (g_dDungeonTime > 11.0)
                                                            {
                                                                Cutscene.cleargrid(g_Console, 24, 5);
                                                                Cutscene.cleargrid(g_Console, 34, 13);
                                                                Cutscene.drawgrid(g_Console, 27, 5, (char)12);
                                                                Cutscene.drawgrid(g_Console, 32, 13, (char)12);
                                                                if (g_dDungeonTime > 11.3)
                                                                {
                                                                    Cutscene.cleargrid(g_Console, 27, 5);
                                                                    Cutscene.cleargrid(g_Console, 32, 13);
                                                                    Cutscene.drawgrid(g_Console, 30, 5, (char)12);
                                                                    Cutscene.drawgrid(g_Console, 30, 13, (char)12);
                                                                    if (g_dDungeonTime > 11.6)
                                                                    {
                                                                        Cutscene.cleargrid(g_Console, 30, 5);
                                                                        Cutscene.cleargrid(g_Console, 30, 13);
                                                                        Cutscene.drawgrid(g_Console, 30, 7, (char)12);
                                                                        Cutscene.drawgrid(g_Console, 30, 11, (char)12);
                                                                        if (g_dDungeonTime > 11.9)
                                                                        {
                                                                            Cutscene.cleargrid(g_Console, 30, 11);
                                                                            Cutscene.drawgrid(g_Console, 30, 9, (char)12);
                                                                            if (g_dDungeonTime > 12.2)
                                                                            {
                                                                                g_Console.writeToBuffer(c, "Ell: You're finally awake!!", 0x0F, 100);
                                                                                if (g_dDungeonTime > 15.2)
                                                                                {
                                                                                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x0A, 100);
                                                                                    g_Console.writeToBuffer(c, "Ell: Take this piece of paper.", 0x0F, 100);
                                                                                    g_Console.writeToBuffer(d, "     Read it and everything will become clear.", 0x0F, 100);
                                                                                    if (g_dDungeonTime > 21.2)
                                                                                    {
                                                                                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x0A, 100);
                                                                                        g_Console.writeToBuffer(d, "                                                                                                     ", 0x0A, 100);
                                                                                        g_Console.writeToBuffer(c, "Ell: I need to leave now or they'll get suspicious.", 0x0F, 100);
                                                                                        if (g_dDungeonTime > 24.2)
                                                                                        {
                                                                                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x0A, 100);
                                                                                            g_Console.writeToBuffer(c, "Ell: I'll meet you after you pass the maze.", 0x0F, 100);
                                                                                            g_Console.writeToBuffer(d, "     Make sure to sneak past the guards.", 0x0F, 100);
                                                                                            if (g_dDungeonTime > 27.2)
                                                                                            {
                                                                                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x0A, 100);
                                                                                                g_Console.writeToBuffer(d, "                                                                                                     ", 0x0A, 100);
                                                                                                g_Console.writeToBuffer(c, "Ell: I'll meet you after you pass the maze.", 0x0F, 100);
                                                                                                if (g_dDungeonTime > 30.2)
                                                                                                {
                                                                                                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                    g_Console.writeToBuffer(c, "Ell: Best of luck Robert!", 0x0F, 100);
                                                                                                    if (g_dDungeonTime > 33.2)
                                                                                                    {
                                                                                                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                        Cutscene.cleargrid(g_Console, 30, 7);
                                                                                                        Cutscene.drawgrid(g_Console, 30, 5, (char)12);

                                                                                                        if (g_dDungeonTime > 33.5)
                                                                                                        {
                                                                                                            Cutscene.cleargrid(g_Console, 30, 5);
                                                                                                            Cutscene.drawgrid(g_Console, 27, 5, (char)12);
                                                                                                            if (g_dDungeonTime > 33.8)
                                                                                                            {
                                                                                                                Cutscene.cleargrid(g_Console, 27, 5);
                                                                                                                Cutscene.drawgrid(g_Console, 24, 5, (char)12);
                                                                                                                if (g_dDungeonTime > 34.1)
                                                                                                                {
                                                                                                                    Cutscene.cleargrid(g_Console, 24, 5);
                                                                                                                    Cutscene.drawgrid(g_Console, 21, 5, (char)12);
                                                                                                                    if (g_dDungeonTime > 34.4)
                                                                                                                    {
                                                                                                                        Cutscene.cleargrid(g_Console, 21, 5);
                                                                                                                        Cutscene.drawgrid(g_Console, 18, 5, (char)12);
                                                                                                                        if (g_dDungeonTime > 34.7)
                                                                                                                        {
                                                                                                                            Cutscene.cleargrid(g_Console, 18, 5);
                                                                                                                            Cutscene.drawgrid(g_Console, 15, 5, (char)12);
                                                                                                                            if (g_dDungeonTime > 35.0)
                                                                                                                            {
                                                                                                                                Cutscene.cleargrid(g_Console, 15, 5);
                                                                                                                                Cutscene.drawgrid(g_Console, 12, 5, (char)12);
                                                                                                                                if (g_dDungeonTime > 35.3)
                                                                                                                                {
                                                                                                                                    Cutscene.cleargrid(g_Console, 12, 5);
                                                                                                                                    Cutscene.drawgrid(g_Console, 9, 5, (char)12);
                                                                                                                                    if (g_dDungeonTime > 35.6)
                                                                                                                                    {
                                                                                                                                        Cutscene.cleargrid(g_Console, 9, 5);
                                                                                                                                        Cutscene.drawgrid(g_Console, 6, 5, (char)12);
                                                                                                                                        if (g_dDungeonTime > 35.9)
                                                                                                                                        {
                                                                                                                                            Cutscene.cleargrid(g_Console, 6, 5);
                                                                                                                                            Cutscene.drawgrid(g_Console, 4, 5, (char)12);
                                                                                                                                            if (g_dDungeonTime > 36.2)
                                                                                                                                            {
                                                                                                                                                Cutscene.cleargrid(g_Console, 4, 5);
                                                                                                                                                Cutscene.drawgrid(g_Console, 4, 3, (char)12);
                                                                                                                                                if (g_dDungeonTime > 36.5)
                                                                                                                                                {
                                                                                                                                                    Cutscene.cleargrid(g_Console, 4, 3);
                                                                                                                                                    g_Console.writeToBuffer(c, "Objective: Escape the cell.", 0x0F, 100);
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                }
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Update_Path_Area()
{
    if (g_dPathTime > 4.5)
    {
        g_eGameState = S_Dungeon_Stealth_1;
    }
    processUserInput();
}
void Path_Area_Animation()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.patharea(g_Console);
    COORD c;
    renderCharacter();
    c.X = 5;
    c.Y = 26;
    Cutscene.drawgrid(g_Console, 41, 7, 'E');
    if (g_dPathTime > 0.3)
    {
        Cutscene.cleargrid(g_Console, 41, 7);
        Cutscene.drawgrid(g_Console, 40, 7, 'E');
        if (g_dPathTime > 0.6)
        {
            Cutscene.cleargrid(g_Console, 40, 7);
            Cutscene.drawgrid(g_Console, 41, 7, 'E');
            if (g_dPathTime > 0.9)
            {
                Cutscene.cleargrid(g_Console, 41, 7);
                Cutscene.drawgrid(g_Console, 42, 7, 'E');
                if (g_dPathTime > 1.2)
                {
                    Cutscene.cleargrid(g_Console, 42, 7);
                    Cutscene.drawgrid(g_Console, 41, 7, 'E');
                    if (g_dPathTime > 1.5)
                    {
                        Cutscene.drawgrid(g_Console, 42, 6, '!');
                        if (g_dPathTime > 1.8)
                        {
                            Cutscene.cleargrid(g_Console, 42, 6);
                            if (g_dPathTime > 2.1)
                            {
                                Cutscene.cleargrid(g_Console, 41, 7);
                                Cutscene.drawgrid(g_Console, 41, 9, 'E');
                                if (g_dPathTime > 2.4)
                                {
                                    Cutscene.cleargrid(g_Console, 41, 9);
                                    Cutscene.drawgrid(g_Console, 41, 11, 'E');
                                    if (g_dPathTime > 2.7)
                                    {
                                        Cutscene.cleargrid(g_Console, 41, 11);
                                        Cutscene.drawgrid(g_Console, 41, 13, 'E');
                                        if (g_dPathTime > 3.0)
                                        {
                                            Cutscene.cleargrid(g_Console, 41, 13);
                                            Cutscene.drawgrid(g_Console, 41, 15, 'E');
                                            if (g_dPathTime > 3.3)
                                            {
                                                Cutscene.cleargrid(g_Console, 41, 15);
                                                Cutscene.drawgrid(g_Console, 41, 17, 'E');
                                                if (g_dPathTime > 3.6)
                                                {
                                                    Cutscene.cleargrid(g_Console, 41, 17);
                                                    Cutscene.drawgrid(g_Console, 41, 19, 'E');
                                                    if (g_dPathTime > 3.9)
                                                    {
                                                        Cutscene.cleargrid(g_Console, 41, 19);
                                                        Cutscene.drawgrid(g_Console, 41, 20, 'E');
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

//IAF stands for inside abandoned facility, HAVE NOT PUT TIMEDT INTO ITS RENDERED AREA YET
void Update_IAF3()
{
    if (g_dIAF3Time > 47)
    {
        g_eGameState = S_GAME;
    }
    processUserInput();
}
void IAF3_Animation()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.insideAbandonedFacility3(g_Console);
    COORD c;
    COORD d;
    renderCharacter();
    c.X = 5;
    c.Y = 26;
    d.X = 5;
    d.Y = 27;
    Cutscene.drawgrid(g_Console, 40, 6, 'E');
    if (g_dIAF3Time > 0.3)
    {
        //g_Console.writeToBuffer(c, "                                                                                                     ", 0x0A, 100);
        g_Console.writeToBuffer(c, "???: I owe my life to you stranger.", 0x0F, 100);
        if (g_dIAF3Time > 3.6)
        {
            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
            g_Console.writeToBuffer(c, "???: Tell me what's your name!", 0x0F, 100);
            if (g_dIAF3Time > 6.6)
            {
                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                g_Console.writeToBuffer(c, "???: Ah so your name's Robert eh? Not bad for a name.", 0x0F, 100);
                if (g_dIAF3Time > 11.6)
                {
                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                    g_Console.writeToBuffer(c, "???: My name is Ell,", 0x0F, 100);
                    g_Console.writeToBuffer(d, "     the President threw me here to escape from those mutants..", 0x0F, 100);
                    if (g_dIAF3Time > 18.6)
                    {
                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                        g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                        g_Console.writeToBuffer(c, "Ell: What's that? You're heading to confront him?", 0x0F, 100);
                        if (g_dIAF3Time > 22.6)
                        {
                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                            g_Console.writeToBuffer(c, "Ell: ...", 0x0F, 100);
                            if (g_dIAF3Time > 23.6)
                            {
                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                g_Console.writeToBuffer(c, "Ell: ..I see...", 0x0F, 100);
                                if (g_dIAF3Time > 25.6)
                                {
                                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                    g_Console.writeToBuffer(c, "Ell: Then let me join you on your journey!", 0x0F, 100);
                                    if (g_dIAF3Time > 31.6)
                                    {
                                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                        g_Console.writeToBuffer(c, "Ell: I will be of use to you,", 0x0F, 100);
                                        g_Console.writeToBuffer(d, "     since I have been trained in the police department.", 0x0F, 100);
                                        if (g_dIAF3Time > 36.6)
                                        {
                                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                            g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                                            g_Console.writeToBuffer(c, "Ell joined your party!", 0x0F, 100);
                                            if (g_dIAF3Time > 39.6)
                                            {
                                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                g_Console.writeToBuffer(c, "Ell: Then let's get going, we've no time to waste!", 0x0F, 100);
                                                if (g_dIAF3Time > 44.6)
                                                {
                                                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                    g_Console.writeToBuffer(c, "Medical Facilty route is now available.", 0x0F, 100);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Update_Medical_Fight_Animation()
{
    if (g_dMedicalFightTime > 31.8)
    {
        g_eGameState = S_GAME;
    }
    processUserInput();
}
void Medical_Fight_Animation()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.insideMedicalFacility(g_Console);
    COORD c;
    renderCharacter();
    c.X = 5;
    c.Y = 26;
    Cutscene.drawgrid(g_Console, 34, 12, 'H'); //Robert (Hero)
    Cutscene.drawgrid(g_Console, 34, 13, (char)12); //Ell

    Cutscene.drawgrid(g_Console, 36, 12, (char)12); //Patient 1
    Cutscene.drawgrid(g_Console, 36, 9, (char)12); //Patient 2
    Cutscene.drawgrid(g_Console, 36, 15, (char)12); //Patient 3
    Cutscene.drawgrid(g_Console, 46, 15, (char)12); //Patient 4
    Cutscene.drawgrid(g_Console, 46, 9, (char)12); //Patient 5
    Cutscene.drawgrid(g_Console, 56, 15, (char)12); //Patient 6
    Cutscene.drawgrid(g_Console, 56, 9, (char)12); //Patient 7
    Cutscene.drawgrid(g_Console, 23, 13, (char)12); //nurse

    if (g_dMedicalFightTime > 0.6)
    {
        g_Console.writeToBuffer(c, "Patient 1: Thank you so much for the medicine!", 0x0F, 100);
        if (g_dMedicalFightTime > 3.6)
        {
            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
            //patient 2 walks to hero
            Cutscene.cleargrid(g_Console, 36, 9);
            Cutscene.drawgrid(g_Console, 36, 10, (char)12); //Patient 2
            if (g_dMedicalFightTime > 3.9)
            {
                Cutscene.cleargrid(g_Console, 36, 10);
                Cutscene.drawgrid(g_Console, 35, 11, (char)12);
                if (g_dMedicalFightTime > 4.2)
                {
                    g_Console.writeToBuffer(c, "Patient 2: You have so much medicine and you kept it from us?", 0x0F, 100);
                    c.Y = 27;
                    g_Console.writeToBuffer(c, "           How shameless of you!", 0x0F, 100);
                    if (g_dMedicalFightTime > 7.2)
                    {
                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                        c.Y = 26;
                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                        //patient 3 walks to hero ( ally side )
                        Cutscene.cleargrid(g_Console, 36, 15);
                        Cutscene.drawgrid(g_Console, 35, 14, (char)12);
                        if (g_dMedicalFightTime > 7.5)
                        {
                            g_Console.writeToBuffer(c, "Patient 3: Give it to me! Can't you see that you're healthier than me?", 0x0F, 100);
                            c.Y = 27;
                            g_Console.writeToBuffer(c, "           I obviously need it more than you!", 0x0F, 100);
                            if (g_dMedicalFightTime > 10.5)
                            {
                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                c.Y = 26;
                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                //patient 4 walks (in front of ally)
                                Cutscene.cleargrid(g_Console, 46, 15);
                                Cutscene.drawgrid(g_Console, 41, 14, (char)12);
                                if (g_dMedicalFightTime > 10.8)
                                {
                                    Cutscene.cleargrid(g_Console, 41, 14);
                                    Cutscene.drawgrid(g_Console, 36, 13, (char)12);
                                    if (g_dMedicalFightTime > 11.1)
                                    {
                                        g_Console.writeToBuffer(c, "Patient 4: Please! I beg you, please give my daughter", 0x0F, 100);
                                        c.Y = 27;
                                        g_Console.writeToBuffer(c, "           some medicine or she'll die!", 0x0F, 100);
                                        if (g_dMedicalFightTime > 14.1)
                                        {
                                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                            c.Y = 26;
                                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                            // Patient 5 walks to Patient 1
                                            Cutscene.cleargrid(g_Console, 46, 9);
                                            Cutscene.drawgrid(g_Console, 41, 10, (char)12);
                                            if (g_dMedicalFightTime > 14.4)
                                            {
                                                Cutscene.cleargrid(g_Console, 41, 10);
                                                Cutscene.drawgrid(g_Console, 37, 11, (char)12);
                                                if (g_dMedicalFightTime > 14.7)
                                                {
                                                    g_Console.writeToBuffer(c, "Patient 5: Give that to me! I deserve that more than you!", 0x0F, 100);
                                                    if (g_dMedicalFightTime > 17.7)
                                                    {
                                                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                        g_Console.writeToBuffer(c, "Patient 1: Hands off! They're mine!", 0x0F, 100);
                                                        if (g_dMedicalFightTime > 20.7)
                                                        {
                                                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                            //patient 6 & 7 walking 
                                                            Cutscene.cleargrid(g_Console, 56, 15);
                                                            Cutscene.cleargrid(g_Console, 56, 9);
                                                            Cutscene.drawgrid(g_Console, 51, 14, (char)12);
                                                            Cutscene.drawgrid(g_Console, 51, 10, (char)12);
                                                            if (g_dMedicalFightTime > 21.0)
                                                            {
                                                                Cutscene.cleargrid(g_Console, 51, 14);
                                                                Cutscene.cleargrid(g_Console, 51, 10);
                                                                Cutscene.drawgrid(g_Console, 46, 14, (char)12);
                                                                Cutscene.drawgrid(g_Console, 46, 11, (char)12);
                                                                if (g_dMedicalFightTime > 21.3)
                                                                {
                                                                    Cutscene.cleargrid(g_Console, 46, 14);
                                                                    Cutscene.cleargrid(g_Console, 46, 11);
                                                                    Cutscene.drawgrid(g_Console, 41, 14, (char)12);
                                                                    Cutscene.drawgrid(g_Console, 41, 12, (char)12);
                                                                    if (g_dMedicalFightTime > 21.6)
                                                                    {
                                                                        Cutscene.cleargrid(g_Console, 41, 14);
                                                                        Cutscene.cleargrid(g_Console, 41, 12);
                                                                        Cutscene.drawgrid(g_Console, 37, 14, (char)12);
                                                                        Cutscene.drawgrid(g_Console, 38, 12, (char)12);
                                                                        if (g_dMedicalFightTime > 21.9)
                                                                        {
                                                                            g_Console.writeToBuffer(c, "Patient 6: Why do you have som much medicine?", 0x0F, 100);
                                                                            c.Y = 27;
                                                                            g_Console.writeToBuffer(c, "           You must have stolen it from us!", 0x0F, 100);
                                                                            if (g_dMedicalFightTime > 24.9)
                                                                            {
                                                                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                c.Y = 26;
                                                                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                g_Console.writeToBuffer(c, "Patient 7: You thief! Give them back!", 0x0F, 100);
                                                                                if (g_dMedicalFightTime > 27.9)
                                                                                {
                                                                                    //nurse walks
                                                                                    Cutscene.cleargrid(g_Console, 23, 13);
                                                                                    Cutscene.drawgrid(g_Console, 27, 14, (char)12);
                                                                                    if (g_dMedicalFightTime > 28.2)
                                                                                    {
                                                                                        Cutscene.cleargrid(g_Console, 27, 14);
                                                                                        Cutscene.drawgrid(g_Console, 30, 15, (char)12);
                                                                                        if (g_dMedicalFightTime > 28.5)
                                                                                        {
                                                                                            Cutscene.cleargrid(g_Console, 30, 15);
                                                                                            Cutscene.drawgrid(g_Console, 33, 15, (char)12);
                                                                                            if (g_dMedicalFightTime > 28.8)
                                                                                            {
                                                                                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                g_Console.writeToBuffer(c, "Nurse: Everyone! Please calm down!", 0x0F, 100);
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

//HAVE NOT PUT DTTIME INTO RENDERED AREA, PLAYS AFTER 
void Update_Medical_Facility_Animation()
{
    if (g_dMedicalTime > 11.5)
    {
        g_eGameState = S_GAME;
    }
    processUserInput();
}
void Medical_Facility_Animation()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.insideMedicalFacility(g_Console);
    COORD c;
    renderCharacter();
    c.X = 5;
    c.Y = 26;
    Cutscene.drawgrid(g_Console, 34, 12, 'H'); //Robert (Hero)
    Cutscene.drawgrid(g_Console, 34, 13, (char)12); //Ell

    //Breaking in
    Cutscene.drawgrid(g_Console, 2, 12, 'E');
    Cutscene.drawgrid(g_Console, 2, 13, 'E');

    if (g_dMedicalTime > 0.6)
    {
        //g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
        g_Console.writeToBuffer(c, "Ell: The hornets have broken in!", 0x0F, 100);
        if (g_dMedicalTime > 3.6)
        {
            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
            Cutscene.drawgrid(g_Console, 2, 12, '@');
            Cutscene.drawgrid(g_Console, 2, 13, '@');
            Cutscene.drawgrid(g_Console, 4, 11, 'E');
            Cutscene.drawgrid(g_Console, 4, 14, 'E');
            if (g_dMedicalTime > 3.9)
            {
                Cutscene.cleargrid(g_Console, 4, 11);
                Cutscene.cleargrid(g_Console, 4, 14);
                Cutscene.drawgrid(g_Console, 6, 10, 'E');
                Cutscene.drawgrid(g_Console, 6, 15, 'E');
                if (g_dMedicalTime > 4.2)
                {
                    Cutscene.cleargrid(g_Console, 6, 10);
                    Cutscene.cleargrid(g_Console, 6, 15);
                    Cutscene.drawgrid(g_Console, 8, 9, 'E');
                    Cutscene.drawgrid(g_Console, 8, 16, 'E');
                    if (g_dMedicalTime > 4.5)
                    {
                        Cutscene.cleargrid(g_Console, 8, 9);
                        Cutscene.cleargrid(g_Console, 8, 16);
                        Cutscene.drawgrid(g_Console, 10, 8, 'E');
                        Cutscene.drawgrid(g_Console, 10, 17, 'E');
                        if (g_dMedicalTime > 4.8)
                        {
                            Cutscene.cleargrid(g_Console, 10, 8);
                            Cutscene.cleargrid(g_Console, 10, 17);
                            Cutscene.drawgrid(g_Console, 12, 7, 'E');
                            Cutscene.drawgrid(g_Console, 12, 18, 'E');
                            if (g_dMedicalTime > 5.1)
                            {
                                Cutscene.cleargrid(g_Console, 12, 7);
                                Cutscene.cleargrid(g_Console, 12, 18);
                                Cutscene.drawgrid(g_Console, 14, 6, 'E');
                                Cutscene.drawgrid(g_Console, 14, 19, 'E');
                                if (g_dMedicalTime > 5.4)
                                {
                                    Cutscene.cleargrid(g_Console, 14, 6);
                                    Cutscene.cleargrid(g_Console, 14, 19);
                                    Cutscene.drawgrid(g_Console, 16, 5, 'E');
                                    Cutscene.drawgrid(g_Console, 16, 20, 'E');
                                    if (g_dMedicalTime > 5.7)
                                    {
                                        Cutscene.cleargrid(g_Console, 16, 5);
                                        Cutscene.cleargrid(g_Console, 16, 20);
                                        Cutscene.drawgrid(g_Console, 18, 4, 'E');
                                        Cutscene.drawgrid(g_Console, 18, 21, 'E');
                                        if (g_dMedicalTime > 6.0)
                                        {
                                            Cutscene.cleargrid(g_Console, 18, 4);
                                            Cutscene.cleargrid(g_Console, 18, 21);
                                            Cutscene.drawgrid(g_Console, 20, 3, 'E');
                                            Cutscene.drawgrid(g_Console, 20, 22, 'E');
                                            if (g_dMedicalTime > 6.3)
                                            {
                                                Cutscene.cleargrid(g_Console, 20, 3);
                                                Cutscene.cleargrid(g_Console, 20, 22);
                                                Cutscene.drawgrid(g_Console, 21, 4, 'E');
                                                Cutscene.drawgrid(g_Console, 21, 21, 'E');
                                                if (g_dMedicalTime > 6.6)
                                                {
                                                    Cutscene.cleargrid(g_Console, 21, 4);
                                                    Cutscene.cleargrid(g_Console, 21, 21);
                                                    Cutscene.drawgrid(g_Console, 22, 5, 'E');
                                                    Cutscene.drawgrid(g_Console, 22, 20, 'E');
                                                    if (g_dMedicalTime > 6.9)
                                                    {
                                                        Cutscene.cleargrid(g_Console, 22, 5);
                                                        Cutscene.cleargrid(g_Console, 22, 20);
                                                        Cutscene.drawgrid(g_Console, 23, 6, 'E');
                                                        Cutscene.drawgrid(g_Console, 23, 19, 'E');
                                                        if (g_dMedicalTime > 7.2)
                                                        {
                                                            Cutscene.drawgrid(g_Console, 23, 6, '|');
                                                            Cutscene.drawgrid(g_Console, 23, 19, '|');
                                                            Cutscene.drawgrid(g_Console, 24, 7, 'E');
                                                            Cutscene.drawgrid(g_Console, 24, 18, 'E');
                                                            if (g_dMedicalTime > 7.5)
                                                            {
                                                                Cutscene.drawgrid(g_Console, 24, 7, '-');
                                                                Cutscene.drawgrid(g_Console, 24, 18, '-');
                                                                Cutscene.drawgrid(g_Console, 25, 8, 'E');
                                                                Cutscene.drawgrid(g_Console, 25, 17, 'E');
                                                                if (g_dMedicalTime > 7.8)
                                                                {
                                                                    Cutscene.cleargrid(g_Console, 25, 8);
                                                                    Cutscene.cleargrid(g_Console, 25, 17);
                                                                    Cutscene.drawgrid(g_Console, 26, 9, 'E');
                                                                    Cutscene.drawgrid(g_Console, 26, 16, 'E');
                                                                    if (g_dMedicalTime > 8.1)
                                                                    {
                                                                        Cutscene.cleargrid(g_Console, 26, 9);
                                                                        Cutscene.cleargrid(g_Console, 26, 16);
                                                                        Cutscene.drawgrid(g_Console, 27, 10, 'E');
                                                                        Cutscene.drawgrid(g_Console, 27, 15, 'E');
                                                                        if (g_dMedicalTime > 8.4)
                                                                        {
                                                                            Cutscene.cleargrid(g_Console, 27, 10);
                                                                            Cutscene.cleargrid(g_Console, 27, 15);
                                                                            Cutscene.drawgrid(g_Console, 28, 11, 'E');
                                                                            Cutscene.drawgrid(g_Console, 28, 14, 'E');
                                                                            //g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                            g_Console.writeToBuffer(c, "Ell: Oh no! We're surrounded!", 0x0F, 100);
                                                                            if (g_dMedicalTime > 11.4)
                                                                            {
                                                                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                Cutscene.cleargrid(g_Console, 28, 11);
                                                                                Cutscene.cleargrid(g_Console, 28, 14);
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Update_Medical_Facility_Part2_Animation()
{
    if (g_dMedical2Time > 15.9)
    {
        g_eGameState = S_GAME;
    }
    processUserInput();
}
void Medical_Facility_Part2_Animation()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.insideMedicalFacility(g_Console);
    COORD c;
    renderCharacter();
    c.X = 5;
    c.Y = 26;
    Cutscene.drawgrid(g_Console, 34, 12, 'H'); //Robert (Hero)
    Cutscene.drawgrid(g_Console, 34, 13, (char)12); //Ell

    Cutscene.drawgrid(g_Console, 32, 11, 'E');
    Cutscene.drawgrid(g_Console, 32, 12, 'E');
    Cutscene.drawgrid(g_Console, 32, 13, 'E');
    Cutscene.drawgrid(g_Console, 32, 14, 'E');

    Cutscene.drawgrid(g_Console, 36, 12, (char)12); //Patient 1

    if (g_dMedical2Time > 0.6)
    {
        if (g_dMedical2Time > 0.9)
        {
            g_Console.writeToBuffer(c, "Ell: More came in during our fight!", 0x0F, 100);
            if (g_dMedical2Time > 3.9)
            {
                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                g_Console.writeToBuffer(c, "Ell: There's still someone here! We have to protect him!", 0x0F, 100);
                if (g_dMedical2Time > 6.9)
                {
                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                    g_Console.writeToBuffer(c, "Patient 1: I'm sorry!", 0x0F, 100);
                    if (g_dMedical2Time > 9.9)
                    {
                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                        //oofus doofus robert gets pushed
                        Cutscene.cleargrid(g_Console, 36, 12);
                        Cutscene.drawgrid(g_Console, 35, 12, (char)12);
                        if (g_dMedical2Time > 10.2)
                        {
                            Cutscene.cleargrid(g_Console, 34, 12);
                            Cutscene.drawgrid(g_Console, 33, 12, 'H');
                            if (g_dMedical2Time > 10.5)
                            {
                                //run patient run
                                Cutscene.cleargrid(g_Console, 35, 12);
                                Cutscene.drawgrid(g_Console, 31, 10, (char)12);
                                if (g_dMedical2Time > 10.8)
                                {
                                    Cutscene.cleargrid(g_Console, 31, 10);
                                    Cutscene.drawgrid(g_Console, 27, 7, (char)12);
                                    if (g_dMedical2Time > 11.1)
                                    {
                                        Cutscene.cleargrid(g_Console, 27, 7);
                                        Cutscene.drawgrid(g_Console, 23, 4, (char)12);
                                        if (g_dMedical2Time > 11.4)
                                        {
                                            Cutscene.cleargrid(g_Console, 23, 4);
                                            Cutscene.drawgrid(g_Console, 20, 4, (char)12);
                                            if (g_dMedical2Time > 11.7)
                                            {
                                                Cutscene.cleargrid(g_Console, 20, 4);
                                                Cutscene.drawgrid(g_Console, 16, 7, (char)12);
                                                if (g_dMedical2Time > 12.0)
                                                {
                                                    Cutscene.cleargrid(g_Console, 16, 7);
                                                    Cutscene.drawgrid(g_Console, 12, 9, (char)12);
                                                    if (g_dMedical2Time > 12.3)
                                                    {
                                                        Cutscene.cleargrid(g_Console, 12, 9);
                                                        Cutscene.drawgrid(g_Console, 8, 9, (char)12);
                                                        if (g_dMedical2Time > 12.6)
                                                        {
                                                            Cutscene.cleargrid(g_Console, 8, 9);
                                                            Cutscene.drawgrid(g_Console, 3, 12, (char)12);
                                                            if (g_dMedical2Time > 12.9)
                                                            {
                                                                Cutscene.cleargrid(g_Console, 3, 11);
                                                                g_Console.writeToBuffer(c, "Ell: Robert!", 0x0F, 100);
                                                            }
                                                        }

                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

//HAVE NOT PUT DTTIME INTO RENDERED AREA
void Update_Dungeon_Stealth3_Animation()
{
    if (g_dDungeonStealth3Time > 61.7)
    {
        g_eGameState = S_Dungeon_Stealth_3;
    }
    processUserInput();
}
void Dungeon_Stealth3_Animation()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.dungeon_stealth3(g_Console);
    COORD c;
    COORD d;
    renderCharacter();
    c.X = 5;
    c.Y = 26;
    d.X = 5;
    d.Y = 27;
    Cutscene.drawgrid(g_Console, 38, 12, 'R'); //Raymond
    Cutscene.drawgrid(g_Console, 40, 12, 'L'); //Lacky
    if (g_dDungeonStealth3Time > 0.3)
    {
        g_Console.writeToBuffer(c, "Raymond: I want you to keep this secret between us,", 0x0F);
        g_Console.writeToBuffer(d, "         if anyone suspect or knows that I am behind all this,", 0x0F);
        if (g_dDungeonStealth3Time > 5.3)
        {
            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
            g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
            g_Console.writeToBuffer(c, "Raymond: I want you to eliminate them.", 0x0F);
            g_Console.writeToBuffer(d, "         Understand?", 0x0F);
            if (g_dDungeonStealth3Time > 8.6)
            {
                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                g_Console.writeToBuffer(c, "Raymond: This secret is a matter of life and death,", 0x0F);
                g_Console.writeToBuffer(d, "         it MUST not get exposed.", 0x0F);
                if (g_dDungeonStealth3Time > 13.6)
                {
                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                    g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                    g_Console.writeToBuffer(c, "Raymond: If this ever gets out,", 0x0F);
                    g_Console.writeToBuffer(d, "         my plans to rule the world will be ruined.", 0x0F);
                    if (g_dDungeonStealth3Time > 18.6)
                    {
                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                        g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                        g_Console.writeToBuffer(c, "Raymond: Anyways, I thought that I managed to get rid of that idiot of a", 0x0F);
                        g_Console.writeToBuffer(d, "         security guard during the break out in that abandoned facility.", 0x0F);
                        if (g_dDungeonStealth3Time > 27.6)
                        {
                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                            g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                            g_Console.writeToBuffer(c, "Raymond: However, it seems like a young kid had saved him,", 0x0F);
                            g_Console.writeToBuffer(d, "         and now he has turned his back on us.", 0x0F);
                            if (g_dDungeonStealth3Time > 32.6)
                            {
                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                                g_Console.writeToBuffer(c, "Raymond: I want you to find him and bring him to me.", 0x0F);
                                g_Console.writeToBuffer(d, "         I want to show everyone what I do to traitors.", 0x0F);
                                if (g_dDungeonStealth3Time > 38.6)
                                {
                                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                    g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                                    g_Console.writeToBuffer(c, "Raymond: I will get rid of ANYONE who stands in my way.", 0x0F);
                                    if (g_dDungeonStealth3Time > 42.6)
                                    {
                                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                        g_Console.writeToBuffer(c, "Raymond: I'll be waiting for your good news", 0x0F);
                                        g_Console.writeToBuffer(d, "         at the top floor of this building.", 0x0F);
                                        if (g_dDungeonStealth3Time > 47.6)
                                        {
                                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                            g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                                            g_Console.writeToBuffer(c, "Robot: Beep bop boop", 0x0F);
                                            Cutscene.cleargrid(g_Console, 38, 12);
                                            Cutscene.cleargrid(g_Console, 40, 12);
                                            Cutscene.drawgrid(g_Console, 33, 11, 'R');
                                            Cutscene.drawgrid(g_Console, 43, 12, 'L');
                                            if (g_dDungeonStealth3Time > 48.9)
                                            {
                                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                Cutscene.cleargrid(g_Console, 33, 11);
                                                Cutscene.cleargrid(g_Console, 43, 12);
                                                Cutscene.drawgrid(g_Console, 29, 10, 'R');
                                                Cutscene.drawgrid(g_Console, 46, 12, 'L');
                                                if (g_dDungeonStealth3Time > 49.2)
                                                {
                                                    Cutscene.cleargrid(g_Console, 29, 10);
                                                    Cutscene.cleargrid(g_Console, 46, 12);
                                                    Cutscene.drawgrid(g_Console, 24, 9, 'R');
                                                    Cutscene.drawgrid(g_Console, 49, 12, 'L');
                                                    if (g_dDungeonStealth3Time > 49.5)
                                                    {
                                                        Cutscene.cleargrid(g_Console, 24, 9);
                                                        Cutscene.cleargrid(g_Console, 49, 12);
                                                        Cutscene.drawgrid(g_Console, 20, 8, 'R');
                                                        Cutscene.drawgrid(g_Console, 52, 12, 'L');
                                                        if (g_dDungeonStealth3Time > 49.8)
                                                        {
                                                            Cutscene.cleargrid(g_Console, 20, 8);
                                                            Cutscene.cleargrid(g_Console, 52, 12);
                                                            Cutscene.drawgrid(g_Console, 16, 7, 'R');
                                                            Cutscene.drawgrid(g_Console, 55, 12, 'L');
                                                            if (g_dDungeonStealth3Time > 50.1)
                                                            {
                                                                Cutscene.cleargrid(g_Console, 16, 7);
                                                                Cutscene.cleargrid(g_Console, 55, 12);
                                                                Cutscene.drawgrid(g_Console, 12, 6, 'R');
                                                                Cutscene.drawgrid(g_Console, 58, 12, 'L');
                                                                if (g_dDungeonStealth3Time > 50.4)
                                                                {
                                                                    Cutscene.cleargrid(g_Console, 12, 6);
                                                                    Cutscene.cleargrid(g_Console, 58, 12);
                                                                    Cutscene.drawgrid(g_Console, 9, 5, 'R');
                                                                    Cutscene.drawgrid(g_Console, 61, 11, 'L');
                                                                    if (g_dDungeonStealth3Time > 50.7)
                                                                    {
                                                                        Cutscene.cleargrid(g_Console, 9, 5);
                                                                        Cutscene.cleargrid(g_Console, 61, 11);
                                                                        Cutscene.drawgrid(g_Console, 5, 4, 'R');
                                                                        Cutscene.drawgrid(g_Console, 61, 9, 'L');
                                                                        if (g_dDungeonStealth3Time > 50.7)
                                                                        {
                                                                            Cutscene.cleargrid(g_Console, 5, 4);
                                                                            Cutscene.cleargrid(g_Console, 61, 9);
                                                                            Cutscene.drawgrid(g_Console, 61, 7, 'L');
                                                                            if (g_dDungeonStealth3Time > 50.7)
                                                                            {
                                                                                Cutscene.cleargrid(g_Console, 61, 7);
                                                                                Cutscene.drawgrid(g_Console, 61, 5, 'L');
                                                                                if (g_dDungeonStealth3Time > 51.0)
                                                                                {
                                                                                    Cutscene.cleargrid(g_Console, 61, 5);
                                                                                    Cutscene.drawgrid(g_Console, 61, 3, 'L');
                                                                                    if (g_dDungeonStealth3Time > 51.3)
                                                                                    {
                                                                                        Cutscene.cleargrid(g_Console, 61, 3);
                                                                                        if (g_dDungeonStealth3Time > 51.6)
                                                                                        {
                                                                                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                            g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                                                                                            g_Console.writeToBuffer(c, "Robert: It seems like mayor Raymond was the mastermind", 0x0F);
                                                                                            g_Console.writeToBuffer(d, "        behind all these incidents afterall.", 0x0F);
                                                                                            if (g_dDungeonStealth3Time > 57.6)
                                                                                            {
                                                                                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                                                                                                g_Console.writeToBuffer(c, "Robert: I should prepare before confronting him.", 0x0F);
                                                                                                if (g_dDungeonStealth3Time > 61.6)
                                                                                                {
                                                                                                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

//HAVE NOT PUT DTTIME INTO RENDERED AREA
void Update_Boss_Room_Animation()
{
    if (g_dBossTime > 48.3)
    {
        g_eGameState = S_GAME;
    }
    processUserInput();
}
void Boss_Room_Animation()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.boss_room(g_Console);
    COORD c;
    COORD d;
    renderCharacter();
    c.X = 5;
    c.Y = 26;
    d.X = 5;
    d.Y = 27;
    Cutscene.drawgrid(g_Console, 40, 21, 'H'); //Robert
    Cutscene.drawgrid(g_Console, 40, 3, 'R'); //Raymond
    if (g_dBossTime > 0.3)
    {
        g_Console.writeToBuffer(c, "Raymond: It seems that the person I have been searching for", 0x0F);
        g_Console.writeToBuffer(d, "         came to me instead.", 0x0F);
        if (g_dBossTime > 5.3)
        {
            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
            g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
            g_Console.writeToBuffer(c, "Raymond: I should thank you for saving me the trouble.", 0x0F);
            if (g_dBossTime > 9.3)
            {
                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                g_Console.writeToBuffer(c, "Raymond: So... have you come here to surrender?", 0x0F);
                if (g_dBossTime > 13.3)
                {
                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                    Cutscene.cleargrid(g_Console, 40, 3);
                    Cutscene.drawgrid(g_Console, 43, 3, 'R');
                    if (g_dBossTime > 13.6)
                    {
                        Cutscene.cleargrid(g_Console, 43, 3);
                        Cutscene.drawgrid(g_Console, 46, 3, 'R');
                        if (g_dBossTime > 13.9)
                        {
                            Cutscene.cleargrid(g_Console, 46, 3);
                            Cutscene.drawgrid(g_Console, 49, 3, 'R');
                            if (g_dBossTime > 14.2)
                            {
                                Cutscene.cleargrid(g_Console, 49, 3);
                                Cutscene.drawgrid(g_Console, 52, 3, 'R');
                                if (g_dBossTime > 14.5)
                                {
                                    Cutscene.cleargrid(g_Console, 52, 3);
                                    Cutscene.drawgrid(g_Console, 55, 3, 'R');
                                    if (g_dBossTime > 14.8)
                                    {
                                        Cutscene.cleargrid(g_Console, 55, 3);
                                        Cutscene.drawgrid(g_Console, 57, 4, 'R');
                                        if (g_dBossTime > 15.1)
                                        {
                                            Cutscene.cleargrid(g_Console, 57, 4);
                                            Cutscene.drawgrid(g_Console, 57, 6, 'R');
                                            if (g_dBossTime > 15.4)
                                            {
                                                Cutscene.cleargrid(g_Console, 57, 6);
                                                Cutscene.drawgrid(g_Console, 57, 8, 'R');
                                                if (g_dBossTime > 15.7)
                                                {
                                                    Cutscene.cleargrid(g_Console, 57, 8);
                                                    Cutscene.drawgrid(g_Console, 57, 10, 'R');
                                                    if (g_dBossTime > 16.0)
                                                    {
                                                        Cutscene.cleargrid(g_Console, 57, 10);
                                                        Cutscene.drawgrid(g_Console, 57, 12, 'R');
                                                        if (g_dBossTime > 16.3)
                                                        {
                                                            Cutscene.cleargrid(g_Console, 57, 12);
                                                            Cutscene.drawgrid(g_Console, 57, 15, 'R');
                                                            if (g_dBossTime > 16.6)
                                                            {
                                                                Cutscene.cleargrid(g_Console, 57, 15);
                                                                Cutscene.drawgrid(g_Console, 57, 17, 'R');
                                                                if (g_dBossTime > 16.9)
                                                                {
                                                                    Cutscene.cleargrid(g_Console, 57, 17);
                                                                    Cutscene.drawgrid(g_Console, 57, 19, 'R');
                                                                    if (g_dBossTime > 17.2)
                                                                    {
                                                                        Cutscene.cleargrid(g_Console, 57, 19);
                                                                        Cutscene.drawgrid(g_Console, 57, 21, 'R');
                                                                        if (g_dBossTime > 17.5)
                                                                        {
                                                                            g_Console.writeToBuffer(c, "Raymond: Actually, Why don't you join me?", 0x0F);
                                                                            g_Console.writeToBuffer(d, "         We can rule the world together!", 0x0F);
                                                                            Cutscene.cleargrid(g_Console, 57, 21);
                                                                            Cutscene.drawgrid(g_Console, 55, 21, 'R');
                                                                            if (g_dBossTime > 22.5)
                                                                            {
                                                                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                                                                                g_Console.writeToBuffer(c, "Raymond: Wouldn't that be wonderful?", 0x0F);
                                                                                g_Console.writeToBuffer(d, "         It's a fantastic idea!!", 0x0F);
                                                                                Cutscene.cleargrid(g_Console, 55, 21);
                                                                                Cutscene.drawgrid(g_Console, 53, 21, 'R');//hi
                                                                                if (g_dBossTime > 26.5)
                                                                                {
                                                                                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                    g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                                                                                    g_Console.writeToBuffer(c, "Raymond: I've always wanted a friend to rule the world with me..", 0x0F);
                                                                                    g_Console.writeToBuffer(d, "         Two evil minds! And you're the perfect candidate!!", 0x0F);
                                                                                    Cutscene.cleargrid(g_Console, 53, 21);
                                                                                    Cutscene.drawgrid(g_Console, 51, 21, 'R');
                                                                                    if (g_dBossTime > 34.5)
                                                                                    {
                                                                                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                        g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                                                                                        g_Console.writeToBuffer(c, "Raymond: You wouldn't say no to a pal like me won't you?", 0x0F);
                                                                                        g_Console.writeToBuffer(d, "         WON'T YOU?!?", 0x0F);
                                                                                        Cutscene.cleargrid(g_Console, 51, 21);
                                                                                        Cutscene.drawgrid(g_Console, 49, 21, 'R');
                                                                                        if (g_dBossTime > 39.5)
                                                                                        {
                                                                                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                            g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                                                                                            Cutscene.cleargrid(g_Console, 51, 21);
                                                                                            Cutscene.drawgrid(g_Console, 49, 21, 'R');
                                                                                            if (g_dBossTime > 39.6)
                                                                                            {
                                                                                                Cutscene.cleargrid(g_Console, 49, 21);
                                                                                                Cutscene.drawgrid(g_Console, 47, 21, 'R');
                                                                                                if (g_dBossTime > 39.7)
                                                                                                {
                                                                                                    Cutscene.cleargrid(g_Console, 47, 21);
                                                                                                    Cutscene.drawgrid(g_Console, 45, 21, 'R');
                                                                                                    if (g_dBossTime > 39.8)
                                                                                                    {
                                                                                                        Cutscene.cleargrid(g_Console, 45, 21);
                                                                                                        Cutscene.drawgrid(g_Console, 43, 21, 'R');
                                                                                                        if (g_dBossTime > 39.9)
                                                                                                        {
                                                                                                            Cutscene.cleargrid(g_Console, 43, 21);
                                                                                                            Cutscene.drawgrid(g_Console, 41, 21, 'R');
                                                                                                            if (g_dBossTime > 40.0)
                                                                                                            {
                                                                                                                Cutscene.cleargrid(g_Console, 40, 21);
                                                                                                                Cutscene.drawgrid(g_Console, 39, 21, 'H');
                                                                                                                g_Console.writeToBuffer(c, "Robert: ...", 0x0F);
                                                                                                                g_Console.writeToBuffer(d, "        Stay away from me. I'm not joining you.", 0x0F);
                                                                                                                if (g_dBossTime > 44.0)
                                                                                                                {
                                                                                                                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                                    g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                                                                                                                    g_Console.writeToBuffer(c, "Raymond: You're no fun... Oh well, that means I have to crush you.", 0x0F);
                                                                                                                    g_Console.writeToBuffer(d, "         ONLY I CAN RULE THE WORLD!!!", 0x0F);
                                                                                                                    if (g_dBossTime > 48.0)
                                                                                                                    {
                                                                                                                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                                        g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Update_slashGuard()
{
    if (g_dslashGuard > 3)
    {
        g_eGameState = S_GAME;
    }
    processUserInput();
}
void slashGuard()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    COORD c;
    renderCharacter();
    Sprites.drawGuard(g_Console, 0);
    Cutscene.drawgrid(g_Console, 68, 5, '/');
    //next
    if (g_dslashGuard > 0.1)
    {
        Cutscene.drawgrid(g_Console, 67, 6, '|');
        if (g_dslashGuard > 0.2)
        {
            Cutscene.drawgrid(g_Console, 66, 6, '_');
            Cutscene.drawgrid(g_Console, 65, 7, '/');
            Cutscene.drawgrid(g_Console, 66, 7, '/');
            if (g_dslashGuard > 0.3)
            {
                Cutscene.drawgrid(g_Console, 64, 7, '_');
                Cutscene.drawgrid(g_Console, 63, 8, '/');
                Cutscene.drawgrid(g_Console, 64, 8, '/');
                if (g_dslashGuard > 0.4)
                {
                    Cutscene.drawgrid(g_Console, 62, 8, '_');
                    Cutscene.drawgrid(g_Console, 61, 9, '/');
                    Cutscene.drawgrid(g_Console, 62, 9, '/');
                    if (g_dslashGuard > 0.5)
                    {
                        Cutscene.drawgrid(g_Console, 60, 9, '_');
                        Cutscene.drawgrid(g_Console, 59, 10, '/');
                        Cutscene.drawgrid(g_Console, 60, 10, '/');
                        if (g_dslashGuard > 0.6)
                        {
                            Cutscene.drawgrid(g_Console, 58, 10, '_');
                            Cutscene.drawgrid(g_Console, 57, 11, '/');
                            Cutscene.drawgrid(g_Console, 58, 11, '/');
                            if (g_dslashGuard > 0.7)
                            {
                                Cutscene.drawgrid(g_Console, 56, 11, '_');
                                if (g_dslashGuard > 0.8)
                                {
                                    Cutscene.drawgrid(g_Console, 55, 12, '/');
                                    if (g_dslashGuard > 0.9)
                                    {
                                        Cutscene.drawgrid(g_Console, 54, 12, '_');
                                        if (g_dslashGuard > 1.0)
                                        {
                                            Cutscene.drawgrid(g_Console, 53, 12, '_');
                                            Cutscene.cleargrid(g_Console, 68, 5);
                                            if (g_dslashGuard > 1.1)
                                            {
                                                Cutscene.cleargrid(g_Console, 67, 6);
                                                if (g_dslashGuard > 1.2)
                                                {
                                                    Cutscene.drawgridG(g_Console, 66, 6, ' ');
                                                    Cutscene.drawgridG(g_Console, 65, 7, ' ');
                                                    Cutscene.drawgridG(g_Console, 66, 7, ' ');
                                                    if (g_dslashGuard > 1.3)
                                                    {
                                                        Cutscene.drawgridG(g_Console, 64, 7, ' ');
                                                        Cutscene.drawgridG(g_Console, 63, 8, '_');
                                                        Cutscene.drawgridG(g_Console, 64, 8, '_');
                                                        if (g_dslashGuard > 1.4)
                                                        {
                                                            Cutscene.drawgridG(g_Console, 62, 8, '_');
                                                            Cutscene.drawgrid(g_Console, 61, 9, ' ');
                                                            Cutscene.drawgrid(g_Console, 62, 9, ' ');
                                                            if (g_dslashGuard > 1.5)
                                                            {
                                                                Cutscene.drawgrid(g_Console, 60, 9, ' ');
                                                                Cutscene.drawgrid(g_Console, 59, 10, ' ');
                                                                Cutscene.drawgrid(g_Console, 60, 10, ' ');
                                                                if (g_dslashGuard > 1.6)
                                                                {
                                                                    Cutscene.drawgrid(g_Console, 58, 10, ' ');
                                                                    Cutscene.drawgridG(g_Console, 57, 11, '|');
                                                                    Cutscene.drawgrid(g_Console, 58, 11, ' ');
                                                                    if (g_dslashGuard > 1.7)
                                                                    {
                                                                        Cutscene.cleargrid(g_Console, 56, 11);
                                                                        if (g_dslashGuard > 1.8)
                                                                        {
                                                                            Cutscene.cleargrid(g_Console, 55, 12);
                                                                            if (g_dslashGuard > 1.9)
                                                                            {
                                                                                Cutscene.cleargrid(g_Console, 54, 12);
                                                                                if (g_dslashGuard > 2.0)
                                                                                {
                                                                                    Cutscene.cleargrid(g_Console, 53, 12);
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void splashScreenWait()    // waits for time to pass in splash screen
{
    if (g_dElapsedTime > 6.0) // wait for 3 seconds to switch to game mode, else do nothing
        g_eGameState = S_Orphanage_Animation;
}

void updateGame()       // gameplay logic
{
    g_sGuard.xLeft = false;
    g_sGuard.xRight = false;
    g_sGuard.xDown = false;
    g_sGuard.xUp = false;

    g_sGuard2.xLeft = false;
    g_sGuard2.xRight = false;
    g_sGuard2.xDown = false;
    g_sGuard2.xUp = false;

    g_sGuard3.xLeft = false;
    g_sGuard3.xRight = false;
    g_sGuard3.xDown = false;
    g_sGuard3.xUp = false;

    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    moveCharacter();    // moves the character, collision detection, physics, etc
                     // sound can be played here too.
}

void moveCharacter()
{
    // Updating the location of the character based on the key release
    // providing a beep sound whenver we shift the character
    if (g_skKeyEvent[K_UP].keyDown && g_sChar.m_cLocation.Y > 1)
    {
        int i = g_sChar.m_cLocation.X;
        int j = g_sChar.m_cLocation.Y;
        //int m = g_sEnemy.m_cLocation.X;
        //int n = g_sEnemy.m_cLocation.Y;
        if (rMap.Grid[j - 1][i] != '|')
        {
            if (rMap.Grid[j - 1][i] != '#')
            {
                if (rMap.Grid[j - 1][i] != '-')
                {
                    if (rMap.Grid[j - 1][i] != '_')
                    {
                        if (rMap.Grid[j - 1][i] != 'O')
                        {
                            if (rMap.Grid[j - 1][i] != 'E')
                            {
                                if (rMap.Grid[j - 1][i] != '/')
                                {
                                    g_sChar.m_cLocation.Y--;
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard.m_cLocation.Y][g_sGuard.m_cLocation.X])
                {
                    g_sGuard.xRight = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard.m_cLocation.Y][g_sGuard.m_cLocation.X])
                {
                    g_sGuard.xUp = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard.m_cLocation.Y][g_sGuard.m_cLocation.X])
                {
                    g_sGuard.xUp = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard.m_cLocation.Y][g_sGuard.m_cLocation.X])
                {
                    g_sGuard.xLeft = true;
                }
            }
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard2.m_cLocation.Y][g_sGuard2.m_cLocation.X])
                {
                    g_sGuard2.xRight = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard2.m_cLocation.Y][g_sGuard2.m_cLocation.X])
                {
                    g_sGuard2.xUp = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard2.m_cLocation.Y][g_sGuard2.m_cLocation.X])
                {
                    g_sGuard2.xUp = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard2.m_cLocation.Y][g_sGuard2.m_cLocation.X])
                {
                    g_sGuard2.xLeft = true;
                }
            }
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard3.m_cLocation.Y][g_sGuard3.m_cLocation.X])
                {
                    g_sGuard3.xRight = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard3.m_cLocation.Y][g_sGuard3.m_cLocation.X])
                {
                    g_sGuard3.xUp = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard3.m_cLocation.Y][g_sGuard3.m_cLocation.X])
                {
                    g_sGuard3.xUp = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard3.m_cLocation.Y][g_sGuard3.m_cLocation.X])
                {
                    g_sGuard3.xLeft = true;
                }
            }
        }
    }
    if (g_skKeyEvent[K_LEFT].keyDown && g_sChar.m_cLocation.X > 1)
    {
        int i = g_sChar.m_cLocation.X;
        int j = g_sChar.m_cLocation.Y;
        if (rMap.Grid[j][i - 1] != '|')
        {
            if (rMap.Grid[j][i - 1] != '#')
            {
                if (rMap.Grid[j][i - 1] != '-')
                {
                    if (rMap.Grid[j][i - 1] != '_')
                    {
                        if (rMap.Grid[j][i - 1] != 'O')
                        {
                            if (rMap.Grid[j][i - 1] != 'E')
                            {
                                if (rMap.Grid[j][i - 1] != '/')
                                {
                                    g_sChar.m_cLocation.X--;
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {

                // enemy on left side
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard.m_cLocation.Y][g_sGuard.m_cLocation.X])
                {
                    g_sGuard.xDown = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard.m_cLocation.Y][g_sGuard.m_cLocation.X])
                {
                    g_sGuard.xLeft = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard.m_cLocation.Y][g_sGuard.m_cLocation.X])
                {
                    g_sGuard.xUp = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard.m_cLocation.Y][g_sGuard.m_cLocation.X])
                {
                    g_sGuard.xLeft = true;
                }
            }
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {

                // enemy on left side
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard2.m_cLocation.Y][g_sGuard2.m_cLocation.X])
                {
                    g_sGuard2.xDown = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard2.m_cLocation.Y][g_sGuard2.m_cLocation.X])
                {
                    g_sGuard2.xLeft = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard2.m_cLocation.Y][g_sGuard2.m_cLocation.X])
                {
                    g_sGuard2.xUp = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard2.m_cLocation.Y][g_sGuard2.m_cLocation.X])
                {
                    g_sGuard2.xLeft = true;
                }
            }
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {

                // enemy on left side
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard3.m_cLocation.Y][g_sGuard3.m_cLocation.X])
                {
                    g_sGuard3.xDown = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard3.m_cLocation.Y][g_sGuard3.m_cLocation.X])
                {
                    g_sGuard3.xLeft = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard3.m_cLocation.Y][g_sGuard3.m_cLocation.X])
                {
                    g_sGuard3.xUp = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard3.m_cLocation.Y][g_sGuard3.m_cLocation.X])
                {
                    g_sGuard3.xLeft = true;
                }
            }
        }
    }
    if (g_skKeyEvent[K_DOWN].keyDown && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
    {
        int i = g_sChar.m_cLocation.X;
        int j = g_sChar.m_cLocation.Y;
        if (rMap.Grid[j + 1][i] != '|')
        {
            if (rMap.Grid[j + 1][i] != '#')
            {
                if (rMap.Grid[j + 1][i] != '-')
                {
                    if (rMap.Grid[j + 1][i] != '_')
                    {
                        if (rMap.Grid[j + 1][i] != 'O')
                        {
                            if (rMap.Grid[j + 1][i] != 'E')
                            {
                                if (rMap.Grid[j + 1][i] != '/')
                                {
                                    g_sChar.m_cLocation.Y++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard.m_cLocation.Y][g_sGuard.m_cLocation.X])
                {
                    g_sGuard.xDown = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard.m_cLocation.Y][g_sGuard.m_cLocation.X])
                {
                    g_sGuard.xLeft = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard.m_cLocation.Y][g_sGuard.m_cLocation.X])
                {
                    g_sGuard.xRight = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard.m_cLocation.Y][g_sGuard.m_cLocation.X])
                {
                    g_sGuard.xDown = true;
                }
            }
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard2.m_cLocation.Y][g_sGuard2.m_cLocation.X])
                {
                    g_sGuard2.xDown = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard2.m_cLocation.Y][g_sGuard2.m_cLocation.X])
                {
                    g_sGuard2.xLeft = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard2.m_cLocation.Y][g_sGuard2.m_cLocation.X])
                {
                    g_sGuard2.xRight = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard2.m_cLocation.Y][g_sGuard2.m_cLocation.X])
                {
                    g_sGuard2.xDown = true;
                }
            }
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard3.m_cLocation.Y][g_sGuard3.m_cLocation.X])
                {
                    g_sGuard3.xDown = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard3.m_cLocation.Y][g_sGuard3.m_cLocation.X])
                {
                    g_sGuard3.xLeft = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard3.m_cLocation.Y][g_sGuard3.m_cLocation.X])
                {
                    g_sGuard3.xRight = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard3.m_cLocation.Y][g_sGuard3.m_cLocation.X])
                {
                    g_sGuard3.xDown = true;
                }
            }
        }
    }
    if (g_skKeyEvent[K_RIGHT].keyDown && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
    {
        int i = g_sChar.m_cLocation.X;
        int j = g_sChar.m_cLocation.Y;
        if (rMap.Grid[j][i + 1] != '|')
        {
            if (rMap.Grid[j][i + 1] != '#')
            {
                if (rMap.Grid[j][i + 1] != '-')
                {
                    if (rMap.Grid[j][i + 1] != '_')
                    {
                        if (rMap.Grid[j][i + 1] != 'O')
                        {
                            if (rMap.Grid[j][i + 1] != 'E')
                            {
                                if (rMap.Grid[j][i + 1] != '/')
                                {
                                    g_sChar.m_cLocation.X++;
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard.m_cLocation.Y][g_sGuard.m_cLocation.X])
                {
                    g_sGuard.xDown = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard.m_cLocation.Y][g_sGuard.m_cLocation.X])
                {
                    g_sGuard.xRight = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard.m_cLocation.Y][g_sGuard.m_cLocation.X])
                {
                    g_sGuard.xRight = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard.m_cLocation.Y][g_sGuard.m_cLocation.X])
                {
                    g_sGuard.xUp = true;
                }
            }
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard2.m_cLocation.Y][g_sGuard2.m_cLocation.X])
                {
                    g_sGuard2.xDown = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard2.m_cLocation.Y][g_sGuard2.m_cLocation.X])
                {
                    g_sGuard2.xRight = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard2.m_cLocation.Y][g_sGuard2.m_cLocation.X])
                {
                    g_sGuard2.xRight = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard2.m_cLocation.Y][g_sGuard2.m_cLocation.X])
                {
                    g_sGuard.xUp = true;
                }
            }
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard3.m_cLocation.Y][g_sGuard3.m_cLocation.X])
                {
                    g_sGuard3.xDown = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y - i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard3.m_cLocation.Y][g_sGuard3.m_cLocation.X])
                {
                    g_sGuard3.xRight = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X - j] == rMap.Grid[g_sGuard3.m_cLocation.Y][g_sGuard3.m_cLocation.X])
                {
                    g_sGuard3.xRight = true;
                }
                if (rMap.Grid[g_sChar.m_cLocation.Y + i][g_sChar.m_cLocation.X + j] == rMap.Grid[g_sGuard3.m_cLocation.Y][g_sGuard3.m_cLocation.X]) // works
                {
                    g_sGuard.xUp = true;
                }
            }
        }
    }


    if (g_skKeyEvent[K_SPACE].keyDown)
    {
        g_sChar.m_bActive = !g_sChar.m_bActive;
    }
}

void processUserInput()
{
    // quits the game if player hits the escape key
    if (g_skKeyEvent[K_ESCAPE].keyDown)
        g_bQuitGame = true;
}

void renderMyGame()
{
    COORD c;
    c.X = 5;
    c.Y = 5;
    g_Console.writeToBuffer(c, "***");
}

//--------------------------------------------------------------
// Purpose  : Render function is to update the console screen
//            At this point, you should know exactly what to draw onto the screen.
//            Just draw it!
//            To get an idea of the values for colours, look at console.h and the URL listed there
// Input    : void
// Output   : void
//--------------------------------------------------------------
void render()
{
    clearScreen();
    if (g_sChar.counter == true)
    {
        clearMenu();
    }
    // clears the current screen and draw from scratch 
    switch (g_eGameState)
    {
    case S_GAME: renderGame();
        break;
    case S_MENU_UI: render_Main_Menu();
        break;
    case S_Game_Over: RenderGameOver();
        break;
    case S_SPLASHSCREEN: renderSplashScreen();
        break;
    case S_Orphanage_Animation: Orphanage_Animation();
        break;
    case S_Orphanage_Children_Animation: Orphanage_Children_Animation();
        break;

        //Areas of the game
    case S_Townsquare: renderMap_Townsquare();
        break;
    case S_Protest_Area: renderMap_Protest_Area();
        break;
    case S_Path_Area: renderMap_Path_Area();
        break;
    case S_OAF: renderMap_OAF();
        break;
    case S_IAF1: renderMap_IAF1();
        break;
    case S_IAF2: renderMap_IAF2();
        break;
    case S_IAF3: renderMap_IAF3();
        break;
    case S_IAF4: renderMap_IAF4();
        break;
    case S_Inside_Medical_Facility: renderMap_Inside_Medical_Facility();
        break;
    case S_Dungeon_Cell: renderMap_Dungeon_Cell();
        break;
    case S_Dungeon_Stealth_1: renderMap_DS1();
        break;
    case S_Dungeon_Stealth_2: renderMap_DS2();
        break;
    case S_Dungeon_Stealth_3: renderMap_DS3();
        break;
    case S_Boss_Battle_Room: renderMap_Boss_Battle_Room();
        break;

    //Animations
    case S_Protest_Area_Animation: Protest_Area_Animation();
        break;
    case S_Dungeon_Cell_Animation: Dungeon_Cell_Animation();
        break;
    case S_Path_Area_Animation: Path_Area_Animation();
        break;
    case S_IAF3_Animation: IAF3_Animation();
        break;
    case S_Medical_Fight_Animation: Medical_Fight_Animation();
        break;
    case S_Medical_Facility_Animation: Medical_Facility_Animation();
        break;
    case S_Medical_Facility_Part2_Animation: Medical_Facility_Part2_Animation();
        break;
    case S_Dungeon_Stealth3_Animation: Dungeon_Stealth3_Animation();
        break;
    case S_Boss_Room_Animation: Boss_Room_Animation();
        break;
    case S_BattleScreen: RenderBattleScreen();
        break;

        //render battle animations
    case S_SlashGuard: slashGuard();
        break;
    }
    renderFramerate();      // renders debug information, frame rate, elapsed time, etc
    renderInputEvents();    // renders status of input events
    renderToScreen(); // dump the contents of the buffer to the screen, one frame worth of game
    //Cutscene.orphanageCaretakerCutscene(g_Console,0,0,' ');
}

void clearScreen()
{
    // Clears the buffer with this colour attribute
    g_Console.clearBuffer(0x1F);
}

void clearMenu()
{
    g_Console.clearBuffer(0x00);
}

void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
    g_Console.flushBufferToConsole();
}

void renderSplashScreen()  // renders the splash screen
{
    COORD c = g_Console.getConsoleSize();
    c.Y /= 3;
    c.X = c.X / 2 - 9;
    g_Console.writeToBuffer(c, "A game in 3 seconds", 0x03);
    if (g_dElapsedTime > 3.0)
    {
        c.Y += 1;
        c.X = g_Console.getConsoleSize().X / 2 - 20;
        g_Console.writeToBuffer(c, "Press <Space> to change character colour", 0x09);
        c.Y += 1;
        c.X = g_Console.getConsoleSize().X / 2 - 9;
        g_Console.writeToBuffer(c, "Press 'Esc' to quit", 0x09);
    }

}

void renderGame()
{
    if (g_sChar.Orp_Obj2 == false)
    {
        rMap.initialise(g_Console);

        rMap.Animation(g_Console, 11, 7, (char)12);
        rMap.Animation(g_Console, 9, 7, (char)12);
        rMap.Animation(g_Console, 13, 7, (char)12);
        rMap.Animation(g_Console, 11, 7, (char)12);
        int j = 6;
        for (int i = 9; i < 14; i++)
        {
            rMap.Animation(g_Console, i, j, '-');
        }
        j = 8;
        for (int i = 9; i < 14; i++)
        {
            rMap.Animation(g_Console, i, j, '-');
        }
        rMap.Animation(g_Console, 9, 7, '|');
        rMap.Animation(g_Console, 13, 7, '|');

        rMap.drawAnimation(g_Console, 40, 7, 'F');
        rMap.drawAnimation(g_Console, 33, 22, 'B');

        rMap.Border(g_Console);
        rMap.orphanageDoor(g_Console);
        rMap.orphanage(g_Console);
    }
    else
    {
        rMap.initialise(g_Console);
        rMap.Border(g_Console);
        rMap.Animation(g_Console, 11, 7, (char)12);
        rMap.Animation(g_Console, 9, 7, (char)12);
        rMap.Animation(g_Console, 13, 7, (char)12);
        rMap.Animation(g_Console, 11, 7, (char)12);
        int j = 6;
        for (int i = 9; i < 14; i++)
        {
            rMap.Animation(g_Console, i, j, '-');
        }
        j = 8;
        for (int i = 9; i < 14; i++)
        {
            rMap.Animation(g_Console, i, j, '-');
        }
        rMap.Animation(g_Console, 9, 7, '|');
        rMap.Animation(g_Console, 13, 7, '|');
        rMap.drawAnimation(g_Console, 33, 22, 'B');
        rMap.orphanageDoor(g_Console);
        if (g_sChar.Orp_Dialogue == true)
        {
            COORD c;  COORD d;
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Objective: Take the backpack before leaving the burning house!", 0x0F, 100);
            d.X = 5;
            d.Y = 28;
            g_Console.writeToBuffer(d, "B = Backpack", 0x0F, 100);
        }
    }
    /*
    rMap.initialise(g_Console);
    rMap.printmap(g_Console);
    rMap.orphanage(g_Console);

    renderCharacter();
    //Cutscene.orphanageCaretakerCutscene(g_Console);
    */

    //renderEnemy();
    //renderMap(); // renders the character into the buffer
    renderCharacter();

    if ((rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == '@') && (g_sChar.takenBackpack == true) && (g_sChar.takenExtinguisher == true))
    {
        g_eGameState = S_Townsquare;
        g_sChar.m_cLocation.X = 22;
        g_sChar.m_cLocation.Y = 17;
    }
    if (rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == 'F')
    {
        g_sChar.fire = true;
        g_sChar.Orp_Obj1 = false;
        g_sChar.takenExtinguisher = true;
    }
    if (rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == 'B')
    {
        g_sChar.takenBackpack = true;
    }
    if (g_sChar.Orp_Obj1 == true)
    {
        COORD c; COORD d;
        c.X = 5;
        c.Y = 26;
        g_Console.writeToBuffer(c, "Objective: Take the fire extinguisher and put out the fire!", 0x0F, 100);
        d.X = 5;
        d.Y = 28;
        g_Console.writeToBuffer(d, "F = Fire Extinguisher", 0x0F, 100);

    }
    /*
    if (rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == rMap.Grid[g_sEnemy.m_cLocation.Y][g_sEnemy.m_cLocation.X])
    {
        g_sChar.m_cLocation.X = 20;
        g_sChar.m_cLocation.Y = 17;
    }*/
}
void renderMap_NPC()
{
    WORD charColor = 0x0E;

    g_sNPC2.m_cLocation.X = 65;
    g_sNPC2.m_cLocation.Y = 13;

    g_sNPC3.m_cLocation.X = 64;
    g_sNPC3.m_cLocation.Y = 6;

    g_sNPC4.m_cLocation.X = 52;
    g_sNPC4.m_cLocation.Y = 8;

    g_sNPC5.m_cLocation.X = 19;
    g_sNPC5.m_cLocation.Y = 9;

    g_sNPC6.m_cLocation.X = 12;
    g_sNPC6.m_cLocation.Y = 13;

    g_sNPC7.m_cLocation.X = 61;
    g_sNPC7.m_cLocation.Y = 17;

    g_Console.writeToBuffer(g_sNPC1.m_cLocation, (char)12, charColor);
    g_Console.writeToBuffer(g_sNPC2.m_cLocation, (char)12, charColor);
    g_Console.writeToBuffer(g_sNPC3.m_cLocation, (char)12, charColor);
    g_Console.writeToBuffer(g_sNPC4.m_cLocation, (char)12, charColor);
    g_Console.writeToBuffer(g_sNPC5.m_cLocation, (char)12, charColor);
    g_Console.writeToBuffer(g_sNPC6.m_cLocation, (char)12, charColor);
    g_Console.writeToBuffer(g_sNPC7.m_cLocation, (char)12, charColor);
}
void renderMap_Townsquare()
{
    g_sChar.takenBackpack = false;
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.townsquare(g_Console);
    renderMap_NPC();
    g_sChar.talked = true;
    renderCharacter();  // renders the character into the buffer

    if ((g_sChar.m_cLocation.X == 66 && g_sChar.m_cLocation.Y == 13 || g_sChar.m_cLocation.X == 64 && g_sChar.m_cLocation.Y == 13) || (g_sChar.m_cLocation.X == 65 && g_sChar.m_cLocation.Y == 14 || g_sChar.m_cLocation.X == 65 && g_sChar.m_cLocation.Y == 12))
    {
        g_sNPC2.talked = true;
        Dialogues.Tom(g_Console);
    }
    if ((g_sChar.m_cLocation.X == 65 && g_sChar.m_cLocation.Y == 6 || g_sChar.m_cLocation.X == 63 && g_sChar.m_cLocation.Y == 6) || (g_sChar.m_cLocation.X == 64 && g_sChar.m_cLocation.Y == 7 || g_sChar.m_cLocation.X == 64 && g_sChar.m_cLocation.Y == 5))
    {
        g_sNPC3.talked = true;
        Dialogues.Bobby(g_Console);
    }
    if ((g_sChar.m_cLocation.X == 53 && g_sChar.m_cLocation.Y == 8 || g_sChar.m_cLocation.X == 51 && g_sChar.m_cLocation.Y == 8) || (g_sChar.m_cLocation.X == 52 && g_sChar.m_cLocation.Y == 9 || g_sChar.m_cLocation.X == 52 && g_sChar.m_cLocation.Y == 7))
    {
        g_sNPC4.talked = true;
        Dialogues.Harry(g_Console);
    }
    if ((g_sChar.m_cLocation.X == 20 && g_sChar.m_cLocation.Y == 9 || g_sChar.m_cLocation.X == 18 && g_sChar.m_cLocation.Y == 9) || (g_sChar.m_cLocation.X == 19 && g_sChar.m_cLocation.Y == 10 || g_sChar.m_cLocation.X == 19 && g_sChar.m_cLocation.Y == 8))
    {
        g_sNPC5.talked = true;
        Dialogues.Sam(g_Console);
    }
    if ((g_sChar.m_cLocation.X == 11 && g_sChar.m_cLocation.Y == 13 || g_sChar.m_cLocation.X == 13 && g_sChar.m_cLocation.Y == 13) || (g_sChar.m_cLocation.X == 12 && g_sChar.m_cLocation.Y == 14 || g_sChar.m_cLocation.X == 12 && g_sChar.m_cLocation.Y == 12))
    {
        g_sNPC6.talked = true;
        Dialogues.Charles(g_Console);
    }
    if ((g_sChar.m_cLocation.X == 62 && g_sChar.m_cLocation.Y == 17 || g_sChar.m_cLocation.X == 60 && g_sChar.m_cLocation.Y == 17) || (g_sChar.m_cLocation.X == 61 && g_sChar.m_cLocation.Y == 18 || g_sChar.m_cLocation.X == 61 && g_sChar.m_cLocation.Y == 16))
    {
        g_sNPC7.talked = true;
        Dialogues.Emmanuel(g_Console);
    }

    if (g_sNPC2.talked == true)
    {
        g_Console.writeToBuffer(g_sNPC2.m_cLocation, (char)12, 0x06);
    }
    if (g_sNPC3.talked == true)
    {
        g_Console.writeToBuffer(g_sNPC3.m_cLocation, (char)12, 0x06);
    }
    if (g_sNPC4.talked == true)
    {
        g_Console.writeToBuffer(g_sNPC4.m_cLocation, (char)12, 0x06);
    }
    if (g_sNPC5.talked == true)
    {
        g_Console.writeToBuffer(g_sNPC5.m_cLocation, (char)12, 0x06);
    }
    if (g_sNPC6.talked == true)
    {
        g_Console.writeToBuffer(g_sNPC6.m_cLocation, (char)12, 0x06);
    }
    if (g_sNPC7.talked == true)
    {
        g_Console.writeToBuffer(g_sNPC7.m_cLocation, (char)12, 0x06);
    }


    if ((rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == '@') && (g_sNPC2.talked == true) && (g_sNPC3.talked == true) && (g_sNPC4.talked == true) && (g_sNPC5.talked == true) && (g_sNPC6.talked == true) && (g_sNPC7.talked == true))
    {
        g_dProtestTime = 0.0;
        g_eGameState = S_Protest_Area_Animation;
        g_sChar.m_cLocation.X = 40;
        g_sChar.m_cLocation.Y = 15;
    }
}

void renderMap_Protest_Area()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.protest_area(g_Console);
    renderCharacter();  // renders the character into the buffer
    if (rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == '@')
    {
        g_dPathTime = 0.0;
        g_eGameState = S_Path_Area_Animation;
        g_sChar.m_cLocation.X = 41;
        g_sChar.m_cLocation.Y = 21;
    }
    if (g_sChar.m_cLocation.Y == 62 && g_sChar.m_cLocation.X == 4)
    {
        g_dPathTime = 0.0;
        g_eGameState = S_Dungeon_Stealth_3;
        g_sChar.m_cLocation.X = 41;
        g_sChar.m_cLocation.Y = 21;
    }
}

void renderMap_Path_Area()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.patharea(g_Console);
    renderCharacter();  // renders the character into the buffer

    //to OAF area
    if (g_sChar.m_cLocation.Y == 2 && (g_sChar.m_cLocation.X == 37 || g_sChar.m_cLocation.X == 38 || g_sChar.m_cLocation.X == 39 || g_sChar.m_cLocation.X == 40 || g_sChar.m_cLocation.X == 41 || g_sChar.m_cLocation.X == 42 || g_sChar.m_cLocation.X == 43 || g_sChar.m_cLocation.X == 44 || g_sChar.m_cLocation.X == 45))
    {
        g_dPathTime = 0.0;
        g_eGameState = S_OAF;
        g_sChar.m_cLocation.X = 7;
        g_sChar.m_cLocation.Y = 21;
    }

    //to inside medical facility
    if ((g_sChar.m_cLocation.Y == 11 || g_sChar.m_cLocation.Y == 12 || g_sChar.m_cLocation.Y == 13 || g_sChar.m_cLocation.Y == 14) && g_sChar.m_cLocation.X == 77)
    {
        g_eGameState = S_Inside_Medical_Facility;
        g_sChar.m_cLocation.X = 3;
        g_sChar.m_cLocation.Y = 12;
    }

    //to protest area
    if (g_sChar.m_cLocation.Y == 22 && (g_sChar.m_cLocation.X == 37 || g_sChar.m_cLocation.X == 38 || g_sChar.m_cLocation.X == 39 || g_sChar.m_cLocation.X == 40 || g_sChar.m_cLocation.X == 41 || g_sChar.m_cLocation.X == 42 || g_sChar.m_cLocation.X == 43 || g_sChar.m_cLocation.X == 44 || g_sChar.m_cLocation.X == 45))
    {
        g_eGameState = S_Protest_Area;
        g_sChar.m_cLocation.X = 72;
        g_sChar.m_cLocation.Y = 3;
    }
}

//change this gamestate
void renderMap_OAF()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.outside_abandoned_facility(g_Console);
    renderCharacter();  // renders the character into the buffer
    //back to path area
    if (g_sChar.m_cLocation.Y == 22 && (g_sChar.m_cLocation.X == 2 || g_sChar.m_cLocation.X == 3 || g_sChar.m_cLocation.X == 4 || g_sChar.m_cLocation.X == 5 || g_sChar.m_cLocation.X == 6 || g_sChar.m_cLocation.X == 7 || g_sChar.m_cLocation.X == 8 || g_sChar.m_cLocation.X == 9 || g_sChar.m_cLocation.X == 10 || g_sChar.m_cLocation.X == 11))
    {
        g_dPathTime = 0.0;
        g_eGameState = S_Path_Area;
        g_sChar.m_cLocation.X = 41;
        g_sChar.m_cLocation.Y = 3;
    }
    //to IAF1
    if ((g_sChar.m_cLocation.Y == 17 || g_sChar.m_cLocation.Y == 18 || g_sChar.m_cLocation.Y == 19 || g_sChar.m_cLocation.Y == 20) && g_sChar.m_cLocation.X == 58)
    {
        g_dPathTime = 0.0;
        g_eGameState = S_IAF1;
        g_sChar.m_cLocation.X = 41;
        g_sChar.m_cLocation.Y = 21;
    }
}

void renderMap_IAF1()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.insideAbandonedFacility1(g_Console);
    renderCharacter();  // renders the character into the buffer
    //IAF2
    if ((g_sChar.m_cLocation.Y == 17 || g_sChar.m_cLocation.Y == 18 || g_sChar.m_cLocation.Y == 19 || g_sChar.m_cLocation.Y == 20 || g_sChar.m_cLocation.Y == 21 || g_sChar.m_cLocation.Y == 22) && g_sChar.m_cLocation.X == 2)
    {
        g_dPathTime = 0.0;
        g_eGameState = S_IAF2;
        g_sChar.m_cLocation.X = 75;
        g_sChar.m_cLocation.Y = 13;
    }
    //IAF4
    if ((g_sChar.m_cLocation.Y == 17 || g_sChar.m_cLocation.Y == 18 || g_sChar.m_cLocation.Y == 19 || g_sChar.m_cLocation.Y == 20 || g_sChar.m_cLocation.Y == 21 || g_sChar.m_cLocation.Y == 22) && g_sChar.m_cLocation.X == 77)
    {
        g_dPathTime = 0.0;
        g_eGameState = S_IAF4;
        g_sChar.m_cLocation.X = 3;
        g_sChar.m_cLocation.Y = 12;
    }
    //OAF
    if (g_sChar.m_cLocation.Y == 22 && (g_sChar.m_cLocation.X == 37 || g_sChar.m_cLocation.X == 38 || g_sChar.m_cLocation.X == 39 || g_sChar.m_cLocation.X == 40 || g_sChar.m_cLocation.X == 41 || g_sChar.m_cLocation.X == 42 || g_sChar.m_cLocation.X == 43 || g_sChar.m_cLocation.X == 44))
    {
        g_dPathTime = 0.0;
        g_eGameState = S_OAF;
        g_sChar.m_cLocation.X = 57;
        g_sChar.m_cLocation.Y = 18;
    }
}

void renderMap_IAF2()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.insideAbandonedFacility2(g_Console);
    renderCharacter();  // renders the character into the buffer
    //IAF1
    if ((g_sChar.m_cLocation.Y == 11 || g_sChar.m_cLocation.Y == 12 || g_sChar.m_cLocation.Y == 13 || g_sChar.m_cLocation.Y == 14 || g_sChar.m_cLocation.Y == 15) && g_sChar.m_cLocation.X == 76)
    {
        g_dPathTime = 0.0;
        g_eGameState = S_IAF1;
        g_sChar.m_cLocation.X = 3;
        g_sChar.m_cLocation.Y = 20;
    }
    //IA3
    if (g_sChar.m_cLocation.Y == 2 && (g_sChar.m_cLocation.X == 32 || g_sChar.m_cLocation.X == 33 || g_sChar.m_cLocation.X == 34 || g_sChar.m_cLocation.X == 35 || g_sChar.m_cLocation.X == 36 || g_sChar.m_cLocation.X == 37 || g_sChar.m_cLocation.X == 38 || g_sChar.m_cLocation.X == 39 || g_sChar.m_cLocation.X == 40 || g_sChar.m_cLocation.X == 41 || g_sChar.m_cLocation.X == 42 || g_sChar.m_cLocation.X == 43 || g_sChar.m_cLocation.X == 44))
    {
        g_dIAF3Time = 0.0;
        g_eGameState = S_IAF3_Animation;
        g_sChar.m_cLocation.X = 40;
        g_sChar.m_cLocation.Y = 21;
    }
}
void renderMap_IAF3()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.insideAbandonedFacility3(g_Console);
    renderCharacter();  // renders the character into the buffer
    //Back to IAF 2
    if ((g_sChar.m_cLocation.Y == 22) && (g_sChar.m_cLocation.X == 39 || g_sChar.m_cLocation.X == 40 || g_sChar.m_cLocation.X == 41))
    {
        g_dPathTime = 0.0;
        g_eGameState = S_IAF2;
        g_sChar.m_cLocation.X = 38;
        g_sChar.m_cLocation.Y = 3;
    }
}
void renderMap_IAF4()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.insideAbandonedFacility4(g_Console);
    renderCharacter();  // renders the character into the buffer
    //Back to IAF1
    if ((g_sChar.m_cLocation.Y == 11 || g_sChar.m_cLocation.Y == 12 || g_sChar.m_cLocation.Y == 13 || g_sChar.m_cLocation.Y == 14) && g_sChar.m_cLocation.X == 2)
    {
        g_dPathTime = 0.0;
        g_eGameState = S_IAF1;
        g_sChar.m_cLocation.X = 76;
        g_sChar.m_cLocation.Y = 20;
    }
}
void renderMap_Inside_Medical_Facility()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.insideMedicalFacility(g_Console);
    renderCharacter();  // renders the character into the buffer
    if ((g_sChar.m_cLocation.Y == 10 || g_sChar.m_cLocation.Y == 11 || g_sChar.m_cLocation.Y == 12 || g_sChar.m_cLocation.Y == 13 || g_sChar.m_cLocation.Y == 14) && g_sChar.m_cLocation.X == 2)
    {
        g_dPathTime = 0.0;
        g_eGameState = S_Path_Area;
        g_sChar.m_cLocation.X = 76;
        g_sChar.m_cLocation.Y = 12;
    }
}
//change this gamestate
void renderMap_Dungeon_Cell()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.dungeon_cell(g_Console);
    renderCharacter();  // renders the character into the buffer
    //to DS1
    if (rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == '@')
    {
        g_dPathTime = 0.0;
        g_eGameState = S_Dungeon_Stealth_1;
        g_sChar.m_cLocation.X = 5;
        g_sChar.m_cLocation.Y = 21;
    }
}
void renderMap_DS1()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.dungeon_stealth1(g_Console);
    if (g_sGuard.enemyDie == true)
    {
        g_sGuard.m_cLocation.Y = -1;
        g_sGuard.m_cLocation.X = -1;
    }
    if (g_sGuard2.enemyDie == true)
    {
        g_sGuard2.m_cLocation.Y = -1;
        g_sGuard2.m_cLocation.X = -1;
    }
    if (g_sGuard3.enemyDie == true)
    {
        g_sGuard3.m_cLocation.Y = -1;
        g_sGuard3.m_cLocation.X = -1;
    }
    renderCharacter();
    //g_sChar.m_cLocation.Y = 18;
    //g_sChar.m_cLocation.X = 4;
    renderEnemy();
    //To DS2
    if (g_sChar.m_cLocation.Y == 22 && (g_sChar.m_cLocation.X == 11 || g_sChar.m_cLocation.X == 12 || g_sChar.m_cLocation.X == 13 || g_sChar.m_cLocation.X == 14 || g_sChar.m_cLocation.X == 15 || g_sChar.m_cLocation.X == 16 || g_sChar.m_cLocation.X == 17 || g_sChar.m_cLocation.X == 18))
    {
        GuardDetectTime = 0.0;
        g_eGameState = S_Dungeon_Stealth_2;
        g_sChar.m_cLocation.X = 5;
        g_sChar.m_cLocation.Y = 21;
    }

    //to Dungeon Cell
    if (g_sChar.m_cLocation.Y == 22 && (g_sChar.m_cLocation.X == 2 || g_sChar.m_cLocation.X == 3 || g_sChar.m_cLocation.X == 4 || g_sChar.m_cLocation.X == 5 || g_sChar.m_cLocation.X == 6 || g_sChar.m_cLocation.X == 7 || g_sChar.m_cLocation.X == 8 || g_sChar.m_cLocation.X == 9))
    {
        g_dPathTime = 0.0;
        g_eGameState = S_Dungeon_Cell;
        g_sChar.m_cLocation.X = 6;
        g_sChar.m_cLocation.Y = 3;
    }
    if (g_sChar.unlockDoorDS1 == true)
    {
        COORD c;

        for (int i = 0; i < 10; i++)
        {
            c.X = 27 + i;
            c.Y = 14;
            rMap.Animation(g_Console, c.X, c.Y, ' ');
        }
    }
    if (g_sGuard.xLeft == true)
    {
        int i = g_sGuard.m_cLocation.X;
        int j = g_sGuard.m_cLocation.Y;
        if (rMap.Grid[j][i - 1] != '|')
        {
            if (rMap.Grid[j][i - 1] != '#')
            {
                if (rMap.Grid[j][i - 1] != '-')
                {
                    if (rMap.Grid[j][i - 1] != '_')
                    {
                        if (rMap.Grid[j][i - 1] != (char)12)
                        {
                            if (rMap.Grid[j][i - 1] != 'E')
                            {
                                g_sGuard.m_cLocation.X--;
                            }
                        }
                    }
                }
            }
        }


    }
    if (g_sGuard.xRight == true)
    {
        int i = g_sGuard.m_cLocation.X;
        int j = g_sGuard.m_cLocation.Y;
        if (rMap.Grid[j][i + 1] != '|')
        {
            if (rMap.Grid[j][i + 1] != '#')
            {
                if (rMap.Grid[j][i + 1] != '-')
                {
                    if (rMap.Grid[j][i + 1] != '_')
                    {
                        if (rMap.Grid[j][i + 1] != (char)12)
                        {
                            if (rMap.Grid[j][i + 1] != 'E')
                            {
                                g_sGuard.m_cLocation.X++;
                            }
                        }
                    }
                }
            }
        }

    }
    if (g_sGuard.xUp == true)
    {
        int i = g_sGuard.m_cLocation.X;
        int j = g_sGuard.m_cLocation.Y;
        if (rMap.Grid[j - 1][i] != '|')
        {
            if (rMap.Grid[j - 1][i] != '#')
            {
                if (rMap.Grid[j - 1][i] != '-')
                {
                    if (rMap.Grid[j - 1][i] != '_')
                    {
                        if (rMap.Grid[j - 1][i] != (char)12)
                        {
                            if (rMap.Grid[j - 1][i] != 'E')
                            {
                                g_sGuard.m_cLocation.Y--;
                            }
                        }
                    }
                }
            }
        }

    }
    if (g_sGuard.xDown == true)
    {
        int i = g_sGuard.m_cLocation.X;
        int j = g_sGuard.m_cLocation.Y;
        if (rMap.Grid[j + 1][i] != '|')
        {
            if (rMap.Grid[j + 1][i] != '#')
            {
                if (rMap.Grid[j + 1][i] != '-')
                {
                    if (rMap.Grid[j + 1][i] != '_')
                    {
                        if (rMap.Grid[j + 1][i] != (char)12)
                        {
                            if (rMap.Grid[j + 1][i] != 'E')
                            {
                                g_sGuard.m_cLocation.Y++;
                            }
                        }
                    }
                }
            }
        }
    }
    if (g_sGuard2.xLeft == true)
    {
        int i = g_sGuard2.m_cLocation.X;
        int j = g_sGuard2.m_cLocation.Y;
        if (rMap.Grid[j][i - 1] != '|')
        {
            if (rMap.Grid[j][i - 1] != '#')
            {
                if (rMap.Grid[j][i - 1] != '-')
                {
                    if (rMap.Grid[j][i - 1] != '_')
                    {
                        if (rMap.Grid[j][i - 1] != (char)12)
                        {
                            if (rMap.Grid[j][i - 1] != 'E')
                            {
                                g_sGuard2.m_cLocation.X--;
                            }
                        }
                    }
                }
            }
        }


    }
    if (g_sGuard2.xRight == true)
    {
        int i = g_sGuard2.m_cLocation.X;
        int j = g_sGuard2.m_cLocation.Y;
        if (rMap.Grid[j][i + 1] != '|')
        {
            if (rMap.Grid[j][i + 1] != '#')
            {
                if (rMap.Grid[j][i + 1] != '-')
                {
                    if (rMap.Grid[j][i + 1] != '_')
                    {
                        if (rMap.Grid[j][i + 1] != (char)12)
                        {
                            if (rMap.Grid[j][i + 1] != 'E')
                            {
                                g_sGuard2.m_cLocation.X++;
                            }
                        }
                    }
                }
            }
        }

    }
    if (g_sGuard2.xUp == true)
    {
        int i = g_sGuard2.m_cLocation.X;
        int j = g_sGuard2.m_cLocation.Y;
        if (rMap.Grid[j - 1][i] != '|')
        {
            if (rMap.Grid[j - 1][i] != '#')
            {
                if (rMap.Grid[j - 1][i] != '-')
                {
                    if (rMap.Grid[j - 1][i] != '_')
                    {
                        if (rMap.Grid[j - 1][i] != (char)12)
                        {
                            if (rMap.Grid[j - 1][i] != 'E')
                            {
                                g_sGuard2.m_cLocation.Y--;
                            }
                        }
                    }
                }
            }
        }

    }
    if (g_sGuard2.xDown == true)
    {
        int i = g_sGuard2.m_cLocation.X;
        int j = g_sGuard2.m_cLocation.Y;
        if (rMap.Grid[j + 1][i] != '|')
        {
            if (rMap.Grid[j + 1][i] != '#')
            {
                if (rMap.Grid[j + 1][i] != '-')
                {
                    if (rMap.Grid[j + 1][i] != '_')
                    {
                        if (rMap.Grid[j + 1][i] != (char)12)
                        {
                            if (rMap.Grid[j + 1][i] != 'E')
                            {
                                g_sGuard2.m_cLocation.Y++;
                            }
                        }
                    }
                }
            }
        }
    }
    if (g_sGuard3.xLeft == true)
    {
        int i = g_sGuard3.m_cLocation.X;
        int j = g_sGuard3.m_cLocation.Y;
        if (rMap.Grid[j][i - 1] != '|')
        {
            if (rMap.Grid[j][i - 1] != '#')
            {
                if (rMap.Grid[j][i - 1] != '-')
                {
                    if (rMap.Grid[j][i - 1] != '_')
                    {
                        if (rMap.Grid[j][i - 1] != (char)12)
                        {
                            if (rMap.Grid[j][i - 1] != 'E')
                            {
                                g_sGuard3.m_cLocation.X--;
                            }
                        }
                    }
                }
            }
        }


    }
    if (g_sGuard3.xRight == true)
    {
        int i = g_sGuard3.m_cLocation.X;
        int j = g_sGuard3.m_cLocation.Y;
        if (rMap.Grid[j][i + 1] != '|')
        {
            if (rMap.Grid[j][i + 1] != '#')
            {
                if (rMap.Grid[j][i + 1] != '-')
                {
                    if (rMap.Grid[j][i + 1] != '_')
                    {
                        if (rMap.Grid[j][i + 1] != (char)12)
                        {
                            if (rMap.Grid[j][i + 1] != 'E')
                            {
                                g_sGuard3.m_cLocation.X++;
                            }
                        }
                    }
                }
            }
        }

    }
    if (g_sGuard3.xUp == true)
    {
        int i = g_sGuard3.m_cLocation.X;
        int j = g_sGuard3.m_cLocation.Y;
        if (rMap.Grid[j - 1][i] != '|')
        {
            if (rMap.Grid[j - 1][i] != '#')
            {
                if (rMap.Grid[j - 1][i] != '-')
                {
                    if (rMap.Grid[j - 1][i] != '_')
                    {
                        if (rMap.Grid[j - 1][i] != (char)12)
                        {
                            if (rMap.Grid[j - 1][i] != 'E')
                            {
                                g_sGuard3.m_cLocation.Y--;
                            }
                        }
                    }
                }
            }
        }

    }
    if (g_sGuard3.xDown == true)
    {
        int i = g_sGuard3.m_cLocation.X;
        int j = g_sGuard3.m_cLocation.Y;
        if (rMap.Grid[j + 1][i] != '|')
        {
            if (rMap.Grid[j + 1][i] != '#')
            {
                if (rMap.Grid[j + 1][i] != '-')
                {
                    if (rMap.Grid[j + 1][i] != '_')
                    {
                        if (rMap.Grid[j + 1][i] != (char)12)
                        {
                            if (rMap.Grid[j + 1][i] != 'E')
                            {
                                g_sGuard3.m_cLocation.Y++;
                            }
                        }
                    }
                }
            }
        }
    }
    if ((g_sChar.m_cLocation.Y + 1 == g_sGuard.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sGuard.m_cLocation.X) || (g_sChar.m_cLocation.Y - 1 == g_sGuard2.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sGuard.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sGuard.m_cLocation.Y) && (g_sChar.m_cLocation.X + 1 == g_sGuard.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sGuard.m_cLocation.Y) && (g_sChar.m_cLocation.X - 1 == g_sGuard.m_cLocation.X))
    {
        g_sGuard.fightGuard = true;
        g_eGameState = S_BattleScreen;
        g_sChar.m_cLocation.Y = 5;
        g_sChar.m_cLocation.X = 37;
    }
    if ((g_sChar.m_cLocation.Y + 1 == g_sGuard2.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sGuard2.m_cLocation.X) || (g_sChar.m_cLocation.Y - 1 == g_sGuard2.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sGuard2.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sGuard2.m_cLocation.Y) && (g_sChar.m_cLocation.X + 1 == g_sGuard2.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sGuard2.m_cLocation.Y) && (g_sChar.m_cLocation.X - 1 == g_sGuard2.m_cLocation.X))
    {
        g_sGuard2.fightGuard = true;
        g_sChar.count = 0;
        g_eGameState = S_BattleScreen;
        g_sChar.m_cLocation.Y = 13;
        g_sChar.m_cLocation.X = 35;
    }
    if ((g_sChar.m_cLocation.Y + 1 == g_sGuard3.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sGuard3.m_cLocation.X) || (g_sChar.m_cLocation.Y - 1 == g_sGuard3.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sGuard3.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sGuard3.m_cLocation.Y) && (g_sChar.m_cLocation.X + 1 == g_sGuard3.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sGuard3.m_cLocation.Y) && (g_sChar.m_cLocation.X - 1 == g_sGuard3.m_cLocation.X))
    {
        g_sGuard3.fightGuard = true;
        g_sChar.count = 0;
        g_eGameState = S_BattleScreen;
        g_sChar.m_cLocation.Y = 21;
        g_sChar.m_cLocation.X = 50;
    }
    COORD c;
    int BoxItemChance = 0;
    BoxItemChance = (rand() % 5) + 1;
    if (BoxItemChance == 0)
    {
        if (PlayerInv.pickup(item4))
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Item Added", 100);
            item4->setItemName("Bread");
        }
        else {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Not enough space.", 100);
        }
        c.X = 5;
        c.Y = 27;
        g_Console.writeToBuffer(c, PlayerInv.checkInventory("Bread"), 100);

        if (PlayerInv.pickup(item5))
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Item Added", 100);
            item5->setItemName("Burger");
        }
        else
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Not enough space.", 100);
        }
        c.X = 5;
        c.Y = 27;
        g_Console.writeToBuffer(c, PlayerInv.checkInventory("Burger"), 100);

        if (PlayerInv.pickup(item6))
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Item Added", 100);
            item6->setItemName("Taco");
        }
        else
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Not enough space.", 100);
        }
        c.X = 5;
        c.Y = 27;
        g_Console.writeToBuffer(c, PlayerInv.checkInventory("Taco"), 100);

        if (PlayerInv.pickup(item7))
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Item Added", 100);
            item7->setItemName("Cake");
        }
        else
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Not enough space.", 100);
        }
        c.X = 5;
        c.Y = 27;
        g_Console.writeToBuffer(c, PlayerInv.checkInventory("Cake"), 100);

        if (PlayerInv.pickup(item8))
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Item Added", 100);
            item8->setItemName("Medicine");
        }

        else
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Not enough space.", 100);
        }
        c.X = 5;
        c.Y = 27;
        g_Console.writeToBuffer(c, PlayerInv.checkInventory("Medicine"), 100);
    }

}

void renderMap_GuardStealth()
{
    g_sGuard4.m_cLocation.X = 22;
    g_sGuard4.m_cLocation.Y = 3;

    g_sGuard5.m_cLocation.X = 59;
    g_sGuard5.m_cLocation.Y = 3;

    g_sGuard6.m_cLocation.X = 74;
    g_sGuard6.m_cLocation.Y = 12;

    g_sGuard7.m_cLocation.X = 59;
    g_sGuard7.m_cLocation.Y = 20;

    g_Console.writeToBuffer(g_sGuard4.m_cLocation, (char)12, 0x04);
    g_Console.writeToBuffer(g_sGuard5.m_cLocation, (char)12, 0x04);
    g_Console.writeToBuffer(g_sGuard6.m_cLocation, (char)12, 0x04);
    g_Console.writeToBuffer(g_sGuard7.m_cLocation, (char)12, 0x04);
}

void update_GuardDirection()
{
    processUserInput(); 
    moveCharacter();
    if (GuardDetectTime >= 4 && GuardDetectTime < 8)
    {
        g_sChar.faceLeft = false;
        g_sChar.faceRight = true;
    }
    if (GuardDetectTime > 8)
    {
        g_sGuard4.startTimer = true;
    }
}

void renderMap_GuardDirection()
{
    COORD c, d;
    int i; int j;
    if (g_sGuard4.startTimer == true)
    {
        g_sChar.faceLeft = true;
        g_sChar.faceRight = false;
        GuardDetectTime = 0;
        g_sGuard4.startTimer = false;
    }
    if (g_sChar.faceLeft == true)
    { 
        Cutscene.drawgrid(g_Console, 21, 3, '>');
        Cutscene.drawgrid(g_Console, 60, 3, '<');
        Cutscene.drawgrid(g_Console, 74, 11, 'V');
        Cutscene.drawgrid(g_Console, 58, 20, '>');
        Cutscene.cleargrid(g_Console, 23, 3);
        Cutscene.cleargrid(g_Console, 58, 3);
        Cutscene.cleargrid(g_Console, 74, 13);
        Cutscene.cleargrid(g_Console, 60, 20);

        //Guard 4 Detect Left
        for (j = 2; j < 5; j++)
        {
            for (i = 2; i < 23; i++)
            {
                if (g_sChar.m_cLocation.X == i && g_sChar.m_cLocation.Y == j)
                {
                    g_sChar.m_cLocation.X = 5;
                    g_sChar.m_cLocation.Y = 20;
                }
            }
        }
        //Guard 5 Detect Right
        for (j = 2; j < 5; j++)
        {
            for (i = 59; i < 78; i++)
            {
                if (g_sChar.m_cLocation.X == i && g_sChar.m_cLocation.Y == j)
                {
                    g_sChar.m_cLocation.X = 5;
                    g_sChar.m_cLocation.Y = 20;
                }
            }
        }
        //Guard 6 Detect Up
        for (j = 2; j < 13; j++)
        {
            for (i = 70; i < 78; i++)
            {
                if (g_sChar.m_cLocation.X == i && g_sChar.m_cLocation.Y == j)
                {
                    g_sChar.m_cLocation.X = 5;
                    g_sChar.m_cLocation.Y = 20;
                }
            }
        }
        //Guard 7 Detect Left
        for (j = 19; j < 23; j++)
        {
            for (i = 17; i < 60; i++)
            {
                if (g_sChar.m_cLocation.X == i && g_sChar.m_cLocation.Y == j)
                {
                    g_sChar.m_cLocation.X = 5;
                    g_sChar.m_cLocation.Y = 20;
                }
            }
        }
    }
    
    if (g_sChar.faceRight == true)
    {
        Cutscene.drawgrid(g_Console, 23, 3, '<');
        Cutscene.drawgrid(g_Console, 58, 3, '>');
        Cutscene.drawgrid(g_Console, 74, 13, '^');
        Cutscene.drawgrid(g_Console, 60, 20, '<');
        
        Cutscene.cleargrid(g_Console, 21, 3);
        Cutscene.cleargrid(g_Console, 60, 3);
        Cutscene.cleargrid(g_Console, 74, 11);
        Cutscene.cleargrid(g_Console, 58, 20);

        //Guard 4 & 5 Detect Right
        for (j = 2; j < 5; j++)
        {
            for (i = 22; i < 60; i++)
            {
                if (g_sChar.m_cLocation.X == i && g_sChar.m_cLocation.Y == j)
                {
                    g_sChar.m_cLocation.X = 5;
                    g_sChar.m_cLocation.Y = 20;
                }
            }
        }
        //Guard 6 Detect Down
        for (j = 12; j < 23; j++)
        {
            for (i = 70; i < 78; i++)
            {
                if (g_sChar.m_cLocation.X == i && g_sChar.m_cLocation.Y == j)
                {
                    g_sChar.m_cLocation.X = 5;
                    g_sChar.m_cLocation.Y = 20;
                }
            }
        }
        //Guard 7 Detect Right
        for (j = 19; j < 23; j++)
        {
            for (i = 59; i < 78; i++)
            {
                if (g_sChar.m_cLocation.X == i && g_sChar.m_cLocation.Y == j)
                {
                    g_sChar.m_cLocation.X = 5;
                    g_sChar.m_cLocation.Y = 20;
                }
            }
        }
    }
}

void renderMap_DS2()
{

    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.dungeon_stealth2(g_Console);
    renderCharacter();  // renders the character into the buffer
    renderMap_GuardStealth();

    renderMap_GuardDirection();
    //back to DS1
    if (g_sChar.m_cLocation.Y == 22 && (g_sChar.m_cLocation.X == 2 || g_sChar.m_cLocation.X == 3 || g_sChar.m_cLocation.X == 4 || g_sChar.m_cLocation.X == 5 || g_sChar.m_cLocation.X == 6 || g_sChar.m_cLocation.X == 7 || g_sChar.m_cLocation.X == 8))
    {
        g_dPathTime = 0.0;
        g_eGameState = S_Dungeon_Stealth_1;
        g_sChar.m_cLocation.X = 14;
        g_sChar.m_cLocation.Y = 21;
    }
    //To DS3
    if (g_sChar.m_cLocation.Y == 18 && (g_sChar.m_cLocation.X == 17 || g_sChar.m_cLocation.X == 18 || g_sChar.m_cLocation.X == 19 || g_sChar.m_cLocation.X == 20 || g_sChar.m_cLocation.X == 21 || g_sChar.m_cLocation.X == 22 || g_sChar.m_cLocation.X == 23 || g_sChar.m_cLocation.X == 24 || g_sChar.m_cLocation.X == 25 || g_sChar.m_cLocation.X == 26))
    {
        g_dDungeonStealth3Time = 0.0;
        g_eGameState = S_Dungeon_Stealth_3;
        g_sChar.m_cLocation.X = 5;
        g_sChar.m_cLocation.Y = 21;
    }
}

void renderMap_DS3()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.dungeon_stealth3(g_Console);
    renderCharacter();  // renders the character into the buffer
    //back to DS2
    if (g_sChar.m_cLocation.Y == 22 && (g_sChar.m_cLocation.X == 2 || g_sChar.m_cLocation.X == 3 || g_sChar.m_cLocation.X == 4 || g_sChar.m_cLocation.X == 5 || g_sChar.m_cLocation.X == 6 || g_sChar.m_cLocation.X == 7))
    {
        g_dPathTime = 0.0;
        g_eGameState = S_Dungeon_Stealth_2;
        g_sChar.m_cLocation.X = 21;
        g_sChar.m_cLocation.Y = 19;
    }
    //trigger animation
    if ((g_sChar.m_cLocation.Y == 21 || g_sChar.m_cLocation.Y == 22) && g_sChar.m_cLocation.X == 57)
    {
        g_dDungeonTime = 0.0;
        //must do count here, must get character to move after animation
        g_eGameState = S_Dungeon_Stealth3_Animation;
        g_sChar.m_cLocation.X = 60;
        g_sChar.m_cLocation.Y = 22;
    }
    if (g_sChar.m_cLocation.Y == 3 && g_sChar.m_cLocation.X == 5)
    {
        //ask if user wants to enter battle area
        g_eGameState = S_Boss_Room_Animation;
        g_sChar.m_cLocation.X = 40;
        g_sChar.m_cLocation.Y = 21;
    }
    if (g_sChar.m_cLocation.Y == 2 && (g_sChar.m_cLocation.X == 60 || g_sChar.m_cLocation.X == 61 || g_sChar.m_cLocation.X == 62 || g_sChar.m_cLocation.X == 63 || g_sChar.m_cLocation.X == 64 || g_sChar.m_cLocation.X == 65 || g_sChar.m_cLocation.X == 66 || g_sChar.m_cLocation.X == 67 || g_sChar.m_cLocation.X == 68 || g_sChar.m_cLocation.X == 69 || g_sChar.m_cLocation.X == 70 || g_sChar.m_cLocation.X == 71 || g_sChar.m_cLocation.X == 72 || g_sChar.m_cLocation.X == 73 || g_sChar.m_cLocation.X == 74 || g_sChar.m_cLocation.X == 75 || g_sChar.m_cLocation.X == 76 || g_sChar.m_cLocation.X == 77))
    {
        g_dPathTime = 0.0;
        g_eGameState = S_Protest_Area;
        g_sChar.m_cLocation.X = 63;
        g_sChar.m_cLocation.Y = 4;
    }
}

void renderMap_Boss_Battle_Room()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.boss_room(g_Console);
    renderCharacter();  // renders the character into the buffer
}

void RenderBattleScreen()
{
    COORD c;
    
    int UpdateDmg = 0;
    int UpdateHealth = 0;
    if (g_sTutEnemy.GetH() == 0 || g_sMutantWasp.GetH() == 0)
    {

        if (PlayerInv.pickup(item1))
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Item Added", 100);
            item1->setItemName("Stinger");
        }
        else {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Not enough space.", 100);
        }
        c.X = 5;
        c.Y = 27;
        g_Console.writeToBuffer(c, PlayerInv.checkInventory("Stinger"), 100);
    }
    else if (g_sPig.GetH() <= 0)
    {
        if (PlayerInv.pickup(item2))
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Item Added", 100);
            item2->setItemName("Raw Meat");
        }
        else {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Not enough space.", 100);
        }
        c.X = 5;
        c.Y = 27;
        g_Console.writeToBuffer(c, PlayerInv.checkInventory("Raw Meat"), 100);
    }
       
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    c.X = 11;
    c.Y = 0;
    string str_charhealth = to_string(g_sChar.GetH());
    g_Console.writeToBuffer(c, "Your Health: " + str_charhealth, 0x0A, 100);

    // fight guard 1
    if (g_sGuard.fightGuard == true)
    {
        Sprites.drawGuard(g_Console, 0);
        //rMap.pig(g_Console);
        //rMap.Battle_Wasp(g_Console);
        //rMap.Battle_Raymond(g_Console);
        //renderCharacter();  // renders the character into the buffer

        c.X = 53;
        c.Y = 0;
        string str_guardhealth = to_string(g_sGuard.GetH());
        g_Console.writeToBuffer(c, "Enemy Health: " + str_guardhealth, 0x0A, 100);
        if (g_sChar.startTimer == true)
        {
            if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 19)) && ((g_mouseEvent.mousePosition.X == 58) || (g_mouseEvent.mousePosition.X == 59) || (g_mouseEvent.mousePosition.X == 60) || (g_mouseEvent.mousePosition.X == 61) || (g_mouseEvent.mousePosition.X == 62) || (g_mouseEvent.mousePosition.X == 63) || (g_mouseEvent.mousePosition.X == 64))))
            {
                int randHit = rand() % 4 + 1;
                if (randHit == 1 || randHit == 2) // player gets hit
                {
                    int charhealth = g_sChar.GetH() - g_sGuard.GetD(); // get player health
                    string str_charhealth = to_string(charhealth);

                    g_sChar.SetH(charhealth); // set player health to new health

                    g_sChar.showEnemyDMG = true;
                    enemyDMGTime = 0.0;

                }
                if (randHit > 1) // player gets hit
                {
                    int guardhealth = g_sGuard.GetH() - g_sChar.GetD(); // get enemy health
                    //string str_guardhealth = to_string(guardhealth);

                    g_sGuard.SetH(guardhealth); // set enemy health to new health
                    g_sChar.showPlayerDMG = true;

                }

                /*
                if (g_sGuard.GetH() <= 0)
                {
                    Item GuardArmor;

                    GuardArmor.setItemName("Guard Armor");

                    Item* item3 = new Item;
                    if (PlayerInv.pickup(item3))
                    {
                        c.X = 5;
                        c.Y = 26;
                        g_Console.writeToBuffer(c, "Item Added", 100);
                    }
                    else {
                        c.X = 5;
                        c.Y = 26;
                        g_Console.writeToBuffer(c, "Not enough space.", 100);
                    }

                    c.X = 5;
                    c.Y = 27;
                    g_Console.writeToBuffer(c, PlayerInv.checkInventory("Guard Armor"), 100);
                }
                */
                startTime = 0.0;
                g_sChar.resetTimer = true;
                g_sChar.startTimer = false;
                playerDMGTime = 0.0;
                g_sChar.count = 1;

            }
        }
        if (g_sChar.count == 1)
        {
            if (g_sGuard.GetH() <= 0)
            {
                g_sGuard.enemyDie = true;
                g_sGuard.fightGuard = false;
                g_eGameState = S_Dungeon_Stealth_1; // if player kills guard
                g_sChar.unlockDoorDS1 = true;
            }
        }

        if (g_sChar.showPlayerDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 25;
            string str_charDMG = to_string(g_sChar.GetD());

            g_Console.writeToBuffer(c, "You Dealt: " + str_charDMG, 0x0F, 100);

        }
        if (g_sChar.showEnemyDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 26;
            string str_guardDMG = to_string(g_sGuard.GetD());

            g_Console.writeToBuffer(c, "Enemy Dealt: " + str_guardDMG, 0x0F, 100);
        }
    }
    if (g_sGuard2.fightGuard == true)
    {
        Sprites.drawGuard(g_Console, 0);
        //rMap.pig(g_Console);
        //rMap.Battle_Wasp(g_Console);
        //rMap.Battle_Raymond(g_Console);
        //renderCharacter();  // renders the character into the buffer

        c.X = 53;
        c.Y = 0;
        string str_guardhealth = to_string(g_sGuard2.GetH());
        g_Console.writeToBuffer(c, "Enemy Health: " + str_guardhealth, 0x0A, 100);
        if (g_sChar.startTimer == true)
        {
            if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 19)) && ((g_mouseEvent.mousePosition.X == 58) || (g_mouseEvent.mousePosition.X == 59) || (g_mouseEvent.mousePosition.X == 60) || (g_mouseEvent.mousePosition.X == 61) || (g_mouseEvent.mousePosition.X == 62) || (g_mouseEvent.mousePosition.X == 63) || (g_mouseEvent.mousePosition.X == 64))))
            {
                int randHit = rand() % 2 + 1;
                if (randHit == 1) // player gets hit
                {
                    int charhealth = g_sChar.GetH() - g_sGuard2.GetD(); // get player health
                    string str_charhealth = to_string(charhealth);

                    g_sChar.SetH(charhealth); // set player health to new health

                    g_sChar.showEnemyDMG = true;
                    enemyDMGTime = 0.0;

                }

                if (randHit > 1) // player gets hit
                {
                    int guardhealth = g_sGuard2.GetH() - g_sChar.GetD(); // get enemy health
                   //string str_guardhealth = to_string(guardhealth);

                    g_sGuard2.SetH(guardhealth);
                    g_sChar.showPlayerDMG = true;


                }
                /*
                if (g_sGuard2.GetH() <= 0)
                {
                    Item GuardArmor;

                    GuardArmor.setItemName("Guard Armor");

                    Item* item3 = new Item;
                    if (PlayerInv.pickup(item3))
                    {
                        c.X = 5;
                        c.Y = 26;
                        g_Console.writeToBuffer(c, "Item Added", 100);
                    }
                    else {
                        c.X = 5;
                        c.Y = 26;
                        g_Console.writeToBuffer(c, "Not enough space.", 100);
                    }

                    c.X = 5;
                    c.Y = 27;
                    g_Console.writeToBuffer(c, PlayerInv.checkInventory("Guard Armor"), 100);
                }
                */
                startTime = 0.0;
                g_sChar.resetTimer = true;
                g_sChar.startTimer = false;
                playerDMGTime = 0.0;
                g_sChar.count = 1;

            }
        }
        if (g_sChar.count == 1)
        {
            if (g_sGuard2.GetH() <= 0)
            {
                g_sGuard2.enemyDie = true;
                g_sGuard2.fightGuard = false;
                g_eGameState = S_Dungeon_Stealth_1; // if player kills guard
                g_sChar.unlockDoorDS1 = true;
            }
        }

        if (g_sChar.showPlayerDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 25;
            string str_charDMG = to_string(g_sChar.GetD());

            g_Console.writeToBuffer(c, "You Dealt: " + str_charDMG, 0x0F, 100);

        }
        if (g_sChar.showEnemyDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 26;
            string str_guardDMG = to_string(g_sGuard2.GetD());

            g_Console.writeToBuffer(c, "Enemy Dealt: " + str_guardDMG, 0x0F, 100);
        }
    }
    if (g_sGuard3.fightGuard == true)
    {
        Sprites.drawGuard(g_Console, 0);
        //rMap.pig(g_Console);
        //rMap.Battle_Wasp(g_Console);
        //rMap.Battle_Raymond(g_Console);
        //renderCharacter();  // renders the character into the buffer

        c.X = 53;
        c.Y = 0;
        string str_guardhealth = to_string(g_sGuard3.GetH());
        g_Console.writeToBuffer(c, "Enemy Health: " + str_guardhealth, 0x0A, 100);
        if (g_sChar.startTimer == true)
        {
            if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 19)) && ((g_mouseEvent.mousePosition.X == 58) || (g_mouseEvent.mousePosition.X == 59) || (g_mouseEvent.mousePosition.X == 60) || (g_mouseEvent.mousePosition.X == 61) || (g_mouseEvent.mousePosition.X == 62) || (g_mouseEvent.mousePosition.X == 63) || (g_mouseEvent.mousePosition.X == 64))))
            {
                int randHit = rand() % 2 + 1;
                if (randHit == 1) // player gets hit
                {
                    int charhealth = g_sChar.GetH() - g_sGuard3.GetD(); // get player health
                    string str_charhealth = to_string(charhealth);

                    g_sChar.SetH(charhealth); // set player health to new health

                    g_sChar.showEnemyDMG = true;
                    enemyDMGTime = 0.0;

                }
                if (randHit > 1) // player gets hit
                {
                    int guardhealth = g_sGuard3.GetH() - g_sChar.GetD(); // get enemy health
                    //string str_guardhealth = to_string(guardhealth);

                    g_sGuard3.SetH(guardhealth); // set enemy health to new health
                    g_sChar.showPlayerDMG = true;

                }
                /*
                if (g_sGuard2.GetH() <= 0)
                {
                    Item GuardArmor;

                    GuardArmor.setItemName("Guard Armor");

                    Item* item3 = new Item;
                    if (PlayerInv.pickup(item3))
                    {
                        c.X = 5;
                        c.Y = 26;
                        g_Console.writeToBuffer(c, "Item Added", 100);
                    }
                    else {
                        c.X = 5;
                        c.Y = 26;
                        g_Console.writeToBuffer(c, "Not enough space.", 100);
                    }

                    c.X = 5;
                    c.Y = 27;
                    g_Console.writeToBuffer(c, PlayerInv.checkInventory("Guard Armor"), 100);
                }
                */
                startTime = 0.0;
                g_sChar.resetTimer = true;
                g_sChar.startTimer = false;
                playerDMGTime = 0.0;
                g_sChar.count = 1;

            }
        }
        if (g_sChar.count == 1)
        {
            if (g_sGuard3.GetH() <= 0)
            {
                g_sGuard3.enemyDie = true;
                g_sGuard3.fightGuard = false;
                g_eGameState = S_Dungeon_Stealth_1; // if player kills guard
                g_sChar.unlockDoorDS1 = true;
            }
        }

        if (g_sChar.showPlayerDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 25;
            string str_charDMG = to_string(g_sChar.GetD());

            g_Console.writeToBuffer(c, "You Dealt: " + str_charDMG, 0x0F, 100);

        }
        if (g_sChar.showEnemyDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 26;
            string str_guardDMG = to_string(g_sGuard3.GetD());

            g_Console.writeToBuffer(c, "Enemy Dealt: " + str_guardDMG, 0x0F, 100);
        }
    }
    if (g_sChar.GetH() <= 0)
    {
        g_eGameState = S_Game_Over; // if guard kills player
    }
    /*
    if (g_sChar.InvenActive == true)
    {
        rMap.Road2(g_Console, 3, 24, 74);
        rMap.Road(g_Console, 2, 25, 5);
        rMap.Road2(g_Console, 3, 29, 75);
        rMap.Road(g_Console, 77, 25, 5);
        c.X = 13;
        c.Y = 26;
        g_Console.writeToBuffer(c, "o Raw Meat" + PlayerInv.checkInventory("Raw Meat"), 0x0F, 100);
        c.X = 13;
        c.Y = 28;
        g_Console.writeToBuffer(c, "o Stinger" + PlayerInv.checkInventory("Stinger"), 0x0F, 100);
        c.X = 28;
        c.Y = 26;
        g_Console.writeToBuffer(c, "o Guard Armor" + PlayerInv.checkInventory("Guard Armor"), 0x0F, 100);
        c.X = 28;
        c.Y = 28;
        g_Console.writeToBuffer(c, "o Bread" + PlayerInv.checkInventory("Bread"), 0x0F, 100);
        c.X = 46;
        c.Y = 26;
        g_Console.writeToBuffer(c, "o Burger" + PlayerInv.checkInventory("Burger"), 0x0F, 100);
        c.X = 46;
        c.Y = 28;
        g_Console.writeToBuffer(c, "o Taco" + PlayerInv.checkInventory("Taco"), 0x0F, 100);
        c.X = 61;
        c.Y = 26;
        g_Console.writeToBuffer(c, "o Cake" + PlayerInv.checkInventory("Cake"), 0x0F, 100);
        c.X = 61;
        c.Y = 28;
        g_Console.writeToBuffer(c, "o Medicine" + PlayerInv.checkInventory("Medicine"), 0x0F, 100);
    }
>>>>>>> ab9f16db710956d9ae03c67215e62b86f3d942f5
    //change g_eGameState to inventory
    if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 19)) && ((g_mouseEvent.mousePosition.X == 15) || (g_mouseEvent.mousePosition.X == 16) || (g_mouseEvent.mousePosition.X == 17) || (g_mouseEvent.mousePosition.X == 18) || (g_mouseEvent.mousePosition.X == 19) || (g_mouseEvent.mousePosition.X == 20) || (g_mouseEvent.mousePosition.X == 21) || (g_mouseEvent.mousePosition.X == 22) || (g_mouseEvent.mousePosition.X == 23) || (g_mouseEvent.mousePosition.X == 24) || (g_mouseEvent.mousePosition.X == 25))))
    {
        g_sChar.InvenActive = true;
        g_sChar.itemActive = true;
        
        /*if (PlayerInv.Consumed(item1))
        {
            c.X = 8;
            c.Y = 27;
            g_Console.writeToBuffer(c, "item 1 was used.", 100);
            UpdateDmg = g_sChar.GetD() + 5;
            g_sChar.SetD(UpdateDmg);
        }
        
        else
        {
            c.X = 8;
            c.Y = 27;
            g_Console.writeToBuffer(c, "item 1 was not used.", 100);
        }
        c.X = 5;
        c.Y = 27;
        g_Console.writeToBuffer(c, PlayerInv.checkInventory("Stinger"), 100);

        if (PlayerInv.Consumed(item2))
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Item used.", 100);
            UpdateHealth = g_sChar.GetH() + 5;
            g_sChar.SetH(UpdateHealth);
        }
        else
        {
            g_Console.writeToBuffer(c, "Item was not used.", 100);
        }
        c.X = 5;
        c.Y = 27;
        g_Console.writeToBuffer(c, PlayerInv.checkInventory("Raw Meat"), 100);

        if (PlayerInv.Consumed(item3))
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Item used.", 100);
            UpdateDmg = g_sChar.GetD() + 10;
            g_sChar.SetD(UpdateDmg);
        }
        else
        {
            g_Console.writeToBuffer(c, "Item was not used.", 100);
        }
        c.X = 5;
        c.Y = 27;
        g_Console.writeToBuffer(c, PlayerInv.checkInventory("Guard Armor"), 100);

        if (PlayerInv.Consumed(item4))
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Item used.", 100);
            UpdateHealth = g_sChar.GetH() + 10;
            g_sChar.SetD(UpdateHealth);
        }
        else
        {
            g_Console.writeToBuffer(c, "Item was not used.", 100);
        }
        c.X = 5;
        c.Y = 27;
        g_Console.writeToBuffer(c, PlayerInv.checkInventory("Bread"), 100);

        if (PlayerInv.Consumed(item5))
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Item used.", 100);
            UpdateHealth = g_sChar.GetH() + 25;
            g_sChar.SetD(UpdateHealth);
        }
        else
        {
            g_Console.writeToBuffer(c, "Item was not used.", 100);
        }
        c.X = 5;
        c.Y = 27;
        g_Console.writeToBuffer(c, PlayerInv.checkInventory("Burger"), 100);

        if (PlayerInv.Consumed(item6))
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Item used.", 100);
            UpdateHealth = g_sChar.GetD() + 25;
            g_sChar.SetD(UpdateHealth);
        }
        else
        {
            g_Console.writeToBuffer(c, "Item was not used.", 100);
        }
        c.X = 5;
        c.Y = 27;
        g_Console.writeToBuffer(c, PlayerInv.checkInventory("Taco"), 100);

        if (PlayerInv.Consumed(item7))
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Item used.", 100);
            g_sChar.SetH(50);
        }
        else
        {
            g_Console.writeToBuffer(c, "Item was not used.", 100);
        }
        c.X = 5;
        c.Y = 27;
        g_Console.writeToBuffer(c, PlayerInv.checkInventory("Cake"), 100);

        if (PlayerInv.Consumed(item8))
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Item used.", 100);
            //Poison status
        }
        else
        {
            g_Console.writeToBuffer(c, "Item was not used.", 100);
        }
        c.X = 5;
        c.Y = 27;
        g_Console.writeToBuffer(c, PlayerInv.checkInventory("Medicine"), 100);

        //g_eGameState = S_Townsquare;
    }
    */
    if (g_sChar.itemActive == true)
    {
        if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 26)) && ((g_mouseEvent.mousePosition.X == 13))))
        {
            if (g_sInven.startTimer == true)
            {
                c.X = 5;
                c.Y = 25;
                g_Console.writeToBuffer(c, "Raw Meat was used.", 0x0F, 100);
            }
            UpdateHealth = g_sChar.GetH() + 5;
            if (g_sChar.GetH() == 50)
            {
                if (g_sInven.startTimer == true)
                {
                    c.X = 5;
                    c.Y = 25;
                    g_Console.writeToBuffer(c, "Raw Meat was not used.", 0x0F, 100);
                }
            }
            g_sChar.SetH(UpdateHealth);
            if (UpdateHealth > 50)
            {
                g_sChar.SetH(50);
                if (g_sInven.startTimer == true)
                {
                    c.X = 5;
                    c.Y = 25;
                    g_Console.writeToBuffer(c, "Raw Meat was not used.", 0x0F, 100);
                }
            }
            InvenTime = 0.0;
            g_sInven.startTimer = false;
            g_sChar.InvenActive = false;
            g_sChar.itemActive = false;
        }
        if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 28)) && ((g_mouseEvent.mousePosition.X == 13))))
        {
            g_sInven.startTimer = true;
            c.X = 5;
            c.Y = 25;
            g_Console.writeToBuffer(c, "Stinger was used.", 0x0F, 100);
            UpdateDmg = g_sChar.GetD() + 5;
            g_sChar.SetD(UpdateDmg);
            g_sChar.InvenActive = false;
            g_sChar.itemActive = false;
        }
        if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 26)) && ((g_mouseEvent.mousePosition.X == 28))))
        {
            g_sInven.startTimer = true;
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Guard Armor was used.", 100);
            UpdateDmg = g_sChar.GetD() + 10;
            g_sChar.SetD(UpdateDmg);
            g_sChar.InvenActive = false;
            g_sChar.itemActive = false;
        }
        if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 28)) && ((g_mouseEvent.mousePosition.X == 28))))
        {
            g_sInven.startTimer = true;
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Bread was used.", 100);
            UpdateHealth = g_sChar.GetH() + 10;
            if (g_sChar.GetH() == 50)
            {
                g_Console.writeToBuffer(c, "Bread was not used.", 0x0F, 100);
            }
            g_sChar.SetH(UpdateHealth);
            if (UpdateHealth > 50)
            {
                g_sChar.SetH(50);
                g_Console.writeToBuffer(c, "Bread was not used.", 0x0F, 100);
            }
            g_sChar.InvenActive = false;
            g_sChar.itemActive = false;
        }
        if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 26)) && ((g_mouseEvent.mousePosition.X == 46))))
        {
            g_sInven.startTimer = true;
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Burger was used.", 100);
            UpdateHealth = g_sChar.GetH() + 25;
            if (g_sChar.GetH() == 50)
            {
                g_Console.writeToBuffer(c, "Burger was not used.", 0x0F, 100);
            }
            g_sChar.SetH(UpdateHealth);
            if (UpdateHealth > 50)
            {
                g_sChar.SetH(50);
                g_Console.writeToBuffer(c, "Burger was not used.", 0x0F, 100);
            }
            g_sChar.SetH(UpdateHealth);
            g_sChar.InvenActive = false;
            g_sChar.itemActive = false;
        }
        if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 28)) && ((g_mouseEvent.mousePosition.X == 46))))
        {
            g_sInven.startTimer = true;
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Taco was used.", 100);
            UpdateHealth = g_sChar.GetH() + 25;
            g_sChar.SetH(UpdateHealth);
            if (g_sChar.GetH() == 50)
            {
                g_Console.writeToBuffer(c, "Taco was not used.", 0x0F, 100);
            }
            g_sChar.SetH(UpdateHealth);
            if (UpdateHealth > 50)
            {
                g_sChar.SetH(50);
                g_Console.writeToBuffer(c, "Taco was not used.", 0x0F, 100);
            }
            g_sChar.InvenActive = false;
            g_sChar.itemActive = false;
        }
        if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 26)) && ((g_mouseEvent.mousePosition.X == 61))))
        {
            g_sInven.startTimer = true;
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Cake was used.", 100);
            g_sChar.SetH(50);
            if (g_sChar.GetH() == 50)
            {
                g_Console.writeToBuffer(c, "Cake was not used.", 0x0F, 100);
            }
            g_sChar.InvenActive = false;
            g_sChar.itemActive = false;
        }
        if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 28)) && ((g_mouseEvent.mousePosition.X == 61))))
        {
            //Poison Status
            g_sChar.InvenActive = false;
            g_sChar.itemActive = false;
        }
    }
    
    // if click on fight
    if (g_sChar.startTimer == true)
    {
        if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 19)) && ((g_mouseEvent.mousePosition.X == 58) || (g_mouseEvent.mousePosition.X == 59) || (g_mouseEvent.mousePosition.X == 60) || (g_mouseEvent.mousePosition.X == 61) || (g_mouseEvent.mousePosition.X == 62) || (g_mouseEvent.mousePosition.X == 63) || (g_mouseEvent.mousePosition.X == 64))))
        {
            int randHit = rand() % 100 + 1;
            if (randHit >= 0 && randHit <= 50) // player gets hit
            {
                int charhealth = g_sChar.GetH() - g_sGuard.GetD(); // get player health
                string str_charhealth = to_string(charhealth);

                g_sChar.SetH(charhealth); // set player health to new health

                g_sChar.showEnemyDMG = true;
                enemyDMGTime = 0.0;

            }

            int guardhealth = g_sGuard.GetH() - g_sChar.GetD(); // get enemy health
            //string str_guardhealth = to_string(guardhealth);


            g_sGuard.SetH(guardhealth); // set enemy health to new health
            if (g_sGuard.GetH() <= 0)
            {
               
                if (PlayerInv.pickup(item3))
                {
                    c.X = 5;
                    c.Y = 27;
                    g_Console.writeToBuffer(c, "Guard Armor Added", 0x0F, 100);
                }
                else 
                {
                    c.X = 5;
                    c.Y = 27;
                    g_Console.writeToBuffer(c, "Not enough space.", 100);
                }

                c.X = 5;
                c.Y = 27;
                g_Console.writeToBuffer(c, PlayerInv.checkInventory("Guard Armor"), 100);
            }

            startTime = 0.0;
            g_sChar.resetTimer = true;
            g_sChar.startTimer = false;
            g_sChar.showPlayerDMG = true;
            playerDMGTime = 0.0;
            g_sChar.count = 1;

        }
    }

    if (g_sChar.GetH() <= 0)
    {
        g_eGameState = S_Game_Over; // if guard kills player
    }
    if (g_sChar.count == 1)
    {
        if (g_sGuard.GetH() <= 0)
        {
            g_eGameState = S_Dungeon_Stealth_1; // if player kills guard
            g_sChar.unlockDoorDS1 = true;
        }
    }

    if (g_sChar.showPlayerDMG == true)
    {
        COORD c;
        c.X = 3;
        c.Y = 25;
        string str_charDMG = to_string(g_sChar.GetD());

        g_Console.writeToBuffer(c, "You Dealt: " + str_charDMG, 0x0F, 100);

    }
    if (g_sChar.showEnemyDMG == true)
    {
        COORD c;
        c.X = 3;
        c.Y = 26;
        string str_guardDMG = to_string(g_sGuard.GetD());

        g_Console.writeToBuffer(c, "Enemy Dealt: " + str_guardDMG, 0x0F, 100);
    }
    /*if (g_sInven.startTimer == true)
    {
        c.X = 40;
        c.Y = 25;
        g_Console.writeToBuffer(c, "Item used.", 100);
        InvenTime = 0.0;
    }*/
}

void UpdateBattleScreen()
{
    processUserInput();
    if ((InvenTime > 2) && (g_sChar.itemActive == true))
    {
        g_sInven.startTimer = false;
        InvenTime = 0;
    }

    if (g_sChar.resetTimer == true)
    {
        if (startTime > 5)
        {
            g_sChar.startTimer = true;
        }
    }

    if ((playerDMGTime > 3) && (g_sChar.showPlayerDMG == true))
    {
        //g_eGameState = S_Townsquare;
        g_sChar.showPlayerDMG = false;
        COORD c;
        c.X = 3;
        c.Y = 25;
        g_Console.writeToBuffer(c, "                                         ", 0x0F, 100);
        playerDMGTime = 0.0;

    }
    if ((enemyDMGTime > 3) && (g_sChar.showEnemyDMG == true))
    {
        g_sChar.showEnemyDMG = false;
        enemyDMGTime = 0.0;
        COORD c;
        c.X = 3;
        c.Y = 26;

        g_Console.writeToBuffer(c, "                                         ", 0x0F, 100);

    }
    
}


void renderCharacter()
{
    // Draw the location of the character
    WORD charColor = 0x04;
    if (g_sChar.m_bActive)
    {
        charColor = 0x0F;
    }
    if (g_sChar.fire)
    {
        COORD c; COORD d; COORD e;
        c.X = 5;
        c.Y = 26;
        d.X = 5;
        d.Y = 27;
        e.X = 5;
        e.Y = 28;
        g_Console.writeToBuffer(c, "Got it!", 0x0F, 100);
        g_Console.writeToBuffer(d, "Press the ENTER key to extinguish the fire!", 0x0F, 100);
        g_Console.writeToBuffer(e, "Ensure that you are close to the fire first.", 0x0F, 100);

        rMap.Animation(g_Console, 40, 7, ' ');
        if (g_skKeyEvent[K_RETURN].keyDown && ((rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] == '_') || (rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] == '_') || (rMap.Grid[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] == '_') || (rMap.Grid[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] == '_')))
        {
            g_sChar.fireOut = true;
            g_dChildrenTime = 0.0;
            g_eGameState = S_Orphanage_Children_Animation;

        }
    }
    if (g_sChar.takenBackpack == true)
    {
        rMap.Animation(g_Console, 33, 22, ' ');
        COORD c; COORD d; COORD e; COORD f;
        d.X = 5;
        d.Y = 26;
        g_Console.writeToBuffer(d, "                                                                                                                                   ", 0x00, 100);
        c.X = 5;
        c.Y = 26;
        g_Console.writeToBuffer(c, "Gotcha!", 0x0F, 100);
        e.X = 5;
        e.Y = 27;
        g_Console.writeToBuffer(e, "Hurry! Get out of here now!", 0x0F, 100);
        f.X = 5;
        f.Y = 28;
        g_Console.writeToBuffer(f, "@ = Unlocked Door", 0x0F, 100);
    }
    g_Console.writeToBuffer(g_sChar.m_cLocation, (char)1, charColor);
}
void renderEnemy()
{
    WORD charColor = 0x0C;
    g_Console.writeToBuffer(g_sGuard.m_cLocation, rMap.Grid[g_sGuard.m_cLocation.Y][g_sGuard.m_cLocation.X] = (char)1, charColor);
    g_Console.writeToBuffer(g_sGuard2.m_cLocation, rMap.Grid[g_sGuard2.m_cLocation.Y][g_sGuard2.m_cLocation.X] = (char)1, charColor);
    g_Console.writeToBuffer(g_sGuard3.m_cLocation, rMap.Grid[g_sGuard3.m_cLocation.Y][g_sGuard3.m_cLocation.X] = (char)1, charColor);
}
void renderFramerate()
{
    COORD c;
    // displays the framerate
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << 1.0 / g_dDeltaTime << "fps";
    c.X = g_Console.getConsoleSize().X - 9;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str());

    // displays the elapsed time
    ss.str("");
    ss << g_dElapsedTime << "secs";
    c.X = 0;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str(), 0x59);
}

// this is an example of how you would use the input events
void renderInputEvents()
{
    // keyboard events
    COORD startPos = { 50, 2 };
    std::ostringstream ss;
    std::string key;
    for (int i = 0; i < K_COUNT; ++i)
    {
        //ss.str("");
        //switch (i)
        //{
        //case K_UP: key = "UP";
        //    break;
        //case K_DOWN: key = "DOWN";
        //    break;
        //case K_LEFT: key = "LEFT";
        //    break;
        //case K_RIGHT: key = "RIGHT";
        //    break;
        //case K_SPACE: key = "SPACE";
        //    break;
        //default: continue;
        //}
        //if (g_skKeyEvent[i].keyDown)
        //    ss << key << " pressed";
        //else if (g_skKeyEvent[i].keyReleased)
        //    ss << key << " released";
        //else
        //    ss << key << " not pressed";

        COORD c = { startPos.X, startPos.Y + i };
        g_Console.writeToBuffer(c, ss.str(), 0x17);
    }

    // mouse events    
    ss.str("");
    ss << "Mouse position (" << g_mouseEvent.mousePosition.X << ", " << g_mouseEvent.mousePosition.Y << ")";
    g_Console.writeToBuffer(g_mouseEvent.mousePosition, ss.str(), 0x59);
    ss.str("");
    switch (g_mouseEvent.eventFlags)
    {
    case 0:
        if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED)
        {
            ss.str("Left Button Pressed");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 1, ss.str(), 0x59);
        }
        else if (g_mouseEvent.buttonState == RIGHTMOST_BUTTON_PRESSED)
        {
            ss.str("Right Button Pressed");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 2, ss.str(), 0x59);
        }
        else
        {
            ss.str("Some Button Pressed");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 3, ss.str(), 0x59);
        }
        break;
    case DOUBLE_CLICK:
        ss.str("Double Clicked");
        g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 4, ss.str(), 0x59);
        break;
    case MOUSE_WHEELED:
        if (g_mouseEvent.buttonState & 0xFF000000)
            ss.str("Mouse wheeled down");
        else
            ss.str("Mouse wheeled up");
        g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 5, ss.str(), 0x59);
        break;
    default:
        break;
    }
}

void render_Main_Menu()
{
    COORD c; COORD d;

    //Print R (ROBERT)
    int i;
    int j;
    j = 1;
    for (int i = 7; i < 15; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 6;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 9;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 10;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 14;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 5;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 13;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');


    j = 3;
    for (int i = 9; i < 13; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 4;
    c.Y = 4;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 9;
    c.Y = 4;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '\\');


    c.X = 3;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 6;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 7;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '\\');

    c.X = 10;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '\\');

    c.X = 2;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 3;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 5;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 8;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '\\');

    c.X = 9;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 10;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 11;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '\\');

    //Print O
    j = 1;
    for (int i = 18; i < 25; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    /*for (int j = 2; j < 7; j++)
    {
        for (int i = 17; i > 12; i--)
        {
            Grid[i][j] = '/';
            break;
        }
    }

    for (int j = 2; j < 7; j++)
    {
        for (int i = 24; i > 19; i--)
        {
            Grid[i][j] = '/';
            break;
        }
    }*/
    c.X = 17;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 20;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 24;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 16;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 19;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 20;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 23;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 15;
    c.Y = 4;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 18;
    c.Y = 4;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 19;
    c.Y = 4;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 22;
    c.Y = 4;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 14;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 17;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 18;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 21;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 13;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 16;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 17;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 20;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 6;
    for (int i = 14; i < 20; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    //Print B
    j = 1;
    for (int i = 28; i < 35; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 27;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 30;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 34;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 26;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 29;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 30;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 31;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 32;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 33;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 25;
    c.Y = 4;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 28;
    c.Y = 4;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 32;
    c.Y = 4;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 24;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 27;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 28;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 31;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 6;
    for (int i = 24; i < 30; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }
    c.X = 23;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 30;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    //Print E
    j = 1;
    for (int i = 37; i < 45; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 36;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 2;
    for (int i = 39; i < 44; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 44;
    c.Y = j;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 35;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 38;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 3;
    for (int i = 39; i < 43; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 34;
    c.Y = 4;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 4;
    for (int i = 37; i < 42; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 42;
    c.Y = j;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 33;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 36;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 5;
    for (int i = 37; i < 41; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 32;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 6;
    for (int i = 33; i < 40; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 40;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    //Print R
    j = 1;
    for (int i = 47; i < 55; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 46;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 49;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 50;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 54;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 45;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 53;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 3;
    for (int i = 49; i < 53; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 44;
    c.Y = 4;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 49;
    c.Y = 4;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '\\');

    c.X = 43;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 46;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 47;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '\\');

    c.X = 50;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '\\');

    c.X = 42;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 43;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 44;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 45;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 48;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '\\');

    c.X = 49;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 50;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 51;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '\\');

    //Print T
    j = 1;
    for (int i = 57; i < 65; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }
    c.X = 56;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 64;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 2;
    for (int i = 57; i < 64; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 59;
    c.Y = j;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = ' ');

    c.X = 60;
    c.Y = j;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = ' ');

    c.X = 56;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 58;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 60;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 57;
    c.Y = 4;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 59;
    c.Y = 4;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 56;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 58;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 55;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 58;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 55;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 57;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    // '
    c.X = 68;
    c.Y = 0;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 67;
    c.Y = 1;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 66;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 67;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 69;
    c.Y = 1;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 68;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    // S
    j = 1;
    for (int i = 71; i < 79; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 70;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 78;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 2;
    for (int i = 72; i < 78; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 69;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 71;
    c.Y = 3;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 3;
    for (int i = 72; i < 77; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 70;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 78;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 4;
    for (int i = 69; i < 74; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 68;
    c.Y = 4;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 76;
    c.Y = 4;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 75;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 74;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 5;
    for (int i = 67; i < 73; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 70;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 78;
    c.Y = 2;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 6;
    for (int i = 67; i < 74; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 66;
    c.Y = 6;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 73;
    c.Y = 5;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    //Print R (RESCUE)
    j = 8;
    for (int i = 7; i < 15; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 6;
    c.Y = 9;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 9;
    c.Y = 9;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 10;
    c.Y = 9;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 14;
    c.Y = 9;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 5;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 13;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 10;
    for (int i = 9; i < 13; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 4;
    c.Y = 11;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 9;
    c.Y = 11;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '\\');

    c.X = 3;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 6;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 7;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '\\');

    c.X = 10;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '\\');

    c.X = 2;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 3;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 4;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 5;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 8;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '\\');

    c.X = 9;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 10;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 11;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '\\');

    //Print E
    j = 8;
    for (int i = 18; i < 26; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 17;
    c.Y = 9;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 9;
    for (int i = 20; i < 25; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 25;
    c.Y = j;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 16;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 19;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 10;
    for (int i = 20; i < 24; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 15;
    c.Y = 11;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 11;
    for (int i = 18; i < 23; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 23;
    c.Y = j;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 14;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 17;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 12;
    for (int i = 18; i < 22; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 14;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 13;
    for (int i = 14; i < 22; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 21;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 13;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    //Print S
    j = 8;
    for (int i = 29; i < 37; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }
    c.X = 28;
    c.Y = 9;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 36;
    c.Y = 9;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 9;
    for (int i = 30; i < 36; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 27;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 29;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    j = 10;
    for (int i = 30; i < 35; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 26;
    c.Y = 11;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 34;
    c.Y = 11;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 11;
    for (int i = 27; i < 32; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 31;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 33;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 12;
    for (int i = 25; i < 31; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 24;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 13;
    for (int i = 25; i < 32; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 32;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    //Print C
    j = 8;
    for (int i = 40; i < 48; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }
    c.X = 39;
    c.Y = 9;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 47;
    c.Y = 9;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 9;
    for (int i = 41; i < 47; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 38;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 40;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 37;
    c.Y = 11;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 39;
    c.Y = 11;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 36;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 38;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 12;
    for (int i = 39; i < 44; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 35;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 43;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 13;
    for (int i = 36; i < 43; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    //Print U
    c.X = 51;
    c.Y = 8;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 52;
    c.Y = 8;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 57;
    c.Y = 8;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 58;
    c.Y = 8;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');

    c.X = 50;
    c.Y = 9;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 52;
    c.Y = 9;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 56;
    c.Y = 9;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 58;
    c.Y = 9;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 49;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 51;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 55;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 57;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 48;
    c.Y = 11;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 50;
    c.Y = 11;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 54;
    c.Y = 11;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 56;
    c.Y = 11;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 47;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 49;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 53;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 55;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 12;
    for (int i = 50; i < 53; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    j = 13;
    for (int i = 46; i < 54; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }
    c.X = 46;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 54;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    //Print E
    j = 8;
    for (int i = 62; i < 70; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 61;
    c.Y = 9;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 9;
    for (int i = 64; i < 69; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }
    c.X = 69;
    c.Y = j;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 60;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 63;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 10;
    for (int i = 64; i < 68; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 59;
    c.Y = 11;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 11;

    for (int i = 62; i < 67; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 67;
    c.Y = j;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 58;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 61;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 12;
    for (int i = 62; i < 66; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }

    c.X = 57;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    j = 13;
    for (int i = 58; i < 65; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_');
    }
    c.X = 65;
    c.Y = 13;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

    c.X = 35;
    c.Y = 18;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'o', 0x0B);

    c.X = 37;
    c.Y = 18;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'S', 0x0B);

    c.X = 38;
    c.Y = 18;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'T', 0x0B);

    c.X = 39;
    c.Y = 18;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'A', 0x0B);

    c.X = 40;
    c.Y = 18;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'R', 0x0B);

    c.X = 41;
    c.Y = 18;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'T', 0x0B);

    j = 19;
    for (int i = 34; i < 43; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '=', 0x0B);
    }

    c.X = 35;
    c.Y = 21;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'o', 0x07);

    c.X = 37;
    c.Y = 21;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'Q', 0x07);

    c.X = 38;
    c.Y = 21;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'U', 0x07);

    c.X = 39;
    c.Y = 21;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'I', 0x07);

    c.X = 40;
    c.Y = 21;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'T', 0x07);

    j = 22;
    for (int i = 34; i < 43; i++)
    {
        c.X = i;
        c.Y = j;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '=', 0x0F);
    }

    if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 18)) && ((g_mouseEvent.mousePosition.X == 34) || (g_mouseEvent.mousePosition.X == 35) || (g_mouseEvent.mousePosition.X == 36) || (g_mouseEvent.mousePosition.X == 37) || (g_mouseEvent.mousePosition.X == 38) || (g_mouseEvent.mousePosition.X == 39) || (g_mouseEvent.mousePosition.X == 40) || (g_mouseEvent.mousePosition.X == 41) || (g_mouseEvent.mousePosition.X == 42))))
    {
        g_dElapsedTime = 0.0;
        g_eGameState = S_Orphanage_Animation;
    }
    if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 21)) && ((g_mouseEvent.mousePosition.X == 34) || (g_mouseEvent.mousePosition.X == 35) || (g_mouseEvent.mousePosition.X == 36) || (g_mouseEvent.mousePosition.X == 37) || (g_mouseEvent.mousePosition.X == 38) || (g_mouseEvent.mousePosition.X == 39) || (g_mouseEvent.mousePosition.X == 40) || (g_mouseEvent.mousePosition.X == 41) || (g_mouseEvent.mousePosition.X == 42))))
    {
        g_bQuitGame = true;
    }
}
//fried stickbug (* q  *

void RenderGameOver()
{
    COORD c; COORD d;
    {
        {
            //GameOver

            //G
            c.X = 27;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 28;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 29;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 30;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 26;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 25;
            c.Y = 2;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 24;
            c.Y = 3;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 23;
            c.Y = 4;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 22;
            c.Y = 5;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 22;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 21;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 22;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 23;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 24;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 25;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 21;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 26;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 27;
            c.Y = 5;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 26;
            c.Y = 4;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 25;
            c.Y = 4;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);
            //A
            c.X = 28;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 29;
            c.Y = 5;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 30;
            c.Y = 4;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 31;
            c.Y = 3;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 32;
            c.Y = 2;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 33;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 34;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 35;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 36;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 37;
            c.Y = 2;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 36;
            c.Y = 3;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 35;
            c.Y = 4;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 34;
            c.Y = 5;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 33;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 34;
            c.Y = 4;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 33;
            c.Y = 4;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 32;
            c.Y = 4;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 31;
            c.Y = 4;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            //M
            c.X = 35;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 36;
            c.Y = 5;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 37;
            c.Y = 4;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 38;
            c.Y = 3;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 39;
            c.Y = 2;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 40;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 41;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 42;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 43;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 44;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 45;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 46;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 47;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 48;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 49;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 45;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 46;
            c.Y = 5;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 47;
            c.Y = 4;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 48;
            c.Y = 3;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 49;
            c.Y = 2;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 44;
            c.Y = 2;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 43;
            c.Y = 3;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 42;
            c.Y = 4;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 41;
            c.Y = 5;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 40;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            //E
            c.X = 51;
            c.Y = 2;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 50;
            c.Y = 3;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 49;
            c.Y = 4;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 48;
            c.Y = 5;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 47;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 52;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 53;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 54;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 55;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 56;
            c.Y = 1;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 50;
            c.Y = 4;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 51;
            c.Y = 4;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 52;
            c.Y = 4;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 53;
            c.Y = 4;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 48;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 49;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 50;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 51;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 52;
            c.Y = 6;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            //O

            c.X = 23;
            c.Y = 9;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 22;
            c.Y = 10;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 21;
            c.Y = 11;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 20;
            c.Y = 12;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 19;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 20;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 21;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 22;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 23;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 24;
            c.Y = 8;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 25;
            c.Y = 8;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 26;
            c.Y = 8;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 27;
            c.Y = 8;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 28;
            c.Y = 8;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 29;
            c.Y = 8;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 24;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 29;
            c.Y = 9;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 28;
            c.Y = 10;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 27;
            c.Y = 11;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 26;
            c.Y = 12;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 25;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            //V

            c.X = 31;
            c.Y = 9;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 30;
            c.Y = 10;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 29;
            c.Y = 11;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 28;
            c.Y = 12;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 27;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 28;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 29;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 30;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 31;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 32;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 33;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 38;
            c.Y = 9;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 37;
            c.Y = 10;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 36;
            c.Y = 11;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 35;
            c.Y = 12;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 34;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 41;
            c.Y = 8;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 42;
            c.Y = 8;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 43;
            c.Y = 8;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 44;
            c.Y = 8;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 45;
            c.Y = 8;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 37;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 38;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 39;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 40;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 41;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 39;
            c.Y = 11;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 40;
            c.Y = 11;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 41;
            c.Y = 11;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 42;
            c.Y = 11;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            //E
            c.X = 40;
            c.Y = 9;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 39;
            c.Y = 10;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 38;
            c.Y = 11;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 37;
            c.Y = 12;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 36;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            //R
            c.X = 47;
            c.Y = 9;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 46;
            c.Y = 10;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 45;
            c.Y = 11;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 44;
            c.Y = 12;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 43;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 48;
            c.Y = 8;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 49;
            c.Y = 8;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 50;
            c.Y = 8;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 51;
            c.Y = 8;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 52;
            c.Y = 8;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 51;
            c.Y = 10;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 52;
            c.Y = 9;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 50;
            c.Y = 11;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/', 0x07);

            c.X = 47;
            c.Y = 11;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 48;
            c.Y = 11;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 49;
            c.Y = 11;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 46;
            c.Y = 11;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '_', 0x07);

            c.X = 47;
            c.Y = 12;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '\\', 0x07);

            c.X = 48;
            c.Y = 13;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '\\', 0x07);

        }//GameOver

        {//Checkpoint
            c.X = 31;
            c.Y = 18;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'O', 0x07);

            c.X = 33;
            c.Y = 18;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'C', 0x07);

            c.X = 34;
            c.Y = 18;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'H', 0x07);

            c.X = 35;
            c.Y = 18;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'E', 0x07);

            c.X = 36;
            c.Y = 18;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'C', 0x07);

            c.X = 37;
            c.Y = 18;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'K', 0x07);

            c.X = 38;
            c.Y = 18;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'P', 0x07);

            c.X = 39;
            c.Y = 18;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'O', 0x07);

            c.X = 40;
            c.Y = 18;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'I', 0x07);

            c.X = 41;
            c.Y = 18;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'N', 0x07);

            c.X = 42;
            c.Y = 18;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'T', 0x07);
        }//CheckPoint
        {
            //Restart
            c.X = 32;
            c.Y = 20;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'O', 0x07);

            c.X = 34;
            c.Y = 20;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'R', 0x07);

            c.X = 35;
            c.Y = 20;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'E', 0x07);

            c.X = 36;
            c.Y = 20;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'S', 0x07);

            c.X = 37;
            c.Y = 20;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'T', 0x07);

            c.X = 38;
            c.Y = 20;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'A', 0x07);

            c.X = 39;
            c.Y = 20;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'R', 0x07);

            c.X = 40;
            c.Y = 20;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'T', 0x07);
        }//Restart
        {
            //Quit
            c.X = 33;
            c.Y = 22;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'O', 0x07);

            c.X = 35;
            c.Y = 22;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'Q', 0x07);

            c.X = 36;
            c.Y = 22;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'U', 0x07);

            c.X = 37;
            c.Y = 22;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'I', 0x07);

            c.X = 38;
            c.Y = 22;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'T', 0x07);
        }
        for (int i = 29; i < 45; i++)
        {
            c.X = i;
            c.Y = 16;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '=', 0x0B);
        }

        for (int i = 29; i < 45; i++)
        {
            c.X = i;
            c.Y = 24;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '=', 0x0B);
        }
        //For Restart
        if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 20)) && ((g_mouseEvent.mousePosition.X == 34) || (g_mouseEvent.mousePosition.X == 35) || (g_mouseEvent.mousePosition.X == 36) || (g_mouseEvent.mousePosition.X == 37) || (g_mouseEvent.mousePosition.X == 38) || (g_mouseEvent.mousePosition.X == 39) || (g_mouseEvent.mousePosition.X == 40) || (g_mouseEvent.mousePosition.X == 41) || (g_mouseEvent.mousePosition.X == 42))))
        {
            g_dElapsedTime = 0.0;
            g_eGameState = S_Orphanage_Animation;
        }
        //For Checkpoint
        else if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 18)) && ((g_mouseEvent.mousePosition.X == 34) || ((g_mouseEvent.mousePosition.X == 33) || (g_mouseEvent.mousePosition.X == 35) || (g_mouseEvent.mousePosition.X == 36) || (g_mouseEvent.mousePosition.X == 37) || (g_mouseEvent.mousePosition.X == 38) || (g_mouseEvent.mousePosition.X == 39) || (g_mouseEvent.mousePosition.X == 40) || (g_mouseEvent.mousePosition.X == 41) || (g_mouseEvent.mousePosition.X == 42) || (g_mouseEvent.mousePosition.X == 43) || (g_mouseEvent.mousePosition.X == 44)))))
        {
            g_dElapsedTime = 0.0;
            g_eGameState = S_Dungeon_Stealth_1;
        }
        //For Quit
        else if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 22)) && ((g_mouseEvent.mousePosition.X == 37) || (g_mouseEvent.mousePosition.X == 38) || (g_mouseEvent.mousePosition.X == 39) || (g_mouseEvent.mousePosition.X == 40))))
        {
            exit(0);
        }

    }

}
