/* Thomas Bueler 3 integers project
This program finds the smallest and largest number in a set of 3 numbers. It compares
the first number to the next number and sees if that number is smaller or larger.
It then changes the sl and lg variable accordingly. It finally outputs the sl and
lg variables.
*/
#include <iostream>

using namespace std;

int main()
{
    int a, b, c, lg, sl;
    cout << "Enter 3 numbers" << endl;
    cin >> a >> b >> c;

    lg = a;
    sl = a;
    if(lg<b)
        lg=b;
    if(lg<c)
        lg=c;
    if(sl>b)
        sl=b;
    if(sl>c)
        sl=c;

    cout << "The largest is " << lg << endl;
    cout << "The smallest is " << sl << endl;
    return 0;
}
/*
Enter 3 numbers
5
9
8
The largest is 9
The smallest is 5

Process returned 0 (0x0)   execution time : 5.740 s
Press any key to continue.
*/
