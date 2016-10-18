/* Thomas Bueler   Guess The Number
This program creates a random Number and makes the user guess what that number
is by telling the user if that number is too low or too high. It seeds the
random number using the current time. This program uses a while loop and an
if/ if else statement. I added a counter so the user would know how many times
it took them to get the correct answer.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(0));
    int number = rand()%50;
    int x;
    int count = 0;
    cout << "Guess a number between 1 and 50" << endl;
    while (number!=x){
        count ++;
        cin >> x;
        if (x<number){
            cout << "Too Low" << endl;
        }
        else if(x>number){
            cout << "Too High" << endl;
        }
    }
    cout << " \nYour Right" << endl;
    cout << "It took you only " << count << " tries!" << endl;
    return 0;
}

/*
Guess a number between 1 and 50
25
Too Low
37
Too Low
44
Too High
40
Too High
39

Your Right
It took you only 5 tries!

Process returned 0 (0x0)   execution time : 29.125 s
Press any key to continue.
*/
