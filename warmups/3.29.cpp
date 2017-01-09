#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void perfectNum(int);

int main(){
    for (int i=1; i<1000001; i++){
        perfectNum(i);
    }
    return 0;
}

void perfectNum(int num){
    int count=1;
    //cout << num << " divisors: 1";
    for (int i = 2; i<num; i++){
        if (num%i == 0){
            //cout << '+' << i;
            count += i;
        }
    }
    if (num == count){
        cout << num << endl;
    }
}
