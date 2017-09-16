#ifndef CLASSIC_H_INCLUDED
#define CLASSIC_H_INCLUDED
#include "cd.h"
using std::cout;
using std::endl;

class Classic : public Cd
{
    char single[30];
public:
    Classic(char * s1, char * s3, char * s2, int n, double x) : Cd(s1,s2,n,x)
    {
        strncpy(single,s3,30);
    }
    Classic()
    {
        strncpy(single,"",30);
    }
    void Report() const
    {
        Cd::Report();
        cout << "Singiel: " << single << endl;
    }
    Classic & operator=(const Classic & c)
    {
    if (this == &c)
        return *this;
    Cd::operator=(c);
    strncpy(single,c.single,30);
    return *this;
    }
};

#endif // CLASSIC_H_INCLUDED
