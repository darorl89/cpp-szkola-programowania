#include <iostream>
#include <array>
#include <cstdio>
#ifndef EOF
#define EOF (-1)
#endif
using namespace std;

struct car{
    string name;
    int year;
};

int main()
{
    int rows;
    cout << "Podaj liczbe wierszy: ";
    cin >> rows;
   for(int i = 0 ; i < rows; ++i){
        for(int cols = 0; cols < rows ; ++cols){
            if (i >= rows-cols-1)
                cout.put('*');
            else
                cout.put('.');
        }
        cout<<endl;
    }
    return 0;
}
