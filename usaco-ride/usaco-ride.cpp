/*
ID: twbuele1
LANG: C++
PROG: ride
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

int getCharNum(char);

int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    char comet[20];
    char group[20];
    fin >> comet >> group;
    int sumComet = 1, sumGroup= 1;
    for (int i=0; i<strlen(comet); i++){
        sumComet = getCharNum(comet[i])*sumComet;
    }
    sumComet = sumComet%47;
    for (int i=0; i<strlen(group); i++){
        sumGroup = getCharNum(group[i])*sumGroup;
    }
    sumGroup = sumGroup%47;
    if(sumGroup==sumComet){
        fout << "GO" << endl;
    }
    else{
        fout << "STAY" << endl;
    }
    return 0;
}

int getCharNum(char letter){
    int number;
    number = (int) letter;
    number -= 64;
    return number;
}
