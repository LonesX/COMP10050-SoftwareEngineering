#include "../lib/interface.h"
#include "../lib/main.h"
#include "../lib/player.h"
#include <stdio.h>
#include <string.h>

void displayBoard(char board[][8]) {
//    These are the horizontal and vertical lines for each row that I chose
    char horizontal[] = "  +---+---+---+---+---+---+---+---+";
// Prints the current state of the game
    printf("  %s %s (%c) %d:%d %s (%c)\n","Score:" ,player1.name, player1.colour,player1.score,player2.score,player2.name,player2.colour);
    printf("Y +---+---+---+---+---+---+---+---+\n");
//    This prints every row and every spot on each row
    for(int i = 0; i < 8; i++){
        printf("%d ",i);
        for(int k = 0; k<8;k++){
            printf("%s%c%s", "| " ,board[k][i]," ");
        }
//        To end the new row
        puts("|");
        puts(horizontal);
    }
    puts("X   0   1   2   3   4   5   6   7");


}


void setupBoard(char board[8][8]){
    puts("*** Welcome to Othello! ***");
    player1.colour = 'B';
    player2.colour = 'W';
    puts("Enter name of Player 1 (Black):");
    gets(player1.name);
    puts("Enter name of Player 2 (White):");
    gets(player2.name);

    player1.score = 2;
    player2.score = 2;
//   setup each row
    for(int i = 0; i<8;i++){
//   setup each column
        for(int k = 0;k<8;k++){
            strcpy(&board[i][k], " ");
        }
    }
    strcpy(&board[3][3], "B");
    strcpy(&board[4][3], "W");
    strcpy(&board[4][4], "B");
    strcpy(&board[3][4], "W");


}