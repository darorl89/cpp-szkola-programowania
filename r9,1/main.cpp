#include <iostream>
#include "golf.h"

extern const int cLen;
extern const int ctabSize;

using namespace std;

int main()
{
    char name[cLen];
    golf players[ctabSize] {"",0};
    int hc;
    bool loop = true;
    cout << "Podawaj nazwiska oraz handicapy graczy..." << endl;
    while(loop)
    {
        loop = menu(players,ctabSize);
    }
    return 0;
}
