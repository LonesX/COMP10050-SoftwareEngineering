#include "../lib/moves.h"
#include <stdio.h>
#include "../lib/player.h"
#include "../lib/interface.h"

int play(char board[][8], bool validMoves[8][8]) {
    bool finished = false;          //used for keeping the game running until finished == true
    int x, y, move, moveAmount;
    int player = randomisePlayer();
    int consecutivePass = 0;
    displayBoard(board);

    //This do while loop is the main part that allows the game to keep going.
    // It breaks out of this loop when finished == true.

    do {
//        Tells us who's turn it is to make a move
        printPlayerTurn(player);

//      Checks if there are valid moves if not add to consecutivePass
        switch(consecPass(validMoves,&player,board,&consecutivePass)) {
            case 2:                 //if there are two passes in a row then the game is finished.
                finished = true;
                continue;
            case 0:                //if there was no need for a pass.
                break;

            case 1:                //this does the first pass.
                continue;
        }

//        Gives us the x and the y that the player inputed
        getXY(&x,&y,&move);
//        Checks if the move is actually on the board or not.
        if (isOnBoard(x, y) == 0) {
            puts("You entered an invalid spot on the board. Please try again");
            continue;
        }
//        If move is on the board then
        else {
//            Checks how many valid moves there are on the board in the current state for the player
            moveAmount = validMove(x, y, board, validMoves, player);
//            If the move they chose is not a valid move
            if (validMoves[x][y] == false) {
                printf("(%d,%d is an invalid move.Try again)\n", x, y);
                continue;

            }
//            If there is already a piece on the board at that location
            if (moveAmount == -1) {
                printf("There is already a piece on (%d,%d)\n", x, y);
                continue;
            }

            make_move(board, x, y, player);  //This actually does the move and flips over enemy pieces.
            consecutivePass = 0;             //Resets pass counter.
            getscore(board);        //Gets the new score of each player which is stored in player1.score/player2.score.
            player = swapPlayer(player);    //This swaps the player.
            displayBoard(board);            //This displays the new game state board.
        }
    } while (finished != true); //The do_while loop guard.
    return 0;
}

//Checks to see if the position of x and y is on the board.
int isOnBoard(int x, int y) {
    if ((x >= 0 && x <= 7) && (y >= 0 && y <= 7)) {
        return 1;
    } else {
        return 0;
    }
}

/* Places a true on every spot that is a valid board on the auxiliary validmoves[][] board */
int validMove(int x, int y, char board[8][8], bool validMoves[8][8], int player) {
/* Checks if there is already a piece on the place therefore it isn't a valid move cause you cant stack moves. */
    if (board[x][y] == 'B' || board[x][y] == 'W') {
        return -1;
    }
/*Else check for every valid move on the board.*/
    else {
        int rowDirection, columnDirection;
        int movesAmount = 0;
        int opponent, playerC;

/*Finds which player is currently playing and their colour*/
        playerFind(player, &playerC, &opponent);

/* Resetting valid moves array for each game state */
        resetValidMovesBoard(validMoves);
//       Checks each spot on board
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] != ' ') {
                    continue;
                }
/*
                    (rowDir=0,colDir--)
(rowDir--&&colDir--)         ^             (rowDir++ && colDir--)
              <              ^              >
                  <          ^          >
                    <        ^        >
                      <      ^      >
      (rowDir--;)       <    ^    >               (rowdir++;)
     < < < < < < < < < < < < 0 > > > > > > > > > >>
                          <  v  >
                       <     v     >
                    <        v         >
                 <           v            >
              <              v               >
 (row--&&col++)              v                 (rowDir++&&colDir++)
                     (rowDir=0,colDir--)
*/
//  This just goes through each direction on each square for a enemy square so that it becomes valid,
//  I did this by using a mathematical coordinate type system.
                for (rowDirection = -1; rowDirection <= 1; rowDirection++) {
                    for (columnDirection = -1; columnDirection <= 1; columnDirection++) {

//                        Checks if the spot is outside of the board.
                        if (i + rowDirection < 0 || i + rowDirection >= 8 || j + columnDirection < 0 ||
                            j + columnDirection >= 8 || (rowDirection == 0 && columnDirection == 0)) {
                            continue;
                        } else {
                            {
//                                If an enemy piece was found
                                if (board[i + rowDirection][j + columnDirection] == opponent) {
                                    rowCheck(i, j, board, validMoves, rowDirection, columnDirection, &movesAmount,
                                             playerC, opponent, 0);
                                    // Runs to check every opponent piece on that direction
                                }
                            }
                        }
                    }
                }
            }
        }
        return movesAmount;
    }
}

//This actually makes the move and also flips the enemy pieces in its way
void make_move(char board[8][8], int x, int y, int player) {
    int rowDirection, columnDirection;
    int opponent, playerC;

    playerFind(player, &playerC, &opponent);
    board[x][y] = playerC;


    //  This just goes through each direction on each square for a enemy square so that it becomes valid.
    //  I did this by using a mathematical coordinate type system. SAME AS DIAGRAM ABOVE.
    for (rowDirection = -1; rowDirection <= 1; rowDirection++) {
        for (columnDirection = -1; columnDirection <= 1; columnDirection++) {

            //Checks if the spot is outside of the board.

            if (x + rowDirection < 0 || x + rowDirection >= 8 || y + columnDirection < 0 || y + columnDirection >= 8 ||
                (rowDirection == 0 && columnDirection == 0)) {
                continue;
            } else {
                // If an enemy piece was found

                if (board[x + rowDirection][y + columnDirection] == opponent) {
                    // Runs to check every opponent piece on that direction
                    rowCheck(x, y, board, 0, rowDirection, columnDirection, 0, playerC, opponent, 1);
                }
            }
        }
    }
}

