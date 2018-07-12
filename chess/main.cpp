#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "game.h"

using namespace std;

int main (){
     rules o;
     o.next();
     o.play();
     o.printBoard();
     o.printMoves();
 }
