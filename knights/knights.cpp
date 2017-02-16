#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>

using namespace std;

int move(int, int, int);
int testMove(int, int);
void zeroPlaces();
int printBoard();

int places[8][8] = {};
int accesible[8][8] = {};

int main (){
    ifstream fin ("aseccible.in");
    srand(time(0));

    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
            fin >> accesible[i][j];
        }
    }

    while (move(4,4,0) < 64){
        //cout << "skjdfhkj" << endl;
        zeroPlaces();
    }
    cout << "Got It" << endl;
    return 0;
}

int move(int x, int y, int i){
    int hor[8], ver[8];

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
    i++;
    printBoard();
    if (i == 64) {
        return i;
    }
    places[x][y] = 1;
    int number = testMove(x,y);
    int nX = x+hor[number];
    int nY = y+ver[number];
    i = move(nX, nY, i);
    return i;
}

int testMove(int X, int Y){
    int hor[8], ver[8];

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

    int min = 0;

    for (int i = 0; i < 8; i++){
        int x = X+hor[i];
        int y = Y+ver[i];
        if (0<x && x<8){
            if (0<y  && y<8){
                if (places[x][y] != 1){
                    if (accesible[x][y]< accesible[X+hor[min]][Y+ver[min]]){
                        cout << min;
                        min = i;
                    }
                }
            }
        }
    }
    return min;
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
