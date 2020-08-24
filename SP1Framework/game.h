#ifndef _GAME_H
#define _GAME_H
#include "Enemy.h"
#include "Framework\timer.h"

extern CStopWatch g_swTimer;
extern bool g_bQuitGame;
//j

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
    S_Orphanage_Animation,
    S_GAME,
    S_Townsquare,
    S_Protest_Area,
    S_Path_Area,
    S_Dungeon_Stealth_1,
    S_Orphanage_Children_Animation,
    S_Protest_Area_Animation,
    S_Dungeon_Cell_Animation,
    S_Path_Area_Animation,
    S_OAF,
    S_IAF3_Animation,
    s_Medical_Facility_Animation,
    S_Dungeon_Stealth3_Animation,
    S_Boss_Room_Animation,
    S_BattleScreen,
    S_COUNT
};

// struct for the game character
struct SGameChar : public Enemy
{
    COORD m_cLocation;
    COORD e_cLocation;
    COORD f_cLocation;
    COORD g_cLocation;
    bool  m_bActive;
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
    bool Jerry;
    bool Tom;
    bool Charles;
    bool Bobby;
    bool Emmanuel;
    bool Harry;
    bool Sam;
    bool startTimer;
    bool resetTimer;
};
void init(void);      // initialize your variables, allocate memory, etc
void getInput(void);      // get input from player
void update(double dt); // update the game and the state of the game
void render(void);      // renders the current state of the game to the console
void shutdown(void);      // do clean up, free memory

void Update_Menu();
void clearMenu();
void splashScreenWait();    // waits for time to pass in splash screen
void updateGame();          // gameplay logic
void moveCharacter();       // moves the character, collision detection, physics, etc
void processUserInput();    // checks if you should change states or do something else with the game, e.g. pause, exit
void clearScreen();         // clears the current screen and draw from scratch 
void renderSplashScreen();  // renders the splash screen
void renderGame();          // renders the game stuff
//void renderMap();           // renders the map to the buffer first
void renderMap_Townsquare();
void renderMap_Protest_Area();
void renderMap_Path_Area();
void renderMap_OAF();
void render_DS1();
void RenderBattleScreen();

void renderCharacter();     // renders the character into the buffer
void renderEnemy();
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game
void renderInputEvents();   // renders the status of input events

// keyboard and mouse input event managers
void keyboardHandler(const KEY_EVENT_RECORD& keyboardEvent);  // define this function for the console to call when there are keyboard events
void mouseHandler(const MOUSE_EVENT_RECORD& mouseEvent);      // define this function for the console to call when there are mouse events

void gameplayKBHandler(const KEY_EVENT_RECORD& keyboardEvent);   // handles keyboard events for gameplay 
void gameplayMouseHandler(const MOUSE_EVENT_RECORD& mouseEvent); // handles mouse events for gameplay 

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
void Update_Medical_Facility_Animation();
void Medical_Facility_Animation();
void Update_Dungeon_Stealth3_Animation();
void Dungeon_Stealth3_Animation();
void Update_Boss_Room_Animation();
void Boss_Room_Animation();
void render_Main_Menu();
void UpdateBattleScreen();

#endif //_GAME_H
