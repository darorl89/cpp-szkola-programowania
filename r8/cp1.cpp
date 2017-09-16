#include <iostream>

using namespace std;

void show(char * str, bool n = false);

int main()
{
    show("Cos");
    show("Cos");
    show("Cos");
    show("Cos");
    show("Cos",1);
    return 0;
}

void show(char * str, bool n){
    static int func_calls = 0;
    if(n){
        ++func_calls;
    }
    cout << str << ", Called: " << func_calls << endl;
}
