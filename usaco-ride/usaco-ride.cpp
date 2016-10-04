/*
ID: twbuele1
LANG: C++
PROG: test
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

int getCharNum(char);

int main()
{
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    char comet[20];
    char group[20];
    cout << "Enter 2 6 letter all Upper Case strings" << endl;
    cin >> comet >> group;
    int sumComet = 1, sumGroup= 1;
    for (int i=0; i<strlen(comet); i++){
        sumComet = getCharNum(comet[i]*sumComet);
    }
    for (int i=0; i<strlen(group); i++){
        sumGroup = getCharNum(group[i]*sumGroup);
    }
    cout << sumComet << '\n' << sumGroup << endl;
    return 0;
}

int getCharNum(char letter){
    int number;
    number = (int) letter;
    number -= 64;
    return number;
}
