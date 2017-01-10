#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int flip();

int main(){
    int tails=0, heads=0;
    srand(time(NULL));
    for (int i = 0; i<1000000000; i++){
        if (flip()==1){
            tails++;
        } else{
            heads++;
        }
    }
    cout << "Heads: " << heads << "\nTails: " << tails << endl;
    return 0;
}

int flip(){
    return rand()%2;
}
