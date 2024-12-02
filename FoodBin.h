#ifndef FOODBIN
#define FOODBIN

#include "GameMechs.h"


using namespace std;

class FoodBin
{
    private:
        objPos* foodList;
        int foodListCount = 0;
    public:
        FoodBin(GameMechs* thisGMRef, int foodListCount);
        ~FoodBin();
        void generateFoods(objPosArrayList* playerPosList, int playerPosListSize);
        objPos* getFood(int index);
        int getFoodListCount();
        
        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;

};

#endif