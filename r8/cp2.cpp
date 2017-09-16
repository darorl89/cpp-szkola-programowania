#include <iostream>

using namespace std;

const int StrSize = 40;

struct bar{
    string manufacturer;
    double weight;
    int calories;
};

void add_bar(bar &, string producer = "Millenium Munch", double weight = 2.85, double calories = 350);
void show_bar(const bar &);

int main()
{
    bar millenium;
    add_bar(millenium);
    show_bar(millenium);
    return 0;
}

void add_bar(bar & barx, string manufacturer, double weight, double calories){
    barx.manufacturer = manufacturer;
    barx.weight = weight;
    barx.calories = calories;
}

void show_bar(const bar & barx){
    cout << "Producent: " << barx.manufacturer << ", waga: " << barx.weight << ", kalorie: " << barx.calories << endl;
}
