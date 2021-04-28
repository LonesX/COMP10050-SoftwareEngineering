#include <stdio.h>
#include "../lib/interface.h"
#include "../lib/moves.h"
#include "../lib/player.h"
#include "stdlib.h"
#include "time.h"
#include <stdbool.h>
int main(void) {
    char board[8][8];
    bool validMoves[8][8] = {false};
    setupBoard(board);
    displayBoard(board);
    play(board, validMoves);
    return 0;
}

