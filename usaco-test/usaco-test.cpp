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
    ifstream fin ("beads.in");
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
    return 0;
}