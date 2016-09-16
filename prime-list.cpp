#include <iostream>
#include <math.h>

int 

using namespace std;

int main()
{
    int a, primes = 0, composite = 1;
    cout << "Prime Numbers To:" << endl;
    cin >> a;
    cout << "\nThe prime Numbers Are:" << endl;
    for (int i = 2; i <= a; i++) {
        int prime = 1, factor = 2, b=i;
        while (factor <= sqrt(b)){
            if (i % factor == 0){
                prime = 0;
                b=1;
            }
            factor++;
        }
        if (prime == 1){
            primes++;
            cout << i << "\t";
        }
        else{
            composite++;
        }
    }
    cout << "\nNumber of Primes: " << primes << endl;
    cout << "\nNumber of Composites: " << composite << endl;
}
/*
*/

