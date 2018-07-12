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
    int count = 0;
    while (end){
        count++;
        next(false);
        int j = rand()%100;
        while (moves[j][4]<0 || moves[j][4]==0){
            j = rand()%100;
        }
        end = movePiece(j);
        if (end){
            count++;
            next(false);
            j = rand()%100;
            while (moves[j][4]>0 || moves[j][4]==0){
                j = rand()%100;
            }
            end = movePiece(j);
        }
    }
    if (count%2==0){
        black ++;
    }
}
