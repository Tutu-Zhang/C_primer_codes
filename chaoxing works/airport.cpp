#include<iostream>
#include <windows.h> 
#include <winbase.h> 
#include"airport_template.h"
#include"my_template.h"
using namespace std;
class Plane
{
    public:
    int wait_time =0;
    int number;
    Plane(int a)
    {
        number = a;
    }
    Plane()
    {
        number = 0;
    }
};

class air_port
{
    public:
    int plane_processed=0;
    int ask_land=0,ask_takeoff=0,acc_land=0,acc_take=0;
    int refu_land=0,refu_take=0;
    int idle_time=0;
    int end_time;           
    int queue_limit; 

    int all_land_time=0,all_takeoff_time=0;
};

void initialize(int&,int&,double&,double&);
void shut_down(air_port,myqueue<Plane>,myqueue<Plane>);

int main()
{
    int end_time;           
    int queue_limit;         
    int flight_number = 0;
    double arrival_rate, departure_rate;


    initialize(end_time,queue_limit,arrival_rate,departure_rate);

    Random execution(1);
    air_port the_port;
    the_port.end_time = end_time;
    the_port.queue_limit =queue_limit;
    myqueue<Plane> landing_queue,takeoff_queue;

    for (int current_time = 0; current_time < end_time; current_time++)
    { 
        if(landing_queue.empty() && takeoff_queue.empty())
        {
            cout<<current_time<<": Runway is idle"<<endl;
            the_port.idle_time++;
        }
        else if(!landing_queue.empty())
        {
            Plane taking_one = landing_queue.front();
            landing_queue.pop();
            the_port.all_land_time+= taking_one.wait_time;
            cout<<current_time<<": Plane number "<<taking_one.number<<" landed after "
            <<taking_one.wait_time<<" units in the landing queue"<<endl;
        }
        else
        {
            Plane taking_one = takeoff_queue.front();
            takeoff_queue.pop();
            the_port.all_takeoff_time += taking_one.wait_time;
            cout<<current_time<<": Plane number "<<taking_one.number<<" took off after "
            <<taking_one.wait_time<<" units in the takeoff queue"<<endl;
        }

        for(int i = 0;i<landing_queue.size();i++)
        {
            landing_queue[i].wait_time++;
        }
        for(int i = 0;i<takeoff_queue.size();i++)
        {
            takeoff_queue[i].wait_time++;
        }
            
      int number_arrivals = execution.poisson(arrival_rate); //  current arrival requests
      for (int i = 0; i < number_arrivals; i++) 
      {
        Plane coming(the_port.plane_processed);
        if(landing_queue.size()<queue_limit)
        {
            landing_queue.push(coming);
            the_port.ask_land++;
            the_port.acc_land++;
            cout<<"Plane number "<<coming.number<<" ready to land"<<endl;
        }
        else
        {
            the_port.ask_land++;
            the_port.refu_land++;
            cout<<"Plane number "<<coming.number<<" ready to land"<<endl;
            cout<<"Plane number "<<coming.number<<" told to try to land again later"<<endl;
        }

        the_port.plane_processed++;
      }

      int number_departures= execution.poisson(departure_rate); //current departure requests
      for (int j = 0; j < number_departures; j++) 
      {
         Plane coming(the_port.plane_processed);
         if(takeoff_queue.size()<queue_limit)
        {
            takeoff_queue.push(coming);
            the_port.ask_takeoff++;
            the_port.acc_take++;
            cout<<"Plane number "<<coming.number<<" ready to takeoff"<<endl;
        }
        else
        {
            the_port.ask_takeoff++;
            the_port.refu_take++;
            cout<<"Plane number "<<coming.number<<" ready to takeoff"<<endl;
            cout<<"Plane number "<<coming.number<<" told to try to takeoff again later"<<endl;
        }
      }
    }

    cout<<"Simulation has concluded after "<<end_time<<" time units"<<endl;
    shut_down(the_port,landing_queue,takeoff_queue); 

}

void shut_down(air_port inp,myqueue<Plane>land,myqueue<Plane>take)
{

        cout<< "Total number of planes processed "
        << inp.plane_processed << endl
        << "Total number of planes asking to land "
        << inp.ask_land << endl
        << "Total number of planes asking to take off "
        << inp.ask_takeoff << endl
        << "Total number of planes accepted for landing "
        << inp.acc_land << endl
        << "Total number of planes accepted for takeoff "
        << inp.acc_take << endl
        << "Total number of planes refused for landing "
        << inp.refu_land << endl
        << "Total number of planes refused for takeoff "
        << inp.refu_take << endl
        << "Total number of planes that landed "
        << inp.ask_land - land.size()  << endl
        << "Total number of planes that took off "
        << inp.ask_takeoff - take.size() << endl
        << "Total number of planes left in landing queue "
        << land.size() << endl
        << "Total number of planes left in takeoff queue "
        << take.size() << endl;
        cout << "Percentage of time runway idle "
        << 100.0 * (( float ) inp.idle_time) / inp.end_time << "%" << endl;
   if (inp.acc_land)
		cout << "Average wait in landing queue "
			 << (( float ) inp.all_land_time) / (( float ) inp.acc_land) << " time units";
   else 
		cout << "Average wait in landing queue 0 time units";
   if (inp.acc_take)
		cout << endl << "Average wait in takeoff queue "
			 << (( float ) inp.all_takeoff_time) / (( float ) inp.acc_take) << " time units" << endl;
   else 
	    cout << "Average wait in takeoff queue 0 time units" << endl;
   cout << "Average observed rate of planes wanting to land "
        << (( float ) inp.ask_land) / (( float ) inp.end_time)
        << " per time unit" << endl;
   cout << "Average observed rate of planes wanting to take off "
        << (( float ) inp.ask_takeoff) / (( float ) inp.end_time)
        << " per time unit" << endl;
}











void initialize(int &end_time, int &queue_limit,double &arrival_rate, double &departure_rate)
{
   cout << "This program simulates an airport with only one runway." << endl
        << "One plane can land or depart in each unit of time." << endl;
   cout << "Up to what number of planes can be waiting to land "
        << "or take off at any time? " << flush;
   cin  >> queue_limit;
   cout << "How many units of time will the simulation run?" << flush;
   cin  >> end_time;

   bool acceptable;

   do {
      cout << "Expected number of arrivals per unit time?" << flush;
      cin  >> arrival_rate;
      cout << "Expected number of departures per unit time?" << flush;
      cin  >> departure_rate;
      if (arrival_rate < 0.0 || departure_rate < 0.0)
         cerr << "These rates must be nonnegative." << endl;

      else
         acceptable = true;

      if (acceptable && arrival_rate + departure_rate > 1.0)
         cerr << "Safety Warning: This airport will become saturated. " << endl;
   } while (!acceptable);

}