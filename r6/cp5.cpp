
#include <iostream>

using namespace std;

int main() {

    double money,start,tax;
    money = tax = start = 0;
    cout << "Podaj swoj majatek: ";
    while(cin>>money && money >= 0){
        start = money;
        double range;
        if(money > 35000){
            range = money - 35000;
            tax = range * 0.20;
            money = 35000;
            cout << "Range >35k: " << range << endl;
        }
        cout << "Money: " << money << endl;
        if(money > 15000){
            range = money - 15000;
            tax += range * 0.15;
            money = 15000;
            cout << "Range >15k: " << range << endl;
        }
        if(money > 5000){
            range = money - 5000;
            tax+= range * 0.1;
            money = 5000;
            cout << "Range >5k: " << range << endl;
        }
        if(money <= 5000){
            range = money;
            tax += 0;
            cout << "Range <5k: " << range << endl;
        }
    cout << "Oto twoje netto: " << start - tax << " i podatek: " << tax << endl;
    cout << "Podaj swoj majatek: ";
    }
    return 0;
}

