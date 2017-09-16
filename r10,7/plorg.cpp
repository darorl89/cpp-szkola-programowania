#include "plorg.h"

Plorg::Plorg(const char * pname, int pful)
{
    strncpy(name,pname,NAMEMAX);
    fulness = pful;
}
void Plorg::setFulness(int pful)
{
    fulness = pful;
}
void Plorg::showPlorg() const
{
    cout << "Plorg betelgeski: " << endl;
    cout << "Imie: " << name << ", sytosc: " << fulness << endl;
}
