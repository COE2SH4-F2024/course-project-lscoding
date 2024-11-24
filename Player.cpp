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
    char input = mainGameMechsRef->getInput();
    switch(input)
    {
        case 'W':
        case 'w':
            myDir = UP;
        
            break;

        case 'S':
        case 's':
            myDir = DOWN;
        
            break;

        case 'A':
        case 'a':
                myDir = LEFT;
            
        break;

        case 'D':
        case 'd':
                myDir = RIGHT;
            
        break;

        default:
            break;
    }

    // PPA3 Finite State Machine logic
}

// More methods to be added