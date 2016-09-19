#include <iostream>
#include <math.h>

int findPrime (int);

using namespace std;

int main()
{
    int a, primes = 0, composite = 1;
    cout << "Prime Numbers To:" << endl;
    cin >> a;
    cout << "\nThe prime numbers are:" << endl;
    for (int i = 2; i <= a; i++) {
        int prime = findPrime(i);
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

int findPrime (int number) {
    int factor = 2;
    while (factor <= sqrt(number)){
        if (number % factor == 0){
            return 0;
        }
        factor++;
    }
    return 1;
}

/*
Prime Numbers To:
10000

The prime numbers are:
2	3	5	7	11	13	17	19	23	29	31	37	41	43	47	53
...
9907	9923	9929  9931	9941	9949	9967	9973
Number of Primes: 1229

Number of Composites: 8771
*/
