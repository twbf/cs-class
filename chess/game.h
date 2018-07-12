#ifndef GAME_H
#define GAME_H

class rules{
public:
    int moves[100][5];
    void next();
    int printBoard();
    void printMoves();
    int counter;
    void asignMove(int[5]);
};
void play();


#endif
