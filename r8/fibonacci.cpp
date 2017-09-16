#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    long double fib_word,temp;
    fib_word = 0;
    temp = 1;
    while (true){
        cout << setprecision(10000);
        fib_word += temp;
        temp = fib_word - temp;
        cout << fib_word << endl;
    }
    return 0;
}
