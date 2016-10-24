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
    int maxBeads = 0;
    int cmaxBeads = 1;
    char prevChar[10] = {};
    prevChar[0] = beads[0];
    for(int i = 1; i < numBeads; i++){
        if ((prevChar[0] == 'w' || prevChar[0] == 'b') && (beads[i] == 'w' || beads[i] == 'b')){
            cmaxBeads++;
            if (cmaxBeads > maxBeads){
                maxBeads = cmaxBeads;
            }
        }
        else {
            cmaxBeads = 1;
        }
        prevChar[0] = beads[i];
    }
    cout << maxBeads << endl;
    return 0;
}
