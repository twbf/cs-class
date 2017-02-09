#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int move(int, int, int);
void zeroPlaces();

int places[8][8] = {};

int main (){
    while (move(4,4,0) < 40){
        zeroPlaces();
    }
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
    srand(time(0));
    if (i==64){
        return i;
    }
    int h = 0;
    while (!success){
        h++;
        if (h==100){
            success = true;
        }
        int number = rand()%8;
        int nX = x+hor[number];
        int nY = y+ver[number];
        if (0<nX && nX<8){
            if (0<nY  && nY<8){
                if (places[nX][nY] != 1){
                    success = true;
                    //cout << nX << " , " << nY << "   " << i << endl;
                    i++;

                    move(nX, nY, i);
                }
            }
        }
    }
    cout << i << endl;
    return i;
}

void zeroPlaces(){
    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
            places[i][j] = 0;
        }
    }
}
