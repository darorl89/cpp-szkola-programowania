#include <iostream>
#include "classic.h"

using namespace std;

void Bravo(const Cd & disk);

int main()
{
    Cd c1("Beatels", "Capitol", 14, 35.5);
    Classic c2 = Classic("Sonata fortepianowa B-dur, fantazja C-moll", "Alfred Brendel", "Philips", 2, 57.17);

    Cd * pcd = &c1;

    cout << "Bezposrednie uzycie obiektu: " << endl;
    c1.Report();
    c2.Report();

    cout << "Uzycie wskaznika na typ Cd:" << endl;
    pcd->Report();
    pcd = &c2;
    pcd->Report();

    cout << "Wywolanie funkcji z argumentem w postaci referencji do typu Cd: " << endl;
    Bravo(c1);
    Bravo(c2);

    cout << "Test przypisania: ";
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}

void Bravo(const Cd & disk)
{
    disk.Report();
}
