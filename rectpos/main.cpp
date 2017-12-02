#include <iostream>
#include <cmath>

using namespace std;

struct rect
{
    double x;
    double y;
};
struct polar
{
    double distance;
    double angle;
};
void show_polar(const polar * dapos);
void rect_to_polar(const rect * pxy, polar * pda);

int main()
{
    using namespace std;
    rect rplace;
    polar pplace;

    cout << "Podaj wartosci x i y: ";
    while(cin >> rplace.x >> rplace.y)
    {
        rect_to_polar(&rplace, &pplace);
        show_polar(&pplace);
        cout << "Podaj nastepne liczby lub q, aby zakonczyc: ";
    }
    cout << "Gotowe \n";
    return 0;
}

void show_polar(const polar * dapos)
{
    using namespace std;
    const double Rad_to_deg = 57.29577951;

    cout << "odleglosc = " << dapos->distance;
    cout << ", kat = " << dapos->angle * Rad_to_deg << " stopni\n";
}
void rect_to_polar(const rect * pxy, polar * pda)
{
    using namespace std;

    pda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
    pda->angle = atan2(pxy->y, pxy->x);
}
