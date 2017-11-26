#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct bank{
    string name;
    double amount;
};

int main() {
    int payers;
    ifstream inFile;
    inFile.open("donators.txt",ios::in);
    if(!inFile.is_open()){
        cout << "Niepowodzenie" << endl;
        exit(EXIT_FAILURE);
    }

    bank *p_payer = new bank [payers];
    bool var = false;
    inFile >> payers;
    string value;
    cout << "Payers: " << payers << endl;
    for(int i = 0; i < payers; i++ ){
        getline(inFile,value);
        getline(inFile,p_payer[i].name);
        p_payer[i].amount = atoi(value.c_str());
        cout << "Name: " << p_payer[i].name << " Amount:" << p_payer[i].amount << endl;
    }

    int count = 0;
    cout << "Wspaniali sponsorzy: "<<endl;
    for(int i = 0 ; i < payers; ++i){
        if(p_payer[i].amount >= 10000){
            cout << p_payer[i].amount << " - " << p_payer[i].name << endl;
            ++count;
        }
    }
    cout << "Nasi sponsorzy: "<<endl;
    if(count)
        for(int i = 0 ; i < payers; ++i){
            cout << p_payer[i].amount << " - " << p_payer[i].name << endl;
            ++count;
        }
    else
        cout << "Brak";


    delete [] p_payer;
    return 0;
}

