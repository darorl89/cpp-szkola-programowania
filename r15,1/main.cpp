#include <iostream>
#include "remotetv.h"

using namespace std;

int main()
{

    Tv s58;
    std::cout << "Ustawienia telewizora s58\n";
    s58.settings();
    Remote grey;
    grey.onoff(s58);
    grey.set_chan(s58,20);
    grey.volup(s58);
    std::cout << "Ustawienia telewizora s58 po uzyciu pilota:\n";
    s58.settings();
    std::cout << std::endl;

    grey.settings();
    std::cout << std::endl;

    s58.remote_mode(grey);
    std::cout << "Zmiana ustawien pilota\n";

    grey.settings();
    std::cout << std::endl;

    Tv s42(Tv::On);
    std::cout << "Ustawienia telewizora s42\n";

    s42.settings();
    grey.set_chan(s42,3);
    grey.set_mode(s42);

    std::cout << "\nUstawienia telewizora s42 po uzyciu pilota:\n";

    s42.settings();
    return 0;
}
