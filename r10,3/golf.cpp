#include "golf.h"
Golf & Golf::operator=(Golf & g)
{
    strncpy(fname, g.fname, LEN);
    handicap = g.handicap;
    return *this;
}

void Golf::showgolf() const
{
    cout << fname << ", handicap: " << handicap << endl;
}
