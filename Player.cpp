#include "Player.h"



Player::Player(GameMechs* thisGMRef)
{

    
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(objPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'@'));
}


Player::~Player()
{
    delete playerPosList;
}

//Returns playerPositions
objPosArrayList* Player::getPlayerPos() const
{
    return playerPosList;
}

//Updates the current direction snake travels
void Player::updatePlayerDir()
{
        // PPA3 input processing logic 
    char input = mainGameMechsRef -> getInput();
    switch(input)
    {
        case 'W':
        case 'w':

            if(myDir != UP && myDir != DOWN)
            {
                myDir = UP;
            }
            break;

        case 'S':
        case 's':
            if(myDir != UP && myDir != DOWN)
            {
                myDir = DOWN;
            }
        break;

        case 'A':
        case 'a':
            if(myDir != LEFT && myDir != RIGHT)
            {
                myDir = LEFT;
            }
        break;

        case 'D':
        case 'd':
            if(myDir != LEFT && myDir != RIGHT)
            {
                myDir = RIGHT;
            }
        break;

        default:
            break;
    }         
}

//Moves the snake
void Player::movePlayer(FoodBin* foodBin)
{
    objPos newHead = playerPosList->getHeadElement();
    Pos newHeadPos = *newHead.pos; //clones position
    switch(myDir)
    {
        case UP:
            newHeadPos.y-=1;
            break;

        case DOWN:
            newHeadPos.y+=1;
            break;

        case LEFT:
            newHeadPos.x-=1;
            break;

        case RIGHT:
            newHeadPos.x+=1;

            break;
        
        default:
            break;
    }

    //Wrap around code
    if(newHeadPos.y >= mainGameMechsRef->getBoardSizeY()-1){
        newHeadPos.y = 1;
    }
    else if(newHeadPos.y <= 0){
        newHeadPos.y = mainGameMechsRef->getBoardSizeY()-2;
    }

    if(newHeadPos.x >= mainGameMechsRef->getBoardSizeX()-1){
        newHeadPos.x = 1;
    }
    else if(newHeadPos.x <= 0){
        newHeadPos.x = mainGameMechsRef->getBoardSizeX()-2;
    }

    //Sets new head position
    newHead.setObjPos(newHeadPos.x,newHeadPos.y, newHead.symbol);
    
    //Handles collisons
    if(checkSelfCollision()){
        
        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();
        return;

    }
    switch(checkFoodConsumption(foodBin)){
        case 'F':
            playerPosList->insertHead(newHead);
            mainGameMechsRef->addScore(1);
            foodBin->generateFoods(playerPosList, playerPosList->getSize());
            break;
        case 'G':
            mainGameMechsRef->addScore(10);
            foodBin->generateFoods(playerPosList, playerPosList->getSize());
        default:
            playerPosList->insertHead(newHead);
            playerPosList->removeTail();
            break;
    }
}

//Checks if player collided with food
char Player::checkFoodConsumption(FoodBin* foodBin){
    objPosArrayList* playerPosList = getPlayerPos();
    objPos playerHeadObjPos = playerPosList->getHeadElement();
    int playerPosListSize = playerPosList->getSize();
    Pos* playerPos = playerHeadObjPos.pos;
    
    for(int i = 0; i < foodBin->getFoodListCount(); i++){
        objPos* foodPos = foodBin->getFood(i);
        if(playerPos->x != foodPos->pos->x || playerPos->y != foodPos->pos->y){
            continue;
        }
        switch(foodPos->getSymbol()){
            case 'F':
                return 'F';
                break;
            case 'G':
                return 'G';
                break;
        }
    }

    return 0;
}

//Checks if player collided with self
bool Player::checkSelfCollision(){
    objPosArrayList* playerPosList = getPlayerPos();
    objPos playerHeadObjPos = playerPosList->getHeadElement();
    int playerPosListSize = playerPosList->getSize();
    Pos* playerPos = playerHeadObjPos.pos;
    
    for(int i = 1; i < playerPosListSize; i++){
        if(playerPos->x != playerPosList->getElement(i).pos->x || playerPos->y != playerPosList->getElement(i).pos->y){
            continue;
        }
        return true; 
    }

    return false;
}