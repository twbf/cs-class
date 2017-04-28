/* Thomas Bueler    Selection Sort

This program uses multiple functions, and one global variable "the size". The
function sort() uses 2 arrays to sort the array. It goes through the unsorted
part and finds the index of the least number then swaps it into the first part
of the unsorted array making the sorted part longer. It does this until it
gets to the end; I had a giant off by one loop error that took me forever to
get fixed, but eventually I found the bug.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#define SIZE 20
using namespace std;

class insertionSort{
public:
    void sort();
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

void insertionSort::sort(){
    int index, min, tmp;
    for(int i = 0; i<SIZE; i++){
        min = numArray[i];
        for(int j = i; j<SIZE; j++){
            if (min > numArray[j]){
                min = numArray[j];
                index = j;
            }
        }
        if (min == numArray[i]){
            index = i;
        }
        tmp = numArray[i];
        numArray[i] = numArray[index];
        numArray[index] = tmp;
    }
}

int main (){
    insertionSort is;
    is.getData();
    is.printData();
    is.sort();
    is.printData();
}

/*
thomas@thomas-gazelle:~/git/cs-class$ ./main
34      96      7       71      99      4       2       73      84      1       40      88      93      63      31      76      88      37      16      33

1       2       4       7       16      31      33      34      37      40      63      71      73      76      84      88      88      93      96      99

*/
