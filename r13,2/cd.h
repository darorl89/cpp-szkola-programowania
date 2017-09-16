#ifndef CD_H_INCLUDED
#define CD_H_INCLUDED
#include <iostream>
#include <cstring>

class Cd
{
    char * performers;
    char * label;
    int selections;
    double playtime;
public:
    Cd(const char * s1,const char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    ~Cd();
    virtual void Report() const;
    Cd & operator=(const Cd & d);
};

#endif // CD_H_INCLUDED
