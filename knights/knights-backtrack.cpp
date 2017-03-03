#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

int move(int, int, int);
int testMove(int, int);
void zeroPlaces();
int printBoard();

int places[8][8] = {};
int accesible[8][8] = {};
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
    for (int i = 0; i<1; i++){
        for (int j = 0; j<1; j++){
            cout << move(i,j,0) << endl;
            //printBoard();
            zeroPlaces();
        }
    }
    return 0;
}

int move(int x, int y, int i){
    moves[i][0] = x;
    moves[i][1] = y;
    moves[i][2]++;
    i++;
    printBoard();
    if (i == 64) {
        return i;
    }
    places[x][y] = 1;
    int number = testMove(x,y);
    //cout << number << endl;
    if (number == -1){
        i = move(moves[i--][0], moves[i--][0], i--);
    }
    int nX = x+hor[number];
    int nY = y+ver[number];
    i = move(nX, nY, i);
    return i;
}

int testMove(int X, int Y){
    int min = 0;
    bool validspace = false;
    int counter = 
    for (int i = 0; i < 8; i++){
        int x = X+hor[i];
        int y = Y+ver[i];
        if ((0<=x && x<8) && (0<=y  && y<8) && (places[x][y] != 1)){
            validspace = true;
            min = i;
            i = 8;
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
