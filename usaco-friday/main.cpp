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
    ifstream sfin ("friday.in");
    int daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day, date;
    int count13[7] = {};
    int endYear;
    cin << endYear;
    endYear += 1899;
    for (int i = 1900; i < endYear; i++){
        for (int j = 0; j<12; j++){
            for (int h = 1; h <= daysInMonth[j]; h++){
                if (h==13){
                    count13[day]++;
                }
            }
        }
    }
    for (int i=0; i<7; i++){
        fout << count13[day] << ' ';
    }
    return 0;
}
