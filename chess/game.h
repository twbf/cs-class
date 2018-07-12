#ifndef GAME_H
#define GAME_H

class rules{
public:
    int moves[100][5]; // x, y, new x, new y, piece
    int places[8][8];
    void next();
    int printBoard();
    void printMoves();
    int counter;
    void asignMove(int[5]);
    void play();

private:
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
};
void play();


#endif
