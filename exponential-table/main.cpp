/* Thomas Bueler Exponintial Tables
    This program computes the base to exponents between 1 and 10. This program
uses 2 while loops to acomplish the task of computing the exponents and
printing them off. The line that actually computes the exponents is line 21.
I used the *= to do this.
*/

#include <iostream>

using namespace std;
int main()
{
    int base;
    int loop = 1;
    cout << "Enter value for base (less than 8)" << endl;
    cin >> base;
    cout << "Base" << "\t" << "Exponent" << "\t" << "Result" << endl;
    while(loop<11){
        int result = base;
        int count = 1;
        while(count<loop){
            result*=base;
            count++;
        }
        cout << base << "\t" << loop << "\t" "\t" << result << endl;
        loop++;
    }
    return 0;
}
/*
Enter value for base (less than 8)
4
Base    Exponent        Result
4       1               4
4       2               16
4       3               64
4       4               256
4       5               1024
4       6               4096
4       7               16384
4       8               65536
4       9               262144
4       10              1048576

Process returned 0 (0x0)   execution time : 3.822 s
Press any key to continue.
*/
