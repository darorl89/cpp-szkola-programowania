#include <iostream>
#include <array>


using namespace std;

int main()
{
    array<float,3> sprint_times;
    cout<<"Pierwszy czas: ";
    cin>>sprint_times[0];
    cout<<"Drugi czas: ";
    cin>>sprint_times[1];
    cout<<"Trzeci czas: ";
    cin>>sprint_times[2];
    cout<<"Oto œrednia: ";
    float avg = (sprint_times[0]+sprint_times[1]+sprint_times[2])/3;
    cout<<avg<<endl;
    cout<<u8"Pojedyñcze czasy: "<<cout<<sprint_times[0]<<", "<<sprint_times[2]<<", "<<sprint_times[2]<<endl;
}
