#ifndef GAME_H
#define GAME_H

class rules{
public:

    //rules.cpp
    int moves[1000][5]; // x, y, new x, new y, piece
    int places[8][8];
    void next(bool);
    int printBoard();
    void printMoves();
    int counter;
    int black;
    void asignMove(int[5]);

    //play.cpp
    void play();
    int count;

private:

    //rules.cpp
    void pawn(int, int);
    void oneStep(int, int, int[8][2]);
    void recur(int, int, int, int, int, int);
    void diagonalDir(int);
    void ortagonalDir(int);
    void king(int, int);
    void knight(int, int);
    void rook(int, int);
    void bishop(int, int);
    void queen(int, int);

    //play.cpp
    bool movePiece(int);
    bool pickRandomMove(bool);
    bool highestValue(bool);
    bool getSide(bool, int);
};
void play();


#endif
