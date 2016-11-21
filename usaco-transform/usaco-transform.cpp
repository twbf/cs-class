/*
ID: twbuele1
LANG: C++
PROG: transform
*/

#include <iostream>
#include <fstream>
#include <string>

class transformPattern {
public:
    char** rotateArray(char**,int);
    char** flipArray(char**, int);
    int check(char**,char**, int);
    int changeArray(char**, char**, int, int);
};

using namespace std;

char** transformPattern::rotateArray(char **pattern, int arraySize){
    char **rotatedPattern = new char*[arraySize];
    for(int i = 0; i < arraySize; i++)
        rotatedPattern[i] = new char[arraySize];
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < arraySize; j++) {
            rotatedPattern[i][j] = pattern[arraySize-j-1][i];
        }
    }
    return rotatedPattern;
}

char** transformPattern::flipArray(char **pattern, int arraySize){
    char **rotatedPattern = new char*[arraySize];
    for(int i = 0; i < arraySize; i++)
        rotatedPattern[i] = new char[arraySize];
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < arraySize; j++) {
            rotatedPattern[i][j] = pattern[i][arraySize-j-1];
        }
    }
    return rotatedPattern;
}

int transformPattern::check(char** array1, char** array2, int size){
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            if (array1[i][j] != array2[i][j]){
                return 1;
            }
        }
    }
    return 0;
}

int transformPattern::changeArray(char** start, char** end, int arraySize, int transformNum){
    char **changePattern = new char*[arraySize];
    for(int i = 0; i < arraySize; i++)
        changePattern[i] = new char[arraySize];
    transformPattern tp;
    ofstream out ;
    out.open("transform.out", std::ios::app);
    int check;
    switch (transformNum){
    case 1:
        changePattern = tp.rotateArray(start, arraySize);
        check = tp.check(changePattern, end, arraySize);
        if (check == 0){
            out << 1 << endl;
            return 0;
        }
        break;
    case 2:
        changePattern = tp.rotateArray(start, arraySize);
        changePattern = tp.rotateArray(changePattern, arraySize);
        check = tp.check(changePattern, end, arraySize);
        if (check == 0){
            out << 2 << endl;
            return 0;
        }
        break;
    case 3:
        changePattern = tp.rotateArray(start, arraySize);
        changePattern = tp.rotateArray(changePattern, arraySize);
        changePattern = tp.rotateArray(changePattern, arraySize);
        check = tp.check(changePattern, end, arraySize);
        if (check == 0){
            out << 3 << endl;
            return 0;
        }
        break;
    case 4:
        changePattern = tp.flipArray(start, arraySize);
        check = tp.check(changePattern, end, arraySize);
        if (check == 0){
            out << 4 << endl;
            return 0;
        }
        break;
    case 5:
        changePattern = tp.flipArray(start, arraySize);
        if (tp.changeArray(changePattern, end, arraySize, 1)==0){
            out.close();
            out.open("transform.out", std::fstream::out | std::fstream::trunc);
            out << 5 << endl;
            return 0;
        }
        if (tp.changeArray(changePattern, end, arraySize, 2)==0){
            out.close();
            out.open("transform.out", std::fstream::out | std::fstream::trunc);
            out << 5 << endl;
            return 0;
        }
        if (tp.changeArray(changePattern, end, arraySize, 3)==0){
            out.close();
            out.open("transform.out", std::fstream::out | std::fstream::trunc);
            out << 5 << endl;
            return 0;
        }
        break;
    case 6:
        changePattern = start;
        check = tp.check(changePattern, end, arraySize);
        if (check == 0){
            out << 6 << endl;
            return 0;
        }
        break;
    case 7:
        out << 7 << endl;
        return 0;
    }
    out.close();
}

int main()
{
    ifstream fin ("transform.in");
    ofstream fout ("transform.out");
    fout << "";
    int arraySize;
    fin >> arraySize;

    char **startPattern = new char*[arraySize];
    for(int i = 0; i < arraySize; i++)
        startPattern[i] = new char[arraySize];

    char **endPattern = new char*[arraySize];
    for(int i = 0; i < arraySize; i++)
        endPattern[i] = new char[arraySize];

    char **changePattern = new char*[arraySize];
    for(int i = 0; i < arraySize; i++)
        changePattern[i] = new char[arraySize];

    for (int i = 0; i<arraySize; i++){
        fin >> startPattern[i];
    }
    for (int i = 0; i<arraySize; i++){
        fin >> endPattern[i];
    }
    transformPattern tp;
    for (int i = 1; i<8; i++){
        if (tp.changeArray(startPattern, endPattern, arraySize, i)==0){
            return 0;
        }
    }

    return 0;
}
