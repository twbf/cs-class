#include <iostream>

using namespace std;

void switchPens(int, int , int, int, int);
void move(int, int);
void placeRings(int);
int firstPin(int);

int pins[3][10] = {};

int main(){
    placeRings(3);
    switchPens(3,0,1,2);
    return 0;
}

void switchPens(int numPins, int original, int tmp, int moved, numMoved){
    for(int i = 0; i< numMoved+1; i++){
        if (numMoved == 0){
            move(original, moved);
        } else if (num M){
            move(moved, tmp);
            move (original, moved);
            move(tmp, original);
        }
    }
    if(numPins > 1){

        switchPens(numPins-1, original, tmp, moved, numMoved +1);
    }
}

void move(int firstPin, int twoPin){
    int tmp = pins[firstPin][firstPin(firstPin)];
    pins[firstPin][firstPin(firstPin)] = 0;
    pins[twoPin][firstPin(twoPin)+1]=tmp
}

void placeRings(int pins){
    for (int i = 0; i<pins; i++){
        pins[0][i] = 1;
    }
}
