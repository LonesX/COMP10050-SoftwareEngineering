//
// Created by Lones on 27/04/2021.
//

#ifndef PROJECT_2_INTERFACE_H
#define PROJECT_2_INTERFACE_H

#include <stdbool.h>

void displayBoard(char board[][8]);

void setupBoard(char board[8][8]);

void displayvalidBoard(bool validMove[][8]);

void getscore(char board[8][8]);

void gameOver(void);

void resetValidMovesBoard(bool validMoves[8][8]);

void printPlayerTurn(int player);

int consecPass(bool validMoves[8][8], int* player,char board[8][8],int* consecutivePass);

void getXY(int* x, int* y, int *move);

void printFinal(char board[8][8]);



#endif //PROJECT_2_INTERFACE_H
