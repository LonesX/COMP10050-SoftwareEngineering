#include "../lib/player.h"
#include "time.h"
#include "stdlib.h"

int randomisePlayer(void) {
    srand(time(NULL));
    int player = (rand() % (2 - 1 + 1)) + 1;

    return player;
}


int swapPlayer(int currentPlayer) {
    if (currentPlayer == 1) {
        return 2;
    } else {
        return 1;
    }
}


void playerFind(int player, int *playerC, int *opponent) {
    if (player == 1) {
        *opponent = 'W';
        *playerC = 'B';
    } else {
        *opponent = 'B';
        *playerC = 'W';
    }
}