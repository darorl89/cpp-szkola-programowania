#include <cow.h>
#include <cstring>
#include <iostream>
Cow::Cow()
{
    name[0] = '\0';
    hobby[0] = '\0';
    weight = 0;
}
Cow::Cow(const char * nm, const char * ho, double wt)
{
    strcpy(name,nm);
    hobby = new char [strlen(ho)+1];
    strcpy(hobby,ho);
    weight = wt;
}
Cow::Cow(const Cow &c)
{
    Cow(c.name,c.hobby,c.weight);
}
Cow::~Cow()
{
    delete [] hobby;
}
Cow &  Cow::operator=(const Cow & c)
{
    if(this == &c)
        return *this;
    delete [] hobby;
    strcpy(name,c.name);
    hobby = new char [strlen(c.hobby+1)];
    strcpy(hobby,c.hobby);
    weight = c.weight;
    return *this;
}
void Cow::ShowCow() const
{
    std::cout << "Nazwa krowy: " << name << ", hobby: " << hobby << ", waga: " << weight << std::endl;
}
