/* Thomas Bueler   List of Primes
    This program lists all the prime numbers between 1 and whatever number the
user choses. The program goes through the numbers and inputs each number in
the findPrime function. The find prime function outputs a 1 if its prime and a
0 if its composite. The findPrime function divides factors up to the square
root of the number to sees if the number is prime. If it finds a factor it
imedietly returns that number. The main function then has 2 counters one for
primes and one for composites. It adds one every time it finds one of those
numbers. The last step in the program is to output the 2 counters.
*/

#include <iostream>
#include <math.h>
#include <fstream>

int findPrime (int);

using namespace std;

int main()
{
    int a, primes = 0, composite = 1;
    string filename;
    cout << "Prime Numbers To:" << endl;
    cin >> a;
    cout << "Do you want it saved in a file (0-no filename-yes)" << endl;
    cin >> filename;
    cout << "\nThe prime numbers are:" << endl;
    ofstream myfile (filename);
    for (int i = 2; i <= a; i++) {
        int prime = findPrime(i);
        if (prime == 1){
            primes++;
            myfile << i << "\t";
            cout << i << "\t";
        }
        else{
            composite++;
        }
    }
    myfile.close();
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
