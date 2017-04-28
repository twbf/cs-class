/* Towers of Hanoi   Thomas Bueler

    This program is very tough if you don't have a good algorithm. Before
    I looked at the cheatsheet I had a program that was miniplating a 2-d array
    reperesentition of the pins where the disks were labeled 1-10, and a place
    without a disk is labeled a 0. In fact the program is so simple, even with
    the counter that I added in. The base case for the function is when the
    number of pins = 1; when they don't you call the function 3 times changing
    the sources, dest, and aux order each time. This follows the 1213121 pattern
    I was noticing before the cheat sheet came along.
*/

#include <iostream>

using namespace std;

void switchPens(int, char, char, char);

int counter = 0;

int main(){
    int numPins;
    cout << "How many pins do you want to start with? ";
    cin >> numPins;
    switchPens(numPins, 'A', 'C', 'B');
    cout << "\nIt takes " << counter << " moves to move " << numPins << " disks." << endl;
    return 0;
}

void switchPens(int numPins, char source, char dest, char aux){
    if (numPins == 1){
        cout << source << " to " << dest << endl;
        counter++;
    }
    else {
        switchPens(numPins-1, source, aux, dest);
        switchPens(1, source, dest, aux);
        switchPens(numPins-1, aux, dest, source);
    }
}

/*
thomas@thomas-gazelle:~/git/cs-class$ ./main
How many pins do you want to start with? 4
A to B
A to C
B to C
A to B
C to A
C to B
A to B
A to C
B to C
B to A
C to A
B to C
A to B
A to C
B to C

It takes 15 moves to move 4 disks.
*/
