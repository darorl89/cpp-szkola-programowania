#include "golf.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void makestr(char ch,int signs)
{
    for (int i = 0; i < signs; ++i)
    {
        cout << ch;
    }
    cout << endl;
}

string makestr(string str,char ch, int signs)
{
    str = "";
    for (int i = 0; i < signs; ++i)
    {
        str[i] = ch;
    }
    return str;
}

void setgolf(golf & g, const char * name, int hc)
{

    if(name == '\0')
    {
        cout << "Pusty parametr w konstruktorze (nazwisko)" << endl << "Podaj prawidlowy parametr: ";

        while(!(cin.get(g.fullname,cLen)))
        {
            cin.clear();
            cin.ignore();
            cout << "Podaj prawidlowy parametr: ";
        }
    }
    else
    {
        strncpy(g.fullname,name,40);
    }
    if(hc <= 0 || !hc)
    {
        cout << "Zly handicap w konstruktorze, podaj prawidlowy: ";
        while(!(cin >> hc) || hc <= 0 || hc == '\0')
        {
            cin.clear();
            cin.ignore();
            cout << "Podaj prawidlowy handicap: ";
        }
    }
    g.handicap = hc;
    g.fullname[0] = toupper(g.fullname[0]);
}

void setgolf(golf & g)
{
    cout << "Podaj nazwisko: ";
    if(!(cin.get(g.fullname,40)))
    {
        while(!(cin.get(g.fullname,40)))
        {
            cin.clear();
            cin.ignore();
            //cout << "Podaj prawdilowe nazwisko: ";
        }
    }
    cout << "Podaj handicap: ";
    if(g.handicap >= 0 || !(cin >> g.handicap))
    {
        while(!(cin >> g.handicap) || g.handicap <= 0)
        {
            cin.clear();
            cin.ignore();
            cout << "Handicap nie moze byc ani pusty ani ujemny: ";
        }
    }
    g.fullname[0] = toupper(g.fullname[0]);
}

void deletegolf(golf & g)
{
    strncpy(g.fullname,"",40);
    g.handicap = 0;
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
    if(g.handicap <= 0)
    {
        cout << "Zly handicap w konstruktorze, podaj prawidlowy: ";
        while(!(cin >> g.handicap) || g.handicap <= 0)
        {
            cin.clear();
            cin.ignore();
            cout << "Podaj prawidlowy handicap: ";
        }
    }

}

void showgolf(const golf & g)
{
    cout << "Gracz " << g.fullname << ", handicap: " << g.handicap << endl;
}

void showall(const golf g[],int tSize)
{
    cout << "Oto nasi zawodnicy: " << endl;
    int i;
    int count = 0;
    for (i = 0; i < tSize; ++i)
    {
        if(strcmp(g[i].fullname,""))
        {
            if(i == 0)
                makestr('-',20);
            cout << i+1 << ". " <<  g[i].fullname << ", " << g[i].handicap << endl;
            ++count;
        }
    }
    if(count == 0)
        cout << "Brak." << endl;
    else
        makestr('-',20);
}

bool menu(golf g[], int tSize)
{
    int manage;
    const golf * ptable = g;
    cout << "Wybierz 1 aby dodac gracza, 2 aby usunac, 3 aby wyswietlic graczy lub 4 aby wyjsc: ";
    while(!(cin >> manage))
    {
        cin.clear();
        cin.ignore();
        cout << "Podaj 1, 2 lub 3!";
    }
    switch (manage)
    {
    case 1:
    {
        int i = 0;
        while((strcmp(g[i].fullname,"")))
            ++i;
        cout << "Wolne miejsce: " << i+1 << endl;
        setgolf(g[i]);
        showgolf(g[i]);
    }

    break;
    case 2:
    {
        showall(ptable,tSize);
        int id;
        cout << "Podaj id gracza ktorego chcesz usunac: ";
        while(cin >> id && id < 0);
        id -= 1;
        deletegolf(g[id]);
    }
    break;
    case 3:
        showall(ptable,tSize);
    case 4:
        return false;
    }
}
