/* Hailstone Project Thomas Bueler

1. 7

2. The starting number 73 has a length of 106. The starting number 72 and
74 has a length of 23.

3.the length of the sequence starting at 2 n is 1 more, because the sequence
will divide by 2 and go through n.
*/

#include <iostream>

using namespace std;

main (){
    for (int i = 1; i<100; i++){
        long long int startingNum =i;
        int count = 0;
        //do {
        //    cout << "Enter an Integer:" << endl;
        //    cin >> startingNum;
        //} while (startingNum<=0);
        cout << startingNum;
        while(startingNum != 1){
            count++;
            if (startingNum%2==0){
                startingNum = startingNum/2;
            }
            else{
                startingNum = startingNum*3+1;
            }
            //cout << startingNum << endl;
        }
        //cout << "STUCK!!" << endl;
        cout << "How many times before it got stuck: " << count+1 << endl;
    }
}
