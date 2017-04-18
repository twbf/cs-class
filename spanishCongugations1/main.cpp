
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    ofstream fout ("words.out");
    ifstream fin ("words.in");
    int numWords;
    fin >> numWords;
    for (int i = 0; i<numWords; i++){
        char word[30], definition[30], letter[5];
        int place;
        fin >> word >> definition >> place >> letter;
        fout << " " << word << " - to " << definition << "\n";
        for (int i =0; i<45; i++){
            fout << "_";
        }
        std::string stemChange = "";
        std::string l = letter;
        if (l.compare("e")==0){
            stemChange = "ie";
        }
        if (l.compare("u")==0){
            stemChange = "ue";
        }
        if (l.compare("i")==0){
            stemChange = "i";
        }

        std::string s = word;
        std::string stem = "";
        std::string end = s.substr(strlen(word)-2, strlen(word));
        stem = "";
        stem = s.substr(0, place-1);
        stem+=stemChange;
        stem+=s.substr(place, strlen(s.c_str())-place-2);
        s = s.substr(0, strlen(word)-2);

        std::string con[6];
        if (end.compare("ar")==0){
            con[0].assign("o",1);
            con[1].assign("as",2);
            con[2].assign("a",1);
            con[3].assign("amos",4);
            con[4].assign("ais",3);
            con[5].assign("an",2);
        }
        if (end.compare("ir")==0){
            con[0].assign("o",1);
            con[1].assign("es",2);
            con[2].assign("e",1);
            con[3].assign("imos",4);
            con[4].assign("is",2);
            con[5].assign("en",2);
        }
        if (end.compare("er")==0){
            con[0].assign("o",1);
            con[1].assign("es",2);
            con[2].assign("e",1);
            con[3].assign("emos",4);
            con[4].assign("eis",3);
            con[5].assign("en",2);
        }
        int spacel = strlen(word);
        spacel += 12;
        fout <<"\n yo\t\t" << stem << setw(6) << left << con[0] << "|\tnosotros\t" << s << con[3] << "\n";
        for (int i =0; i<45; i++){
            fout << "_";
        }
        fout << "\n tu\t\t" << stem << setw(6) << con[1] << "|\tvosotros\t" << s << con[4] << "\n";
        for (int i =0; i<45; i++){
            fout << "_";
        }
        fout << "\n ud.\t" << stem << setw(6) << con[2] << "|\tuds.\t\t" << stem << con[5]  << "\n" << setw(spacel) << " el "<<"|\tellas \n" << setw(spacel) << " ella" << "|\tellos \n" << setw(spacel) << " (S.S.) "<<"|\t(P.S.) \n\n\n";
    }
    return 0;
}
