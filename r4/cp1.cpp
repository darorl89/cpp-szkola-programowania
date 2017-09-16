#include <iostream>

using namespace std;

int main()
{
    char name[80],sec_name[80];
    int grade,age;
    cout<<"Jak masz na imie? ";
    cin.getline(name,80);
    cout<<"Jak sie nazywasz? ";
    cin.getline(sec_name,80);
    cout<<"Na jaka ocene zaslugujesz? ";
    cin>> grade;
    cout<<"Ile masz lat? ";
    cin>>age;
    cout<<"Nazwisko: "<<sec_name<<", "<<name<<endl;
    cout<<"Ocena: "<<grade<<endl;
    cout<<"Wiek: "<<age<<endl;
    return 0;
}

