#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{

    
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    // playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;
    // playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2;
    // playerPos.symbol = '@';
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(objPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'@'));
}


Player::~Player()
{
    delete playerPosList;
    // delete any heap members here
    //leave destructor empty FOR NOW
}

objPosArrayList* Player::getPlayerPos() const
{
    return playerPosList;
    // return the reference to the playerPos arrray list
}

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

void Player::movePlayer()
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

    newHead.setObjPos(newHeadPos.x,newHeadPos.y, newHead.symbol);
    playerPosList->insertHead(newHead);
    playerPosList->removeTail();
    // PPA3 Finite State Machine logic
}

// More methods to be added