/* Thomas Bueler    Arithmetic Project
This program has the user input 2 numbers. Then the computer caculates the sum,
difference, product, and quotient. After the program has set the variables holding
these numbers then the computer outputs these numbers. The quotient is floored and
thats why it is 0 in the example below.
*/
#include <iostream>

using namespace std;

int main()
{
    int a, b, sum, difference, product, quocheint;
    cout << "Enter Integer 1" << endl;
    cin >> a;
    cout << "Enter Integer 2" << endl;
    cin >> b;

    sum = a+b;
    difference = a-b;
    product = a*b;
    quocheint = a/b;

    cout << "Sum is: " <<  sum << endl;
    cout << "Difference is: " << difference << endl;
    cout << "Product is: " << product << endl;
    cout << "Quotient is: " << quocheint << endl;

    return 0;
}

/*
Enter Integer 1
7
Enter Integer 2
11
Sum is: 18
Difference is: -4
Product is: 77
Quotient is: 0

Process returned 0 (0x0)   execution time : 16.158 s
Press any key to continue.
*/
