#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

class timetype
{
    public:
    void set(int hours, int minus, int secos);
    void increment();
    void write();
    bool equal(timetype othertime)
    {
        if(othertime.hrs == hrs && othertime.secs == secs &&othertime.mins == mins)
            return 1;
        else 
            return 0;
    }
    bool lessthan(timetype other)
    {
        if(other.hrs == hrs && other.mins == mins)
            return other.secs > secs;
        else if(other.hrs == hrs)
            return other.mins > mins;
        else
        {
            return other.hrs>hrs;
        }
    }
    timetype(int a,int b,int c)
    {
        set(a,b,c);
    }
    timetype()
    {
        set(0,0,0);
    }

    private:
    int hrs, mins, secs;
};

void timetype::write()
{
    cout<<hrs<<':'<<setfill('0')<<setw(2)<<mins<<':'<<setfill('0')<<setw(2)<<secs<<endl;
}

void timetype::set(int hours, int minus, int secos)
{
    hrs = hours;
    mins = minus;
    secs = secos;
}

void timetype::increment()
{
    _sleep(1);
    secs++;
    if(secs == 60)
    {
        mins++;
        secs = 0;
    }
    if(mins == 60)
    {
        hrs++;
        mins = 0;
    }
    if(hrs == 24)
    {
        hrs = 0;
    }
}

int main()
{
    timetype first,due;
    due.set(16,0,0);
    first.set(15,50,0);
    while(first.lessthan(due))
    {
        first.increment();
        first.write();
    }
    
}