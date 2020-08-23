// This is the main file for the game logic and function
//1
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Map.h"
#include "Cutscenes.h"
using namespace std;

double  g_dElapsedTime;
double g_dChildrenTime;
double g_dProtestTime;
double g_dDungeonTime;
double g_dPathTime;
double g_dIAF3Time;
double  g_dDeltaTime;
SKeyEvent g_skKeyEvent[K_COUNT];
SMouseEvent g_mouseEvent;

// Game specific variables here
SGameChar   g_sChar;
SGameChar   g_sEnemy;
SGameChar   Pig;
EGAMESTATES g_eGameState; // game states

// Console object
Console g_Console(80, 30, "SP1 Framework");
// Map object
Map rMap;
Map eMap;
Cutscenes Cutscene;
//--------------------------------------------------------------
// Purpose  : Initialisation function
//            Initialize variables, allocate memory, load data from file, etc. 
//            This is called once before entering into your main loop
// Input    : void
// Output   : void
//--------------------------------------------------------------
void init( void )
{
    Pig.SetD(5);
    g_sChar.counter = false;
    g_sChar.fire = false;
    g_sChar.fireOut = false;
    // Set precision for floating point output
    g_dElapsedTime = 0.0;    
    g_dProtestTime = 0.0;

    // sets the initial state for the game
    g_eGameState = S_MENU_UI;

    g_sChar.m_cLocation.X = 22;//g_Console.getConsoleSize().X / 2;
    g_sChar.m_cLocation.Y = 18;//g_Console.getConsoleSize().Y / 2;
    g_sChar.m_bActive = true;

    g_sEnemy.e_cLocation.X = 10;
    g_sEnemy.e_cLocation.Y = 10;

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
void shutdown( void )
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
void getInput( void )
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
    case S_SPLASHSCREEN: // don't handle anything for the splash screen
        break;
    case S_GAME: gameplayKBHandler(keyboardEvent); // handle gameplay keyboard event 
        break;
    case S_Townsquare: gameplayKBHandler(keyboardEvent); // handle gameplay keyboard event 
        break;
    case S_Protest_Area: gameplayKBHandler(keyboardEvent); // handle gameplay keyboard event 
        break;
    case S_Path_Area: gameplayKBHandler(keyboardEvent); // handle gameplay keyboard event 
        break;
    case S_Orphanage_Animation: gameplayKBHandler(keyboardEvent);
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
    case S_SPLASHSCREEN: // don't handle anything for the splash screen
        break;
    case S_GAME: gameplayMouseHandler(mouseEvent); // handle gameplay mouse event
        break;
    case S_Townsquare: gameplayMouseHandler(mouseEvent); // handle gameplay mouse event
        break;
    case S_Protest_Area: gameplayMouseHandler(mouseEvent); // handle gameplay mouse event
        break;
    case S_Path_Area: gameplayMouseHandler(mouseEvent); // handle gameplay mouse event
        break;
    case S_Orphanage_Animation: gameplayMouseHandler(mouseEvent);
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

    switch (g_eGameState)
    {
        case S_MENU_UI: Update_Menu();
            break;
        case S_SPLASHSCREEN : splashScreenWait(); // game logic for the splash screen
            break;
        case S_Orphanage_Animation: Update_Orphanage_Animation();
            break;
        case S_Orphanage_Children_Animation: Update_Orphanage_Animation2();
            break;
        case S_GAME: updateGame(); // gameplay logic when we are in the game
            break;
        case S_Townsquare: updateGame(); // gameplay logic when we are in the game
            break;
        case S_Protest_Area: updateGame(); // gameplay logic when we are in the game
            break;
        case S_Protest_Area_Animation: Update_Protest_Area();
            break;
        case S_Path_Area: updateGame(); // gameplay logic when we are in the game
            break;
        case S_Path_Area_Animation: Update_Path_Area();
            break;
        case S_Dungeon_Cell_Animation: Update_Dungeon_Cell();
            break;
        case S_IAF3_Animation: Update_IAF3();
    }
}
void Update_Menu()
{
    g_sChar.counter = true;
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
                    Cutscene.drawgrid(g_Console, 11, 7, 'O');
                    if (g_dElapsedTime > 2.4)
                    {
                        Cutscene.cleargrid(g_Console, 11, 7);
                        Cutscene.drawgrid(g_Console, 9, 7, 'O');
                        if (g_dElapsedTime > 2.7)
                        {
                            Cutscene.cleargrid(g_Console, 9, 7);
                            Cutscene.drawgrid(g_Console, 13, 7, 'O');
                            if (g_dElapsedTime > 3.0)
                            {
                                Cutscene.cleargrid(g_Console, 13, 7);
                                Cutscene.drawgrid(g_Console, 11, 7, 'O');
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
                                                        g_Console.writeToBuffer(c,"Objective: Take the fire extinguisher and put out the fire!", 0x0F, 100);
                                                    }
                                                }
                                            }
                                        }
                                    }
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
        g_eGameState = S_GAME;
    }
    processUserInput();
}
void Orphanage_Children_Animation()
{
    rMap.initialise(g_Console);
    rMap.Animation(g_Console, 11, 7, 'O');
    rMap.Animation(g_Console, 9, 7, 'O');
    rMap.Animation(g_Console, 13, 7, 'O');
    rMap.Animation(g_Console, 11, 7, 'O');
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
    COORD c;
    renderCharacter();
    c.X = 5;
    c.Y = 26;
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
                                                        Cutscene.drawgrid(g_Console, 56, 22, 'O');
                                                        Cutscene.drawgrid(g_Console, 64, 21, 'O');
                                                        Cutscene.drawgrid(g_Console, 62, 18, 'O');
                                                        Cutscene.drawgrid(g_Console, 54, 18, 'O');
                                                        Cutscene.drawgrid(g_Console, 50, 21, 'O');
                                                        if (g_dChildrenTime > 12.3)
                                                        {
                                                            Cutscene.cleargrid(g_Console, 56, 22);
                                                            Cutscene.cleargrid(g_Console, 64, 21);
                                                            Cutscene.cleargrid(g_Console, 62, 18);
                                                            Cutscene.cleargrid(g_Console, 54, 18);
                                                            Cutscene.cleargrid(g_Console, 50, 21);
                                                            Cutscene.drawgrid(g_Console, 56, 22, 'O');
                                                            Cutscene.drawgrid(g_Console, 64, 22, 'O');
                                                            Cutscene.drawgrid(g_Console, 62, 19, 'O');
                                                            Cutscene.drawgrid(g_Console, 54, 19, 'O');
                                                            Cutscene.drawgrid(g_Console, 50, 22, 'O');
                                                            if (g_dChildrenTime > 12.6)
                                                            {
                                                                Cutscene.cleargrid(g_Console, 56, 22);
                                                                Cutscene.cleargrid(g_Console, 64, 22);
                                                                Cutscene.cleargrid(g_Console, 62, 19);
                                                                Cutscene.cleargrid(g_Console, 54, 19);
                                                                Cutscene.cleargrid(g_Console, 50, 22);
                                                                Cutscene.drawgrid(g_Console, 64, 22, 'O');
                                                                Cutscene.drawgrid(g_Console, 62, 20, 'O');
                                                                Cutscene.drawgrid(g_Console, 54, 20, 'O');
                                                                Cutscene.drawgrid(g_Console, 50, 22, 'O');
                                                                if (g_dChildrenTime > 12.9)
                                                                {
                                                                    Cutscene.cleargrid(g_Console, 64, 22);
                                                                    Cutscene.cleargrid(g_Console, 62, 20);
                                                                    Cutscene.cleargrid(g_Console, 54, 20);
                                                                    Cutscene.cleargrid(g_Console, 50, 22);
                                                                    Cutscene.drawgrid(g_Console, 64, 22, 'O');
                                                                    Cutscene.drawgrid(g_Console, 62, 21, 'O');
                                                                    Cutscene.drawgrid(g_Console, 54, 21, 'O');
                                                                    Cutscene.drawgrid(g_Console, 50, 22, 'O');
                                                                    if (g_dChildrenTime > 13.2)
                                                                    {
                                                                        Cutscene.cleargrid(g_Console, 64, 22);
                                                                        Cutscene.cleargrid(g_Console, 62, 21);
                                                                        Cutscene.cleargrid(g_Console, 54, 21);
                                                                        Cutscene.cleargrid(g_Console, 50, 22);
                                                                        Cutscene.drawgrid(g_Console, 62, 22, 'O');
                                                                        Cutscene.drawgrid(g_Console, 54, 22, 'O');
                                                                        if (g_dChildrenTime > 13.5)
                                                                        {
                                                                            Cutscene.cleargrid(g_Console, 62, 22);
                                                                            Cutscene.cleargrid(g_Console, 54, 22);
                                                                            Cutscene.drawgrid(g_Console, 62, 22, 'O');
                                                                            Cutscene.drawgrid(g_Console, 54, 22, 'O');
                                                                            if (g_dChildrenTime > 13.8)
                                                                            {
                                                                                Cutscene.cleargrid(g_Console, 62, 22);
                                                                                Cutscene.cleargrid(g_Console, 54, 22);
                                                                                Cutscene.drawgrid(g_Console, 62, 22, 'O');
                                                                                Cutscene.drawgrid(g_Console, 54, 22, 'O');
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
        g_eGameState = S_GAME;
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
                Cutscene.drawgrid(g_Console, 62, 4, 'O');
                if (g_dProtestTime > 1.2)
                {
                    Cutscene.cleargrid(g_Console, 62, 4);
                    Cutscene.drawgrid(g_Console, 63, 4, 'O');
                    if (g_dProtestTime > 1.5)
                    {
                        Cutscene.cleargrid(g_Console, 63, 4);
                        Cutscene.drawgrid(g_Console, 63, 5, 'O');
                        if (g_dProtestTime > 1.8)
                        {
                            Cutscene.cleargrid(g_Console, 63, 5);
                            Cutscene.drawgrid(g_Console, 63, 6, 'O');
                            if (g_dProtestTime > 2.1)
                            {
                                Cutscene.cleargrid(g_Console, 63, 6);
                                Cutscene.drawgrid(g_Console, 63, 7, 'O');
                                if (g_dProtestTime > 2.4)
                                {
                                    Cutscene.cleargrid(g_Console, 63, 7);
                                    Cutscene.drawgrid(g_Console, 62, 8, 'O');
                                    if (g_dProtestTime > 2.7)
                                    {
                                        Cutscene.cleargrid(g_Console, 62, 8);
                                        Cutscene.drawgrid(g_Console, 60, 8, 'O');
                                        if (g_dProtestTime > 3.0)
                                        {
                                            Cutscene.cleargrid(g_Console, 60, 8);
                                            Cutscene.drawgrid(g_Console, 57, 8, 'O');
                                            if (g_dProtestTime > 3.3)
                                            {
                                                Cutscene.cleargrid(g_Console, 57, 8);
                                                Cutscene.drawgrid(g_Console, 54, 8, 'O');
                                                if (g_dProtestTime > 3.6)
                                                {
                                                    Cutscene.cleargrid(g_Console, 54, 8);
                                                    Cutscene.drawgrid(g_Console, 51, 8, 'O');
                                                    if (g_dProtestTime > 3.9)
                                                    {
                                                        Cutscene.cleargrid(g_Console, 51, 8);
                                                        Cutscene.drawgrid(g_Console, 48, 8, 'O');
                                                        if (g_dProtestTime > 4.2)
                                                        {
                                                            Cutscene.cleargrid(g_Console, 48, 8);
                                                            Cutscene.drawgrid(g_Console, 45, 8, 'O');
                                                            if (g_dProtestTime > 4.5)
                                                            {
                                                                Cutscene.cleargrid(g_Console, 45, 8);
                                                                Cutscene.drawgrid(g_Console, 42, 8, 'O');
                                                                if (g_dProtestTime > 4.8)
                                                                {
                                                                    Cutscene.cleargrid(g_Console, 42, 8);
                                                                    Cutscene.drawgrid(g_Console, 39, 8, 'O');
                                                                    if (g_dProtestTime > 5.1)
                                                                    {
                                                                        //g_Console.writeToBuffer(c, "                                                                                                     ", 0x1A, 100);
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
                                                                                                    g_Console.writeToBuffer(c,  "Raymond: And that concludes my speech.", 0x0F, 100);
                                                                                                    if (g_dProtestTime > 53.0)
                                                                                                    {
                                                                                                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                        g_Console.writeToBuffer(c,  "Raymond: Ketchup and other condiments can be found in your fridges,", 0x0F, 100);
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
                                                                                                                        Cutscene.drawgrid(g_Console, 42, 8, 'O');
                                                                                                                        if (g_dProtestTime > 74.3)
                                                                                                                        {
                                                                                                                            Cutscene.cleargrid(g_Console, 42, 8);
                                                                                                                            Cutscene.drawgrid(g_Console, 45, 8, 'O');
                                                                                                                            if (g_dProtestTime > 74.6)
                                                                                                                            {
                                                                                                                                Cutscene.cleargrid(g_Console, 45, 8);
                                                                                                                                Cutscene.drawgrid(g_Console, 48, 8, 'O');
                                                                                                                                if (g_dProtestTime > 74.9)
                                                                                                                                {
                                                                                                                                    Cutscene.cleargrid(g_Console, 48, 8);
                                                                                                                                    Cutscene.drawgrid(g_Console, 51, 8, 'O');
                                                                                                                                    if (g_dProtestTime > 75.2)
                                                                                                                                    {
                                                                                                                                        Cutscene.cleargrid(g_Console, 51, 8);
                                                                                                                                        Cutscene.drawgrid(g_Console, 54, 8, 'O');
                                                                                                                                        if (g_dProtestTime > 75.5)
                                                                                                                                        {
                                                                                                                                            Cutscene.cleargrid(g_Console, 54, 8);
                                                                                                                                            Cutscene.drawgrid(g_Console, 57, 8, 'O');
                                                                                                                                            if (g_dProtestTime > 75.8)
                                                                                                                                            {
                                                                                                                                                Cutscene.cleargrid(g_Console, 57, 8);
                                                                                                                                                Cutscene.drawgrid(g_Console, 60, 8, 'O');
                                                                                                                                                if (g_dProtestTime > 76.1)
                                                                                                                                                {
                                                                                                                                                    Cutscene.cleargrid(g_Console, 60, 8);
                                                                                                                                                    Cutscene.drawgrid(g_Console, 62, 8, 'O');
                                                                                                                                                    if (g_dProtestTime > 76.4)
                                                                                                                                                    {
                                                                                                                                                        Cutscene.cleargrid(g_Console, 62, 8);
                                                                                                                                                        Cutscene.drawgrid(g_Console, 63, 7, 'O');
                                                                                                                                                        if (g_dProtestTime > 76.7)
                                                                                                                                                        {
                                                                                                                                                            Cutscene.cleargrid(g_Console, 63, 7);
                                                                                                                                                            Cutscene.drawgrid(g_Console, 63, 6, 'O');
                                                                                                                                                            if (g_dProtestTime > 77.0)
                                                                                                                                                            {
                                                                                                                                                                Cutscene.cleargrid(g_Console, 63, 6);
                                                                                                                                                                Cutscene.drawgrid(g_Console, 63, 5, 'O');
                                                                                                                                                                if (g_dProtestTime > 77.3)
                                                                                                                                                                {
                                                                                                                                                                    Cutscene.cleargrid(g_Console, 63, 5);
                                                                                                                                                                    Cutscene.drawgrid(g_Console, 63, 4, 'O');
                                                                                                                                                                    if (g_dProtestTime > 77.6)
                                                                                                                                                                    {
                                                                                                                                                                        Cutscene.cleargrid(g_Console, 63, 4);
                                                                                                                                                                        Cutscene.drawgrid(g_Console, 62, 4, 'O');
                                                                                                                                                                        if (g_dProtestTime > 77.9)
                                                                                                                                                                        {
                                                                                                                                                                            Cutscene.cleargrid(g_Console, 63, 4);
                                                                                                                                                                            Cutscene.drawgrid(g_Console, 62, 4, 'O');
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
    Cutscene.drawgrid(g_Console, 40, 13, 'O');
    if (g_dDungeonTime > 0.3)
    {
        //drawing Ell
        Cutscene.drawgrid(g_Console, 4, 3, 'O');
        if (g_dDungeonTime > 0.6)
        {
            g_Console.writeToBuffer(c, "Robert: ...Where am I?", 0x0F, 100);
            if (g_dDungeonTime > 3.6)
            {
                g_Console.writeToBuffer(c, "                                                                                                     ", 0x1A, 100);
                g_Console.writeToBuffer(c, "Robert: Wasn't I at the medical facility?", 0x0F, 100);
                if (g_dDungeonTime > 7.6)
                {
                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x1A, 100);
                    Cutscene.drawgrid(g_Console, 41, 12, '!');
                    if (g_dDungeonTime > 8.0)
                    {
                        g_Console.writeToBuffer(c, "Robert: ! Is that Ell?", 0x0F, 100);
                        if (g_dDungeonTime > 8.3)
                        {
                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x1A, 100);
                            Cutscene.cleargrid(g_Console, 41, 12);
                            Cutscene.cleargrid(g_Console, 4, 1);
                            Cutscene.drawgrid(g_Console, 4, 3, 'O');
                            if (g_dDungeonTime > 8.6)
                            {
                                Cutscene.cleargrid(g_Console, 4, 3);
                                Cutscene.drawgrid(g_Console, 4, 5, 'O');
                                if (g_dDungeonTime > 8.9)
                                {
                                    Cutscene.cleargrid(g_Console, 4, 5);
                                    Cutscene.drawgrid(g_Console, 6, 5, 'O');
                                    if (g_dDungeonTime > 9.2)
                                    {
                                        Cutscene.cleargrid(g_Console, 6, 5);
                                        Cutscene.drawgrid(g_Console, 9, 5, 'O');
                                        if (g_dDungeonTime > 9.5)
                                        {
                                            Cutscene.cleargrid(g_Console, 9, 5);
                                            Cutscene.drawgrid(g_Console, 12, 5, 'O');
                                            if (g_dDungeonTime > 9.8)
                                            {
                                                Cutscene.cleargrid(g_Console, 12, 5);
                                                Cutscene.drawgrid(g_Console, 15, 5, 'O');
                                                if (g_dDungeonTime > 10.1)
                                                {
                                                    Cutscene.cleargrid(g_Console, 15, 5);
                                                    Cutscene.cleargrid(g_Console, 40, 13);
                                                    Cutscene.drawgrid(g_Console, 18, 5, 'O');
                                                    Cutscene.drawgrid(g_Console, 38, 13, 'O');
                                                    if (g_dDungeonTime > 10.4)
                                                    {
                                                        Cutscene.cleargrid(g_Console, 18, 5);
                                                        Cutscene.cleargrid(g_Console, 38, 13);
                                                        Cutscene.drawgrid(g_Console, 21, 5, 'O');
                                                        Cutscene.drawgrid(g_Console, 36, 13, 'O');
                                                        if (g_dDungeonTime > 10.7)
                                                        {
                                                            Cutscene.cleargrid(g_Console, 21, 5);
                                                            Cutscene.cleargrid(g_Console, 36, 13);
                                                            Cutscene.drawgrid(g_Console, 24, 5, 'O');
                                                            Cutscene.drawgrid(g_Console, 34, 13, 'O');
                                                            if (g_dDungeonTime > 11.0)
                                                            {
                                                                Cutscene.cleargrid(g_Console, 24, 5);
                                                                Cutscene.cleargrid(g_Console, 34, 13);
                                                                Cutscene.drawgrid(g_Console, 27, 5, 'O');
                                                                Cutscene.drawgrid(g_Console, 32, 13, 'O');
                                                                if (g_dDungeonTime > 11.3)
                                                                {
                                                                    Cutscene.cleargrid(g_Console, 27, 5);
                                                                    Cutscene.cleargrid(g_Console, 32, 13);
                                                                    Cutscene.drawgrid(g_Console, 30, 5, 'O');
                                                                    Cutscene.drawgrid(g_Console, 30, 13, 'O');
                                                                    if (g_dDungeonTime > 11.6)
                                                                    {
                                                                        Cutscene.cleargrid(g_Console, 30, 5);
                                                                        Cutscene.cleargrid(g_Console, 30, 13);
                                                                        Cutscene.drawgrid(g_Console, 30, 7, 'O');
                                                                        Cutscene.drawgrid(g_Console, 30, 11, 'O');
                                                                        if (g_dDungeonTime > 11.9)
                                                                        {
                                                                            Cutscene.cleargrid(g_Console, 30, 11);
                                                                            Cutscene.drawgrid(g_Console, 30, 9, 'O');
                                                                            if (g_dDungeonTime > 12.2)
                                                                            {
                                                                                g_Console.writeToBuffer(c, "Ell: You're finally awake!!", 0x0F, 100);
                                                                                if (g_dDungeonTime > 15.2)
                                                                                {
                                                                                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x1A, 100);
                                                                                    g_Console.writeToBuffer(c, "Ell: Take this piece of paper.", 0x0F, 100);
                                                                                    g_Console.writeToBuffer(d, "     Read it and everything will become clear.", 0x0F, 100);
                                                                                    if (g_dDungeonTime > 21.2)
                                                                                    {
                                                                                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x1A, 100);
                                                                                        g_Console.writeToBuffer(d, "                                                                                                     ", 0x1A, 100);
                                                                                        g_Console.writeToBuffer(c, "Ell: I need to leave now or they'll get suspicious.", 0x0F, 100);
                                                                                        if (g_dDungeonTime > 24.2)
                                                                                        {
                                                                                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x1A, 100);
                                                                                            g_Console.writeToBuffer(c, "Ell: I'll meet you after you pass the maze.", 0x0F, 100);
                                                                                            g_Console.writeToBuffer(d, "     Make sure to sneak past the guards.", 0x0F, 100);
                                                                                            if (g_dDungeonTime > 27.2)
                                                                                            {
                                                                                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x1A, 100);
                                                                                                g_Console.writeToBuffer(d, "                                                                                                     ", 0x1A, 100);
                                                                                                g_Console.writeToBuffer(c, "Ell: I'll meet you after you pass the maze.", 0x0F, 100);
                                                                                                if (g_dDungeonTime > 30.2)
                                                                                                {
                                                                                                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                    g_Console.writeToBuffer(c, "Ell: Best of luck Robert!", 0x0F, 100);
                                                                                                    if (g_dDungeonTime > 33.2)
                                                                                                    {
                                                                                                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x00, 100);
                                                                                                        Cutscene.cleargrid(g_Console, 30, 7);
                                                                                                        Cutscene.drawgrid(g_Console, 30, 5, 'O');

                                                                                                        if (g_dDungeonTime > 33.5)
                                                                                                        {
                                                                                                            Cutscene.cleargrid(g_Console, 30, 5);
                                                                                                            Cutscene.drawgrid(g_Console, 27, 5, 'O');
                                                                                                            if (g_dDungeonTime > 33.8)
                                                                                                            {
                                                                                                                Cutscene.cleargrid(g_Console, 27, 5);
                                                                                                                Cutscene.drawgrid(g_Console, 24, 5, 'O');
                                                                                                                if (g_dDungeonTime > 34.1)
                                                                                                                {
                                                                                                                    Cutscene.cleargrid(g_Console, 24, 5);
                                                                                                                    Cutscene.drawgrid(g_Console, 21, 5, 'O');
                                                                                                                    if (g_dDungeonTime > 34.4)
                                                                                                                    {
                                                                                                                        Cutscene.cleargrid(g_Console, 21, 5);
                                                                                                                        Cutscene.drawgrid(g_Console, 18, 5, 'O');
                                                                                                                        if (g_dDungeonTime > 34.7)
                                                                                                                        {
                                                                                                                            Cutscene.cleargrid(g_Console, 18, 5);
                                                                                                                            Cutscene.drawgrid(g_Console, 15, 5, 'O');
                                                                                                                            if (g_dDungeonTime > 35.0)
                                                                                                                            {
                                                                                                                                Cutscene.cleargrid(g_Console, 15, 5);
                                                                                                                                Cutscene.drawgrid(g_Console, 12, 5, 'O');
                                                                                                                                if (g_dDungeonTime > 35.3)
                                                                                                                                {
                                                                                                                                    Cutscene.cleargrid(g_Console, 12, 5);
                                                                                                                                    Cutscene.drawgrid(g_Console, 9, 5, 'O');
                                                                                                                                    if (g_dDungeonTime > 35.6)
                                                                                                                                    {
                                                                                                                                        Cutscene.cleargrid(g_Console, 9, 5);
                                                                                                                                        Cutscene.drawgrid(g_Console, 6, 5, 'O');
                                                                                                                                        if (g_dDungeonTime > 35.9)
                                                                                                                                        {
                                                                                                                                            Cutscene.cleargrid(g_Console, 6, 5);
                                                                                                                                            Cutscene.drawgrid(g_Console, 4, 5, 'O');
                                                                                                                                            if (g_dDungeonTime > 36.2)
                                                                                                                                            {
                                                                                                                                                Cutscene.cleargrid(g_Console, 4, 5);
                                                                                                                                                Cutscene.drawgrid(g_Console, 4, 3, 'O');
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
        g_eGameState = S_GAME;
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
        //g_Console.writeToBuffer(c, "                                                                                                     ", 0x1A, 100);
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
                                            g_Console.writeToBuffer(c,  "Ell joined your party!", 0x0F, 100);
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


void splashScreenWait()    // waits for time to pass in splash screen
{
    if (g_dElapsedTime > 6.0) // wait for 3 seconds to switch to game mode, else do nothing
        g_eGameState = S_Orphanage_Animation;
}

void updateGame()       // gameplay logic
{   
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
                                g_sChar.m_cLocation.Y--;
                            }
                        }
                    }
                }
            }
        }
        /*
        if (rMap.Grid[j - 1][i] == eMap.Grid[n][m])
        {
            g_sChar.m_cLocation.X = 10;
            g_sChar.m_cLocation.Y = 20;
        }
        */
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
                                g_sChar.m_cLocation.X--;
                            }
                        }
                    }
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
                                g_sChar.m_cLocation.Y++;
                            }
                        }
                    }
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
                                g_sChar.m_cLocation.X++;
                            }
                        }
                    }
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
    case S_MENU_UI: render_Main_Menu();
         break;
    case S_SPLASHSCREEN: renderSplashScreen();
        break;
    case S_Orphanage_Animation: Orphanage_Animation();
        break;
    case S_Orphanage_Children_Animation: Orphanage_Children_Animation();
        break;
    case S_Protest_Area_Animation: Protest_Area_Animation();
        break;
    case S_GAME: renderGame();
        break;
    case S_Townsquare: renderMap_Townsquare();
        break;
    case S_Protest_Area: renderMap_Protest_Area();
        break;
    case S_Path_Area: renderMap_Path_Area();
        break;
    case S_Dungeon_Cell_Animation: Dungeon_Cell_Animation();
        break;
    case S_Path_Area_Animation: Path_Area_Animation();
        break;
    case S_IAF3_Animation: IAF3_Animation();

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
    /*
    rMap.initialise(g_Console);
    rMap.printmap(g_Console);
    rMap.orphanage(g_Console);
    
    renderCharacter();
    //Cutscene.orphanageCaretakerCutscene(g_Console);
    */
    rMap.initialise(g_Console);

    rMap.Animation(g_Console, 11, 7, 'O');                   
    rMap.Animation(g_Console, 9, 7, 'O');
    rMap.Animation(g_Console, 13, 7, 'O');
    rMap.Animation(g_Console, 11, 7, 'O');
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

    rMap.Animation(g_Console, 40, 7, 'F');
                                        
    rMap.Border(g_Console);
    
    rMap.orphanage(g_Console);
  

    //rMap.drawChildren(g_Console);

    renderCharacter();
    renderEnemy();
    //renderMap(); // renders the character into the buffer
    if (rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == '@')
    {
        g_eGameState = S_Townsquare;
        g_sChar.m_cLocation.X = 22;
        g_sChar.m_cLocation.Y = 17;
    }
    if (rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == 'F')
    {
        g_sChar.fire = true;
    }
    if (rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == rMap.Grid[g_sEnemy.e_cLocation.Y][g_sEnemy.e_cLocation.X])
    {
        g_sChar.m_cLocation.X = 20;
        g_sChar.m_cLocation.Y = 17;
    }
}

void renderMap_Townsquare()
{
    rMap.initialise(g_Console);
    rMap.Border(g_Console);
    rMap.townsquare(g_Console);
    renderCharacter();  // renders the character into the buffer
    if (rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == '@')//talkCount = 7)
    {
        g_dProtestTime = 0.0;
        g_eGameState = S_Protest_Area;
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
    if (rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == '@')//talkCount = 7)
    {
        g_dPathTime = 0.0;
        g_eGameState = S_Path_Area;
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
        charColor = 0x1A;
        rMap.Animation(g_Console, 40, 7, ' ');
        if (g_skKeyEvent[K_RETURN].keyDown && ((rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] == '_') || (rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] == '_') || (rMap.Grid[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] == '_') || (rMap.Grid[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] == '_')))
        {
            g_sChar.fireOut = true;
            g_dChildrenTime = 0.0;
            g_eGameState = S_Orphanage_Children_Animation;
            
        }
    }
    g_Console.writeToBuffer(g_sChar.m_cLocation, (char)1, charColor);
}
void renderEnemy()
{
    WORD charColor = 0x0C;
    g_Console.writeToBuffer(g_sEnemy.e_cLocation, rMap.Grid[g_sEnemy.e_cLocation.Y][g_sEnemy.e_cLocation.X] = (char)1, charColor);
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
    COORD startPos = {50, 2};
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
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'O', 0x0B);

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
    g_Console.writeToBuffer(c, rMap.Grid[c.Y][c.X] = 'O', 0x07);

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
        g_eGameState = S_Orphanage_Animation;
    }

    if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (((g_mouseEvent.mousePosition.Y == 21)) && ((g_mouseEvent.mousePosition.X == 34) || (g_mouseEvent.mousePosition.X == 35) || (g_mouseEvent.mousePosition.X == 36) || (g_mouseEvent.mousePosition.X == 37) || (g_mouseEvent.mousePosition.X == 38) || (g_mouseEvent.mousePosition.X == 39) || (g_mouseEvent.mousePosition.X == 40) || (g_mouseEvent.mousePosition.X == 41) || (g_mouseEvent.mousePosition.X == 42))))
    {
        g_bQuitGame = true;
    }
}


