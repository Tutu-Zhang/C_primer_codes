#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include"my_template.h"

int main()
{


    myqueue<int> a;
    for(int i = 0;i<5;i++)
    {
        a.push(i);
    }
    for(int i = 0;i<3;i++)
    {
        a.pop();
    }
    for(int i = 0;i<2;i++)
        a.push(i);

    std::cout<<a.head<<a.tail;
}