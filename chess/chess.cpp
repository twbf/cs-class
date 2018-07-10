#include <iostream>
#include <stdlib.h>
#include <fstream>
//#include <time.h>
//#include <string>

using namespace std;

void zeroPlaces();
int printBoard();
int createMoves(int, int, int);

int places[8][8];
int moves[100][5] = {}; // x, y, new x, new y, piece
int counter = 0;
int dirNewX = 0; //For directions
int dirNewY = 0;

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

void resetDir(){
    dirNewX = 0;
    dirNewY = 0;
}

void knight(int x, int y){

}

void queen(int x, int y){

}

void pawn(int x, int y){

    int newY = y+sign(places[y][x]);
    std::cout << "gjdh" << '\n';
    if (places[newY][x]==0){
        int move[5] = {x, y, x, newY, sign(places[y][x])};
        asignMove(move);
    }
    if (places[newY][x+1]!=0){
        int move[5] = {x, y, x+1, newY, sign(places[y][x])};
        asignMove(move);
    }
    if (places[newY][x-1]!=0){
        int move[5] = {x, y, x-1, newY, sign(places[y][x])};
        asignMove(move);
    }
}

void king(int x, int y){

}


void bishop(int x, int y){

}

// directions are cardinal with y = 1 being north
void rookDirection(int direction){
    resetDir();
    if (direction==0){
        dirNewY=-1;
    }
    if (direction==1){
        dirNewX=1;
    }
    if (direction==2){
        dirNewY=1;
    }
    if (direction==3){
        dirNewX=-1;
    }
}

int rookRecur(int x, int y, int direction) {
    rookDirection(direction);
    int newX = dirNewX + x;
    int newY = dirNewY + y;
    if (places[newY][newX]==0&&newX>=0&&newY>=0&&newX<8&&newY<8){
        return 1 + rookRecur(newX, newY, direction);
    } else{
        return 0;
    }
}

void rook(int x, int y){
    int eachDirection[4];
    for (int i=0; i<4; i++){
        eachDirection[i] = rookRecur(x,y,i);
    }
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

 int printMoves(){
     cout << endl;
      for (int i = 0; i<100; i++){
          for (int j = 0; j<5; j++){
             cout << moves[i][j] << " ";
          }
         cout << endl;
      }
      return 0;
 }


 void next(){
     for (int i = 0; i<8; i++){
         for (int j = 0; j<8; j++){
             switch (abs(places[i][j])){
                 case 0 :
                     break;
                 case 1 :
                     pawn(j,i);
                     break;
                 case 2:
                     rook(j,i);
                     break;
                 case 3:
                     knight(j,i);
                     break;
                 case 4:
                     bishop(j,i);
                     break;
                 case 5:
                     king(j,i);
                     break;
                 case 6:
                     queen(j,i);
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
     printMoves();
     //createMoves(-1,1,0);
 }
