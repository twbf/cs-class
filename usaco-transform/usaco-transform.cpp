/*
ID: twbuele1
LANG: C++
PROG: transform
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class transformPattern {
public:
    char rotateArray(char*,int);
};

char transformPattern::rotateArray(char *pattern, int arraySize){
    char* rotatedPattern = new char[arraySize*arraySize];
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize; ++j) {
            rotatedPattern[i*arraySize+j] = pattern[(arraySize-j-1)*arraySize+i];
        }
    }
    return rotatedPattern;
}

int main()
{
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int arraySize;
    fin >> arraySize;

    char startPattern[arraySize*arraySize];
    char endPattern[arraySize*arraySize];
    char changePattern[arraySize*arraySize];

    int SIZE = &arraySize;
    for (int i = 0; i<arraySize; i++){
        fin >> startPattern[i];
    }
    for (int i = 0; i<arraySize; i++){
        fin >> endPattern[i];
    }
    transformPattern tp;
    changePattern* = tp.rotateArray(*startPattern, arraySize);

    //checking
    int check = true;
    for (int i=0; i<arraySize; i++){
        for (int j=0; i<arraySize; i++){
            if (!(changePattern[i][j] == changePattern[i][j])){
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
