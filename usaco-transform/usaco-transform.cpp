/*
ID: twbuele1
LANG: C++
PROG: transform
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int arraySize;
    fin >> arraySize;
    char startPattern[arraySize][arraySize];
    char endPattern[arraySize][arraySize];
    for (int i = 0; i<arraySize; i++){
        fin >> startPattern[i];
    }
    for (int i = 0; i<arraySize; i++){
        fin >> endPattern[i];
    }
    if (startPattern[0][0] == endPattern[0][0]){
        cout << 6 << endl;
        return 0;
    }
    return 0;
}
