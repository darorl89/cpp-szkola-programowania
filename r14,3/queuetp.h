#ifndef QUEUETP_H_
#define QUEUETP_H_
#include <string>
#include <iostream>
#include <cstdlib>


template <typename Item>
class QueueTP
{
protected:
    //definicje zasiegu klasy
    //Node to definicja zagnie¿d¿ona klasy, lokalna wzglêdem tej klasy
    struct Node { Item item; struct Node * next; };
    //prywatne sk³adowe klasy
    Node * front;       //wskaŸnik czo³a kolejki
    Node * rear;        //wskaŸnik ogona kolejki
    int items;          //bie¿¹ca liczba elementów
    const int qsize;    //maksymalna liczba elementów kolejki
                        //definicje blokuj¹ce publiczny dostêp do operacji kopiowania
    //QueueTP(const QueueTP & q) : qsize(0) {}
    //QueueTP & operator=(const QueueTP & q) { return *this; }
public:

    QueueTP(int qs);            //tworzy kolejkê o pojemnoœci qs
    virtual ~QueueTP();
    bool isempty() const;
    bool isfull() const;
    int  queuecount() const;
    bool enqueue(const Item &item); //dodaje element na koniec kolejki
    bool dequeue(Item & item);      //wyci¹ga element z czo³a kolejki
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
        temp = front;       //zachowanie adresu elementu bie¿¹cego
        front = front->next; //przesuniêcie wskaŸnika do elementu nastêpnego
        delete temp;        //zwolnienie elementu spod zapamiêtanego adresu
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
    Node * add = new Node;      //utworzenie wêz³a
                                //w przypadku niepowodzenia przydzia³u new zrzudzi wyj¹tek na std::bad_alloc
    add->item = item;            //ustawienie wskaŸników wêz³ów
    add->next = nullptr;
    ++items;
    if (front == NULL)          //jeœli kolejka pusta
        front = add;            //umieœæ element na czele listy
    else
        rear->next = add;        //w przeciwnym wypadku do³¹cz do koñca
    rear = add;                 //rear wskazuje teraz nowy wêze³

    return true;
}

//kopiuje element czo³owy kolejki do argumentu wywo³ania i usuwa go z kolejki
template <typename Item>
bool QueueTP<Item>::dequeue(Item & item)
{
    if (front == NULL)
        return false;
    item = front->item;          //skopiowanie do item pierwszego elementu
    --items;
    Node * temp = front;        //zachowanie po³o¿enia pierwszego elementu
    front = front->next;     //przestawienie wskaŸnika front na nastêpny element
    delete temp;                //usuniêcie dotychczasowego pierwszego elementu
    if (items == 0)
        rear = NULL;
    return true;
}

#endif
