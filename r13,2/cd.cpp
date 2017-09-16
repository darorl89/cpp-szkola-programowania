#include "cd.h"


using std::cout;
using std::endl;

Cd::Cd(const char * s1,const char * s2, int n, double x)
{
    performers = new char [strlen(s1) + 1];
    strcpy(performers,s1);
    label = new char[strlen(s2) + 1];
    strcpy(label,s2);
    selections = n;
    playtime = x;
}

Cd::~Cd()
{
    delete [] performers;
    delete [] label;
}
Cd::Cd()
{
    performers = new char [1];
    strcpy(performers,"");
    label = new char [1];
    strcpy(label,"");
    selections = 0;
    playtime = 0.0;
}

Cd::Cd(const Cd & d)
{
    performers = new char [strlen(d.performers) + 1];
    strcpy(performers,d.performers);
    label = new char [strlen(d.label) + 1];
    strcpy(label,d.label);
    selections = d.selections;
    playtime = d.playtime;
}

void Cd::Report() const
{
    cout << "Wykonawca/y: " << performers << endl;
    cout << "Wytwornia: " << label << endl;
    cout << "Liczba utworow: " << selections << endl;
    cout << "Czas utworu w minutach: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
    if (this == &d)
        return *this;
    delete [] label;
    delete [] performers;
    performers = new char [strlen(d.performers) + 1];
    strcpy(performers,d.performers);
    label = new char [strlen(d.label) + 1];
    strcpy(label,d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}
