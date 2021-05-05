/* Lones Xheladini (20331731)
 * This is my implementation of the game othello/reversi as part of my COMP10050 module
 * It uses a number of functions together for the game to work.
 * The main game logic is done inside the moves.c file.
 * The main interface is done in interface.c
 * The player handling is done with the othelloPlayer struct in main.h and player.c functions. */

#include "../lib/interface.h"
#include "../lib/moves.h"
#include <stdbool.h>

int main(void) {
    char board[8][8];                              // The play board.
    bool validMoves[8][8] = {false};               // Clears the validmoves board.
    setupBoard(board);                             // Clears and sets up the board for play.
    play(board, validMoves);                       // The main function for the running and maintaining of game.
    gameOver();                                    // Displays the final results in console and that game is over.
    printFinal(board);                             // Writes the result to file (../"othello-results.txt").
    return 0;
}

