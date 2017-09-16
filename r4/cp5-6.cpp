#include <iostream>

using namespace std;

struct bar{
    string mark;
    float weight;
    int calories;
};

int main()
{
    bar snack{"Mocha Munch",2.3,350};
    cout<<"Marka: "<<snack.mark<<", waga: "<<snack.weight<<", kalorie: "<<snack.calories<<endl;
    bar snacks[3];
    snacks[0] =  {"Mars",1.7,270};
    snacks[1] =  {"Snickers",1.5,340};
    snacks[2] = {"GoOn",1.5,300};
    cout<<"Marka: "<<snacks[0].mark<<", waga: "<<snacks[0].weight<<", kalorie: "<<snacks[0].calories<<endl;
    cout<<"Marka: "<<snacks[1].mark<<", waga: "<<snacks[1].weight<<", kalorie: "<<snacks[1].calories<<endl;
    cout<<"Marka: "<<snacks[2].mark<<", waga: "<<snacks[2].weight<<", kalorie: "<<snacks[2].calories<<endl;
    return 0;
}

