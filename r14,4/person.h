#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <iostream>
#include <ctime>
#include <random>

using std::string;

class Person
{
    string lname;
    string fname;
public:
    Person(string l = "undef", string f = "undef") : lname(l), fname(f) {}
    virtual void show() const {std::cout << "Nazwisko: " << lname << std::endl << "Imie: " << fname << std::endl;}
    virtual void get() {std::cout << "Podaj imie: "; std::cin >> fname; std::cout << "Podaj nazwisko: "; std::cin >> lname;}
    virtual void set() {get();}
};

class Gunslinger : virtual public Person
{
    int incision;
protected:
    virtual void data() const {std::cout << "Liczba wciec: " << incision;}
public:
    Gunslinger(string l = "undef", string f = "undef", int i = 0) : Person(l,f), incision(i) {}
    virtual int draw() const {return incision;}
    virtual void show() const {std::cout << "Rewolwerowiec: " << std::endl; Person::show(); std::cout << "Liczba wciec: " << incision;}
    virtual void get() {std::cout << "Podaj liczbe naciec: "; std::cin >> incision;}
    virtual void set() {Person::get(); Gunslinger::get();}
};

class PokerPlayer : virtual public Person
{
    int card;
public:
    PokerPlayer(string l = "undef", string f = "undef") : Person(l,f), card(std::rand() % 51 + 1) {}
    virtual void data() const {std::cout << "Karta: " << card;}
    virtual int draw() const {return card;}
    virtual void get() {std::cout << "Podaj numer karty: "; std::cin >> card;}
    virtual void set() {Person::get(); PokerPlayer::get();}
    virtual void show() const {std::cout << "Pokerzysta" << std::endl; Person::show(); std::cout << std::endl; PokerPlayer::data();}
};

class BadGuy : public PokerPlayer, public Gunslinger
{
public:
    int gdraw() const {return Gunslinger::draw();}
    int cdraw() const {return PokerPlayer::draw();}
    virtual void show() const {Person::show();Gunslinger::data(); std::cout << std::endl;PokerPlayer::data();}
    virtual void set() {PokerPlayer::set(); Gunslinger::get();}
    virtual void get() {set();}
};
#endif // PERSON_H_INCLUDED
