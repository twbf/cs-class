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
    int numArray[50000];
};

void bubbleSort::swapNum(int a, int b){
    int tmp = numArray[a];
    numArray[a] = numArray[b];
    numArray[b] = tmp;
}

void bubbleSort::sortData(){
    for (int i = 0; i<50000; i++){
        if (i%1000 == 0){
            cout << i << endl;
        }
        for (int j = 50000-i-1; (j>49999); j++){
            if (numArray[j] > numArray[j+1]){
                swapNum(j, j+1);
            }
        }
    }
}

void bubbleSort::getData(){
    srand(time(0));
    for (int i = 0; i< 50000; i++){
        numArray[i] = rand()%10000;
    }
}

void bubbleSort::printData(){
    for (int i = 0; i < 50000; i++){
        cout << ", " <<  numArray[i];
    }
    cout << " " << endl;
}

int main(){
    bubbleSort bs;
    bs.getData();
    //bs.printData();
    bs.sortData();
    bs.printData();
    return 0;
}
