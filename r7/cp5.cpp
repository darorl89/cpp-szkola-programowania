#include <iostream>

using namespace std;

int factorial(int);

int main()
{
    long long fact;
    cout << "Podawaj liczby z ktorych chcesz silnie: ";
    while(cin >> fact){
        cout << factorial(fact) << endl << "Jeszcze? :";
    }
    return 0;
}

int factorial(int fact){
    if(fact < 2) return fact;
    return fact * factorial(fact-1);
}
