# COMP10050 Assignment 2
## Lones Xheladini (20331731)

###Board
* The board was implemented using a 2D char array filled with, ' ' , 'B' and 'W'.

* When a move is needed to be made then the spot board[x][x] is filled with whichever colour.

* Most of the board related functions are in interface.c.

###Player
* The player is initialised from the othelloPlayer struct in main.h, this is used to keep all player related stats.

* Both player names are kept in player(1/2).name.

* Both player scores are kept in player(1/2).score.

* Both player colours are kept in player(1/2).colour.

* The use of the randomisePlayer() is used to find who goes first.
### Game logic
* The game is started using the play() function.

* There is a 2D bool array with all falses on it. Then the validmove function will make all the validmoves on the bool table to TRUE.

* This allows me to quickly check if a player choice is valid or not.

* If the player choice is a valid move then the move is made on the real board using the make_move() function.

* The make move function just goes through each row in every direction to check for all the disks that it must flip over to the new game state.

* This function uses the rowCheck() function which is what does the actual flipping.




