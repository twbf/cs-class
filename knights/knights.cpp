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

int main (){
    ifstream fin ("knights/aseccible.in");
    srand(time(0));
    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
            fin >> accesible[i][j];
        }
    }
    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
            cout << move(i,j,1) << endl;
            printBoard();
            zeroPlaces();
        }
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
    //printBoard();
    if (i == 64) {
        return i;
    }
    places[x][y] = 1;
    int number = testMove(x,y);
    //cout << number << endl;
    if (number == -1){
        cout << "dang" << endl;
        return i;
    }
    int nX = x+hor[number];
    int nY = y+ver[number];
    places[nX][nY] = 1;
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

    int min = 0, nY, nX;
    bool validspace = false;

    for (int i = 0; i < 8; i++){
        int x = X+hor[i];
        int y = Y+ver[i];
        if ((0<=X+hor[min] && X+hor[min]<8) || (0<=Y+ver[min] && Y+ver[min]<8)){
            nX = X+hor[min];
            nY = Y+ver[min];
        }
        else{
            nX = 2;
            nY = 2;
        }
        if (0<=x && x<8){
            if (0<=y  && y<8){
                if (places[x][y] != 1){
                    validspace = true;
                    if (accesible[x][y] < accesible[nX][nY]){
                        //cout << min;
                        min = i;
                    }
                }
            }
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
