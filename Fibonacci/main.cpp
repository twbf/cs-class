/* Thomas Bueler Fibonacci Sequence
    This Program uses a function fibSeq that has a for loop to calculate the
nth number of the Fibonacci Sequence. The function adds the previous
number and the current number together to get the next number. It then
resets the variables.
*/

#include <iostream>

using namespace std;

int fibSeq(int nthValue){
    int curNum=1, prevNum=1, nextNum;
    for (int a=2;a<nthValue;a++){
        nextNum = curNum + prevNum;
        prevNum = curNum;
        curNum = nextNum;
    }
    return nextNum;
}

int main()
{
    int num;
    cout << "Input A Number" << endl;
    cin >> num;
    cout << "The " << num << "th number of the Fibonacci Sequence is " << fibSeq(num) << endl;
    return 0;
}

/*
Input A Number
7
The 7th number of the Fibonacci Sequence is 13

Process returned 0 (0x0)   execution time : 6.796 s
Press any key to continue.
*/
