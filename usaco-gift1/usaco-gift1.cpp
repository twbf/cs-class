/*
ID: twbuele1
LANG: C++
PROG: gift1
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    //ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int numberPeople;
    int people[10];
    fin >> numberPeople;
    while(i<=numberPeople){
        fin >> people[i];
        cout << people [i] << endl;
        i++
    }
    return 0;
}
