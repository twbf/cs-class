
#include <iostream>

using namespace std;

void switchPens(int, int , int, int, int);
void move(int, int);
void placeRings(int);
int firstPin(int);

int pins[3][10] = {};

int main(){
    placeRings(3);
    switchPens(3,0,1,2,0);
    return 0;
}

void switchPens(int numPins, int original, int tmp, int moved, int numMoved){
    for(int i = 0; i< numMoved+1; i++){
        switchPens(numPins-1, original, tmp, moved, numMoved +1)
        move (original, moved);
        switchPens(numPins-1, original, tmp, moved, numMoved +1)
        if (numMoved == 0){
            move(original, moved);
        } else if (numMoved == 1){
            move(moved, tmp);
            move (original, moved);
            move(tmp, moved);
        }
        else {
            move (moved, original);
            move(moved, tmp);
            move (original, tmp);
            move (original, moved);
            move(tmp, original);
            move (tmp, moved);
            move (original, moved);
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
        pins[0][i] = i+1;
    }
}
