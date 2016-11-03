/*
ID: twbuele1
LANG: C++
PROG: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    //ofstream fout ("test.out");
    ifstream fin ("milk2.in");
    int time[2][5000];
    int numFarmers;
    fin >> numFarmers;
    for (int i = 0; i < numFarmers; i++){
        fin >> time[0][i];
        fin >> time[1][i];
    }
    for (int i = 0; i < numFarmers; i++){
        for (int j = 0; j < numFarmers; j++){
            int tmp[2] = {};
            if(time[0][j] > time [0][j+1]){
                tmp[0] = time[0][j];
                tmp[1] = time[1][j];
                time[0][j] = time[0][j+1];
                time[1][j] = time[1][j+1];
                time[0][j+1] = tmp[0];
                time[1][j+1] = tmp[1];
            }
        }
    }
    for (int i = 1; i < numFarmers +1; i++){
        cout << time[0][i] << ' ';
        cout << time[1][i] << endl;
    }
    return 0;
}

