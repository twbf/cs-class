/* Thomas Bueler   Addition of 2 Fractions
    I am using the linux terminal to run programs rather than an IDE. I think
the terminal is simplier. Back to the program, it addes 2 fractions by
muntipling the denominaters and then adding the numerator. It output the
unreduced fraction. Then the fraction goes into the reduceFrac function.
This function tests all integers starting at 2 and going up to the current
square root to the smallest numerator or denominator. It then cout's the
reduced fraction.
*/
#include <iostream>
#include <math.h>

int addFrac(int,int,int,int);
int reduceFrac(int,int);

using namespace std;

int main()
{
    int a, b, c, d;
    cout << "\n" << "Insert a fraction in the form a 'enter' b " << endl;
    cin >> a >> b;
    cout << "\n" << "Insert another fraction in the form c 'enter' d " << endl;
    cin >> c >> d;
    addFrac(a,b,c,d);
    return 0;
}

int addFrac(int a, int b, int c, int d){
    int den, num;
    den = b*d;
    num = (a*d)+(c*b);
    cout << "\nUnreduced: " << num << "/" << den << endl;
    reduceFrac(num, den);
    return 0;
}

int reduceFrac(int num, int den){
    int sml, factor = 2;
    if (num<den) {
        sml=num;
    }
    else {
        sml=den;
    }

    while (factor <= sqrt(sml)){
        while (num % factor == 0 && den % factor == 0) {
            num = num/factor;
            den = den/factor;
            sml = sml/factor;
        }
        factor++;
    }
    if (den == 1){
        cout << "\nReduced: " << num << "\n" << endl;
    }
    else{
        cout << "\nReduced: " << num << "/" << den << "\n" << endl;
    }

    return 0;
}

/*
tv@bueler-gazelle:~/cs-class/fraction-addition$ ./main1

Insert a fraction in the form a 'enter' b
8
36

Insert another fraction in the form c 'enter' d
169
21

Unreduced: 6252/756

Reduced: 521/63
*/
