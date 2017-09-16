#ifndef PLORG_H_INCLUDED
#define PLORG_H_INCLUDED
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;


class Plorg
{
    static const int NAMEMAX = 19;
    char name[NAMEMAX];
    int fulness;
public:
    Plorg(const char * pname = "Plorga", int pful = 50);
    void setFulness(int pful);
    void showPlorg() const;
};


#endif // PLORG_H_INCLUDED
