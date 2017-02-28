/*
ID: twbuele1
LANG: C++
PROG: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("test.out");
    ifstream fin ("usaco-test/test.in");
    int a, b;
    fin >> a >> b;
    cout << a << endl;
    cout << a+b << endl;
    return 0;
}
