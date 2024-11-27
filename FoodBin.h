#ifndef FOODBIN
#define FOODBIN

#include "GameMechs.h"
#include "Player.h"

using namespace std;

class FoodBin
{
    private:
        objPos* foodList;
        int foodListCount = 0;
    public:
        FoodBin(GameMechs* thisGMRef, int foodListCount);
        ~FoodBin();
        void generateFoods(Player* playerRef);
        objPos* getFood(int index);
        int getFoodListCount();
        
        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;

};

#endif