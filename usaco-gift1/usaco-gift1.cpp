/*
ID: twbuele1
LANG: C++
PROG: gift1
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getId(char, char);

int main()
{
    //ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int numberPeople, i = 0;
    char people[25][25];
    fin >> numberPeople;
    while(i<=numberPeople-1){
        fin >> people[i];
        cout << people[i] << endl;
        i++;
    }
    i=0;
    int money[10], moneyGived;
    char giver[25];
    while(i<=numberPeople-1){
        int numGiftees = 0, j=0;
        fin >> giver;
        fin >> moneyGived;
        fin >> numGiftees;
        money[i]-=moneyGived-(moneyGived%numGiftees);
        while(j<=numGiftees){
            char giftee[25];
            fin >> giftee;
            money[getId(giftee, people)] = moneyGived%numGiftees;
            j++;
        }
    }
    return 0;
}

int getId(char[25] giftee, char[25][25] people){
    for(int i=0; i<=20; i++){
        if(giftee == people[i]){
            return i;
        }
    }
}
