/* Thomas Bueler    Selection Sort

*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#define SIZE 500
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
        index = 0;
        min = numArray[i];
        for(int j = i; j<SIZE; j++){
            if (min > numArray[j]){
                min = numArray[j];
                index = j;
            }
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
