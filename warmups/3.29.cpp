#include <iostream>

using namespace std;

void perfectNum(int);

int main(){
    int num;
    cin >> num;
    perfectNum(num);
}

void perfectNum(int num){
    int count=0;
    cout << num << " divisors: ";
    for (int i = 2; i<num; i++){
        if (num%i == 0){
            cout << i << "+";
            count += i;
        }
    }
    if (num == count){
        cout << " yes" << endl;
    } else {
        cout << " no" << endl;
    }

}
