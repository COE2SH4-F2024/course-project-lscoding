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
    if(gameMech->getInput() == ' '){
        gameMech->setExitTrue();
    }
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
}

void DrawScreen(void)
{


    objPos playerObjPos = myPlayer->getPlayerPos();
    
    Pos* playerPos = playerObjPos.pos;
    char playerSymbol = myPlayer->getPlayerPos().getSymbol();
    
    int boardWidth = gameMech->getBoardSizeX();
    int boardHeight = gameMech->getBoardSizeY();

    // MacUILib_printf("%c \n", gameMech->getInput());
    MacUILib_clearScreen();
    for(int row = 0; row < boardHeight; row++){
        MacUILib_printf("\n");
        for(int col = 0; col < boardWidth; col++){
            if(row == 0 || row == boardHeight-1 ||
                col == 0 || col == boardWidth-1){
                    MacUILib_printf("%c", '#');
            }
            else if(playerPos->y == row && playerPos->x == col){
                MacUILib_printf("%c", playerSymbol);
            }
            else{
                char characterDisp = ' ';
                // for(int i = 0; i < 5; i++) //go through collection List and place all collectables
                // {
                //     if(collectableList[i].x == col && collectableList[i].y == row){
                //         characterDisp = collectableList[i].symbol;
                //         break;
                //     }
                // }
      
                 MacUILib_printf("%c", characterDisp);
       
            }
        }
    }
    // MacUILib_printf("\nPress '=' to Increase Game Speed!\n");
    // MacUILib_printf("Press '-' to Decrease Game Speed!\n");
    // MacUILib_printf("Game Level set to %d (%f seconds per frame).\n", gameSpeedState+1, (double)gameSpeeds[gameSpeedState]/1000000);
    // MacUILib_printf("Player [x, y, sym] = [%d, %d, %c]\n", playerPos.pos->x, playerPos.pos->y, playerPos.symbol);
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
