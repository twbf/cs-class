/* Thomas Bueler  Mad Libs
*/

#include <iostream>

using namespace std;

int main()
{
    char pName[30];
    char actionVerb[2][30];
    char adverb[30];
    char nonPNoun[3][30];
    char integer[30];
    char adj[2][30];

    cout << "Enter a proper noun:" << endl;
    cin >> pName;

    cout << "Enter an action verb:" << endl;
    cin >> actionVerb[0];

    cout << "Enter an action verb:" << endl;
    cin >> actionVerb[1];

    cout << "Enter an adverb:" << endl;
    cin >> adverb;

    cout << "Enter a non-proper noun:" << endl;
    cin >> nonPNoun[0];

    cout << "Enter a non-proper noun:" << endl;
    cin >> nonPNoun[1];

    cout << "Enter a non-proper noun:" << endl;
    cin >> nonPNoun[2];

    cout << "Enter an integer:" << endl;
    cin >> integer;

    cout << "Enter an adjective:" << endl;
    cin >> adj[0];

    cout << "Enter an adjective:" << endl;
    cin >> adj[1];


    cout << "Once upon a time there was a computer science student named " << pName
    << ". He/She built a " << adj[0] <<  " program that " << actionVerb[0] <<
    ". This program changed how people lived their lives. It also changed " <<
    integer << " " << nonPNoun[0] << "s for the better. The program made the " <<
    nonPNoun[0] << "s " << adj[1] << " by always " << actionVerb[1] << ". " << pName
    << " became insanely famous after his life changing invention. So famous that " <<
    "he was hired at Apple as a " << nonPNoun[1] << " maker. He used a " << adverb << " "
    << nonPNoun[2] << " to make a " << nonPNoun[1] << endl;


    return 0;
}
