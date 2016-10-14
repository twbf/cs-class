/*
ID: twbuele1
LANG: C++
PROG: gift1
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int getId(char, char);

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    // variables
    int numberPeople, i = 0;
    char people[25][25] = {};
    int personId = 0;
    int money[25] = {}, moneyGived;
    char giftee[25];

    //get people
    fin >> numberPeople;
    while(i<=numberPeople-1){
        fin >> people[i];
        i++;
    }

    // for each giver loop
    i=0;
    while(i<numberPeople){
        int numGiftees = 0, j=0;
        char giver[25];
        fin >> giver;
        fin >> moneyGived;
        fin >> numGiftees;

        // get person ID matching
        personId=0;
        for(int h=0; h<25; h++){
            if(!(strcmp(giver, people[h]))){
                personId = h;
            }
        }
        if (numGiftees!=0) {
            money[personId]-=moneyGived-(moneyGived%numGiftees);
        }
        while(j<numGiftees){
            fin >> giftee;
            personId = 0;
            for(int h=0; h<25; h++){
                if(!(strcmp(giftee, people[h]))){
                    personId = h;
                }
            }
            money[personId] += moneyGived/numGiftees;
            j++;
        }
        i++;
    }

    //Out put person and money
    for(int h=0; h<=numberPeople-1; h++){
        fout << people[h] << ' ' << money[h] << endl;
    }
    return 0;
}
