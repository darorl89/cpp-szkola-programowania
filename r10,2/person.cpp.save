#include "person.h"
#include <cstring>
using std::cout;
using std::endl;
using std::string;

Person::Person(const string & ln, const char* fn)
{
    lname = ln;
    strncpy(fname,fn,LIMIT);
}
void Person::show() const
{
    cout << "Imie: " << fname << ", nazwisko: " << lname << endl;
}
void Person::formalShow() const
{
    cout << "Nazwisko: " << lname << ", imie: " << fname << endl;
}
