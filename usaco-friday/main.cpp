/*
ID: twbuele1
LANG: C++
PROG: friday
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(){
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = 2;
    int count13[7] = {0,0,0,0,0,0,0};
    int exactDays;
    int endYear;
    fin >> endYear;
    endYear += 1900;
    for (int i = 1900; i < endYear; i++){
        for (int j = 0; j<12; j++){
            exactDays = daysInMonth[j];
            if ((i%4 == 0) && j==1){
                exactDays = 29;
            }
            if ((i%100 == 0) && j==1){
                exactDays = 28;
            }
            if ((i%400 == 0) && j==1){
                exactDays = 29;
            }
            for (int h = 1; h < exactDays + 1; h++){
                if (h == 13){
                    count13[day] += 1;
                }
                day++;
                if(day == 7){
                    day = 0;
                }
            }
        }
    }
    for (int i=0; i<7; i++){
        if (i<6){
            fout << count13[i] << ' ';
        }
        else {
            fout << count13[i] << endl;
        }
    }
    return 0;
}
