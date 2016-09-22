/* Thomas Bueler    Least Common Multiple
    This program used very similar logic to the addition of fraction project.
The findFactors function finds the greatest common factors that both of the
numbers have. It is almost the exact same as the reduceFrac function in the
last program. Then it returns the greatest common factor. It multiples the 2
numbers and divides them by the GCF. This is a very easy way of finding the
least common Denominator. On thing that I noticed is that this is also an
algoritheam to find prime numbers. It won't take out a 14 because it will
have already taken out a 7 and a 2.
*/

#include <iostream>
#include <math.h>

int divideFactors(int, int, int, int);

using namespace std;

int main()
{
    int a, b, c, factor = 2, bigFactor = 1, lcm1, lcm2, lcm;
    cout << "Enter 2 numbers:" << endl;
    cin >> a >> b >> c;
    lcm1 = (a*b)/divideFactors(a, b, bigFactor, factor);
    lcm2 = (c*b)/divideFactors(c, b, bigFactor, factor);
    lcm = (lcm1*lcm2)/divideFactors(lcm1, lcm2, bigFactor, factor);
    cout << lcm1 << lcm2 << endl;
    cout << "\n" << "LCM is: " << lcm << endl;
    return 0;
}

int divideFactors(int a, int b, int bigFactor, int factor){
    int bold = b, aold = a;
    while (a % factor == 0 && b % factor == 0){
        a = a/factor;
        b = b/factor;
        bigFactor = bigFactor*factor;
    }
    if (bold != b || aold != a) {
        divideFactors(b, a, bigFactor, factor+1);
    }
    else{
        return bigFactor;
    }

}

/*
Enter 2 numbers:
12
18
LCM is: 36
Process returned 0 (0x0)   execution time : 6.312 s
Press any key to continue.
*/
