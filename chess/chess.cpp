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
int moves[100][5] = {}; // x, y, new x, new y, peice
int counter = 0;


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

void sign (int num){
    int sign = num/abs(num);
    return sign;
}



void rook(int x, int y){
    for ()
}

void knight(int x, int y){

}

void queen(int x, int y){

}

void pawn(int x, int y){
    if (places[x][y+sign(places[x][y])]==0){
        moves[counter][0]= x;
        moves[counter][1]= y;
        moves[counter][3]= x;
        moves[counter][4]= y+sign(places[x][y]);
        moves[counter][5]= sign(places[x][y]);
    }
    counter++;
}

void king(int x, int y){

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
