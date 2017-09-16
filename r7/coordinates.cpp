#include <iostream>
#include <cmath>

using namespace std;

struct rect{
    double x;
    double y;
};

struct polar{
    double distance;
    double angle;
};

void show_polar(const polar *);

polar distance(const rect *);

int main()
{
    rect pos;
    cout << "Podaj wspolrzedne: ";
    while(cin >> pos.x && cin >> pos.y){
        polar pplace = distance(&pos);
        show_polar(&pplace);
        cout << "Nastepne wspolrzedne: ";
    }
    return 0;
}

void show_polar(const polar * polarx){
    const double Rad_to_deg = 57.29577951;
    cout << "Odleglosc: " << polarx->distance << endl;
    cout << "Kat: " << polarx->angle * Rad_to_deg << endl;
}

polar distance(const rect * pos){
    polar result;
    result.distance = sqrt(pos->x * pos->x + pos->y * pos->y);
    result.angle = atan2(pos->y,pos->x);
    return result;
}
