/* Thomas Bueler    Insertion Sort
    This program works by having 3 functions. Get data puts the data in an Array.
It uses time with rand to create random number. Print data is pretty self
explanatory. Bubble down is the work horse. It starts at the beggening of the
array and moves along taking out a peice and then it puts it in the right place.
It is like a machine and it moves along the array spitting out the sortyed array.
I for the first time used a global variable to make it eaisear to change the size
of the array. This was very important to make the usability of the program.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#define SIZE 40
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
        cout << ", " <<  numArray[i];
    }
    cout << endl;
}

void insertionSort::bubbleDown(){
    int tmp;
    int location;
    for (int i=0; i<SIZE; i++){
        tmp = numArray[i+1];
        for(int j = i+1; j>0; j--){
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
, 7, 51, 72, 16, 65, 49, 38, 25, 70, 10, 2, 13, 79, 24, 55, 82, 66, 14, 74, 28, 70, 94, 46, 51, 47, 96, 34, 25, 90, 75, 22, 81, 91, 41, 90, 61, 12, 34, 38, 50
, 96, 94, 91, 90, 90, 82, 81, 79, 75, 74, 72, 70, 70, 66, 65, 61, 61, 55, 51, 51, 50, 49, 47, 46, 41, 38, 38, 34, 34, 28, 25, 25, 24, 22, 16, 14, 13, 12, 2, 7

Process returned 0 (0x0)   execution time : 0.302 s
Press any key to continue.
*/
