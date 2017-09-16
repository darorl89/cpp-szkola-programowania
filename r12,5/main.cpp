#include <queue.h>


using std::cout;
using std::endl;
using std::cin;


bool processtime();
int main()
{
    std::srand(std::time(0));
    const int Min_per_h = 60;
    Queue q;
    Customer temp;
    int customers = 0;
    int turnaways = 0;
    int line_wait = 0;
    int wait_time = 0;
    int served = 0;
    int expected;
    int cyclelimit = Min_per_h * 100;
    int sum_line = 0;
    cout << "Bank stu kas" << endl;
    cout << "Podaj sredni czas oczekiwania: " << endl;
    cin >> expected;
    for (int cycle = 0; cycle < cyclelimit; ++cycle)
    {
        if(q.queuecount() > expected)
        {
            ++turnaways;
        }

        else
        {
            q.enqueue(temp);
            temp.set(cycle);
            ++customers;
        }
        if(wait_time <= 0 && !q.isempty())
        {
            q.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            ++served;
        }
        if(wait_time > 0)
        {
            --wait_time;
        }
    sum_line = q.queuecount();
    }
    cout << "Odeslano: " << turnaways << endl;
    cout << "Sredni czas oczekiwania: " << (double)line_wait / served;
    cout << customers / Min_per_h;
}

bool processtime()
{
    return (rand()/RAND_MAX*2+1);
}
