#include <iostream>
#include "queuetp.h"
#include "worker.h"

using namespace std;

int main()
{
    QueueTp<Worker> qw1(2);
    Worker temp("pawel",1);
    qw1.enqueue(temp);
    //qw1.enqueue(Worker("seba",2));
    //qw1.dequeue(temp);
    //qw1.dequeue(temp);
    return 0;
}
