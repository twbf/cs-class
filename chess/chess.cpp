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
int moves[100][5] = {}; //new x, new y, x, y, peice


int main (){
    ifstream fin ("chess/initial-board.in");
    srand(time(0));
    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
            fin >> places[i][j];
        }
    }
    printBoard();
    moves();
    createMoves(-1,0,0);
}

void moves(){
    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
            switch (places[i][j]){
                case 0 :
                    //exit
                case 1 || -1 :
                    pawn(i,j);
                case 2 || -2 :
                    rook(i,j);
                case 3 || -3 :
                    knight(i,j);
                case 4 || -4 :
                    bishop(i,j);
                case 5 || -5 :
                    king(i,j);
                case 6 || -6 :
                    queen(i,j);
            }
        }
    }
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



void rook(int x, int y){
    for ()
}

void knight(int x, int y, bool pos){

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
