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

// Checks to see if a spot is on the board.
bool coB(int x, int y){
    if(x>=0&&y>=0&&x<8&&y<8){
        return true;
    }
    return false;
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

void pawn(int x, int y){
    int newY = y+sign(places[y][x]);
    if (places[newY][x]==0&&coB(x,newY)){
        int move[5] = {x, y, x, newY, sign(places[y][x])};
        asignMove(move);
    }
    if (places[newY][x+1]!=0&&coB(x+1,newY)){
        int move[5] = {x, y, x+1, newY, sign(places[y][x])};
        asignMove(move);
    }
    if (places[newY][x-1]!=0&&coB(x-1,newY)){
        int move[5] = {x, y, x-1, newY, sign(places[y][x])};
        asignMove(move);
    }
}

// directions are cardinal with y = 1 being north
void ortagonalDir(int direction){
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

// starting with north-east
void diagonalDir(int direction){
    resetDir();
    if (direction==0){
        dirNewY=-1;
        dirNewX=1;
    }
    if (direction==1){
        dirNewX=1;
        dirNewY=1;
    }
    if (direction==2){
        dirNewY=1;
        dirNewX=-1;
    }
    if (direction==3){
        dirNewX=-1;
        dirNewY=-1;
    }
}


void recur(int x, int y, int orgX, int orgY, int grid, int direction) { // For grid 1 is ortagonal and 2 is diagonal
    if (grid == 1) {
        ortagonalDir(direction);
    }
    if (grid == 2) {
        diagonalDir(direction);
    }
    int newX = dirNewX + x;
    int newY = dirNewY + y;
    if (coB(newX,newY)){
        if (places[newY][newX]==0){
            int move[5] = {orgX, orgY, newX, newY, places[orgY][orgX]};
            asignMove(move);
            recur(newX, newY, orgX, orgY, grid, direction);
        } else if(sign(places[newY][newX])!=sign(places[orgY][orgX])){
            int move[5] = {orgX, orgY, newX, newY, places[orgY][orgX]};
            asignMove(move);
        }
    }
}

void rook(int x, int y){
    for (int i=0; i<4; i++){
        recur(x,y,x,y,1,i);
    }
}

void bishop(int x, int y){
    for (int i=0; i<4; i++){
        recur(x,y,x,y,2,i);
    }
}

void queen(int x, int y){
    for (int i=0; i<4; i++){
        recur(x,y,x,y,1,i);
    }
    for (int i=0; i<4; i++){
        recur(x,y,x,y,2,i);
    }
}

void knight(int x, int y){

}

void king(int x, int y){

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
                 case 6:
                     king(j,i);
                     break;
                 case 5:
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
 }
