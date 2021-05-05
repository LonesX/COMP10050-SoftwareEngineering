//
// Created by Lones on 27/04/2021.
//

#ifndef PROJECT_2_MOVES_H
#define PROJECT_2_MOVES_H

#include <stdbool.h>

int play(char board[][8], bool validMoves[8][8]);

int isOnBoard(int x, int y);

int validMove(int x, int y, char board[][8], bool validMoves[][8], int player);

void make_move(char board[][8], int x, int y, int player);

void
rowCheck(int x, int y, char board[8][8], bool validMoves[8][8], int rowDirection, int columnDirection, int *movesAmount,
         int playerC, int opponent, int type);

#endif //PROJECT_2_MOVES_H

//54 35 24 53 42 55 64 45 46