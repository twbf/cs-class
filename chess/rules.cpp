#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "game.h"

using namespace std;

int dirnX = 0; //For directions
int dirnY = 0;

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

void rules::asignMove (int move[5]){
    for(int i=0; i<5; i++){
        moves[counter][i]=move[i];
    }
    counter++;
}

void resetDir(){
    dirnX = 0;
    dirnY = 0;
}

void rules::pawn(int x, int y){
    int nY = y+sign(places[y][x]);
    int ori = places[y][x];
    int a = places[nY][x+1];
    int b = places[nY][x-1];
    if (places[nY][x]==0&&coB(x,nY)){
        int move[5] = {x, y, x, nY, sign(ori)};
        asignMove(move);
    }
    if (a!=0&&coB(x+1,nY)){
        if (sign(ori)!=sign(a)){
            int move[5] = {x, y, x+1, nY, sign(ori)};
            asignMove(move);
        }
    }
    if (b!=0&&coB(x-1,nY)){
        if (sign(ori)!=sign(b)){
            int move[5] = {x, y, x-1, nY, sign(ori)};
            asignMove(move);
        }
    }
}

// directions are cardinal with y = 1 being north
void rules::ortagonalDir(int direction){
    resetDir();
    if (direction==0){
        dirnY=-1;
    }
    if (direction==1){
        dirnX=1;
    }
    if (direction==2){
        dirnY=1;
    }
    if (direction==3){
        dirnX=-1;
    }
}

// starting with north-east
void rules::diagonalDir(int direction){
    resetDir();
    if (direction==0){
        dirnY=-1;
        dirnX=1;
    }
    if (direction==1){
        dirnX=1;
        dirnY=1;
    }
    if (direction==2){
        dirnY=1;
        dirnX=-1;
    }
    if (direction==3){
        dirnX=-1;
        dirnY=-1;
    }
}


void rules::recur(int x, int y, int orgX, int orgY, int grid, int direction) { // For grid 1 is ortagonal and 2 is diagonal
    if (grid == 1) {
        ortagonalDir(direction);
    }
    if (grid == 2) {
        diagonalDir(direction);
    }
    int nX = dirnX + x;
    int nY = dirnY + y;
    if (coB(nX,nY)){
        if (places[nY][nX]==0){
            int move[5] = {orgX, orgY, nX, nY, places[orgY][orgX]};
            asignMove(move);
            recur(nX, nY, orgX, orgY, grid, direction);
        } else if(sign(places[nY][nX])!=sign(places[orgY][orgX])){
            int move[5] = {orgX, orgY, nX, nY, places[orgY][orgX]};
            asignMove(move);
        }
    }
}

void rules::rook(int x, int y){
    for (int i=0; i<4; i++){
        recur(x,y,x,y,1,i);
    }
}

void rules::bishop(int x, int y){
    for (int i=0; i<4; i++){
        recur(x,y,x,y,2,i);
    }
}

void rules::queen(int x, int y){
    for (int i=0; i<4; i++){
        recur(x,y,x,y,1,i);
        recur(x,y,x,y,2,i);
    }
}

void rules::oneStep(int x, int y, int pMoves[8][2]){
    for (int i=0; i<8; i++){
        int nX = pMoves[i][0] + x;
        int nY = pMoves[i][1] + y;
        if (coB(nX,nY)){
            if (places[nY][nX]==0||sign(places[nY][nX])!=sign(places[y][x])){
                int move[5] = {x, y, nX, nY, places[y][x]};
                asignMove(move);
            }
        }
    }
}

void rules::knight(int x, int y){
    int pMoves[8][2] =  {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
    oneStep(x,y,pMoves);
}

void rules::king(int x, int y){
    int pMoves[8][2] =  {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1}};
    oneStep(x,y,pMoves);
}

int rules::printBoard(){
    cout << endl;
     for (int i = 0; i<8; i++){
         for (int j = 0; j<8; j++){
            cout << places[i][j] << " ";
         }
        cout << endl;
     }
     return 0;
 }

 void rules::printMoves(){
     cout << endl;
      for (int i = 0; i<counter; i++){
          for (int j = 0; j<5; j++){
             std::cout << moves[i][j] << " ";
          }
         cout << endl;
      }
 }

 void rules::next(bool first){  //if first is true then it cins from file
     memset(moves, 0, sizeof(moves));
     counter = 0;
     if (first){
         ifstream fin ("initial-board.in");
         for (int i = 0; i<8; i++){
             for (int j = 0; j<8; j++){
                 fin >> places[i][j];
             }
         }
    }
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
