#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "game.h"

using namespace std;

int main (){
     rules o;
     o.black = 0;
     for(int i=0; i<1000; i++){
         o.next(true);
         o.play();
     }
     cout << o.black << endl;
 }
