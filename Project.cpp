#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *gameMech;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(gameMech->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    gameMech = new GameMechs();
}

void GetInput(void)
{
    if(MacUILib_hasChar() != 0){
        gameMech->setInput(MacUILib_getChar());
    }
    else{
        gameMech->clearInput();
    }
}

void RunLogic(void)
{

    switch(gameMech->getInput())
    {                      
        case ' ':  // exit
            gameMech->setExitTrue();
            break;
        case 'w':

            break;
        case 'a':

            break;
        case 's':

            break;
        case 'd':

            break;
        default:
            break;
    }

    

}

void DrawScreen(void)
{
    // MacUILib_printf("%c \n", gameMech->getInput());
    MacUILib_clearScreen();    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();

    delete gameMech;
}
