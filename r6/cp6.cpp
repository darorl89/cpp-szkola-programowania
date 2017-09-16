
#include <iostream>

using namespace std;

struct bank{
    string name;
    double amount;
};

int main() {
    int payers;
    cout << "Podaj liczbe wplacajacych: ";
    cin >> payers;
    bank *p_payer = new bank [payers];
    for (int i = 0; i < payers; i++){
        cout << "Nazwisko: ";
        cin >> p_payer[i].name;
        cout << "Kwota: ";
        cin >> p_payer[i].amount;
    }
    int count = 0;
    cout << "Wspaniali sponsorzy: "<<endl;
    for(int i = 0 ; i < payers; i++){
        if(p_payer[i].amount >= 10000){
            cout << p_payer[i].amount << " - " << p_payer[i].name << endl;
            count++;
        }
    }
    if(!count)
        cout << "Brak";
        cout << "Nasi sponsorzy: "<<endl;
    for(int i = 0 ; i < payers; i++){
            cout << p_payer[i].amount << " - " << p_payer[i].name << endl;
            count++;
        }
    delete [] p_payer;
    if(!count)
        cout << "Brak";
    return 0;
}

