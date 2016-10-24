/*
ID: twbuele1
LANG: C++
PROG: beads
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    //ofstream fout ("test.out");
    ifstream fin ("beads.in");
    int numBeads;
    char beads[370];
    fin >> numBeads >> beads;
    int maxBeads = 0, start;
    int cmaxBeads = 0;
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
            if (prevChar[0] == 'r' && beads[i] == 'b'){
                cout << cmaxBeads << endl;
                cmaxBeads = 0;
            }
            else {
                cmaxBeads++;
                cout << cmaxBeads << endl;
                if (cmaxBeads > maxBeads){
                    maxBeads = cmaxBeads;
                }
            }
            prevChar[0] = beads[i];
        }
    }
    cmaxBeads = 0;
    prevChar[0] = beads[0];
    for (int h = 0; h<10; h++) {
        if (h == 0){
            start = 1;
        }
        else {
            start = 0;
        }
        for (int i = start; i < numBeads; i++){
            if (prevChar[0] == 'b' && beads[i] == 'r'){
                cout << cmaxBeads << endl;
                cmaxBeads = 0;
            }
            else {
                cmaxBeads++;
                cout << cmaxBeads << endl;
                if (cmaxBeads > maxBeads){
                    maxBeads = cmaxBeads;
                }
            }
            prevChar[0] = beads[i];
        }
    }
    cout << maxBeads + 1 << endl;
    return 0;
}
