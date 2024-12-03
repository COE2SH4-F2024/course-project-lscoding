#include "FoodBin.h"
FoodBin::FoodBin(GameMechs* thisGMRef, int foodListCount){
    mainGameMechsRef = thisGMRef;
    this->foodListCount = foodListCount;
    foodList = new objPos[foodListCount];
}

FoodBin::~FoodBin(){
    delete[] foodList;
}
objPos* FoodBin::getFood(int index){
    return &foodList[index];
}
void FoodBin::generateFoods(objPosArrayList* playerPosList, int playerPosListSize)
{
    // This is possibly one of the most conceptually challenging function in all PPAs
    // Once you've mastered this one, you are ready to take on the 2SH4 course project!

    // Random Non-Repeating Item Generation Algorithm
    ////////////////////////////////////////////////////

    char selectableChar[2] = {'F', 'G'};
    int count = 0;

    int xRange = mainGameMechsRef->getBoardSizeX();
    int yRange = mainGameMechsRef->getBoardSizeY();

    int numOfSpecialFood = 0;

    while(count != foodListCount){
        

        int newX = rand() % xRange;       
        int newY =  rand() % yRange;

        for(int i = 0; i < playerPosListSize; i++){
            //Checks if in range of board
            if(newX == 0 
                || newX == xRange-1 
                || (newX == playerPosList->getElement(i).pos->x
                && newY == playerPosList->getElement(i).pos->y)
                || newY == 0
                || newY == yRange-1)
            {
                continue;
            }
        }

            int charIndex = rand() % 2;

            charIndex = charIndex - (numOfSpecialFood==2 && charIndex == 1);
            
            numOfSpecialFood += charIndex;

            objPos newObj = objPos(newX, newY, selectableChar[charIndex]);
            foodList[count] = newObj;
            count += 1;
            
            
            
    



    }
}

int FoodBin::getFoodListCount(){
    return foodListCount;
}
//Remember, best practice is to make copy constructor and assignment constructor
