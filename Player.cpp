#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{

    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2;
    playerPos.symbol = '@';
}


Player::~Player()
{
    
    // delete any heap members here
    //leave destructor empty FOR NOW
}

objPos Player::getPlayerPos() const
{
    return playerPos;
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

    switch(myDir)
    {
        case UP:
            playerPos.pos->y-=1;
            break;

        case DOWN:
            playerPos.pos->y+=1;
            break;

        case LEFT:
            playerPos.pos->x-=1;
            break;

        case RIGHT:
            playerPos.pos->x+=1;

            break;
        
        default:
            break;

    }

    //Wrap around code
    if(playerPos.pos->y >= mainGameMechsRef->getBoardSizeY()-1){
        playerPos.pos->y = 1;
    }
    else if(playerPos.pos->y <= 0){
        playerPos.pos->y = mainGameMechsRef->getBoardSizeY()-2;
    }

    if(playerPos.pos->x >= mainGameMechsRef->getBoardSizeX()-1){
        playerPos.pos->x = 1;
    }
    else if(playerPos.pos->x <= 0){
        playerPos.pos->x = mainGameMechsRef->getBoardSizeX()-2;
    }


    // PPA3 Finite State Machine logic
}

// More methods to be added