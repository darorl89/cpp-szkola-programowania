#include "cd.h"


using std::cout;
using std::endl;

Cd::Cd(char * s1, char * s2, int n, double x)
{
    strncpy(performers,s1,50);
    strncpy(label,s2,20);
    selections = n;
    playtime = x;
}

Cd::Cd()
{
    strncpy(performers,"",50);
    strncpy(label,"",20);
    selections = 0;
    playtime = 0.0;
}

Cd::Cd(const Cd & d)
{
    strncpy(performers,d.performers,50);
    strncpy(label,d.label,20);
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
    strncpy(performers,d.performers,50);
    strncpy(label,d.label,20);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}
