#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include "game.h"

using namespace std;

bool rules::movePiece(int i) {
    if (abs(places[moves[i][3]][moves[i][2]])==6){
        //std::cout << "Checkmate!!" << '\n';
        return false;
    }
    int spot = places[moves[i][1]][moves[i][0]];
    places[moves[i][1]][moves[i][0]] = 0;
    places[moves[i][3]][moves[i][2]] = spot;
    return true;
}

void rules::play(){
    bool end = true;
    count = 0;
    while (end){

        //black
        end = highestValue(false);
        //printBoard();
        if (end){

            //white
            end = pickRandomMove(true);
            //printBoard();
        }
    }
    //printMoves();
    cout << count << endl;
    if (count%2==0){
        black ++;
    }
}

bool rules::getSide(bool side, int j){
    if (side){
        return moves[j][4]<0;
    } else {
        return moves[j][4]>0;
    }
}

bool rules::pickRandomMove(bool side){
    count++;
    next(false);
    int j = rand()%counter;
    while (!getSide(side,j) || moves[j][4]==0){
        j = rand()%counter;
    }
    return movePiece(j);
}

bool rules::highestValue(bool side){
    next(false);
    int max = 0, index = 0, spot = 0;
    for (int i=0; i<counter; i++){
        spot = places[moves[i][3]][moves[i][2]];
        if (getSide(side,i)&&abs(spot)>max){
            index = i;
            max = spot;
        }
    }
    if (max == 0){
         return pickRandomMove(side);
    } else {
        count++;
        return movePiece(index);
    }
}
