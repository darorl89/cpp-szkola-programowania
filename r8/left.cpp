// tempover.cpp -- przeci¹¿anie szablonów
#include <iostream>

unsigned long left(unsigned long number, int n){
    int digits = 1;
    unsigned long temp = number;
    while (temp /= 10){
        ++digits;
    }
    if (number == 0 || n == 0)
        return 0;
    else{
        n = digits - n;
        while (n--)
            number /= 10;
        return number;
    }

}

int main()
{
    using namespace std;
    cout << left(29,1);
    return 0;
}
