#include <iostream>

using namespace std;

double harmon(double,double);

int main()
{
    int x,y;
    while(cin>>x>>y && x != 0 && y != 0)
        cout << harmon(x,y) << endl;
    return 0;
}

double harmon(double x, double y){
    return 2*x*y/(x+y);
}
