#include <iostream>
#include "remotetv.h"

bool Tv::volup()
{
    if(volume >= MaxVal)
    {
        ++volume;
        return true;
    }
    else
        return false;
}

bool Tv::voldown()
{
    if(volume <= 0)
    {
        --volume;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if (channel >= maxchannel)
        channel = 1;
    else
        ++channel;
}

void Tv::chandown()
{
    if (channel >= 1)
        --channel;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "Telewizor jest: " << (state == Off ? "Wylaczony" : "Wlaczony") << endl;
    if (state == On)
    {
        cout << "Glosnosc: " << volume << endl
        <<  "Program = " << channel << endl
        << "Tryb = " << (mode == Antenna ? "antena" : "kabel") << endl
        << "Wejscie = " << (input == TV ? "TV" : "DVD") << endl;
    }
}

void Remote::settings() const
{
    std::cout << "Tryb pilota = " << (mode == Normal ? "Normalny" : "Interaktywny");
}
