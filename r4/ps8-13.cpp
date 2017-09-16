#include <iostream>
#include <array>


using namespace std;
//ps8
struct fish{
    string type;
    int weight;
    float length;
};

//ps10
enum answer{no,yes,maybe};

int main()
{
    /*array<float,3> sprint_times;
    cout<<"Pierwszy czas: ";
    cin>>sprint_times[0];
    cout<<"Drugi czas: ";
    cin>>sprint_times[1];
    cout<<"Trzeci czas: ";
    cin>>sprint_times[2];
    cout<<"Oto srednia: ";
    float avg = (sprint_times[0]+sprint_times[1]+sprint_times[2])/3;
    cout<<avg<<endl;
    cout<<u8"Pojedyncze czasy: "<<cout<<sprint_times[0]<<", "<<sprint_times[2]<<", "<<sprint_times[2]<<endl;
    */
    //ps9
    fish salomon = {"salty",2000,50};
    cout<<salomon.type<<" salomon"<<"Weight: "<<salomon.weight<<", Height: "<<salomon.length<<endl;

    //ps11
    double ted = 23;
    double *p_ted = &ted;
    cout<<"*p_ted: "<<*p_ted<<endl<<"p_ted: "<<p_ted<<endl;

    //ps12
    float treacle[10] = {0};
    float *p_treacle = treacle;
    cout<<"Treacle[0]: "<<treacle[0]<<", Treacle[last]: "<<treacle[9]<<endl;

    //ps13
    cout<<"Podaj rozmiar tablicy: ";
    int size;
    cin>>size;
    int *p_dynamic_array = new int [size];



}
