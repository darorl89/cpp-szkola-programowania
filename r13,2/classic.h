#ifndef CLASSIC_H_INCLUDED
#define CLASSIC_H_INCLUDED
#include "cd.h"
using std::cout;
using std::endl;

class Classic : public Cd
{
    char * single;
public:
    Classic(char * s1, char * s3, char * s2, int n, double x) : Cd(s1,s2,n,x)
    {
        single = new char [strlen(s1) + 1];
        strcpy(single,s3);
    }
    Classic()
    {
        single = new char [1];
        strcpy(single,"");
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
    single = new char [strlen(c.single) + 1];
    strcpy(single,c.single);
    return *this;
    }
};

#endif // CLASSIC_H_INCLUDED
