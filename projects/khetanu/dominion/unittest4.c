#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "dominion.h"

int main()
{
    char *testFuncName = "fullDeckCount";
    int seed = 4;
    int numPlayers = 3;
    struct gameState state;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    initializeGame(numPlayers, k, seed, &state);

    printf("----------------TESTING FUNCTION %s----------------\n", testFuncName);

    //Test 1
    int testPlayer = 0;
    int card = copper; 
    int deckCount = fullDeckCount(testPlayer, card, &state);
    printf("deck count: %d\n", deckCount);
    assert(deckCount == 7); //Player should begin with 7 copper cards
    
    //Test 2
    testPlayer = 0;
    card = silver; 
    deckCount = fullDeckCount(testPlayer, card, &state);
    printf("deck count: %d\n", deckCount);
    assert(deckCount == 0); //Player should begin with 0 silver cards

    //Test 3
    testPlayer = 0;
    card = curse; 
    deckCount = fullDeckCount(testPlayer, card, &state);
    printf("deck count: %d\n", deckCount);
    assert(deckCount == 0); //Player should begin with 0 curse cards
    


    return 0;
}