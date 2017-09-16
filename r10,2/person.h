#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <cstring>
#include <iostream>
using std::string;
class Person
{
    static const int LIMIT = 256;
    string lname;
    char fname[LIMIT];
public:
    Person() {lname = ""; fname[0] = '\0';}
    Person(const string & ln, const char * fn = "HejTy");
    void show() const;
    void formalShow() const;
};


#endif // PERSON_H_INCLUDED
