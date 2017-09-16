#include <iostream>

using namespace std;
struct pizza{
    string mark;
    float diameter;
    float weight;
};
int main()
{
    ///cp7
    /*pizza margherita;
    cout<<"Podaj marke: ";
    cin>>margherita.mark;
    cout<<"Podaj srednice: ";
    cin>>margherita.diameter;
    cout<<"Podaj wage: ";
    cin>>margherita.weight;
    cout<<"Oto twoja pizza margherita: "<<margherita.mark<<", "<<margherita.diameter<<", "<<margherita.weight;
    */
    pizza *p_pizza = new pizza;
    cout<<"Podaj marke: ";
    cin>>p_pizza->mark;
    cout<<"Podaj srednice: ";
    cin>>p_pizza->diameter;
    cout<<"Podaj wage: ";
    cin>>p_pizza->weight;
    cout<<"Oto twoja pizza margherita: "<<p_pizza->mark<<", "<<p_pizza->diameter<<", "<<p_pizza->weight;
    return 0;
}

