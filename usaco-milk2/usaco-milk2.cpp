/*
ID: twbuele1
LANG: C++
PROG: milk2
*/

#include <iostream>
#include <fstream>
#include <string>

void swapNum(int,int,int,int[2][5002]);

using namespace std;

int main()
{
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int time[2][5002];
    int numFarmers;
    fin >> numFarmers;
    for (int i = 0; i < numFarmers; i++){
        fin >> time[0][i];
        fin >> time[1][i];
    }
    for (int i = 0; i < numFarmers; i++){
        for (int j = numFarmers-i-1; j < numFarmers; j++){
            if(time[0][j] > time[0][j+1]){
                swapNum(j, j+1, 0, time);
                swapNum(j, j+1, 1, time);
            }
        }
    }
    int currentMilking = 0, currentNot = 0, maxMilking = 0, maxNot = 0;
    bool flag = true;

    int max = 0;
    for (int i=0; i<=numFarmers; i++){
        if (time[1][i] > max){
            max = time[1][i];
        }
    }
    int timeInBetween;
    for (int i = time[0][1]; i < max; i++){
        flag = true;
        for (int j = 0; j < numFarmers +1 && flag != false; j++){
            if ((time[0][j] <= i) && (time[1][j] > i)){
                currentNot = 0;
                timeInBetween = (time[1][j]-i);
                currentMilking += timeInBetween;
                i+= timeInBetween -1;
                if (currentMilking > maxMilking){
                    maxMilking = currentMilking;
                }
                flag = false;
            }
        }
        if (flag == true){
            currentMilking = 0;
            currentNot++;
            if (currentNot > maxNot){
                maxNot = currentNot;
            }
        }
    }

    fout << maxMilking  << " " << maxNot << endl;

    return 0;
}
void swapNum(int a, int b, int collum, int time[2][5002]){
    int tmp = time[collum][a];
    time[collum][a] = time[collum][b];
    time[collum][b] = tmp;
}
