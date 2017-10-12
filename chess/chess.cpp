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

int moves (){
    
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
