#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int flip();

int main(){

    return 0;
}

void flip(int num){
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
