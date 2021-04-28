//
// Created by Lones on 27/04/2021.
//

#ifndef PROJECT_2_MAIN_H
#define PROJECT_2_MAIN_H

enum othelloColour{
    BLACK = 'B',
    WHITE = 'W',
    EMPTY = ' ',
};

typedef struct othelloPlayer{
    char name[20];
    enum othelloColour colour;
    int score;
}othelloPlayer;

othelloPlayer player1, player2;


#endif //PROJECT_2_MAIN_H
