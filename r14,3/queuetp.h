#ifndef QUEUETP_H_INCLUDED
#define QUEUETP_H_INCLUDED

template<typename T>
class QueueTp
{
    struct Node {T item; Node * next;};
    const int qsize;
    int items;
    Node * front;
    Node * rear;
    QueueTp(const QueueTp & q) : qsize(0) {}
    QueueTp & operator=(const QueueTp & q) {return *this;}
public:
    QueueTp(int qs = 3);
    ~QueueTp();
    bool isfull() const;
    bool isempty() const;
    bool enqueue(const T & item);
    bool dequeue(T & item);
};

template<typename T>
QueueTp<T>::QueueTp(int qs) : qsize(qs), front(nullptr), rear(nullptr), items(0) {}

template<typename T>
QueueTp<T>::~QueueTp()
{
    Node * temp;
    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template<typename T>
bool QueueTp<T>::isfull() const
{
    return items == qsize;
}
template<typename T>
bool QueueTp<T>::isempty() const
{
    return items == 0;
}
template <typename T>
bool QueueTp<T>::enqueue(const T & item)
{
    if (isfull())
        return false;
    Node * add = new Node;
    add->item = item;
    add->next = nullptr;
    ++items;
    if (isempty())
        front = add;
    else
        rear->next = add;
    return true;
}
template <typename T>
bool QueueTp<T>::dequeue(T & item)
{
    if(isempty())
        return false;
    item = front->item;
    --items;
    Node * temp = front;
    front = front->next;
    delete temp;
    if (isempty())
        rear = nullptr;
    return true;
}
#endif // QUEUETP_H_INCLUDED
