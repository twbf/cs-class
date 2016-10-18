/* Thomas Bueler | Factorial-Recursion program
    This program has the user insert a number. That number goes into
the function "factorial" which outputs the factorial value. The function factorial
is a recursive function. This means that it calls itself in its function. This is
good way of approaching factorials because it doesn't have a for loop now.
*/
#include <iostream>

int factorial(int, int);

using namespace std;

int main (){
    int n;
    std::cout << "Please enter a number:" << std::endl;
    std::cin >> n;
    std::cout << n << "! = " << factorial(n,1) << std::endl;
    return 0;
}

int factorial(int n, int value){
    if(n>=1){
        value *= n;
        n--;
        factorial(n, value);
    } else{
        return value;
    }
}

/*
Please enter a number:
6
6! = 720

Process returned 0 (0x0)   execution time : 6.422 s
Press any key to continue.
*/
