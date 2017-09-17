#ifndef QUEUETP_H_
#define QUEUETP_H_
#include <string>
#include <iostream>
#include <cstdlib>


template <typename Item>
class QueueTP
{
private:
    //definicje zasiegu klasy
    //Node to definicja zagniezdzona klasy, lokalna wzgledem tej klasy
    struct Node { Item item; struct Node * next; };
    //prywatne skladowe klasy
    Node * front;       //wskaznik czola kolejki
    Node * rear;        //wskaznik ogona kolejki
    int items;          //biezaca liczba elementów
    const int qsize;    //maksymalna liczba elementów kolejki
                        //definicje blokujace publiczny dostep do operacji kopiowania
    //QueueTP(const QueueTP & q) : qsize(0) {}
    //QueueTP & operator=(const QueueTP & q) { return *this; }
public:
    QueueTP(int qs);            //tworzy kolejke o pojemnozci qs
    virtual ~QueueTP();
    bool isempty() const;
    bool isfull() const;
    int  queuecount() const;
    bool enqueue(const Item &item); //dodaje element na koniec kolejki
    bool dequeue(Item & item);      //wyciaga element z czola kolejki
    bool operator>(const QueueTP & l)
    {
        if (this->items > l.items)
            return true;

        return false;
    }
};

//metody klasy Queue
template <typename Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}
template <typename Item>
QueueTP<Item>::~QueueTP()
{
    Node * temp;
    while (front != NULL)   //do wyczerpania kolejki
    {
        temp = front;       //zachowanie adresu elementu biezacego
        front = front->next; //przesuniecie wskaznika do elementu nastepnego
        delete temp;        //zwolnienie elementu spod zapamietanego adresu
    }
}
template <typename Item>
bool QueueTP<Item>::isempty() const
{
    return items == 0;
}
template <typename Item>
bool QueueTP<Item>::isfull() const
{
    return items == qsize;
}
template <typename Item>
int QueueTP<Item>::queuecount() const
{
    return items;
}

//dodaje element do kolejki
template <typename Item>
bool QueueTP<Item>::enqueue(const Item &item)
{
    if (isfull())
        return false;
    Node * add = new Node;      //utworzenie wezla
                                //w przypadku niepowodzenia przydzialu new zrzudzi wyjatek na std::bad_alloc
    add->item = item;            //ustawienie wskazników wezlów
    add->next = nullptr;
    ++items;
    if (front == NULL)          //jezli kolejka pusta
        front = add;            //umiezæ element na czele listy
    else
        rear->next = add;        //w przeciwnym wypadku dolacz do koñca
    rear = add;                 //rear wskazuje teraz nowy wezel

    return true;
}

//kopiuje element czolowy kolejki do argumentu wywolania i usuwa go z kolejki
template <typename Item>
bool QueueTP<Item>::dequeue(Item & item)
{
    if (front == NULL)
        return false;
    item = front->item;          //skopiowanie do item pierwszego elementu
    --items;
    Node * temp = front;        //zachowanie polozenia pierwszego elementu
    front = front->next;     //przestawienie wskaznika front na nastepny element
    delete temp;                //usuniecie dotychczasowego pierwszego elementu
    if (items == 0)
        rear = NULL;
    return true;
}

#endif
