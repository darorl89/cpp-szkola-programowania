#ifndef GOLF_H_INCLUDED
#define GOLF_H_INCLUDED

#include <cstring>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class Golf
{
    static const int LEN = 40;
    char fname[LEN];
    int handicap;
public:
    Golf(const char * name = "UNDEFINED",const int hc = 0){strncpy(fname,name,LEN);handicap = hc;}
    Golf & operator=(Golf & g);
    void sethandicap(int hc) {handicap = hc;}
    void showgolf() const;
};


#endif // GOLF_H_INCLUDED
