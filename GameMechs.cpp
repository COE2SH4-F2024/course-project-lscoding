#include "GameMechs.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;

    score = 0;
    
    exitFlag = false;
    loseFlag = false;  
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;

    score = 0;
    
    exitFlag = false;
    loseFlag = false;

    //Might need to Generate food position here
}

// do you need a destructor?
GameMechs::~GameMechs() //Might be removable since there is no HEAP memory to deallocate
{
    
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::addScore(int num)
{
    score += num;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = 1;
}

void GameMechs::setLoseFlag()
{
    loseFlag = 1;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;   
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here