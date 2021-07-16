#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include"my_template.h"
using namespace std;

class Polynomial
{
private:
    int size = 0;
public:
    My_cycle_2direction_list<pair<int,int>> polynomial;
    
    void print_poly();
    void input();
    void mult_term();
};

void operation();
void initialize();
bool control_panel(Vec_base<Polynomial>& );

int main()
{
    Vec_base<Polynomial> thestack;
    cout<<"This is a polynomials program."<<endl;
    initialize();
    bool if_break;
    do
    {
        if_break = control_panel(thestack);
    } while (if_break);
    
}

void initialize()
{
    cout<<"Please enter a valid command:"
    <<endl<<"[?]Read a Polynomial"<<endl<<"[=]Reture Top Polynomial"<<endl
    <<"[+]Sum two Polynomial"<<endl<<"[-]Difference two Polynomial"<<endl
    <<"[*]Mult one Polynomial with a Term"<<endl
    <<"[q]Quit."<<endl;
}

bool control_panel(Vec_base<Polynomial> &stack_vec)
{
    cout<<"Select command and press <Enter>:";
    char command;
    cin>>command;

    int a;

    if(command == '?')
    {
        Polynomial a;
        a.input();
        stack_vec.push_back(a);
        cout<<"The following polynomial has been pushed into stack"<<endl;
        stack_vec[stack_vec.size() - 1].print_poly();
    }
    else if(command == '=')
    {
        if(stack_vec.size())
            stack_vec[stack_vec.size() - 1].print_poly();
        else
            cout<<"Stack empty"<<endl;
    }
    else if(command == 'q')
    {
        return 0;
    }
    else if(command == '*')
    {
        if(stack_vec.size())
        {
            stack_vec[stack_vec.size() - 1].mult_term();
            cout<<"The following polynomial has been pushed into stack"<<endl;
            stack_vec[stack_vec.size() - 1].print_poly();
        }
        else
        {
            cout<<"Stack empty"<<endl;
        }
    }

    else if(command == '-')
    {
        auto &r_poly = stack_vec[stack_vec.size() - 1];
        if(stack_vec.empty())
            cout<<"Stack empty"<<endl;
        else if(stack_vec.size() == 1)
        {
            r_poly.print_poly();
        }
        else 
        {
            auto &l_poly = stack_vec[stack_vec.size() - 2];
            auto i = r_poly.polynomial.begin();
            do
            {
                auto j = l_poly.polynomial.begin();
                bool iffound = 0;
                do
                {
                    if(i->Node_data.second == (*j).second)
                    {
                        j->Node_data.first -= i->Node_data.first;
                        iffound = 1;
                    }
                    j++;
                } while (j != l_poly.polynomial.begin() && !iffound);

                if(!iffound)
                    l_poly.polynomial.insert_tail({-(i->Node_data.first),i->Node_data.second});
                i++;
            }
            while(i != r_poly.polynomial.begin());

            stack_vec.pop_back();

        cout<<"The following polynomial has been pushed into stack"<<endl;
        stack_vec[stack_vec.size() - 1].print_poly();    
        }
    }
    else if(command == '+')
    {
        auto &r_poly = stack_vec[stack_vec.size() - 1];
        if(stack_vec.empty())
            cout<<"Stack empty"<<endl;
        else if(stack_vec.size() == 1)
        {
            r_poly.print_poly();
        }
        else 
        {
            auto &l_poly = stack_vec[stack_vec.size() - 2];
            auto i = r_poly.polynomial.begin();
            do
            {
                auto j = l_poly.polynomial.begin();
                bool iffound = 0;
                do
                {
                    if(i->Node_data.second == (*j).second)
                    {
                        j->Node_data.first += i->Node_data.first;
                        iffound = 1;
                    }
                    else if(i->Node_data.second > (*j).second)
                    {
                        l_poly.polynomial.insert(j,i->Node_data);
                        iffound = 1;
                    }
                    j++;
                } while(j != l_poly.polynomial.begin() && !iffound);

                if(!iffound)
                    l_poly.polynomial.insert_tail(i->Node_data);
                i++;
            }
            while(i != r_poly.polynomial.begin());

            stack_vec.pop_back();

        cout<<"The following polynomial has been pushed into stack"<<endl;
        stack_vec[stack_vec.size() - 1].print_poly();    
        }
    }
    else
    {
        initialize();
    }
    

    return 1;
}


void Polynomial::mult_term()
{
  int coefficient,exponent;
            cout<<"coefficient?";
            cin>>coefficient;
            cout<<"exponent?";
            cin>>exponent;

        for(auto i = polynomial.begin();i!=polynomial.end();i++)
        {
            i->Node_data.first *= coefficient;
            i->Node_data.second += exponent;
        }

        polynomial.end()->Node_data.first *= coefficient;
        polynomial.end()->Node_data.second += exponent;
}

void Polynomial::input()
{
            int coefficient,exponent,last_exponent = 0x7fffffff;
            cout<<"coefficient?";
            cin>>coefficient;
            cout<<"exponent?";
            cin>>exponent;

        while(exponent != 0 && coefficient!=0 && exponent < last_exponent)
        {
            polynomial.insert_tail({coefficient,exponent});
            last_exponent = exponent;
            cout<<"coefficient?";
            cin>>coefficient;
            if(!coefficient)
                break;
            cout<<"exponent?";
            cin>>exponent;

        };

        if(exponent)
        {
            cout<<"Bad exponent: Polynomial terminates without its last term."<<endl;
        }
}

void Polynomial::print_poly()
{
 for(auto i = polynomial.begin();i!=polynomial.end();i++)
        {
            if(i->Node_data.first > 0)
            {
                if(i == polynomial.begin())
                    cout<<i->Node_data.first<<" X^"<<i->Node_data.second<<' ';
                else
                    cout<<"+ "<<i->Node_data.first<<" X^"<<i->Node_data.second<<' ';
            }
            else if(i->Node_data.first == 0)
            {
            }        
            else
            {
                cout<<"- "<<-(i->Node_data.first)<<" X^"<<i->Node_data.second<<' ';
            }
        }
        auto i = polynomial.end();
        if(i->Node_data.first > 0)
            {
                if(i == polynomial.begin())
                {
                    cout<<i->Node_data.first<<" X^"<<i->Node_data.second<<' ';
                }
                else
                {
                    cout<<"+ "<<i->Node_data.first<<" X^"<<i->Node_data.second<<' ';
                }
            }
            else
            {
                cout<<"- "<<-(i->Node_data.first)<<" X^"<<i->Node_data.second<<' ';
            }
        cout<<endl;
}
