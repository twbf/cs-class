#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

void zeroPlaces();
int printBoard();

int places[8][8] = {};


int main (){
    ifstream fin ("chess/initial-board.in");
    srand(time(0));
    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
            fin >> places[i][j];
        }
    }
    printBoard();
}

int moves (int piece){
    int kindOfPeice = abs(peice);
    int side = 0;
    if (peice!=kindOfPeice){
        side=1;
    }
    //put into peice functons
    return 0;
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
