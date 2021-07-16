#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include"my_template.h"
using namespace std;
void website_execution(char &order,My_cycle_2direction_list<string> &control);

int main()
{
    My_cycle_2direction_list<string> websites; // 此为双向循环链表，特判头尾达到一般双向链表的效果
    cout<<"请输入浏览器命令: V<访问新网站>, F<前进> ,B<后退> ,X<退出>"<<endl;
    char order;
    cin>>order;
    while(order != 'X' && order != 'x')
    {
        website_execution(order,websites);
        cin>>order;
    }
}

void website_execution(char &order,My_cycle_2direction_list<string> &control)
{
    static auto nowplace = control.begin();
    if(order == 'F' || order == 'f')
    {
        if(control.empty() || nowplace == control.end())
        {
            cout<<"无法前进!"<<endl;
        }
        else
        {
            nowplace++;
            cout<<"当前网址是:"<<(*nowplace)<<endl;
        }
    }
    if(order == 'B' || order == 'b')
    {
        if(control.empty() || nowplace == control.begin())
        {
            cout<<"无法后退!"<<endl;
        }
        else
        {
            nowplace--;
            cout<<"当前网址是:"<<(*nowplace)<<endl;
        }
    }
    if(order == 'V'||order == 'v')
    {
        string new_web;
        cout<<"请输入新的网址:";
        cin>>new_web;
        getchar();
        if(control.empty())
        {
            control.insert_tail(new_web);
            nowplace = control.end();
            cout<<"当前网址是:"<<(*nowplace)<<endl;
        }
        else if(nowplace == control.end())
        {   
            control.insert_tail(new_web);
            nowplace = control.end();
            cout<<"当前网址是:"<<(*nowplace)<<endl;
        }
        else
        {
            while(nowplace != control.end())
            {
                control.erase(control.end());
            }
            control.insert_tail(new_web);
            nowplace = control.end();
            cout<<"当前网址是:"<<(*nowplace)<<endl;
        }
    }
}