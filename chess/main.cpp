#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "game.h"

using namespace std;

int main (){
     rules o;
     for(int i=0; i<10; i++){
         o.next(true);
         o.play();
     }
 }
