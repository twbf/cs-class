/* Thomas Bueler    Bubble Sort
This is a smart bubble sort. It uses a for loop and  and classes to make it
more readable. The bubble sort  goes through half as as often as a regular
bubble sort. It is still not as fast as other sorts.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class bubbleSort {
public:
    void swapNum(int,int);
    void getData();
    void sortData();
    void printData();
private:
    int numArray[20];
};

void bubbleSort::swapNum(int a, int b){
    int tmp = numArray[a];
    numArray[a] = numArray[b];
    numArray[b] = tmp;
}

void bubbleSort::sortData(){
    for (int i = 0; i<20; i++){
        for (int j = i; j>-1; j--){
            if (numArray[j] > numArray[j+1]){
                swapNum(j, j+1);
            }
        }
    }
}

void bubbleSort::getData(){
    srand(time(0));
    for (int i = 0; i< 20; i++){
        numArray[i] = rand()%100;
    }
}

void bubbleSort::printData(){
    for (int i = 0; i < 20; i++){
        cout <<  numArray[i] << "\t";
    }
    cout << " \n" << endl;
}

int main(){
    bubbleSort bs;
    bs.getData();
    bs.printData();
    bs.sortData();
    bs.printData();
    return 0;
}

/*
15      49      22      88      65      34      11      45      81      72      74      50      3       25      4
21      60      54      79      72

3       4       11      15      21      22      25      34      45      49      50      54      58      60      65
72      72      74      79      81


Process returned 0 (0x0)   execution time : 0.016 s
Press any key to continue.
*/
