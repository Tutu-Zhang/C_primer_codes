#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include"my_template.h"
using namespace std;
void help( )
/* Post: A help screen for the program is printed, giving the meaning of each
command that the user may enter. */
{
cout << endl
<< "This program allows the user to enter one command" << endl
<< "(but only one) on each input line." << endl
<< "For example, if the command S is entered, then" << endl
<< "the program will serve the front of the queue." << endl
<< endl
<< " The valid commands are:" << endl
<< "A − Append the next input character to the extended queue" << endl
<< "S − Serve the front of the extended queue" << endl
<< "R − Retrieve and print the front entry." << endl
<< "# − The current size of the extended queue" << endl
<< "C − Clear the extended queue (same as delete)" << endl
<< "P − Print the extended queue" << endl
<< "H − This help screen" << endl
<< "Q − Quit" << endl;
}
int main()
{
    myqueue<char> queue_a;
    help();
    cout<< "Select command and press <Enter>:";
    char input;
    cin>>input;
    cout<<flush;
    while(input != 'Q'&&input!= 'q')
    {
        if(input == 'A' || input == 'a')
        {
            cout<<"Please input a char"<<endl;
            char inp;
            cin>>inp;
            cout<<flush;
            queue_a.push(inp);
        }
        else if(input == 'S'||input == 's')
        {
            if(queue_a.empty())
            {
                std::cout<<"Queue is empty"<<endl;
            }
            else
            queue_a.pop();
        }
        else if(input == 'R' || input == 'r')
        {
            if(!queue_a.empty())
            std::cout<<"The first entry is:"<<queue_a.front()<<endl;
            else
            {
                std::cout<<"Empty queue"<<endl;
            }
            
        }
        else if(input == '#')
        {
            std::cout<<"The size of Queue is:"<<queue_a.size()<<endl;
        }
        else if(input ==  'c'||input == 'C')
        {
            while(!queue_a.empty())
            {
                queue_a.pop();
            }
            std::cout<<"The empty queue with length 0"<<endl;
        }
        else if(input == 'p' || input == 'P')
        {
            if(!queue_a.empty())
                queue_a.print();
            else
            {
                std::cout<<"Empty Queue"<<endl;
            }
            
        }
        else if(input == 'h'||input == 'H')
        {
            help();
        }
        else
        {
            std::cout<<"Please enter a valid command:"<<endl
                <<"[a] Append [s]Serve [r]Retrieve [#]size [c]Clear [p]Print [h] Help page [q]quit"<<endl;       
        }


        cout<<"Select command and press <Enter>:";
        cin>>input;
        cout<<flush;
    }

}