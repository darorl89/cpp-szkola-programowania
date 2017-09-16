#include "golf.h"
Golf & Golf::operator=(Golf & g)
{
    Golf newg;
    strncpy(newg.fname,g.fname,LEN);
    newg.handicap = g.handicap;
    return *this;
}
