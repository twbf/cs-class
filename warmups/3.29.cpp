/* Thomas Bueler 3.29 prime numbers

This program outputs all prime numbers between 1 and 1000. It has a loop that
goes from 1-1000 that then calls a functon PerfectNum. PerfectNum then divides
factors and adds them up.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void perfectNum(int);

int main(){
    for (int i=1; i<1001; i++){
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
