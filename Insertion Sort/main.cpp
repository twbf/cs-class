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
        location = i+1;
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
thomas@thomas-gazelle:~/cs-class/Insertion Sort$ ./main
75	77	98	35	88	11	52	0	6	50	89	42	40	80	68	4	97	23	92	81

98	97	92	89	88	81	80	77	68	52	50	42	40	35	23	11	6	4	0   0

thomas@thomas-gazelle:~/cs-class/Insertion Sort$
*/
