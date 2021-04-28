#include "../lib/moves.h"
#include <stdio.h>
#include <unistd.h>
#include "../lib/player.h"
int play(char board[][8], bool validMoves[8][8]){
    bool finished = false;
    int move;
    int x,y;
    int player = randomisePlayer();
    int resetMove = 0;
    do{
        resetMove = 0;
//        Tells us who's turn it is to make a move
        if(player == 1) {
            printf("It is player 1's turn. (BLACK)\n");
        }
        else{
            printf("It is player 2's turn. (WHITE)\n");
        }
//        Gives us the x and the y that the player inputed
        puts("Where would you like to put your token? Format: xy\n");
        scanf("%d", &move);
        x = move / 10;
        y = move - (move /10) * 10;

//        Checks if the move is actually on the board or not.
        if(isOnBoard(x,y) == 0){
            puts("You entered an invalid spot on the board. Please try again");
            sleep(2);
            continue;
        }
//        If move is on the board then
        else{
            switch(validMove(x,y , board, validMoves)){
                case -1:
                    printf("There is already a piece on (%d,%d)",x,y);
                    resetMove = 1;
                    break;

                case 2:
                    break;

                case 3:
                    break;
            }
//            If an invalid move was made and it needs to be reset.
            if(resetMove == 1){
                continue;
            }
        }


        finished = true;

    }while(finished != true);


    return 1;

}





//Checks to see if the position of x and y is on the board.
 int isOnBoard(int x, int y){
    if((x >= 0 && x <= 7) && (y >= 0 && y <= 7)){
        return 1;
    }
    else{
        return 0;
    }
}

int validMove(int x,int y, char board[][8], bool validMoves[8][8]){
//    Checks if there is already a piece on the place therefore it isnt a valid move cause you cant stack moves.
    if(board[x][y] == 'B' || board[x][y] == 'W'){
        return -1;
    }
    else{
        int a,b,rowDirection,columnDirection,movesAmount = 0;

//        Reseting valid moves array for each game state
        for(int i = 0; i < 8; i++){
            for(int j = 0; j<8; j++){
                validMoves[i][j] = false;
            }
        }
//       Checks each spot on board if it is empty.
        for(int i = 0;i <8; i++){
            for(int j = 0; j<8; j++) {
                if (board[i][j] != ' ')
                {
                    continue;
                }
            }
        }

        for(rowDirection = -1; rowDirection <=1;rowDirection++){
            for(columnDirection = -1;columnDirection <=1; columnDirection++){

            }
        }





    }

}