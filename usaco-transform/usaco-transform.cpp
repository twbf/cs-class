/*
ID: twbuele1
LANG: C++
PROG: transform
*/

#include <iostream>
#include <fstream>
#include <string>

char rotateArray(char[3][3],int);

using namespace std;

class transformPattern {

};

int main()
{
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int arraySize;
    fin >> arraySize;
    char startPattern[arraySize][arraySize];
    char endPattern[arraySize][arraySize];
    char changedPattern[arraySize][arraySize];
    for (int i = 0; i<arraySize; i++){
        fin >> startPattern[i];
    }
    for (int i = 0; i<arraySize; i++){
        fin >> endPattern[i];
    }

    changedPattern[arraySize][arraySize] = rotateArray(startPattern[arraySize][arraySize], arraySize);

    //checking
    int check = true;
    for (int i=0; i<arraySize; i++){
        for (int j=0; i<arraySize; i++){
            if (!(changedPattern[i][j] == changedPattern[i][j])){
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

char rotateArray(char pattern[3][3], int arraySize){
    char rotatedPattern[arraySize][arraySize];
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize; ++j) {
            rotatedPattern[i][j] = pattern[arraySize-j-1][i];
        }
    }
    return rotatedPattern[arraySize][arraySize];
}
