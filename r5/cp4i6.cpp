#include <iostream>
#include <array>
#include <cstdio>
using namespace std;

int main()
{
    float daphne_cash = 100;
    double daphne_rate = 0.08;
    double daphne_profit = daphne_cash * daphne_rate;
    long double cleo_cash = 100;
    float cleo_rate = 0.05;
    int months = 0;
    float arr[2][32];
    for (int i = 0 ; i<32 ; i++){
        daphne_cash += daphne_profit;
        cleo_cash = cleo_cash * (1 + cleo_rate);
        arr[0][i] = daphne_cash;
        arr[1][i]  = cleo_cash;
        if (cleo_cash < daphne_cash)
            months++;
        cout << "Miesiac " << i << endl;
        printf("Daphne: \t %.2f \t Cleo: \t %.2f",arr[0][i],arr[1][i]);
        cout<<endl;
    }
    cout << "Cleo wyprzedzil Daphne po: " << months << " miesiacach";
    //delete [2][] p_array;
    return 0;
}
