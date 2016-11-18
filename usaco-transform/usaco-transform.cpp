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
    char rotateArray(char**,int);
    int check(char**,char**, int);
    void changeArray(char**, char**, int, int);
};

char transformPattern::rotateArray(char **pattern, int arraySize){
    char **rotatedPattern = new char*[arraySize];
    for(int i = 0; i < arraySize; ++i)
        rotatedPattern[i] = new char[arraySize];
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize; ++j) {
            rotatedPattern[i][j] = pattern[arraySize-j-1][i];
        }
    }
    return **rotatedPattern;
}

int transformPattern::check(char** array1, char** array2, int size){
    for (int i=0; i<size; i++){
        for (int j=0; i<size; i++){
            if (!(array1[i][j] == array2[i][j])){
                return 1;
            }
        }
    }
    return 0;
}

void transformPattern::changeArray(char** start, char** end, int arraySize, int transformNum){
    char **changePattern = new char*[arraySize];
    for(int i = 0; i < arraySize; ++i)
        changePattern[i] = new char[arraySize];
    transformPattern tp;
    int check;
    switch (transformNum){
    case 1:
        **changePattern = tp.rotateArray(start, arraySize);
        check = tp.check(changePattern, end, arraySize);
        if (check == 0){
            cout << 1 << endl;
        }
    case 2:
        **changePattern = tp.rotateArray(start, arraySize);
        **changePattern = tp.rotateArray(start, arraySize);
        check = tp.check(changePattern, end, arraySize);
        if (check == 0){
            cout << 2 << endl;
        }
    case 3:
        **changePattern = tp.rotateArray(start, arraySize);
        **changePattern = tp.rotateArray(start, arraySize);
        **changePattern = tp.rotateArray(start, arraySize);
        check = tp.check(changePattern, end, arraySize);
        if (check == 0){
            cout << 2 << endl;
        }
    case 6:
        changePattern = start;
        check = tp.check(changePattern, end, arraySize);
        if (check == 0){
            cout << 2 << endl;
        }
    }
}

int main()
{
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int arraySize;
    fin >> arraySize;

    char **startPattern = new char*[arraySize];
    for(int i = 0; i < arraySize; ++i)
        startPattern[i] = new char[arraySize];

    char **endPattern = new char*[arraySize];
    for(int i = 0; i < arraySize; ++i)
        endPattern[i] = new char[arraySize];

    char **changePattern = new char*[arraySize];
    for(int i = 0; i < arraySize; ++i)
        changePattern[i] = new char[arraySize];

    for (int i = 0; i<arraySize; i++){
        fin >> startPattern[i];
    }
    for (int i = 0; i<arraySize; i++){
        fin >> endPattern[i];
    }
    transformPattern tp;
    for (int i = 0; i<8; i++){
        tp.changeArray(startPattern, endPattern, arraySize, i);
    }
    **changePattern = tp.rotateArray(startPattern, arraySize);

    //checking

    return 0;
}
