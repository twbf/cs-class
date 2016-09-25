/* Thomas Bueler | Factorial program
    This program has the user insert a number. That number goes into
the function "factorial" which outputs the factorial value. In the
function there is one variable that gets declared which is "value".
The function cointains one for loop that starts at one and ends at the
number. In the for loop value gets multiplied by i. At the end of the
function value gets outputed.
*/
#include <iostream>

int factorial(int);

using namespace std;

int main (){
    int n;
    std::cout << "Please enter a number:" << std::endl;
    std::cin >> n;
    std::cout << n << "! = " << factorial(n) << std::endl;
    return 0;
}

int factorial(int n){
    int value = 1;
    for(int i = 1; i <= n; i++){
        value *= i;
    }
    return value;
}

/*
tv@bueler-gazelle:~/cs-class/factorials$ ./main1
Please enter a number:
4
4! = 24
tv@bueler-gazelle:~/cs-class/factorials$
*/
