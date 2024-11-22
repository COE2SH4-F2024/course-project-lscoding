#include "objPos.h"

objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule

//Destructor
objPos::~objPos() {
    delete pos;
    pos = nullptr;
}

//Copy Constructor
objPos::objPos(const objPos& clone){
    pos = new Pos;
    pos->x = clone.pos->x;
    pos->y = clone.pos->y;
    symbol = clone.symbol;
	// rowsNum = clone.rowsNum;
	// colsNum = clone.colsNum;
    
	// matrixData = new int*[rowsNum];
    
	// for (int i = 0; i < rowsNum; ++i) {
    //     matrixData[i] = new int[colsNum];
    // }
    // for (int i = 0; i < rowsNum; ++i) {
    //     for (int j = 0; j < colsNum; ++j) {
    //         setElement(clone.matrixData[i][j],i,j);
    //     }
    // }
}

//Copy Assignment Constructor
objPos& objPos::operator=(const objPos& clone){
	if(this == &clone){
		return *this;
	}
    
    delete pos;
    
    pos = new Pos;
    pos->x = clone.pos->x;
    pos->y = clone.pos->y;
    
    symbol = clone.symbol;

	return *this;
}


void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
