#include <iostream>

using namespace std;

void switchPens(int, int , int, int);
void move(int, int);

int pins [3][10];

int main(){
    switchPens(3,0,1,2);
    return 0;
}

void switchPens(int numPins, int original, int tmp, int moved){
    if(numPins > 1){

        switchPens(numPins-1, original, tmp, moved);
    }
}
void move(int firstPin, int secoundPin){

}
