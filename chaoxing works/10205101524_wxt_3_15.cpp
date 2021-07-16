#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include"my_template.h"
using namespace std;
int main()
{
    myqueue<int> a;
    for(int i = 0;i<10;i++)
        a.push(i);

    cout<<a.size()<<endl;
    for(int i = 0;i<5;i++)
        a.pop();
    cout<<a.size()<<endl;
    for(int i = 0;i<3;i++)
        a.push(i);
    cout<<a.size()<<endl;
    int j = a.size();
    for(int i = 0;i<j;i++)
    {
        cout<<a.front()<<' '<<a.back()<<endl;
        a.pop();
    }
}