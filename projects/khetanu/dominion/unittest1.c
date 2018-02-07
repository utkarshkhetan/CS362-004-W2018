#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "dominion.h"

int main()
{
    char *testFuncName = "isGameOver";
    int seed = 4;
    int numPlayers = 3;
    struct gameState state;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    initializeGame(numPlayers, k, seed, &state);

    printf("----------------TESTING FUNCTION %s----------------\n", testFuncName);

    //Test 1

    int gg = -1;
    gg = isGameOver(&state);
    printf("%d\n", gg);

    //Zero means game not over
    assert(gg == 0);

    //Test 2

    //Providence count being zero means game should end
    state.supplyCount[3] = 0;

    gg = isGameOver(&state);
    printf("%d\n", gg);

    assert(gg == 1);

    return 0;
}