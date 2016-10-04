/*
ID: twbuele1
LANG: C++
PROG: test
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getCharNum(char);

int main()
{
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    char a, b;
    cin >> a;
    cout << getCharNum(a) << endl;
    return 0;
}

int getCharNum(char letter){
    int number;
    switch (letter){
        case "A": number=1;
            break;
    }
    return number;
}
