#include <iostream>

using namespace std;

class callingPlans{
private:
    double s7(int);
    double s500(int);
    double s1000(int);
    double s5night(int);
};

main () {
    int plan;
    cout << "Welcome to Thomas's sprint calling plan guide. Are you interested in: \n (1) a pecific plan \n (2) a comparison of all plans \n\nSelect an option: ";
    cin >> plan;
    if (plan == 1){

    }
    else if (plan == 2){

    }
    else {
        cout << "Not a valid plan. Exiting ..." << endl;
    }
}

double s7(int x){
    double money = 5.95 + 0.07*x;
    return money;
}

double s500(int x){
    double money = 0;
    if (x>500){
        money = (x-500)*10;
    }
    money+=25;
    return money;
}

double s1000(int x){
    double money = 0;
    if (x>1000){
        money = (x-1000)*10;
    }
    money+=40;
    return money;
}

double s5night(int x){
    double money = 8.95 + 0.05*x;
    return money;
}
