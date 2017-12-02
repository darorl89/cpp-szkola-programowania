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

    strncpy(g.fullname,name,cLen);
    g.handicap = hc;
    g.fullname[0] = toupper(g.fullname[0]);
}

void setgolf(golf & g)
{
    cout << "Podaj nazwisko: ";
    if(!(cin.get(g.fullname,cLen)))
    {
        while(!(cin.get(g.fullname,cLen)))
        {
            cin.clear();
            cin.ignore();
            //cout << "Podaj prawdilowe nazwisko: ";
        }
    }
    cout << "Podaj handicap: ";
    if(g.handicap >= 0 || !(cin >> g.handicap))
    {
        while(!(cin >> g.handicap) || g.handicap < 0)
        {
            cin.clear();
            cin.ignore();
            cout << "Handicap nie moze byc rowny 0 ani ujemny: ";
        }
    }
    g.fullname[0] = toupper(g.fullname[0]);
}

void deletegolf(golf & g)
{
    strncpy(g.fullname,"",cLen);
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
    bool any_player = false;
    cout << "Oto nasi zawodnicy: " << endl;
    int count = 0;
    for (int i = 0; i < tSize; ++i)
    {
        if(g[i].handicap != 0)
            any_player = true;
        if(any_player == false)
            continue;
        cout << i+1 << ". " <<  g[i].fullname << ", " << g[i].handicap << endl;
        if(g[i+1].fullname != "")
            makestr('-',20);
        ++count;
    }

    if(count == 0)
    {
        cout << "Brak." << endl;
    }
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
    break;
    case 4:
        return false;
    }
}
