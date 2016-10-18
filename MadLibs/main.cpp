/* Thomas Bueler  Mad Libs
*/

#include <iostream>

using namespace std;

int main()
{
    char pName[30];
    char actionVerb[2][30];
    char adverb[30];
    char nonPNouns[3][30];
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


    cout << "Once upon a time there was a computer science student named " << pName << " "


    return 0;
}
