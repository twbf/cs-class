#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a;
    cout << "Prime Numbers To:" << endl;
    cin >> a;
    for (int i = 1; i <= a; i++) {
        int prime = 1, factor = 2;
        while (factor < i){
            if (i % factor == 0){
                prime = 0;
            }
            factor++;
        }
        if (prime == 1){
            cout << i << endl;
        }
    }
}
