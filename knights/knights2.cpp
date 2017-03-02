#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int move(int, int, int);
int testMove(int, int);
void zeroPlaces();

int places[8][8] = {};

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

int main (){
    srand(time(0));
    while (move(0,0,1) < 64){
        zeroPlaces();
    }
    cout << "Got It" << endl;
    printBoard();
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

    places[x][y] = 1;

    int success = false;
    if (i==64){
        return i;
    }
    int h = 0;
    while (!success){
        h++;
        if (h==1000){
            success = true;
        }
        int number = rand()%8;
        int nX = x+hor[number];
        int nY = y+ver[number];
        if(testMove(nX, nY) == 1){
            success = true;
            //cout << nX << " , " << nY << "   " << i << endl;
            i++;
            places[nX][nY] = 1;
            i = move(nX, nY, i);
        }
    }
    //cout << i << endl;
    return i;
}

int testMove(int x, int y){
    if (0<=x && x<8){
        if (0<=y  && y<8){
            if (places[x][y] != 1){
                return 1;
            }
        }
    }
    return 0;
}

void zeroPlaces(){
    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
            places[i][j] = 0;
        }
    }
}
