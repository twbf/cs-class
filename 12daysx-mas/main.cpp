/* 12 Days Of Christmas   Thomas Bueler

This program sings the song of 12 days of Christmas using 2 for loops that are connected
using a variable. That then calls a function that has a switch statement. An extremely
simple program.
*/
#include <iostream>

using namespace std;

void singSong(int);

main (){
    for(int i=1; i<13; i++){
        cout << "On the " << i << " day of Christmas \nmy true love sent to me:" << endl;
        for (int j=i; j>0; j--){
            singSong(j);
        }
        cout << endl;
    }
}

void singSong(int h){
    switch (h){
    case 1:
        cout << "A Partridge in a Pear Tree" << endl;
        break;
    case 2:
        cout << "Two Turtle Doves" << endl;
        break;
    case 3:
        cout << "Three French Hens" << endl;
        break;
    case 4:
        cout << "Four Calling Birds" << endl;
        break;
     case 5:
        cout << "Five Golden Rings" << endl;
        break;
     case 6:
        cout << "Six Geese a Laying" << endl;
        break;
     case 7:
        cout << "Seven Swans a Swimming" << endl;
        break;
     case 8:
        cout << "Eight Maids a Milking" << endl;
        break;
     case 9:
        cout << "Nine Ladies Dancing" << endl;
        break;
     case 10:
        cout << "Ten Lords a Leaping" << endl;
        break;
     case 11:
        cout << "Eleven Pipers Piping" << endl;
        break;
     case 12:
        cout << "12 Drummers Drumming" << endl;
        break;
    }

}

/*
On the 1 day of Christmas
my true love sent to me:
A Partridge in a Pear Tree

On the 2 day of Christmas
my true love sent to me:
Two Turtle Doves
A Partridge in a Pear Tree

On the 3 day of Christmas
my true love sent to me:
Three French Hens
Two Turtle Doves
A Partridge in a Pear Tree

On the 4 day of Christmas
my true love sent to me:
Four Calling Birds
Three French Hens
Two Turtle Doves
A Partridge in a Pear Tree

On the 5 day of Christmas
my true love sent to me:
Five Golden Rings
Four Calling Birds
Three French Hens
Two Turtle Doves
A Partridge in a Pear Tree

On the 6 day of Christmas
my true love sent to me:
Six Geese a Laying
Five Golden Rings
Four Calling Birds
Three French Hens
Two Turtle Doves
A Partridge in a Pear Tree

On the 7 day of Christmas
my true love sent to me:
Seven Swans a Swimming
Six Geese a Laying
Five Golden Rings
Four Calling Birds
Three French Hens
Two Turtle Doves
A Partridge in a Pear Tree

On the 8 day of Christmas
my true love sent to me:
Eight Maids a Milking
Seven Swans a Swimming
Six Geese a Laying
Five Golden Rings
Four Calling Birds
Three French Hens
Two Turtle Doves
A Partridge in a Pear Tree

On the 9 day of Christmas
my true love sent to me:
Nine Ladies Dancing
Eight Maids a Milking
Seven Swans a Swimming
Six Geese a Laying
Five Golden Rings
Four Calling Birds
Three French Hens
Two Turtle Doves
A Partridge in a Pear Tree

On the 10 day of Christmas
my true love sent to me:
Ten Lords a Leaping
Nine Ladies Dancing
Eight Maids a Milking
Seven Swans a Swimming
Six Geese a Laying
Five Golden Rings
Four Calling Birds
Three French Hens
Two Turtle Doves
A Partridge in a Pear Tree

On the 11 day of Christmas
my true love sent to me:
Eleven Pipers Piping
Ten Lords a Leaping
Nine Ladies Dancing
Eight Maids a Milking
Seven Swans a Swimming
Six Geese a Laying
Five Golden Rings
Four Calling Birds
Three French Hens
Two Turtle Doves
A Partridge in a Pear Tree

On the 12 day of Christmas
my true love sent to me:
12 Drummers Drumming
Eleven Pipers Piping
Ten Lords a Leaping
Nine Ladies Dancing
Eight Maids a Milking
Seven Swans a Swimming
Six Geese a Laying
Five Golden Rings
Four Calling Birds
Three French Hens
Two Turtle Doves
A Partridge in a Pear Tree


Process returned 0 (0x0)   execution time : 0.220 s
Press any key to continue.
*/
