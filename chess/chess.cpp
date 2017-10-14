#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

void zeroPlaces();
int printBoard();
int createMoves(int, int, int);

int places[8][8] = {};
int moves[100][2] = {};


int main (){
    ifstream fin ("chess/initial-board.in");
    srand(time(0));
    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
            fin >> places[i][j];
        }
    }
    printBoard();
    createMoves(-1,0,0);
}

int createMoves (int piece, int x, int y){
    int kindOfPeice = abs(piece);
    int side = 0;
    if (piece!=kindOfPeice){
        side=1;
    }
    //put into peice functons
    return 0;
}

void rook(int x, int y, bool pos){

}

void castle(int x, int y, bool pos){

}

void queen(int x, int y, bool pos){

}

void pawn(int x, int y, bool pos){

}

void king(int x, int y, bool pos){

}

void bishop(int x, int y){

}


 int printBoard(){
     cout << endl;
     for (int i = 0; i<8; i++){
         for (int j = 0; j<8; j++){
             cout << places[i][j] << " ";
         }
         cout << endl;
     }
     return 0;
 }
