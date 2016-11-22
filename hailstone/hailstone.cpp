#include <iostream>

using namespace std;

main (){
    long long int startingNum;
    int count = 0;
    do {
        cout << "Enter an Integer:" << endl;
        cin >> startingNum;
    } while (startingNum>0);
    cout << startingNum << endl;
    while(startingNum != 1){
        count++;
        if (startingNum%2==0){
            startingNum = startingNum/2;
        }
        else{
            startingNum = startingNum*3+1;
        }
        cout << startingNum << endl;
    }
    cout << "STUCK!!" << endl;
    cout << count+1 << endl;
}
