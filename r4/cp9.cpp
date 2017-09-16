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
    bar *p_snacks = new bar [2];
    p_snacks[0] =  {"Mars",1.7,270};
    p_snacks[1] =  {"Snickers",1.5,340};
    p_snacks[2] =  {"GoOn",1.5,300};
    cout<<"Marka: "<<p_snacks[0].mark<<", waga: "<<p_snacks[0].weight<<", kalorie: "<<p_snacks[0].calories<<endl;
    cout<<"Marka: "<<p_snacks[1].mark<<", waga: "<<p_snacks[1].weight<<", kalorie: "<<p_snacks[1].calories<<endl;
    cout<<"Marka: "<<p_snacks[2].mark<<", waga: "<<p_snacks[2].weight<<", kalorie: "<<p_snacks[2].calories<<endl;
    delete [] p_snacks;
    return 0;
}
