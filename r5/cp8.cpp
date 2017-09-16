#include <iostream>
#include <array>
#include <cstdio>
#ifndef EOF
#define EOF (-1)
#endif
#include <cstring>
using namespace std;

int main()
{
    /*string text;
    char buffer[30];
    int ch,words;
    cout << "Podaj slowa kiedy skonczysz napisz gotowe" << endl;
    while (strcmp(buffer,"gotowe") && (ch = cin.get()) != -1){
        cin.getline(buffer,30);
        text += buffer;
        if(strcmp(buffer,"gotowe")) words++;
    }
    cout << "Podano: " << words << "slow";
    */

    int i = 0;
    char slowo[ 250 ] = "";
    while( strcmp( slowo, "gotowe" ) ) {
        scanf( "%s", slowo );
        ++i;
    }
    printf( "%d\n", i - 1 );
    return 0;
}
