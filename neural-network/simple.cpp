#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double nonlin(double,bool);

using namespace std;

int main(){
    ofstream fout ("simple.out");
    ifstream fin ("simple.test.in");
    srand(time(0));
    double layer1[3];
    double output;
    double error;
    double delta;
    int inputs[3][3];
    for (int i= 0; i<3; i++){
        layer1[i]=rand() / double(RAND_MAX)-0.5;
        cout << layer1[i] << endl;
    }
    int numTests;
    double correctOutput[3];
    fin >> numTests;
    for (int j = 0; j<numTests; j++){
        for (int i = 0; i<numTests; i++){
            fin >> inputs[j][i];
        }
        fin >> correctOutput[j];
    }
    for (int h = 0; h < 5000; h++){
        for (int j = 0; j<numTests; j++){
            double sum;
            for (int i = 0; i<3; i++){
                sum += inputs[j][i] * layer1[i];
            }
            output = nonlin(sum,false);
            error = output - correctOutput[j];
            //cout << error << endl;
            delta = error * nonlin (output, true);
            for (int i = 0; i<3; i++){
                layer1[i]+=delta;
            }
            //cout << output << endl;
        }
    }
}

double nonlin(double input, bool der){
    if (der){
        return input*(input-1);
    }
    return 1/(1+pow(2,-input));
}
