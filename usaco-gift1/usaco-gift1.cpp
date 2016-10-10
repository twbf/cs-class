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
    int personId = 0;
    fin >> numberPeople;
    while(i<=numberPeople-1){
        fin >> people[i];
        i++;
    }
    i=0;
    int money[10] = {}, moneyGived;
    char giver[25];
    while(i<=numberPeople-2){
        //cout << numberPeople;
        int numGiftees = 0, j=0;
        fin >> giver;
        fin >> moneyGived;
        fin >> numGiftees;
        for(int h=0; h<=20; h++){
            if(giver == people[h]){
                personId = h;
            }
        }
        cout << personId;
        money[personId]-=moneyGived-(moneyGived%numGiftees);
        //cout << money[i] << endl;
        while(j<=numGiftees-1){
            char giftee[25];
            fin >> giftee;
            for(int h=0; h<=20; h++){
                if(giftee == people[h]){
                    personId = h;
                }
            }
            //cout << numberPeople;
            money[personId] += moneyGived/numGiftees;
            //cout << people[i] << ' ' << money[i] << endl;
            //cout << personId << endl;
            //cout << money[personId] << endl;
            //cout << moneyGived << endl;
            //cout << numGiftees << endl;
            j++;
        }
        i++;
    }
    for(int h=0; h<=numberPeople; h++){
        cout << people[h] << ' ' << money[h] << endl;
    }
    return 0;
}
