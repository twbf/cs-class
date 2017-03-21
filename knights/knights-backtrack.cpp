#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

int move(int, int, int);
int testMove(int, int, int);
void zeroPlaces();
int printBoard();
int printMoves();
int numMoves =0;

int places[8][8] = {};
int moves [64][3] = {};
int hor[8], ver[8];

int main (){
    hor[0] = 2;
    hor[1] = 1;
    hor[2] = -1;
    hor[3] = -2;
    hor[4] = -2;
    hor[5] = -1;
    hor[6] = 1;
    hor[7] = 2;

    ver[0] = -1;
    ver[1] = -2;
    ver[2] = -2;
    ver[3] = -1;
    ver[4] = 1;
    ver[5] = 2;
    ver[6] = 2;
    ver[7] = 1;
    for (int i = 5; i<6; i++){
        for (int j = 0; j<1; j++){
            cout << move(i,j,0) << endl;
            printBoard();
            printMoves();
            zeroPlaces();
            cout << numMoves << endl;
        }
    }
    return 0;
}

int move(int x, int y, int i){
    //printMoves();
    printBoard();
    moves[i][0] = x;
    moves[i][1] = y;
    cout << i << endl;
    places[x][y] = 1;
    if (i == 63) {
        return i;
    }
    int number = testMove(x,y,i);
    numMoves++;
    if (number == -1){
        moves[i][2]++;
        if (moves[i][2] > 7){
            places[x][y] = 0;
            moves[i][0] = 0;
            moves[i][1] = 0;
            moves[i][2] = 0;
            i--;
            i--;
            i = move(moves[i][0], moves[i][1], i);
        } else {
            i = move(moves[i][0], moves[i][1], i);
        }
    } else {
        int nX = x+hor[number];
        int nY = y+ver[number];
        i++;
        i = move(nX, nY, i);
    }
    return i;
}

int testMove(int X, int Y, int j){
    int min = 0;
    bool validspace = false;
    int cMoves = moves[j][2];
    int counter = 0;
    for (int i = 0; i < 8; i++){
        int x = X+hor[i];
        int y = Y+ver[i];
        if ((0<=x && x<8) && (0<=y  && y<8) && (places[x][y] < 1)){
            if(counter == cMoves){
                validspace = true;
                min = i;
                i = 8;
            }
            counter++;
        }
    }
    if (validspace == false){
        return -1;
    }else{
        return min;
    }
}

void zeroPlaces(){
    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
            places[i][j] = 0;
        }
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
     for (int i = 0; i<64; i++){
         cout << moves[i][0] << " , " << moves[i][1];
         cout << endl;
     }
     return 0;
 }
