/*  Thomas Bueler    Alpha Sort

This sorts words using the strcmp function with the algoritheam being selection
sort because I think that its the esiest to program. The size variable up top
determines how many words you cin. It is actualy a vary simple if you know about
strcmp.
*/

#include <iostream>
#include <string.h>
#include <ctype.h>
#define SIZE 5

using namespace std;

int getCharNum(char);
void sort();

char words[40][20] = {};

int main()
{
    char word[20] = {};
    for (int j = 0; j < SIZE; j++){
        cin >> word;
        for(int i = 0; i<strlen(word); i++){
            word[i] = tolower(word[i]);
        }
        strcpy(words[j], word);
    }
    sort();
    cout << "\nSorted Words \n";
    for (int j = 0; j < SIZE; j++){
        cout << words[j] << endl;
    }
    return 0;
}

void sort(){
    int index;
    char min[20], tmp[20];
    for(int i = 0; i<SIZE; i++){
        strcpy(min, words[i]);
        //cout << min << endl;
        for(int j = i; j<SIZE; j++){
            if (strcmp(min, words[j])>0){
                strcpy(min, words[j]);
                index = j;
            }
        }
        if (strcmp(min, words[i]) == 0){
            index = i;
        }
        strcpy(tmp, words[i]);
        strcpy(words[i], words[index]);
        strcpy(words[index], tmp);
    }
}

/*
thomas@thomas-gazelle:~/git/cs-class/alpha-sort$ ./main
the
that
you
on
thomas

Sorted Words
on
that
the
thomas
you
thomas@thomas-gazelle:~/git/cs-class/alpha-sort$
*/
