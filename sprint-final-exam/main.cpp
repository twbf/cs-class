/*  Project: Sprint Final Exam
    Name: Thomas Bueler
    Date: 12/6/16

    Description: This program provides a user interface to decide which sprint
    phone plan is right for you. Each plan is a function that takes how many
    minutes you think you will need and returns the cost. You can compare plans
    or choose a specific plan to identify the cost. 
*/

#include <iostream>

using namespace std;

class callingPlans{
public:
    double s7(int);
    double s500(int);
    double s1000(int);
    double s5night(int);
    double switchPlans(int, int);
    void planName(int);
};

main () {
    callingPlans cp;
    int plan;
    int minutes;
    cout << "Welcome to Thomas's sprint calling plan guide. Are you interested in: \n (1) a specific plan \n (2) a comparison of all plans \n\nSelect an option: ";
    cin >> plan;
    if (plan == 1){
        int callingPlan;
        cout << "Which plan are you interested in? \n (1)";
        cp.planName(1);
        cout  << "\n (2)";
        cp.planName(2);
        cout << "\n (3)";
        cp.planName(3);
        cout << "\n (4)";
        cp.planName(4);
        cout << "\n\nSelect an option: ";
        cin >> callingPlan;
        if (0<callingPlan<5){
            cout << "How many minutes do you forsee using each month? ";
            cin >> minutes;
            cout << "\nYour bill would be: $" << cp.switchPlans(minutes, callingPlan) << " using ";
            cp.planName(callingPlan);
            cout << endl;
        }
        else {
            cout << "Not a valid calling plan. Exiting ..." << endl;
        }
    }
    else if (plan == 2){
        cout << "How many minutes do you forsee using each month? ";
        cin >> minutes;
        cout << "\nYour bill would be (before tax and such):\n";
        for (int i = 1; i < 5; i++){
            cout << "\n$" << cp.switchPlans(minutes, i) << " using";
            cp.planName(i);
        }
        cout << "\n";
    }
    else {
        cout << "Not a valid plan. Exiting ..." << endl;
    }
}

void callingPlans::planName(int plan){
    switch (plan){
    case 1:
        cout << " Sprint 7 cents Anytime";
        break;
    case 2:
        cout << " Sprint 500 Anytime";
        break;
    case 3:
        cout << " Sprint 1000 Anytime";
        break;
    case 4:
        cout << " Sprint 5 cents nights";
        break;
    }
}

double callingPlans::switchPlans(int x, int plan){
    callingPlans cp;
    switch (plan){
    case 1:
        return cp.s7(x);
    case 2:
        return cp.s500(x);
    case 3:
        return cp.s1000(x);
    case 4:
        return cp.s5night(x);
    }
}

double callingPlans::s7(int x){
    double money = 5.95 + 0.07*x;
    return money;
}

double callingPlans::s500(int x){
    double money = 0;
    if (x>500){
        money = (x-500)*.10;
    }
    money+=25;
    return money;
}

double callingPlans::s1000(int x){
    double money = 0;
    if (x>1000){
        money = (x-1000)*.10;
    }
    money+=40;
    return money;
}

double callingPlans::s5night(int x){
    double money = 8.95 + 0.05*x;
    return money;
}
