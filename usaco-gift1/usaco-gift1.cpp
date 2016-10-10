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
    cout << numberPeople;
    while(i<=numberPeople-1){
        fin >> people[i];
        cout << people[i] << endl;
        i++;
    }
    i=0;
    cout << numberPeople;
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
            int personId;
            for(int h=0; h<=20; h++){
                if(giftee == people[h]){
                    personId = h;
                }
            }
            money[personId] = moneyGived%numGiftees;
            j++;
        }
    }
    return 0;
}
