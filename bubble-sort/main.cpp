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
    bool isdone = false;
    for (int i = 0; i< 20; i++){
        for (int j = 0; (j< 19) && !isdone; j++){
            isdone = true;
            if (numArray[j] > numArray[j+1]){
                isdone = false;
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
        cout << ", " <<  numArray[i];
    }
    cout << " " << endl;
}

int main(){
    bubbleSort bs;
    bs.getData();
    bs.printData();
    bs.sortData();
    bs.printData();
    return 0;
}
