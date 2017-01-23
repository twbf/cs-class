
#include <iostream>

using namespace std;

void switchPens(int, char, char, char);


int main(){
    int numPins;
    cin >> numPins;
    switchPens(numPins, 'A', 'B', 'C');
    return 0;
}

void switchPens(int numPins, char source, char aux, char dest){
    if (numPins == 1){
        cout << source << " to " << dest << endl;
    }
    else {
        switchPens(numPins-1, source, aux, dest);
        switchPens(1, source, dest, aux);
        switchPens(numPins-1, aux, dest, source);
    }
}
