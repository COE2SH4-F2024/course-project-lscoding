#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"

#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

Player *myPlayer; //global pointer to instantiate a player object on heap
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

    myPlayer = new Player(gameMech); //replace later


    


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

    objPos playerPos = myPlayer ->getPlayerPos();

    // MacUILib_printf("%c \n", gameMech->getInput());
    MacUILib_clearScreen();
    MacUILib_printf("Player [x, y, sym] = [%d, %d, %c]\n", playerPos.pos->x, playerPos.pos->y, playerPos.symbol);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();

    delete myPlayer; // delete my player object pointer

    delete gameMech; //delete gamemech object pointer
}
