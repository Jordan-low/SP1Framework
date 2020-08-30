//This is the main file for the game logic and function
//1
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Map.h"
#include "Item.h"
#include "Inventory.h"
#include "Cutscenes.h"
#include "Dialogue.h"
#include "drawSprites.h"
#include "Minigame.h"

using namespace std;

double g_dElapsedTime;
double g_dStartScene;
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
double g_dBossMiddleTime;
double g_dBossEndTime;
double g_dPresentationTime;
double g_dslashGuard;
double g_dkillGuard;
double g_dslashWasp;
double g_dkillWasp;
double g_dslashPig;
double g_dkillPig;;
double g_dslashRaymond;
double g_dkillRaymond;
double g_dslashRobert;
double g_dkillRobert;
double g_dslashTutWasp;
double g_dkillTutWasp;
double GuardDetectTime;
double g_dphase2Time;
double startTime;
double resetTime;
double playerDMGTime;
double enemyDMGTime;
double InvenTime;
double playerInvenTime;
double deathAnimation;
double laserTime;
double laserTime2;
double laserTime3;
double movingBlockTime;
double breakFloorTime;
double g_dCreditsTime;
double bombTime;
double raymondTime;
double showCollect;
double Poisontime;
int randnum;
int randnum2;
int randnum3;
int randnum4;
int randnum5;
int randnum6;
int randnum7;
int randnum8;
int randstickman;
int randstickman2;
int randstickman3;
int randBlock;
int randBlock2;
int randBlock3;
int randBreakFloor;
int randBreakFloor2;
int randBreakFloor3;
int randBreakFloor4;
int randBomb;
int randBomb2;
int randCount;
int fightCount;
int fightCount2;
int fightCount3;
int fightCount4;
int fightCount5;
int fightCount6;

bool mainMenu_music;
bool orphanage_music;
bool townsquare_music;
bool speech_se;
bool game_music; // same music for path area, oaf, iaf123
bool stealth_music;
bool phase2_music;
bool credits_music;
bool null_music;
bool enterPathArea;
bool enterOldman;

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
SGameChar   g_sRaymond;
SGameChar   g_sRaymondBoss;
SGameChar   g_sNPC1;
SGameChar   g_sNPC2;
SGameChar   g_sNPC3;
SGameChar   g_sNPC4;
SGameChar   g_sNPC5;
SGameChar   g_sNPC6;
SGameChar   g_sNPC7;
SGameChar   g_sInven;
SGameChar   g_sRawMeat;
SGameChar   g_sBread;
SGameChar   g_sBurger;
SGameChar   g_sTaco;
SGameChar   g_sCake;
SGameChar   g_sMedicine;
SGameChar   g_sStinger;
SGameChar   g_sGuardArmor;
SGameChar   g_sBox;
SGameChar   g_sBox1;
SGameChar   g_sBox2;
SGameChar   g_sBox3;
SGameChar   g_sBox4;
SGameChar   g_sBox5;
SGameChar   g_sBox6;
SGameChar   g_sLaser;
SGameChar   g_sLaser2;
SGameChar   g_sLaser3;
SGameChar   g_sMovingBlock;
SGameChar   g_sBreakFloor;
SGameChar   g_sBomb;
EGAMESTATES g_eGameState; // game states

// Console object
Console g_Console(80, 30, "Robert's Rescue");
// Map object
Map rMap;
Map eMap;
drawSprites Sprites;
Cutscenes Cutscene;
Dialogue Dialogues;
Entity Ent;
Minigame mini;
//Inventory Stuff
Inventory PlayerInv;
Inventory RawMeat;
Inventory Bread;
Inventory Burger;
Inventory Taco;
Inventory Cake;
Inventory Medicine;
Inventory Stinger;
Inventory GuardArmor;

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
    enterPathArea = true;
    randCount = 0;
    g_sChar.entityDied = false;
    g_sLaser.m_cLocation.X = 3;
    g_sLaser.m_cLocation.Y = 2;

    g_sChar.nextDialogue = 0;
    g_sGuard4.startTimer = true;
    g_sChar.faceLeft = true;
    g_sChar.faceRight = false;
    g_sGuard.entityDie = false;
    g_sGuard2.entityDie = false;
    g_sGuard3.entityDie = false;
    g_sChar.entityDie = false;

    g_sGuard.fight = false;
    g_sGuard2.fight = false;
    g_sGuard3.fight = false;
    g_sLaser.fight = false;
    g_sLaser2.fight = false;
    g_sLaser3.fight = false;
    g_sMovingBlock.fight = false;
    g_sBreakFloor.fight = true;
    g_sBomb.fight = false;
    g_sRaymond.fight = false;
    g_sRaymondBoss.fight = false;
    g_sRaymondBoss.counter = false;



    g_sChar.count = 0;
    g_sChar.unlockDoorDS1 = false;
    g_sChar.showEnemyDMG = false;
    g_sChar.showPlayerDMG = false;
    g_sChar.startTimer = true;
    g_sChar.resetTimer = false;
    g_sGuard.startTimer = false;
    g_sMutantWasp.startTimer = false;
    g_sMutantWasp.entityDie = false;
    g_sRaymondBoss.startTimer = false;
    g_sRaymondBoss.resetTimer = false;
    g_sPig.startTimer = false;
    g_sPig.resetTimer = false;
    g_sPig2.startTimer = false;
    g_sPig2.resetTimer = false;
    g_sPig3.startTimer = false;
    g_sPig3.resetTimer = false;
    g_sPig.entityDie = false;
    g_sPig2.entityDie = false;
    g_sPig3.entityDie = false;
    g_sMutantWasp.fight = false;

    /*
    TutEnemy.setEnemy(1, 1, 10, 2, 'E');
    Pig.setEnemy(1, 1, 15, 3, 'E');
    MutantWasp.setEnemy(1, 1, 25, 5, 'E');
    Guard.setEnemy(1, 1, 40, 15, 'E');
    Raymond.setEnemy(1, 1, 120, 25, 'E');
    */

    g_sChar.SetH(1000); // set to 1k when enter room
    g_sChar.SetD(5);
    g_sGuard.SetD(15);
    g_sGuard.SetH(40);
    g_sGuard2.SetD(15);
    g_sGuard2.SetH(40);
    g_sGuard3.SetD(15);
    g_sGuard3.SetH(40);
    g_sPig.SetH(15);
    g_sPig.SetD(3);
    g_sPig2.SetH(15);
    g_sPig2.SetD(3);
    g_sPig3.SetH(15);
    g_sPig3.SetD(3);
    g_sTutEnemy.SetH(10);
    g_sTutEnemy.SetD(2);
    g_sMutantWasp.SetH(25);
    g_sMutantWasp.SetD(5);
    g_sMutantWasp2.SetH(25);
    g_sMutantWasp2.SetD(100);

    g_sChar.Poison = false;
    g_sRaymondBoss.SetH(120);
    g_sRaymondBoss.SetD(25);
    g_sChar.InvenActive = false;
    g_sChar.itemActive = false;
    g_sInven.startTimer = false;
    g_sInven.resetTimer = false;
    g_sInven.showItemUsed = false;
    g_sInven.showItemNotUsed = false;
    g_sInven.showItemDropped = false;
    g_sChar.CP1 = false;
    g_sChar.CP2 = false;
    g_sChar.CP3 = false;
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
    g_sChar.animationPlayed = false;
    g_sChar.enterArea = false;
    g_sChar.talkedOldMan = false;
    g_sChar.IAF3Convo = false;

    //Wire minigame
    g_sBox1.m_cLocation.X = 52;
    g_sBox1.m_cLocation.Y = 12;
    g_sBox1.startTimer = false;
    g_sBox2.m_cLocation.X = 56;
    g_sBox2.m_cLocation.Y = 9;
    g_sBox2.startTimer = false;
    g_sBox3.m_cLocation.X = 60;
    g_sBox3.m_cLocation.Y = 15;
    g_sBox3.startTimer = false;
    g_sBox4.m_cLocation.X = 64;
    g_sBox4.m_cLocation.Y = 10;
    g_sBox4.startTimer = false;
    g_sBox5.m_cLocation.X = 68;
    g_sBox5.m_cLocation.Y = 14;
    g_sBox5.startTimer = false;
    g_sBox6.m_cLocation.X = 72;
    g_sBox6.m_cLocation.Y = 11;
    g_sBox6.startTimer = false;

    //Dungeon Cell Skull spot the difference
    g_sBox.m_cLocation.X = 39;
    g_sBox.m_cLocation.Y = 12;
    g_sBox.startTimer = false;

    g_sLaser.startTimer = false;
    g_sLaser2.startTimer = false;
    g_sLaser3.startTimer = false;
    g_sMovingBlock.startTimer = false;
    g_sBreakFloor.startTimer = false;
    g_sBomb.startTimer = false;
    g_sRaymond.startTimer = false;
    fightCount = 0;
    fightCount2 = 0;
    fightCount3 = 0;
    fightCount4 = 0;
    fightCount5 = 0;
    fightCount6 = 0;
    //bomb things
    g_sBomb.m_cLocation.X = 58;
    g_sBomb.m_cLocation.Y = 19;
    // Set precision for floating point output

    // sets the initial state for the game
    g_eGameState = S_IAF2;

    g_sChar.m_cLocation.X = 4;// 4  g_Console.getConsoleSize().X / 2;
    g_sChar.m_cLocation.Y = 18;// 18   g_Console.getConsoleSize().Y / 2;
    g_sChar.m_bActive = true;

    g_sGuard3.m_cLocation.X = 40;
    g_sGuard3.m_cLocation.Y = 19;

    g_sGuard2.m_cLocation.X = 22;
    g_sGuard2.m_cLocation.Y = 15;

    g_sGuard.m_cLocation.X = 44;
    g_sGuard.m_cLocation.Y = 10;

    g_sRaymond.m_cLocation.X = 20;
    g_sRaymond.m_cLocation.Y = 10;

    // sets the width, height and the font name to use in the console
    g_Console.setConsoleFont(0, 16, L"Consolas");

    // remember to set your keyboard handler, so that your functions can be notified of input events
    g_Console.setKeyboardHandler(keyboardHandler);
    g_Console.setMouseHandler(mouseHandler);
    srand((unsigned)time(0));

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
    case S_phase2Battle: gameplayKBHandler(keyboardEvent);
        break;
        //minigame
    case S_wireGame: gameplayKBHandler(keyboardEvent);
        break;

        //Death
    case S_Boss_Room_Animation: gameplayKBHandler(keyboardEvent);
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
    case S_wireGame: gameplayMouseHandler(mouseEvent);
        break;
    case S_phase2Battle: gameplayMouseHandler(mouseEvent);
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
    g_dStartScene += dt;
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
    g_dBossMiddleTime += dt;
    g_dBossEndTime += dt;
    g_dPresentationTime += dt;
    g_dslashGuard += dt;
    g_dkillGuard += dt;
    GuardDetectTime += dt;
    startTime += dt;
    resetTime += dt;
    playerDMGTime += dt;
    enemyDMGTime += dt;
    InvenTime += dt;
    playerInvenTime += dt;
    g_dslashWasp += dt;
    g_dkillWasp += dt;
    g_dslashPig += dt;
    g_dkillPig += dt;
    g_dslashRaymond += dt;
    g_dkillRaymond += dt;
    g_dslashRobert += dt;
    g_dkillRobert += dt;
    g_dslashTutWasp += dt;
    g_dkillTutWasp += dt;
    g_dphase2Time += dt;
    laserTime += dt;
    laserTime2 += dt;
    laserTime3 += dt;
    movingBlockTime += dt;
    breakFloorTime += dt;
    g_dCreditsTime += dt;
    bombTime += dt;
    raymondTime += dt;
    showCollect += dt;
    Poisontime += dt;

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
    case S_Protest_Area: Update_Protest_Area();
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
        //minigame
    case S_wireGame: updateGame();
        break;

        //Animations
    case S_Start_Animation: Update_starting_cutscene();
        break;
    case S_Protest_Area_Animation: Update_Protest_Area();
        break;
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
    case S_Boss_Room_Mid_Animation: Update_Boss_Room_Mid_Animation();
        break;
    case S_Boss_Room_End_Animation: Update_Boss_End_Animation();
        break;
    case S_Presentation_Animation: Update_Presentation_Animation();
        break;
    case S_BattleScreen: UpdateBattleScreen();
        break;
    case S_Credits: Update_Credits();
        break;

        //Battle Animations
        //case S_SlashGuard: Update_slashGuard();
            //break;
    case S_KillGuard: Update_killGuard();
        break;
    case S_slashWasp: Update_slashWasp();
        break;
    case S_killWasp: Update_killWasp();
        break;
    case S_slashPig: Update_slashPig();
        break;
    case S_killPig: Update_killPig();
        break;
    case S_slashRaymond: Update_slashRaymond();
        break;
    case S_killRaymond: Update_killRaymond();
        break;
    case S_slashRobert: Update_slashRobert();
        break;
    case S_killRobert: Update_killRobert();
        break;
    case S_slashTutWasp: Update_slashTutWasp();
        break;
    case S_killTutWasp: Update_killTutWasp();
        break;

        //Battle Phase 2 Raymond
    case S_phase2Battle: Update_phase2Battle();
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

void Update_starting_cutscene()
{
    if (g_dStartScene > 36)
    {
        g_eGameState = S_Orphanage_Animation;
        g_dElapsedTime = 0.00;
    }
    processUserInput();
}
void starting_cutscene()
{
    Cutscene.clearScreen(g_Console);;
    COORD c;
    if (g_dStartScene > 0.5)
    {
        c.X = 20;
        c.Y = 13;
        g_Console.writeToBuffer(c, "The world went through an economic");
        if (g_dStartScene > 1.5)
        {
            Cutscene.clearScreen(g_Console);;
            c.Y = 12;
            g_Console.writeToBuffer(c, "The world went through an economic");
            c.Y = 13;
            g_Console.writeToBuffer(c, "crisis due to all the things that");

            if (g_dStartScene > 2.5)
            {
                Cutscene.clearScreen(g_Console);;
                c.Y = 11;
                g_Console.writeToBuffer(c, "The world went through an economic");
                c.Y = 12;
                g_Console.writeToBuffer(c, "crisis due to all the things that");
                c.Y = 13;
                g_Console.writeToBuffer(c, "are happening around the globe.");
                if (g_dStartScene > 3.5)
                {
                    Cutscene.clearScreen(g_Console);;
                    c.Y = 10;
                    g_Console.writeToBuffer(c, "The world went through an economic");
                    c.Y = 11;
                    g_Console.writeToBuffer(c, "crisis due to all the things that");
                    c.Y = 12;
                    g_Console.writeToBuffer(c, "are happening around the globe.");
                    c.Y = 13;
                    g_Console.writeToBuffer(c, "Natural disasters due to multiple");
                    if (g_dStartScene > 4.5)
                    {
                        Cutscene.clearScreen(g_Console);;
                        c.Y = 9;
                        g_Console.writeToBuffer(c, "The world went through an economic");
                        c.Y = 10;
                        g_Console.writeToBuffer(c, "crisis due to all the things that");
                        c.Y = 11;
                        g_Console.writeToBuffer(c, "are happening around the globe.");
                        c.Y = 12;
                        g_Console.writeToBuffer(c, "Natural disasters due to multiple");
                        c.Y = 13;
                        g_Console.writeToBuffer(c, "factors such as climate changes and");
                        if (g_dStartScene > 5.5)
                        {
                            Cutscene.clearScreen(g_Console);;
                            c.Y = 8;
                            g_Console.writeToBuffer(c, "The world went through an economic");
                            c.Y = 9;
                            g_Console.writeToBuffer(c, "crisis due to all the things that");
                            c.Y = 10;
                            g_Console.writeToBuffer(c, "are happening around the globe.");
                            c.Y = 11;
                            g_Console.writeToBuffer(c, "Natural disasters due to multiple");
                            c.Y = 12;
                            g_Console.writeToBuffer(c, "factors such as climate changes and");
                            c.Y = 13;
                            g_Console.writeToBuffer(c, "population distribution which");
                            if (g_dStartScene > 6.5)
                            {
                                Cutscene.clearScreen(g_Console);;
                                c.Y = 7;
                                g_Console.writeToBuffer(c, "The world went through an economic");
                                c.Y = 8;
                                g_Console.writeToBuffer(c, "crisis due to all the things that");
                                c.Y = 9;
                                g_Console.writeToBuffer(c, "are happening around the globe.");
                                c.Y = 10;
                                g_Console.writeToBuffer(c, "Natural disasters due to multiple");
                                c.Y = 11;
                                g_Console.writeToBuffer(c, "factors such as climate changes and");
                                c.Y = 12;
                                g_Console.writeToBuffer(c, "population distribution which");
                                c.Y = 13;
                                g_Console.writeToBuffer(c, "greatly affected the country have");
                                if (g_dStartScene > 7.5)
                                {
                                    Cutscene.clearScreen(g_Console);;
                                    c.Y = 6;
                                    g_Console.writeToBuffer(c, "The world went through an economic");
                                    c.Y = 7;
                                    g_Console.writeToBuffer(c, "crisis due to all the things that");
                                    c.Y = 8;
                                    g_Console.writeToBuffer(c, "are happening around the globe.");
                                    c.Y = 9;
                                    g_Console.writeToBuffer(c, "Natural disasters due to multiple");
                                    c.Y = 10;
                                    g_Console.writeToBuffer(c, "factors such as climate changes and");
                                    c.Y = 11;
                                    g_Console.writeToBuffer(c, "population distribution which");
                                    c.Y = 12;
                                    g_Console.writeToBuffer(c, "greatly affected the country have");
                                    c.Y = 13;
                                    g_Console.writeToBuffer(c, "caused mass panic and the country");
                                    if (g_dStartScene > 8.5)
                                    {
                                        Cutscene.clearScreen(g_Console);;
                                        c.Y = 5;
                                        g_Console.writeToBuffer(c, "The world went through an economic");
                                        c.Y = 6;
                                        g_Console.writeToBuffer(c, "crisis due to all the things that");
                                        c.Y = 7;
                                        g_Console.writeToBuffer(c, "are happening around the globe.");
                                        c.Y = 8;
                                        g_Console.writeToBuffer(c, "Natural disasters due to multiple");
                                        c.Y = 9;
                                        g_Console.writeToBuffer(c, "factors such as climate changes");
                                        c.Y = 10;
                                        g_Console.writeToBuffer(c, "and population distribution which");
                                        c.Y = 11;
                                        g_Console.writeToBuffer(c, "greatly affected the country have");
                                        c.Y = 12;
                                        g_Console.writeToBuffer(c, "caused mass panic and the country");
                                        c.Y = 13;
                                        g_Console.writeToBuffer(c, "to suffer huge losses. The government");
                                        if (g_dStartScene > 9.5)
                                        {
                                            Cutscene.clearScreen(g_Console);;
                                            c.Y = 4;
                                            g_Console.writeToBuffer(c, "The world went through an economic");
                                            c.Y = 5;
                                            g_Console.writeToBuffer(c, "crisis due to all the things that");
                                            c.Y = 6;
                                            g_Console.writeToBuffer(c, "are happening around the globe.");
                                            c.Y = 7;
                                            g_Console.writeToBuffer(c, "Natural disasters due to multiple");
                                            c.Y = 8;
                                            g_Console.writeToBuffer(c, "factors such as climate changes");
                                            c.Y = 9;
                                            g_Console.writeToBuffer(c, "and population distribution which");
                                            c.Y = 10;
                                            g_Console.writeToBuffer(c, "greatly affected the country have");
                                            c.Y = 11;
                                            g_Console.writeToBuffer(c, "caused mass panic and the country");
                                            c.Y = 12;
                                            g_Console.writeToBuffer(c, "to suffer huge losses. The government");
                                            c.Y = 13;
                                            g_Console.writeToBuffer(c, "                                                 ");
                                            g_Console.writeToBuffer(c, "then turned corrupt and");
                                            if (g_dStartScene > 10.5)
                                            {
                                                Cutscene.clearScreen(g_Console);;
                                                c.Y = 4;
                                                g_Console.writeToBuffer(c, "crisis due to all the things that");
                                                c.Y = 5;
                                                g_Console.writeToBuffer(c, "are happening around the globe.");
                                                c.Y = 6;
                                                g_Console.writeToBuffer(c, "Natural disasters due to multiple");
                                                c.Y = 7;
                                                g_Console.writeToBuffer(c, "factors such as climate changes");
                                                c.Y = 8;
                                                g_Console.writeToBuffer(c, "and population distribution which");
                                                c.Y = 9;
                                                g_Console.writeToBuffer(c, "greatly affected the country have");
                                                c.Y = 10;
                                                g_Console.writeToBuffer(c, "caused mass panic and the country");
                                                c.Y = 11;
                                                g_Console.writeToBuffer(c, "to suffer huge losses. The government ");
                                                c.Y = 12;
                                                g_Console.writeToBuffer(c, "                                                 ");
                                                g_Console.writeToBuffer(c, "then turned corrupt and");
                                                c.Y = 13;
                                                g_Console.writeToBuffer(c, "blamed each other for their losses.");
                                                if (g_dStartScene > 11.5)
                                                {
                                                    Cutscene.clearScreen(g_Console);;
                                                    c.Y = 4;
                                                    g_Console.writeToBuffer(c, "are happening around the globe.");
                                                    c.Y = 5;
                                                    g_Console.writeToBuffer(c, "Natural disasters due to multiple");
                                                    c.Y = 6;
                                                    g_Console.writeToBuffer(c, "factors such as climate changes");
                                                    c.Y = 7;
                                                    g_Console.writeToBuffer(c, "and population distribution which");
                                                    c.Y = 8;
                                                    g_Console.writeToBuffer(c, "greatly affected the country have");
                                                    c.Y = 9;
                                                    g_Console.writeToBuffer(c, "caused mass panic and the country");
                                                    c.Y = 10;
                                                    g_Console.writeToBuffer(c, "to suffer huge losses. The government");
                                                    c.Y = 11;
                                                    g_Console.writeToBuffer(c, "                                                 ");
                                                    g_Console.writeToBuffer(c, "then turned corrupt and");
                                                    c.Y = 12;
                                                    g_Console.writeToBuffer(c, "blamed each other for their losses.");
                                                    c.Y = 13;
                                                    g_Console.writeToBuffer(c, "Government officials are only worried");
                                                    if (g_dStartScene > 12.5)
                                                    {
                                                        c.Y = 4;
                                                        g_Console.writeToBuffer(c, "Natural disasters due to multiple");
                                                        c.Y = 5;
                                                        g_Console.writeToBuffer(c, "factors such as climate changes");
                                                        c.Y = 6;
                                                        g_Console.writeToBuffer(c, "and population distribution which");
                                                        c.Y = 7;
                                                        g_Console.writeToBuffer(c, "greatly affected the country have");
                                                        c.Y = 8;
                                                        g_Console.writeToBuffer(c, "caused mass panic and the country");
                                                        c.Y = 9;
                                                        g_Console.writeToBuffer(c, "to suffer huge losses. The government");
                                                        c.Y = 10;
                                                        g_Console.writeToBuffer(c, "                                                 ");
                                                        g_Console.writeToBuffer(c, "then turned corrupt and");
                                                        c.Y = 11;
                                                        g_Console.writeToBuffer(c, "blamed each other for their losses.");
                                                        c.Y = 12;
                                                        g_Console.writeToBuffer(c, "Government officials are only worried");
                                                        c.Y = 13;
                                                        g_Console.writeToBuffer(c, "about their own personal gain and");
                                                        if (g_dStartScene > 13.5)
                                                        {
                                                            Cutscene.clearScreen(g_Console);;
                                                            c.Y = 4;
                                                            g_Console.writeToBuffer(c, "factors such as climate changes");
                                                            c.Y = 5;
                                                            g_Console.writeToBuffer(c, "and population distribution which");
                                                            c.Y = 6;
                                                            g_Console.writeToBuffer(c, "greatly affected the country have");
                                                            c.Y = 7;
                                                            g_Console.writeToBuffer(c, "caused mass panic and the country");
                                                            c.Y = 8;
                                                            g_Console.writeToBuffer(c, "to suffer huge losses. The government");
                                                            c.Y = 9;
                                                            g_Console.writeToBuffer(c, "                                                 ");
                                                            g_Console.writeToBuffer(c, "then turned corrupt and");
                                                            c.Y = 10;
                                                            g_Console.writeToBuffer(c, "blamed each other for their losses.");
                                                            c.Y = 11;
                                                            g_Console.writeToBuffer(c, "Government officials are only worried");
                                                            c.Y = 12;
                                                            g_Console.writeToBuffer(c, "about their own personal gain and");
                                                            c.Y = 13;
                                                            g_Console.writeToBuffer(c, "were apathetic towards the citizens");
                                                            if (g_dStartScene > 14.5)
                                                            {
                                                                Cutscene.clearScreen(g_Console);;
                                                                c.Y = 4;
                                                                g_Console.writeToBuffer(c, "and population distribution which");
                                                                c.Y = 5;
                                                                g_Console.writeToBuffer(c, "greatly affected the country have");
                                                                c.Y = 6;
                                                                g_Console.writeToBuffer(c, "caused mass panic and the country");
                                                                c.Y = 7;
                                                                g_Console.writeToBuffer(c, "to suffer huge losses. The government");
                                                                c.Y = 8; 
                                                                g_Console.writeToBuffer(c, "                                                 ");
                                                                g_Console.writeToBuffer(c, "then turned corrupt and");
                                                                c.Y = 9;
                                                                g_Console.writeToBuffer(c, "blamed each other for their losses.");
                                                                c.Y = 10;
                                                                g_Console.writeToBuffer(c, "Government officials are only worried");
                                                                c.Y = 11;
                                                                g_Console.writeToBuffer(c, "about their own personal gain and");
                                                                c.Y = 12;
                                                                g_Console.writeToBuffer(c, "were apathetic towards the citizens");
                                                                c.Y = 13;
                                                                g_Console.writeToBuffer(c, "struggles. And so many other countries");
                                                                if (g_dStartScene > 15.5)
                                                                {
                                                                    Cutscene.clearScreen(g_Console);;
                                                                    c.Y = 4;
                                                                    g_Console.writeToBuffer(c, "greatly affected the country have");
                                                                    c.Y = 5;
                                                                    g_Console.writeToBuffer(c, "caused mass panic and the country");
                                                                    c.Y = 6;
                                                                    g_Console.writeToBuffer(c, "to suffer huge losses. The government");
                                                                    c.Y = 7;
                                                                    g_Console.writeToBuffer(c, "                                                 ");
                                                                    g_Console.writeToBuffer(c, "then turned corrupt and");
                                                                    c.Y = 8;
                                                                    g_Console.writeToBuffer(c, "blamed each other for their losses.");
                                                                    c.Y = 9;
                                                                    g_Console.writeToBuffer(c, "Government officials are only worried");
                                                                    c.Y = 10;
                                                                    g_Console.writeToBuffer(c, "about their own personal gain and");
                                                                    c.Y = 11;
                                                                    g_Console.writeToBuffer(c, "were apathetic towards the citizens");
                                                                    c.Y = 12;
                                                                    g_Console.writeToBuffer(c, "struggles. And so many other countries");
                                                                    c.Y = 13;
                                                                    g_Console.writeToBuffer(c, "were hoping to invade and conquer the");
                                                                    if (g_dStartScene > 16.5)
                                                                    {
                                                                        Cutscene.clearScreen(g_Console);;
                                                                        c.Y = 4;
                                                                        g_Console.writeToBuffer(c, "caused mass panic and the country");
                                                                        c.Y = 5;
                                                                        g_Console.writeToBuffer(c, "to suffer huge losses. The government");
                                                                        c.Y = 6;
                                                                        g_Console.writeToBuffer(c, "                                                 ");
                                                                        g_Console.writeToBuffer(c, "then turned corrupt and");
                                                                        c.Y = 7;
                                                                        g_Console.writeToBuffer(c, "blamed each other for their losses.");
                                                                        c.Y = 8;
                                                                        g_Console.writeToBuffer(c, "Government officials are only worried");
                                                                        c.Y = 9;
                                                                        g_Console.writeToBuffer(c, "about their own personal gain and");
                                                                        c.Y = 10;
                                                                        g_Console.writeToBuffer(c, "were apathetic towards the citizens");
                                                                        c.Y = 11;
                                                                        g_Console.writeToBuffer(c, "struggles. And so many other countries");
                                                                        c.Y = 12;
                                                                        g_Console.writeToBuffer(c, "were hoping to invade and conquer the");
                                                                        c.Y = 13;
                                                                        g_Console.writeToBuffer(c, "country while it was in chaos. This has");
                                                                        if (g_dStartScene > 17.5)
                                                                        {
                                                                            Cutscene.clearScreen(g_Console);;
                                                                            c.Y = 4;
                                                                            g_Console.writeToBuffer(c, "to suffer huge losses. The government");
                                                                            c.Y = 5;
                                                                            g_Console.writeToBuffer(c, "                                                 ");
                                                                            g_Console.writeToBuffer(c, "then turned corrupt and");
                                                                            c.Y = 6;
                                                                            g_Console.writeToBuffer(c, "blamed each other for their losses.");
                                                                            c.Y = 7;
                                                                            g_Console.writeToBuffer(c, "Government officials are only worried");
                                                                            c.Y = 8;
                                                                            g_Console.writeToBuffer(c, "about their own personal gain and");
                                                                            c.Y = 9;
                                                                            g_Console.writeToBuffer(c, "were apathetic towards the citizens");
                                                                            c.Y = 10;
                                                                            g_Console.writeToBuffer(c, "struggles. And so many other countries");
                                                                            c.Y = 11;
                                                                            g_Console.writeToBuffer(c, "were hoping to invade and conquer the");
                                                                            c.Y = 12;
                                                                            g_Console.writeToBuffer(c, "country while it was in chaos. This has");
                                                                            c.Y = 13;
                                                                            g_Console.writeToBuffer(c, "greatly increased the tension between");
                                                                            if (g_dStartScene > 18.5)
                                                                            {
                                                                                Cutscene.clearScreen(g_Console);;
                                                                                c.Y = 4;
                                                                                g_Console.writeToBuffer(c, "                                                 ");
                                                                                g_Console.writeToBuffer(c, "then turned corrupt and");
                                                                                c.Y = 5;
                                                                                g_Console.writeToBuffer(c, "blamed each other for their losses.");
                                                                                c.Y = 6;
                                                                                g_Console.writeToBuffer(c, "Government officials are only worried");
                                                                                c.Y = 7;
                                                                                g_Console.writeToBuffer(c, "about their own personal gain and");
                                                                                c.Y = 8;
                                                                                g_Console.writeToBuffer(c, "were apathetic towards the citizens");
                                                                                c.Y = 9;
                                                                                g_Console.writeToBuffer(c, "struggles. And so many other countries");
                                                                                c.Y = 10;
                                                                                g_Console.writeToBuffer(c, "were hoping to invade and conquer the");
                                                                                c.Y = 11;
                                                                                g_Console.writeToBuffer(c, "country while it was in chaos. This has");
                                                                                c.Y = 12;
                                                                                g_Console.writeToBuffer(c, "greatly increased the tension between");
                                                                                c.Y = 13;
                                                                                g_Console.writeToBuffer(c, "countries, eventually leading to a world war.");
                                                                                if (g_dStartScene > 19.5)
                                                                                {
                                                                                    Cutscene.clearScreen(g_Console);;
                                                                                    c.Y = 4;
                                                                                    g_Console.writeToBuffer(c, "blamed each other for their losses.");
                                                                                    c.Y = 5;
                                                                                    g_Console.writeToBuffer(c, "Government officials are only worried");
                                                                                    c.Y = 6;
                                                                                    g_Console.writeToBuffer(c, "about their own personal gain and");
                                                                                    c.Y = 7;
                                                                                    g_Console.writeToBuffer(c, "were apathetic towards the citizens");
                                                                                    c.Y = 8;
                                                                                    g_Console.writeToBuffer(c, "struggles. And so many other countries");
                                                                                    c.Y = 9;
                                                                                    g_Console.writeToBuffer(c, "were hoping to invade and conquer the");
                                                                                    c.Y = 10;
                                                                                    g_Console.writeToBuffer(c, "country while it was in chaos. This has");
                                                                                    c.Y = 11;
                                                                                    g_Console.writeToBuffer(c, "greatly increased the tension between");
                                                                                    c.Y = 12;
                                                                                    g_Console.writeToBuffer(c, "countries, eventually leading to a world war.");
                                                                                    c.Y = 13;
                                                                                    g_Console.writeToBuffer(c, "And as if god was mocking humans, hornets");
                                                                                    if (g_dStartScene > 20.5)
                                                                                    {
                                                                                        Cutscene.clearScreen(g_Console);;
                                                                                        c.Y = 4;
                                                                                        g_Console.writeToBuffer(c, "Government officials are only worried");
                                                                                        c.Y = 5;
                                                                                        g_Console.writeToBuffer(c, "about their own personal gain and");
                                                                                        c.Y = 6;
                                                                                        g_Console.writeToBuffer(c, "were apathetic towards the citizens");
                                                                                        c.Y = 7;
                                                                                        g_Console.writeToBuffer(c, "struggles. And so many other countries");
                                                                                        c.Y = 8;
                                                                                        g_Console.writeToBuffer(c, "were hoping to invade and conquer the");
                                                                                        c.Y = 9;
                                                                                        g_Console.writeToBuffer(c, "country while it was in chaos. This has");
                                                                                        c.Y = 10;
                                                                                        g_Console.writeToBuffer(c, "greatly increased the tension between");
                                                                                        c.Y = 11;
                                                                                        g_Console.writeToBuffer(c, "countries, eventually leading to a world war.");
                                                                                        c.Y = 12;
                                                                                        g_Console.writeToBuffer(c, "And as if god was mocking humans, hornets");
                                                                                        c.Y = 13;
                                                                                        g_Console.writeToBuffer(c, "evolved and turned into man eating monsters.");
                                                                                        if (g_dStartScene > 21.5)
                                                                                        {
                                                                                            Cutscene.clearScreen(g_Console);;
                                                                                            c.Y = 4;
                                                                                            g_Console.writeToBuffer(c, "about their own personal gain and");
                                                                                            c.Y = 5;
                                                                                            g_Console.writeToBuffer(c, "were apathetic towards the citizens");
                                                                                            c.Y = 6;
                                                                                            g_Console.writeToBuffer(c, "struggles. And so many other countries");
                                                                                            c.Y = 7;
                                                                                            g_Console.writeToBuffer(c, "were hoping to invade and conquer the");
                                                                                            c.Y = 8;
                                                                                            g_Console.writeToBuffer(c, "country while it was in chaos. This has");
                                                                                            c.Y = 9;
                                                                                            g_Console.writeToBuffer(c, "greatly increased the tension between");
                                                                                            c.Y = 10;
                                                                                            g_Console.writeToBuffer(c, "countries, eventually leading to a world war.");
                                                                                            c.Y = 11;
                                                                                            g_Console.writeToBuffer(c, "And as if god was mocking humans, hornets");
                                                                                            c.Y = 12;
                                                                                            g_Console.writeToBuffer(c, "evolved and turned into man eating monsters.");
                                                                                            c.Y = 13;
                                                                                            g_Console.writeToBuffer(c, "And now, it is up to Robert to fight against");
                                                                                            if (g_dStartScene > 22.5)
                                                                                            {
                                                                                                Cutscene.clearScreen(g_Console);;
                                                                                                c.Y = 4;
                                                                                                g_Console.writeToBuffer(c, "were apathetic towards the citizens");
                                                                                                c.Y = 5;
                                                                                                g_Console.writeToBuffer(c, "struggles. And so many other countries");
                                                                                                c.Y = 6;
                                                                                                g_Console.writeToBuffer(c, "were hoping to invade and conquer the");
                                                                                                c.Y = 7;
                                                                                                g_Console.writeToBuffer(c, "country while it was in chaos. This has");
                                                                                                c.Y = 8;
                                                                                                g_Console.writeToBuffer(c, "greatly increased the tension between");
                                                                                                c.Y = 9;
                                                                                                g_Console.writeToBuffer(c, "countries, eventually leading to a world war.");
                                                                                                c.Y = 10;
                                                                                                g_Console.writeToBuffer(c, "And as if god was mocking humans, hornets");
                                                                                                c.Y = 11;
                                                                                                g_Console.writeToBuffer(c, "evolved and turned into man eating monsters.");
                                                                                                c.Y = 12;
                                                                                                g_Console.writeToBuffer(c, "And now, it is up to Robert to fight against");
                                                                                                c.Y = 13;
                                                                                                g_Console.writeToBuffer(c, "all odds to try and salvage what is left of");
                                                                                                if (g_dStartScene > 23.5)
                                                                                                {
                                                                                                    Cutscene.clearScreen(g_Console);;
                                                                                                    c.Y = 4;
                                                                                                    g_Console.writeToBuffer(c, "struggles. And so many other countries");
                                                                                                    c.Y = 5;
                                                                                                    g_Console.writeToBuffer(c, "were hoping to invade and conquer the");
                                                                                                    c.Y = 6;
                                                                                                    g_Console.writeToBuffer(c, "country while it was in chaos. This has");
                                                                                                    c.Y = 7;
                                                                                                    g_Console.writeToBuffer(c, "greatly increased the tension between");
                                                                                                    c.Y = 8;
                                                                                                    g_Console.writeToBuffer(c, "countries, eventually leading to a world war.");
                                                                                                    c.Y = 9;
                                                                                                    g_Console.writeToBuffer(c, "And as if god was mocking humans, hornets");
                                                                                                    c.Y = 10;
                                                                                                    g_Console.writeToBuffer(c, "evolved and turned into man eating monsters.");
                                                                                                    c.Y = 11;
                                                                                                    g_Console.writeToBuffer(c, "And now, it is up to Robert to fight against");
                                                                                                    c.Y = 12;
                                                                                                    g_Console.writeToBuffer(c, "all odds to try and salvage what is left of");
                                                                                                    c.Y = 13;
                                                                                                    g_Console.writeToBuffer(c, "this world. To use whatever limited resources");
                                                                                                    if (g_dStartScene > 24.5)
                                                                                                    {
                                                                                                        Cutscene.clearScreen(g_Console);;
                                                                                                        c.Y = 4;
                                                                                                        g_Console.writeToBuffer(c, "were hoping to invade and conquer the");
                                                                                                        c.Y = 5;
                                                                                                        g_Console.writeToBuffer(c, "country while it was in chaos. This has");
                                                                                                        c.Y = 6;
                                                                                                        g_Console.writeToBuffer(c, "greatly increased the tension between");
                                                                                                        c.Y = 7;
                                                                                                        g_Console.writeToBuffer(c, "countries, eventually leading to a world war.");
                                                                                                        c.Y = 8;
                                                                                                        g_Console.writeToBuffer(c, "And as if god was mocking humans, hornets");
                                                                                                        c.Y = 9;
                                                                                                        g_Console.writeToBuffer(c, "evolved and turned into man eating monsters.");
                                                                                                        c.Y = 10;
                                                                                                        g_Console.writeToBuffer(c, "And now, it is up to Robert to fight against");
                                                                                                        c.Y = 11;
                                                                                                        g_Console.writeToBuffer(c, "all odds to try and salvage what is left of");
                                                                                                        c.Y = 12;
                                                                                                        g_Console.writeToBuffer(c, "this world. To use whatever limited resources");
                                                                                                        c.Y = 13;
                                                                                                        g_Console.writeToBuffer(c, "he has to help restore the world back to its");
                                                                                                        if (g_dStartScene > 25.5)
                                                                                                        {
                                                                                                            Cutscene.clearScreen(g_Console);;
                                                                                                            c.Y = 4;
                                                                                                            g_Console.writeToBuffer(c, "country while it was in chaos. This has");
                                                                                                            c.Y = 5;
                                                                                                            g_Console.writeToBuffer(c, "greatly increased the tension between");
                                                                                                            c.Y = 6;
                                                                                                            g_Console.writeToBuffer(c, "countries, eventually leading to a world war.");
                                                                                                            c.Y = 7;
                                                                                                            g_Console.writeToBuffer(c, "And as if god was mocking humans, hornets");
                                                                                                            c.Y = 8;
                                                                                                            g_Console.writeToBuffer(c, "evolved and turned into man eating monsters.");
                                                                                                            c.Y = 9;
                                                                                                            g_Console.writeToBuffer(c, "And now, it is up to Robert to fight against");
                                                                                                            c.Y = 10;
                                                                                                            g_Console.writeToBuffer(c, "all odds to try and salvage what is left of");
                                                                                                            c.Y = 11;
                                                                                                            g_Console.writeToBuffer(c, "this world. To use whatever limited resources");
                                                                                                            c.Y = 12;
                                                                                                            g_Console.writeToBuffer(c, "he has to help restore the world back to its");
                                                                                                            c.Y = 13;
                                                                                                            g_Console.writeToBuffer(c, "peaceful state.");
                                                                                                            if (g_dStartScene > 26.5)
                                                                                                            {
                                                                                                                Cutscene.clearScreen(g_Console);;
                                                                                                                c.Y = 4;
                                                                                                                g_Console.writeToBuffer(c, "greatly increased the tension between");
                                                                                                                c.Y = 5;
                                                                                                                g_Console.writeToBuffer(c, "countries, eventually leading to a world war.");
                                                                                                                c.Y = 6;
                                                                                                                g_Console.writeToBuffer(c, "And as if god was mocking humans, hornets");
                                                                                                                c.Y = 7;
                                                                                                                g_Console.writeToBuffer(c, "evolved and turned into man eating monsters.");
                                                                                                                c.Y = 8;
                                                                                                                g_Console.writeToBuffer(c, "And now, it is up to Robert to fight against");
                                                                                                                c.Y = 9;
                                                                                                                g_Console.writeToBuffer(c, "all odds to try and salvage what is left of");
                                                                                                                c.Y = 10;
                                                                                                                g_Console.writeToBuffer(c, "this world. To use whatever limited resources");
                                                                                                                c.Y = 11;
                                                                                                                g_Console.writeToBuffer(c, "he has to help restore the world back to its");
                                                                                                                c.Y = 12;
                                                                                                                g_Console.writeToBuffer(c, "peaceful state.");
                                                                                                                if (g_dStartScene > 27.5)
                                                                                                                {
                                                                                                                    Cutscene.clearScreen(g_Console);;
                                                                                                                    c.Y = 4;
                                                                                                                    g_Console.writeToBuffer(c, "countries, eventually leading to a world war.");
                                                                                                                    c.Y = 5;
                                                                                                                    g_Console.writeToBuffer(c, "And as if god was mocking humans, hornets");
                                                                                                                    c.Y = 6;
                                                                                                                    g_Console.writeToBuffer(c, "evolved and turned into man eating monsters.");
                                                                                                                    c.Y = 7;
                                                                                                                    g_Console.writeToBuffer(c, "And now, it is up to Robert to fight against");
                                                                                                                    c.Y = 8;
                                                                                                                    g_Console.writeToBuffer(c, "all odds to try and salvage what is left of");
                                                                                                                    c.Y = 9;
                                                                                                                    g_Console.writeToBuffer(c, "this world. To use whatever limited resources");
                                                                                                                    c.Y = 10;
                                                                                                                    g_Console.writeToBuffer(c, "he has to help restore the world back to its");
                                                                                                                    c.Y = 11;
                                                                                                                    g_Console.writeToBuffer(c, "peaceful state.");
                                                                                                                    if (g_dStartScene > 28.5)
                                                                                                                    {
                                                                                                                        Cutscene.clearScreen(g_Console);;
                                                                                                                        c.Y = 4;
                                                                                                                        g_Console.writeToBuffer(c, "And as if god was mocking humans, hornets");
                                                                                                                        c.Y = 5;
                                                                                                                        g_Console.writeToBuffer(c, "evolved and turned into man eating monsters.");
                                                                                                                        c.Y = 6;
                                                                                                                        g_Console.writeToBuffer(c, "And now, it is up to Robert to fight against");
                                                                                                                        c.Y = 7;
                                                                                                                        g_Console.writeToBuffer(c, "all odds to try and salvage what is left of");
                                                                                                                        c.Y = 8;
                                                                                                                        g_Console.writeToBuffer(c, "this world. To use whatever limited resources");
                                                                                                                        c.Y = 9;
                                                                                                                        g_Console.writeToBuffer(c, "he has to help restore the world back to its");
                                                                                                                        c.Y = 10;
                                                                                                                        g_Console.writeToBuffer(c, "peaceful state.");
                                                                                                                        if (g_dStartScene > 29.5)
                                                                                                                        {
                                                                                                                            Cutscene.clearScreen(g_Console);;
                                                                                                                            c.Y = 4;
                                                                                                                            g_Console.writeToBuffer(c, "evolved and turned into man eating monsters.");
                                                                                                                            c.Y = 5;
                                                                                                                            g_Console.writeToBuffer(c, "And now, it is up to Robert to fight against");
                                                                                                                            c.Y = 6;
                                                                                                                            g_Console.writeToBuffer(c, "all odds to try and salvage what is left of");
                                                                                                                            c.Y = 7;
                                                                                                                            g_Console.writeToBuffer(c, "this world. To use whatever limited resources");
                                                                                                                            c.Y = 8;
                                                                                                                            g_Console.writeToBuffer(c, "he has to help restore the world back to its");
                                                                                                                            c.Y = 9;
                                                                                                                            g_Console.writeToBuffer(c, "peaceful state.");
                                                                                                                            if (g_dStartScene > 30.5)
                                                                                                                            {
                                                                                                                                Cutscene.clearScreen(g_Console);;
                                                                                                                                c.Y = 4;
                                                                                                                                g_Console.writeToBuffer(c, "And now, it is up to Robert to fight against");
                                                                                                                                c.Y = 5;
                                                                                                                                g_Console.writeToBuffer(c, "all odds to try and salvage what is left of");
                                                                                                                                c.Y = 6;
                                                                                                                                g_Console.writeToBuffer(c, "this world. To use whatever limited resources");
                                                                                                                                c.Y = 7;
                                                                                                                                g_Console.writeToBuffer(c, "he has to help restore the world back to its");
                                                                                                                                c.Y = 8;
                                                                                                                                g_Console.writeToBuffer(c, "peaceful state.");
                                                                                                                                if (g_dStartScene > 31.5)
                                                                                                                                {
                                                                                                                                    Cutscene.clearScreen(g_Console);;
                                                                                                                                    c.Y = 4;
                                                                                                                                    g_Console.writeToBuffer(c, "all odds to try and salvage what is left of");
                                                                                                                                    c.Y = 5;
                                                                                                                                    g_Console.writeToBuffer(c, "this world. To use whatever limited resources");
                                                                                                                                    c.Y = 6;
                                                                                                                                    g_Console.writeToBuffer(c, "he has to help restore the world back to its");
                                                                                                                                    c.Y = 7;
                                                                                                                                    g_Console.writeToBuffer(c, "peaceful state.");
                                                                                                                                    if (g_dStartScene > 32.5)
                                                                                                                                    {
                                                                                                                                        Cutscene.clearScreen(g_Console);;
                                                                                                                                        c.Y = 4;
                                                                                                                                        g_Console.writeToBuffer(c, "this world. To use whatever limited resources");
                                                                                                                                        c.Y = 5;
                                                                                                                                        g_Console.writeToBuffer(c, "he has to help restore the world back to its");
                                                                                                                                        c.Y = 6;
                                                                                                                                        g_Console.writeToBuffer(c, "peaceful state.");
                                                                                                                                        if (g_dStartScene > 33.5)
                                                                                                                                        {
                                                                                                                                            Cutscene.clearScreen(g_Console);;
                                                                                                                                            c.Y = 4;
                                                                                                                                            g_Console.writeToBuffer(c, "he has to help restore the world back to its");
                                                                                                                                            c.Y = 5;
                                                                                                                                            g_Console.writeToBuffer(c, "peaceful state.");
                                                                                                                                            if (g_dStartScene > 34.5)
                                                                                                                                            {
                                                                                                                                                Cutscene.clearScreen(g_Console);;
                                                                                                                                                c.Y = 4;
                                                                                                                                                g_Console.writeToBuffer(c, "peaceful state.");
                                                                                                                                                if (g_dStartScene > 35.5)
                                                                                                                                                {
                                                                                                                                                    Cutscene.clearScreen(g_Console);;
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

void Update_Credits()
{
    if (g_dCreditsTime > 55.0)
    {
        g_eGameState = S_MENU_UI;
    }
    processUserInput();
}
void Credits()
{
    while (credits_music == false)
    {
        PlaySound(TEXT("Ancient Lullaby.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        credits_music = true;
    }
    Cutscene.clearScreen(g_Console);
    COORD c;
    if (g_dCreditsTime > 1.0)
    {
        Cutscene.clearScreen(g_Console);
        if (g_dCreditsTime > 2.0)
        {
            c.X = 32;
            c.Y = 17;
            g_Console.writeToBuffer(c, "Development Team");
            if (g_dCreditsTime > 3.0)
            {
                Cutscene.clearScreen(g_Console);
                c.Y = 16;
                g_Console.writeToBuffer(c, "Development Team");
                if (g_dCreditsTime > 4.0)
                {
                    Cutscene.clearScreen(g_Console);
                    c.Y = 15;
                    g_Console.writeToBuffer(c, "Development Team");
                    c.Y = 17;
                    g_Console.writeToBuffer(c, "     Andrew");
                    if (g_dCreditsTime > 5.0)
                    {
                        Cutscene.clearScreen(g_Console);
                        c.Y = 14;
                        g_Console.writeToBuffer(c, "Development Team");
                        c.Y = 16;
                        g_Console.writeToBuffer(c, "     Andrew");
                        c.Y = 17;
                        g_Console.writeToBuffer(c, "     Artus");
                        if (g_dCreditsTime > 6.0)
                        {
                            Cutscene.clearScreen(g_Console);
                            c.Y = 13;
                            g_Console.writeToBuffer(c, "Development Team");
                            c.Y = 15;
                            g_Console.writeToBuffer(c, "     Andrew");
                            c.Y = 16;
                            g_Console.writeToBuffer(c, "     Artus");
                            c.Y = 17;
                            g_Console.writeToBuffer(c, "     Jordan");
                            if (g_dCreditsTime > 7.0)
                            {
                                Cutscene.clearScreen(g_Console);
                                c.Y = 12;
                                g_Console.writeToBuffer(c, "Development Team");
                                c.Y = 14;
                                g_Console.writeToBuffer(c, "     Andrew");
                                c.Y = 15;
                                g_Console.writeToBuffer(c, "     Artus");
                                c.Y = 16;
                                g_Console.writeToBuffer(c, "     Jordan");
                                c.Y = 17;
                                g_Console.writeToBuffer(c, "     Nicole");
                                if (g_dCreditsTime > 8.0)
                                {
                                    Cutscene.clearScreen(g_Console);
                                    c.Y = 11;
                                    g_Console.writeToBuffer(c, "Development Team");
                                    c.Y = 13;
                                    g_Console.writeToBuffer(c, "     Andrew");
                                    c.Y = 14;
                                    g_Console.writeToBuffer(c, "     Artus");
                                    c.Y = 15;
                                    g_Console.writeToBuffer(c, "     Jordan");
                                    c.Y = 16;
                                    g_Console.writeToBuffer(c, "     Nicole");
                                    c.Y = 17;
                                    g_Console.writeToBuffer(c, "     Renee");
                                    if (g_dCreditsTime > 9.0)
                                    {
                                        Cutscene.clearScreen(g_Console);
                                        c.Y = 10;
                                        g_Console.writeToBuffer(c, "Development Team");
                                        c.Y = 12;
                                        g_Console.writeToBuffer(c, "     Andrew");
                                        c.Y = 13;
                                        g_Console.writeToBuffer(c, "     Artus");
                                        c.Y = 14;
                                        g_Console.writeToBuffer(c, "     Jordan");
                                        c.Y = 15;
                                        g_Console.writeToBuffer(c, "     Nicole");
                                        c.Y = 16;
                                        g_Console.writeToBuffer(c, "     Renee");
                                        if (g_dCreditsTime > 10.0)
                                        {
                                            Cutscene.clearScreen(g_Console);
                                            c.Y = 9;
                                            g_Console.writeToBuffer(c, "Development Team");
                                            c.Y = 11;
                                            g_Console.writeToBuffer(c, "     Andrew");
                                            c.Y = 12;
                                            g_Console.writeToBuffer(c, "     Artus");
                                            c.Y = 13;
                                            g_Console.writeToBuffer(c, "     Jordan");
                                            c.Y = 14;
                                            g_Console.writeToBuffer(c, "     Nicole");
                                            c.Y = 15;
                                            g_Console.writeToBuffer(c, "     Renee");
                                            if (g_dCreditsTime > 11.0)
                                            {
                                                Cutscene.clearScreen(g_Console);
                                                c.Y = 8;
                                                g_Console.writeToBuffer(c, "Development Team");
                                                c.Y = 10;
                                                g_Console.writeToBuffer(c, "     Andrew");
                                                c.Y = 11;
                                                g_Console.writeToBuffer(c, "     Artus");
                                                c.Y = 12;
                                                g_Console.writeToBuffer(c, "     Jordan");
                                                c.Y = 13;
                                                g_Console.writeToBuffer(c, "     Nicole");
                                                c.Y = 14;
                                                g_Console.writeToBuffer(c, "     Renee");
                                                c.Y = 17;
                                                g_Console.writeToBuffer(c, "     Music");
                                                if (g_dCreditsTime > 12.0)
                                                {
                                                    Cutscene.clearScreen(g_Console);
                                                    c.Y = 7;
                                                    g_Console.writeToBuffer(c, "Development Team");
                                                    c.Y = 9;
                                                    g_Console.writeToBuffer(c, "     Andrew");
                                                    c.Y = 10;
                                                    g_Console.writeToBuffer(c, "     Artus");
                                                    c.Y = 11;
                                                    g_Console.writeToBuffer(c, "     Jordan");
                                                    c.Y = 12;
                                                    g_Console.writeToBuffer(c, "     Nicole");
                                                    c.Y = 13;
                                                    g_Console.writeToBuffer(c, "     Renee");
                                                    c.Y = 16;
                                                    g_Console.writeToBuffer(c, "     Music");
                                                    if (g_dCreditsTime > 13.0)
                                                    {
                                                        Cutscene.clearScreen(g_Console);
                                                        c.Y = 8;
                                                        g_Console.writeToBuffer(c, "     Andrew");
                                                        c.Y = 9;
                                                        g_Console.writeToBuffer(c, "     Artus");
                                                        c.Y = 10;
                                                        g_Console.writeToBuffer(c, "     Jordan");
                                                        c.Y = 11;
                                                        g_Console.writeToBuffer(c, "     Nicole");
                                                        c.Y = 12;
                                                        g_Console.writeToBuffer(c, "     Renee");
                                                        c.Y = 15;
                                                        g_Console.writeToBuffer(c, "     Music");
                                                        c.X = 30;
                                                        c.Y = 17;
                                                        g_Console.writeToBuffer(c, "  \"8 Bit Retro Funk\"");
                                                        if (g_dCreditsTime > 14.0)
                                                        {
                                                            Cutscene.clearScreen(g_Console);
                                                            c.X = 32;
                                                            c.Y = 7;
                                                            g_Console.writeToBuffer(c, "     Andrew");
                                                            c.Y = 8;
                                                            g_Console.writeToBuffer(c, "     Artus");
                                                            c.Y = 9;
                                                            g_Console.writeToBuffer(c, "     Jordan");
                                                            c.Y = 10;
                                                            g_Console.writeToBuffer(c, "     Nicole");
                                                            c.Y = 11;
                                                            g_Console.writeToBuffer(c, "     Renee");
                                                            c.Y = 14;
                                                            g_Console.writeToBuffer(c, "     Music");
                                                            c.X = 30;
                                                            c.Y = 16;
                                                            g_Console.writeToBuffer(c, "  \"8 Bit Retro Funk\"");
                                                            c.Y = 17;
                                                            g_Console.writeToBuffer(c, "Written By: David Renda");
                                                            if (g_dCreditsTime > 15.0)
                                                            {
                                                                Cutscene.clearScreen(g_Console);
                                                                c.X = 32;
                                                                c.Y = 7;
                                                                g_Console.writeToBuffer(c, "     Artus");
                                                                c.Y = 8;
                                                                g_Console.writeToBuffer(c, "     Jordan");
                                                                c.Y = 9;
                                                                g_Console.writeToBuffer(c, "     Nicole");
                                                                c.Y = 10;
                                                                g_Console.writeToBuffer(c, "     Renee");
                                                                c.Y = 13;
                                                                g_Console.writeToBuffer(c, "     Music");
                                                                c.X = 30;
                                                                c.Y = 15;
                                                                g_Console.writeToBuffer(c, "  \"8 Bit Retro Funk\"");
                                                                c.Y = 16;
                                                                g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                c.X = 25;
                                                                c.Y = 17;
                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                if (g_dCreditsTime > 16.0)
                                                                {
                                                                    Cutscene.clearScreen(g_Console);
                                                                    c.X = 32;
                                                                    c.Y = 7;
                                                                    g_Console.writeToBuffer(c, "     Jordan");
                                                                    c.Y = 8;
                                                                    g_Console.writeToBuffer(c, "     Nicole");
                                                                    c.Y = 9;
                                                                    g_Console.writeToBuffer(c, "     Renee");
                                                                    c.Y = 12;
                                                                    g_Console.writeToBuffer(c, "     Music");
                                                                    c.X = 30;
                                                                    c.Y = 14;
                                                                    g_Console.writeToBuffer(c, "  \"8 Bit Retro Funk\"");
                                                                    c.Y = 15;
                                                                    g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                    c.X = 25;
                                                                    c.Y = 16;
                                                                    g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                    if (g_dCreditsTime > 17.0)
                                                                    {
                                                                        Cutscene.clearScreen(g_Console);
                                                                        c.X = 32;
                                                                        c.Y = 7;
                                                                        g_Console.writeToBuffer(c, "     Nicole");
                                                                        c.Y = 8;
                                                                        g_Console.writeToBuffer(c, "     Renee");
                                                                        c.Y = 11;
                                                                        g_Console.writeToBuffer(c, "     Music");
                                                                        c.X = 30;
                                                                        c.Y = 13;
                                                                        g_Console.writeToBuffer(c, "  \"8 Bit Retro Funk\"");
                                                                        c.Y = 14;
                                                                        g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                        c.X = 25;
                                                                        c.Y = 15;
                                                                        g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                        c.X = 32;
                                                                        c.Y = 17;
                                                                        g_Console.writeToBuffer(c, "\"Retro Platforming\"");
                                                                        if (g_dCreditsTime > 18.0)
                                                                        {
                                                                            Cutscene.clearScreen(g_Console);
                                                                            c.Y = 7;
                                                                            g_Console.writeToBuffer(c, "     Renee");
                                                                            c.Y = 10;
                                                                            g_Console.writeToBuffer(c, "     Music");
                                                                            c.X = 30;
                                                                            c.Y = 12;
                                                                            g_Console.writeToBuffer(c, "  \"8 Bit Retro Funk\"");
                                                                            c.Y = 13;
                                                                            g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                            c.X = 25;
                                                                            c.Y = 14;
                                                                            g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                            c.X = 32;
                                                                            c.Y = 16;
                                                                            g_Console.writeToBuffer(c, "\"Retro Platforming\"");
                                                                            c.X = 25;
                                                                            c.Y = 17;
                                                                            g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                            if (g_dCreditsTime > 19.0)
                                                                            {
                                                                                Cutscene.clearScreen(g_Console);
                                                                                c.X = 32;
                                                                                c.Y = 9;
                                                                                g_Console.writeToBuffer(c, "     Music");
                                                                                c.X = 30;
                                                                                c.Y = 11;
                                                                                g_Console.writeToBuffer(c, "  \"8 Bit Retro Funk\"");
                                                                                c.Y = 12;
                                                                                g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                c.X = 25;
                                                                                c.Y = 13;
                                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                c.X = 32;
                                                                                c.Y = 15;
                                                                                g_Console.writeToBuffer(c, "\"Retro Platforming\"");
                                                                                c.X = 25;
                                                                                c.Y = 16;
                                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                if (g_dCreditsTime > 20.0)
                                                                                {
                                                                                    Cutscene.clearScreen(g_Console);
                                                                                    c.X = 32;
                                                                                    c.Y = 8;
                                                                                    g_Console.writeToBuffer(c, "     Music");
                                                                                    c.X = 30;
                                                                                    c.Y = 10;
                                                                                    g_Console.writeToBuffer(c, "  \"8 Bit Retro Funk\"");
                                                                                    c.Y = 11;
                                                                                    g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                    c.X = 25;
                                                                                    c.Y = 12;
                                                                                    g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                    c.X = 32;
                                                                                    c.Y = 14;
                                                                                    g_Console.writeToBuffer(c, "\"Retro Platforming\"");
                                                                                    c.X = 25;
                                                                                    c.Y = 15;
                                                                                    g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                    c.X = 32;
                                                                                    c.Y = 17;
                                                                                    g_Console.writeToBuffer(c, "\"Land of 8 Bits\"");
                                                                                    if (g_dCreditsTime > 21.0)
                                                                                    {
                                                                                        Cutscene.clearScreen(g_Console);
                                                                                        c.X = 32;
                                                                                        c.Y = 7;
                                                                                        g_Console.writeToBuffer(c, "     Music");
                                                                                        c.X = 30;
                                                                                        c.Y = 9;
                                                                                        g_Console.writeToBuffer(c, "  \"8 Bit Retro Funk\"");
                                                                                        c.Y = 10;
                                                                                        g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                        c.X = 25;
                                                                                        c.Y = 11;
                                                                                        g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                        c.X = 32;
                                                                                        c.Y = 13;
                                                                                        g_Console.writeToBuffer(c, "\"Retro Platforming\"");
                                                                                        c.X = 25;
                                                                                        c.Y = 14;
                                                                                        g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                        c.X = 32;
                                                                                        c.Y = 16;
                                                                                        g_Console.writeToBuffer(c, "\"Land of 8 Bits\"");
                                                                                        c.X = 27;
                                                                                        c.Y = 17;
                                                                                        g_Console.writeToBuffer(c, "Written By: Stephen Bennett");
                                                                                        if (g_dCreditsTime > 22.0)
                                                                                        {
                                                                                            Cutscene.clearScreen(g_Console);
                                                                                            c.X = 30;
                                                                                            c.Y = 8;
                                                                                            g_Console.writeToBuffer(c, "  \"8 Bit Retro Funk\"");
                                                                                            c.Y = 9;
                                                                                            g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                            c.X = 25;
                                                                                            c.Y = 10;
                                                                                            g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                            c.X = 32;
                                                                                            c.Y = 12;
                                                                                            g_Console.writeToBuffer(c, "\"Retro Platforming\"");
                                                                                            c.X = 25;
                                                                                            c.Y = 13;
                                                                                            g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                            c.X = 32;
                                                                                            c.Y = 15;
                                                                                            g_Console.writeToBuffer(c, "\"Land of 8 Bits\"");
                                                                                            c.X = 27;
                                                                                            c.Y = 16;
                                                                                            g_Console.writeToBuffer(c, "Written By: Stephen Bennett");
                                                                                            c.X = 25;
                                                                                            c.Y = 17;
                                                                                            g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                            if (g_dCreditsTime > 23.0)
                                                                                            {
                                                                                                Cutscene.clearScreen(g_Console);
                                                                                                c.X = 30;
                                                                                                c.Y = 7;
                                                                                                g_Console.writeToBuffer(c, "  \"8 Bit Retro Funk\"");
                                                                                                c.Y = 8;
                                                                                                g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                c.X = 25;
                                                                                                c.Y = 9;
                                                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                c.X = 32;
                                                                                                c.Y = 11;
                                                                                                g_Console.writeToBuffer(c, "\"Retro Platforming\"");
                                                                                                c.X = 25;
                                                                                                c.Y = 12;
                                                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                c.X = 32;
                                                                                                c.Y = 14;
                                                                                                g_Console.writeToBuffer(c, "\"Land of 8 Bits\"");
                                                                                                c.X = 27;
                                                                                                c.Y = 15;
                                                                                                g_Console.writeToBuffer(c, "Written By: Stephen Bennett");
                                                                                                c.X = 25;
                                                                                                c.Y = 16;
                                                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                if (g_dCreditsTime > 24.0)
                                                                                                {
                                                                                                    Cutscene.clearScreen(g_Console);
                                                                                                    c.X = 32;
                                                                                                    c.Y = 7;
                                                                                                    g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                    c.X = 25;
                                                                                                    c.Y = 8;
                                                                                                    g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                    c.X = 32;
                                                                                                    c.Y = 10;
                                                                                                    g_Console.writeToBuffer(c, "\"Retro Platforming\"");
                                                                                                    c.X = 25;
                                                                                                    c.Y = 11;
                                                                                                    g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                    c.X = 32;
                                                                                                    c.Y = 13;
                                                                                                    g_Console.writeToBuffer(c, "\"Land of 8 Bits\"");
                                                                                                    c.X = 27;
                                                                                                    c.Y = 14;
                                                                                                    g_Console.writeToBuffer(c, "Written By: Stephen Bennett");
                                                                                                    c.X = 25;
                                                                                                    c.Y = 15;
                                                                                                    g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                    c.X = 15;
                                                                                                    c.Y = 17;
                                                                                                    g_Console.writeToBuffer(c, "\"Outdoor Festival Crowd Talking Chatter B Sound Effect\"");
                                                                                                    if (g_dCreditsTime > 25.0)
                                                                                                    {
                                                                                                        Cutscene.clearScreen(g_Console);
                                                                                                        c.X = 25;
                                                                                                        c.Y = 7;
                                                                                                        g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                        c.X = 32;
                                                                                                        c.Y = 9;
                                                                                                        g_Console.writeToBuffer(c, "\"Retro Platforming\"");
                                                                                                        c.X = 25;
                                                                                                        c.Y = 10;
                                                                                                        g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                        c.X = 32;
                                                                                                        c.Y = 12;
                                                                                                        g_Console.writeToBuffer(c, "\"Land of 8 Bits\"");
                                                                                                        c.X = 27;
                                                                                                        c.Y = 13;
                                                                                                        g_Console.writeToBuffer(c, "Written By: Stephen Bennett");
                                                                                                        c.X = 25;
                                                                                                        c.Y = 14;
                                                                                                        g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                        c.X = 15;
                                                                                                        c.Y = 16;
                                                                                                        g_Console.writeToBuffer(c, "\"Outdoor Festival Crowd Talking Chatter B Sound Effect\"");
                                                                                                        c.X = 25;
                                                                                                        c.Y = 17;
                                                                                                        g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                        if (g_dCreditsTime > 26.0)
                                                                                                        {
                                                                                                            Cutscene.clearScreen(g_Console);
                                                                                                            c.X = 32;
                                                                                                            c.Y = 8;
                                                                                                            g_Console.writeToBuffer(c, "\"Retro Platforming\"");
                                                                                                            c.X = 25;
                                                                                                            c.Y = 9;
                                                                                                            g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                            c.X = 32;
                                                                                                            c.Y = 11;
                                                                                                            g_Console.writeToBuffer(c, "\"Land of 8 Bits\"");
                                                                                                            c.X = 27;
                                                                                                            c.Y = 12;
                                                                                                            g_Console.writeToBuffer(c, "Written By: Stephen Bennett");
                                                                                                            c.X = 25;
                                                                                                            c.Y = 13;
                                                                                                            g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                            c.X = 15;
                                                                                                            c.Y = 15;
                                                                                                            g_Console.writeToBuffer(c, "\"Outdoor Festival Crowd Talking Chatter B Sound Effect\"");
                                                                                                            c.X = 25;
                                                                                                            c.Y = 16;
                                                                                                            g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                            if (g_dCreditsTime > 27.0)
                                                                                                            {
                                                                                                                Cutscene.clearScreen(g_Console);
                                                                                                                c.X = 32;
                                                                                                                c.Y = 7;
                                                                                                                g_Console.writeToBuffer(c, "\"Retro Platforming\"");
                                                                                                                c.X = 25;
                                                                                                                c.Y = 8;
                                                                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                c.X = 32;
                                                                                                                c.Y = 10;
                                                                                                                g_Console.writeToBuffer(c, "\"Land of 8 Bits\"");
                                                                                                                c.X = 27;
                                                                                                                c.Y = 11;
                                                                                                                g_Console.writeToBuffer(c, "Written By: Stephen Bennett");
                                                                                                                c.X = 25;
                                                                                                                c.Y = 12;
                                                                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                c.X = 15;
                                                                                                                c.Y = 14;
                                                                                                                g_Console.writeToBuffer(c, "\"Outdoor Festival Crowd Talking Chatter B Sound Effect\"");
                                                                                                                c.X = 25;
                                                                                                                c.Y = 15;
                                                                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                c.X = 32;
                                                                                                                c.Y = 17;
                                                                                                                g_Console.writeToBuffer(c, "   \"8 Bit Surf\"");
                                                                                                                if (g_dCreditsTime > 28.0)
                                                                                                                {
                                                                                                                    Cutscene.clearScreen(g_Console);
                                                                                                                    c.X = 25;
                                                                                                                    c.Y = 7;
                                                                                                                    g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                    c.X = 32;
                                                                                                                    c.Y = 9;
                                                                                                                    g_Console.writeToBuffer(c, "\"Land of 8 Bits\"");
                                                                                                                    c.X = 27;
                                                                                                                    c.Y = 10;
                                                                                                                    g_Console.writeToBuffer(c, "Written By: Stephen Bennett");
                                                                                                                    c.X = 25;
                                                                                                                    c.Y = 11;
                                                                                                                    g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                    c.X = 15;
                                                                                                                    c.Y = 13;
                                                                                                                    g_Console.writeToBuffer(c, "\"Outdoor Festival Crowd Talking Chatter B Sound Effect\"");
                                                                                                                    c.X = 25;
                                                                                                                    c.Y = 14;
                                                                                                                    g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                    c.X = 32;
                                                                                                                    c.Y = 16;
                                                                                                                    g_Console.writeToBuffer(c, "   \"8 Bit Surf\"");
                                                                                                                    c.X = 30;
                                                                                                                    c.Y = 17;
                                                                                                                    g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                    if (g_dCreditsTime > 29.0)
                                                                                                                    {
                                                                                                                        Cutscene.clearScreen(g_Console);
                                                                                                                        c.X = 32;
                                                                                                                        c.Y = 8;
                                                                                                                        g_Console.writeToBuffer(c, "\"Land of 8 Bits\"");
                                                                                                                        c.X = 27;
                                                                                                                        c.Y = 9;
                                                                                                                        g_Console.writeToBuffer(c, "Written By: Stephen Bennett");
                                                                                                                        c.X = 25;
                                                                                                                        c.Y = 10;
                                                                                                                        g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                        c.X = 15;
                                                                                                                        c.Y = 12;
                                                                                                                        g_Console.writeToBuffer(c, "\"Outdoor Festival Crowd Talking Chatter B Sound Effect\"");
                                                                                                                        c.X = 25;
                                                                                                                        c.Y = 13;
                                                                                                                        g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                        c.X = 32;
                                                                                                                        c.Y = 15;
                                                                                                                        g_Console.writeToBuffer(c, "   \"8 Bit Surf\"");
                                                                                                                        c.X = 30;
                                                                                                                        c.Y = 16;
                                                                                                                        g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                        c.X = 25;
                                                                                                                        c.Y = 17;
                                                                                                                        g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                        if (g_dCreditsTime > 30.0)
                                                                                                                        {
                                                                                                                            Cutscene.clearScreen(g_Console);
                                                                                                                            c.X = 32;
                                                                                                                            c.Y = 7;
                                                                                                                            g_Console.writeToBuffer(c, "\"Land of 8 Bits\"");
                                                                                                                            c.X = 27;
                                                                                                                            c.Y = 8;
                                                                                                                            g_Console.writeToBuffer(c, "Written By: Stephen Bennett");
                                                                                                                            c.X = 25;
                                                                                                                            c.Y = 9;
                                                                                                                            g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                            c.X = 15;
                                                                                                                            c.Y = 11;
                                                                                                                            g_Console.writeToBuffer(c, "\"Outdoor Festival Crowd Talking Chatter B Sound Effect\"");
                                                                                                                            c.X = 25;
                                                                                                                            c.Y = 12;
                                                                                                                            g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                            c.X = 32;
                                                                                                                            c.Y = 14;
                                                                                                                            g_Console.writeToBuffer(c, "   \"8 Bit Surf\"");
                                                                                                                            c.X = 30;
                                                                                                                            c.Y = 15;
                                                                                                                            g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                            c.X = 25;
                                                                                                                            c.Y = 16;
                                                                                                                            g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                            if (g_dCreditsTime > 31.0)
                                                                                                                            {
                                                                                                                                Cutscene.clearScreen(g_Console);
                                                                                                                                c.X = 27;
                                                                                                                                c.Y = 7;
                                                                                                                                g_Console.writeToBuffer(c, "Written By: Stephen Bennett");
                                                                                                                                c.X = 25;
                                                                                                                                c.Y = 8;
                                                                                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                c.X = 15;
                                                                                                                                c.Y = 10;
                                                                                                                                g_Console.writeToBuffer(c, "\"Outdoor Festival Crowd Talking Chatter B Sound Effect\"");
                                                                                                                                c.X = 25;
                                                                                                                                c.Y = 11;
                                                                                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                c.X = 32;
                                                                                                                                c.Y = 13;
                                                                                                                                g_Console.writeToBuffer(c, "   \"8 Bit Surf\"");
                                                                                                                                c.X = 30;
                                                                                                                                c.Y = 14;
                                                                                                                                g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                c.X = 25;
                                                                                                                                c.Y = 15;
                                                                                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                c.X = 32;
                                                                                                                                c.Y = 17;
                                                                                                                                g_Console.writeToBuffer(c, "   \"8 Bit Menu\"");
                                                                                                                                if (g_dCreditsTime > 32.0)
                                                                                                                                {
                                                                                                                                    Cutscene.clearScreen(g_Console);
                                                                                                                                    c.X = 25;
                                                                                                                                    c.Y = 7;
                                                                                                                                    g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                    c.X = 15;
                                                                                                                                    c.Y = 9;
                                                                                                                                    g_Console.writeToBuffer(c, "\"Outdoor Festival Crowd Talking Chatter B Sound Effect\"");
                                                                                                                                    c.X = 25;
                                                                                                                                    c.Y = 10;
                                                                                                                                    g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                    c.X = 32;
                                                                                                                                    c.Y = 12;
                                                                                                                                    g_Console.writeToBuffer(c, "   \"8 Bit Surf\"");
                                                                                                                                    c.X = 30;
                                                                                                                                    c.Y = 13;
                                                                                                                                    g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                    c.X = 25;
                                                                                                                                    c.Y = 14;
                                                                                                                                    g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                    c.X = 32;
                                                                                                                                    c.Y = 16;
                                                                                                                                    g_Console.writeToBuffer(c, "   \"8 Bit Menu\"");
                                                                                                                                    c.X = 30;
                                                                                                                                    c.Y = 17;
                                                                                                                                    g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                    if (g_dCreditsTime > 33.0)
                                                                                                                                    {
                                                                                                                                        Cutscene.clearScreen(g_Console);
                                                                                                                                        c.X = 15;
                                                                                                                                        c.Y = 8;
                                                                                                                                        g_Console.writeToBuffer(c, "\"Outdoor Festival Crowd Talking Chatter B Sound Effect\"");
                                                                                                                                        c.X = 25;
                                                                                                                                        c.Y = 9;
                                                                                                                                        g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                        c.X = 32;
                                                                                                                                        c.Y = 11;
                                                                                                                                        g_Console.writeToBuffer(c, "   \"8 Bit Surf\"");
                                                                                                                                        c.X = 30;
                                                                                                                                        c.Y = 12;
                                                                                                                                        g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                        c.X = 25;
                                                                                                                                        c.Y = 13;
                                                                                                                                        g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                        c.X = 32;
                                                                                                                                        c.Y = 15;
                                                                                                                                        g_Console.writeToBuffer(c, "   \"8 Bit Menu\"");
                                                                                                                                        c.X = 30;
                                                                                                                                        c.Y = 16;
                                                                                                                                        g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                        c.X = 25;
                                                                                                                                        c.Y = 17;
                                                                                                                                        g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                        if (g_dCreditsTime > 34.0)
                                                                                                                                        {
                                                                                                                                            Cutscene.clearScreen(g_Console);
                                                                                                                                            c.X = 15;
                                                                                                                                            c.Y = 7;
                                                                                                                                            g_Console.writeToBuffer(c, "\"Outdoor Festival Crowd Talking Chatter B Sound Effect\"");
                                                                                                                                            c.X = 25;
                                                                                                                                            c.Y = 8;
                                                                                                                                            g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                            c.X = 32;
                                                                                                                                            c.Y = 10;
                                                                                                                                            g_Console.writeToBuffer(c, "   \"8 Bit Surf\"");
                                                                                                                                            c.X = 30;
                                                                                                                                            c.Y = 11;
                                                                                                                                            g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                            c.X = 25;
                                                                                                                                            c.Y = 12;
                                                                                                                                            g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                            c.X = 32;
                                                                                                                                            c.Y = 14;
                                                                                                                                            g_Console.writeToBuffer(c, "   \"8 Bit Menu\"");
                                                                                                                                            c.X = 30;
                                                                                                                                            c.Y = 15;
                                                                                                                                            g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                            c.X = 25;
                                                                                                                                            c.Y = 16;
                                                                                                                                            g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                            if (g_dCreditsTime > 35.0)
                                                                                                                                            {
                                                                                                                                                Cutscene.clearScreen(g_Console);
                                                                                                                                                c.X = 25;
                                                                                                                                                c.Y = 7;
                                                                                                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                                c.X = 32;
                                                                                                                                                c.Y = 9;
                                                                                                                                                g_Console.writeToBuffer(c, "   \"8 Bit Surf\"");
                                                                                                                                                c.X = 30;
                                                                                                                                                c.Y = 10;
                                                                                                                                                g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                                c.X = 25;
                                                                                                                                                c.Y = 11;
                                                                                                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                                c.X = 32;
                                                                                                                                                c.Y = 13;
                                                                                                                                                g_Console.writeToBuffer(c, "   \"8 Bit Menu\"");
                                                                                                                                                c.X = 30;
                                                                                                                                                c.Y = 14;
                                                                                                                                                g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                                c.X = 25;
                                                                                                                                                c.Y = 15;
                                                                                                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                                c.X = 32;
                                                                                                                                                c.Y = 17;
                                                                                                                                                g_Console.writeToBuffer(c, "   \"For Peace\"");
                                                                                                                                                if (g_dCreditsTime > 36.0)
                                                                                                                                                {
                                                                                                                                                    Cutscene.clearScreen(g_Console);
                                                                                                                                                    c.X = 32;
                                                                                                                                                    c.Y = 8;
                                                                                                                                                    g_Console.writeToBuffer(c, "   \"8 Bit Surf\"");
                                                                                                                                                    c.X = 30;
                                                                                                                                                    c.Y = 9;
                                                                                                                                                    g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                                    c.X = 25;
                                                                                                                                                    c.Y = 10;
                                                                                                                                                    g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                                    c.X = 32;
                                                                                                                                                    c.Y = 12;
                                                                                                                                                    g_Console.writeToBuffer(c, "   \"8 Bit Menu\"");
                                                                                                                                                    c.X = 30;
                                                                                                                                                    c.Y = 13;
                                                                                                                                                    g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                                    c.X = 25;
                                                                                                                                                    c.Y = 14;
                                                                                                                                                    g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                                    c.X = 32;
                                                                                                                                                    c.Y = 16;
                                                                                                                                                    g_Console.writeToBuffer(c, "   \"For Peace\"");
                                                                                                                                                    c.Y = 17;
                                                                                                                                                    g_Console.writeToBuffer(c, "  Written By: Ngiam");
                                                                                                                                                    if (g_dCreditsTime > 37.0)
                                                                                                                                                    {
                                                                                                                                                        Cutscene.clearScreen(g_Console);
                                                                                                                                                        c.X = 32;
                                                                                                                                                        c.Y = 7;
                                                                                                                                                        g_Console.writeToBuffer(c, "   \"8 Bit Surf\"");
                                                                                                                                                        c.X = 30;
                                                                                                                                                        c.Y = 8;
                                                                                                                                                        g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                                        c.X = 25;
                                                                                                                                                        c.Y = 9;
                                                                                                                                                        g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                                        c.X = 32;
                                                                                                                                                        c.Y = 11;
                                                                                                                                                        g_Console.writeToBuffer(c, "   \"8 Bit Menu\"");
                                                                                                                                                        c.X = 30;
                                                                                                                                                        c.Y = 12;
                                                                                                                                                        g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                                        c.X = 25;
                                                                                                                                                        c.Y = 13;
                                                                                                                                                        g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                                        c.X = 32;
                                                                                                                                                        c.Y = 15;
                                                                                                                                                        g_Console.writeToBuffer(c, "   \"For Peace\"");
                                                                                                                                                        c.Y = 16;
                                                                                                                                                        g_Console.writeToBuffer(c, "  Written By: Ngiam");
                                                                                                                                                        if (g_dCreditsTime > 38.0)
                                                                                                                                                        {
                                                                                                                                                            Cutscene.clearScreen(g_Console);
                                                                                                                                                            c.X = 30;
                                                                                                                                                            c.Y = 7;
                                                                                                                                                            g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                                            c.X = 25;
                                                                                                                                                            c.Y = 8;
                                                                                                                                                            g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                                            c.X = 32;
                                                                                                                                                            c.Y = 10;
                                                                                                                                                            g_Console.writeToBuffer(c, "   \"8 Bit Menu\"");
                                                                                                                                                            c.X = 30;
                                                                                                                                                            c.Y = 11;
                                                                                                                                                            g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                                            c.X = 25;
                                                                                                                                                            c.Y = 12;
                                                                                                                                                            g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                                            c.X = 32;
                                                                                                                                                            c.Y = 14;
                                                                                                                                                            g_Console.writeToBuffer(c, "   \"For Peace\"");
                                                                                                                                                            c.Y = 15;
                                                                                                                                                            g_Console.writeToBuffer(c, "  Written By: Ngiam");
                                                                                                                                                            c.Y = 17;
                                                                                                                                                            g_Console.writeToBuffer(c, "\"Ancient Lullaby\"");
                                                                                                                                                            if (g_dCreditsTime > 39.0)
                                                                                                                                                            {
                                                                                                                                                                Cutscene.clearScreen(g_Console);
                                                                                                                                                                c.X = 25;
                                                                                                                                                                c.Y = 7;
                                                                                                                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                                                c.X = 32;
                                                                                                                                                                c.Y = 9;
                                                                                                                                                                g_Console.writeToBuffer(c, "   \"8 Bit Menu\"");
                                                                                                                                                                c.X = 30;
                                                                                                                                                                c.Y = 10;
                                                                                                                                                                g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                                                c.X = 25;
                                                                                                                                                                c.Y = 11;
                                                                                                                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                                                c.X = 32;
                                                                                                                                                                c.Y = 13;
                                                                                                                                                                g_Console.writeToBuffer(c, "   \"For Peace\"");
                                                                                                                                                                c.Y = 14;
                                                                                                                                                                g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                c.Y = 16;
                                                                                                                                                                g_Console.writeToBuffer(c, "\"Ancient Lullaby\"");
                                                                                                                                                                c.Y = 17;
                                                                                                                                                                g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                if (g_dCreditsTime > 40.0)
                                                                                                                                                                {
                                                                                                                                                                    Cutscene.clearScreen(g_Console);
                                                                                                                                                                    c.X = 32;
                                                                                                                                                                    c.Y = 8;
                                                                                                                                                                    g_Console.writeToBuffer(c, "   \"8 Bit Menu\"");
                                                                                                                                                                    c.X = 30;
                                                                                                                                                                    c.Y = 9;
                                                                                                                                                                    g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                                                    c.X = 25;
                                                                                                                                                                    c.Y = 10;
                                                                                                                                                                    g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                                                    c.X = 32;
                                                                                                                                                                    c.Y = 12;
                                                                                                                                                                    g_Console.writeToBuffer(c, "   \"For Peace\"");
                                                                                                                                                                    c.Y = 13;
                                                                                                                                                                    g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                    c.Y = 15;
                                                                                                                                                                    g_Console.writeToBuffer(c, "\"Ancient Lullaby\"");
                                                                                                                                                                    c.Y = 16;
                                                                                                                                                                    g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                    if (g_dCreditsTime > 41.0)
                                                                                                                                                                    {
                                                                                                                                                                        Cutscene.clearScreen(g_Console);
                                                                                                                                                                        c.X = 32;
                                                                                                                                                                        c.Y = 7;
                                                                                                                                                                        g_Console.writeToBuffer(c, "   \"8 Bit Menu\"");
                                                                                                                                                                        c.X = 30;
                                                                                                                                                                        c.Y = 8;
                                                                                                                                                                        g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                                                        c.X = 25;
                                                                                                                                                                        c.Y = 9;
                                                                                                                                                                        g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                                                        c.X = 32;
                                                                                                                                                                        c.Y = 11;
                                                                                                                                                                        g_Console.writeToBuffer(c, "   \"For Peace\"");
                                                                                                                                                                        c.Y = 12;
                                                                                                                                                                        g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                        c.Y = 14;
                                                                                                                                                                        g_Console.writeToBuffer(c, "\"Ancient Lullaby\"");
                                                                                                                                                                        c.Y = 15;
                                                                                                                                                                        g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                        if (g_dCreditsTime > 42.0)
                                                                                                                                                                        {
                                                                                                                                                                            Cutscene.clearScreen(g_Console);
                                                                                                                                                                            c.X = 30;
                                                                                                                                                                            c.Y = 7;
                                                                                                                                                                            g_Console.writeToBuffer(c, "Written By: David Renda");
                                                                                                                                                                            c.X = 25;
                                                                                                                                                                            c.Y = 8;
                                                                                                                                                                            g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                                                            c.X = 32;
                                                                                                                                                                            c.Y = 10;
                                                                                                                                                                            g_Console.writeToBuffer(c, "   \"For Peace\"");
                                                                                                                                                                            c.Y = 11;
                                                                                                                                                                            g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                            c.Y = 13;
                                                                                                                                                                            g_Console.writeToBuffer(c, "\"Ancient Lullaby\"");
                                                                                                                                                                            c.Y = 14;
                                                                                                                                                                            g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                            if (g_dCreditsTime > 43.0)
                                                                                                                                                                            {
                                                                                                                                                                                Cutscene.clearScreen(g_Console);
                                                                                                                                                                                c.X = 25;
                                                                                                                                                                                c.Y = 7;
                                                                                                                                                                                g_Console.writeToBuffer(c, "From: https://www.fesliyanstudios.com");
                                                                                                                                                                                c.X = 32;
                                                                                                                                                                                c.Y = 9;
                                                                                                                                                                                g_Console.writeToBuffer(c, "   \"For Peace\"");
                                                                                                                                                                                c.Y = 10;
                                                                                                                                                                                g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                                c.Y = 12;
                                                                                                                                                                                g_Console.writeToBuffer(c, "\"Ancient Lullaby\"");
                                                                                                                                                                                c.Y = 13;
                                                                                                                                                                                g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                                if (g_dCreditsTime > 44.0)
                                                                                                                                                                                {
                                                                                                                                                                                    Cutscene.clearScreen(g_Console);                                      
                                                                                                                                                                                    c.X = 32;
                                                                                                                                                                                    c.Y = 8;
                                                                                                                                                                                    g_Console.writeToBuffer(c, "   \"For Peace\"");
                                                                                                                                                                                    c.Y = 9;
                                                                                                                                                                                    g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                                    c.Y = 11;
                                                                                                                                                                                    g_Console.writeToBuffer(c, "\"Ancient Lullaby\"");
                                                                                                                                                                                    c.Y = 12;
                                                                                                                                                                                    g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                                    if (g_dCreditsTime > 45.0)
                                                                                                                                                                                    {
                                                                                                                                                                                        Cutscene.clearScreen(g_Console);
                                                                                                                                                                                        c.X = 32;
                                                                                                                                                                                        c.Y = 7;
                                                                                                                                                                                        g_Console.writeToBuffer(c, "   \"For Peace\"");
                                                                                                                                                                                        c.Y = 8;
                                                                                                                                                                                        g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                                        c.Y = 10;
                                                                                                                                                                                        g_Console.writeToBuffer(c, "\"Ancient Lullaby\"");
                                                                                                                                                                                        c.Y = 11;
                                                                                                                                                                                        g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                                        if (g_dCreditsTime > 46.0)
                                                                                                                                                                                        {
                                                                                                                                                                                            Cutscene.clearScreen(g_Console);
                                                                                                                                                                                            c.X = 32;
                                                                                                                                                                                            c.Y = 7;
                                                                                                                                                                                            g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                                            c.Y = 9;
                                                                                                                                                                                            g_Console.writeToBuffer(c, "\"Ancient Lullaby\"");
                                                                                                                                                                                            c.Y = 10;
                                                                                                                                                                                            g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                                            c.X = 25;
                                                                                                                                                                                            c.Y = 17;
                                                                                                                                                                                            g_Console.writeToBuffer(c, "Thank you for playing our game!");
                                                                                                                                                                                            if (g_dCreditsTime > 47.0)
                                                                                                                                                                                            {
                                                                                                                                                                                                Cutscene.clearScreen(g_Console);
                                                                                                                                                                                                c.X = 32;
                                                                                                                                                                                                c.Y = 8;
                                                                                                                                                                                                g_Console.writeToBuffer(c, "\"Ancient Lullaby\"");
                                                                                                                                                                                                c.Y = 9;
                                                                                                                                                                                                g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                                                c.X = 25;
                                                                                                                                                                                                c.Y = 16;
                                                                                                                                                                                                g_Console.writeToBuffer(c, "Thank you for playing our game!");
                                                                                                                                                                                                if (g_dCreditsTime > 48.0)
                                                                                                                                                                                                {
                                                                                                                                                                                                    Cutscene.clearScreen(g_Console);
                                                                                                                                                                                                    c.X = 32;
                                                                                                                                                                                                    c.Y = 7;
                                                                                                                                                                                                    g_Console.writeToBuffer(c, "\"Ancient Lullaby\"");
                                                                                                                                                                                                    c.Y = 8;
                                                                                                                                                                                                    g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                                                    c.X = 25;
                                                                                                                                                                                                    c.Y = 15;
                                                                                                                                                                                                    g_Console.writeToBuffer(c, "Thank you for playing our game!");
                                                                                                                                                                                                    if (g_dCreditsTime > 49.0)
                                                                                                                                                                                                    {
                                                                                                                                                                                                        Cutscene.clearScreen(g_Console);
                                                                                                                                                                                                        c.X = 32;
                                                                                                                                                                                                        c.Y = 7;
                                                                                                                                                                                                        g_Console.writeToBuffer(c, " Written By: Ngiam");
                                                                                                                                                                                                        c.X = 25;
                                                                                                                                                                                                        c.Y = 14;
                                                                                                                                                                                                        g_Console.writeToBuffer(c, "Thank you for playing our game!");
                                                                                                                                                                                                        if (g_dCreditsTime > 50.0)
                                                                                                                                                                                                        {
                                                                                                                                                                                                            Cutscene.clearScreen(g_Console);
                                                                                                                                                                                                            c.Y = 13;
                                                                                                                                                                                                            g_Console.writeToBuffer(c, "Thank you for playing our game!");

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
    while (orphanage_music == false)
    {
        PlaySound(TEXT("Retro Platforming VERY SLOW.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        orphanage_music = true;
    }
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

    COORD c;
    if (g_dProtestTime > 83.6)
    {
        g_eGameState = S_Protest_Area;
    }
    processUserInput();
    moveCharacter();
}
void Protest_Area_Animation()
{
    game_music = false;
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
        while (null_music == false)
        {
            PlaySound(NULL, NULL, SND_ASYNC);
            null_music = true;
        }
        Cutscene.drawgrid(g_Console, 62, 4, '-');
        if (g_dProtestTime > 0.6)
        {
            Cutscene.cleargrid(g_Console, 62, 4);
            Cutscene.drawgrid(g_Console, 62, 5, '\\');
            if (g_dProtestTime > 0.9)
            {
                Cutscene.drawgrid(g_Console, 62, 4,'R');
                if (g_dProtestTime > 1.2)
                {
                    Cutscene.cleargrid(g_Console, 62, 4);
                    Cutscene.drawgrid(g_Console, 63, 4,'R');
                    if (g_dProtestTime > 1.5)
                    {
                        Cutscene.cleargrid(g_Console, 63, 4);
                        Cutscene.drawgrid(g_Console, 63, 5,'R');
                        if (g_dProtestTime > 1.8)
                        {
                            Cutscene.cleargrid(g_Console, 63, 5);
                            Cutscene.drawgrid(g_Console, 63, 6,'R');
                            if (g_dProtestTime > 2.1)
                            {
                                Cutscene.cleargrid(g_Console, 63, 6);
                                Cutscene.drawgrid(g_Console, 63, 7,'R');
                                if (g_dProtestTime > 2.4)
                                {
                                    Cutscene.cleargrid(g_Console, 63, 7);
                                    Cutscene.drawgrid(g_Console, 62, 8,'R');
                                    if (g_dProtestTime > 2.7)
                                    {
                                        Cutscene.cleargrid(g_Console, 62, 8);
                                        Cutscene.drawgrid(g_Console, 60, 8,'R');
                                        if (g_dProtestTime > 3.0)
                                        {
                                            Cutscene.cleargrid(g_Console, 60, 8);
                                            Cutscene.drawgrid(g_Console, 57, 8,'R');
                                            if (g_dProtestTime > 3.3)
                                            {
                                                Cutscene.cleargrid(g_Console, 57, 8);
                                                Cutscene.drawgrid(g_Console, 54, 8,'R');
                                                if (g_dProtestTime > 3.6)
                                                {
                                                    Cutscene.cleargrid(g_Console, 54, 8);
                                                    Cutscene.drawgrid(g_Console, 51, 8,'R');
                                                    if (g_dProtestTime > 3.9)
                                                    {
                                                        Cutscene.cleargrid(g_Console, 51, 8);
                                                        Cutscene.drawgrid(g_Console, 48, 8,'R');
                                                        if (g_dProtestTime > 4.2)
                                                        {
                                                            Cutscene.cleargrid(g_Console, 48, 8);
                                                            Cutscene.drawgrid(g_Console, 45, 8,'R');
                                                            if (g_dProtestTime > 4.5)
                                                            {
                                                                Cutscene.cleargrid(g_Console, 45, 8);
                                                                Cutscene.drawgrid(g_Console, 42, 8,'R');
                                                                if (g_dProtestTime > 4.8)
                                                                {
                                                                    Cutscene.cleargrid(g_Console, 42, 8);
                                                                    Cutscene.drawgrid(g_Console, 39, 8,'R');
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
                                                                                                                        Cutscene.drawgrid(g_Console, 42, 8,'R');
                                                                                                                        if (g_dProtestTime > 74.3)
                                                                                                                        {
                                                                                                                            Cutscene.cleargrid(g_Console, 42, 8);
                                                                                                                            Cutscene.drawgrid(g_Console, 45, 8,'R');
                                                                                                                            if (g_dProtestTime > 74.6)
                                                                                                                            {
                                                                                                                                Cutscene.cleargrid(g_Console, 45, 8);
                                                                                                                                Cutscene.drawgrid(g_Console, 48, 8,'R');
                                                                                                                                if (g_dProtestTime > 74.9)
                                                                                                                                {
                                                                                                                                    Cutscene.cleargrid(g_Console, 48, 8);
                                                                                                                                    Cutscene.drawgrid(g_Console, 51, 8,'R');
                                                                                                                                    if (g_dProtestTime > 75.2)
                                                                                                                                    {
                                                                                                                                        Cutscene.cleargrid(g_Console, 51, 8);
                                                                                                                                        Cutscene.drawgrid(g_Console, 54, 8,'R');
                                                                                                                                        if (g_dProtestTime > 75.5)
                                                                                                                                        {
                                                                                                                                            Cutscene.cleargrid(g_Console, 54, 8);
                                                                                                                                            Cutscene.drawgrid(g_Console, 57, 8,'R');
                                                                                                                                            if (g_dProtestTime > 75.8)
                                                                                                                                            {
                                                                                                                                                Cutscene.cleargrid(g_Console, 57, 8);
                                                                                                                                                Cutscene.drawgrid(g_Console, 60, 8,'R');
                                                                                                                                                if (g_dProtestTime > 76.1)
                                                                                                                                                {
                                                                                                                                                    Cutscene.cleargrid(g_Console, 60, 8);
                                                                                                                                                    Cutscene.drawgrid(g_Console, 62, 8,'R');
                                                                                                                                                    if (g_dProtestTime > 76.4)
                                                                                                                                                    {
                                                                                                                                                        Cutscene.cleargrid(g_Console, 62, 8);
                                                                                                                                                        Cutscene.drawgrid(g_Console, 63, 7,'R');
                                                                                                                                                        if (g_dProtestTime > 76.7)
                                                                                                                                                        {
                                                                                                                                                            Cutscene.cleargrid(g_Console, 63, 7);
                                                                                                                                                            Cutscene.drawgrid(g_Console, 63, 6,'R');
                                                                                                                                                            if (g_dProtestTime > 77.0)
                                                                                                                                                            {
                                                                                                                                                                Cutscene.cleargrid(g_Console, 63, 6);
                                                                                                                                                                Cutscene.drawgrid(g_Console, 63, 5,'R');
                                                                                                                                                                if (g_dProtestTime > 77.3)
                                                                                                                                                                {
                                                                                                                                                                    Cutscene.cleargrid(g_Console, 63, 5);
                                                                                                                                                                    Cutscene.drawgrid(g_Console, 63, 4,'R');
                                                                                                                                                                    if (g_dProtestTime > 77.6)
                                                                                                                                                                    {
                                                                                                                                                                        Cutscene.cleargrid(g_Console, 63, 4);
                                                                                                                                                                        Cutscene.drawgrid(g_Console, 62, 4,'R');
                                                                                                                                                                        if (g_dProtestTime > 77.9)
                                                                                                                                                                        {
                                                                                                                                                                            Cutscene.cleargrid(g_Console, 63, 4);
                                                                                                                                                                            Cutscene.drawgrid(g_Console, 62, 4,'R');
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
                                                                                                                                                                                                    while (speech_se == false)
                                                                                                                                                                                                    {
                                                                                                                                                                                                        PlaySound(TEXT("Crowd Chattering.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                                                                                                                                                                                                        speech_se = true;
                                                                                                                                                                                                    }
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
                                                                                                                                                                                                                                                PlaySound(NULL, NULL, NULL);
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
        g_eGameState = S_Dungeon_Cell;
        g_sChar.m_cLocation.X = 30;
        g_sChar.m_cLocation.Y = 9;
    }
    processUserInput();
}
void Dungeon_Cell_Animation()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.dungeon_cell(g_Console);
    COORD c; COORD d;
    c.X = 13;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 6;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 4;
    c.Y = 15;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 6;
    c.Y = 18;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 13;
    c.Y = 20;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);


    c.X = 66;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 73;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 75;
    c.Y = 15;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    //skull correct
    c.X = 73;
    c.Y = 18;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 66;
    c.Y = 20;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);

    c.X = 23;
    c.Y = 21;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 56;
    c.Y = 21;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 39;
    c.Y = 22;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);

    c.X = 5;
    c.Y = 26;
    d.X = 5;
    d.Y = 27;
    //drawing Robert
    Cutscene.drawgridW(g_Console, 40, 13, (char)1);
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
                                                    Cutscene.drawgridW(g_Console, 38, 13, (char)1);
                                                    if (g_dDungeonTime > 10.4)
                                                    {
                                                        Cutscene.cleargrid(g_Console, 18, 5);
                                                        Cutscene.cleargrid(g_Console, 38, 13);
                                                        Cutscene.drawgrid(g_Console, 21, 5, (char)12);
                                                        Cutscene.drawgridW(g_Console, 36, 13, (char)1);
                                                        if (g_dDungeonTime > 10.7)
                                                        {
                                                            Cutscene.cleargrid(g_Console, 21, 5);
                                                            Cutscene.cleargrid(g_Console, 36, 13);
                                                            Cutscene.drawgrid(g_Console, 24, 5, (char)12);
                                                            Cutscene.drawgridW(g_Console, 34, 13, (char)1);
                                                            if (g_dDungeonTime > 11.0)
                                                            {
                                                                Cutscene.cleargrid(g_Console, 24, 5);
                                                                Cutscene.cleargrid(g_Console, 34, 13);
                                                                Cutscene.drawgrid(g_Console, 27, 5, (char)12);
                                                                Cutscene.drawgridW(g_Console, 32, 13, (char)1);
                                                                if (g_dDungeonTime > 11.3)
                                                                {
                                                                    Cutscene.cleargrid(g_Console, 27, 5);
                                                                    Cutscene.cleargrid(g_Console, 32, 13);
                                                                    Cutscene.drawgrid(g_Console, 30, 5, (char)12);
                                                                    Cutscene.drawgridW(g_Console, 30, 13, (char)1);
                                                                    if (g_dDungeonTime > 11.6)
                                                                    {
                                                                        Cutscene.cleargrid(g_Console, 30, 5);
                                                                        Cutscene.cleargrid(g_Console, 30, 13);
                                                                        Cutscene.drawgrid(g_Console, 30, 7, (char)12);
                                                                        Cutscene.drawgridW(g_Console, 30, 11, (char)1);
                                                                        if (g_dDungeonTime > 11.9)
                                                                        {
                                                                            Cutscene.cleargrid(g_Console, 30, 11);
                                                                            Cutscene.drawgridW(g_Console, 30, 9, (char)1);
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
                                                                                                g_Console.writeToBuffer(c, "Ell: Be careful... I'll be waiting for you!", 0x0F, 100);
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
    COORD c;
    if (g_dPathTime > 4.5)
    {
        g_sTutEnemy.fight = true;
        g_eGameState = S_BattleScreen;
    }
    processUserInput();
}
void Path_Area_Animation()
{
    while (game_music == false)
    {
        PlaySound(TEXT("8 Bit Surf.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        game_music = true;
    }
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
        g_sChar.animationPlayed = true;
        g_eGameState = S_IAF3;
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
    Cutscene.drawgrid(g_Console, 40, 6, (char)12);
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
        g_dMedicalTime = 0.0;
        g_eGameState = S_Medical_Facility_Animation;
    }
    processUserInput();
}
void Medical_Fight_Animation()
{
    PlaySound(NULL, NULL , NULL);
    game_music = false;
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.insideMedicalFacility(g_Console);
    COORD c;
    renderCharacter(); 
    c.X = 5;
    c.Y = 26;
    Cutscene.drawgridW(g_Console, 34, 12, (char)1); //Robert (Hero)
    Cutscene.drawgrid(g_Console, 34, 13, (char)12); //Ell

    Cutscene.drawPatients(g_Console, 36, 12, (char)12); //Patient 1
    Cutscene.drawPatients(g_Console, 36, 9, (char)12); //Patient 2
    Cutscene.drawPatients(g_Console, 36, 15, (char)12); //Patient 3
    Cutscene.drawPatients(g_Console, 46, 15, (char)12); //Patient 4
    Cutscene.drawPatients(g_Console, 46, 9, (char)12); //Patient 5
    Cutscene.drawPatients(g_Console, 56, 15, (char)12); //Patient 6
    Cutscene.drawPatients(g_Console, 56, 9, (char)12); //Patient 7
    Cutscene.drawPatients(g_Console, 23, 13, (char)12); //nurse

    if (g_dMedicalFightTime > 0.6)
    {
        g_Console.writeToBuffer(c, "Patient 1: Thank you so much for the medicine!", 0x0F, 100);
        if (g_dMedicalFightTime > 3.6)
        {
            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
            //patient 2 walks to hero
            Cutscene.cleargrid(g_Console, 36, 9);
            Cutscene.drawPatients(g_Console, 36, 10, (char)12); //Patient 2
            if (g_dMedicalFightTime > 3.9)
            {
                Cutscene.cleargrid(g_Console, 36, 10);
                Cutscene.drawPatients(g_Console, 35, 11, (char)12);
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
                        Cutscene.drawPatients(g_Console, 35, 14, (char)12);
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
                                Cutscene.drawPatients(g_Console, 41, 14, (char)12);
                                if (g_dMedicalFightTime > 10.8)
                                {
                                    Cutscene.cleargrid(g_Console, 41, 14);
                                    Cutscene.drawPatients(g_Console, 36, 13, (char)12);
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
                                            Cutscene.drawPatients(g_Console, 41, 10, (char)12);
                                            if (g_dMedicalFightTime > 14.4)
                                            {
                                                Cutscene.cleargrid(g_Console, 41, 10);
                                                Cutscene.drawPatients(g_Console, 37, 11, (char)12);
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
                                                            Cutscene.drawPatients(g_Console, 51, 14, (char)12);
                                                            Cutscene.drawPatients(g_Console, 51, 10, (char)12);
                                                            if (g_dMedicalFightTime > 21.0)
                                                            {
                                                                Cutscene.cleargrid(g_Console, 51, 14);
                                                                Cutscene.cleargrid(g_Console, 51, 10);
                                                                Cutscene.drawPatients(g_Console, 46, 14, (char)12);
                                                                Cutscene.drawPatients(g_Console, 46, 11, (char)12);
                                                                if (g_dMedicalFightTime > 21.3)
                                                                {
                                                                    Cutscene.cleargrid(g_Console, 46, 14);
                                                                    Cutscene.cleargrid(g_Console, 46, 11);
                                                                    Cutscene.drawPatients(g_Console, 41, 14, (char)12);
                                                                    Cutscene.drawPatients(g_Console, 41, 12, (char)12);
                                                                    if (g_dMedicalFightTime > 21.6)
                                                                    {
                                                                        Cutscene.cleargrid(g_Console, 41, 14);
                                                                        Cutscene.cleargrid(g_Console, 41, 12);
                                                                        Cutscene.drawPatients(g_Console, 37, 14, (char)12);
                                                                        Cutscene.drawPatients(g_Console, 38, 12, (char)12);
                                                                        if (g_dMedicalFightTime > 21.9)
                                                                        {
                                                                            g_Console.writeToBuffer(c, "Patient 6: Why do you have so much medicine?", 0x0F, 100);
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
                                                                                    Cutscene.drawPatients(g_Console, 27, 14, (char)12);
                                                                                    if (g_dMedicalFightTime > 28.2)
                                                                                    {
                                                                                        Cutscene.cleargrid(g_Console, 27, 14);
                                                                                        Cutscene.drawPatients(g_Console, 30, 15, (char)12);
                                                                                        if (g_dMedicalFightTime > 28.5)
                                                                                        {
                                                                                            Cutscene.cleargrid(g_Console, 30, 15);
                                                                                            Cutscene.drawPatients(g_Console, 33, 15, (char)12);
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
        g_dMedicalTime = 0.0;
        g_sMutantWasp.fight = true;
        g_eGameState = S_BattleScreen;
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
    Cutscene.drawgridW(g_Console, 34, 12, (char)1); //Robert (Hero)
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
        g_dDungeonTime = 0.0;
        g_eGameState = S_Dungeon_Cell_Animation;
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
    Cutscene.drawgridW(g_Console, 34, 12, (char)1); //Robert (Hero)
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
                            Cutscene.drawgridW(g_Console, 33, 12, (char)1);
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
    PlaySound(NULL, NULL, NULL);
    stealth_music = false;
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
                                                                                            g_Console.writeToBuffer(c, "Robert: It seems like Mayor Raymond was the mastermind", 0x0F);
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

    if (g_dBossTime > 48.9)
    {
        g_sRaymondBoss.fight = true;
        g_eGameState = S_BattleScreen;
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
    Cutscene.drawgridW(g_Console, 40, 21, (char)1); //Robert
    Cutscene.drawgrid(g_Console, 40, 3, 'R'); //Raymond
    if (g_dBossTime > 1)
    {
        g_Console.writeToBuffer(c, "Raymond: It seems that the person I have been searching for", 0x0F);
        g_Console.writeToBuffer(d, "         came to me instead.", 0x0F);
        g_sChar.nextDialogue++;

        if (g_dBossTime > 5)
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
                                                                                Cutscene.drawgrid(g_Console, 53, 21, 'R');
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
                                                                                                                Cutscene.drawgridW(g_Console, 39, 21, (char)1);
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

void Update_Boss_Room_Mid_Animation()
{
    if (g_dBossMiddleTime > 11.2)
    {
        g_eGameState = S_phase2Battle;
    }
    processUserInput();
}
void Boss_Room_Mid_Animation()
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
    Cutscene.drawgrid(g_Console, 41, 21, 'R'); //Raymond
    if (g_dBossMiddleTime > 1)
    {
        Cutscene.cleargrid(g_Console, 41, 21);
        Cutscene.drawgrid(g_Console, 42, 21, 'R');
        g_Console.writeToBuffer(c, "Raymond: ...", 0x0F);
        if (g_dBossMiddleTime > 3)
        {
            Cutscene.cleargrid(g_Console, 41, 21);
            Cutscene.drawgrid(g_Console, 42, 21, 'R');
            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
            g_Console.writeToBuffer(c, "Raymond: This is no fun at all for such an interesting opponent...", 0x0F);
            if (g_dBossMiddleTime > 6)
            {
                Cutscene.cleargrid(g_Console, 42, 21);
                Cutscene.drawgrid(g_Console, 43, 21, 'R');
                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                if (g_dBossMiddleTime > 6.3)
                {
                    Cutscene.cleargrid(g_Console, 43, 21);
                    Cutscene.drawgrid(g_Console, 45, 21, 'R');
                    if (g_dBossMiddleTime > 6.6)
                    {
                        Cutscene.cleargrid(g_Console, 45, 21);
                        Cutscene.drawgrid(g_Console, 48, 21, 'R');
                        if (g_dBossMiddleTime > 6.9)
                        {
                            Cutscene.cleargrid(g_Console, 48, 21);
                            Cutscene.drawgrid(g_Console, 52, 21, 'R');
                            if (g_dBossMiddleTime > 7.2)
                            {
                                Cutscene.cleargrid(g_Console, 52, 21);
                                Cutscene.drawgrid(g_Console, 56, 21, 'R');
                                if (g_dBossMiddleTime > 7.5)
                                {
                                    Cutscene.cleargrid(g_Console, 56, 21);
                                    Cutscene.drawgrid(g_Console, 60, 21, 'R');
                                    if (g_dBossMiddleTime > 7.8)
                                    {
                                        Cutscene.cleargrid(g_Console, 60, 21);
                                        Cutscene.drawgrid(g_Console, 64, 21, 'R');
                                        if (g_dBossMiddleTime > 8.1)
                                        {
                                            g_Console.writeToBuffer(c, "Raymond: Come Robert! Let us have this dance of a duel!!", 0x0F);
                                            if (g_dBossMiddleTime > 11.1)
                                            {
                                                Cutscene.cleargrid(g_Console, 64, 21);
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

void Update_Boss_End_Animation()
{
    if (g_dBossEndTime > 33)
    {
        g_dCreditsTime = 5.2;
        g_eGameState = S_Credits;
    }
    processUserInput();
}
void Boss_End_Animation()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.Battle_Screen(g_Console);
    COORD c;
    COORD d;
    COORD e;
    COORD f;
    //renderCharacter();
    c.X = 5;
    c.Y = 26;
    d.X = 5;
    d.Y = 27;
    e.X = 23;
    e.Y = 12;
    f.X = 32;
    f.Y = 14;
    
    if (g_dBossMiddleTime > 1)
    {
        g_Console.writeToBuffer(c, "And so... Raymond was defeated.", 0x0F);
        if (g_dBossMiddleTime > 4)
        {
            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
            g_Console.writeToBuffer(c, "The people of the state cheered in unison.", 0x0F);
            if (g_dBossMiddleTime > 8)
            {
                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                g_Console.writeToBuffer(c, "Robert was elected to become the next President, ", 0x0F);
                g_Console.writeToBuffer(d, "where he would solve the people's issues with ease and passion.", 0x0F);
                if (g_dBossMiddleTime > 12)
                {
                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                    g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                    g_Console.writeToBuffer(c, "Though there was still a small resistance amongst the people, ", 0x0F);
                    g_Console.writeToBuffer(d, "life had majorly improved for everyone. ", 0x0F);
                    if (g_dBossMiddleTime > 16)
                    {
                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                        g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                        g_Console.writeToBuffer(c, "Now with Robert controlling the people's hearts and minds alike,", 0x0F);
                        g_Console.writeToBuffer(d, "he was sure to achieve his goal...", 0x0F);
                        if (g_dBossMiddleTime > 20)
                        {
                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                            g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                            g_Console.writeToBuffer(c, "At least that was what he thought...", 0x0F);
                            g_Console.writeToBuffer(d, "His heart had been lured too deep with greed...", 0x0F);
                            if (g_dBossMiddleTime > 23)
                            {
                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                g_Console.writeToBuffer(d, "                                                                                                     ", 0x00, 100);
                                g_Console.writeToBuffer(c, "And so comes to the end of Robert's Rescue...", 0x0F);
                                if (g_dBossMiddleTime > 27)
                                {
                                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                    rMap.initialise(g_Console);
                                    g_Console.writeToBuffer(e, "R o b e r t 's   R e s c u e   2", 0x0F);
                                    if (g_dBossMiddleTime > 30)
                                    {
                                        g_Console.writeToBuffer(f, "=Coming Soon?=", 0x0F);
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

void Update_Presentation_Animation()
{
    if (g_dPresentationTime > 11.2)
    {
        g_eGameState = S_Boss_Battle_Room;
    }
    processUserInput();
}
void Presentation_Animation()
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
    Cutscene.drawgridW(g_Console, 39, 21, (char)1); //Robert
    Cutscene.drawgrid(g_Console, 41, 21, 'R'); //Raymond
    if (g_dPresentationTime > 1)
    {
        Cutscene.cleargrid(g_Console, 41, 21);
        Cutscene.drawgrid(g_Console, 42, 21, 'R');
        g_Console.writeToBuffer(c, "Raymond: ...", 0x0F);
        if (g_dPresentationTime > 3)
        {
            Cutscene.cleargrid(g_Console, 41, 21);
            Cutscene.drawgrid(g_Console, 42, 21, 'R');
            g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
            g_Console.writeToBuffer(c, "Raymond: You're finally awake Robert! Oh how I've been waiting!!", 0x0F);
            if (g_dPresentationTime > 6)
            {
                Cutscene.cleargrid(g_Console, 42, 21);
                Cutscene.drawgrid(g_Console, 43, 21, 'R');
                g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                if (g_dPresentationTime > 6.3)
                {
                    Cutscene.cleargrid(g_Console, 43, 21);
                    Cutscene.drawgrid(g_Console, 45, 21, 'R');
                    if (g_dPresentationTime > 6.6)
                    {
                        Cutscene.cleargrid(g_Console, 45, 21);
                        Cutscene.drawgrid(g_Console, 48, 21, 'R');
                        if (g_dPresentationTime > 6.9)
                        {
                            Cutscene.cleargrid(g_Console, 48, 21);
                            Cutscene.drawgrid(g_Console, 52, 21, 'R');
                            if (g_dPresentationTime > 7.2)
                            {
                                Cutscene.cleargrid(g_Console, 52, 21);
                                Cutscene.drawgrid(g_Console, 56, 21, 'R');
                                if (g_dPresentationTime > 7.5)
                                {
                                    Cutscene.cleargrid(g_Console, 56, 21);
                                    Cutscene.drawgrid(g_Console, 60, 21, 'R');
                                    if (g_dPresentationTime > 7.8)
                                    {
                                        Cutscene.cleargrid(g_Console, 60, 21);
                                        Cutscene.drawgrid(g_Console, 64, 21, 'R');
                                        if (g_dPresentationTime > 8.1)
                                        {
                                            g_Console.writeToBuffer(c, "Raymond: Come Robert! Let us have this unforgettable ddance of a duel!!", 0x0F);
                                            if (g_dPresentationTime > 11.1)
                                            {
                                                Cutscene.cleargrid(g_Console, 64, 21);
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

void Update_slashGuard()
{
    if (g_dslashGuard > 3)
    {
        //g_eGameState = S_GAME;
    }
    //processUserInput();
}
void slashGuard()
{
    //rMap.initialise(g_Console);
    //rMap.Border(g_Console);
    COORD c;
    //renderCharacter();
    Sprites.drawGuard(g_Console, 0);
    Cutscene.drawgrid(g_Console, 68, 5, '/');
    //next
    if (g_dslashGuard > 0.05)
    {
        Cutscene.drawgrid(g_Console, 67, 6, '|');
        if (g_dslashGuard > 0.10)
        {
            Cutscene.drawgrid(g_Console, 66, 6, '_');
            Cutscene.drawgrid(g_Console, 65, 7, '/');
            Cutscene.drawgrid(g_Console, 66, 7, '/');
            if (g_dslashGuard > 0.15)
            {
                Cutscene.drawgrid(g_Console, 64, 7, '_');
                Cutscene.drawgrid(g_Console, 63, 8, '/');
                Cutscene.drawgrid(g_Console, 64, 8, '/');
                if (g_dslashGuard > 0.20)
                {
                    Cutscene.drawgrid(g_Console, 62, 8, '_');
                    Cutscene.drawgrid(g_Console, 61, 9, '/');
                    Cutscene.drawgrid(g_Console, 62, 9, '/');
                    if (g_dslashGuard > 0.25)
                    {
                        Cutscene.drawgrid(g_Console, 60, 9, '_');
                        Cutscene.drawgrid(g_Console, 59, 10, '/');
                        Cutscene.drawgrid(g_Console, 60, 10, '/');
                        if (g_dslashGuard > 0.30)
                        {
                            Cutscene.drawgrid(g_Console, 58, 10, '_');
                            Cutscene.drawgrid(g_Console, 57, 11, '/');
                            Cutscene.drawgrid(g_Console, 58, 11, '/');
                            if (g_dslashGuard > 0.35)
                            {
                                Cutscene.drawgrid(g_Console, 56, 11, '_');
                                if (g_dslashGuard > 0.40)
                                {
                                    Cutscene.drawgrid(g_Console, 55, 12, '/');
                                    if (g_dslashGuard > 0.45)
                                    {
                                        Cutscene.drawgrid(g_Console, 54, 12, '_');
                                        if (g_dslashGuard > 0.50)
                                        {
                                            Cutscene.drawgrid(g_Console, 53, 12, '_');
                                            Cutscene.cleargrid(g_Console, 68, 5);
                                            if (g_dslashGuard > 0.55)
                                            {
                                                Cutscene.cleargrid(g_Console, 67, 6);
                                                if (g_dslashGuard > 0.60)
                                                {
                                                    Cutscene.drawgridG(g_Console, 66, 6, ' ');
                                                    Cutscene.drawgridG(g_Console, 65, 7, ' ');
                                                    Cutscene.drawgridG(g_Console, 66, 7, ' ');
                                                    if (g_dslashGuard > 0.65)
                                                    {
                                                        Cutscene.drawgridG(g_Console, 64, 7, ' ');
                                                        Cutscene.drawgridG(g_Console, 63, 8, '_');
                                                        Cutscene.drawgridG(g_Console, 64, 8, '_');
                                                        if (g_dslashGuard > 0.70)
                                                        {
                                                            Cutscene.drawgridG(g_Console, 62, 8, '_');
                                                            Cutscene.drawgrid(g_Console, 61, 9, ' ');
                                                            Cutscene.drawgrid(g_Console, 62, 9, ' ');
                                                            if (g_dslashGuard > 0.75)
                                                            {
                                                                Cutscene.drawgrid(g_Console, 60, 9, ' ');
                                                                Cutscene.drawgrid(g_Console, 59, 10, ' ');
                                                                Cutscene.drawgrid(g_Console, 60, 10, ' ');
                                                                if (g_dslashGuard > 0.80)
                                                                {
                                                                    Cutscene.drawgrid(g_Console, 58, 10, ' ');
                                                                    Cutscene.drawgridG(g_Console, 57, 11, '|');
                                                                    Cutscene.drawgrid(g_Console, 58, 11, ' ');
                                                                    if (g_dslashGuard > 0.85)
                                                                    {
                                                                        Cutscene.cleargrid(g_Console, 56, 11);
                                                                        if (g_dslashGuard > 0.90)
                                                                        {
                                                                            Cutscene.cleargrid(g_Console, 55, 12);
                                                                            if (g_dslashGuard > 0.95)
                                                                            {
                                                                                Cutscene.cleargrid(g_Console, 54, 12);
                                                                                if (g_dslashGuard > 1.00)
                                                                                {
                                                                                    Cutscene.cleargrid(g_Console, 53, 12);
                                                                                    if (g_dslashGuard > 1.05)
                                                                                    {
                                                                                        Cutscene.clearSprite(g_Console);
                                                                                        Sprites.drawGuard(g_Console, 2);
                                                                                        if (g_dslashGuard > 1.1)
                                                                                        {
                                                                                            Cutscene.clearSprite(g_Console);
                                                                                            Sprites.drawGuard(g_Console, 4);
                                                                                            if (g_dslashGuard > 1.15)
                                                                                            {
                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                Sprites.drawGuard(g_Console, 2);
                                                                                                if (g_dslashGuard > 1.20)
                                                                                                {
                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                    Sprites.drawGuard(g_Console, 0);
                                                                                                    if (g_dslashGuard > 1.25)
                                                                                                    {
                                                                                                        Cutscene.clearSprite(g_Console);
                                                                                                        Sprites.drawGuard(g_Console, -2);
                                                                                                        if (g_dslashGuard > 1.30)
                                                                                                        {
                                                                                                            Cutscene.clearSprite(g_Console);
                                                                                                            Sprites.drawGuard(g_Console, -4);
                                                                                                            if (g_dslashGuard > 1.35)
                                                                                                            {
                                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                                Sprites.drawGuard(g_Console, -2);
                                                                                                                if (g_dslashGuard > 1.40)
                                                                                                                {
                                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                                    Sprites.drawGuard(g_Console, 0);
                                                                                                                    if (g_dslashGuard > 1.45)
                                                                                                                    {
                                                                                                                        Cutscene.clearSprite(g_Console);
                                                                                                                        Sprites.drawGuard(g_Console, 1);
                                                                                                                        if (g_dslashGuard > 1.50)
                                                                                                                        {
                                                                                                                            Cutscene.clearSprite(g_Console);
                                                                                                                            Sprites.drawGuard(g_Console, 2);
                                                                                                                            if (g_dslashGuard > 1.55)
                                                                                                                            {
                                                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                                                Sprites.drawGuard(g_Console, 1);
                                                                                                                                if (g_dslashGuard > 1.60)
                                                                                                                                {
                                                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                                                    Sprites.drawGuard(g_Console, 0);
                                                                                                                                    if (g_dslashGuard > 1.65)
                                                                                                                                    {
                                                                                                                                        Cutscene.clearSprite(g_Console);
                                                                                                                                        Sprites.drawGuard(g_Console, -1);
                                                                                                                                        if (g_dslashGuard > 1.70)
                                                                                                                                        {
                                                                                                                                            Cutscene.clearSprite(g_Console);
                                                                                                                                            Sprites.drawGuard(g_Console, -2);
                                                                                                                                            if (g_dslashGuard > 1.75)
                                                                                                                                            {
                                                                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                                                                Sprites.drawGuard(g_Console, -1);
                                                                                                                                                if (g_dslashGuard > 1.80)
                                                                                                                                                {
                                                                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                                                                    Sprites.drawGuard(g_Console, 0);
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
void Update_killGuard()
{
    // if (g_dkillGuard > 3)
    // {
        // g_eGameState = S_GAME;
   //  }
    processUserInput();
}
void killGuard()
{
    //rMap.initialise(g_Console);
    //rMap.Border(g_Console);
    COORD c;
    //renderCharacter();
    //Sprites.drawGuard(g_Console, 0);
    if (g_dkillGuard > 1.95)
    {
        Cutscene.clearSpriteLine(g_Console, 2);
        if (g_dkillGuard > 2.0)
        {
            Cutscene.clearSpriteLine(g_Console, 3);
            if (g_dkillGuard > 2.05)
            {
                Cutscene.clearSpriteLine(g_Console, 4);
                if (g_dkillGuard > 2.10)
                {
                    Cutscene.clearSpriteLine(g_Console, 5);
                    if (g_dkillGuard > 2.15)
                    {
                        Cutscene.clearSpriteLine(g_Console, 6);
                        if (g_dkillGuard > 2.20)
                        {
                            Cutscene.clearSpriteLine(g_Console, 7);
                            if (g_dkillGuard > 2.25)
                            {
                                Cutscene.clearSpriteLine(g_Console, 8);
                                if (g_dkillGuard > 2.30)
                                {
                                    Cutscene.clearSpriteLine(g_Console, 9);
                                    if (g_dkillGuard > 2.35)
                                    {
                                        Cutscene.clearSpriteLine(g_Console, 10);
                                        if (g_dkillGuard > 2.40)
                                        {
                                            Cutscene.clearSpriteLine(g_Console, 11);
                                            if (g_dkillGuard > 2.45)
                                            {
                                                Cutscene.clearSpriteLine(g_Console, 12);
                                                if (g_dkillGuard > 2.50)
                                                {
                                                    Cutscene.clearSpriteLine(g_Console, 13);
                                                    if (g_dkillGuard > 2.55)
                                                    {
                                                        Cutscene.clearSpriteLine(g_Console, 14);
                                                        if (g_dkillGuard > 2.60)
                                                        {
                                                            Cutscene.clearSpriteLine(g_Console, 15);
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
    g_sGuardArmor.showItemDropped = true;
    static bool item8 = false;
    if (item8 == false)
    {
        GuardArmor.QuantityCheck("Guard Armor");
        item8 = true;

        if (item8 == true)
        {
            GuardArmor.QuantityCheck("Guard Armor");
        }
    }
    playerInvenTime = 0.0;
}

void Update_slashWasp()
{
    if (g_dslashWasp > 3)
    {
        //g_eGameState = S_GAME;
    }
    processUserInput();
}
void slashWasp()
{
    //rMap.initialise(g_Console);
    //rMap.Border(g_Console);
    COORD c;
    //renderCharacter();
    //Sprites.Battle_Wasp(g_Console, 0);
    c.X = 3;
    c.Y = 2;
    g_Console.writeToBuffer(c, "=Mutant Wasp=", 0x0A);
    Cutscene.drawgrid(g_Console, 68, 5, '/');
    //next
    if (g_dslashWasp > 0.05)
    {
        Cutscene.drawgrid(g_Console, 67, 6, '|');
        if (g_dslashWasp > 0.10)
        {
            Cutscene.drawgrid(g_Console, 66, 6, '_');
            Cutscene.drawgrid(g_Console, 65, 7, '/');
            Cutscene.drawgrid(g_Console, 66, 7, '/');
            if (g_dslashWasp > 0.15)
            {
                Cutscene.drawgrid(g_Console, 64, 7, '_');
                Cutscene.drawgrid(g_Console, 63, 8, '/');
                Cutscene.drawgrid(g_Console, 64, 8, '/');
                if (g_dslashWasp > 0.20)
                {
                    Cutscene.drawgrid(g_Console, 62, 8, '_');
                    Cutscene.drawgrid(g_Console, 61, 9, '/');
                    Cutscene.drawgrid(g_Console, 62, 9, '/');
                    if (g_dslashWasp > 0.25)
                    {
                        Cutscene.drawgrid(g_Console, 60, 9, '_');
                        Cutscene.drawgrid(g_Console, 59, 10, '/');
                        Cutscene.drawgrid(g_Console, 60, 10, '/');
                        if (g_dslashWasp > 0.30)
                        {
                            Cutscene.drawgrid(g_Console, 58, 10, '_');
                            Cutscene.drawgrid(g_Console, 57, 11, '/');
                            Cutscene.drawgrid(g_Console, 58, 11, '/');
                            if (g_dslashWasp > 0.35)
                            {
                                Cutscene.drawgrid(g_Console, 56, 11, '_');
                                if (g_dslashWasp > 0.40)
                                {
                                    Cutscene.drawgrid(g_Console, 55, 12, '/');
                                    if (g_dslashWasp > 0.45)
                                    {
                                        Cutscene.drawgrid(g_Console, 54, 12, '_');
                                        if (g_dslashWasp > 0.50)
                                        {
                                            Cutscene.drawgrid(g_Console, 53, 12, '_');
                                            Cutscene.cleargrid(g_Console, 68, 5);
                                            if (g_dslashWasp > 0.55)
                                            {
                                                Cutscene.drawgridG(g_Console, 67, 6, '_');
                                                if (g_dslashWasp > 0.60)
                                                {
                                                    Cutscene.drawgridG(g_Console, 66, 6, '_');
                                                    Cutscene.drawgridG(g_Console, 65, 7, ' ');
                                                    Cutscene.drawgridG(g_Console, 66, 7, ' ');
                                                    if (g_dslashWasp > 0.65)
                                                    {
                                                        Cutscene.drawgridG(g_Console, 64, 7, '/');
                                                        Cutscene.drawgridG(g_Console, 63, 8, '|');
                                                        Cutscene.drawgridG(g_Console, 64, 8, ' ');
                                                        if (g_dslashWasp > 0.70)
                                                        {
                                                            Cutscene.drawgridG(g_Console, 62, 8, '_');
                                                            Cutscene.drawgrid(g_Console, 61, 9, ' ');
                                                            Cutscene.drawgridG(g_Console, 62, 9, '_');
                                                            if (g_dslashWasp > 0.75)
                                                            {
                                                                Cutscene.drawgridG(g_Console, 60, 9, ' ');
                                                                Cutscene.drawgridG(g_Console, 59, 10, '_');
                                                                Cutscene.drawgridG(g_Console, 60, 10, '_');
                                                                if (g_dslashWasp > 0.80)
                                                                {
                                                                    Cutscene.drawgridG(g_Console, 58, 10, '_');
                                                                    Cutscene.drawgridG(g_Console, 57, 11, '_');
                                                                    Cutscene.drawgridG(g_Console, 58, 11, '_');
                                                                    if (g_dslashWasp > 0.85)
                                                                    {
                                                                        Cutscene.drawgridG(g_Console, 56, 11, '_');
                                                                        if (g_dslashWasp > 0.90)
                                                                        {
                                                                            Cutscene.drawgridG(g_Console, 55, 11, '|');
                                                                            if (g_dslashWasp > 0.95)
                                                                            {
                                                                                Cutscene.cleargrid(g_Console, 54, 12);
                                                                                if (g_dslashWasp > 1.00)
                                                                                {
                                                                                    Cutscene.cleargrid(g_Console, 53, 12);
                                                                                    if (g_dslashWasp > 1.05)
                                                                                    {
                                                                                        Cutscene.clearSprite(g_Console);
                                                                                        Sprites.Battle_Wasp(g_Console, 2);
                                                                                        if (g_dslashWasp > 1.1)
                                                                                        {
                                                                                            Cutscene.clearSprite(g_Console);
                                                                                            Sprites.Battle_Wasp(g_Console, 4);
                                                                                            if (g_dslashWasp > 1.15)
                                                                                            {
                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                Sprites.Battle_Wasp(g_Console, 2);
                                                                                                if (g_dslashWasp > 1.20)
                                                                                                {
                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                    Sprites.Battle_Wasp(g_Console, 0);
                                                                                                    if (g_dslashWasp > 1.25)
                                                                                                    {
                                                                                                        Cutscene.clearSprite(g_Console);
                                                                                                        Sprites.Battle_Wasp(g_Console, -2);
                                                                                                        if (g_dslashWasp > 1.30)
                                                                                                        {
                                                                                                            Cutscene.clearSprite(g_Console);
                                                                                                            Sprites.Battle_Wasp(g_Console, -4);
                                                                                                            if (g_dslashWasp > 1.35)
                                                                                                            {
                                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                                Sprites.Battle_Wasp(g_Console, -2);
                                                                                                                if (g_dslashWasp > 1.40)
                                                                                                                {
                                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                                    Sprites.Battle_Wasp(g_Console, 0);
                                                                                                                    if (g_dslashWasp > 1.45)
                                                                                                                    {
                                                                                                                        Cutscene.clearSprite(g_Console);
                                                                                                                        Sprites.Battle_Wasp(g_Console, 1);
                                                                                                                        if (g_dslashWasp > 1.50)
                                                                                                                        {
                                                                                                                            Cutscene.clearSprite(g_Console);
                                                                                                                            Sprites.Battle_Wasp(g_Console, 2);
                                                                                                                            if (g_dslashWasp > 1.55)
                                                                                                                            {
                                                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                                                Sprites.Battle_Wasp(g_Console, 1);
                                                                                                                                if (g_dslashWasp > 1.60)
                                                                                                                                {
                                                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                                                    Sprites.Battle_Wasp(g_Console, 0);
                                                                                                                                    if (g_dslashWasp > 1.65)
                                                                                                                                    {
                                                                                                                                        Cutscene.clearSprite(g_Console);
                                                                                                                                        Sprites.Battle_Wasp(g_Console, -1);
                                                                                                                                        if (g_dslashWasp > 1.70)
                                                                                                                                        {
                                                                                                                                            Cutscene.clearSprite(g_Console);
                                                                                                                                            Sprites.Battle_Wasp(g_Console, -2);
                                                                                                                                            if (g_dslashWasp > 1.75)
                                                                                                                                            {
                                                                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                                                                Sprites.Battle_Wasp(g_Console, -1);
                                                                                                                                                if (g_dslashWasp > 1.80)
                                                                                                                                                {
                                                                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                                                                    Sprites.Battle_Wasp(g_Console, 0);
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
void Update_killWasp()
{
    if (g_dkillWasp > 3)
    {
        //g_eGameState = S_GAME;
    }
    processUserInput();
}
void killWasp()
{
    //rMap.initialise(g_Console);
    //rMap.Border(g_Console);
    COORD c;
    //renderCharacter();
    c.X = 3;
    c.Y = 2;
    g_Console.writeToBuffer(c, "=Mutant Wasp=", 0x0A);
    //Sprites.Battle_Wasp(g_Console, 0);
    if (g_dkillWasp > 1.95)
    {
        Cutscene.clearSpriteLine(g_Console, 2);
        if (g_dkillWasp > 2.0)
        {
            Cutscene.clearSpriteLine(g_Console, 3);
            if (g_dkillWasp > 2.05)
            {
                Cutscene.clearSpriteLine(g_Console, 4);
                if (g_dkillWasp > 2.10)
                {
                    Cutscene.clearSpriteLine(g_Console, 5);
                    if (g_dkillWasp > 2.15)
                    {
                        Cutscene.clearSpriteLine(g_Console, 6);
                        if (g_dkillWasp > 2.20)
                        {
                            Cutscene.clearSpriteLine(g_Console, 7);
                            if (g_dkillWasp > 2.25)
                            {
                                Cutscene.clearSpriteLine(g_Console, 8);
                                if (g_dkillWasp > 2.30)
                                {
                                    Cutscene.clearSpriteLine(g_Console, 9);
                                    if (g_dkillWasp > 2.35)
                                    {
                                        Cutscene.clearSpriteLine(g_Console, 10);
                                        if (g_dkillWasp > 2.40)
                                        {
                                            Cutscene.clearSpriteLine(g_Console, 11);
                                            if (g_dkillWasp > 2.45)
                                            {
                                                Cutscene.clearSpriteLine(g_Console, 12);
                                                if (g_dkillWasp > 2.50)
                                                {
                                                    Cutscene.clearSpriteLine(g_Console, 13);
                                                    if (g_dkillWasp > 2.55)
                                                    {
                                                        Cutscene.clearSpriteLine(g_Console, 14);
                                                        if (g_dkillWasp > 2.60)
                                                        {
                                                            Cutscene.clearSpriteLine(g_Console, 15);
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
    g_sStinger.showItemDropped = true;
    static bool item7 = false;
    if (item7 == false)
    {
        Stinger.QuantityCheck("Stinger");
        item7 = true;
        if (item7 == true)
        {
            Stinger.QuantityCheck("Stinger");
        }
    }
}

void Update_slashPig()
{
    if (g_dslashPig > 3)
    {
        g_eGameState = S_GAME;
    }
    processUserInput();
}
void slashPig()
{
    //rMap.initialise(g_Console);
    //rMap.Border(g_Console);
    COORD c;
    //renderCharacter();
    c.X = 3;
    c.Y = 2;
    g_Console.writeToBuffer(c, "=Pig=", 0x0A);
    //Sprites.pig(g_Console, 0);
    Cutscene.drawgrid(g_Console, 68, 5, '/');
    //next
    if (g_dslashPig > 0.05)
    {
        Cutscene.drawgrid(g_Console, 67, 6, '|');
        if (g_dslashPig > 0.10)
        {
            Cutscene.drawgrid(g_Console, 66, 6, '_');
            Cutscene.drawgrid(g_Console, 65, 7, '/');
            Cutscene.drawgrid(g_Console, 66, 7, '/');
            if (g_dslashPig > 0.15)
            {
                Cutscene.drawgrid(g_Console, 64, 7, '_');
                Cutscene.drawgrid(g_Console, 63, 8, '/');
                Cutscene.drawgrid(g_Console, 64, 8, '/');
                if (g_dslashPig > 0.20)
                {
                    Cutscene.drawgrid(g_Console, 62, 8, '_');
                    Cutscene.drawgrid(g_Console, 61, 9, '/');
                    Cutscene.drawgrid(g_Console, 62, 9, '/');
                    if (g_dslashPig > 0.25)
                    {
                        Cutscene.drawgrid(g_Console, 60, 9, '_');
                        Cutscene.drawgrid(g_Console, 59, 10, '/');
                        Cutscene.drawgrid(g_Console, 60, 10, '/');
                        if (g_dslashPig > 0.30)
                        {
                            Cutscene.drawgrid(g_Console, 58, 10, '_');
                            Cutscene.drawgrid(g_Console, 57, 11, '/');
                            Cutscene.drawgrid(g_Console, 58, 11, '/');
                            if (g_dslashPig > 0.35)
                            {
                                Cutscene.drawgrid(g_Console, 56, 11, '_');
                                if (g_dslashPig > 0.40)
                                {
                                    Cutscene.drawgrid(g_Console, 55, 12, '/');
                                    if (g_dslashPig > 0.45)
                                    {
                                        Cutscene.drawgrid(g_Console, 54, 12, '_');
                                        if (g_dslashPig > 0.50)
                                        {
                                            Cutscene.drawgrid(g_Console, 53, 12, '_');
                                            Cutscene.cleargrid(g_Console, 68, 5);
                                            if (g_dslashPig > 0.55)
                                            {
                                                Cutscene.cleargrid(g_Console, 67, 6);
                                                if (g_dslashPig > 0.60)
                                                {
                                                    Cutscene.drawgridG(g_Console, 66, 6, ' ');
                                                    Cutscene.drawgridG(g_Console, 65, 7, ' ');
                                                    Cutscene.drawgridG(g_Console, 66, 7, ' ');
                                                    if (g_dslashPig > 0.65)
                                                    {
                                                        Cutscene.drawgridG(g_Console, 64, 7, ' ');
                                                        Cutscene.drawgridG(g_Console, 63, 8, ' ');
                                                        Cutscene.drawgridG(g_Console, 64, 8, ' ');
                                                        if (g_dslashPig > 0.70)
                                                        {
                                                            Cutscene.drawgridG(g_Console, 62, 8, ' ');
                                                            Cutscene.drawgrid(g_Console, 61, 9, ' ');
                                                            Cutscene.drawgrid(g_Console, 62, 9, ' ');
                                                            if (g_dslashPig > 0.75)
                                                            {
                                                                Cutscene.drawgridG(g_Console, 60, 9, '|');
                                                                Cutscene.drawgrid(g_Console, 59, 10, ' ');
                                                                Cutscene.drawgridG(g_Console, 60, 10, '|');
                                                                if (g_dslashPig > 0.80)
                                                                {
                                                                    Cutscene.drawgridG(g_Console, 58, 10, '|');
                                                                    Cutscene.drawgridG(g_Console, 57, 11, '_');
                                                                    Cutscene.drawgridG(g_Console, 58, 11, '|');
                                                                    if (g_dslashPig > 0.85)
                                                                    {
                                                                        Cutscene.drawgridG(g_Console, 56, 11, '_');
                                                                        if (g_dslashPig > 0.90)
                                                                        {
                                                                            Cutscene.drawgridG(g_Console, 55, 12, '|');
                                                                            if (g_dslashPig > 0.95)
                                                                            {
                                                                                Cutscene.cleargrid(g_Console, 54, 12);
                                                                                if (g_dslashPig > 1.00)
                                                                                {
                                                                                    Cutscene.cleargrid(g_Console, 53, 12);
                                                                                    if (g_dslashPig > 1.05)
                                                                                    {
                                                                                        Cutscene.clearSprite(g_Console);
                                                                                        Sprites.pig(g_Console, 2);
                                                                                        if (g_dslashPig > 1.1)
                                                                                        {
                                                                                            Cutscene.clearSprite(g_Console);
                                                                                            Sprites.pig(g_Console, 4);
                                                                                            if (g_dslashPig > 1.15)
                                                                                            {
                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                Cutscene.cleargrid(g_Console, 79, 9);
                                                                                                rMap.Border(g_Console);
                                                                                                Sprites.pig(g_Console, 2);
                                                                                                if (g_dslashPig > 1.20)
                                                                                                {
                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                    Sprites.pig(g_Console, 0);
                                                                                                    if (g_dslashPig > 1.25)
                                                                                                    {
                                                                                                        Cutscene.clearSprite(g_Console);
                                                                                                        Sprites.pig(g_Console, -2);
                                                                                                        if (g_dslashPig > 1.30)
                                                                                                        {
                                                                                                            Cutscene.clearSprite(g_Console);
                                                                                                            Sprites.pig(g_Console, -4);
                                                                                                            if (g_dslashPig > 1.35)
                                                                                                            {
                                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                                Sprites.pig(g_Console, -2);
                                                                                                                if (g_dslashPig > 1.40)
                                                                                                                {
                                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                                    Sprites.pig(g_Console, 0);
                                                                                                                    if (g_dslashPig > 1.45)
                                                                                                                    {
                                                                                                                        Cutscene.clearSprite(g_Console);
                                                                                                                        Sprites.pig(g_Console, 1);
                                                                                                                        if (g_dslashPig > 1.50)
                                                                                                                        {
                                                                                                                            Cutscene.clearSprite(g_Console);
                                                                                                                            Sprites.pig(g_Console, 2);
                                                                                                                            if (g_dslashPig > 1.55)
                                                                                                                            {
                                                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                                                Sprites.pig(g_Console, 1);
                                                                                                                                if (g_dslashPig > 1.60)
                                                                                                                                {
                                                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                                                    Sprites.pig(g_Console, 0);
                                                                                                                                    if (g_dslashPig > 1.65)
                                                                                                                                    {
                                                                                                                                        Cutscene.clearSprite(g_Console);
                                                                                                                                        Sprites.pig(g_Console, -1);
                                                                                                                                        if (g_dslashPig > 1.70)
                                                                                                                                        {
                                                                                                                                            Cutscene.clearSprite(g_Console);
                                                                                                                                            Sprites.pig(g_Console, -2);
                                                                                                                                            if (g_dslashPig > 1.75)
                                                                                                                                            {
                                                                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                                                                Sprites.pig(g_Console, -1);
                                                                                                                                                if (g_dslashPig > 1.80)
                                                                                                                                                {
                                                                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                                                                    Sprites.pig(g_Console, 0);
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
void Update_killPig()
{
    if (g_dkillPig > 3)
    {
        g_eGameState = S_GAME;
    }
    processUserInput();
}
void killPig()
{
    //rMap.initialise(g_Console);
    //rMap.Border(g_Console);
    COORD c;
    //renderCharacter();
    c.X = 3;
    c.Y = 2;
    g_Console.writeToBuffer(c, "=Pig=", 0x0A);
    //Sprites.pig(g_Console, 0);
    if (g_dkillPig > 1.95)
    {
        Cutscene.clearSpriteLine(g_Console, 2);
        if (g_dkillPig > 2.0)
        {
            Cutscene.clearSpriteLine(g_Console, 3);
            if (g_dkillPig > 2.05)
            {
                Cutscene.clearSpriteLine(g_Console, 4);
                if (g_dkillPig > 2.10)
                {
                    Cutscene.clearSpriteLine(g_Console, 5);
                    if (g_dkillPig > 2.15)
                    {
                        Cutscene.clearSpriteLine(g_Console, 6);
                        if (g_dkillPig > 2.20)
                        {
                            Cutscene.clearSpriteLine(g_Console, 7);
                            if (g_dkillPig > 2.25)
                            {
                                Cutscene.clearSpriteLine(g_Console, 8);
                                if (g_dkillPig > 2.30)
                                {
                                    Cutscene.clearSpriteLine(g_Console, 9);
                                    if (g_dkillPig > 2.35)
                                    {
                                        Cutscene.clearSpriteLine(g_Console, 10);
                                        if (g_dkillPig > 2.40)
                                        {
                                            Cutscene.clearSpriteLine(g_Console, 11);
                                            if (g_dkillPig > 2.45)
                                            {
                                                Cutscene.clearSpriteLine(g_Console, 12);
                                                if (g_dkillPig > 2.50)
                                                {
                                                    Cutscene.clearSpriteLine(g_Console, 13);
                                                    if (g_dkillPig > 2.55)
                                                    {
                                                        Cutscene.clearSpriteLine(g_Console, 14);
                                                        if (g_dkillPig > 2.60)
                                                        {
                                                            Cutscene.clearSpriteLine(g_Console, 15);
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
    g_sRawMeat.showItemDropped = true;
    static bool item1 = false;
    if (item1 == false)
    {
        RawMeat.QuantityCheck("Raw Meat");
        item1 = true;
        if (item1 == true)
        {
            RawMeat.QuantityCheck("Raw Meat");
        }
    }
}

void Update_slashRaymond()
{
    if (g_dslashRaymond > 3)
    {
        g_eGameState = S_GAME;
    }
    processUserInput();
}
void slashRaymond()
{
    //rMap.initialise(g_Console);
   // rMap.Border(g_Console);
    COORD c;
    //renderCharacter();
    c.X = 3;
    c.Y = 2;
    g_Console.writeToBuffer(c, "=Raymond=", 0x0A);
    //  Sprites.Battle_Raymond(g_Console, 0);
    Cutscene.drawgrid(g_Console, 68, 5, '/');
    //next
    if (g_dslashRaymond > 0.05)
    {
        Cutscene.drawgrid(g_Console, 67, 6, '|');
        if (g_dslashRaymond > 0.10)
        {
            Cutscene.drawgrid(g_Console, 66, 6, '_');
            Cutscene.drawgrid(g_Console, 65, 7, '/');
            Cutscene.drawgrid(g_Console, 66, 7, '/');
            if (g_dslashRaymond > 0.15)
            {
                Cutscene.drawgrid(g_Console, 64, 7, '_');
                Cutscene.drawgrid(g_Console, 63, 8, '/');
                Cutscene.drawgrid(g_Console, 64, 8, '/');
                if (g_dslashRaymond > 0.20)
                {
                    Cutscene.drawgrid(g_Console, 62, 8, '_');
                    Cutscene.drawgrid(g_Console, 61, 9, '/');
                    Cutscene.drawgrid(g_Console, 62, 9, '/');
                    if (g_dslashRaymond > 0.25)
                    {
                        Cutscene.drawgrid(g_Console, 60, 9, '_');
                        Cutscene.drawgrid(g_Console, 59, 10, '/');
                        Cutscene.drawgrid(g_Console, 60, 10, '/');
                        if (g_dslashRaymond > 0.30)
                        {
                            Cutscene.drawgrid(g_Console, 58, 10, '_');
                            Cutscene.drawgrid(g_Console, 57, 11, '/');
                            Cutscene.drawgrid(g_Console, 58, 11, '/');
                            if (g_dslashRaymond > 0.35)
                            {
                                Cutscene.drawgrid(g_Console, 56, 11, '_');
                                if (g_dslashRaymond > 0.40)
                                {
                                    Cutscene.drawgrid(g_Console, 55, 12, '/');
                                    if (g_dslashRaymond > 0.45)
                                    {
                                        Cutscene.drawgrid(g_Console, 54, 12, '_');
                                        if (g_dslashRaymond > 0.50)
                                        {
                                            Cutscene.drawgrid(g_Console, 53, 12, '_');
                                            Cutscene.cleargrid(g_Console, 68, 5);
                                            if (g_dslashRaymond > 0.55)
                                            {
                                                Cutscene.cleargrid(g_Console, 67, 6);
                                                if (g_dslashRaymond > 0.60)
                                                {
                                                    Cutscene.drawgridG(g_Console, 66, 6, ' ');
                                                    Cutscene.drawgridG(g_Console, 65, 7, '_');
                                                    Cutscene.drawgridG(g_Console, 66, 7, ' ');
                                                    if (g_dslashRaymond > 0.65)
                                                    {
                                                        Cutscene.drawgridG(g_Console, 64, 7, '_');
                                                        Cutscene.drawgridG(g_Console, 63, 8, '|');
                                                        Cutscene.drawgridG(g_Console, 64, 8, ' ');
                                                        if (g_dslashRaymond > 0.70)
                                                        {
                                                            Cutscene.drawgridG(g_Console, 62, 8, ' ');
                                                            Cutscene.drawgrid(g_Console, 61, 9, ' ');
                                                            Cutscene.drawgrid(g_Console, 62, 9, ' ');
                                                            if (g_dslashRaymond > 0.75)
                                                            {
                                                                Cutscene.drawgridG(g_Console, 60, 9, '/');
                                                                Cutscene.drawgridG(g_Console, 59, 10, 'V');
                                                                Cutscene.drawgrid(g_Console, 60, 10, ' ');
                                                                if (g_dslashRaymond > 0.80)
                                                                {
                                                                    Cutscene.drawgrid(g_Console, 58, 10, ' ');
                                                                    Cutscene.drawgridG(g_Console, 57, 11, '_');
                                                                    Cutscene.drawgridG(g_Console, 58, 11, '_');
                                                                    if (g_dslashRaymond > 0.85)
                                                                    {
                                                                        Cutscene.drawgridG(g_Console, 56, 11, '_');
                                                                        if (g_dslashRaymond > 0.90)
                                                                        {
                                                                            Cutscene.drawgridG(g_Console, 55, 12, '|');
                                                                            if (g_dslashRaymond > 0.95)
                                                                            {
                                                                                Cutscene.cleargrid(g_Console, 54, 12);
                                                                                if (g_dslashRaymond > 1.00)
                                                                                {
                                                                                    Cutscene.cleargrid(g_Console, 53, 12);
                                                                                    if (g_dslashRaymond > 1.05)
                                                                                    {
                                                                                        Cutscene.clearSprite(g_Console);
                                                                                        Sprites.Battle_Raymond(g_Console, 2);
                                                                                        if (g_dslashRaymond > 1.1)
                                                                                        {
                                                                                            Cutscene.clearSprite(g_Console);
                                                                                            Sprites.Battle_Raymond(g_Console, 4);
                                                                                            if (g_dslashRaymond > 1.15)
                                                                                            {
                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                Sprites.Battle_Raymond(g_Console, 2);
                                                                                                if (g_dslashRaymond > 1.20)
                                                                                                {
                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                    Sprites.Battle_Raymond(g_Console, 0);
                                                                                                    if (g_dslashRaymond > 1.25)
                                                                                                    {
                                                                                                        Cutscene.clearSprite(g_Console);
                                                                                                        Sprites.Battle_Raymond(g_Console, -2);
                                                                                                        if (g_dslashRaymond > 1.30)
                                                                                                        {
                                                                                                            Cutscene.clearSprite(g_Console);
                                                                                                            Sprites.Battle_Raymond(g_Console, -4);
                                                                                                            if (g_dslashRaymond > 1.35)
                                                                                                            {
                                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                                Sprites.Battle_Raymond(g_Console, -2);
                                                                                                                if (g_dslashRaymond > 1.40)
                                                                                                                {
                                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                                    Sprites.Battle_Raymond(g_Console, 0);
                                                                                                                    if (g_dslashRaymond > 1.45)
                                                                                                                    {
                                                                                                                        Cutscene.clearSprite(g_Console);
                                                                                                                        Sprites.Battle_Raymond(g_Console, 1);
                                                                                                                        if (g_dslashRaymond > 1.50)
                                                                                                                        {
                                                                                                                            Cutscene.clearSprite(g_Console);
                                                                                                                            Sprites.Battle_Raymond(g_Console, 2);
                                                                                                                            if (g_dslashRaymond > 1.55)
                                                                                                                            {
                                                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                                                Sprites.Battle_Raymond(g_Console, 1);
                                                                                                                                if (g_dslashRaymond > 1.60)
                                                                                                                                {
                                                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                                                    Sprites.Battle_Raymond(g_Console, 0);
                                                                                                                                    if (g_dslashRaymond > 1.65)
                                                                                                                                    {
                                                                                                                                        Cutscene.clearSprite(g_Console);
                                                                                                                                        Sprites.Battle_Raymond(g_Console, -1);
                                                                                                                                        if (g_dslashRaymond > 1.70)
                                                                                                                                        {
                                                                                                                                            Cutscene.clearSprite(g_Console);
                                                                                                                                            Sprites.Battle_Raymond(g_Console, -2);
                                                                                                                                            if (g_dslashRaymond > 1.75)
                                                                                                                                            {
                                                                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                                                                Sprites.Battle_Raymond(g_Console, -1);
                                                                                                                                                if (g_dslashRaymond > 1.80)
                                                                                                                                                {
                                                                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                                                                    Sprites.Battle_Raymond(g_Console, 0);
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
void Update_killRaymond()
{
    if (g_dkillRaymond > 5)
    {
        g_eGameState = S_GAME;
    }
    processUserInput();
}
void killRaymond()
{
    //rMap.initialise(g_Console);
   // rMap.Border(g_Console);
    COORD c, d;
    // renderCharacter();
    c.X = 3;
    c.Y = 2;
    d.X = 5;
    d.Y = 26;
    g_Console.writeToBuffer(c, "=Raymond=", 0x0A);
    Sprites.Battle_Raymond(g_Console, -19);
    g_Console.writeToBuffer(d, "Raymond: NOOOOOOO!!!!!", 0x0F);
    if (g_dkillRaymond > 1.95)
    {
        Cutscene.clearRaymondSpriteLine(g_Console, 2);
        if (g_dkillRaymond > 2.0)
        {
            Cutscene.clearRaymondSpriteLine(g_Console, 3);
            if (g_dkillRaymond > 2.05)
            {
                Cutscene.clearRaymondSpriteLine(g_Console, 4);
                if (g_dkillRaymond > 2.10)
                {
                    Cutscene.clearRaymondSpriteLine(g_Console, 5);
                    if (g_dkillRaymond > 2.15)
                    {
                        Cutscene.clearRaymondSpriteLine(g_Console, 6);
                        if (g_dkillRaymond > 2.20)
                        {
                            Cutscene.clearRaymondSpriteLine(g_Console, 7);
                            if (g_dkillRaymond > 2.25)
                            {
                                Cutscene.clearRaymondSpriteLine(g_Console, 8);
                                if (g_dkillRaymond > 2.30)
                                {
                                    Cutscene.clearRaymondSpriteLine(g_Console, 9);
                                    if (g_dkillRaymond > 2.35)
                                    {
                                         Cutscene.clearRaymondSpriteLine(g_Console, 10);
                                        if (g_dkillRaymond > 2.40)
                                        {
                                            Cutscene.clearRaymondSpriteLine(g_Console, 11);
                                            if (g_dkillRaymond > 2.45)
                                            {
                                                Cutscene.clearRaymondSpriteLine(g_Console, 12);
                                                if (g_dkillRaymond > 2.50)
                                                {
                                                    Cutscene.clearRaymondSpriteLine(g_Console, 13);
                                                    if (g_dkillRaymond > 2.55)
                                                    {
                                                        Cutscene.clearRaymondSpriteLine(g_Console, 14);
                                                        if (g_dkillRaymond > 2.60)
                                                        {
                                                            Cutscene.clearRaymondSpriteLine(g_Console, 15);
                                                            if (g_dkillRaymond > 2.65)
                                                            {
                                                                Cutscene.drawgridG(g_Console, 36, 16, '_');
                                                                Cutscene.drawgridG(g_Console, 40, 16, '_');
                                                                Cutscene.drawgridG(g_Console, 44, 16, '_');
                                                                if (g_dkillRaymond > 3.5)
                                                                {
                                                                    g_Console.writeToBuffer(d, "                                                         ", 0x0F);
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

void Update_slashRobert()
{
    if (g_dslashRobert > 3)
    {
        //g_eGameState = S_GAME;
    }
    processUserInput();
}
void slashRobert()
{
    //rMap.initialise(g_Console);
    //rMap.Border(g_Console);
    COORD c;
    //renderCharacter();
    Sprites.drawRobert(g_Console, 0);
    //rMap.Battle_Screen(g_Console);
    Cutscene.drawgrid(g_Console, 20, 5, '/');
    //next
    if (g_dslashRobert > 0.05)
    {
        Cutscene.drawgrid(g_Console, 19, 6, '|');
        if (g_dslashRobert > 0.10)
        {
            Cutscene.drawgrid(g_Console, 18, 6, '_');
            Cutscene.drawgrid(g_Console, 17, 7, '/');
            Cutscene.drawgrid(g_Console, 18, 7, '/');
            if (g_dslashRobert > 0.15)
            {
                Cutscene.drawgrid(g_Console, 16, 7, '_');
                Cutscene.drawgrid(g_Console, 15, 8, '/');
                Cutscene.drawgrid(g_Console, 16, 8, '/');
                if (g_dslashRobert > 0.20)
                {
                    Cutscene.drawgrid(g_Console, 14, 8, '_');
                    Cutscene.drawgrid(g_Console, 13, 9, '/');
                    Cutscene.drawgrid(g_Console, 14, 9, '/');
                    if (g_dslashRobert > 0.25)
                    {
                        Cutscene.drawgrid(g_Console, 12, 9, '_');
                        Cutscene.drawgrid(g_Console, 11, 10, '/');
                        Cutscene.drawgrid(g_Console, 12, 10, '/');
                        if (g_dslashRobert > 0.30)
                        {
                            Cutscene.drawgrid(g_Console, 10, 10, '_');
                            if (g_dslashRobert > 0.35)
                            {
                                Cutscene.drawgrid(g_Console, 9, 11, '/');
                                if (g_dslashRobert > 0.4)
                                {
                                    Cutscene.drawgrid(g_Console, 8, 11, '_');
                                    if (g_dslashRobert > 0.45)
                                    {
                                        Cutscene.drawgrid(g_Console, 7, 11, '_');
                                        Cutscene.cleargrid(g_Console, 20, 5);
                                        if (g_dslashRobert > 0.5)
                                        {
                                            Cutscene.cleargrid(g_Console, 19, 6);
                                            if (g_dslashRobert > 0.55)
                                            {
                                                Cutscene.drawgridG(g_Console, 18, 6, ' ');
                                                Cutscene.drawgridG(g_Console, 17, 7, ' ');
                                                Cutscene.drawgridG(g_Console, 18, 7, ' ');
                                                if (g_dslashRobert > 0.60)
                                                {
                                                    Cutscene.drawgridG(g_Console, 16, 7, '\\');
                                                    Cutscene.drawgridG(g_Console, 15, 8, ' ');
                                                    Cutscene.drawgridG(g_Console, 16, 8, ' ');
                                                    if (g_dslashRobert > 0.65)
                                                    {
                                                        Cutscene.drawgridG(g_Console, 14, 8, ' ');
                                                        Cutscene.drawgrid(g_Console, 13, 9, ' ');
                                                        Cutscene.drawgrid(g_Console, 14, 9, ' ');
                                                        if (g_dslashRobert > 0.70)
                                                        {
                                                            Cutscene.drawgrid(g_Console, 12, 9, ' ');
                                                            Cutscene.drawgridG(g_Console, 11, 10, '\\');
                                                            Cutscene.drawgridG(g_Console, 12, 10, '/');
                                                            if (g_dslashRobert > 0.75)
                                                            {
                                                                Cutscene.cleargrid(g_Console, 10, 10);
                                                                if (g_dslashRobert > 0.80)
                                                                {
                                                                    Cutscene.cleargrid(g_Console, 9, 11);
                                                                    if (g_dslashRobert > 0.85)
                                                                    {
                                                                        Cutscene.cleargrid(g_Console, 8, 11);
                                                                        if (g_dslashRobert > 0.90)
                                                                        {
                                                                            Cutscene.cleargrid(g_Console, 7, 11);
                                                                            if (g_dslashRobert > 0.95)
                                                                            {
                                                                                Cutscene.clearRobertSprite(g_Console);
                                                                                Sprites.drawRobert(g_Console, 2);
                                                                                if (g_dslashRobert > 1.0)
                                                                                {
                                                                                    Cutscene.clearRobertSprite(g_Console);
                                                                                    Sprites.drawRobert(g_Console, 4);
                                                                                    if (g_dslashRobert > 1.05)
                                                                                    {
                                                                                        Cutscene.clearRobertSprite(g_Console);
                                                                                        Sprites.drawRobert(g_Console, 2);
                                                                                        if (g_dslashRobert > 1.10)
                                                                                        {
                                                                                            Cutscene.clearRobertSprite(g_Console);
                                                                                            Sprites.drawRobert(g_Console, 0);
                                                                                            if (g_dslashRobert > 1.15)
                                                                                            {
                                                                                                Cutscene.clearRobertSprite(g_Console);
                                                                                                Sprites.drawRobert(g_Console, -2);
                                                                                                if (g_dslashRobert > 1.20)
                                                                                                {
                                                                                                    Cutscene.clearRobertSprite(g_Console);
                                                                                                    Sprites.drawRobert(g_Console, -4);
                                                                                                    if (g_dslashRobert > 1.25)
                                                                                                    {
                                                                                                        Cutscene.clearRobertSprite(g_Console);
                                                                                                        Sprites.drawRobert(g_Console, -2);
                                                                                                        if (g_dslashRobert > 1.3)
                                                                                                        {
                                                                                                            Cutscene.clearRobertSprite(g_Console);
                                                                                                            Sprites.drawRobert(g_Console, 0);
                                                                                                            if (g_dslashRobert > 1.35)
                                                                                                            {
                                                                                                                Cutscene.clearRobertSprite(g_Console);
                                                                                                                Sprites.drawRobert(g_Console, 1);
                                                                                                                if (g_dslashRobert > 1.40)
                                                                                                                {
                                                                                                                    Cutscene.clearRobertSprite(g_Console);
                                                                                                                    Sprites.drawRobert(g_Console, 2);
                                                                                                                    if (g_dslashRobert > 1.45)
                                                                                                                    {
                                                                                                                        Cutscene.clearRobertSprite(g_Console);
                                                                                                                        Sprites.drawRobert(g_Console, 1);
                                                                                                                        if (g_dslashRobert > 1.50)
                                                                                                                        {
                                                                                                                            Cutscene.clearRobertSprite(g_Console);
                                                                                                                            Sprites.drawRobert(g_Console, 0);
                                                                                                                            if (g_dslashRobert > 1.55)
                                                                                                                            {
                                                                                                                                Cutscene.clearRobertSprite(g_Console);
                                                                                                                                Sprites.drawRobert(g_Console, -1);
                                                                                                                                if (g_dslashRobert > 1.60)
                                                                                                                                {
                                                                                                                                    Cutscene.clearRobertSprite(g_Console);
                                                                                                                                    Sprites.drawRobert(g_Console, -2);
                                                                                                                                    if (g_dslashRobert > 1.65)
                                                                                                                                    {
                                                                                                                                        Cutscene.clearRobertSprite(g_Console);
                                                                                                                                        Sprites.drawRobert(g_Console, -1);
                                                                                                                                        if (g_dslashRobert > 1.70)
                                                                                                                                        {
                                                                                                                                            Cutscene.clearRobertSprite(g_Console);
                                                                                                                                            Sprites.drawRobert(g_Console, 0);
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
void Update_killRobert()
{
    if (g_dkillRobert > 3)
    {
        //g_eGameState = S_GAME;
    }
    processUserInput();
}
void killRobert()
{
    //rMap.initialise(g_Console);
    // rMap.Border(g_Console);
    COORD c;
    //renderCharacter();
    //Sprites.drawRobert(g_Console, 0);
    if (g_dkillRobert > 1.95)
    {
        Cutscene.clearRobertSpriteLine(g_Console, 2);
        if (g_dkillRobert > 2.0)
        {
            Cutscene.clearRobertSpriteLine(g_Console, 3);
            if (g_dkillRobert > 2.05)
            {
                Cutscene.clearRobertSpriteLine(g_Console, 4);
                if (g_dkillRobert > 2.10)
                {
                    Cutscene.clearRobertSpriteLine(g_Console, 5);
                    if (g_dkillRobert > 2.15)
                    {
                        Cutscene.clearRobertSpriteLine(g_Console, 6);
                        if (g_dkillRobert > 2.20)
                        {
                            Cutscene.clearRobertSpriteLine(g_Console, 7);
                            if (g_dkillRobert > 2.25)
                            {
                                Cutscene.clearRobertSpriteLine(g_Console, 8);
                                if (g_dkillRobert > 2.30)
                                {
                                    Cutscene.clearRobertSpriteLine(g_Console, 9);
                                    if (g_dkillRobert > 2.35)
                                    {
                                        Cutscene.clearRobertSpriteLine(g_Console, 10);
                                        if (g_dkillRobert > 2.40)
                                        {
                                            Cutscene.clearRobertSpriteLine(g_Console, 11);
                                            if (g_dkillRobert > 2.45)
                                            {
                                                Cutscene.clearRobertSpriteLine(g_Console, 12);
                                                if (g_dkillRobert > 2.50)
                                                {
                                                    Cutscene.clearRobertSpriteLine(g_Console, 13);
                                                    if (g_dkillRobert > 2.55)
                                                    {
                                                        Cutscene.clearRobertSpriteLine(g_Console, 14);
                                                        if (g_dkillRobert > 2.60)
                                                        {
                                                            Cutscene.clearRobertSpriteLine(g_Console, 15);
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

void Update_slashTutWasp()
{
    if (g_dslashTutWasp > 3)
    {
        g_eGameState = S_GAME;
    }
    processUserInput();
}
void slashTutWasp()
{
    //rMap.initialise(g_Console);
    //rMap.Border(g_Console);
    COORD c;
    //renderCharacter();
    //Sprites.Tutorial_Wasp(g_Console, 0);
    c.X = 3;
    c.Y = 2;
    g_Console.writeToBuffer(c, "=Tutorial Wasp=", 0x0A);
    Cutscene.drawgrid(g_Console, 68, 5, '/');
    if (g_dslashTutWasp > 0.05)
    {
        Cutscene.drawgrid(g_Console, 67, 6, '|');
        if (g_dslashTutWasp > 0.10)
        {
            Cutscene.drawgrid(g_Console, 66, 6, '_');
            Cutscene.drawgrid(g_Console, 65, 7, '/');
            Cutscene.drawgrid(g_Console, 66, 7, '/');
            if (g_dslashTutWasp > 0.15)
            {
                Cutscene.drawgrid(g_Console, 64, 7, '_');
                Cutscene.drawgrid(g_Console, 63, 8, '/');
                Cutscene.drawgrid(g_Console, 64, 8, '/');
                if (g_dslashTutWasp > 0.20)
                {
                    Cutscene.drawgrid(g_Console, 62, 8, '_');
                    Cutscene.drawgrid(g_Console, 61, 9, '/');
                    Cutscene.drawgrid(g_Console, 62, 9, '/');
                    if (g_dslashTutWasp > 0.25)
                    {
                        Cutscene.drawgrid(g_Console, 60, 9, '_');
                        Cutscene.drawgrid(g_Console, 59, 10, '/');
                        Cutscene.drawgrid(g_Console, 60, 10, '/');
                        if (g_dslashTutWasp > 0.30)
                        {
                            Cutscene.drawgrid(g_Console, 58, 10, '_');
                            Cutscene.drawgrid(g_Console, 57, 11, '/');
                            Cutscene.drawgrid(g_Console, 58, 11, '/');
                            if (g_dslashTutWasp > 0.35)
                            {
                                Cutscene.drawgrid(g_Console, 56, 11, '_');
                                if (g_dslashTutWasp > 0.40)
                                {
                                    Cutscene.drawgrid(g_Console, 55, 12, '/');
                                    if (g_dslashTutWasp > 0.45)
                                    {
                                        Cutscene.drawgrid(g_Console, 54, 12, '_');
                                        if (g_dslashTutWasp > 0.50)
                                        {
                                            Cutscene.drawgrid(g_Console, 53, 12, '_');
                                            Cutscene.cleargrid(g_Console, 68, 5);
                                            if (g_dslashTutWasp > 0.55)
                                            {
                                                Cutscene.drawgridG(g_Console, 67, 6, '_');
                                                if (g_dslashTutWasp > 0.60)
                                                {
                                                    Cutscene.drawgridG(g_Console, 66, 6, '_');
                                                    Cutscene.drawgridG(g_Console, 65, 7, ' ');
                                                    Cutscene.drawgridG(g_Console, 66, 7, ' ');
                                                    if (g_dslashTutWasp > 0.65)
                                                    {
                                                        Cutscene.drawgridG(g_Console, 64, 7, '/');
                                                        Cutscene.drawgridG(g_Console, 63, 8, '|');
                                                        Cutscene.drawgridG(g_Console, 64, 8, ' ');
                                                        if (g_dslashTutWasp > 0.70)
                                                        {
                                                            Cutscene.drawgridG(g_Console, 62, 8, '_');
                                                            Cutscene.drawgrid(g_Console, 61, 9, ' ');
                                                            Cutscene.drawgridG(g_Console, 62, 9, '_');
                                                            if (g_dslashTutWasp > 0.75)
                                                            {
                                                                Cutscene.drawgridG(g_Console, 60, 9, ' ');
                                                                Cutscene.drawgridG(g_Console, 59, 10, '_');
                                                                Cutscene.drawgridG(g_Console, 60, 10, '_');
                                                                if (g_dslashTutWasp > 0.80)
                                                                {
                                                                    Cutscene.drawgridG(g_Console, 58, 10, '_');
                                                                    Cutscene.drawgridG(g_Console, 57, 11, '_');
                                                                    Cutscene.drawgridG(g_Console, 58, 11, '_');
                                                                    if (g_dslashTutWasp > 0.85)
                                                                    {
                                                                        Cutscene.drawgridG(g_Console, 56, 11, '_');
                                                                        if (g_dslashTutWasp > 0.90)
                                                                        {
                                                                            Cutscene.drawgridG(g_Console, 55, 11, '|');
                                                                            if (g_dslashTutWasp > 0.95)
                                                                            {
                                                                                Cutscene.cleargrid(g_Console, 54, 12);
                                                                                if (g_dslashTutWasp > 1.00)
                                                                                {
                                                                                    Cutscene.cleargrid(g_Console, 53, 12);
                                                                                    if (g_dslashTutWasp > 1.05)
                                                                                    {
                                                                                        Cutscene.clearSprite(g_Console);
                                                                                        Sprites.Tutorial_Wasp(g_Console, 2);
                                                                                        if (g_dslashTutWasp > 1.1)
                                                                                        {
                                                                                            Cutscene.clearSprite(g_Console);
                                                                                            Sprites.Tutorial_Wasp(g_Console, 4);
                                                                                            if (g_dslashTutWasp > 1.15)
                                                                                            {
                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                Sprites.Tutorial_Wasp(g_Console, 2);
                                                                                                if (g_dslashTutWasp > 1.20)
                                                                                                {
                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                    Sprites.Tutorial_Wasp(g_Console, 0);
                                                                                                    if (g_dslashTutWasp > 1.25)
                                                                                                    {
                                                                                                        Cutscene.clearSprite(g_Console);
                                                                                                        Sprites.Tutorial_Wasp(g_Console, -2);
                                                                                                        if (g_dslashTutWasp > 1.30)
                                                                                                        {
                                                                                                            Cutscene.clearSprite(g_Console);
                                                                                                            Sprites.Tutorial_Wasp(g_Console, -4);
                                                                                                            if (g_dslashTutWasp > 1.35)
                                                                                                            {
                                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                                Sprites.Tutorial_Wasp(g_Console, -2);
                                                                                                                if (g_dslashTutWasp > 1.40)
                                                                                                                {
                                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                                    Sprites.Tutorial_Wasp(g_Console, 0);
                                                                                                                    if (g_dslashTutWasp > 1.45)
                                                                                                                    {
                                                                                                                        Cutscene.clearSprite(g_Console);
                                                                                                                        Sprites.Tutorial_Wasp(g_Console, 1);
                                                                                                                        if (g_dslashTutWasp > 1.50)
                                                                                                                        {
                                                                                                                            Cutscene.clearSprite(g_Console);
                                                                                                                            Sprites.Tutorial_Wasp(g_Console, 2);
                                                                                                                            if (g_dslashTutWasp > 1.55)
                                                                                                                            {
                                                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                                                Sprites.Tutorial_Wasp(g_Console, 1);
                                                                                                                                if (g_dslashTutWasp > 1.60)
                                                                                                                                {
                                                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                                                    Sprites.Tutorial_Wasp(g_Console, 0);
                                                                                                                                    if (g_dslashTutWasp > 1.65)
                                                                                                                                    {
                                                                                                                                        Cutscene.clearSprite(g_Console);
                                                                                                                                        Sprites.Tutorial_Wasp(g_Console, -1);
                                                                                                                                        if (g_dslashTutWasp > 1.70)
                                                                                                                                        {
                                                                                                                                            Cutscene.clearSprite(g_Console);
                                                                                                                                            Sprites.Tutorial_Wasp(g_Console, -2);
                                                                                                                                            if (g_dslashTutWasp > 1.75)
                                                                                                                                            {
                                                                                                                                                Cutscene.clearSprite(g_Console);
                                                                                                                                                Sprites.Tutorial_Wasp(g_Console, -1);
                                                                                                                                                if (g_dslashTutWasp > 1.80)
                                                                                                                                                {
                                                                                                                                                    Cutscene.clearSprite(g_Console);
                                                                                                                                                    Sprites.Tutorial_Wasp(g_Console, 0);
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
void Update_killTutWasp()
{
    if (g_dkillTutWasp > 3)
    {
        //g_eGameState = S_GAME;
    }
    processUserInput();
}
void killTutWasp()
{
    //rMap.initialise(g_Console);
    //rMap.Border(g_Console);
    COORD c;
    //renderCharacter();
    c.X = 3;
    c.Y = 2;
    g_Console.writeToBuffer(c, "=Tutorial Wasp=", 0x0A);
    //Sprites.Tutorial_Wasp(g_Console, 0);
    if (g_dkillTutWasp > 1.95)
    {
        Cutscene.clearSpriteLine(g_Console, 2);
        if (g_dkillTutWasp > 2.0)
        {
            Cutscene.clearSpriteLine(g_Console, 3);
            if (g_dkillTutWasp > 2.05)
            {
                Cutscene.clearSpriteLine(g_Console, 4);
                if (g_dkillTutWasp > 2.10)
                {
                    Cutscene.clearSpriteLine(g_Console, 5);
                    if (g_dkillTutWasp > 2.15)
                    {
                        Cutscene.clearSpriteLine(g_Console, 6);
                        if (g_dkillTutWasp > 2.20)
                        {
                            Cutscene.clearSpriteLine(g_Console, 7);
                            if (g_dkillTutWasp > 2.25)
                            {
                                Cutscene.clearSpriteLine(g_Console, 8);
                                if (g_dkillTutWasp > 2.30)
                                {
                                    Cutscene.clearSpriteLine(g_Console, 9);
                                    if (g_dkillTutWasp > 2.35)
                                    {
                                        Cutscene.clearSpriteLine(g_Console, 10);
                                        if (g_dkillTutWasp > 2.40)
                                        {
                                            Cutscene.clearSpriteLine(g_Console, 11);
                                            if (g_dkillTutWasp > 2.45)
                                            {
                                                Cutscene.clearSpriteLine(g_Console, 12);
                                                if (g_dkillTutWasp > 2.50)
                                                {
                                                    Cutscene.clearSpriteLine(g_Console, 13);
                                                    if (g_dkillTutWasp > 2.55)
                                                    {
                                                        Cutscene.clearSpriteLine(g_Console, 14);
                                                        if (g_dkillTutWasp > 2.60)
                                                        {
                                                            Cutscene.clearSpriteLine(g_Console, 15);
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
    g_sStinger.showItemDropped = true;
    static bool item7 = false;
    if (item7 == false)
    {
        Stinger.QuantityCheck("Stinger");
        item7 = true;
        if (item7 == true)
        {
            Stinger.QuantityCheck("Stinger");
        }
    }
}
void drawLaser(Console& g_Console, int j)
{
    if (laserTime3 > 1.00)
    {
        Cutscene.drawgrid(g_Console, 2 + j, 2, '\\');
        if (g_sChar.m_cLocation.X == (2 + j) && g_sChar.m_cLocation.Y == 2)
        {
            g_sChar.SetH(g_sChar.GetH() - 1);
        }
        if (laserTime3 > 1.05)
        {
            Cutscene.drawgrid(g_Console, 3 + j, 3, '\\');
            if (g_sChar.m_cLocation.X == (3 + j) && g_sChar.m_cLocation.Y == 3)
            {
                g_sChar.SetH(g_sChar.GetH() - 1);

            }
            if (laserTime3 > 1.1)
            {
                Cutscene.drawgrid(g_Console, 4 + j, 4, '\\');
                if (g_sChar.m_cLocation.X == (4 + j) && g_sChar.m_cLocation.Y == 4)
                {
                    g_sChar.SetH(g_sChar.GetH() - 1);

                }
                if (laserTime3 > 1.15)
                {
                    Cutscene.drawgridLaserRight(g_Console, 5 + j, 5);
                    if (g_sChar.m_cLocation.X == (5 + j) && g_sChar.m_cLocation.Y == 5)
                    {
                        g_sChar.SetH(g_sChar.GetH() - 1);

                    }
                    if (laserTime3 > 1.20)
                    {
                        Cutscene.drawgridLaserRight(g_Console, 6 + j, 6);
                        if (g_sChar.m_cLocation.X == (6 + j) && g_sChar.m_cLocation.Y == 6)
                        {
                            g_sChar.SetH(g_sChar.GetH() - 1);

                        }
                        if (laserTime3 > 1.25)
                        {
                            Cutscene.drawgridLaserRight(g_Console, 7 + j, 7);
                            if (g_sChar.m_cLocation.X == (7 + j) && g_sChar.m_cLocation.Y == 7)
                            {
                                g_sChar.SetH(g_sChar.GetH() - 1);

                            }
                            if (laserTime3 > 1.30)
                            {
                                Cutscene.drawgridLaserRight(g_Console, 8 + j, 8);
                                if (g_sChar.m_cLocation.X == (8 + j) && g_sChar.m_cLocation.Y == 8)
                                {
                                    g_sChar.SetH(g_sChar.GetH() - 1);

                                }
                                if (laserTime3 > 1.35)
                                {
                                    Cutscene.drawgridLaserRight(g_Console, 9 + j, 9);
                                    if (g_sChar.m_cLocation.X == (9 + j) && g_sChar.m_cLocation.Y == 9)
                                    {
                                        g_sChar.SetH(g_sChar.GetH() - 1);

                                    }
                                    if (laserTime3 > 1.40)
                                    {
                                        Cutscene.drawgridLaserRight(g_Console, 10 + j, 10);
                                        if (g_sChar.m_cLocation.X == (10 + j) && g_sChar.m_cLocation.Y == 10)
                                        {
                                            g_sChar.SetH(g_sChar.GetH() - 1);

                                        }
                                        if (laserTime3 > 1.45)
                                        {
                                            Cutscene.drawgridLaserRight(g_Console, 11 + j, 11);
                                            if (g_sChar.m_cLocation.X == (11 + j) && g_sChar.m_cLocation.Y == 11)
                                            {
                                                g_sChar.SetH(g_sChar.GetH() - 1);

                                            }
                                            if (laserTime3 > 1.50)
                                            {
                                                Cutscene.drawgridLaserRight(g_Console, 12 + j, 12);
                                                if (g_sChar.m_cLocation.X == (12 + j) && g_sChar.m_cLocation.Y == 12)
                                                {
                                                    g_sChar.SetH(g_sChar.GetH() - 1);

                                                }
                                                if (laserTime3 > 1.55)
                                                {
                                                    Cutscene.drawgridLaserRight(g_Console, 13 + j, 13);
                                                    if (g_sChar.m_cLocation.X == (13 + j) && g_sChar.m_cLocation.Y == 13)
                                                    {

                                                        g_sChar.SetH(g_sChar.GetH() - 1);

                                                    }
                                                    if (laserTime3 > 1.60)
                                                    {
                                                        Cutscene.drawgridLaserRight(g_Console, 14 + j, 14);
                                                        if (g_sChar.m_cLocation.X == (14 + j) && g_sChar.m_cLocation.Y == 14)
                                                        {
                                                            g_sChar.SetH(g_sChar.GetH() - 1);

                                                        }
                                                        if (laserTime3 > 1.65)
                                                        {
                                                            Cutscene.drawgridLaserRight(g_Console, 15 + j, 15);
                                                            if (g_sChar.m_cLocation.X == (15 + j) && g_sChar.m_cLocation.Y == 15)
                                                            {
                                                                g_sChar.SetH(g_sChar.GetH() - 1);

                                                            }
                                                            if (laserTime3 > 1.70)
                                                            {
                                                                Cutscene.drawgridLaserRight(g_Console, 16 + j, 16);
                                                                if (g_sChar.m_cLocation.X == (16 + j) && g_sChar.m_cLocation.Y == 16)
                                                                {
                                                                    g_sChar.SetH(g_sChar.GetH() - 1);

                                                                }
                                                                if (laserTime3 > 1.75)
                                                                {
                                                                    Cutscene.drawgridLaserRight(g_Console, 17 + j, 17);
                                                                    if (g_sChar.m_cLocation.X == (17 + j) && g_sChar.m_cLocation.Y == 17)
                                                                    {
                                                                        g_sChar.SetH(g_sChar.GetH() - 1);

                                                                    }
                                                                    if (laserTime3 > 1.80)
                                                                    {
                                                                        Cutscene.drawgridLaserRight(g_Console, 18 + j, 18);
                                                                        if (g_sChar.m_cLocation.X == (18 + j) && g_sChar.m_cLocation.Y == 18)
                                                                        {
                                                                            g_sChar.SetH(g_sChar.GetH() - 1);

                                                                        }
                                                                        if (laserTime3 > 1.85)
                                                                        {
                                                                            Cutscene.drawgridLaserRight(g_Console, 19 + j, 19);
                                                                            if (g_sChar.m_cLocation.X == (19 + j) && g_sChar.m_cLocation.Y == 19)
                                                                            {
                                                                                g_sChar.SetH(g_sChar.GetH() - 1);

                                                                            }
                                                                            if (laserTime3 > 1.90)
                                                                            {
                                                                                Cutscene.drawgridLaserRight(g_Console, 20 + j, 20);
                                                                                if (g_sChar.m_cLocation.X == (20 + j) && g_sChar.m_cLocation.Y == 20)
                                                                                {
                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);

                                                                                }
                                                                                if (laserTime3 > 1.95)
                                                                                {
                                                                                    Cutscene.drawgridLaserRight(g_Console, 21 + j, 21);
                                                                                    if (g_sChar.m_cLocation.X == (21 + j) && g_sChar.m_cLocation.Y == 21)
                                                                                    {
                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);

                                                                                    }
                                                                                    if (laserTime3 > 2.00)
                                                                                    {
                                                                                        Cutscene.drawgridLaserRight(g_Console, 22 + j, 22);
                                                                                        if (g_sChar.m_cLocation.X == (22 + j) && g_sChar.m_cLocation.Y == 22)
                                                                                        {
                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                        }
                                                                                        if (laserTime3 > 2.05)
                                                                                        {
                                                                                            Cutscene.drawgridLaserRight(g_Console, 23 + j, 23);
                                                                                            if (g_sChar.m_cLocation.X == (23 + j) && g_sChar.m_cLocation.Y == 23)
                                                                                            {
                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
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

void drawLaser2(Console& g_Console, int j)
{
    if (laserTime2 > 0)
    {
        Cutscene.drawgrid(g_Console, 77 - j, 2, '/');
        if (g_sChar.m_cLocation.X == (77 - j) && g_sChar.m_cLocation.Y == 2)
        {
            g_sChar.SetH(g_sChar.GetH() - 1);
        }
        if (laserTime2 > 0.05)
        {
            Cutscene.drawgrid(g_Console, 76 - j, 3, '/');
            if (g_sChar.m_cLocation.X == (76 - j) && g_sChar.m_cLocation.Y == 3)
            {
                g_sChar.SetH(g_sChar.GetH() - 1);

            }
            if (laserTime2 > 0.1)
            {
                Cutscene.drawgrid(g_Console, 75 - j, 4, '/');
                if (g_sChar.m_cLocation.X == (75 - j) && g_sChar.m_cLocation.Y == 4)
                {
                    g_sChar.SetH(g_sChar.GetH() - 1);

                }
                if (laserTime2 > 0.15)
                {
                    Cutscene.drawgridLaserLeft(g_Console, 74 - j, 5);
                    if (g_sChar.m_cLocation.X == (74 - j) && g_sChar.m_cLocation.Y == 5)
                    {
                        g_sChar.SetH(g_sChar.GetH() - 1);

                    }
                    if (laserTime2 > 0.20)
                    {
                        Cutscene.drawgridLaserLeft(g_Console, 73 - j, 6);
                        if (g_sChar.m_cLocation.X == (73 - j) && g_sChar.m_cLocation.Y == 6)
                        {
                            g_sChar.SetH(g_sChar.GetH() - 1);

                        }
                        if (laserTime2 > 0.25)
                        {
                            Cutscene.drawgridLaserLeft(g_Console, 72 - j, 7);
                            if (g_sChar.m_cLocation.X == (72 - j) && g_sChar.m_cLocation.Y == 7)
                            {
                                g_sChar.SetH(g_sChar.GetH() - 1);

                            }
                            if (laserTime2 > 0.30)
                            {
                                Cutscene.drawgridLaserLeft(g_Console, 71 - j, 8);
                                if (g_sChar.m_cLocation.X == (71 - j) && g_sChar.m_cLocation.Y == 8)
                                {
                                    g_sChar.SetH(g_sChar.GetH() - 1);

                                }
                                if (laserTime2 > 0.35)
                                {
                                    Cutscene.drawgridLaserLeft(g_Console, 70 - j, 9);
                                    if (g_sChar.m_cLocation.X == (70 - j) && g_sChar.m_cLocation.Y == 9)
                                    {
                                        g_sChar.SetH(g_sChar.GetH() - 1);

                                    }
                                    if (laserTime2 > 0.40)
                                    {
                                        Cutscene.drawgridLaserLeft(g_Console, (69 - j), 10);
                                        if (g_sChar.m_cLocation.X == (69 - j) && g_sChar.m_cLocation.Y == 10)
                                        {
                                            g_sChar.SetH(g_sChar.GetH() - 1);

                                        }
                                        if (laserTime2 > 0.45)
                                        {
                                            Cutscene.drawgridLaserLeft(g_Console, (68 - j), 11);
                                            if (g_sChar.m_cLocation.X == (68 - j) && g_sChar.m_cLocation.Y == 11)
                                            {
                                                g_sChar.SetH(g_sChar.GetH() - 1);

                                            }
                                            if (laserTime2 > 0.50)
                                            {
                                                Cutscene.drawgridLaserLeft(g_Console, (67 - j), 12);
                                                if (g_sChar.m_cLocation.X == (67 - j) && g_sChar.m_cLocation.Y == 12)
                                                {
                                                    g_sChar.SetH(g_sChar.GetH() - 1);

                                                }
                                                if (laserTime2 > 0.55)
                                                {
                                                    Cutscene.drawgridLaserLeft(g_Console, (66 - j), 13);
                                                    if (g_sChar.m_cLocation.X == (66 - j) && g_sChar.m_cLocation.Y == 13)
                                                    {
                                                        g_sChar.SetH(g_sChar.GetH() - 1);

                                                    }
                                                    if (laserTime2 > 0.60)
                                                    {
                                                        Cutscene.drawgridLaserLeft(g_Console, (65 - j), 14);
                                                        if (g_sChar.m_cLocation.X == (65 - j) && g_sChar.m_cLocation.Y == 14)
                                                        {
                                                            g_sChar.SetH(g_sChar.GetH() - 1);

                                                        }
                                                        if (laserTime2 > 0.65)
                                                        {
                                                            Cutscene.drawgridLaserLeft(g_Console, (64 - j), 15);
                                                            if (g_sChar.m_cLocation.X == (64 - j) && g_sChar.m_cLocation.Y == 15)
                                                            {
                                                                g_sChar.SetH(g_sChar.GetH() - 1);

                                                            }
                                                            if (laserTime2 > 0.70)
                                                            {
                                                                Cutscene.drawgridLaserLeft(g_Console, (63 - j), 16);
                                                                if (g_sChar.m_cLocation.X == (63 - j) && g_sChar.m_cLocation.Y == 16)
                                                                {
                                                                    g_sChar.SetH(g_sChar.GetH() - 1);

                                                                }
                                                                if (laserTime2 > 0.75)
                                                                {
                                                                    Cutscene.drawgridLaserLeft(g_Console, (62 - j), 17);
                                                                    if (g_sChar.m_cLocation.X == (62 - j) && g_sChar.m_cLocation.Y == 17)
                                                                    {
                                                                        g_sChar.SetH(g_sChar.GetH() - 1);

                                                                    }
                                                                    if (laserTime2 > 0.80)
                                                                    {
                                                                        Cutscene.drawgridLaserLeft(g_Console, (61 - j), 18);
                                                                        if (g_sChar.m_cLocation.X == (61 - j) && g_sChar.m_cLocation.Y == 18)
                                                                        {
                                                                            g_sChar.SetH(g_sChar.GetH() - 1);

                                                                        }
                                                                        if (laserTime2 > 0.85)
                                                                        {
                                                                            Cutscene.drawgridLaserLeft(g_Console, (60 - j), 19);
                                                                            if (g_sChar.m_cLocation.X == (60 - j) && g_sChar.m_cLocation.Y == 19)
                                                                            {
                                                                                g_sChar.SetH(g_sChar.GetH() - 1);

                                                                            }
                                                                            if (laserTime2 > 0.90)
                                                                            {
                                                                                Cutscene.drawgridLaserLeft(g_Console, (59 - j), 20);
                                                                                if (g_sChar.m_cLocation.X == (59 - j) && g_sChar.m_cLocation.Y == 20)
                                                                                {
                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);

                                                                                }
                                                                                if (laserTime2 > 0.95)
                                                                                {
                                                                                    Cutscene.drawgridLaserLeft(g_Console, (58 - j), 21);
                                                                                    if (g_sChar.m_cLocation.X == (58 - j) && g_sChar.m_cLocation.Y == 21)
                                                                                    {
                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);

                                                                                    }
                                                                                    if (laserTime2 > 1.00)
                                                                                    {
                                                                                        Cutscene.drawgridLaserLeft(g_Console, (57 - j), 22);
                                                                                        if (g_sChar.m_cLocation.X == (57 - j) && g_sChar.m_cLocation.Y == 22)
                                                                                        {
                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);

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


void drawLaser3(Console& g_Console, int j)
{
    if (g_dphase2Time > 1.00)
    {
        Cutscene.stickmanLeft(g_Console, 2, j);
        if (g_sChar.m_cLocation.X == 2 && g_sChar.m_cLocation.Y == j)
        {
            g_sChar.SetH(g_sChar.GetH() - 1);
        }
        if (g_dphase2Time > 1.05)
        {
            Cutscene.stickmanLeft(g_Console, 3, j);
            if (g_sChar.m_cLocation.X == 3 && g_sChar.m_cLocation.Y == j)
            {
                g_sChar.SetH(g_sChar.GetH() - 1);
            }
            if (g_dphase2Time > 1.10)
            {
                Cutscene.stickmanLeft(g_Console, 4, j);
                if (g_sChar.m_cLocation.X == 4 && g_sChar.m_cLocation.Y == j)
                {
                    g_sChar.SetH(g_sChar.GetH() - 1);
                }
                if (g_dphase2Time > 1.15)
                {
                    Cutscene.stickmanLeft(g_Console, 5, j);
                    if (g_sChar.m_cLocation.X == 5 && g_sChar.m_cLocation.Y == j)
                    {
                        g_sChar.SetH(g_sChar.GetH() - 1);
                    }
                    if (g_dphase2Time > 1.20)
                    {
                        Cutscene.stickmanLeft(g_Console, 6, j);
                        if (g_sChar.m_cLocation.X == 6 && g_sChar.m_cLocation.Y == j)
                        {
                            g_sChar.SetH(g_sChar.GetH() - 1);
                        }
                        if (g_dphase2Time > 1.25)
                        {
                            Cutscene.stickmanLeft(g_Console, 7, j);
                            if (g_sChar.m_cLocation.X == 7 && g_sChar.m_cLocation.Y == j)
                            {
                                g_sChar.SetH(g_sChar.GetH() - 1);
                            }
                            if (g_dphase2Time > 1.30)
                            {
                                Cutscene.stickmanLeft(g_Console, 8, j);
                                if (g_sChar.m_cLocation.X == 8 && g_sChar.m_cLocation.Y == j)
                                {
                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                }
                                if (g_dphase2Time > 1.35)
                                {
                                    Cutscene.stickmanLeft(g_Console, 9, j);
                                    if (g_sChar.m_cLocation.X == 9 && g_sChar.m_cLocation.Y == j)
                                    {
                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                    }
                                    if (g_dphase2Time > 1.40)
                                    {
                                        Cutscene.stickmanLeft(g_Console, 10, j);
                                        if (g_sChar.m_cLocation.X == 10 && g_sChar.m_cLocation.Y == j)
                                        {
                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                        }
                                        if (g_dphase2Time > 1.45)
                                        {
                                            Cutscene.stickmanLeft(g_Console, 11, j);
                                            if (g_sChar.m_cLocation.X == 11 && g_sChar.m_cLocation.Y == j)
                                            {
                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                            }
                                            if (g_dphase2Time > 1.50)
                                            {
                                                Cutscene.stickmanLeft(g_Console, 12, j);
                                                if (g_sChar.m_cLocation.X == 12 && g_sChar.m_cLocation.Y == j)
                                                {
                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                }
                                                if (g_dphase2Time > 1.55)
                                                {
                                                    Cutscene.stickmanLeft(g_Console, 13, j);
                                                    if (g_sChar.m_cLocation.X == 13 && g_sChar.m_cLocation.Y == j)
                                                    {
                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                    }
                                                    if (g_dphase2Time > 1.60)
                                                    {
                                                        Cutscene.stickmanLeft(g_Console, 14, j);
                                                        if (g_sChar.m_cLocation.X == 14 && g_sChar.m_cLocation.Y == j)
                                                        {
                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                        }
                                                        if (g_dphase2Time > 1.65)
                                                        {
                                                            Cutscene.stickmanLeft(g_Console, 15, j);
                                                            if (g_sChar.m_cLocation.X == 15 && g_sChar.m_cLocation.Y == j)
                                                            {
                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                            }
                                                            if (g_dphase2Time > 1.70)
                                                            {
                                                                Cutscene.stickmanLeft(g_Console, 16, j);
                                                                if (g_sChar.m_cLocation.X == 16 && g_sChar.m_cLocation.Y == j)
                                                                {
                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                }
                                                                if (g_dphase2Time > 1.75)
                                                                {
                                                                    Cutscene.stickmanLeft(g_Console, 17, j);
                                                                    if (g_sChar.m_cLocation.X == 17 && g_sChar.m_cLocation.Y == j)
                                                                    {
                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                    }
                                                                    if (g_dphase2Time > 1.80)
                                                                    {
                                                                        Cutscene.stickmanLeft(g_Console, 18, j);
                                                                        if (g_sChar.m_cLocation.X == 18 && g_sChar.m_cLocation.Y == j)
                                                                        {
                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                        }
                                                                        if (g_dphase2Time > 1.85)
                                                                        {
                                                                            Cutscene.stickmanLeft(g_Console, 19, j);
                                                                            if (g_sChar.m_cLocation.X == 19 && g_sChar.m_cLocation.Y == j)
                                                                            {
                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                            }
                                                                            if (g_dphase2Time > 1.90)
                                                                            {
                                                                                Cutscene.stickmanLeft(g_Console, 20, j);
                                                                                if (g_sChar.m_cLocation.X == 20 && g_sChar.m_cLocation.Y == j)
                                                                                {
                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                }
                                                                                if (g_dphase2Time > 1.95)
                                                                                {
                                                                                    Cutscene.stickmanLeft(g_Console, 21, j);
                                                                                    if (g_sChar.m_cLocation.X == 21 && g_sChar.m_cLocation.Y == j)
                                                                                    {
                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                    }
                                                                                    if (g_dphase2Time > 2.00)
                                                                                    {
                                                                                        Cutscene.stickmanLeft(g_Console, 22, j);
                                                                                        if (g_sChar.m_cLocation.X == 22 && g_sChar.m_cLocation.Y == j)
                                                                                        {
                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                        }
                                                                                        if (g_dphase2Time > 2.05)
                                                                                        {
                                                                                            Cutscene.stickmanLeft(g_Console, 23, j);
                                                                                            if (g_sChar.m_cLocation.X == 23 && g_sChar.m_cLocation.Y == j)
                                                                                            {
                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                            }
                                                                                            if (g_dphase2Time > 2.10)
                                                                                            {
                                                                                                Cutscene.stickmanLeft(g_Console, 24, j);
                                                                                                if (g_sChar.m_cLocation.X == 24 && g_sChar.m_cLocation.Y == j)
                                                                                                {
                                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                }
                                                                                                if (g_dphase2Time > 2.15)
                                                                                                {
                                                                                                    Cutscene.stickmanLeft(g_Console, 25, j);
                                                                                                    if (g_sChar.m_cLocation.X == 25 && g_sChar.m_cLocation.Y == j)
                                                                                                    {
                                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                    }
                                                                                                    if (g_dphase2Time > 2.20)
                                                                                                    {
                                                                                                        Cutscene.stickmanLeft(g_Console, 26, j);
                                                                                                        if (g_sChar.m_cLocation.X == 26 && g_sChar.m_cLocation.Y == j)
                                                                                                        {
                                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                        }
                                                                                                        if (g_dphase2Time > 2.25)
                                                                                                        {
                                                                                                            Cutscene.stickmanLeft(g_Console, 27, j);
                                                                                                            if (g_sChar.m_cLocation.X == 27 && g_sChar.m_cLocation.Y == j)
                                                                                                            {
                                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                            }
                                                                                                            if (g_dphase2Time > 2.30)
                                                                                                            {
                                                                                                                Cutscene.stickmanLeft(g_Console, 28, j);
                                                                                                                if (g_sChar.m_cLocation.X == 28 && g_sChar.m_cLocation.Y == j)
                                                                                                                {
                                                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                }
                                                                                                                if (g_dphase2Time > 2.35)
                                                                                                                {
                                                                                                                    Cutscene.stickmanLeft(g_Console, 29, j);
                                                                                                                    if (g_sChar.m_cLocation.X == 29 && g_sChar.m_cLocation.Y == j)
                                                                                                                    {
                                                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                    }
                                                                                                                    if (g_dphase2Time > 2.40)
                                                                                                                    {
                                                                                                                        Cutscene.stickmanLeft(g_Console, 30, j);
                                                                                                                        if (g_sChar.m_cLocation.X == 30 && g_sChar.m_cLocation.Y == j)
                                                                                                                        {
                                                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                        }
                                                                                                                        if (g_dphase2Time > 2.45)
                                                                                                                        {
                                                                                                                            Cutscene.stickmanLeft(g_Console, 31, j);
                                                                                                                            if (g_sChar.m_cLocation.X == 31 && g_sChar.m_cLocation.Y == j)
                                                                                                                            {
                                                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                            }
                                                                                                                            if (g_dphase2Time > 2.50)
                                                                                                                            {
                                                                                                                                Cutscene.stickmanLeft(g_Console, 32, j);
                                                                                                                                if (g_sChar.m_cLocation.X == 32 && g_sChar.m_cLocation.Y == j)
                                                                                                                                {
                                                                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                }
                                                                                                                                if (g_dphase2Time > 2.55)
                                                                                                                                {
                                                                                                                                    Cutscene.stickmanLeft(g_Console, 33, j);
                                                                                                                                    if (g_sChar.m_cLocation.X == 33 && g_sChar.m_cLocation.Y == j)
                                                                                                                                    {
                                                                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                    }
                                                                                                                                    if (g_dphase2Time > 2.60)
                                                                                                                                    {
                                                                                                                                        Cutscene.stickmanLeft(g_Console, 34, j);
                                                                                                                                        if (g_sChar.m_cLocation.X == 34 && g_sChar.m_cLocation.Y == j)
                                                                                                                                        {
                                                                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                        }
                                                                                                                                        if (g_dphase2Time > 2.65)
                                                                                                                                        {
                                                                                                                                            Cutscene.stickmanLeft(g_Console, 35, j);
                                                                                                                                            if (g_sChar.m_cLocation.X == 35 && g_sChar.m_cLocation.Y == j)
                                                                                                                                            {
                                                                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                            }
                                                                                                                                            if (g_dphase2Time > 2.70)
                                                                                                                                            {
                                                                                                                                                Cutscene.stickmanLeft(g_Console, 36, j);
                                                                                                                                                if (g_sChar.m_cLocation.X == 36 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                {
                                                                                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                }
                                                                                                                                                if (g_dphase2Time > 2.75)
                                                                                                                                                {
                                                                                                                                                    Cutscene.stickmanLeft(g_Console, 37, j);
                                                                                                                                                    if (g_sChar.m_cLocation.X == 37 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                    {
                                                                                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                    }
                                                                                                                                                    if (g_dphase2Time > 2.80)
                                                                                                                                                    {
                                                                                                                                                        Cutscene.stickmanLeft(g_Console, 38, j);
                                                                                                                                                        if (g_sChar.m_cLocation.X == 38 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                        {
                                                                                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                        }
                                                                                                                                                        if (g_dphase2Time > 2.85)
                                                                                                                                                        {
                                                                                                                                                            Cutscene.stickmanLeft(g_Console, 39, j);
                                                                                                                                                            if (g_sChar.m_cLocation.X == 39 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                            {
                                                                                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                            }
                                                                                                                                                            if (g_dphase2Time > 2.90)
                                                                                                                                                            {
                                                                                                                                                                Cutscene.stickmanLeft(g_Console, 40, j);
                                                                                                                                                                if (g_sChar.m_cLocation.X == 40 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                {
                                                                                                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                }
                                                                                                                                                                if (g_dphase2Time > 2.95)
                                                                                                                                                                {
                                                                                                                                                                    Cutscene.stickmanLeft(g_Console, 41, j);
                                                                                                                                                                    if (g_sChar.m_cLocation.X == 41 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                    {
                                                                                                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                    }
                                                                                                                                                                    if (g_dphase2Time > 3.00)
                                                                                                                                                                    {
                                                                                                                                                                        Cutscene.stickmanLeft(g_Console, 42, j);
                                                                                                                                                                        if (g_sChar.m_cLocation.X == 42 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                        {
                                                                                                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                        }
                                                                                                                                                                        if (g_dphase2Time > 3.05)
                                                                                                                                                                        {
                                                                                                                                                                            Cutscene.stickmanLeft(g_Console, 43, j);
                                                                                                                                                                            if (g_sChar.m_cLocation.X == 43 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                            {
                                                                                                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                            }
                                                                                                                                                                            if (g_dphase2Time > 3.10)
                                                                                                                                                                            {
                                                                                                                                                                                Cutscene.stickmanLeft(g_Console, 44, j);
                                                                                                                                                                                if (g_sChar.m_cLocation.X == 44 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                {
                                                                                                                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                }
                                                                                                                                                                                if (g_dphase2Time > 3.15)
                                                                                                                                                                                {
                                                                                                                                                                                    Cutscene.stickmanLeft(g_Console, 45, j);
                                                                                                                                                                                    if (g_sChar.m_cLocation.X == 45 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                    {
                                                                                                                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                    }
                                                                                                                                                                                    if (g_dphase2Time > 3.20)
                                                                                                                                                                                    {
                                                                                                                                                                                        Cutscene.stickmanLeft(g_Console, 46, j);
                                                                                                                                                                                        if (g_sChar.m_cLocation.X == 46 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                        {
                                                                                                                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                        }
                                                                                                                                                                                        if (g_dphase2Time > 3.25)
                                                                                                                                                                                        {
                                                                                                                                                                                            Cutscene.stickmanLeft(g_Console, 47, j);
                                                                                                                                                                                            if (g_sChar.m_cLocation.X == 47 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                            {
                                                                                                                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                            }
                                                                                                                                                                                            if (g_dphase2Time > 3.30)
                                                                                                                                                                                            {
                                                                                                                                                                                                Cutscene.stickmanLeft(g_Console, 48, j);
                                                                                                                                                                                                if (g_sChar.m_cLocation.X == 48 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                {
                                                                                                                                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                }
                                                                                                                                                                                                if (g_dphase2Time > 3.35)
                                                                                                                                                                                                {
                                                                                                                                                                                                    Cutscene.stickmanLeft(g_Console, 49, j);
                                                                                                                                                                                                    if (g_sChar.m_cLocation.X == 49 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                    {
                                                                                                                                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                    }
                                                                                                                                                                                                    if (g_dphase2Time > 3.40)
                                                                                                                                                                                                    {
                                                                                                                                                                                                        Cutscene.stickmanLeft(g_Console, 50, j);
                                                                                                                                                                                                        if (g_sChar.m_cLocation.X == 50 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                        {
                                                                                                                                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                        }
                                                                                                                                                                                                        if (g_dphase2Time > 3.45)
                                                                                                                                                                                                        {
                                                                                                                                                                                                            Cutscene.stickmanLeft(g_Console, 51, j);
                                                                                                                                                                                                            if (g_sChar.m_cLocation.X == 51 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                            {
                                                                                                                                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                            }
                                                                                                                                                                                                            if (g_dphase2Time > 3.50)
                                                                                                                                                                                                            {
                                                                                                                                                                                                                Cutscene.stickmanLeft(g_Console, 52, j);
                                                                                                                                                                                                                if (g_sChar.m_cLocation.X == 52 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                }
                                                                                                                                                                                                                if (g_dphase2Time > 3.55)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                    Cutscene.stickmanLeft(g_Console, 53, j);
                                                                                                                                                                                                                    if (g_sChar.m_cLocation.X == 53 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                    {
                                                                                                                                                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                    }
                                                                                                                                                                                                                    if (g_dphase2Time > 3.60)
                                                                                                                                                                                                                    {
                                                                                                                                                                                                                        Cutscene.stickmanLeft(g_Console, 54, j);
                                                                                                                                                                                                                        if (g_sChar.m_cLocation.X == 54 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                        {
                                                                                                                                                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                        }
                                                                                                                                                                                                                        if (g_dphase2Time > 3.65)
                                                                                                                                                                                                                        {
                                                                                                                                                                                                                            Cutscene.stickmanLeft(g_Console, 55, j);
                                                                                                                                                                                                                            if (g_sChar.m_cLocation.X == 55 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                            if (g_dphase2Time > 3.70)
                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                Cutscene.stickmanLeft(g_Console, 56, j);
                                                                                                                                                                                                                                if (g_sChar.m_cLocation.X == 56 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                if (g_dphase2Time > 3.75)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                    Cutscene.stickmanLeft(g_Console, 57, j);
                                                                                                                                                                                                                                    if (g_sChar.m_cLocation.X == 57 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                    if (g_dphase2Time > 3.80)
                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                        Cutscene.stickmanLeft(g_Console, 58, j);
                                                                                                                                                                                                                                        if (g_sChar.m_cLocation.X == 58 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                        if (g_dphase2Time > 3.85)
                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                            Cutscene.stickmanLeft(g_Console, 59, j);
                                                                                                                                                                                                                                            if (g_sChar.m_cLocation.X == 59 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                            if (g_dphase2Time > 3.90)
                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                Cutscene.stickmanLeft(g_Console, 60, j);
                                                                                                                                                                                                                                                if (g_sChar.m_cLocation.X == 60 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                if (g_dphase2Time > 3.95)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                    Cutscene.stickmanLeft(g_Console, 61, j);
                                                                                                                                                                                                                                                    if (g_sChar.m_cLocation.X == 61 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                    if (g_dphase2Time > 4.00)
                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                        Cutscene.stickmanLeft(g_Console, 62, j);
                                                                                                                                                                                                                                                        if (g_sChar.m_cLocation.X == 62 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                        if (g_dphase2Time > 4.05)
                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                            Cutscene.stickmanLeft(g_Console, 63, j);
                                                                                                                                                                                                                                                            if (g_sChar.m_cLocation.X == 63 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                            if (g_dphase2Time > 4.10)
                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                Cutscene.stickmanLeft(g_Console, 64, j);
                                                                                                                                                                                                                                                                if (g_sChar.m_cLocation.X == 64 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                if (g_dphase2Time > 4.15)
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                    Cutscene.stickmanLeft(g_Console, 65, j);
                                                                                                                                                                                                                                                                    if (g_sChar.m_cLocation.X == 65 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                    if (g_dphase2Time > 4.20)
                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                        Cutscene.stickmanLeft(g_Console, 66, j);
                                                                                                                                                                                                                                                                        if (g_sChar.m_cLocation.X == 66 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                        if (g_dphase2Time > 4.25)
                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                            Cutscene.stickmanLeft(g_Console, 67, j);
                                                                                                                                                                                                                                                                            if (g_sChar.m_cLocation.X == 67 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                            if (g_dphase2Time > 4.30)
                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                Cutscene.stickmanLeft(g_Console, 68, j);
                                                                                                                                                                                                                                                                                if (g_sChar.m_cLocation.X == 68 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                if (g_dphase2Time > 4.35)
                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                    Cutscene.stickmanLeft(g_Console, 69, j);
                                                                                                                                                                                                                                                                                    if (g_sChar.m_cLocation.X == 69 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                    if (g_dphase2Time > 4.40)
                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                        Cutscene.stickmanLeft(g_Console, 70, j);
                                                                                                                                                                                                                                                                                        if (g_sChar.m_cLocation.X == 70 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                        if (g_dphase2Time > 4.45)
                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                            Cutscene.stickmanLeft(g_Console, 71, j);
                                                                                                                                                                                                                                                                                            if (g_sChar.m_cLocation.X == 71 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                            if (g_dphase2Time > 4.50)
                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                Cutscene.stickmanLeft(g_Console, 72, j);
                                                                                                                                                                                                                                                                                                if (g_sChar.m_cLocation.X == 72 && g_sChar.m_cLocation.Y == j)
                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
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


void drawMovingBlock(Console& g_Console, int j)
{
    if (movingBlockTime > 1)
    {                                                                                      
        Cutscene.movingBlock(g_Console, 2 + j, 28);
        if (movingBlockTime > 1.1)
        {
            Cutscene.movingBlock(g_Console, 2 + j, 27);
            if (movingBlockTime > 1.2)
            {
                Cutscene.movingBlock(g_Console, 2 + j, 26);
                if (movingBlockTime > 1.3)
                {
                    Cutscene.movingBlock(g_Console, 2 + j, 25);
                    if (movingBlockTime > 1.4)
                    {
                        Cutscene.movingBlock(g_Console, 2 + j, 24);
                        if (movingBlockTime > 1.5)
                        {
                            Cutscene.movingBlock(g_Console, 2 + j, 25);
                            if (movingBlockTime > 1.6)
                            {
                                Cutscene.movingBlock(g_Console, 2 + j, 26);
                                if (movingBlockTime > 1.7)
                                {
                                    Cutscene.movingBlock(g_Console, 2 + j, 25);
                                    if (movingBlockTime > 1.8)
                                    {
                                        Cutscene.movingBlock(g_Console, 2 + j, 24);
                                        if (movingBlockTime > 1.9)
                                        {
                                            Cutscene.movingBlock(g_Console, 2 + j, 25);
                                            if (movingBlockTime > 2.0)
                                            {
                                                Cutscene.movingBlock(g_Console, 2 + j, 26);
                                                if (movingBlockTime > 2.1)
                                                {
                                                    Cutscene.movingBlock(g_Console, 2 + j, 25);
                                                    if (movingBlockTime > 2.2)
                                                    {
                                                        Cutscene.movingBlock(g_Console, 2 + j, 24);
                                                        if (movingBlockTime > 2.3)
                                                        {
                                                            Cutscene.movingBlock(g_Console, 2 + j, 23);
                                                            if (movingBlockTime > 2.35)
                                                            {
                                                                Cutscene.movingBlock(g_Console, 2 + j, 22);
                                                                for (int m = (2 + j); m < (11 + j); m++)
                                                                {
                                                                    if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == 22)
                                                                    {
                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                    }
                                                                }
                                                                if (movingBlockTime > 2.40)
                                                                {
                                                                    Cutscene.movingBlock(g_Console, 2 + j, 21);
                                                                    for (int n = 21; n < 23; n++)
                                                                    {
                                                                        for (int m = (2 + j); m < (11 + j); m++)
                                                                        {
                                                                            if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                            {
                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                            }
                                                                        }
                                                                    }
                                                                    if (movingBlockTime > 2.45)
                                                                    {
                                                                        Cutscene.movingBlock(g_Console, 2 + j, 20);
                                                                        for (int n = 20; n < 23; n++)
                                                                        {
                                                                            for (int m = (2 + j); m < (11 + j); m++)
                                                                            {
                                                                                if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                {
                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                }
                                                                            }
                                                                        }
                                                                        if (movingBlockTime > 2.5)
                                                                        {
                                                                            Cutscene.movingBlock(g_Console, 2 + j, 19);
                                                                            for (int n = 19; n < 23; n++)
                                                                            {
                                                                                for (int m = (2 + j); m < (11 + j); m++)
                                                                                {
                                                                                    if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                    {
                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                    }
                                                                                }
                                                                            }
                                                                            if (movingBlockTime > 2.55)
                                                                            {
                                                                                Cutscene.movingBlock(g_Console, 2 + j, 18);
                                                                                for (int n = 18; n < 23; n++)
                                                                                {
                                                                                    for (int m = (2 + j); m < (11 + j); m++)
                                                                                    {
                                                                                        if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                        {
                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                        }
                                                                                    }
                                                                                }
                                                                                if (movingBlockTime > 2.6)
                                                                                {
                                                                                    Cutscene.movingBlock(g_Console, 2 + j, 17);
                                                                                    for (int n = 17; n < 23; n++)
                                                                                    {
                                                                                        for (int m = (2 + j); m < (11 + j); m++)
                                                                                        {
                                                                                            if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                            {
                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                    if (movingBlockTime > 2.65)
                                                                                    {
                                                                                        Cutscene.movingBlock(g_Console, 2 + j, 16);
                                                                                        for (int n = 16; n < 23; n++)
                                                                                        {
                                                                                            for (int m = (2 + j); m < (11 + j); m++)
                                                                                            {
                                                                                                if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                                {
                                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                        if (movingBlockTime > 2.7)
                                                                                        {
                                                                                            Cutscene.movingBlock(g_Console, 2 + j, 15);
                                                                                            for (int n = 15; n < 23; n++)
                                                                                            {
                                                                                                for (int m = (2 + j); m < (11 + j); m++)
                                                                                                {
                                                                                                    if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                                    {
                                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                            if (movingBlockTime > 2.75)
                                                                                            {
                                                                                                Cutscene.movingBlock(g_Console, 2 + j, 14);
                                                                                                for (int n = 14; n < 23; n++)
                                                                                                {
                                                                                                    for (int m = (2 + j); m < (11 + j); m++)
                                                                                                    {
                                                                                                        if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                                        {
                                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                                if (movingBlockTime > 2.8)
                                                                                                {
                                                                                                    Cutscene.movingBlock(g_Console, 2 + j, 13);
                                                                                                    for (int n = 13; n < 23; n++)
                                                                                                    {
                                                                                                        for (int m = (2 + j); m < (11 + j); m++)
                                                                                                        {
                                                                                                            if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                                            {
                                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                    if (movingBlockTime > 2.85)
                                                                                                    {
                                                                                                        Cutscene.movingBlock(g_Console, 2 + j, 12);
                                                                                                        for (int n = 12; n < 23; n++)
                                                                                                        {
                                                                                                            for (int m = (2 + j); m < (11 + j); m++)
                                                                                                            {
                                                                                                                if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                                                {
                                                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                        if (movingBlockTime > 2.9)
                                                                                                        {
                                                                                                            Cutscene.movingBlock(g_Console, 2 + j, 11);
                                                                                                            for (int n = 11; n < 23; n++)
                                                                                                            {
                                                                                                                for (int m = (2 + j); m < (11 + j); m++)
                                                                                                                {
                                                                                                                    if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                                                    {
                                                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                            if (movingBlockTime > 2.95)
                                                                                                            {
                                                                                                                Cutscene.movingBlock(g_Console, 2 + j, 10);
                                                                                                                for (int n = 10; n < 23; n++)
                                                                                                                {
                                                                                                                    for (int m = (2 + j); m < (11 + j); m++)
                                                                                                                    {
                                                                                                                        if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                                                        {
                                                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                                if (movingBlockTime > 3.00)
                                                                                                                {
                                                                                                                    Cutscene.movingBlock(g_Console, 2 + j, 9);
                                                                                                                    for (int n = 9; n < 23; n++)
                                                                                                                    {
                                                                                                                        for (int m = (2 + j); m < (11 + j); m++)
                                                                                                                        {
                                                                                                                            if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                                                            {
                                                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                    if (movingBlockTime > 3.05)
                                                                                                                    {
                                                                                                                        Cutscene.movingBlock(g_Console, 2 + j, 8);
                                                                                                                        for (int n = 8; n < 23; n++)
                                                                                                                        {
                                                                                                                            for (int m = (2 + j); m < (11 + j); m++)
                                                                                                                            {
                                                                                                                                if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                                                                {
                                                                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                }
                                                                                                                            }
                                                                                                                        }
                                                                                                                        if (movingBlockTime > 3.1)
                                                                                                                        {
                                                                                                                            Cutscene.movingBlock(g_Console, 2 + j, 7);
                                                                                                                            for (int n = 7; n < 23; n++)
                                                                                                                            {
                                                                                                                                for (int m = (2 + j); m < (11 + j); m++)
                                                                                                                                {
                                                                                                                                    if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                                                                    {
                                                                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                    }
                                                                                                                                }
                                                                                                                            }
                                                                                                                            if (movingBlockTime > 3.15)
                                                                                                                            {
                                                                                                                                Cutscene.movingBlock(g_Console, 2 + j, 6);
                                                                                                                                for (int n = 6; n < 23; n++)
                                                                                                                                {
                                                                                                                                    for (int m = (2 + j); m < (11 + j); m++)
                                                                                                                                    {
                                                                                                                                        if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                                                                        {
                                                                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                }
                                                                                                                                if (movingBlockTime > 3.20)
                                                                                                                                {
                                                                                                                                    Cutscene.movingBlock(g_Console, 2 + j, 5);
                                                                                                                                    for (int n = 5; n < 23; n++)
                                                                                                                                    {
                                                                                                                                        for (int m = (2 + j); m < (11 + j); m++)
                                                                                                                                        {
                                                                                                                                            if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                                                                            {
                                                                                                                                                g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                    if (movingBlockTime > 3.25)
                                                                                                                                    {
                                                                                                                                        Cutscene.movingBlock(g_Console, 2 + j, 4);
                                                                                                                                        for (int n = 4; n < 23; n++)
                                                                                                                                        {
                                                                                                                                            for (int m = (2 + j); m < (11 + j); m++)
                                                                                                                                            {
                                                                                                                                                if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                                                                                {
                                                                                                                                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                        if (movingBlockTime > 3.30)
                                                                                                                                        {
                                                                                                                                            Cutscene.movingBlock(g_Console, 2 + j, 3);
                                                                                                                                            for (int n = 3; n < 23; n++)
                                                                                                                                            {
                                                                                                                                                for (int m = (2 + j); m < (11 + j); m++)
                                                                                                                                                {
                                                                                                                                                    if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                                                                                    {
                                                                                                                                                        g_sChar.SetH(g_sChar.GetH() - 1);
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                            if (movingBlockTime > 3.35)
                                                                                                                                            {
                                                                                                                                                Cutscene.movingBlock(g_Console, 2 + j, 2);
                                                                                                                                                for (int n = 2; n < 23; n++)
                                                                                                                                                {
                                                                                                                                                    for (int m = (2 + j); m < (11 + j); m++)
                                                                                                                                                    {
                                                                                                                                                        if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                                                                                                                                        {
                                                                                                                                                            g_sChar.SetH(g_sChar.GetH() - 1);
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

void drawBreakFloor(Console& g_Console, int k, int j)
{
    if (breakFloorTime > 1)
    {
        Cutscene.drawgridY(g_Console, k, j, '-');
        if (breakFloorTime > 1.3)
        {
            Cutscene.drawgridY(g_Console, k + 1, j, '-');
            Cutscene.drawgridY(g_Console, k, j + 1, '|');
            if (breakFloorTime > 1.5)
            {
                Cutscene.drawgridY(g_Console, k + 2, j, '-');
                Cutscene.drawgridY(g_Console, k - 1, j + 1, '_');
                if (breakFloorTime > 2.0)
                {
                    Cutscene.drawgridY(g_Console, k + 3, j, '-');
                    Cutscene.drawgridY(g_Console, k - 2, j + 2, '|');
                    if (breakFloorTime > 2.3)
                    {
                        Cutscene.breakFloor(g_Console, k, j);
                        for (int n = j; n < (j + 1); n++)
                        {
                            for (int m = k; m < (k + 11); m++)
                            {
                                if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                {
                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                }
                            }
                        }
                        for (int n = (j + 1); n < (j + 4); n++)
                        {
                            for (int m = (k - 2); m < (k + 13); m++)
                            {
                                if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                {
                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                }
                            }
                        }
                        for (int n = (j + 4); n < (j + 5); n++)
                        {
                            for (int m = (k - 1); m < (k + 12); m++)
                            {
                                if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                {
                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                }
                            }
                        }
                        for (int n = (j + 5); n < (j + 6); n++)
                        {
                            for (int m = k; m < (k + 11); m++)
                            {
                                if (g_sChar.m_cLocation.X == m && g_sChar.m_cLocation.Y == n)
                                {
                                    g_sChar.SetH(g_sChar.GetH() - 1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Update_phase2Battle()
{
    processUserInput();
    moveCharacter();
    if (laserTime > 1) // start time
    {
        g_sLaser.startTimer = false;
        g_sLaser2.startTimer = false;
        g_sLaser3.startTimer = false;
        g_sMovingBlock.startTimer = false;
        g_sBreakFloor.startTimer = false;
        g_sRaymond.startTimer = false;

    }
    if (g_dphase2Time > 5) // stickman
    {
        g_sLaser.startTimer = true;
        g_sLaser.counter = true;
    }
    if (laserTime2 > 1.1) // forward slash
    {
        g_sLaser2.startTimer = true;
        g_sLaser2.counter = true;
    }
    if (laserTime3 > 2.1) // back slash
    {
        g_sLaser3.startTimer = true;
        g_sLaser3.counter = true;
    }
    if (movingBlockTime > 4) //block thing
    {
        g_sMovingBlock.startTimer = true;
        g_sMovingBlock.counter = true;
    }
    if (breakFloorTime > 5) //break floor
    {
        g_sBreakFloor.startTimer = true;
        g_sBreakFloor.counter = true;
    }
    if (raymondTime > 10)
    {
        g_sRaymond.startTimer = true;
        g_sRaymond.counter = true;
    }
}
void phase2Battle()
{
    COORD c;


    if ((fightCount == 1) && (fightCount2 == 1) && (fightCount3 == 1) && (fightCount4 == 1) && (fightCount5 == 1))
    {
        if ((g_sBomb.m_cLocation.X == g_sRaymond.m_cLocation.X) && (g_sBomb.m_cLocation.Y == g_sRaymond.m_cLocation.Y)) // collison for R and B
        {
            g_sRaymondBoss.SetH(1);
            g_sChar.showPlayerDMG = false;
            g_sChar.showEnemyDMG = false;
            g_sRaymondBoss.counter = true;
            g_dkillRaymond = 0.0;
            g_eGameState = S_BattleScreen;
        }

    }
    if ((g_sChar.m_cLocation.X == g_sRaymond.m_cLocation.X) && (g_sChar.m_cLocation.Y == g_sRaymond.m_cLocation.Y)) // collison for Raymond and Robert
    {
        g_sChar.SetH(g_sChar.GetH() - 1); // minus dmg if robert touch raymond
    }
    while (phase2_music == false)
    {
        PlaySound(TEXT("For Peace.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        phase2_music = true;
    }


    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    c.X = 32;
    c.Y = 0;
    string charHealth = to_string(g_sChar.GetH());
    g_Console.writeToBuffer(c, "Your Health: " + charHealth, 0x0D, 100);
    static bool showPhase1 = true;
    if (showPhase1 == true)
    {
        c.X = 35;
        c.Y = 24;
        g_Console.writeToBuffer(c, "Phase 1", 0x0B, 100);
    }
    //drawLaser(g_Console, 20, 0, 0);
    //drawLaser(g_Console, 40, 0);

    if (g_sLaser.fight == true)
    {

        fightCount = 1;
        if (g_sLaser.startTimer == true) // stickman work
        {
            g_dphase2Time = 0.0;
            g_sLaser.resetTimer = true;
        }
        if (g_sLaser.resetTimer == true)
        {
            if (g_sLaser.counter == true)
            {
                randstickman = rand() % 22 + 2;
                randstickman2 = rand() % 22 + 2;
                randstickman3 = rand() % 22 + 2;

                g_sLaser.counter = false;
            }
            drawLaser3(g_Console, randstickman);
            drawLaser3(g_Console, randstickman2);
            drawLaser3(g_Console, randstickman3);
        }

    }

    if (g_sLaser2.fight == true)
    {
        fightCount2 = 1;
        if (g_sLaser2.startTimer == true) // stickman work
        {
            laserTime2 = 0.0;
            g_sLaser2.resetTimer = true;
        }
        if (g_sLaser2.resetTimer == true)
        {

            if (g_sLaser2.counter == true)
            {
                randnum = rand() % 70 + 1;
                randnum2 = rand() % 70 + 1;
                randnum3 = rand() % 70 + 1;
                randnum4 = rand() % 70 + 1;
                g_sLaser2.counter = false;
            }
            drawLaser2(g_Console, randnum);
            drawLaser2(g_Console, randnum2);
            drawLaser2(g_Console, randnum3);
            drawLaser2(g_Console, randnum4);
        }
        if (g_sLaser.fight == true)
        {

            if ((g_sBomb.m_cLocation.X == g_sRaymond.m_cLocation.X) && (g_sBomb.m_cLocation.Y == g_sRaymond.m_cLocation.Y)) // collison for R and B
            {
                g_sMovingBlock.fight = true;
                g_sBreakFloor.fight = true;
                int randPosX = rand() % (20 - 4 + 1) + 4;
                int randPosY = rand() % (20 - 3 + 1) + 3;

                g_sRaymond.m_cLocation.X = randPosX;
                g_sRaymond.m_cLocation.Y = randPosY;

                int randPosX2 = rand() % (70 - 57 + 1) + 57;
                int randPosY2 = rand() % (20 - 3 + 1) + 3;

                g_sBomb.m_cLocation.X = randPosX2;
                g_sBomb.m_cLocation.Y = randPosY2;
                c.X = 5;
                c.Y = 26;
                string ras = to_string(randPosX2);
                g_Console.writeToBuffer(c, ras, 100);
                // reset locations for bomb and raymond
            }
        }

    }
    
    if (g_sLaser3.fight == true)
    {
        static bool showPhase = true;
        if (showPhase == true)
        {
            c.X = 35;
            c.Y = 24;
            g_Console.writeToBuffer(c, "Phase 3", 0x0B, 100);
        }
        fightCount3 = 1;
        if (g_sLaser3.startTimer == true)
        {
            laserTime3 = 0.0;
            g_sLaser3.resetTimer = true;
        }
        if (g_sLaser3.resetTimer == true)
        {

            if (g_sLaser3.counter == true)
            {
                randnum5 = rand() % 70 + 1;
                randnum6 = rand() % 70 + 1;
                randnum7 = rand() % 70 + 1;
                randnum8 = rand() % 70 + 1;
                g_sLaser3.counter = false;
            }


            drawLaser(g_Console, randnum5);
            drawLaser(g_Console, randnum6);
            drawLaser(g_Console, randnum7);
            drawLaser(g_Console, randnum8);
            //drawHoriLaser(g_Console, randnum3);


            //drawVertLaser(g_Console, 0);

            //g_sLaser.resetTimer = false;
        }
        if ((g_sBomb.m_cLocation.X == g_sRaymond.m_cLocation.X) && (g_sBomb.m_cLocation.Y == g_sRaymond.m_cLocation.Y)) // collison for R and B
        {
            g_sLaser.fight = true;
            int randPosX = rand() % (20 - 4 + 1) + 4;
            int randPosY = rand() % (20 - 3 + 1) + 3;

            g_sRaymond.m_cLocation.X = randPosX;
            g_sRaymond.m_cLocation.Y = randPosY;

            int randPosX2 = rand() % (70 - 57 + 1) + 57;
            int randPosY2 = rand() % (20 - 3 + 1) + 3;

            g_sBomb.m_cLocation.X = randPosX2;
            g_sBomb.m_cLocation.Y = randPosY2;
            c.X = 5;
            c.Y = 26;
            string ras = to_string(randPosX2);
            g_Console.writeToBuffer(c, ras, 100);
            // reset locations for bomb and raymond
        }

    }

    if (g_sMovingBlock.fight == true)
    {

        fightCount4 = 1;
        if (g_sMovingBlock.startTimer == true) // stickman work
        {
            movingBlockTime = 0.0;
            g_sMovingBlock.resetTimer = true;
        }
        if (g_sMovingBlock.resetTimer == true)
        {
            if (g_sMovingBlock.counter == true)
            {
                randBlock = rand() % 69 + 2;
                randBlock2 = rand() % 69 + 2;
                randBlock3 = rand() % 69 + 2;
                g_sMovingBlock.counter = false;
            }
            drawMovingBlock(g_Console, randBlock);
            drawMovingBlock(g_Console, randBlock2);
            drawMovingBlock(g_Console, randBlock3);
        }
        if ((g_sBomb.m_cLocation.X == g_sRaymond.m_cLocation.X) && (g_sBomb.m_cLocation.Y == g_sRaymond.m_cLocation.Y)) // collison for R and B
        {
            //g_sLaser.fight = true;
            g_sLaser2.fight = true;
            g_sLaser3.fight = true;
            g_sBreakFloor.collected = false;
            g_sBreakFloor.fight = false;
            g_sMovingBlock.fight = false;
            int randPosX = rand() % (20 - 4 + 1) + 4;
            int randPosY = rand() % (20 - 3 + 1) + 3;

            g_sRaymond.m_cLocation.X = randPosX;
            g_sRaymond.m_cLocation.Y = randPosY;

            int randPosX2 = rand() % (70 - 57 + 1) + 57;
            int randPosY2 = rand() % (20 - 3 + 1) + 3;

            g_sBomb.m_cLocation.X = randPosX2;
            g_sBomb.m_cLocation.Y = randPosY2;
            c.X = 5;
            c.Y = 26;
            string ras = to_string(randPosX2);
            g_Console.writeToBuffer(c, ras, 100);
            // reset locations for bomb and raymond
        }

    }
    if (g_sBreakFloor.fight == true)
    {
        g_sBreakFloor.collected = true;
        if (g_sBreakFloor.startTimer == true) // stickman work
        {
            breakFloorTime = 0.0;
            g_sBreakFloor.resetTimer = true;
        }
        if (g_sBreakFloor.resetTimer == true)
        {
            if (g_sBreakFloor.counter == true)
            {
                randBreakFloor = rand() % (22 - 2 + 1) + 2;
                randBreakFloor2 = rand() % (17 - 2 + 1) + 2;
                randBreakFloor3 = rand() % (65 - 50 + 1) + 50;
                randBreakFloor4 = rand() % (17 - 2 + 1) + 2;
                g_sBreakFloor.counter = false;
            }
            drawBreakFloor(g_Console, randBreakFloor, randBreakFloor2);
            drawBreakFloor(g_Console, randBreakFloor3, randBreakFloor4);
            //drawLaser3(g_Console, randstickman2);
            //drawLaser3(g_Console, randstickman3);
        }
        if ((g_sBomb.m_cLocation.X == g_sRaymond.m_cLocation.X) && (g_sBomb.m_cLocation.Y == g_sRaymond.m_cLocation.Y)) // collison for R and B
        {
            g_sMovingBlock.fight = true;
            int randPosX = rand() % (20 - 4 + 1) + 4;
            int randPosY = rand() % (20 - 3 + 1) + 3;

            g_sRaymond.m_cLocation.X = randPosX;
            g_sRaymond.m_cLocation.Y = randPosY;

            int randPosX2 = rand() % (70 - 57 + 1) + 57;
            int randPosY2 = rand() % (20 - 3 + 1) + 3;
            g_sBomb.m_cLocation.X = randPosX2;
            g_sBomb.m_cLocation.Y = randPosY2;


            // reset locations for bomb and raymond
        }
    }
    if (g_sBreakFloor.collected == true)
    {
        fightCount5 = 1;
    }
    else
    {
        fightCount5 = 0;
    }
    renderCharacter();
    rMap.boss_room(g_Console);

    renderBomb();
    if ((g_sChar.m_cLocation.X == g_sBomb.m_cLocation.X) && (g_sChar.m_cLocation.Y == (g_sBomb.m_cLocation.Y)))
    {
        if (g_skKeyEvent[K_RIGHT].keyDown && g_sChar.m_cLocation.X < 76)
        {
            if (rMap.Grid[g_sBomb.m_cLocation.Y][g_sBomb.m_cLocation.X + 1] == ' ') // check if bomb == ' '
            {
                if (rMap.Grid[g_sBomb.m_cLocation.Y][g_sBomb.m_cLocation.X + 2] == ' ') // check if bomb == ' '
                {
                    g_sBomb.m_cLocation.X++;
                }
            }
        }
        if (g_skKeyEvent[K_UP].keyDown && g_sChar.m_cLocation.Y > 3)
        {
            if (rMap.Grid[g_sBomb.m_cLocation.Y - 1][g_sBomb.m_cLocation.X] == ' ')
            {
                if (rMap.Grid[g_sBomb.m_cLocation.Y - 2][g_sBomb.m_cLocation.X] == ' ')
                {
                    g_sBomb.m_cLocation.Y--;
                }
            }
        }
        if (g_skKeyEvent[K_DOWN].keyDown && g_sChar.m_cLocation.Y < 21)
        {
            if (rMap.Grid[g_sBomb.m_cLocation.Y + 1][g_sBomb.m_cLocation.X] == ' ')
            {
                if (rMap.Grid[g_sBomb.m_cLocation.Y + 2][g_sBomb.m_cLocation.X] == ' ')
                {
                    g_sBomb.m_cLocation.Y++;
                }
            }
        }
        if (g_skKeyEvent[K_LEFT].keyDown && g_sChar.m_cLocation.X > 3)
        {
            if (rMap.Grid[g_sBomb.m_cLocation.Y][g_sBomb.m_cLocation.X - 1] == ' ')
            {
                if (rMap.Grid[g_sBomb.m_cLocation.Y][g_sBomb.m_cLocation.X - 2] == ' ')
                {
                    g_sBomb.m_cLocation.X--;

                }

            }
        }
    }


    renderRaymond();
    if (g_sRaymond.startTimer == true)
    {
        raymondTime = 0.0;
        g_sRaymond.resetTimer = true;
    }
    if (g_sRaymond.resetTimer == true)
    {
        if (g_sRaymond.counter == true)
        {
            int randPosX = rand() % (20 - 4 + 1) + 4;
            int randPosY = rand() % (20 - 3 + 1) + 3;

            g_sRaymond.m_cLocation.X = randPosX;
            g_sRaymond.m_cLocation.Y = randPosY;

            c.X = 5;
            c.Y = 27;
            string ras = to_string(randPosX);
            g_Console.writeToBuffer(c, ras, 100);

            g_sRaymond.counter = false;
        }
    }
    bool showObj = true;
    if (showObj == true)
    {
        c.X = 5;
        c.Y = 26;
        g_Console.writeToBuffer(c, "Objective: Avoid the incoming objects and", 0x0B, 100);
        c.Y = 27;
        g_Console.writeToBuffer(c, "           Push the bomb ('B') to Raymond ('R') to move on to next phase", 0x0B, 100);

    }
    if ((g_sMovingBlock.fight == true) && (g_sBreakFloor.fight == true))
    {
        static bool showPhase = true;
        if (showPhase == true)
        {
            c.X = 35;
            c.Y = 24;
            g_Console.writeToBuffer(c, "Phase 2", 0x0B, 100);
        }
    }
    if ((g_sLaser.fight == true) && (g_sLaser2.fight == true) && (g_sLaser3.fight == true))
    {
        static bool showPhase = true;
        if (showPhase == true)
        {
            c.X = 35;
            c.Y = 24;
            g_Console.writeToBuffer(c, "Phase 4", 0x0B, 100);
        }
    }
    if ((g_sLaser.fight == true) && (g_sLaser2.fight == true) && (g_sLaser3.fight == true) && (g_sMovingBlock.fight == true) && (g_sBreakFloor.fight == true))
    {
        static bool showPhase = true;
        if (showPhase == true)
        {
            c.X = 35;
            c.Y = 24;
            g_Console.writeToBuffer(c, "Final Phase", 0x0B, 100);
        }
    }
    

}
void updateBomb()
{

}

void renderRaymond()
{
    g_Console.writeToBuffer(g_sRaymond.m_cLocation, 'R', 0x0C);
}

void renderBomb()
{
    g_Console.writeToBuffer(g_sBomb.m_cLocation, 'B', 0x0B);
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
        int m = g_sBox.m_cLocation.X;
        int n = g_sBox.m_cLocation.Y;
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
                                    if (rMap.Grid[j - 1][i] != '&')
                                    {
                                        g_sChar.m_cLocation.Y--;
                                    }
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
                                    if (rMap.Grid[j][i - 1] != '&')
                                    {
                                        g_sChar.m_cLocation.X--;
                                    }
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
                                    if (rMap.Grid[j + 1][i] != '&')
                                    {
                                        g_sChar.m_cLocation.Y++;
                                    }
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
                                    if (rMap.Grid[j][i + 1] != '&')
                                    {
                                        g_sChar.m_cLocation.X++;
                                    }
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
                    g_sGuard.xLeft = true; 
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
                    g_sGuard2.xLeft = true; 
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

        //minigame
    case S_wireGame: renderMap_wireGame();
        break;

        //Animations
    case S_Start_Animation: starting_cutscene();
        break;
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
    case S_Boss_Room_Mid_Animation: Boss_Room_Mid_Animation();
        break;
    case S_Boss_Room_End_Animation: Boss_End_Animation();
        break;
    case S_Presentation_Animation: Presentation_Animation();
        break;
    case S_BattleScreen: RenderBattleScreen();
        break;
    case S_Credits: Credits();
        break;

        //render battle animations
    //case S_SlashGuard: slashGuard();
        //break;
    case S_KillGuard: killGuard();
        break;
    case S_slashWasp: slashWasp();
        break;
    case S_killWasp: killWasp();
        break;
    case S_slashPig: slashPig();
        break;
    case S_killPig: killPig();
        break;
    case S_slashRaymond: slashRaymond();
        break;
    case S_killRaymond: killRaymond();
        break;
    case S_slashRobert: slashRobert();
        break;
    case S_killRobert: killRobert();
        break;
    case S_slashTutWasp: slashTutWasp();
        break;
    case S_killTutWasp: killTutWasp();
        break;

        //Raymond phase 2 battle
    case S_phase2Battle: phase2Battle();
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
    g_Console.clearBuffer(0x00);
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
        c.X = g_Console.getConsoleSize().X / 2 - 10;
        g_Console.writeToBuffer(c, "Press <Space> to change character colour", 0x09);
        c.Y += 1;
        c.X = g_Console.getConsoleSize().X / 2 - 9;
        g_Console.writeToBuffer(c, "Press 'Esc' to quit", 0x09);
    }

}

void renderGame()
{
    COORD c;  COORD d;

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
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Objective: Take the backpack before leaving the burning house!", 0x0B, 100);
            d.X = 5;
            d.Y = 28;
            g_Console.writeToBuffer(d, "B = Backpack", 0x0B, 100);
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
        g_Console.writeToBuffer(c, "Objective: Take the fire extinguisher and put out the fire!", 0x0B, 100);
        d.X = 5;
        d.Y = 28;
        g_Console.writeToBuffer(d, "'F' = Fire Extinguisher", 0x0B, 100);

    }
    /*
    if (rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == rMap.Grid[g_sEnemy.m_cLocation.Y][g_sEnemy.m_cLocation.X])
    {
        g_sChar.m_cLocation.X = 20;
        g_sChar.m_cLocation.Y = 17;
    }*/
    static bool showLoc = false;
    if (showLoc == false)
    {
        c.X = 33;
        c.Y = 0;
        g_Console.writeToBuffer(c, "Orphanage", 0x0F);
    }
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
    COORD c;
    while (townsquare_music == false)
    {
        PlaySound(TEXT("Land of 8 Bits.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        townsquare_music = true;
    }
    g_sChar.takenBackpack = false;
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.townsquare(g_Console);
    renderMap_NPC();
    g_sChar.talked = true;
    renderCharacter();  // renders the character into the buffer
    static bool showObj = false;
    if (showObj == false)
    {
        c.X = 5;
        c.Y = 26;
        g_Console.writeToBuffer(c, "Objective: Talk to all the NPCs before exiting", 0x0B, 100);
    }
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
        //showObj = true;
    }
    static bool showLoc = false;
    if (showLoc == false)
    {
        c.X = 33;
        c.Y = 0;
        g_Console.writeToBuffer(c, "Townsquare", 0x0F);
    }
}

void renderMap_Protest_Area()
{
    COORD c;
    srand((unsigned)time(0));
    //srand((unsigned)time(0));
    int Quantity = 0;
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.protest_area(g_Console);
    renderCharacter();  // renders the character into the buffer
    c.X = 62;
    c.Y = 4;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '&', 0x0D);
    static bool showObj = false;
    if (showObj == false)
    {
        c.X = 5;
        c.Y = 25;
        g_Console.writeToBuffer(c, "Objective: Collect Barrels '(B)' for consumables", 0x0B, 100);
    }
    if (g_sChar.enterArea == true)
    {
        c.X = 62;
        c.Y = 4;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '@', 0x0A);
    }
    if (g_sChar.m_cLocation.Y == 4 && g_sChar.m_cLocation.X == 62)
    {
        g_dPathTime = 0.0;
        g_eGameState = S_Dungeon_Stealth_3;
        g_sChar.m_cLocation.X = 69;
        g_sChar.m_cLocation.Y = 3;
    }

    if (rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == '@')
    {
        if (enterPathArea == true)
        {
            enterPathArea = false;
            g_dPathTime = 0.0;
            g_eGameState = S_Path_Area_Animation;
            g_sChar.m_cLocation.X = 41;
            g_sChar.m_cLocation.Y = 21;
        }
        else
        {
            g_eGameState = S_Path_Area;
            g_sChar.m_cLocation.X = 41;
            g_sChar.m_cLocation.Y = 21;
        }
    }
    

    if (g_sChar.m_cLocation.Y == 3 && g_sChar.m_cLocation.X == 3)
    {
        showCollect = 0.0;
        static int ItemChance = 0;
        static bool temp = false;
        if (temp == false)
        {
            ItemChance = rand() % 6 + 1;
            temp = true;
        }
        if (ItemChance == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(RawMeat.getQuantity());
            g_Console.writeToBuffer(c, "You received a Raw Meat. You now have " + Quantity + " Raw Meat.", 0x0F, 100);
            static bool item1 = false;
            if (item1 == false)
            {
                RawMeat.QuantityCheck("Raw Meat");
                item1 = true;
            }
        }

        else if (ItemChance == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Bread.getQuantity());
            g_Console.writeToBuffer(c, "You received a Bread. You now have " + Quantity + " Bread.", 0x0F, 100);
            static bool item2 = false;
            if (item2 == false)
            {
                Bread.QuantityCheck("Bread");
                item2 = true;
            }
        }
        else if (ItemChance == 3)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Burger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Burger. You now have " + Quantity + " Burger.", 0x0F, 100);
            static bool item3 = false;
            if (item3 == false)
            {
                Burger.QuantityCheck("Burger");
                item3 = true;
            }
        }
        else if (ItemChance == 4)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Taco.getQuantity());
            g_Console.writeToBuffer(c, "You received a Taco. You now have " + Quantity + " Taco.", 0x0F, 100);
            static bool item4 = false;
            if (item4 == false)
            {
                Taco.QuantityCheck("Taco");
                item4 = true;
            }
        }
        else if (ItemChance == 5)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Cake.getQuantity());
            g_Console.writeToBuffer(c, "You received a Cake. You now have " + Quantity + " Cake.", 0x0F, 100);
            static bool item5 = false;
            if (item5 == false)
            {
                Cake.QuantityCheck("Cake");
                item5 = true;
            }
        }
        else if (ItemChance == 6)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Medicine.getQuantity());
            g_Console.writeToBuffer(c, "You received a Medicine. You now have " + Quantity + " Medicine.", 0x0F, 100);
            static bool item6 = false;
            if (item6 == false)
            {
                Medicine.QuantityCheck("Medicine");
                item6 = true;
            }
        }
    }
    if (g_sChar.m_cLocation.Y == 4 && g_sChar.m_cLocation.X == 5)
    {
        showCollect = 0.0;
        static int ItemChance2 = 0;
        static bool temp2 = false;
        if (temp2 == false)
        {
            ItemChance2 = rand() % 6 + 1;
            temp2 = true;
        }
        if (ItemChance2 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(RawMeat.getQuantity());
            g_Console.writeToBuffer(c, "You received a Raw Meat. You now have " + Quantity + " Raw Meat.", 0x0F, 100);
            static bool item1 = false;
            if (item1 == false)
            {
                RawMeat.QuantityCheck("Raw Meat");
                item1 = true;
            }
        }
        else if (ItemChance2 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Bread.getQuantity());
            g_Console.writeToBuffer(c, "You received a Bread. You now have " + Quantity + " Bread.", 0x0F, 100);
            static bool item2 = false;
            if (item2 == false)
            {
                Bread.QuantityCheck("Bread");
                item2 = true;
            }
        }
        else if (ItemChance2 == 3)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Burger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Burger. You now have " + Quantity + " Burger.", 0x0F, 100);
            static bool item3 = false;
            if (item3 == false)
            {
                Burger.QuantityCheck("Burger");
                item3 = true;
            }
        }
        else if (ItemChance2 == 4)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Taco.getQuantity());
            g_Console.writeToBuffer(c, "You received a Taco. You now have " + Quantity + " Taco.", 0x0F, 100);
            static bool item4 = false;
            if (item4 == false)
            {
                Taco.QuantityCheck("Taco");
                item4 = true;
            }
        }
        else if (ItemChance2 == 5)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Cake.getQuantity());
            g_Console.writeToBuffer(c, "You received a Cake. You now have " + Quantity + " Cake.", 0x0F, 100);
            static bool item5 = false;
            if (item5 == false)
            {
                Cake.QuantityCheck("Cake");
                item5 = true;
            }
        }
        else if (ItemChance2 == 6)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Medicine.getQuantity());
            g_Console.writeToBuffer(c, "You received a Medicine. You now have " + Quantity + " Medicine.", 0x0F, 100);
            static bool item6 = false;
            if (item6 == false)
            {
                Medicine.QuantityCheck("Medicine");
                item6 = true;
            }
        }
    }

    if (g_sChar.m_cLocation.Y == 3 && g_sChar.m_cLocation.X == 6)
    {
        static int ItemChance3 = 0;
        static bool temp3 = false;
        if (temp3 == false)
        {
            ItemChance3 = rand() % 6 + 1;
            temp3 = true;
        }
        if (ItemChance3 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(RawMeat.getQuantity());
            g_Console.writeToBuffer(c, "You received a Raw Meat. You now have " + Quantity + " Raw Meat.", 0x0F, 100);
            static bool item1 = false;
            if (item1 == false)
            {
                RawMeat.QuantityCheck("Raw Meat");
                item1 = true;
            }
        }
        else if (ItemChance3 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Bread.getQuantity());
            g_Console.writeToBuffer(c, "You received a Bread. You now have " + Quantity + " Bread.", 0x0F, 100);
            static bool item2 = false;
            if (item2 == false)
            {
                Bread.QuantityCheck("Bread");
                item2 = true;
            }
        }
        else if (ItemChance3 == 3)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Burger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Burger. You now have " + Quantity + " Burger.", 0x0F, 100);
            static bool item3 = false;
            if (item3 == false)
            {
                Burger.QuantityCheck("Burger");
                item3 = true;
            }
        }
        else if (ItemChance3 == 4)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Taco.getQuantity());
            g_Console.writeToBuffer(c, "You received a Taco. You now have " + Quantity + " Taco.", 0x0F, 100);
            static bool item4 = false;
            if (item4 == false)
            {
                Taco.QuantityCheck("Taco");
                item4 = true;
            }
        }
        else if (ItemChance3 == 5)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Cake.getQuantity());
            g_Console.writeToBuffer(c, "You received a Cake. You now have " + Quantity + " Cake.", 0x0F, 100);
            static bool item5 = false;
            if (item5 == false)
            {
                Cake.QuantityCheck("Cake");
                item5 = true;
            }
        }
        else if (ItemChance3 == 6)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Medicine.getQuantity());
            g_Console.writeToBuffer(c, "You received a Medicine. You now have " + Quantity + " Medicine.", 0x0F, 100);
            static bool item6 = false;
            if (item6 == false)
            {
                Medicine.QuantityCheck("Medicine");
                item6 = true;
            }
        }
    }
    if (g_sChar.m_cLocation.Y == 2 && g_sChar.m_cLocation.X == 5)
    {
        showCollect = 0.0;
        static int ItemChance4 = 0;
        static bool temp4 = false;
        if (temp4 == false)
        {
            ItemChance4 = rand() % 6 + 1;
            temp4 = true;
        }
        if (ItemChance4 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(RawMeat.getQuantity());
            g_Console.writeToBuffer(c, "You received a Raw Meat. You now have " + Quantity + " Raw Meat.", 0x0F, 100);
            static bool item1 = false;
            if (item1 == false)
            {
                RawMeat.QuantityCheck("Raw Meat");
                item1 = true;
            }
        }
        else if (ItemChance4 == 2)

        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Bread.getQuantity());
            g_Console.writeToBuffer(c, "You received a Bread. You now have " + Quantity + " Bread.", 0x0F, 100);
            static bool item2 = false;
            if (item2 == false)
            {
                Bread.QuantityCheck("Bread");
                item2 = true;
            }
        }
        else if (ItemChance4 == 3)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Burger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Burger. You now have " + Quantity + " Burger.", 0x0F, 100);
            static bool item3 = false;
            if (item3 == false)
            {
                Burger.QuantityCheck("Burger");
                item3 = true;
            }
        }
        else if (ItemChance4 == 4)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Taco.getQuantity());
            g_Console.writeToBuffer(c, "You received a Taco. You now have " + Quantity + " Taco.", 0x0F, 100);
            static bool item4 = false;
            if (item4 == false)
            {
                Taco.QuantityCheck("Taco");
                item4 = true;
            }
        }
        else if (ItemChance4 == 5)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Cake.getQuantity());
            g_Console.writeToBuffer(c, "You received a Cake. You now have " + Quantity + " Cake.", 0x0F, 100);
            static bool item5 = false;
            if (item5 == false)
            {
                Cake.QuantityCheck("Cake");
                item5 = true;
            }
        }
        else if (ItemChance4 == 6)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Medicine.getQuantity());
            g_Console.writeToBuffer(c, "You received a Medicine. You now have " + Quantity + " Medicine.", 0x0F, 100);
            static bool item6 = false;
            if (item6 == false)
            {
                Medicine.QuantityCheck("Medicine");
                item6 = true;
            }
        }
    }
    if (g_sChar.m_cLocation.Y == 2 && g_sChar.m_cLocation.X == 8)
    {
        showCollect = 0.0;
        static int ItemChance5 = 0;
        static bool temp5 = false;
        if (temp5 == false)
        {
            ItemChance5 = rand() % 6 + 1;
            temp5 = true;
        }
        if (ItemChance5 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(RawMeat.getQuantity());
            g_Console.writeToBuffer(c, "You received a Raw Meat. You now have " + Quantity + " Raw Meat.", 0x0F, 100);
            static bool item1 = false;
            if (item1 == false)
            {
                RawMeat.QuantityCheck("Raw Meat");
                item1 = true;
            }
        }
        else if (ItemChance5 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Bread.getQuantity());
            g_Console.writeToBuffer(c, "You received a Bread. You now have " + Quantity + " Bread.", 0x0F, 100);
            static bool item2 = false;
            if (item2 == false)
            {
                Bread.QuantityCheck("Bread");
                item2 = true;
            }
        }
        else if (ItemChance5 == 3)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Burger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Burger. You now have " + Quantity + " Burger.", 0x0F, 100);
            static bool item3 = false;
            if (item3 == false)
            {
                Burger.QuantityCheck("Burger");
                item3 = true;
            }
        }
        else if (ItemChance5 == 4)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Taco.getQuantity());
            g_Console.writeToBuffer(c, "You received a Taco. You now have " + Quantity + " Taco.", 0x0F, 100);
            static bool item4 = false;
            if (item4 == false)
            {
                Taco.QuantityCheck("Taco");
                item4 = true;
            }
        }
        else if (ItemChance5 == 5)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Cake.getQuantity());
            g_Console.writeToBuffer(c, "You received a Cake. You now have " + Quantity + " Cake.", 0x0F, 100);
            static bool item5 = false;
            if (item5 == false)
            {
                Cake.QuantityCheck("Cake");
                item5 = true;
            }
        }
        else if (ItemChance5 == 6)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Medicine.getQuantity());
            g_Console.writeToBuffer(c, "You received a Medicine. You now have " + Quantity + " Medicine.", 0x0F, 100);
            static bool item6 = false;
            if (item6 == false)
            {
                Medicine.QuantityCheck("Medicine");
                item6 = true;
            }
        }
    }

    if (g_sChar.m_cLocation.Y == 3 && g_sChar.m_cLocation.X == 9)
    {
        showCollect = 0.0;
        static int ItemChance6 = 0;
        static bool temp6 = false;
        if (temp6 == false)
        {
            ItemChance6 = rand() % 6 + 1;
            temp6 = true;
        }
        if (ItemChance6 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(RawMeat.getQuantity());
            g_Console.writeToBuffer(c, "You received a Raw Meat. You now have " + Quantity + " Raw Meat.", 0x0F, 100);
            static bool item1 = false;
            if (item1 == false)
            {
                RawMeat.QuantityCheck("Raw Meat");
                item1 = true;
            }
        }
        else if (ItemChance6 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Bread.getQuantity());
            g_Console.writeToBuffer(c, "You received a Bread. You now have " + Quantity + " Bread.", 0x0F, 100);
            static bool item2 = false;
            if (item2 == false)
            {
                Bread.QuantityCheck("Bread");
                item2 = true;
            }
        }
        else if (ItemChance6 == 3)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Burger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Burger. You now have " + Quantity + " Burger.", 0x0F, 100);
            static bool item3 = false;
            if (item3 == false)
            {
                Burger.QuantityCheck("Burger");
                item3 = true;
            }
        }
        else if (ItemChance6 == 4)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Taco.getQuantity());
            g_Console.writeToBuffer(c, "You received a Taco. You now have " + Quantity + " Taco.", 0x0F, 100);
            static bool item4 = false;
            if (item4 == false)
            {
                Taco.QuantityCheck("Taco");
                item4 = true;
            }

        }
        else if (ItemChance6 == 5)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Cake.getQuantity());
            g_Console.writeToBuffer(c, "You received a Cake. You now have " + Quantity + " Cake.", 0x0F, 100);
            static bool item5 = false;
            if (item5 == false)
            {
                Cake.QuantityCheck("Cake");
                item5 = true;
            }
        }
        else if (ItemChance6 == 6)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Medicine.getQuantity());
            g_Console.writeToBuffer(c, "You received a Medicine. You now have " + Quantity + " Medicine.", 0x0F, 100);
            static bool item6 = false;
            if (item6 == false)
            {
                Medicine.QuantityCheck("Medicine");
                item6 = true;
            }
        }
    }

    if (g_sChar.m_cLocation.Y == 4 && g_sChar.m_cLocation.X == 8)
    {
        showCollect = 0.0;
        static int ItemChance7 = 0;
        static bool temp7 = false;
        if (temp7 == false)
        {
            ItemChance7 = rand() % 6 + 1;
            temp7 = true;
        }
        if (ItemChance7 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(RawMeat.getQuantity());
            g_Console.writeToBuffer(c, "You received a Raw Meat. You now have " + Quantity + " Raw Meat.", 0x0F, 100);
            static bool item1 = false;
            if (item1 == false)
            {
                RawMeat.QuantityCheck("Raw Meat");
                item1 = true;
            }
        }
        else if (ItemChance7 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Bread.getQuantity());
            g_Console.writeToBuffer(c, "You received a Bread. You now have " + Quantity + " Bread.", 0x0F, 100);
            static bool item2 = false;
            if (item2 == false)
            {
                Bread.QuantityCheck("Bread");
                item2 = true;
            }
        }
        else if (ItemChance7 == 3)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Burger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Burger. You now have " + Quantity + " Burger.", 0x0F, 100);
            static bool item3 = false;
            if (item3 == false)
            {
                Burger.QuantityCheck("Burger");
                item3 = true;
            }
        }
        else if (ItemChance7 == 4)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Taco.getQuantity());
            g_Console.writeToBuffer(c, "You received a Taco. You now have " + Quantity + " Taco.", 0x0F, 100);
            static bool item4 = false;
            if (item4 == false)
            {
                Taco.QuantityCheck("Taco");
                item4 = true;
            }
        }
        else if (ItemChance7 == 5)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Cake.getQuantity());
            g_Console.writeToBuffer(c, "You received a Cake. You now have " + Quantity + " Cake.", 0x0F, 100);
            static bool item5 = false;
            if (item5 == false)
            {
                Cake.QuantityCheck("Cake");
                item5 = true;
            }
        }
        else if (ItemChance7 == 6)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Medicine.getQuantity());
            g_Console.writeToBuffer(c, "You received a Medicine. You now have " + Quantity + " Medicine.", 0x0F, 100);
            static bool item6 = false;
            if (item6 == false)
            {
                Medicine.QuantityCheck("Medicine");
                item6 = true;
            }
        }
    }
    static bool showLoc = false;
    if (showLoc == false)
    {
        c.X = 33;
        c.Y = 0;
        g_Console.writeToBuffer(c, "Protest Area", 0x0F);
    }
}

void renderMap_Path_Area()
{
    while (game_music == false)
    {
        PlaySound(TEXT("8 Bit Surf.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        game_music = true;
    }
    COORD c, d;
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.patharea(g_Console);
    renderCharacter();  // renders the character into the buffer

    static bool showObj = false;
    if (showObj == false)
    {
        c.X = 5;
        c.Y = 26;
        g_Console.writeToBuffer(c, "Objective: Go up to the abandoned facility, go right ", 0x0B, 100);
        d.X = 5;
        d.Y = 27;
        g_Console.writeToBuffer(d, "           to medical facility, go down to enter protest area.", 0x0B, 100);
    }

    if (g_sChar.animationPlayed == true)
    {
        int i = 77;
        for (int j = 11; j < 15; j++)
        {
            c.X = i;
            c.Y = j;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '@', 0x0A);
        }
    }
    //to OAF area
    if (g_sChar.m_cLocation.Y == 2 && (g_sChar.m_cLocation.X == 37 || g_sChar.m_cLocation.X == 38 || g_sChar.m_cLocation.X == 39 || g_sChar.m_cLocation.X == 40 || g_sChar.m_cLocation.X == 41 || g_sChar.m_cLocation.X == 42 || g_sChar.m_cLocation.X == 43 || g_sChar.m_cLocation.X == 44 || g_sChar.m_cLocation.X == 45))
    {
        g_sChar.CP1 = true;
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
    static bool showLoc = false;
    if (showLoc == false)
    {
        c.X = 37;
        c.Y = 0;
        g_Console.writeToBuffer(c, "Path Area", 0x0F);
    }
}

//change this gamestate
void renderMap_OAF()
{
    COORD c, d;
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.outside_abandoned_facility(g_Console);
    renderCharacter();  // renders the character into the buffer
    renderPig();

    static bool showObj = false;
    if (showObj == false)
    {
        c.X = 5;
        c.Y = 26;
        g_Console.writeToBuffer(c, "Objective: Go right to enter the abandoned facility, go down ", 0x0B, 100);
        d.X = 5;
        d.Y = 27;
        g_Console.writeToBuffer(d, "           to go back to path area. You can fight pigs for resources.", 0x0B, 100);
    }

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
    if ((g_sChar.m_cLocation.Y + 1 == g_sPig.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sPig.m_cLocation.X) || (g_sChar.m_cLocation.Y - 1 == g_sPig.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sPig.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sPig.m_cLocation.Y) && (g_sChar.m_cLocation.X - 1 == g_sPig.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sPig.m_cLocation.Y) && (g_sChar.m_cLocation.X + 1 == g_sPig.m_cLocation.X))
    {
        g_sPig.fight = true;
        g_eGameState = S_BattleScreen;
        g_sChar.m_cLocation.X = 5;
        g_sChar.m_cLocation.Y = 12;

    }
    if ((g_sChar.m_cLocation.Y + 1 == g_sPig2.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sPig2.m_cLocation.X) || (g_sChar.m_cLocation.Y - 1 == g_sPig2.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sPig2.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sPig2.m_cLocation.Y) && (g_sChar.m_cLocation.X - 1 == g_sPig2.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sPig2.m_cLocation.Y) && (g_sChar.m_cLocation.X + 1 == g_sPig2.m_cLocation.X))
    {
        g_sPig2.fight = true;
        g_eGameState = S_BattleScreen;
        g_sChar.m_cLocation.X = 10;
        g_sChar.m_cLocation.Y = 12;

    }
    if ((g_sChar.m_cLocation.Y + 1 == g_sPig3.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sPig3.m_cLocation.X) || (g_sChar.m_cLocation.Y - 1 == g_sPig3.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sPig3.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sPig3.m_cLocation.Y) && (g_sChar.m_cLocation.X - 1 == g_sPig3.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sPig3.m_cLocation.Y) && (g_sChar.m_cLocation.X + 1 == g_sPig3.m_cLocation.X))
    {
        g_sPig3.fight = true;
        g_eGameState = S_BattleScreen;
        g_sChar.m_cLocation.X = 15;
        g_sChar.m_cLocation.Y = 12;

    }
    static bool showLoc = false;
    if (showLoc == false)
    {
        c.X = 25;
        c.Y = 0;
        g_Console.writeToBuffer(c, "Outside Abandoned Facility", 0x0F);
    }
}
void renderPig()
{
    g_sPig.m_cLocation.X = 15;
    g_sPig.m_cLocation.Y = 10;

    g_sPig2.m_cLocation.X = 18;
    g_sPig2.m_cLocation.Y = 7;

    g_sPig3.m_cLocation.X = 25;
    g_sPig3.m_cLocation.Y = 8;

    if (g_sPig.entityDie == true)
    {
        g_sPig.m_cLocation.X = -1;
        g_sPig.m_cLocation.Y = -1;
        g_sPig.startTimer = false;
    }
    if (g_sPig2.entityDie == true)
    {
        g_sPig2.m_cLocation.X = -1;
        g_sPig2.m_cLocation.Y = -1;
        g_sPig2.startTimer = false;

    }
    if (g_sPig3.entityDie == true)
    {
        g_sPig3.m_cLocation.X = -1;
        g_sPig3.m_cLocation.Y = -1;
        g_sPig3.startTimer = false;

    }

    g_Console.writeToBuffer(g_sPig.m_cLocation, 'P' , 0x0D);
    g_Console.writeToBuffer(g_sPig2.m_cLocation, 'P', 0x0D);
    g_Console.writeToBuffer(g_sPig3.m_cLocation, 'P', 0x0D);

}
void renderMap_IAF1()
{
    COORD c, d;
    srand((unsigned)time(0));
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.insideAbandonedFacility1(g_Console);
    renderCharacter();  // renders the character into the buffer

    static bool showObj = false;
    if (showObj == false)
    {
        c.X = 5;
        c.Y = 26;
        g_Console.writeToBuffer(c, "Objective: Fix the wires by stepping on |!|. ", 0x0B, 100);
        d.X = 5;
        d.Y = 27;
        g_Console.writeToBuffer(d, "           Go right to room 2, go left to room 4, go down to the outside.", 0x0B, 100);
    }

    //IAF2
    if (g_sBox1.startTimer == true && g_sBox2.startTimer == true && g_sBox3.startTimer == true && g_sBox4.startTimer == true && g_sBox5.startTimer == true && g_sBox6.startTimer == true)
    {
        for (int j = 17; j < 23; j++)
        {
            c.X = 2;
            c.Y = j;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '@', 0x0A);
        }
    }

    if (g_sChar.enterArea == true)
    {
        for (int j = 17; j < 23; j++)
        {
            c.X = 77;
            c.Y = j;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '@', 0x0A);
        }
    }

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

    //wire game
    if (g_sChar.m_cLocation.X == 56 && g_sChar.m_cLocation.Y == 4)
    {
        g_dPathTime = 0.0;
        g_eGameState = S_wireGame;
        g_sChar.m_cLocation.X = 7;
        g_sChar.m_cLocation.Y = 12;
    }

    if (g_sChar.m_cLocation.Y == 2 && g_sChar.m_cLocation.X == 3)
    {
        showCollect = 0.0;
        static int ItemChance = 0;
        static bool temp = false;
        if (temp == false)
        {
            ItemChance = rand() % 2 + 1;
            temp = true;
        }
        if (ItemChance == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }
        }
        else if (ItemChance == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }

    if (g_sChar.m_cLocation.Y == 3 && g_sChar.m_cLocation.X == 9)
    {
        showCollect = 0.0;
        static int ItemChance2 = 0;
        static bool temp2 = false;
        if (temp2 == false)
        {
            ItemChance2 = rand() % 2 + 1;
            temp2 = true;
        }
        if (ItemChance2 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }
        }
        else if (ItemChance2 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }

    if (g_sChar.m_cLocation.Y == 2 && g_sChar.m_cLocation.X == 18)
    {
        showCollect = 0.0;
        static int ItemChance3 = 0;
        static bool temp3 = false;
        if (temp3 == false)
        {
            ItemChance3 = rand() % 2 + 1;
            temp3 = true;
        }
        if (ItemChance3 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }
        }
        else if (ItemChance3 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }


    if (g_sChar.m_cLocation.Y == 6 && g_sChar.m_cLocation.X == 4)
    {
        showCollect = 0.0;
        static int ItemChance4 = 0;
        static bool temp4 = false;
        if (temp4 == false)
        {
            ItemChance4 = rand() % 2 + 1;
            temp4 = true;
        }
        if (ItemChance4 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }
        }
        else if (ItemChance4 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }

    if (g_sChar.m_cLocation.Y == 7 && g_sChar.m_cLocation.X == 18)
    {
        showCollect = 0.0;
        static int ItemChance5 = 0;
        static bool temp5 = false;
        if (temp5 == false)
        {
            ItemChance5 = rand() % 2 + 1;
            temp5 = true;
        }
        if (ItemChance5 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }
        }
        else if (ItemChance5 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }

    if (g_sChar.m_cLocation.Y == 2 && g_sChar.m_cLocation.X == 76)
    {
        showCollect = 0.0;
        static int ItemChance6 = 0;
        static bool temp6 = false;
        if (temp6 == false)
        {
            ItemChance6 = rand() % 2 + 1;
            temp6 = true;
        }
        if (ItemChance6 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }
        }
        else if (ItemChance6 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }

    if (g_sChar.m_cLocation.Y == 3 && g_sChar.m_cLocation.X == 62)
    {
        showCollect = 0.0;
        static int ItemChance7 = 0;
        static bool temp7 = false;
        if (temp7 == false)
        {
            ItemChance7= rand() % 2 + 1;
            temp7 = true;
        }
        if (ItemChance7 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }
        }
        else if (ItemChance7 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }

    if (g_sChar.m_cLocation.Y == 5 && g_sChar.m_cLocation.X == 67)
    {
        showCollect = 0.0;
        static int ItemChance8 = 0;
        static bool temp8 = false;
        if (temp8 == false)
        {
            ItemChance8 = rand() % 2 + 1;
            temp8 = true;
        }
        if (ItemChance8 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }
        }
        else if (ItemChance8 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }

    if (g_sChar.m_cLocation.Y == 6 && g_sChar.m_cLocation.X == 63)
    {
        showCollect = 0.0;
        static int ItemChance9 = 0;
        static bool temp9 = false;
        if (temp9 == false)
        {
            ItemChance9 = rand() % 2 + 1;
            temp9 = true;
        }
        if (ItemChance9 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }
        }
        else if (ItemChance9 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }

    if (g_sChar.m_cLocation.Y == 9 && g_sChar.m_cLocation.X == 76)
    {
        showCollect = 0.0;
        static int ItemChance10 = 0;
        static bool temp10 = false;
        if (temp10 == false)
        {
            ItemChance10 = rand() % 2 + 1;
            temp10 = true;
        }
        if (ItemChance10 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }
        }
        else if (ItemChance10 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }

    if (g_sChar.m_cLocation.Y == 13 && g_sChar.m_cLocation.X == 67)
    {
        showCollect = 0.0;
        static int ItemChance11 = 0;
        static bool temp11 = false;
        if (temp11 == false)
        {
            ItemChance11= rand() % 2 + 1;
            temp11 = true;
        }
        if (ItemChance11 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }
        }
        else if (ItemChance11 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }
    static bool showLoc = false;
    if (showLoc == false)
    {
        c.X = 26;
        c.Y = 0;
        g_Console.writeToBuffer(c, "Inside Abandoned Facility 1", 0x0F);
    }
}
void renderMap_IAF4()
{
    COORD c, d, e;
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.insideAbandonedFacility4(g_Console);
    renderCharacter();  // renders the character into the buffer

    static bool showObj = false;
    if (showObj == false)
    {
        c.X = 5;
        c.Y = 24;
        g_Console.writeToBuffer(c, "Objective: Talk to the wise old man for his advice! ", 0x0B, 100);
    }

    if (rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == '@')
    {
        g_eGameState = S_IAF1;
        g_sChar.m_cLocation.X = 76;
        g_sChar.m_cLocation.Y = 19;
    }
    if (g_sChar.m_cLocation.Y == 9 && g_sChar.m_cLocation.X == 40)
    {
        g_sChar.talkedOldMan = true;
    }
    if (((g_sChar.m_cLocation.Y == 11 || g_sChar.m_cLocation.Y == 13) && g_sChar.m_cLocation.X == 40) || ((g_sChar.m_cLocation.X == 39 || g_sChar.m_cLocation.X == 41) && g_sChar.m_cLocation.Y == 12))
    {
        if (g_sChar.talkedOldMan == false)
        {
            c.X = 2;
            c.Y = 25;
            g_Console.writeToBuffer(c, "Strange Old Man: Young man, are you going to fight Raymond? How Courageous!", 0x0F, 100);
            c.Y = 26;
            g_Console.writeToBuffer(c, "                 I have lived for thousands of years and have", 0x0F, 100);
            c.Y = 27;
            g_Console.writeToBuffer(c, "                 never seen anyone as tyrannical as him.", 0x0F, 100);
            c.Y = 28;
            g_Console.writeToBuffer(c, "                 Here, lemme boost you to aid you on your journey.", 0x0F, 100);
            g_sChar.SetH(500);
            g_sChar.SetD(g_sChar.GetD() + 10);
        }
    }

    if (((g_sChar.m_cLocation.Y == 11 || g_sChar.m_cLocation.Y == 13) && g_sChar.m_cLocation.X == 40) || ((g_sChar.m_cLocation.X == 39 || g_sChar.m_cLocation.X == 41) && g_sChar.m_cLocation.Y == 12))
    {
        if ((g_sChar.talkedOldMan == true))
        {
            c.X = 2;
            c.Y = 26;
            g_Console.writeToBuffer(c, "Strange Old Man: Get going now! You have to continue your journey!", 0x0F, 100);
            c.Y = 27;
            g_Console.writeToBuffer(c, "                 Go and fulfill your destiny!", 0x0F, 100);
        }
    }
    static bool showLoc = false;
    if (showLoc == false)
    {
        c.X = 26;
        c.Y = 0;
        g_Console.writeToBuffer(c, "Inside Abandoned Facility 4", 0x0F);
    }
}

void renderMap_IAF2()
{
    COORD c;
    srand((unsigned)time(0));
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.insideAbandonedFacility2(g_Console);
    renderCharacter();  // renders the character into the buffer

    static bool showObj = false;
    if (showObj == false)
    {
        c.X = 5;
        c.Y = 26;
        g_Console.writeToBuffer(c, "Objective: Go right back to room 1, go up to room 3.", 0x0B, 100);
    }

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
        g_sChar.m_cLocation.Y = 7;
    }

    if (g_sChar.IAF3Convo == true)
    {
        for (int i = 32; i <= 44; i++)
        {
            c.X = i;
            c.Y = 2;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '&', 0x0A);
        }
    }

    if (g_sChar.m_cLocation.Y == 3 && g_sChar.m_cLocation.X == 4)
    {
        showCollect = 0.0;
        static int ItemChance = 0;
        static bool temp = false;
        if (temp == false)
        {
            ItemChance = rand() % 2 + 1;
            temp = true;
        }
        if (ItemChance == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }

        }
        else if (ItemChance == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }

    if (g_sChar.m_cLocation.Y == 3 && g_sChar.m_cLocation.X == 7)
    {
        showCollect = 0.0;
        static int ItemChance2 = 0;
        static bool temp2 = false;
        if (temp2 == false)
        {
            ItemChance2 = rand() % 2 + 1;
            temp2 = true;
        }
        if (ItemChance2 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }

        }
        else if (ItemChance2 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }

    if (g_sChar.m_cLocation.Y == 4 && g_sChar.m_cLocation.X == 6)
    {
        showCollect = 0.0;
        static int ItemChance3 = 0;
        static bool temp3 = false;
        if (temp3 == false)
        {
            ItemChance3 = rand() % 2 + 1;
            temp3 = true;
        }
        if (ItemChance3 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }
        }
        else if (ItemChance3 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }

    if (g_sChar.m_cLocation.Y == 20 && g_sChar.m_cLocation.X == 6)
    {
        showCollect = 0.0;
        static int ItemChance4 = 0;
        static bool temp4 = false;
        if (temp4 == false)
        {
            ItemChance4 = rand() % 2 + 1;
            temp4 = true;
        }
        if (ItemChance4 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }

        }
        else if (ItemChance4 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }

    if (g_sChar.m_cLocation.Y == 21 && g_sChar.m_cLocation.X == 4)
    {
        showCollect = 0.0;
        static int ItemChance5 = 0;
        static bool temp5 = false;
        if (temp5 == false)
        {
            ItemChance5 = rand() % 2 + 1;
            temp5 = true;
        }
        if (ItemChance5 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }
        }
        else if (ItemChance5 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }

    if (g_sChar.m_cLocation.Y == 21 && g_sChar.m_cLocation.X == 7)
    {
        showCollect = 0.0;
        static int ItemChance6 = 0;
        static bool temp6 = false;
        if (temp6 == false)
        {
            ItemChance6 = rand() % 2 + 1;
            temp6 = true;
        }
        if (ItemChance6 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }

        }
        else if (ItemChance6 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }
    static bool showLoc = false;
    if (showLoc == false)
    {
        c.X = 26;
        c.Y = 0;
        g_Console.writeToBuffer(c, "Inside Abandoned Facility 2", 0x0F);
    }
}

void renderMap_IAF3()
{
    COORD c;
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.insideAbandonedFacility3(g_Console);
    renderCharacter();  // renders the character into the buffer
    g_sChar.IAF3Convo = true;
    //Back to IAF 2
    if ((g_sChar.m_cLocation.Y == 22) && (g_sChar.m_cLocation.X == 39 || g_sChar.m_cLocation.X == 40 || g_sChar.m_cLocation.X == 41))
    {
        g_dPathTime = 0.0;
        g_eGameState = S_IAF2;
        g_sChar.m_cLocation.X = 38;
        g_sChar.m_cLocation.Y = 3;
    }
    static bool showLoc = false;
    if (showLoc == false)
    {
        c.X = 26;
        c.Y = 0;
        g_Console.writeToBuffer(c, "Inside Abandoned Facility 3", 0x0F);
    }
}

void renderMap_Inside_Medical_Facility()
{
    PlaySound(NULL, NULL, NULL);
    game_music = false;
    COORD c;
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.insideMedicalFacility(g_Console);
    renderCharacter();  // renders the character into the buffer

    static bool showObj = false;
    if (showObj == false)
    {
        c.X = 5;
        c.Y = 25;
        g_Console.writeToBuffer(c, "Objective: Talk to the patient nearest to the counter.", 0x0B, 100);
    }

    if ((g_sChar.m_cLocation.Y == 10 || g_sChar.m_cLocation.Y == 11 || g_sChar.m_cLocation.Y == 12 || g_sChar.m_cLocation.Y == 13 || g_sChar.m_cLocation.Y == 14) && g_sChar.m_cLocation.X == 2)
    {
        g_dPathTime = 0.0;
        g_eGameState = S_Path_Area;
        g_sChar.m_cLocation.X = 76;
        g_sChar.m_cLocation.Y = 12;
    }
    if ((g_sChar.m_cLocation.X == 33 && (g_sChar.m_cLocation.Y == 21 || g_sChar.m_cLocation.Y == 19)) || ((g_sChar.m_cLocation.X == 32 || g_sChar.m_cLocation.X == 34) && g_sChar.m_cLocation.Y == 20))
    {
        g_dMedicalFightTime = 0.0;
        g_eGameState = S_Medical_Fight_Animation;
        g_sChar.m_cLocation.X = 34;
        g_sChar.m_cLocation.Y = 12;
    }
    if (g_sChar.m_cLocation.X == 19 && g_sChar.m_cLocation.Y == 12)
    {
        c.X = 5;
        c.Y = 26;
        g_Console.writeToBuffer(c, "Nurse: Sorry, we're busy dealing with the patients at the moment.", 0x0F, 100);
        c.Y = 27;
        g_Console.writeToBuffer(c, "       Please leave.", 0x0F, 100);
    }
    if ((g_sChar.m_cLocation.X == 22 && (g_sChar.m_cLocation.Y == 11 || g_sChar.m_cLocation.Y == 13)) || ((g_sChar.m_cLocation.X == 21 || g_sChar.m_cLocation.X == 23) && g_sChar.m_cLocation.Y == 12))
    {
        c.X = 5;
        c.Y = 26;
        g_Console.writeToBuffer(c, "Nurse: What are you doing behind the counter? This is for", 0x0F, 100);
        c.Y = 27;
        g_Console.writeToBuffer(c, "       staff only!!", 0x0F, 100);
    }
    static bool showLoc = false;
    if (showLoc == false)
    {
        c.X = 25;
        c.Y = 0;
        g_Console.writeToBuffer(c, "Inside Medical Facility", 0x0F);
    }

}
//change this gamestate
void renderMap_Dungeon_Cell()
{
    COORD c;

    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.dungeon_cell(g_Console);

    static bool showObj = false;
    if (showObj == false)
    {
        c.X = 5;
        c.Y = 25;
        g_Console.writeToBuffer(c, "Objective: Place the box '[' onto the correct skull!", 0x0B, 100);
    }

    if (g_sBox.startTimer == true)
    {
        for (int i = 32; i < 46; i++)
        {
            c.X = i;
            c.Y = 8;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = ' ', 0x0F);
        }
    }
    renderCharacter();  // renders the character into the buffer

    c.X = 13;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 6;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 4;
    c.Y = 15;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 6;
    c.Y = 18;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 13;
    c.Y = 20;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);


    c.X = 66;
    c.Y = 10;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 73;
    c.Y = 12;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 75;
    c.Y = 15;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    //skull correct
    c.X = 73;
    c.Y = 18;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 66;
    c.Y = 20;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);

    c.X = 23;
    c.Y = 21;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 56;
    c.Y = 21;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);
    c.X = 39;
    c.Y = 22;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = (char)12, 0x0F);

    c.X = 26;
    c.Y = 9;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'L', 0x0D);

    renderBox();

    if ((g_sChar.m_cLocation.X == g_sBox.m_cLocation.X) && (g_sChar.m_cLocation.Y == (g_sBox.m_cLocation.Y)))
    {
        if (g_skKeyEvent[K_UP].keyDown && g_sChar.m_cLocation.Y > 10)
        {
            g_sBox.m_cLocation.Y--;
            if (g_sBox.m_cLocation.X == 73 && g_sBox.m_cLocation.Y == 18)
            {
                g_sBox.startTimer = true;

            }
        }
        if (g_skKeyEvent[K_DOWN].keyDown && g_sChar.m_cLocation.Y < 21)
        {
            g_sBox.m_cLocation.Y++;
            if (g_sBox.m_cLocation.X == 73 && g_sBox.m_cLocation.Y == 18)
            {
                g_sBox.startTimer = true;

            }
        }
        if (g_skKeyEvent[K_LEFT].keyDown && g_sChar.m_cLocation.X > 3)
        {
            g_sBox.m_cLocation.X--;
            if (g_sBox.m_cLocation.X == 73 && g_sBox.m_cLocation.Y == 18)
            {
                g_sBox.startTimer = true;

            }
        }
        if (g_skKeyEvent[K_RIGHT].keyDown && g_sChar.m_cLocation.X < 76)
        {
            g_sBox.m_cLocation.X++;
            if (g_sBox.m_cLocation.X == 73 && g_sBox.m_cLocation.Y == 18)
            {
                g_sBox.startTimer = true;

            }
        }
    }

    //to DS1
    if (rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == '@')
    {
        g_sChar.CP2 = true;
        g_sChar.CP1 = false;
        g_dPathTime = 0.0;
        g_eGameState = S_Dungeon_Stealth_1;
        g_sChar.m_cLocation.X = 5;
        g_sChar.m_cLocation.Y = 21;
    }

    //fake skull drawings
    if ((g_sChar.m_cLocation.X == 13 && g_sChar.m_cLocation.Y == 20) || (g_sChar.m_cLocation.X == 13 && g_sChar.m_cLocation.Y == 10) || (g_sChar.m_cLocation.X == 6 && g_sChar.m_cLocation.Y == 12) || (g_sChar.m_cLocation.X == 4 && g_sChar.m_cLocation.Y == 15) || (g_sChar.m_cLocation.X == 6 && g_sChar.m_cLocation.Y == 18) || (g_sChar.m_cLocation.X == 23 && g_sChar.m_cLocation.Y == 21) || (g_sChar.m_cLocation.X == 39 && g_sChar.m_cLocation.Y == 22) || (g_sChar.m_cLocation.X == 56 && g_sChar.m_cLocation.Y == 21) || (g_sChar.m_cLocation.X == 66 && g_sChar.m_cLocation.Y == 20) || (g_sChar.m_cLocation.X == 75 && g_sChar.m_cLocation.Y == 15) || (g_sChar.m_cLocation.X == 73 && g_sChar.m_cLocation.Y == 12) || (g_sChar.m_cLocation.X == 66 && g_sChar.m_cLocation.Y == 10))
    {
        rMap.initialise(g_Console);
        rMap.Border(g_Console);
        mini.skull_game(g_Console);
    }
    //real skull drawings
    if (g_sChar.m_cLocation.X == 73 && g_sChar.m_cLocation.Y == 18)
    {
        rMap.initialise(g_Console);
        rMap.Border(g_Console);
        mini.trueSkull(g_Console);
    }

    if (g_sChar.m_cLocation.X == 26 && g_sChar.m_cLocation.Y == 9)
    {
        rMap.initialise(g_Console);
        rMap.Border(g_Console);
        mini.letter(g_Console);
    }
    static bool showLoc = false;
    if (showLoc == false)
    {
        c.X = 33;
        c.Y = 0;
        g_Console.writeToBuffer(c, "Dungeon Cell", 0x0F);
    }
}
void renderBox()
{
    g_Console.writeToBuffer(g_sBox.m_cLocation, '[', 0x0D);

}


void renderMap_DS1()
{
    COORD c;
    
    
    while (stealth_music == false)
    {
        PlaySound(TEXT("8 Bit Menu.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        stealth_music = true;
    }
    srand((unsigned)time(0));
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.dungeon_stealth1(g_Console);

    static bool showObj = false;
    if (showObj == false)
    {
        c.X = 5;
        c.Y = 25;
        g_Console.writeToBuffer(c, "Objective: Find Ell in the next room! ", 0x0B, 100);
    }

    if (g_sGuard.entityDie == true)
    {
        g_sGuard.m_cLocation.Y = -1;
        g_sGuard.m_cLocation.X = -1;
        g_sGuard.startTimer = false;
    }
    if (g_sGuard2.entityDie == true)
    {
        g_sGuard2.m_cLocation.Y = -1;
        g_sGuard2.m_cLocation.X = -1;
        g_sGuard2.startTimer = false;
    }
    if (g_sGuard3.entityDie == true)
    {
        g_sGuard3.m_cLocation.Y = -1;
        g_sGuard3.m_cLocation.X = -1;
        g_sGuard3.startTimer = false;
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
    //fight guard
    if ((g_sChar.m_cLocation.Y + 1 == g_sGuard.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sGuard.m_cLocation.X) || (g_sChar.m_cLocation.Y - 1 == g_sGuard2.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sGuard.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sGuard.m_cLocation.Y) && (g_sChar.m_cLocation.X + 1 == g_sGuard.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sGuard.m_cLocation.Y) && (g_sChar.m_cLocation.X - 1 == g_sGuard.m_cLocation.X))
    {
        g_sGuard.fight = true;
        g_eGameState = S_BattleScreen;
        g_sChar.m_cLocation.Y = 5;
        g_sChar.m_cLocation.X = 37;
    }
    if ((g_sChar.m_cLocation.Y + 1 == g_sGuard2.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sGuard2.m_cLocation.X) || (g_sChar.m_cLocation.Y - 1 == g_sGuard2.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sGuard2.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sGuard2.m_cLocation.Y) && (g_sChar.m_cLocation.X + 1 == g_sGuard2.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sGuard2.m_cLocation.Y) && (g_sChar.m_cLocation.X - 1 == g_sGuard2.m_cLocation.X))
    {
        g_sGuard2.fight = true;
        g_eGameState = S_BattleScreen;
        g_sChar.m_cLocation.Y = 16;
        g_sChar.m_cLocation.X = 28;
    }
    if ((g_sChar.m_cLocation.Y + 1 == g_sGuard3.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sGuard3.m_cLocation.X) || (g_sChar.m_cLocation.Y - 1 == g_sGuard3.m_cLocation.Y) && (g_sChar.m_cLocation.X == g_sGuard3.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sGuard3.m_cLocation.Y) && (g_sChar.m_cLocation.X + 1 == g_sGuard3.m_cLocation.X) || (g_sChar.m_cLocation.Y == g_sGuard3.m_cLocation.Y) && (g_sChar.m_cLocation.X - 1 == g_sGuard3.m_cLocation.X))
    {
        g_sGuard3.fight = true;
        g_eGameState = S_BattleScreen;
        g_sChar.m_cLocation.Y = 21;
        g_sChar.m_cLocation.X = 62;
    }
    if (g_sChar.m_cLocation.Y == 20 && g_sChar.m_cLocation.X == 8)
    {
        showCollect = 0.0;
        static int ItemChance = 0;
        static bool temp = false;
        if (temp == false)
        {
            ItemChance = rand() % 6 + 1;
            temp = true;
        }
        if (ItemChance == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(RawMeat.getQuantity());
            g_Console.writeToBuffer(c, "You received a Raw Meat. You now have " + Quantity + " Raw Meat.", 0x0F, 100);
            static bool item1 = false;
            if (item1 == false)
            {
                RawMeat.QuantityCheck("Raw Meat");
                item1 = true;
            }
        }
        else if (ItemChance == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Bread.getQuantity());
            g_Console.writeToBuffer(c, "You received a Bread. You now have " + Quantity + " Bread.", 0x0F, 100);
            static bool item2 = false;
            if (item2 == false)
            {
                Bread.QuantityCheck("Bread");
                item2 = true;
            }
        }
        else if (ItemChance == 3)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Burger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Burger. You now have " + Quantity + " Burger.", 0x0F, 100);
            static bool item3 = false;
            if (item3 == false)
            {
                Burger.QuantityCheck("Burger");
                item3 = true;
            }
        }
        else if (ItemChance == 4)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Taco.getQuantity());
            g_Console.writeToBuffer(c, "You received a Taco. You now have " + Quantity + " Taco.", 0x0F, 100);
            static bool item4 = false;
            if (item4 == false)
            {
                Taco.QuantityCheck("Taco");
                item4 = true;
            }
        }
        else if (ItemChance == 5)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Cake.getQuantity());
            g_Console.writeToBuffer(c, "You received a Cake. You now have " + Quantity + " Cake.", 0x0F, 100);
            static bool item5 = false;
            if (item5 == false)
            {
                Cake.QuantityCheck("Cake");
                item5 = true;
            }
        }
        else if (ItemChance == 6)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Medicine.getQuantity());
            g_Console.writeToBuffer(c, "You received a Medicine. You now have " + Quantity + " Medicine.", 0x0F, 100);
            static bool item6 = false;
            if (item6 == false)
            {
                Medicine.QuantityCheck("Medicine");
                item6 = true;
            }
        }
    }
    if (g_sChar.m_cLocation.Y == 18 && g_sChar.m_cLocation.X == 23)
    {
        showCollect = 0.0;
        static int ItemChance2 = 0;
        static bool temp2 = false;
        if (temp2 == false)
        {
            ItemChance2 = rand() % 6 + 1;
            temp2 = true;
        }
       
        if (ItemChance2 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(RawMeat.getQuantity());
            g_Console.writeToBuffer(c, "You received a Raw Meat. You now have " + Quantity + " Raw Meat.", 0x0F, 100);
            static bool item1 = false;
            if (item1 == false)
            {
                RawMeat.QuantityCheck("Raw Meat");
                item1 = true;
            }
        }
        else if (ItemChance2 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Bread.getQuantity());
            g_Console.writeToBuffer(c, "You received a Bread. You now have " + Quantity + " Bread.", 0x0F, 100);
            static bool item2 = false;
            if (item2 == false)
            {
                Bread.QuantityCheck("Bread");
                item2 = true;
            }
        }
        else if (ItemChance2 == 3)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Burger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Burger. You now have " + Quantity + " Burger.", 0x0F, 100);
            static bool item3 = false;
            if (item3 == false)
            {
                Burger.QuantityCheck("Burger");
                item3 = true;
            }
        }
        else if (ItemChance2 == 4)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Taco.getQuantity());
            g_Console.writeToBuffer(c, "You received a Taco. You now have " + Quantity + " Taco.", 0x0F, 100);
            static bool item4 = false;
            if (item4 == false)
            {
                Taco.QuantityCheck("Taco");
                item4 = true;
            }
        }
        else if (ItemChance2 == 5)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Cake.getQuantity());
            g_Console.writeToBuffer(c, "You received a Cake. You now have " + Quantity + " Cake.", 0x0F, 100);
            static bool item5 = false;
            if (item5 == false)
            {
                Cake.QuantityCheck("Cake");
                item5 = true;
            }
        }
        else if (ItemChance2 == 6)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Medicine.getQuantity());
            g_Console.writeToBuffer(c, "You received a Medicine. You now have " + Quantity + " Medicine.", 0x0F, 100);
            static bool item6 = false;
            if (item6 == false)
            {
                Medicine.QuantityCheck("Medicine");
                item6 = true;
            }
        }
    }
    if (g_sChar.m_cLocation.Y == 2 && g_sChar.m_cLocation.X == 76)
    {
        showCollect = 0.0;
        static int ItemChance3 = 0;
        static bool temp3 = false;
        if (temp3 == false)
        {
            ItemChance3 = rand() % 6 + 1;
            temp3 = true;
        }
        
        if (ItemChance3 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(RawMeat.getQuantity());
            g_Console.writeToBuffer(c, "You received a Raw Meat. You now have " + Quantity + " Raw Meat.", 0x0F, 100);
            static bool item1 = false;
            if (item1 == false)
            {
                RawMeat.QuantityCheck("Raw Meat");
                item1 = true;
            }
        }
        else if (ItemChance3 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Bread.getQuantity());
            g_Console.writeToBuffer(c, "You received a Bread. You now have " + Quantity + " Bread.", 0x0F, 100);
            static bool item2 = false;
            if (item2 == false)
            {
                Bread.QuantityCheck("Bread");
                item2 = true;
            }
        }
        else if (ItemChance3 == 3)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Burger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Burger. You now have " + Quantity + " Burger.", 0x0F, 100);
            static bool item3 = false;
            if (item3 == false)
            {
                Burger.QuantityCheck("Burger");
                item3 = true;
            }
        }
        else if (ItemChance3 == 4)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Taco.getQuantity());
            g_Console.writeToBuffer(c, "You received a Taco. You now have " + Quantity + " Taco.", 0x0F, 100);
            static bool item4 = false;
            if (item4 == false)
            {
                Taco.QuantityCheck("Taco");
                item4 = true;
            }
        }
        else if (ItemChance3 == 5)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Cake.getQuantity());
            g_Console.writeToBuffer(c, "You received a Cake. You now have " + Quantity + " Cake.", 0x0F, 100);
            static bool item5 = false;
            if (item5 == false)
            {
                Cake.QuantityCheck("Cake");
                item5 = true;
            }
        }
        else if (ItemChance3 == 6)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Medicine.getQuantity());
            g_Console.writeToBuffer(c, "You received a Medicine. You now have " + Quantity + " Medicine.", 0x0F, 100);
            static bool item6 = false;
            if (item6 == false)
            {
                Medicine.QuantityCheck("Medicine");
                item6 = true;
            }
        }
    }
    if (g_sChar.m_cLocation.Y == 19 && g_sChar.m_cLocation.X == 8)
    {
        static int ItemChance4 = 0;
        static bool temp4 = false;
        if (temp4 == false)
        {
            ItemChance4 = rand() % 2 + 1;
            temp4 = true;
        }
        if (ItemChance4 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }
        }
        else if (ItemChance4 == 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }
    /*if (g_sChar.m_cLocation.Y == 17 && g_sChar.m_cLocation.X == 41)
    {
        static int ItemChance5 = 0;
        static bool temp5 = false;
        if (temp5 == false)
        {
            ItemChance5 = rand() % 2 + 1;
            temp5 = true;
        }
        if (ItemChance5 == 1)
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "You received a Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }
        }
        else if (ItemChance5 == 2)
        {
            c.X = 5;
            c.Y = 26;
            g_Console.writeToBuffer(c, "You received a Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }*/
    if (g_sChar.m_cLocation.Y == 7 && g_sChar.m_cLocation.X == 50)
    {
        static int ItemChance6 = 0;
        static bool temp6 = false;
        if (temp6 == false)
        {
            ItemChance6 = rand() % 2 + 1;
            temp6 = true;
        }
        if (ItemChance6 == 1)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(Stinger.getQuantity());
            g_Console.writeToBuffer(c, "You received a Stinger. You now have " + Quantity + " Stinger.", 0x0F, 100);
            static bool item7 = false;
            if (item7 == false)
            {
                Stinger.QuantityCheck("Stinger");
                item7 = true;
            }
        }
        else if (ItemChance6== 2)
        {
            c.X = 5;
            c.Y = 26;
            string Quantity = to_string(GuardArmor.getQuantity());
            g_Console.writeToBuffer(c, "You received a Guard Armor. You now have " + Quantity + " Guard Armor.", 0x0F, 100);
            static bool item8 = false;
            if (item8 == false)
            {
                GuardArmor.QuantityCheck("Guard Armor");
                item8 = true;
            }
        }
    }
    static bool showLoc = false;
    if (showLoc == false)
    {
        c.X = 30;
        c.Y = 0;
        g_Console.writeToBuffer(c, "Dungeon Stealth 1", 0x0F);
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
    while (stealth_music == false)
    {
        PlaySound(TEXT("8 Bit Menu.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        stealth_music = true;
    }
    COORD c, d;
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.dungeon_stealth2(g_Console);
    renderCharacter();  // renders the character into the buffer

    static bool showObj = false;
    if (showObj == false)
    {
        c.X = 5;
        c.Y = 24;
        g_Console.writeToBuffer(c, "Objective: Sneak past the guards! ", 0x0B, 100);
        d.X = 5;
        d.Y = 25;
        g_Console.writeToBuffer(d, "Directions: Right: '<', Left: '<', Up: 'V', Down: '^'. ", 0x0B, 100);
    }

    c.X = 8;
    c.Y = 13;
    g_Console.writeToBuffer(c, (char)12, 0x0D);

    if ((g_sChar.m_cLocation.Y == 13) && (g_sChar.m_cLocation.X == 7) || (g_sChar.m_cLocation.Y == 12) && (g_sChar.m_cLocation.X == 8) || (g_sChar.m_cLocation.Y == 14) && (g_sChar.m_cLocation.X == 8))
    {
        c.X = 5;
        c.Y = 26;
        g_Console.writeToBuffer(c, "Ell: Avoid the guards and hide in the walls.");
        c.X = 5;
        c.Y = 27;
        g_Console.writeToBuffer(c, "     I'll get you out if you're in trouble, but don't count on me.");
    }
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
        g_sChar.CP2 = false;
        g_sChar.CP3 = true;
        g_eGameState = S_Dungeon_Stealth_3;
        g_sChar.m_cLocation.X = 5;
        g_sChar.m_cLocation.Y = 21;
    }
    static bool showLoc = false;
    if (showLoc == false)
    {
        c.X = 30;
        c.Y = 0;
        g_Console.writeToBuffer(c, "Dungeon Stealth 2", 0x0F);
    }
}

void renderMap_DS3()
{
    COORD c, d;
    PlaySound(NULL, NULL, NULL);
    stealth_music = false;
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.dungeon_stealth3(g_Console);
    renderCharacter();  // renders the character into the buffer

    static bool showObj = false;
    if (showObj == false)
    {
        c.X = 5;
        c.Y = 25;
        g_Console.writeToBuffer(c, "Objective: Go to the abandoned facility room 4.", 0x0B, 100);
    }
    //back to DS2
    g_sChar.enterArea = true;
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
        g_dDungeonStealth3Time = 0.0;
        //must do count here, must get character to move after animation
        g_eGameState = S_Dungeon_Stealth3_Animation;
        g_sChar.m_cLocation.X = 60;
        g_sChar.m_cLocation.Y = 22;
    }
    if (g_sChar.m_cLocation.Y == 3 && g_sChar.m_cLocation.X == 5)
    {
        if (enterOldman == true)
        {
            g_dBossTime = 0.0;
            g_eGameState = S_Boss_Room_Animation;
            g_sChar.m_cLocation.X = 40;
            g_sChar.m_cLocation.Y = 21;
        }

    }
    if (g_sChar.m_cLocation.Y == 2 && (g_sChar.m_cLocation.X == 60 || g_sChar.m_cLocation.X == 61 || g_sChar.m_cLocation.X == 62 || g_sChar.m_cLocation.X == 63 || g_sChar.m_cLocation.X == 64 || g_sChar.m_cLocation.X == 65 || g_sChar.m_cLocation.X == 66 || g_sChar.m_cLocation.X == 67 || g_sChar.m_cLocation.X == 68 || g_sChar.m_cLocation.X == 69 || g_sChar.m_cLocation.X == 70 || g_sChar.m_cLocation.X == 71 || g_sChar.m_cLocation.X == 72 || g_sChar.m_cLocation.X == 73 || g_sChar.m_cLocation.X == 74 || g_sChar.m_cLocation.X == 75 || g_sChar.m_cLocation.X == 76 || g_sChar.m_cLocation.X == 77))
    {
        enterOldman = true;
        g_dPathTime = 0.0;
        g_eGameState = S_Protest_Area;
        g_sChar.m_cLocation.X = 63;
        g_sChar.m_cLocation.Y = 4;
    }
    static bool showLoc = false;
    if (showLoc == false)
    {
        c.X = 30;
        c.Y = 0;
        g_Console.writeToBuffer(c, "Dungeon Stealth 3", 0x0F);
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
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    c.X = 11;
    c.Y = 0;
    string str_charhealth = to_string(g_sChar.GetH());
    g_Console.writeToBuffer(c, "Your Health: " + str_charhealth, 0x0A, 100);

    if (g_sRaymondBoss.counter == true)
    {
        Sprites.Battle_Raymond(g_Console, -19);

        g_sRaymondBoss.startTimer = true;
       
    }

    if (g_sPig.fight == true)
    {
        Sprites.pig(g_Console, 0);
        Sprites.drawRobert(g_Console, 0);
        c.X = 53;
        c.Y = 0;
        string str_pighealth = to_string(g_sPig.GetH());
        g_Console.writeToBuffer(c, "Enemy Health: " + str_pighealth, 0x0A, 100);
        if (g_sChar.startTimer == true)
        {
            if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 19)) && ((g_mouseEvent.mousePosition.X == 58) || (g_mouseEvent.mousePosition.X == 59) || (g_mouseEvent.mousePosition.X == 60) || (g_mouseEvent.mousePosition.X == 61) || (g_mouseEvent.mousePosition.X == 62) || (g_mouseEvent.mousePosition.X == 63) || (g_mouseEvent.mousePosition.X == 64))))
            {
                int randHit = rand() % 4 + 1;
                if (randHit == 1 || randHit == 2) // player gets hit
                {
                    int charhealth = g_sChar.GetH() - g_sPig.GetD(); // get player health
                    string str_charhealth = to_string(charhealth);

                    g_sChar.SetH(charhealth); // set player health to new health

                    g_sChar.showEnemyDMG = true;
                    enemyDMGTime = 0.0;
                    g_dslashRobert = 0.0;
                }
                if (randHit > 1) // guard gets hit
                {
                    int pighealth = g_sPig.GetH() - g_sChar.GetD(); // get enemy health
                    //string str_guardhealth = to_string(guardhealth);

                    g_sPig.SetH(pighealth); // set enemy health to new health
                    g_sChar.showPlayerDMG = true;
                    playerDMGTime = 0.0;
                    g_dslashPig = 0.0;
                }
                startTime = 0.0;
                g_sChar.resetTimer = true;
                g_sChar.startTimer = false;
                if (g_sPig.GetH() <= 0)
                {
                    g_dkillPig = 0.0;
                    g_sPig.startTimer = true;
                }
                if (g_sChar.GetH() <= 0)
                {
                    g_dkillRobert = 0.0;
                    g_sChar.entityDie = true;
                }
            }
        }
        if (g_sChar.showPlayerDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 25;
            string str_charDMG = to_string(g_sChar.GetD());

            g_Console.writeToBuffer(c, "You Dealt: " + str_charDMG, 0x0F, 100);
            slashPig();
        }
        if (g_sChar.showEnemyDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 26;
            string str_waspDMG = to_string(g_sPig.GetD());

            g_Console.writeToBuffer(c, "Enemy Dealt: " + str_waspDMG, 0x0F, 100);
            slashRobert();
        }
    }
    if (g_sPig2.fight == true)
    {
        Sprites.pig(g_Console, 0);
        Sprites.drawRobert(g_Console, 0);
        c.X = 53;
        c.Y = 0;
        string str_pig2health = to_string(g_sPig2.GetH());
        g_Console.writeToBuffer(c, "Enemy Health: " + str_pig2health, 0x0A, 100);
        if (g_sChar.startTimer == true)
        {
            if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 19)) && ((g_mouseEvent.mousePosition.X == 58) || (g_mouseEvent.mousePosition.X == 59) || (g_mouseEvent.mousePosition.X == 60) || (g_mouseEvent.mousePosition.X == 61) || (g_mouseEvent.mousePosition.X == 62) || (g_mouseEvent.mousePosition.X == 63) || (g_mouseEvent.mousePosition.X == 64))))
            {
                int randHit = rand() % 4 + 1;
                if (randHit == 1 || randHit == 2) // player gets hit
                {
                    int charhealth = g_sChar.GetH() - g_sPig2.GetD(); // get player health
                    string str_charhealth = to_string(charhealth);

                    g_sChar.SetH(charhealth); // set player health to new health

                    g_sChar.showEnemyDMG = true;
                    enemyDMGTime = 0.0;
                    g_dslashRobert = 0.0;
                }
                if (randHit > 1) // guard gets hit
                {
                    int pighealth = g_sPig2.GetH() - g_sChar.GetD(); // get enemy health
                    //string str_guardhealth = to_string(guardhealth);

                    g_sPig2.SetH(pighealth); // set enemy health to new health
                    g_sChar.showPlayerDMG = true;
                    playerDMGTime = 0.0;
                    g_dslashPig = 0.0;
                }
                startTime = 0.0;
                g_sChar.resetTimer = true;
                g_sChar.startTimer = false;
                if (g_sPig2.GetH() <= 0)
                {
                    g_dkillPig = 0.0;
                    g_sPig2.startTimer = true;
                }
                if (g_sChar.GetH() <= 0)
                {
                    g_dkillRobert = 0.0;
                    g_sChar.entityDie = true;
                }
            }
        }
        if (g_sChar.showPlayerDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 25;
            string str_charDMG = to_string(g_sChar.GetD());

            g_Console.writeToBuffer(c, "You Dealt: " + str_charDMG, 0x0F, 100);
            slashPig();
        }
        if (g_sChar.showEnemyDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 26;
            string str_waspDMG = to_string(g_sPig2.GetD());

            g_Console.writeToBuffer(c, "Enemy Dealt: " + str_waspDMG, 0x0F, 100);
            slashRobert();
        }
    }
    if (g_sPig3.fight == true)
    {
        Sprites.pig(g_Console, 0);
        Sprites.drawRobert(g_Console, 0);
        c.X = 53;
        c.Y = 0;
        string str_pig3health = to_string(g_sPig3.GetH());
        g_Console.writeToBuffer(c, "Enemy Health: " + str_pig3health, 0x0A, 100);
        if (g_sChar.startTimer == true)
        {
            if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 19)) && ((g_mouseEvent.mousePosition.X == 58) || (g_mouseEvent.mousePosition.X == 59) || (g_mouseEvent.mousePosition.X == 60) || (g_mouseEvent.mousePosition.X == 61) || (g_mouseEvent.mousePosition.X == 62) || (g_mouseEvent.mousePosition.X == 63) || (g_mouseEvent.mousePosition.X == 64))))
            {
                int randHit = rand() % 4 + 1;
                if (randHit == 1 || randHit == 2) // player gets hit
                {
                    int charhealth = g_sChar.GetH() - g_sPig3.GetD(); // get player health
                    string str_charhealth = to_string(charhealth);

                    g_sChar.SetH(charhealth); // set player health to new health

                    g_sChar.showEnemyDMG = true;
                    enemyDMGTime = 0.0;
                    g_dslashRobert = 0.0;
                }
                if (randHit > 1) // guard gets hit
                {
                    int pighealth = g_sPig3.GetH() - g_sChar.GetD(); // get enemy health
                    //string str_guardhealth = to_string(guardhealth);

                    g_sPig3.SetH(pighealth); // set enemy health to new health
                    g_sChar.showPlayerDMG = true;
                    playerDMGTime = 0.0;
                    g_dslashPig = 0.0;
                }
                startTime = 0.0;
                g_sChar.resetTimer = true;
                g_sChar.startTimer = false;
                if (g_sPig3.GetH() <= 0)
                {
                    g_dkillPig = 0.0;
                    g_sPig3.startTimer = true;
                }
                if (g_sChar.GetH() <= 0)
                {
                    g_dkillRobert = 0.0;
                    g_sChar.entityDie = true;
                }
            }
        }
        if (g_sChar.showPlayerDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 25;
            string str_charDMG = to_string(g_sChar.GetD());

            g_Console.writeToBuffer(c, "You Dealt: " + str_charDMG, 0x0F, 100);
            slashPig();
        }
        if (g_sChar.showEnemyDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 26;
            string str_waspDMG = to_string(g_sPig3.GetD());

            g_Console.writeToBuffer(c, "Enemy Dealt: " + str_waspDMG, 0x0F, 100);
            slashRobert();
        }
    }
    if (g_sRaymondBoss.fight == true)
    {
        Sprites.Battle_Raymond(g_Console, 0);
        Sprites.drawRobert(g_Console, 0);
        c.X = 53;
        c.Y = 0;
        string str_raymondhealth = to_string(g_sRaymondBoss.GetH());
        g_Console.writeToBuffer(c, "Enemy Health: " + str_raymondhealth, 0x0A, 100);
        if (g_sChar.startTimer == true)
        {
            if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 19)) && ((g_mouseEvent.mousePosition.X == 58) || (g_mouseEvent.mousePosition.X == 59) || (g_mouseEvent.mousePosition.X == 60) || (g_mouseEvent.mousePosition.X == 61) || (g_mouseEvent.mousePosition.X == 62) || (g_mouseEvent.mousePosition.X == 63) || (g_mouseEvent.mousePosition.X == 64))))
            {
                int randHit = rand() % 4 + 1;
                if (randHit == 1 || randHit == 2) // player gets hit
                {
                    int charhealth = g_sChar.GetH() - g_sRaymondBoss.GetD(); // get player health
                    string str_charhealth = to_string(charhealth);

                    g_sChar.SetH(charhealth); // set player health to new health

                    g_sChar.showEnemyDMG = true;
                    enemyDMGTime = 0.0;
                    g_dslashRobert = 0.0;
                }
                if (randHit > 1) // guard gets hit
                {
                    int raymondhealth = g_sRaymondBoss.GetH() - g_sChar.GetD(); // get enemy health
                    //string str_guardhealth = to_string(guardhealth);

                    g_sRaymondBoss.SetH(raymondhealth); // set enemy health to new health
                    g_sChar.showPlayerDMG = true;
                    playerDMGTime = 0.0;
                    g_dslashRaymond = 0.0;
                }
                startTime = 0.0;
                g_sChar.resetTimer = true;
                g_sChar.startTimer = false;
                if (g_sRaymondBoss.GetH() <= 0)
                {
                    g_dkillRaymond = 0.0;
                    g_sRaymondBoss.startTimer = true;
                }
                if (g_sChar.GetH() <= 0)
                {
                    g_dkillRobert = 0.0;
                    g_sChar.entityDie = true;
                }
            }
            
            if (g_sRaymondBoss.GetH() < 61)
            {
                g_sRaymondBoss.fight = false;
                g_sRaymondBoss.startTimer = false;
                g_dBossMiddleTime = 0.0; // set boss animation time to 0
                g_eGameState = S_Boss_Room_Mid_Animation; //link to boss animation before phase 2
            }
        }
        if (g_sChar.showPlayerDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 25;
            string str_charDMG = to_string(g_sChar.GetD());

            g_Console.writeToBuffer(c, "You Dealt: " + str_charDMG, 0x0F, 100);
            slashRaymond();
        }
        if (g_sChar.showEnemyDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 26;
            string str_waspDMG = to_string(g_sRaymondBoss.GetD());

            g_Console.writeToBuffer(c, "Enemy Dealt: " + str_waspDMG, 0x0F, 100);
            slashRobert();
        }
        
    }
    if (g_sTutEnemy.fight == true)
    {
        Sprites.Tutorial_Wasp(g_Console, 0);
        c.X = 53;
        c.Y = 0;
        string str_wasphealth = to_string(g_sTutEnemy.GetH());
        g_Console.writeToBuffer(c, "Enemy Health: " + str_wasphealth, 0x0A, 100);
        if (g_sChar.startTimer == true)
        {
            if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 19)) && ((g_mouseEvent.mousePosition.X == 58) || (g_mouseEvent.mousePosition.X == 59) || (g_mouseEvent.mousePosition.X == 60) || (g_mouseEvent.mousePosition.X == 61) || (g_mouseEvent.mousePosition.X == 62) || (g_mouseEvent.mousePosition.X == 63) || (g_mouseEvent.mousePosition.X == 64))))
            {
                int randHit = rand() % 4 + 1;
                if (randHit == 1 || randHit == 2) // player gets hit
                {
                    int charhealth = g_sChar.GetH() - g_sTutEnemy.GetD(); // get player health
                    string str_charhealth = to_string(charhealth);
                    g_sChar.SetH(charhealth); // set player health to new health
                    g_sChar.showEnemyDMG = true;
                    enemyDMGTime = 0.0;
                    g_dslashRobert = 0.0;
                }
                if (randHit > 1) // guard gets hit
                {
                    int tutWasphealth = g_sTutEnemy.GetH() - g_sChar.GetD(); // get enemy health
                    //string str_guardhealth = to_string(guardhealth);

                    g_sTutEnemy.SetH(tutWasphealth); // set enemy health to new health
                    g_sChar.showPlayerDMG = true;
                    playerDMGTime = 0.0;
                    g_dslashTutWasp = 0.0;
                }
                startTime = 0.0;
                g_sChar.resetTimer = true;
                g_sChar.startTimer = false;
                if (g_sTutEnemy.GetH() <= 0)
                {
                    g_dkillTutWasp = 0.0;
                    g_sTutEnemy.startTimer = true;
                }
                if (g_sChar.GetH() <= 0)
                {
                    g_dkillRobert = 0.0;
                    g_sChar.entityDie = true;
                }
            }
        }
        if (g_sChar.showPlayerDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 25;
            string str_charDMG = to_string(g_sChar.GetD());

            g_Console.writeToBuffer(c, "You Dealt: " + str_charDMG, 0x0F, 100);
            slashTutWasp();
        }
        if (g_sChar.showEnemyDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 26;
            string str_waspDMG = to_string(g_sTutEnemy.GetD());

            g_Console.writeToBuffer(c, "Enemy Dealt: " + str_waspDMG, 0x0F, 100);
            slashRobert();
        }
    }

    if (g_sMutantWasp.fight == true)
    {
        Sprites.Battle_Wasp(g_Console, 0);
        c.X = 53;
        c.Y = 0;
        string str_wasphealth = to_string(g_sMutantWasp.GetH());
        g_Console.writeToBuffer(c, "Enemy Health: " + str_wasphealth, 0x0A, 100);
        if (g_sChar.startTimer == true)
        {
            if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 19)) && ((g_mouseEvent.mousePosition.X == 58) || (g_mouseEvent.mousePosition.X == 59) || (g_mouseEvent.mousePosition.X == 60) || (g_mouseEvent.mousePosition.X == 61) || (g_mouseEvent.mousePosition.X == 62) || (g_mouseEvent.mousePosition.X == 63) || (g_mouseEvent.mousePosition.X == 64))))
            {
                int randHit = rand() % 4 + 1;
                if (randHit == 1 || randHit == 2) // player gets hit
                {
                    int charhealth = g_sChar.GetH() - g_sMutantWasp.GetD(); // get player health
                    string str_charhealth = to_string(charhealth);
                    g_sChar.SetH(charhealth); // set player health to new health
                    g_sChar.showEnemyDMG = true;
                    enemyDMGTime = 0.0;
                    g_dslashRobert = 0.0;
                }
                if (randHit > 1) // guard gets hit
                {
                    int wasphealth = g_sMutantWasp.GetH() - g_sChar.GetD(); // get enemy health
                    //string str_guardhealth = to_string(guardhealth);

                    g_sMutantWasp.SetH(wasphealth); // set enemy health to new health
                    g_sChar.showPlayerDMG = true;
                    playerDMGTime = 0.0;
                    g_dslashWasp = 0.0;
                }
                startTime = 0.0;
                g_sChar.resetTimer = true;
                g_sChar.startTimer = false;
                if (g_sMutantWasp.GetH() <= 0)
                {
                    g_dkillWasp = 0.0;
                    g_sMutantWasp.startTimer = true;
                }
                if (g_sChar.GetH() <= 0)
                {
                    g_dkillRobert = 0.0;
                    g_sChar.entityDie = true;
                }

            }
        }
        if (g_sChar.showPlayerDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 25;
            string str_charDMG = to_string(g_sChar.GetD());

            g_Console.writeToBuffer(c, "You Dealt: " + str_charDMG, 0x0F, 100);
            slashWasp();
        }
        if (g_sChar.showEnemyDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 26;
            string str_waspDMG = to_string(g_sMutantWasp.GetD());

            g_Console.writeToBuffer(c, "Enemy Dealt: " + str_waspDMG, 0x0F, 100);
            slashRobert();
        }
    }
    if (g_sMutantWasp2.fight == true)
    {
        Sprites.Battle_Wasp(g_Console, 0);
        c.X = 53;
        c.Y = 0;
        string str_wasphealth = to_string(g_sMutantWasp2.GetH());
        g_Console.writeToBuffer(c, "Enemy Health: " + str_wasphealth, 0x0A, 100);
        if (g_sChar.startTimer == true)
        {

            if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 19)) && ((g_mouseEvent.mousePosition.X == 58) || (g_mouseEvent.mousePosition.X == 59) || (g_mouseEvent.mousePosition.X == 60) || (g_mouseEvent.mousePosition.X == 61) || (g_mouseEvent.mousePosition.X == 62) || (g_mouseEvent.mousePosition.X == 63) || (g_mouseEvent.mousePosition.X == 64))))
            {
                int randHit = rand() % 4 + 1;
                if (randHit == 1 || randHit == 2) // player gets hit
                {
                    int charhealth = g_sChar.GetH() - g_sMutantWasp.GetD(); // get player health
                    string str_charhealth = to_string(charhealth);
                    g_sChar.SetH(charhealth); // set player health to new health
                    g_sChar.showEnemyDMG = true;
                    enemyDMGTime = 0.0;
                    g_dslashRobert = 0.0;

                }
                if (randHit > 1) // guard gets hit
                {
                    int wasphealth = g_sMutantWasp2.GetH() - g_sChar.GetD(); // get enemy health
                    //string str_guardhealth = to_string(guardhealth);

                    g_sMutantWasp2.SetH(wasphealth); // set enemy health to new health
                    g_sChar.showPlayerDMG = true;
                    playerDMGTime = 0.0;
                    g_dslashWasp = 0.0;
                }
                startTime = 0.0;
                g_sChar.resetTimer = true;
                g_sChar.startTimer = false;
                if (g_sMutantWasp2.GetH() <= 0)
                {
                    g_dkillWasp = 0.0;
                    g_sMutantWasp2.startTimer = true;
                }
                if (g_sChar.GetH() <= 0)
                {
                    g_dkillRobert = 0.0;
                    g_sChar.entityDie = true;
                    g_sChar.entityDied = true;
                }

            }
        }
        if (g_sChar.showPlayerDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 25;
            string str_charDMG = to_string(g_sChar.GetD());

            g_Console.writeToBuffer(c, "You Dealt: " + str_charDMG, 0x0F, 100);
            slashWasp();
        }
        if (g_sChar.showEnemyDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 26;
            string str_waspDMG = to_string(g_sMutantWasp2.GetD());

            g_Console.writeToBuffer(c, "Enemy Dealt: " + str_waspDMG, 0x0F, 100);
            slashRobert();
        }

    }
    // fight guard 1
    if (g_sGuard.fight == true)
    {
        Sprites.drawGuard(g_Console, 0);

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
                    g_dslashRobert = 0.0;

                }
                if (randHit > 1) // guard gets hit
                {
                    int guardhealth = g_sGuard.GetH() - g_sChar.GetD(); // get enemy health
                    //string str_guardhealth = to_string(guardhealth);

                    g_sGuard.SetH(guardhealth); // set enemy health to new health
                    g_sChar.showPlayerDMG = true;
                    playerDMGTime = 0.0;
                    g_dslashGuard = 0.0;
                }
                startTime = 0.0;
                g_sChar.resetTimer = true;
                g_sChar.startTimer = false;
                if (g_sGuard.GetH() <= 0)
                {
                    g_dkillGuard = 0.0;
                    g_sGuard.startTimer = true;
                    //g_sChar.showPlayerDMG = true;
                }
                if (g_sChar.GetH() <= 0)
                {
                    g_dkillRobert = 0.0;
                    g_sChar.entityDie = true;
                }

            }
        }

        if (g_sChar.showPlayerDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 25;
            string str_charDMG = to_string(g_sChar.GetD());

            g_Console.writeToBuffer(c, "You Dealt: " + str_charDMG, 0x0F, 100);
            slashGuard();
        }
        if (g_sChar.showEnemyDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 26;
            string str_guardDMG = to_string(g_sGuard.GetD());

            g_Console.writeToBuffer(c, "Enemy Dealt: " + str_guardDMG, 0x0F, 100);
            slashRobert();
        }
    }
    if (g_sGuard2.fight == true)
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
                int randHit = rand() % 4 + 1;
                if (randHit == 1 || randHit == 2) // player gets hit
                {
                    int charhealth = g_sChar.GetH() - g_sGuard2.GetD(); // get player health
                    string str_charhealth = to_string(charhealth);

                    g_sChar.SetH(charhealth); // set player health to new health

                    g_sChar.showEnemyDMG = true;
                    enemyDMGTime = 0.0;
                    g_dslashRobert = 0.0;

                }

                if (randHit > 1) // player gets hit
                {
                    int guardhealth = g_sGuard2.GetH() - g_sChar.GetD(); // get enemy health
                   //string str_guardhealth = to_string(guardhealth);

                    g_sGuard2.SetH(guardhealth);
                    g_sChar.showPlayerDMG = true;
                    g_dslashGuard = 0.0;
                    playerDMGTime = 0.0;
                }
                startTime = 0.0;
                g_sChar.resetTimer = true;
                g_sChar.startTimer = false;
                g_sChar.count = 1;
                if (g_sGuard2.GetH() <= 0)
                {
                    g_dkillGuard = 0.0;
                    //deathAnimation = 0.0;
                    g_sGuard2.startTimer = true;
                    //g_sChar.showPlayerDMG = true;

                }
                if (g_sChar.GetH() <= 0)
                {
                    g_dkillRobert = 0.0;
                    g_sChar.entityDie = true;
                }
            }
        }

        if (g_sChar.showPlayerDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 25;
            string str_charDMG = to_string(g_sChar.GetD());

            g_Console.writeToBuffer(c, "You Dealt: " + str_charDMG, 0x0F, 100);
            slashGuard();

        }
        if (g_sChar.showEnemyDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 26;
            string str_guardDMG = to_string(g_sGuard2.GetD());

            g_Console.writeToBuffer(c, "Enemy Dealt: " + str_guardDMG, 0x0F, 100);
            slashRobert();
        }
    }
    if (g_sGuard3.fight == true)
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
                int randHit = rand() % 4 + 1;
                if (randHit == 1 || randHit == 2) // player gets hit
                {
                    int charhealth = g_sChar.GetH() - g_sGuard3.GetD(); // get player health
                    string str_charhealth = to_string(charhealth);

                    g_sChar.SetH(charhealth); // set player health to new health

                    g_sChar.showEnemyDMG = true;
                    enemyDMGTime = 0.0;
                    g_dslashRobert = 0.0;

                }
                if (randHit > 1) // player gets hit
                {
                    int guardhealth = g_sGuard3.GetH() - g_sChar.GetD(); // get enemy health
                    //string str_guardhealth = to_string(guardhealth);

                    g_sGuard3.SetH(guardhealth); // set enemy health to new health
                    g_sChar.showPlayerDMG = true;
                    playerDMGTime = 0.0;
                    g_dslashGuard = 0.0;
                }
                startTime = 0.0;
                g_sChar.resetTimer = true;
                g_sChar.startTimer = false;
                g_sChar.count = 1;
                if (g_sGuard3.GetH() <= 0)
                {
                    g_dkillGuard = 0.0;
                    g_sGuard3.startTimer = true;
                }
                if (g_sChar.GetH() <= 0)
                {
                    g_dkillRobert = 0.0;
                    g_sChar.entityDie = true;
                }
            }
        }

        if (g_sChar.showPlayerDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 25;
            string str_charDMG = to_string(g_sChar.GetD());

            g_Console.writeToBuffer(c, "You Dealt: " + str_charDMG, 0x0F, 100);
            slashGuard();
        }
        if (g_sChar.showEnemyDMG == true)
        {
            COORD c;
            c.X = 3;
            c.Y = 26;
            string str_guardDMG = to_string(g_sGuard.GetD());

            g_Console.writeToBuffer(c, "Enemy Dealt: " + str_guardDMG, 0x0F, 100);
            slashRobert();
        }

    }


    if (g_sChar.InvenActive == true)
    {
        string str_Quantity1 = to_string(RawMeat.getQuantity());
        string str_Quantity2 = to_string(Stinger.getQuantity());
        string str_Quantity3 = to_string(GuardArmor.getQuantity());
        string str_Quantity4 = to_string(Bread.getQuantity());
        string str_Quantity5 = to_string(Burger.getQuantity());
        string str_Quantity6 = to_string(Taco.getQuantity());
        string str_Quantity7 = to_string(Cake.getQuantity());
        string str_Quantity8 = to_string(Medicine.getQuantity());
        rMap.Road2(g_Console, 3, 24, 74);
        rMap.Road(g_Console, 2, 25, 5);
        rMap.Road2(g_Console, 3, 29, 75);
        rMap.Road(g_Console, 77, 25, 5);
        c.X = 13;
        c.Y = 26;
        g_Console.writeToBuffer(c, "o Raw Meat " + str_Quantity1, 0x0F, 100);
        c.X = 13;
        c.Y = 28;
        g_Console.writeToBuffer(c, "o Stinger " + str_Quantity2, 0x0F, 100);
        c.X = 28;
        c.Y = 26;
        g_Console.writeToBuffer(c, "o Guard Armor " + str_Quantity3, 0x0F, 100);
        c.X = 28;
        c.Y = 28;
        g_Console.writeToBuffer(c, "o Bread " + str_Quantity4, 0x0F, 100);
        c.X = 46;
        c.Y = 26;
        g_Console.writeToBuffer(c, "o Burger " + str_Quantity5, 0x0F, 100);
        c.X = 46;
        c.Y = 28;
        g_Console.writeToBuffer(c, "o Taco " + str_Quantity6, 0x0F, 100);
        c.X = 61;
        c.Y = 26;
        g_Console.writeToBuffer(c, "o Cake " + str_Quantity7, 0x0F, 100);
        c.X = 61;
        c.Y = 28;
        g_Console.writeToBuffer(c, "o Medicine " + str_Quantity8, 0x0F, 100);
    }
    //change g_eGameState to inventory
    if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 19)) && ((g_mouseEvent.mousePosition.X == 15) || (g_mouseEvent.mousePosition.X == 16) || (g_mouseEvent.mousePosition.X == 17) || (g_mouseEvent.mousePosition.X == 18) || (g_mouseEvent.mousePosition.X == 19) || (g_mouseEvent.mousePosition.X == 20) || (g_mouseEvent.mousePosition.X == 21) || (g_mouseEvent.mousePosition.X == 22) || (g_mouseEvent.mousePosition.X == 23) || (g_mouseEvent.mousePosition.X == 24) || (g_mouseEvent.mousePosition.X == 25))))
    {
        g_sChar.InvenActive = true;
        g_sChar.itemActive = true;
        g_sInven.startTimer = true;
    }
    
    if ((g_sInven.startTimer == true) && (g_sChar.InvenActive == true) && (g_sChar.itemActive == true))
    {
        if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && ((g_mouseEvent.mousePosition.Y == 26) && (g_mouseEvent.mousePosition.X == 13)))
        {
            g_sRawMeat.showItemUsed = false;
            g_sInven.showItemNotUsed = false;
            g_sInven.showNoQuantity = false;
            if ((g_sChar.GetH() < 50 || g_sChar.GetH() < 1000) && RawMeat.getQuantity() > 0)
            {
                UpdateHealth = g_sChar.GetH() + 5;
                g_sRawMeat.showItemUsed = true;
                g_sChar.SetH(UpdateHealth);
                RawMeat.setQuantity(RawMeat.getQuantity() - 1);
                if (UpdateHealth >= 50 && UpdateHealth < 1000)
                {
                    g_sRawMeat.showItemUsed = false;
                    g_sChar.SetH(50);
                }
                else if (UpdateHealth >= 1000)
                {
                    g_sRawMeat.showItemUsed = false;
                    g_sChar.SetH(10000);
                }
            }
            else if ((g_sChar.GetH() == 50 || g_sChar.GetH() == 1000) && RawMeat.getQuantity() > 0)
            {
                g_sInven.showItemNotUsed = true;
            }
            else
            {
                g_sInven.showNoQuantity = true;
            }
            playerInvenTime = 0.0;
            g_sChar.InvenActive = false;
            g_sChar.itemActive = false;
            InvenTime = 0.0;
            g_sInven.startTimer = false;
            g_sInven.resetTimer = true;
        }
        else if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && ((g_mouseEvent.mousePosition.Y == 28) && (g_mouseEvent.mousePosition.X == 13)))
        {
            g_sStinger.showItemUsed = false;
            g_sInven.showNoQuantity = false;
            if (Stinger.getQuantity() > 0)
            {
                UpdateDmg = g_sChar.GetD() + 5;
                g_sStinger.showItemUsed = true;
                g_sChar.SetD(UpdateDmg);
                Stinger.setQuantity(Stinger.getQuantity() - 1);
            }
            else
            {
                g_sInven.showNoQuantity = true;
            }
            playerInvenTime = 0.0;
            g_sChar.InvenActive = false;
            g_sChar.itemActive = false;
            InvenTime = 0.0;
            g_sInven.startTimer = false;
            g_sInven.resetTimer = true;
        }
        else if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && ((g_mouseEvent.mousePosition.Y == 26) && (g_mouseEvent.mousePosition.X == 28)))
        {
            g_sGuardArmor.showItemUsed = false;
            g_sInven.showNoQuantity = false;
            if (GuardArmor.getQuantity() > 0)
            {
                UpdateDmg = g_sChar.GetD() + 10;
                g_sGuardArmor.showItemUsed = true;
                g_sChar.SetD(UpdateDmg);
                GuardArmor.setQuantity(GuardArmor.getQuantity() - 1);
            }
            else
            {
                g_sInven.showNoQuantity = true;
            }
            g_sChar.InvenActive = false;
            g_sChar.itemActive = false;
            InvenTime = 0.0;
            g_sInven.startTimer = false;
            g_sInven.resetTimer = true;
            playerInvenTime = 0.0;
        }
        else if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && ((g_mouseEvent.mousePosition.Y == 28) && (g_mouseEvent.mousePosition.X == 28)))
        {
            g_sBread.showItemUsed = false;
            g_sInven.showItemNotUsed = false;
            g_sInven.showNoQuantity = false;
            if ((g_sChar.GetH() < 50 || g_sChar.GetH() < 1000) && Bread.getQuantity() > 0)
            {
                UpdateHealth = g_sChar.GetH() + 10;
                g_sBread.showItemUsed = true;
                g_sChar.SetH(UpdateHealth);
                Bread.setQuantity(Bread.getQuantity() - 1);
                if (UpdateHealth >= 50 && UpdateHealth < 1000)
                {
                    g_sBread.showItemUsed = false;
                    g_sChar.SetH(50);
                }
                else if (UpdateHealth >= 1000)
                {
                    g_sBread.showItemUsed = false;
                    g_sChar.SetH(1000);
                }
            }
            else if ((g_sChar.GetH() == 50 || g_sChar.GetH() == 1000) && Bread.getQuantity() > 0)
            {
                g_sInven.showItemNotUsed = true;
            }
            else
            {
                g_sInven.showNoQuantity = true;
            }
            playerInvenTime = 0.0;
            g_sChar.InvenActive = false;
            g_sChar.itemActive = false;
            InvenTime = 0.0;
            g_sInven.startTimer = false;
            g_sInven.resetTimer = true;
        }
        else if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && ((g_mouseEvent.mousePosition.Y == 26) && (g_mouseEvent.mousePosition.X == 46)))
        {
            g_sBurger.showItemUsed = false;
            g_sInven.showItemNotUsed = false;
            g_sInven.showNoQuantity = false;
            if ((g_sChar.GetH() < 50 || g_sChar.GetH() < 1000) && Burger.getQuantity() > 0)
            {
                UpdateHealth = g_sChar.GetH() + 25;
                g_sInven.showItemUsed = true;
                g_sChar.SetH(UpdateHealth);
                Burger.setQuantity(Burger.getQuantity() - 1);
                if (UpdateHealth >= 50 && UpdateHealth < 1000)
                {
                    g_sBurger.showItemUsed = false;
                    g_sChar.SetH(50);
                }
                else if (UpdateHealth >= 1000)
                {
                    g_sBurger.showItemUsed = false;
                    g_sChar.SetH(1000);
                }
            }
            else if ((g_sChar.GetH() == 50 || g_sChar.GetH() == 1000) && Burger.getQuantity() > 0)
            {
                g_sInven.showItemNotUsed = true;
            }
            else
            {
                g_sInven.showNoQuantity = true;
            }
            playerInvenTime = 0.0;
            g_sChar.InvenActive = false;
            g_sChar.itemActive = false;
            InvenTime = 0.0;
            g_sInven.startTimer = false;
            g_sInven.resetTimer = true;
        }
        else if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && ((g_mouseEvent.mousePosition.Y == 28) && (g_mouseEvent.mousePosition.X == 46)))
        {
            g_sTaco.showItemUsed = false;
            g_sInven.showItemNotUsed = false;
            g_sInven.showNoQuantity = false;
            if ((g_sChar.GetH() < 50 || g_sChar.GetH() < 10000) && Taco.getQuantity() > 0)
            {
                UpdateHealth = g_sChar.GetH() + 25;
                g_sTaco.showItemUsed = true;
                g_sChar.SetH(UpdateHealth);
                Taco.setQuantity(Taco.getQuantity() - 1);
                if (UpdateHealth >= 50 && UpdateHealth < 10000)
                {
                    g_sTaco.showItemUsed = false;
                    g_sChar.SetH(50);
                }
                else if (UpdateHealth >= 1000)
                {
                    g_sTaco.showItemUsed = false;
                    g_sChar.SetH(1000);
                }
            }
            else if ((g_sChar.GetH() == 50 || g_sChar.GetH() == 1000) && Taco.getQuantity() > 0)
            {
                g_sInven.showItemNotUsed = true;
            }
            else
            {
                g_sInven.showNoQuantity = true;
            }
            playerInvenTime = 0.0;
            g_sChar.InvenActive = false;
            g_sChar.itemActive = false;
            InvenTime = 0.0;
            g_sInven.startTimer = false;
            g_sInven.resetTimer = true;
        }
        else if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && ((g_mouseEvent.mousePosition.Y == 26) && (g_mouseEvent.mousePosition.X == 61)))
        {
            g_sCake.showItemUsed = false;
            g_sInven.showItemNotUsed = false;
            g_sInven.showNoQuantity = false;
            if ((g_sChar.GetH() < 50 || g_sChar.GetH() < 1000) && Cake.getQuantity() > 0)
            {
                UpdateHealth = g_sChar.GetH() + 50;
                g_sCake.showItemUsed = true;
                g_sChar.SetH(UpdateHealth);
                Cake.setQuantity(Cake.getQuantity() - 1);
                if (UpdateHealth >= 50 && UpdateHealth < 1000)
                {
                    g_sCake.showItemUsed = false;
                    g_sChar.SetH(50);
                }
                else if (UpdateHealth >= 1000)
                {
                    g_sCake.showItemUsed = false;
                    g_sChar.SetH(1000);
                }
            }
            else if ((g_sChar.GetH() == 50 || g_sChar.GetH() == 1000) && Cake.getQuantity() > 0)
            {
                g_sInven.showItemNotUsed = true;
            }
            else
            {
                g_sInven.showNoQuantity = true;
            }
            playerInvenTime = 0.0;
            g_sChar.InvenActive = false;
            g_sChar.itemActive = false;
            InvenTime = 0.0;
            g_sInven.startTimer = false;
            g_sInven.resetTimer = true;
        }
        else if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && ((g_mouseEvent.mousePosition.Y == 28) && (g_mouseEvent.mousePosition.X == 61)))
        {
            g_sMedicine.showItemUsed = false;
            g_sInven.showItemNotUsed = false;
            g_sInven.showNoQuantity = false;
            if (g_sChar.GetH() < 50 && Medicine.getQuantity() > 0)
            {
                UpdateHealth = 50;
                g_sMedicine.showItemUsed = true;
                g_sChar.SetH(UpdateHealth);
                Medicine.setQuantity(Medicine.getQuantity() - 1);
            }
            else if (g_sChar.GetH() < 1000 && Medicine.getQuantity() > 0)
            {
                UpdateHealth = 1000;
                g_sMedicine.showItemUsed = true;
                g_sChar.SetH(UpdateHealth);
                Medicine.setQuantity(Medicine.getQuantity() - 1);
            }
            else if ((g_sChar.GetH() == 50 || g_sChar.GetH() == 1000) && Medicine.getQuantity() > 0)
            {
                g_sInven.showItemNotUsed = true;
            }
            else
            {
                g_sInven.showNoQuantity = true;
            }
            playerInvenTime = 0.0;
            g_sChar.InvenActive = false;
            g_sChar.itemActive = false;
            InvenTime = 0.0;
            g_sInven.startTimer = false;
            g_sInven.resetTimer = true;
        }
        else if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && ((g_mouseEvent.mousePosition.Y == 19) && (g_mouseEvent.mousePosition.X == 58) || (g_mouseEvent.mousePosition.X == 59) || (g_mouseEvent.mousePosition.X == 60) || (g_mouseEvent.mousePosition.X == 61) || (g_mouseEvent.mousePosition.X == 62) || (g_mouseEvent.mousePosition.X == 63) || (g_mouseEvent.mousePosition.X == 64)))
        {
            g_sChar.InvenActive = false;
            g_sChar.itemActive = false;
        }
    }
    
    // if click on fight
    /*
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
                /*
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
            //g_eGameState = S_Dungeon_Stealth_1; // if player kills guard
            //g_sChar.unlockDoorDS1 = true;
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
    {
        c.X = 40;
        c.Y = 25;
        g_Console.writeToBuffer(c, "Item used.", 100);
        InvenTime = 0.0;
    }
    */
    if (g_sGuard.startTimer == true)
    {
        killGuard();
    }
    if (g_sGuard2.startTimer == true)
    {
        killGuard();
    }
    if (g_sGuard3.startTimer == true)
    {
        killGuard();
    }
    if (g_sMutantWasp.startTimer == true)
    {
        killWasp();
    }
    if (g_sMutantWasp2.startTimer == true)
    {
        killWasp();
    }
    if (g_sTutEnemy.startTimer == true)
    {
        killTutWasp();
    }
    if (g_sRaymondBoss.startTimer == true)
    {
        killRaymond();
    }
    if (g_sPig.startTimer == true)
    {
        killPig();
    }
    if (g_sPig2.startTimer == true)
    {
        killPig();
    }
    if (g_sPig3.startTimer == true)
    {
        killPig();
    }
    if (g_sChar.entityDie == true)
    {
        killRobert();
    }
    if (g_sRawMeat.showItemUsed == true)
    {
        c.X = 3;
        c.Y = 26;
        string str_Healed = to_string(g_sChar.GetH());
        string str_Quantity1 = to_string(RawMeat.getQuantity());
        g_Console.writeToBuffer(c, "Item used. You have been healed to " + str_Healed + "HP. You have " + str_Quantity1 + " left.", 0x0F, 100);
    }
    if (g_sBread.showItemUsed == true)
    {
        c.X = 3;
        c.Y = 26;
        string str_Healed = to_string(g_sChar.GetH());
        string str_Quantity2 = to_string(Bread.getQuantity());
        g_Console.writeToBuffer(c, "Item used. You have been healed to " + str_Healed + "HP. You have " + str_Quantity2 + " left.", 0x0F, 100);
    }
    if (g_sBurger.showItemUsed == true)
    {
        c.X = 3;
        c.Y = 26;
        string str_Healed = to_string(g_sChar.GetH());
        string str_Quantity3 = to_string(Burger.getQuantity());
        g_Console.writeToBuffer(c, "Item used. You have been healed to " + str_Healed + "HP. You have " + str_Quantity3 + " left.", 0x0F, 100);
    }
    if (g_sTaco.showItemUsed == true)
    {
        c.X = 3;
        c.Y = 26;
        string str_Healed = to_string(g_sChar.GetH());
        string str_Quantity4 = to_string(Taco.getQuantity());
        g_Console.writeToBuffer(c, "Item used. You have been healed to " + str_Healed + "HP. You have " + str_Quantity4 + " left.", 0x0F, 100);
    }

    if (g_sCake.showItemUsed == true)
    {
        c.X = 3;
        c.Y = 26;
        string str_Healed = to_string(g_sChar.GetH());
        string str_Quantity5 = to_string(Cake.getQuantity());
        g_Console.writeToBuffer(c, "Item used. You have been healed to " + str_Healed + "HP. You have " + str_Quantity5 + " left.", 0x0F, 100);
    }

    if (g_sMedicine.showItemUsed == true)
    {
        c.X = 3;
        c.Y = 26;
        string str_Healed = to_string(g_sChar.GetH());
        string str_Quantity6 = to_string(Medicine.getQuantity());
        g_Console.writeToBuffer(c, "Item used. You have been healed to " + str_Healed + "HP. You have " + str_Quantity6 + " left.", 0x0F, 100);
    }

    if (g_sStinger.showItemUsed == true)
    {
        c.X = 3;
        c.Y = 26;
        string str_Dmg = to_string(g_sChar.GetD());
        string str_Quantity7 = to_string(Stinger.getQuantity());
        g_Console.writeToBuffer(c, "Item used. Your damage has been increased to " + str_Dmg + ". You have " + str_Quantity7 + " left.", 0x0F, 100);
    }

    if (g_sGuardArmor.showItemUsed == true)
    {
        c.X = 3;
        c.Y = 26;
        string str_Dmg = to_string(g_sChar.GetD());
        string str_Quantity8 = to_string(GuardArmor.getQuantity());
        g_Console.writeToBuffer(c, "Item used. Your damage has been increased to " + str_Dmg + ". You have " + str_Quantity8 + " left.", 0x0F, 100);
    }

    if (g_sChar.Poison == true)
    {
        c.X = 1;
        c.Y = 23;
        g_Console.writeToBuffer(c, "You have been Poisoned.", 0x0F, 100);
    }

    if (g_sInven.showItemNotUsed == true)
    {
        c.X = 3;
        c.Y = 26;
        g_Console.writeToBuffer(c, "Item not used.", 0x0F, 100);
    }

    if (g_sInven.showNoQuantity == true)
    {
        c.X = 3;
        c.Y = 26;
        g_Console.writeToBuffer(c, "Item ran out.", 0x0F, 100);
    }
}
void UpdateBattleScreen()
{
    COORD c;
    processUserInput();
    if (g_sInven.resetTimer == true)
    {
        if (InvenTime > 2)
        {
            g_sInven.startTimer = true;
        }
    }

    if (g_sChar.resetTimer == true)
    {
        if (startTime > 5)
        {
            g_sChar.startTimer = true;
        }
    }

    if ((playerInvenTime > 2) && (g_sRawMeat.showItemUsed == true))
    {
        g_sRawMeat.showItemUsed = false;
        playerInvenTime = 0.0;
        c.X = 3;
        c.Y = 26;
        g_Console.writeToBuffer(c, "                                         ", 0x0F, 100);

    }

    if ((playerInvenTime > 2) && (g_sBread.showItemUsed == true))
    {
        g_sBread.showItemUsed = false;
        playerInvenTime = 0.0;
        c.X = 3;
        c.Y = 26;
        g_Console.writeToBuffer(c, "                                         ", 0x0F, 100);
    }

    if ((playerInvenTime > 2) && (g_sBurger.showItemUsed == true))
    {
        g_sBurger.showItemUsed = false;
        playerInvenTime = 0.0;
        c.X = 3;
        c.Y = 26;
        g_Console.writeToBuffer(c, "                                         ", 0x0F, 100);
    }

    if ((playerInvenTime > 2) && (g_sTaco.showItemUsed == true))
    {
        g_sTaco.showItemUsed = false;
        playerInvenTime = 0.0;
        c.X = 3;
        c.Y = 26;
        g_Console.writeToBuffer(c, "                                         ", 0x0F, 100);
    }

    if ((playerInvenTime > 2) && (g_sCake.showItemUsed == true))
    {
        g_sCake.showItemUsed = false;
        playerInvenTime = 0.0;
        c.X = 3;
        c.Y = 26;
        g_Console.writeToBuffer(c, "                                         ", 0x0F, 100);
    }

    if ((playerInvenTime > 2) && (g_sMedicine.showItemUsed == true))
    {
        g_sMedicine.showItemUsed = false;
        playerInvenTime = 0.0;
        c.X = 3;
        c.Y = 26;
        g_Console.writeToBuffer(c, "                                         ", 0x0F, 100);
    }

    if ((playerInvenTime > 2) && (g_sStinger.showItemUsed == true))
    {
        g_sStinger.showItemUsed = false;
        playerInvenTime = 0.0;
        c.X = 3;
        c.Y = 26;
        g_Console.writeToBuffer(c, "                                         ", 0x0F, 100);
    }

    if ((playerInvenTime > 2) && (g_sGuardArmor.showItemUsed == true))
    {
        g_sGuardArmor.showItemUsed = false;
        playerInvenTime = 0.0;
        c.X = 3;
        c.Y = 26;
        g_Console.writeToBuffer(c, "                                         ", 0x0F, 100);
    }

    if ((playerInvenTime > 2) && (g_sInven.showItemNotUsed == true))
    {
        g_sInven.showItemNotUsed = false;
        playerInvenTime = 0.0;
        c.X = 3;
        c.Y = 26;
        g_Console.writeToBuffer(c, "                                         ", 0x0F, 100);

    }
    if ((playerInvenTime > 2) && (g_sInven.showNoQuantity == true))
    {
        g_sInven.showNoQuantity = false;
        playerInvenTime = 0.0;
        c.X = 3;
        c.Y = 26;
        g_Console.writeToBuffer(c, "                                         ", 0x0F, 100);

    }
    if ((g_dkillGuard > 4) && (g_sGuard.startTimer == true))
    {
        g_sGuard.fight = false; // to stop the fighting after enemy die
        g_sGuard.entityDie = true; // make this bool true so that the character will move to (-1,-1)
        g_eGameState = S_Dungeon_Stealth_1; // if player kills guard
        g_sChar.unlockDoorDS1 = true;
    }
    if ((g_dkillGuard > 4) && (g_sGuard2.startTimer == true))
    {
        g_sGuard2.fight = false; // to stop the fighting after enemy die
        g_sGuard2.entityDie = true; // make this bool true so that the character will move to (-1,-1)
        g_eGameState = S_Dungeon_Stealth_1; // if player kills guard
    }
    if ((g_dkillGuard > 4) && (g_sGuard3.startTimer == true))
    {
        g_sGuard3.fight = false; // to stop the fighting after enemy die
        g_sGuard3.entityDie = true; // make this bool true so that the character will move to (-1,-1)
        g_eGameState = S_Dungeon_Stealth_1; // if player kills guard
    }
    if ((g_dkillWasp > 4) && (g_sMutantWasp.startTimer == true))
    {
        g_sMutantWasp.fight = false;
        g_sMutantWasp.startTimer = false;
        g_sMutantWasp2.fight = true;
        g_eGameState = S_BattleScreen;
        Sprites.Battle_Wasp(g_Console, 0);
    }
    if ((g_dkillWasp > 4) && (g_sMutantWasp2.startTimer == true))
    {
        g_sMutantWasp2.fight = false;
        g_sMutantWasp2.startTimer = false;
        g_dMedical2Time = 0.0;
        g_eGameState = S_Medical_Facility_Part2_Animation;
    }
    if ((g_dkillRaymond > 4) && (g_sRaymondBoss.startTimer == true))  // raymond die
    {
        g_sRaymondBoss.fight = false;
        g_dBossEndTime = 0.0;
        g_eGameState = S_Boss_Room_End_Animation;
    }
    if ((g_dkillPig > 4) && (g_sPig.startTimer == true))
    {
        g_sPig.fight = false;
        g_sPig.entityDie = true;
        g_eGameState = S_OAF;
    }
    if ((g_dkillPig > 4) && (g_sPig2.startTimer == true))
    {
        g_sPig2.fight = false;
        g_sPig2.entityDie = true;
        g_eGameState = S_OAF;
    }
    if ((g_dkillPig > 4) && (g_sPig3.startTimer == true))
    {
        g_sPig3.fight = false;
        g_sPig3.entityDie = true;
        g_eGameState = S_OAF;
    }
    if ((g_dkillRobert > 4) && (g_sChar.entityDie == true))
    {
        g_eGameState = S_Game_Over; // show game over screen after player die animation
    }
    if ((g_dkillTutWasp > 4) && (g_sTutEnemy.startTimer == true))
    {
        g_sTutEnemy.fight = false;
        g_sTutEnemy.startTimer = false;
        g_eGameState = S_Path_Area; // show game over screen after player die animation
    }

    if ((playerDMGTime > 3) && (g_sChar.showPlayerDMG == true))
    {
        //g_eGameState = S_Townsquare;
        g_sChar.showPlayerDMG = false;
        playerDMGTime = 0.0;
        c.X = 3;
        c.Y = 25;
        g_Console.writeToBuffer(c, "                                         ", 0x0F, 100);

    }
    if ((enemyDMGTime > 3) && (g_sChar.showEnemyDMG == true))
    {
        g_sChar.showEnemyDMG = false;
        enemyDMGTime = 0.0;
        c.X = 3;
        c.Y = 26;
        g_Console.writeToBuffer(c, "                                         ", 0x0F, 100);

    }

    if (g_sStinger.showItemDropped == true)
    {
        c.X = 3;
        c.Y = 26;
        g_Console.writeToBuffer(c, "You received a Stinger", 0x0F, 100);
    }
    if (g_sGuardArmor.showItemDropped == true)
    {
        c.X = 3;
        c.Y = 26;
        g_Console.writeToBuffer(c, "You received a Guard Armor.", 0x0F, 100);
    }
}


void renderMap_wireGame()
{
    COORD c;
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    mini.wire_game(g_Console);

    //Border
    for (int i = 51; i < 78; i++)
    {
        c.Y = 7;
        c.X = i;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '-', 0x0F);
    }

    for (int i = 51; i < 78; i++)
    {
        c.Y = 17;
        c.X = i;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '-', 0x0F);
    }

    //Gate 1
    for (int j = 8; j < 17; j++)
    {
        c.Y = j;
        c.X = 54;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '|', 0x0C);
    }

    //Gate 2
    for (int j = 8; j < 17; j++)
    {
        c.Y = j;
        c.X = 58;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '|', 0x0B);
    }

    //Gate 3
    for (int j = 8; j < 17; j++)
    {
        c.Y = j;
        c.X = 62;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '|', 0x0A);
    }

    //Gate 4
    for (int j = 8; j < 17; j++)
    {
        c.Y = j;
        c.X = 66;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '|', 0x0C);
    }

    //Gate 5
    for (int j = 8; j < 17; j++)
    {
        c.Y = j;
        c.X = 70;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '|', 0x0B);
    }

    //Gate 6
    for (int j = 8; j < 17; j++)
    {
        c.Y = j;
        c.X = 74;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '|', 0x0A);
    }

    //Letters & Numbers
    c.Y = 6;
    c.X = 52;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'A', 0x0C);
    c.X = 56;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '3', 0x0B);
    c.X = 60;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'B', 0x0A);
    c.X = 64;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '2', 0x0C);
    c.X = 68;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'C', 0x0B);
    c.X = 72;
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '1', 0x0A);

    //Door to get back to IAF1
    for (int j = 8; j < 17; j++)
    {
        c.Y = j;
        c.X = 77;
        g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '@', 0x0D);
    }

    if (g_sBox1.startTimer == true)
    {
        for (int j = 8; j < 17; j++)
        {
            c.Y = j;
            c.X = 54;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = ' ', 0x0F);
        }
    }
    if (g_sBox2.startTimer == true)
    {
        for (int j = 8; j < 17; j++)
        {
            c.Y = j;
            c.X = 58;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = ' ', 0x0F);
        }
    }
    if (g_sBox3.startTimer == true)
    {
        for (int j = 8; j < 17; j++)
        {
            c.Y = j;
            c.X = 62;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = ' ', 0x0F);
        }
    }
    if (g_sBox4.startTimer == true)
    {
        for (int j = 8; j < 17; j++)
        {
            c.Y = j;
            c.X = 66;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = ' ', 0x0F);
        }
    }
    if (g_sBox5.startTimer == true)
    {
        for (int j = 8; j < 17; j++)
        {
            c.Y = j;
            c.X = 70;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = ' ', 0x0F);
        }
    }
    if (g_sBox6.startTimer == true)
    {
        for (int j = 8; j < 17; j++)
        {
            c.Y = j;
            c.X = 74;
            g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = ' ', 0x0F);
        }
    }
    renderCharacter();  // renders the character into the buffer
    renderBoxes();

    //box 1
    if ((g_sChar.m_cLocation.X == g_sBox1.m_cLocation.X) && (g_sChar.m_cLocation.Y == (g_sBox1.m_cLocation.Y)))
    {
        if (g_skKeyEvent[K_UP].keyDown && g_sChar.m_cLocation.Y > 10)
        {
            g_sBox1.m_cLocation.Y--;
            if (g_sBox1.m_cLocation.Y == 10 && (g_sBox1.m_cLocation.X == 16 || g_sBox1.m_cLocation.X == 17 || g_sBox1.m_cLocation.X == 18))
            {
                g_sBox1.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_DOWN].keyDown && g_sChar.m_cLocation.Y < 15)
        {
            g_sBox1.m_cLocation.Y++;
            if (g_sBox1.m_cLocation.Y == 10 && (g_sBox1.m_cLocation.X == 16 || g_sBox1.m_cLocation.X == 17 || g_sBox1.m_cLocation.X == 18))
            {
                g_sBox1.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_LEFT].keyDown && g_sChar.m_cLocation.X > 3)
        {
            g_sBox1.m_cLocation.X--;
            if (g_sBox1.m_cLocation.Y == 10 && (g_sBox1.m_cLocation.X == 16 || g_sBox1.m_cLocation.X == 17 || g_sBox1.m_cLocation.X == 18))
            {
                g_sBox1.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_RIGHT].keyDown && g_sChar.m_cLocation.X < 50)
        {
            g_sBox1.m_cLocation.X++;
            if (g_sBox1.m_cLocation.Y == 10 && (g_sBox1.m_cLocation.X == 16 || g_sBox1.m_cLocation.X == 17 || g_sBox1.m_cLocation.X == 18))
            {
                g_sBox1.startTimer = true;
            }
        }
    }

    //box 4
    if ((g_sChar.m_cLocation.X == g_sBox4.m_cLocation.X) && (g_sChar.m_cLocation.Y == (g_sBox4.m_cLocation.Y)))
    {
        if (g_skKeyEvent[K_UP].keyDown && g_sChar.m_cLocation.Y > 10)
        {
            g_sBox4.m_cLocation.Y--;
            if (g_sBox4.m_cLocation.Y == 15 && (g_sBox4.m_cLocation.X == 31 || g_sBox4.m_cLocation.X == 32 || g_sBox4.m_cLocation.X == 33))
            {
                g_sBox4.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_DOWN].keyDown && g_sChar.m_cLocation.Y < 15)
        {
            g_sBox4.m_cLocation.Y++;
            if (g_sBox4.m_cLocation.Y == 15 && (g_sBox4.m_cLocation.X == 31 || g_sBox4.m_cLocation.X == 32 || g_sBox4.m_cLocation.X == 33))
            {
                g_sBox4.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_LEFT].keyDown && g_sChar.m_cLocation.X > 3)
        {
            g_sBox4.m_cLocation.X--;
            if (g_sBox4.m_cLocation.Y == 15 && (g_sBox4.m_cLocation.X == 31 || g_sBox4.m_cLocation.X == 32 || g_sBox4.m_cLocation.X == 33))
            {
                g_sBox4.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_RIGHT].keyDown && g_sChar.m_cLocation.X < 50)
        {
            g_sBox4.m_cLocation.X++;
            if (g_sBox4.m_cLocation.Y == 15 && (g_sBox4.m_cLocation.X == 31 || g_sBox4.m_cLocation.X == 32 || g_sBox4.m_cLocation.X == 33))
            {
                g_sBox4.startTimer = true;
            }
        }
    }
    //box 2
    if ((g_sChar.m_cLocation.X == g_sBox2.m_cLocation.X) && (g_sChar.m_cLocation.Y == (g_sBox2.m_cLocation.Y)))
    {
        if (g_skKeyEvent[K_UP].keyDown && g_sChar.m_cLocation.Y > 10)
        {
            g_sBox2.m_cLocation.Y--;
            if (g_sBox2.m_cLocation.Y == 15 && (g_sBox2.m_cLocation.X == 47 || g_sBox2.m_cLocation.X == 48))
            {
                g_sBox2.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_DOWN].keyDown && g_sChar.m_cLocation.Y < 15)
        {
            g_sBox2.m_cLocation.Y++;
            if (g_sBox2.m_cLocation.Y == 15 && (g_sBox2.m_cLocation.X == 47 || g_sBox2.m_cLocation.X == 48))
            {
                g_sBox2.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_LEFT].keyDown && g_sChar.m_cLocation.X > 3)
        {
            g_sBox2.m_cLocation.X--;
            if (g_sBox2.m_cLocation.Y == 15 && (g_sBox2.m_cLocation.X == 47 || g_sBox2.m_cLocation.X == 48))
            {
                g_sBox2.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_RIGHT].keyDown && g_sChar.m_cLocation.X < 50)
        {
            g_sBox2.m_cLocation.X++;
            if (g_sBox2.m_cLocation.Y == 15 && (g_sBox2.m_cLocation.X == 47 || g_sBox2.m_cLocation.X == 48))
            {
                g_sBox2.startTimer = true;
            }
        }
    }

    //box 5
    if ((g_sChar.m_cLocation.X == g_sBox5.m_cLocation.X) && (g_sChar.m_cLocation.Y == (g_sBox5.m_cLocation.Y)))
    {
        if (g_skKeyEvent[K_UP].keyDown && g_sChar.m_cLocation.Y > 10)
        {
            g_sBox5.m_cLocation.Y--;
            if (g_sBox5.m_cLocation.Y == 10 && (g_sBox5.m_cLocation.X == 47 || g_sBox5.m_cLocation.X == 48))
            {
                g_sBox5.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_DOWN].keyDown && g_sChar.m_cLocation.Y < 15)
        {
            g_sBox5.m_cLocation.Y++;
            if (g_sBox5.m_cLocation.Y == 10 && (g_sBox5.m_cLocation.X == 47 || g_sBox5.m_cLocation.X == 48))
            {
                g_sBox5.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_LEFT].keyDown && g_sChar.m_cLocation.X > 3)
        {
            g_sBox5.m_cLocation.X--;
            if (g_sBox5.m_cLocation.Y == 10 && (g_sBox5.m_cLocation.X == 47 || g_sBox5.m_cLocation.X == 48))
            {
                g_sBox5.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_RIGHT].keyDown && g_sChar.m_cLocation.X < 50)
        {
            g_sBox5.m_cLocation.X++;
            if (g_sBox5.m_cLocation.Y == 10 && (g_sBox5.m_cLocation.X == 47 || g_sBox5.m_cLocation.X == 48))
            {
                g_sBox5.startTimer = true;
            }
        }
    }

    //box 3
    if ((g_sChar.m_cLocation.X == g_sBox3.m_cLocation.X) && (g_sChar.m_cLocation.Y == (g_sBox3.m_cLocation.Y)))
    {
        if (g_skKeyEvent[K_UP].keyDown && g_sChar.m_cLocation.Y > 10)
        {
            g_sBox3.m_cLocation.Y--;
            if (g_sBox3.m_cLocation.X == 32 && g_sBox3.m_cLocation.Y == 10)
            {
                g_sBox3.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_DOWN].keyDown && g_sChar.m_cLocation.Y < 15)
        {
            g_sBox3.m_cLocation.Y++;
            if (g_sBox3.m_cLocation.X == 32 && g_sBox3.m_cLocation.Y == 10)
            {
                g_sBox3.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_LEFT].keyDown && g_sChar.m_cLocation.X > 3)
        {
            g_sBox3.m_cLocation.X--;
            if (g_sBox3.m_cLocation.X == 32 && g_sBox3.m_cLocation.Y == 10)
            {
                g_sBox3.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_RIGHT].keyDown && g_sChar.m_cLocation.X < 50)
        {
            g_sBox3.m_cLocation.X++;
            if (g_sBox3.m_cLocation.X == 32 && g_sBox3.m_cLocation.Y == 10)
            {
                g_sBox3.startTimer = true;
            }
        }
    }

    //box 6
    if ((g_sChar.m_cLocation.X == g_sBox6.m_cLocation.X) && (g_sChar.m_cLocation.Y == (g_sBox6.m_cLocation.Y)))
    {
        if (g_skKeyEvent[K_UP].keyDown && g_sChar.m_cLocation.Y > 10)
        {
            g_sBox6.m_cLocation.Y--;
            if (g_sBox6.m_cLocation.X == 17 && g_sBox6.m_cLocation.Y == 15)
            {
                g_sBox6.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_DOWN].keyDown && g_sChar.m_cLocation.Y < 15)
        {
            g_sBox6.m_cLocation.Y++;
            if (g_sBox6.m_cLocation.X == 17 && g_sBox6.m_cLocation.Y == 15)
            {
                g_sBox6.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_LEFT].keyDown && g_sChar.m_cLocation.X > 3)
        {
            g_sBox6.m_cLocation.X--;
            if (g_sBox6.m_cLocation.X == 17 && g_sBox6.m_cLocation.Y == 15)
            {
                g_sBox6.startTimer = true;
            }
        }
        if (g_skKeyEvent[K_RIGHT].keyDown && g_sChar.m_cLocation.X < 50)
        {
            g_sBox6.m_cLocation.X++;
            if (g_sBox6.m_cLocation.X == 17 && g_sBox6.m_cLocation.Y == 15)
            {
                g_sBox6.startTimer = true;
            }
        }
    }

    if ((g_sChar.m_cLocation.Y == 8 || g_sChar.m_cLocation.Y == 9 || g_sChar.m_cLocation.Y == 10 || g_sChar.m_cLocation.Y == 11 || g_sChar.m_cLocation.Y == 12 || g_sChar.m_cLocation.Y == 13 || g_sChar.m_cLocation.Y == 14 || g_sChar.m_cLocation.Y == 15 || g_sChar.m_cLocation.Y == 16) && g_sChar.m_cLocation.X == 77)
    {
        g_dPathTime = 0.0;
        g_eGameState = S_IAF1;
        g_sChar.m_cLocation.X = 56;
        g_sChar.m_cLocation.Y = 5;
    }
}

void renderBoxes()
{
    g_Console.writeToBuffer(g_sBox1.m_cLocation, '[', 0x0C);
    g_Console.writeToBuffer(g_sBox2.m_cLocation, '[', 0x0B);
    g_Console.writeToBuffer(g_sBox3.m_cLocation, '[', 0x0A);
    g_Console.writeToBuffer(g_sBox4.m_cLocation, '[', 0x0C);
    g_Console.writeToBuffer(g_sBox5.m_cLocation, '[', 0x0B);
    g_Console.writeToBuffer(g_sBox6.m_cLocation, '[', 0x0A);
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
        g_Console.writeToBuffer(c, "Got it!", 0x0B, 100);
        g_Console.writeToBuffer(d, "Press the ENTER key to extinguish the fire!", 0x0B, 100);
        g_Console.writeToBuffer(e, "Ensure that you are close to the fire first.", 0x0B, 100);

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
        g_Console.writeToBuffer(c, "Gotcha!", 0x0B, 100);
        e.X = 5;
        e.Y = 27;
        g_Console.writeToBuffer(e, "Hurry! Get out of here now!", 0x0B, 100);
        f.X = 5;
        f.Y = 28;
        g_Console.writeToBuffer(f, "@ = Unlocked Door", 0x0B, 100);
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
            //g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 1, ss.str(), 0x59);
        }
        else if (g_mouseEvent.buttonState == RIGHTMOST_BUTTON_PRESSED)
        {
            ss.str("Right Button Pressed");
            //g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 2, ss.str(), 0x59);
        }
        else
        {
            ss.str("Some Button Pressed");
            //g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 3, ss.str(), 0x59);
        }
        break;
    case DOUBLE_CLICK:
        ss.str("Double Clicked");
        //g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 4, ss.str(), 0x59);
        break;
    case MOUSE_WHEELED:
        if (g_mouseEvent.buttonState & 0xFF000000)
            ss.str("Mouse wheeled down");
        else
            ss.str("Mouse wheeled up");
        //g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 5, ss.str(), 0x59);
        break;
    default:
        break;
    }
}

void render_Main_Menu()
{
    while (mainMenu_music == false)
    {
        PlaySound(TEXT("8 Bit Retro Funk.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        mainMenu_music = true;
    }
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
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = '/');

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
        g_dStartScene = 0.0;
        g_eGameState = S_Start_Animation;
    }
    if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 21)) && ((g_mouseEvent.mousePosition.X == 34) || (g_mouseEvent.mousePosition.X == 35) || (g_mouseEvent.mousePosition.X == 36) || (g_mouseEvent.mousePosition.X == 37) || (g_mouseEvent.mousePosition.X == 38) || (g_mouseEvent.mousePosition.X == 39) || (g_mouseEvent.mousePosition.X == 40) || (g_mouseEvent.mousePosition.X == 41) || (g_mouseEvent.mousePosition.X == 42))))
    {
        g_bQuitGame = true;
    }
}

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
            if (g_sChar.CP1 == true)
            {
                g_eGameState = S_OAF;
                g_sChar.m_cLocation.X = 7;
                g_sChar.m_cLocation.Y = 21;
            }
            if (g_sChar.CP2 == true)
            {
                g_eGameState = S_Dungeon_Stealth_1;
                g_sChar.m_cLocation.X = 5;
                g_sChar.m_cLocation.Y = 21;
            }
            if (g_sChar.CP3 == true)
            {
                g_eGameState = S_Dungeon_Stealth_3;
                g_sChar.m_cLocation.X = 41;
                g_sChar.m_cLocation.Y = 21;
            };
        }
        //For Quit
        else if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 22)) && ((g_mouseEvent.mousePosition.X == 37) || (g_mouseEvent.mousePosition.X == 38) || (g_mouseEvent.mousePosition.X == 39) || (g_mouseEvent.mousePosition.X == 40))))
        {
            g_bQuitGame = true;
            g_sChar.m_cLocation.X = 4;
            g_sChar.m_cLocation.Y = 18;
        }

    }

}
