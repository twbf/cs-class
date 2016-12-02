/* Thomas Bueler    Insertion Sort
    This program works by having 3 functions. Get data puts the data in an Array.
It uses time with rand to create random number. Print data is pretty self
explanatory. Bubble down is the work horse. It starts at the beggening of the
array and moves along taking out a peice and then it puts it in the right place.
It is like a machine and it moves along the array spitting out the sorted array.
I for the first time used a global variable to make it eaisear to change the size
of the array. This was very important to make the usability of the program.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#define SIZE 20
using namespace std;

class insertionSort{
public:
    void bubbleDown();
    void getData();
    void printData();
private:
    int numArray[SIZE];
};

void insertionSort::getData(){
    srand(time(0));
    for (int i = 0; i< SIZE; i++){
        numArray[i] = rand()%100;
    }
}

void insertionSort::printData(){
    for (int i = 0; i < SIZE; i++){
        cout <<  numArray[i] << "\t";
    }
    cout << "\n\n";
}

void insertionSort::bubbleDown(){
    int tmp;
    int location;
    for (int i=0; i<SIZE-1; i++){
        tmp = numArray[i+1];
        location = i+2;
        for(int j = location; j>0; j--){
            if (numArray[j-1]<tmp){
                numArray[j]=numArray[j-1];
                location = j;
            }
        }
        numArray[location-1]=tmp;
    }
}

main (){
    insertionSort is;
    is.getData();
    is.printData();
    is.bubbleDown();
    is.printData();
}

/*
11      29      14      54      12      74      98      1       23      51      76      17      51      13      59
66      12      75      57      70

98      76      75      74      70      66      59      57      54      51      51      29      23      17      14
13      12      12      11      1


Process returned 0 (0x0)   execution time : 0.031 s
Press any key to continue.

*/
