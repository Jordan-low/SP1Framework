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
double  g_dDeltaTime;
SKeyEvent g_skKeyEvent[K_COUNT];
SMouseEvent g_mouseEvent;

// Game specific variables here
SGameChar   g_sChar;
SGameChar   g_sEnemy;
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
    g_sChar.fire = false;
    g_sChar.fireOut = false;
    // Set precision for floating point output
    g_dElapsedTime = 0.0;    

    // sets the initial state for the game
    g_eGameState = S_GAME;

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

    switch (g_eGameState)
    {
        case S_SPLASHSCREEN : splashScreenWait(); // game logic for the splash screen
            break;
        case S_Orphanage_Animation: Update_Orphanage_Animation();
            break;
        case S_GAME: updateGame(); // gameplay logic when we are in the game
            break;
        case S_Townsquare: updateGame(); // gameplay logic when we are in the game
            break;
        case S_Protest_Area: updateGame(); // gameplay logic when we are in the game
            break;
        case S_Path_Area: updateGame(); // gameplay logic when we are in the game
            break;
    }
}

void Update_Orphanage_Animation()
{
    if (g_dElapsedTime > 36)
    {
        g_eGameState = S_GAME;
    }
    processUserInput();
}

void Animation_Input()
{
    
}

void Orphanage_Animation()
{
    rMap.initialise(g_Console);
    rMap.printmap(g_Console);
    rMap.orphanage(g_Console);
    COORD c;
    renderCharacter();
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
                                                c.X = 5;
                                                c.Y = 26;
                                                g_Console.writeToBuffer(c, "Robert: ...", 0x1A, 10);
                                                if (g_dElapsedTime > 10)
                                                {
                                                    c.X = 5;
                                                    c.Y = 26;
                                                    g_Console.writeToBuffer(c, "                                                                                                     ", 0x1A, 100);
                                                    c.X = 5;
                                                    c.Y = 26;
                                                    g_Console.writeToBuffer(c, "Caretaker: Robert... Leave the Orphanage now!..", 0x1A, 100);
                                                    if (g_dElapsedTime > 16)
                                                    {
                                                        c.X = 5;
                                                        c.Y = 26;
                                                        g_Console.writeToBuffer(c, "                                                                                                     ", 0x1A, 100);
                                                        c.X = 5;
                                                        c.Y = 26;
                                                        g_Console.writeToBuffer(c, "It's better that at least one of us comes out alive..", 0x1A, 100);
                                                        if (g_dElapsedTime > 24)
                                                        {
                                                            c.X = 5;
                                                            c.Y = 26;
                                                            g_Console.writeToBuffer(c, "                                                                                                     ", 0x1A, 100);
                                                            c.X = 5;
                                                            c.Y = 26;
                                                            g_Console.writeToBuffer(c, "Take the backpack and leave... Don't look back Robert..", 0x1A, 100);
                                                            if (g_dElapsedTime > 30)
                                                            {
                                                                c.X = 5;
                                                                c.Y = 26;
                                                                g_Console.writeToBuffer(c, "                                                                                                     ", 0x1A, 100);
                                                                c.X = 5;
                                                                c.Y = 26;
                                                                g_Console.writeToBuffer(c, "Objective: Take the backpack before leaving the burning house!", 0x1A, 100);
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                        }
                                    }
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
    clearScreen();      // clears the current screen and draw from scratch 
    switch (g_eGameState)
    {
    case S_SPLASHSCREEN: renderSplashScreen();
        break;
    case S_Orphanage_Animation: Orphanage_Animation();
        break;
    case S_GAME: renderGame();
        break;
    case S_Townsquare: renderMap_Townsquare();
        break;
    case S_Protest_Area: renderMap_Protest_Area();
        break;
    case S_Path_Area: renderMap_Path_Area();
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
    COORD c;
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

    if (g_sChar.fireOut == false)
    {
        rMap.orphanage(g_Console);
    }

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
    WORD charColor = 0x0C;
    if (g_sChar.m_bActive)
    {
        charColor = 0x0A;
    }
    if (g_sChar.fire)
    {
        charColor = 0xDD;
        rMap.Animation(g_Console, 40, 7, ' ');
        if (g_skKeyEvent[K_RETURN].keyDown && ((rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] == '_') || (rMap.Grid[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] == '_') || (rMap.Grid[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] == '_') || (rMap.Grid[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] == '_')))
        {
            g_sChar.fireOut = true;
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



