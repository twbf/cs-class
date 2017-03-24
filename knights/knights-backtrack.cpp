/* Knights Tour Backtrack       Thomas Bueler

Beware this program uses aproximatly 3gb of Stack or it will overflow!!!

This program uses recursion and 4 functions to move a knight to all spots on a
chessboard. Why it uses 3gb of stack is because it recurses about 100 million
times and this adds up a lot in Stack. The function move either moves it foward
or takes off moves and does it angain and angain. This was one of the most
challenging programs and it took a while to complete.
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

int move(int, int, int);
int testMove(int, int, int);
int printMoves();

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
    move(0,0,0);
    printMoves();
    return 0;
}

int move(int x, int y, int i){
    moves[i][0] = x;
    moves[i][1] = y;
    places[x][y] = 1;
    if (i == 63) {
        return i;
    }
    int number = testMove(x,y,i);
    if (number == -1){
            places[x][y] = 0;
            moves[i][0] = 0;
            moves[i][1] = 0;
            moves[i][2] = 0;
            i--;
            moves[i][2]++;
            i = move(moves[i][0], moves[i][1], i);
    } else {
        i++;
        i = move(x+hor[number], y+ver[number], i);
    }
    return i;
}

int testMove(int X, int Y, int j){
    int cMoves = moves[j][2];
    int counter = 0;
    for (int i = 0; i < 8; i++){
        int x = X+hor[i];
        int y = Y+ver[i];
        if ((0<=x && x<8) && (0<=y  && y<8)){
            if (places[x][y] < 1){
                if(counter == cMoves){
                    return i;
                }
                counter++;
            }
        }
    }
    return -1;
}

 int printMoves(){
     cout << endl;
     for (int i = 0; i<64; i++){
         cout << moves[i][0] << " , " << moves[i][1];
         cout << endl;
     }
     return 0;
 }

/*
0 , 0
1 , 2
3 , 1
5 , 0
4 , 2
6 , 1
4 , 0
2 , 1
0 , 2
1 , 0
2 , 2
4 , 1
6 , 0
5 , 2
7 , 1
6 , 3
5 , 1
7 , 0
6 , 2
4 , 3
2 , 4
3 , 2
2 , 0
0 , 1
1 , 3
0 , 5
1 , 7
3 , 6
5 , 5
7 , 4
5 , 3
7 , 2
6 , 4
7 , 6
5 , 7
4 , 5
3 , 7
1 , 6
0 , 4
2 , 3
4 , 4
2 , 5
3 , 3
1 , 4
0 , 6
2 , 7
3 , 5
4 , 7
6 , 6
5 , 4
7 , 3
6 , 5
7 , 7
5 , 6
7 , 5
6 , 7
4 , 6
3 , 4
2 , 6
0 , 7
1 , 5
0 , 3
1 , 1
3 , 0
*/
