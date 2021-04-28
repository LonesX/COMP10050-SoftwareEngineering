//
// Created by Lones on 28/04/2021.
//

#include "../lib/player.h"
#include "time.h"
#include "stdlib.h"

int randomisePlayer(void){
    srand(time(NULL));
    int player = (rand() % (2-1+1))  +  1;

    return player;
}


int swapPlayer(int currentPlayer){
    if(currentPlayer == 1){
        currentPlayer = 2;
    }else
    {
        currentPlayer = 1;
    }
    return currentPlayer;
}
