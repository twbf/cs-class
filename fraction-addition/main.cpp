/*Thomas Bueler
*/
#include <iostream>

int addFrac(int,int,int,int);
int reduceFrac(int,int);

using namespace std;

int main()
{
    int a, b, c, d;
    cout << "Insert a fraction in the form a 'enter' b " << endl;
    cin >> a >> b;
    cout << "Insert another fraction in the form c 'enter' d " << endl;
    cin >> c >> d;
    addFrac(a,b,c,d);
    return 0;
}

int addFrac(int a, int b, int c, int d){
    int den, num;
    den = b*d;
    num = (a*d)+(c*b);
    cout << num << "/" << den;
    reduceFrac(num, den);
    return 0;
}

int reduceFrac(int a, int b){

    return 0;
}
