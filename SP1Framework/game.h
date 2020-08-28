#ifndef _GAME_H
#define _GAME_H
#include "Enemy.h"
#include "Framework\timer.h"

extern CStopWatch g_swTimer;
extern bool g_bQuitGame;

// struct to store keyboard events
// a small subset of KEY_EVENT_RECORD
struct SKeyEvent
{
    bool keyDown;
    bool keyReleased;
};

// struct to store mouse events
// a small subset of MOUSE_EVENT_RECORD
struct SMouseEvent
{
    COORD mousePosition;
    DWORD buttonState;
    DWORD eventFlags;
};

// Enumeration to store the control keys that your game will have
enum EKEYS
{
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_ESCAPE,
    K_SPACE,
    K_RETURN,
    K_COUNT
};

// Enumeration for the different screen states
enum EGAMESTATES
{
    S_MENU_UI,
    S_SPLASHSCREEN,
    S_Game_Over,
    S_GAME,
    //Areas
    S_Townsquare,
    S_Protest_Area,
    S_Path_Area,
    S_OAF,
    S_IAF1,
    S_IAF2,
    S_IAF3,
    S_IAF4,
    S_Inside_Medical_Facility,
    S_Dungeon_Cell,
    S_Dungeon_Stealth_1,
    S_Dungeon_Stealth_2,
    S_Dungeon_Stealth_3,
    S_Boss_Battle_Room,
    //Animations
    S_Start_Animation,
    S_Orphanage_Animation,
    S_Orphanage_Children_Animation,
    S_Protest_Area_Animation,
    S_Dungeon_Cell_Animation,
    S_Path_Area_Animation,
    S_IAF3_Animation,
    S_Medical_Fight_Animation,
    S_Medical_Facility_Animation,
    S_Medical_Facility_Part2_Animation,
    S_Dungeon_Stealth3_Animation,
    S_Boss_Room_Animation,
    S_BattleScreen,
    S_wireGame,
    //Battle animations
    S_SlashGuard,
    S_KillGuard,
    S_slashWasp,
    S_killWasp,
    S_slashPig,
    S_killPig,
    S_slashRaymond,
    S_killRaymond,
    S_slashRobert,
    S_killRobert,
    S_slashTutWasp,
    S_killTutWasp,
    //Boss Fight
    S_phase2Battle,
    S_COUNT

    
};

// struct for the game character
struct SGameChar : public Enemy
{
    int count;
    COORD m_cLocation;
    bool m_bActive;
    bool fire;
    bool fireOut;
    bool Orp_Obj1;
    bool Orp_Obj2;
    bool Orp_Dialogue;
    bool takenBackpack;
    bool takenExtinguisher;
    bool counter;
    bool xLeft;
    bool xRight;
    bool xUp;
    bool xDown;
    bool talked;
    bool startTimer;
    bool resetTimer;
    bool showPlayerDMG;
    bool showEnemyDMG;
    bool unlockDoorDS1;
    bool Poison;
    bool faceLeft;
    bool faceRight;
    bool fight;
    bool entityDie;
    bool InvenActive;
    bool itemActive;
    bool showItemUsed;
    bool showItemNotUsed;
    bool showItem;
    bool collected;
    bool CP1;
    bool CP2;
    bool CP3;
    int nextDialogue;
    int laserCount;
    bool entityDied;
    bool animationPlayed;
    bool enterArea;
    int randNum;
};
void init(void);      // initialize your variables, allocate memory, etc
void getInput(void);      // get input from player
void update(double dt); // update the game and the state of the game
void render(void);      // renders the current state of the game to the console
void shutdown(void);      // do clean up, free memory

//update
void Update_Menu();
void UpdateGameOver();
void clearMenu();
void splashScreenWait();    // waits for time to pass in splash screen
void updateGame();          // gameplay logic
void moveCharacter();       // moves the character, collision detection, physics, etc
void processUserInput();    // checks if you should change states or do something else with the game, e.g. pause, exit
void clearScreen();         // clears the current screen and draw from scratch 
void renderSplashScreen();  // renders the splash screen
void renderGame();          // renders the game stuff
//void renderMap();  // renders the map to the buffer first

//Render areas + Battle screens
void renderBox();
void renderBoxes();
void renderMap_Townsquare();
void renderMap_Protest_Area();
void renderMap_Path_Area();
void renderMap_OAF();
void renderMap_IAF1();
void renderMap_IAF2();
void renderMap_IAF3();
void renderMap_IAF4();
void renderMap_Inside_Medical_Facility();
void renderMap_Dungeon_Cell();
void renderMap_DS1();
void renderMap_DS2();
void renderMap_DS3();
void renderMap_Boss_Battle_Room();
void RenderBattleScreen();  // render battle screen
void renderMap_wireGame();

void renderMap_NPC();       // render NPCs in Townsquare
void renderCharacter();     // renders the character into the buffer.
void renderEnemy();         // render enemy
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game
void renderInputEvents();   // renders the status of input events

// keyboard and mouse input event managers
void keyboardHandler(const KEY_EVENT_RECORD& keyboardEvent);  // define this function for the console to call when there are keyboard events
void mouseHandler(const MOUSE_EVENT_RECORD& mouseEvent);      // define this function for the console to call when there are mouse events

void gameplayKBHandler(const KEY_EVENT_RECORD& keyboardEvent);   // handles keyboard events for gameplay 
void gameplayMouseHandler(const MOUSE_EVENT_RECORD& mouseEvent); // handles mouse events for gameplay 

//Animations + Menu AI
void Update_starting_cutscene();
void starting_cutscene();
void RenderGameOver();
void Update_Orphanage_Animation();
void Orphanage_Animation();
void Update_Orphanage_Animation2();
void Orphanage_Children_Animation();
void Update_Protest_Area();
void Protest_Area_Animation();
void Update_Dungeon_Cell();
void Dungeon_Cell_Animation();
void Update_Path_Area();
void Path_Area_Animation();
void Update_IAF3();
void IAF3_Animation();
void Update_Medical_Fight_Animation();
void Medical_Fight_Animation();
void Update_Medical_Facility_Animation();
void Medical_Facility_Animation();
void Update_Medical_Facility_Part2_Animation();
void Medical_Facility_Part2_Animation();
void Update_Dungeon_Stealth3_Animation();
void Dungeon_Stealth3_Animation();
void Update_Boss_Room_Animation();
void Boss_Room_Animation();
void render_Main_Menu();
void UpdateBattleScreen();


//Animate Battle
void Update_slashGuard();
void slashGuard();
void Update_killGuard();
void killGuard();
void Update_slashWasp();
void slashWasp();
void Update_killWasp();
void killWasp();
void Update_slashPig();
void slashPig();
void Update_killPig();
void killPig();
void Update_slashRaymond();
void slashRaymond();
void Update_killRaymond();
void killRaymond();
void Update_slashRobert();
void slashRobert();
void Update_killRobert();
void killRobert();
void Update_slashTutWasp();
void slashTutWasp();
void Update_killTutWasp();
void killTutWasp();
void drawLaser(Console& g_Console, int j);
void drawLaser2(Console& g_Console, int j);


//Raymond Battle Paths
void Update_phase2Battle();
void phase2Battle();

//Others
void renderMap_GuardStealth();
void update_GuardDirection();
void renderMap_GuardDirection();

#endif //_GAME_H
