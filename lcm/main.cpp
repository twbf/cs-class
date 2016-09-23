/* Thomas Bueler    Least Common Multiple
    This program uses the logic that goes to find the LCM of 3 numbers you can
find the LCM of the first 2 then the LCM  of the last 2. Then you can find the
LCM of those 2 numbers. This program makes us of a function to make this
process easier and to make it use less code. To find the LCM of 2 numbers the
program find the greatest common factor by dividing out factors and seeing if
they divide out. Once it has the GCF the program multiplies the 2 numbers and
divides by the GCF.
*/

#include <iostream>
#include <math.h>

int divideFactors(int, int, int, int, int);

using namespace std;

int main()
{
    int a, b, c, factor = 2, bigFactor = 1, lcm1, lcm2, lcm;
    cout << "Enter 3 numbers:" << endl;
    cin >> a >> b >> c;
    lcm1 = (a*b)/divideFactors(a, b, bigFactor, factor, a);
    lcm2 = (c*b)/divideFactors(c, b, bigFactor, factor, c);
    lcm = (lcm1*lcm2)/divideFactors(lcm1, lcm2, bigFactor, factor, lcm1);
    cout << "\n" << "LCM is: " << lcm << endl;
    return 0;
}

int divideFactors(int a, int b, int bigFactor, int factor, int original){
    int bold = b, aold = a;
    while (a % factor == 0 && b % factor == 0){
        a = a/factor;
        b = b/factor;
        bigFactor = bigFactor*factor;
    }
    if (factor<original) {
        divideFactors(b, a, bigFactor, factor+1, original);
    }
    else{
        return bigFactor;
    }

}

/*
thomas@ed-galu:~/cs-class/lcm$ ./lcm
Enter 3 numbers:
24
18
16
LCM is: 144
thomas@ed-galu:~/cs-class/lcm$
*/
