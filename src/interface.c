#include "../lib/interface.h"
#include "../lib/main.h"
#include "../lib/moves.h"
#include "../lib/player.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// This function displays the board
void displayBoard(char board[][8]) {
//    These are the horizontal and vertical lines for each row that I chose
    char horizontal[] = "  +---+---+---+---+---+---+---+---+";
// Prints the current state of the game
    printf("  %s %s (%c) %d:%d %s (%c)\n", "Score:", player1.name, player1.colour, player1.score, player2.score,
           player2.name, player2.colour);
    printf("Y +---+---+---+---+---+---+---+---+\n");
//    This prints every row and every spot on each row
    for (int i = 0; i < 8; i++) {
        printf("%d ", i);
        for (int k = 0; k < 8; k++) {
            printf("%s%c%s", "| ", board[k][i], " ");
        }
//        To end the new row
        puts("|");
        puts(horizontal);
    }
    puts("X   0   1   2   3   4   5   6   7");


}

void displayvalidBoard(bool validMove[][8]) {
//    These are the horizontal and vertical lines for each row that I chose
    char horizontal[] = "  +---+---+---+---+---+---+---+---+";
// Prints the current state of the game
    printf("Y +---+---+---+---+---+---+---+---+\n");
//    This prints every row and every spot on each row
    for (int i = 0; i < 8; i++) {
        printf("%d ", i);
        for (int k = 0; k < 8; k++) {
            printf("%s%d%s", "| ", validMove[k][i], " ");
        }
//        To end the new row
        puts("|");
        puts(horizontal);
    }
    puts("X   0   1   2   3   4   5   6   7");

}


void setupBoard(char board[8][8]) {
//    Basic setting up
    puts("*** Welcome to Othello! ***");
    player1.colour = 'B';
    player2.colour = 'W';
    puts("Enter name of Player 1 (Black):");
    gets(player1.name);
    puts("Enter name of Player 2 (White):");
    gets(player2.name);
// Initialises the starting score.
    player1.score = 2;
    player2.score = 2;
//   setup each row
    for (int i = 0; i < 8; i++) {
//   setup each column
        for (int k = 0; k < 8; k++) {
            board[i][k] = ' ';
        }
    }
//    The starting board pieces placed
    strcpy(&board[4][3], "B");
    strcpy(&board[3][3], "W");
    strcpy(&board[3][4], "B");
    strcpy(&board[4][4], "W");

//    This was done to fix a unusual bug with the program.
    for (int i = 0; i < 8; i++) {
        board[i][5] = ' ';
    }
}

void getscore(char board[8][8]) {
    int black = 0, white = 0;
//Goes through every spot on the board and checks who it belongs to then adds the score.
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch (board[i][j]) {
                case 'B':
                    black++;
                    break;

                case 'W':
                    white++;
                    break;


                default:
                    continue;
            }
        }
    }
    player1.score = black;
    player2.score = white;
}


void gameOver(void) {
    puts("\n\nAS THERE ARE NO MORE MOVES, THE GAME HAS ENDED");
    printf("\n\n  %s %s (%c) %d:%d %s (%c)\n", "FINAL SCORE:", player1.name, player1.colour, player1.score, player2.score,
           player2.name, player2.colour);
}


void resetValidMovesBoard(bool validMoves[8][8]) {
//  fully clears the valid moves board.
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            validMoves[i][j] = false;
        }
    }

}


void printPlayerTurn(int player){
    if (player == 1) {
        printf("It is player 1's turn. (BLACK)\n");
    } else {
        printf("It is player 2's turn. (WHITE)\n");
    }
}

int consecPass(bool validMoves[8][8], int* player,char board[8][8],int* consecutivePass){
//    This function counts how many passes in a row happened and it will keep checking if two happen in a row then
//    it will end the game.
    if (validMove(-1, -1, board, validMoves, *player) == 0) {
        printf("There is no more valid moves for player %d.\nYour turn is being passed.\n ", *player);
        consecutivePass++;
        if (*consecutivePass == 2) {
            return 2;
        }
        int temp = swapPlayer(*player);
        *player = temp;
        return 0;
    }
    return 1;
}

void getXY(int* x, int* y, int *move){
//    Gets the xy
    puts("Where would you like to put your token? Format: xy\n");
    scanf("%d", move);
    *x = *move / 10;
    *y = *move - (*move / 10) * 10;
}

void printFinal(char board[8][8]) {
    FILE *fp;
    char horizontal[] = "  +---+---+---+---+---+---+---+---+";

    time_t current_time; //keeps the time
    char *c_time_string; // keeps the time in string format
    current_time = time(NULL);
    c_time_string = ctime(&current_time);

// This prints the board to the file the same way as the displayBoard function.
    fp = fopen("../othello-results.txt", "a+");
    if (fp == NULL) {
        puts("Couldn't open a file");
    }
    fputs("FINAL BOARD:\n",fp);
    fprintf(fp, "%s", "Y +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < 8; i++) {
        fprintf(fp, "%d ", i);
        for (int k = 0; k < 8; k++) {
            fprintf(fp, "%s%c%s", "| ", board[k][i], " ");
        }
//        To end the new row
        fputs("|\n", fp);
        fprintf(fp, "%s\n", horizontal);
    }

    fputs("X   0   1   2   3   4   5   6   7\n\n", fp);

//print final score
    fprintf(fp,"  %s %s (%c) %d:%d %s (%c)\n", "FINAL SCORE:", player1.name, player1.colour, player1.score, player2.score,
           player2.name, player2.colour);
// print the final time.
    fprintf(fp, "Current time is %s\n\n", c_time_string);


}
