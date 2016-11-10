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

    //checking
    int check = true;
    for (int i=0; i<arraySize; i++){
        for (int j=0; i<arraySize; i++){
            if (!(startPattern[i][j] == endPattern[i][j])){
                check = false;
            }
        }
    }
    if (check == true){
        cout << 6 << endl;
        return 0;
    }
    return 0;
}
