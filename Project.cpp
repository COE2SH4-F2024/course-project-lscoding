#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"

#include "Player.h"
#include "FoodBin.h"

using namespace std;

#define DELAY_CONST 100000

Player *myPlayer; //global pointer to instantiate a player object on heap
GameMechs *gameMech;
FoodBin *foodBin;

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

    foodBin = new FoodBin(gameMech, 5); //2 food collectables should appear at a time

    srand(time(NULL));
    
    objPosArrayList* playerPosList = myPlayer->getPlayerPos();
    foodBin->generateFoods(playerPosList, playerPosList->getSize());
    


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
    if(gameMech->getLoseFlagStatus() == 1)
    {
        gameMech->setExitTrue();
    }

    myPlayer->updatePlayerDir();
    myPlayer->movePlayer(foodBin);
    
    // // Check if collision with food
    //Made the game end when you reach max snake length
    // if(playerPosList->getSize() >= (gameMech->getBoardSizeX()-2)*(gameMech->getBoardSizeY()))
    // {
    //     MacUILib_printf("YOU WIN THE GAME!!!");
    //     gameMech->setExitTrue();
    // } 
}

void DrawScreen(void)
{

    
    objPosArrayList* playerObjPosList = myPlayer->getPlayerPos();
    

    
    
    int boardWidth = gameMech->getBoardSizeX();
    int boardHeight = gameMech->getBoardSizeY();

    MacUILib_clearScreen();
    for(int row = 0; row < boardHeight; row++){
        MacUILib_printf("\n");
        for(int col = 0; col < boardWidth; col++){
            if(row == 0 || row == boardHeight-1 ||
                col == 0 || col == boardWidth-1){
                    MacUILib_printf("%c", '#');
            }
            else{
                char characterDisp = ' ';
                bool characterFound = false;
                for(int i = 0; i < playerObjPosList->getSize(); i++) //go through collection List and place all collectables
                {
                    objPos playerBody = playerObjPosList->getElement(i);
                    if(playerBody.pos->x == col && playerBody.pos->y == row){
                        characterDisp = playerBody.symbol;
                        characterFound = true;
                        break;
                    }
                }
                if(characterFound == false){
                    for(int i = 0; i < foodBin->getFoodListCount(); i++) //go through collection List and place all collectables
                    {
                        objPos* food = foodBin->getFood(i);
                        if(food->pos->x == col && food->pos->y == row){
                            characterDisp = food->symbol;
                            break;
                        }
                    }   
                }
      
                MacUILib_printf("%c", characterDisp);
       
            }
        }
    }
    
    MacUILib_printf("\nCurrent Score: %d\n", gameMech->getScore());
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    if(gameMech->getLoseFlagStatus() == true){
        MacUILib_printf("\nYou Lose!\nYour score is: %d\n", gameMech->getScore());
    }
    MacUILib_printf("Exiting game...\n");
    MacUILib_uninit();

    delete myPlayer; // delete my player object pointer
    myPlayer = nullptr;

    delete gameMech; //delete gamemech object pointer
    gameMech = nullptr;

    delete foodBin; //delete foodBin object pointer
    foodBin = nullptr;
    
}
