#include <iostream>
#include <array>
using namespace std;

int main()
{
    int number,sum;
    number = sum = 0;
    cout << "0 przerywa program" << endl;
    do{
        cout << "Podaj liczbe: ";
        cin >> number;
        sum += number;
    }while(number != 0);
    cout<<"Suma podanych liczb wynosi: " << sum;
    return 0;
}
