#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include"my_template.h"

using namespace std;

int main()
{
    Mylist<int> joseph_list;
    int n,m;
    cout<<"This is a YSF(n,m) problem."<<endl;
    cout<<"Please input the integer n(n>=1)."<<endl;
    cin>>n;
    cout<<"Please input the integer m(m>=1)"<<endl;
    cin>>m;

    for(int i = 1;i<=n;i++)
        joseph_list.insert_tail(i);


    auto ite = joseph_list.begin();
    while(joseph_list.size()>1)
    {
        for(int i = 0;i<m-1;i++)
        {
            ite = ite->next;
        }
        Mylist<int>::iterator next(ite->next);
        cout<<"Get rid of:"<<*ite<<endl;
        joseph_list.erase(ite);
        ite = next;
    }
    cout<<"The left element is:"<<joseph_list.front()<<endl<<"Press any key to quit.";
}