/*
ID: twbuele1
LANG: C++
PROG: ride
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <string.h>

using namespace std;

int main()
{
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream finDict ("dict.txt");
    char keyboard[8][3][2] = {{"A","B","C"},{"D","E","F"},{"G","H","I"},{"J","K","L"},{"M","N","O"}, {"P","R","S"}, {"T","U","V"}, {"W","X","Y"}};
    char dict[5000][5];
    char number[20];
    for (int i=0; i<5000; i++){
        finDict >> dict[i];
    }
    fin >> number;
    for (int i =0; i<pow(3,strlen(number)); i++)(
        
    )
    return 0;
}
