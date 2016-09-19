/* Thomas Bueler    Is a number prime?
    This program creates random number between 1 and 1000. It then sees if
this number is prime or not. It uses the time to seed the random number. It
uses a while loop to check to go through integers between 2 and the square
root of the number. An if statement checks to see if that factor goes into
the number. If it does go in than  it sets prime to 0 so the computer knows
it isn't prime.
*/

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int findPrime (int);

using namespace std;

int main()
{
    srand(time(0));
    int a = rand()%1000;
    cout << "Is " << a << " prime?" << endl;
    findPrime(a);
    return 0;
}

int findPrime (int a){
    int prime = 1, factor = 2;
    while (factor <= sqrt(a)){
        if (a % factor == 0){
            prime = 0;
            cout << "Not Prime" << endl;
            return 0;
        }
        factor++;
    }
    cout << "Prime" << endl;
    return 0;
}

/*
Is 859 prime?
Prime

Process returned 0 (0x0)   execution time : 0.016 s
Press any key to continue.
*/
