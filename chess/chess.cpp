#include <iostream>
#include <stdlib.h>
#include <fstream>
//#include <time.h>
//#include <string>

using namespace std;

void zeroPlaces();
int printBoard();
int createMoves(int, int, int);

int places[8][8] = {};
int moves[100][5] = {}; // x, y, new x, new y, peice
int counter = 0;




int createMoves (int piece, int x, int y){
    int kindOfPeice = abs(piece);
    int side = 0;
    if (piece!=kindOfPeice){
        side=1;
    }
    //put into peice functons
    return 0;
}

int sign (int num){
    int sign = num/abs(num);
    return sign;
}

void asignMove (int move[5]){
    for(int i=0; i<5; i++){
        moves[counter][i]=move[i];
    }
    counter++;
}

//void rook(int x, int y){
    //for ()
//}

void knight(int x, int y){

}

void queen(int x, int y){

}

void pawn(int x, int y){
    if (places[x][y+sign(places[x][y])]==0){
        int move[5] = {x, y, x, y+sign(places[x][y]), sign(places[x][y])};
        asignMove(move);
    }
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


 void next(){
     for (int i = 0; i<8; i++){
         for (int j = 0; j<8; j++){
             switch (places[i][j]){
                 case 0 :
                     break;
                 case 1 :
                     pawn(i,j);
                     break;
                 case 2:
                     //rook(i,j);
                     break;
                 case 3:
                     knight(i,j);
                     break;
                 case 4:
                     bishop(i,j);
                     break;
                 case 5:
                     king(i,j);
                     break;
                 case 6:
                     queen(i,j);
                     break;
                 default:
                    break;
             }
         }
     }
 }

 int main (){
     ifstream fin ("initial-board.in");
     for (int i = 0; i<8; i++){
         for (int j = 0; j<8; j++){
             fin >> places[i][j];
         }
     }
     printBoard();
     next();
     //createMoves(-1,1,0);
 }
