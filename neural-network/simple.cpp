#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    ofstream fout ("simple.out");
    ifstream fin ("simple.test.in");
    srand(time(0));
    int layer1[3];
    for (int i= 0; i<3; i++){
        layer1[i]=rand();
    }
    int numTests;
    fin << numTests;
    for (int i = 0; i<numTests; i++){
        
    }
}
