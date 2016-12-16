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

class namenum {
public:
    void createCombos(int, int, char[20]);
    char combos[531500][20];
    int max;
    char keyboard[8][3][2] = {{"A","B","C"},{"D","E","F"},{"G","H","I"},{"J","K","L"},{"M","N","O"}, {"P","R","S"}, {"T","U","V"}, {"W","X","Y"}};
};

int main()
{
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream finDict ("dict.txt");
    char dict[5000][20];
    char number[20];
    for (int i=0; i<5000; i++){
        finDict >> dict[i];
    }
    fin >> number;
    int max =0;
    nn namenum;
    nn.createCombos(0,0,number);
    int count;
    for (int i =0; i<pow(3,strlen(number)); i++)(
        char tmp;
        int count = 0;
        while(combos[i] != tmp){
            tmp = dict[count];
            count++
        }

    )
    return 0;
}

namenume::createCombos(int a, int loc,  char[20] number){
    for (int i =1; i<4; i++){}
        strcpy(combos[a], combos[max])
        combos[max][loc] = keyboard[number[loc]][i];
        if (loc=!strlen(number)){
            createCombos(max,loc+1,number);
        }
        max++;
    }
}
