#ifndef CD_H_INCLUDED
#define CD_H_INCLUDED
#include <iostream>
#include <cstring>

class Cd
{
    char performers[50];
    char label[20];
    int selections;
    double playtime;
public:
    Cd(char * s1, char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    ~Cd() {}
    virtual void Report() const;
    Cd & operator=(const Cd & d);
};

#endif // CD_H_INCLUDED
