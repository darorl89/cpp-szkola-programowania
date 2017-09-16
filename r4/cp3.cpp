#include <iostream>

using namespace std;

int main()
{
    string fname,sname,fullname;
    cout<<"Podaj imie: ";
    cin>>fname;
    cout<<"Podaj nazwisko: ";
    cin>>sname;
    fullname = sname+", "+fname;
    cout<<"Oto informacje zestawione w jeden napis: "<<fullname;
    return 0;
}

