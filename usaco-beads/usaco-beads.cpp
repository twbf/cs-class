/*
ID: twbuele1
LANG: C++
PROG: beads
*/

#include <iostream>
#include <fstream>
#include <string>

int loopingString (char, char);

using namespace std;

int main()
{
    ofstream fout ("beads.out");
    if (loopingString('b', 'r') > loopingString('r', 'b')){
        fout << loopingString('b', 'r') << endl;
    }
    else {
        fout << loopingString('r', 'b') << endl;
    }
    return 0;
}

int loopingString (char a, char b){
    ifstream fin ("beads.in");
    int numBeads;
    char beads[370];
    fin >> numBeads >> beads;
    int maxBeads = 0, start, cmaxBeads = 0, wCounter = 0;
    char prevChar[10] = {};
    prevChar[0] = beads[0];
    for (int j = 0; j<3; j++) {
        if (j == 0){
            start = 1;
        }
        else {
            start = 0;
        }
        for (int i = start; i < numBeads; i++){
            if (prevChar[0] == a && beads[i] == b){
                cmaxBeads = wCounter;
            }
            else {
                cmaxBeads++;
                if (cmaxBeads > maxBeads){
                    maxBeads = cmaxBeads;
                }
            }
            if (beads[i] == a || beads[i] == b){
                prevChar[0] = beads[i];
                wCounter = 0;
            }
            else {
                wCounter++;
            }
        }
    }
    if (maxBeads>numBeads){
        maxBeads = numBeads;
    }
    else{
        maxBeads++;
    }
    return maxBeads;
}
