//
// Created by Lones on 27/04/2021.
//

#ifndef PROJECT_2_MOVES_H
#define PROJECT_2_MOVES_H
#include <stdbool.h>
int play(char board[][8], bool validMoves[8][8]);
int isOnBoard(int x, int y);
int validMove(int x,int y, char board[][8],bool validMoves[][8]);

#endif //PROJECT_2_MOVES_H
