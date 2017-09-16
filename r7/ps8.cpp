#include <iostream>

using namespace std;

int replace(char * str, char c1, char c2);

int main()
{
    char * str = "Co tam u ciebie";
    cout<<"Przed replace";
    int replaces = replace(str,' ','-');
    cout<<"Po";
    return 0;
}

int replace(char * str, char c1, char c2){
    int swaps = 0;
    while(*str){
        if(*str == c1){
            *str = c2;
            ++swaps;
        }
        ++str;
    }
    return swaps;
}
