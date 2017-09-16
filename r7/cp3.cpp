#include <iostream>

using namespace std;

struct box{
    char producer[40];
    float height;
    float width;
    float length;
    float velocity;
};

void show_box(box boxx);
void set_velocity(box * boxx);

int main()
{
    box box1 = {"Zlom S.A", 20, 30, 40, 14000};
    set_velocity(&box1);
    show_box(box1);
    return 0;
}

void show_box(box boxx){
    cout << "Producent: " << boxx.producer << ", ";
    cout << "Wysokosc " << boxx.height << ", ";
    cout << "Szerokosc: " << boxx.width << ", ";
    cout << "Dlugosc: " << boxx.length << ", ";
    cout << "Objetosc: " << boxx.velocity << endl;
}

void set_velocity(box * boxx){
    boxx->velocity = boxx->height * boxx->width * boxx->length;
}
