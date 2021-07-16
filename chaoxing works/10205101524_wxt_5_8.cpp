#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include"my_template.h"

void update(Mylist_cycle<int> &a_list)
{
    auto i = a_list.begin();
    do
    {
        i->Node_data *= 2;
        i++;
    }
    while(i != a_list.begin());
}

int main()
{
    Mylist_cycle<int> a_list;
    for(int i = 0;i<5;i++)
    {
        a_list.insert_tail(i);
    }

    std::cout<<"Your list have 5 elements:"<<std::endl;
    a_list.output_line();
    std::cout<<"after remove(1)"<<std::endl;
    a_list.remove_unit(1);
    a_list.output_line();
    std::cout<<"after remove(0)"<<std::endl;
    a_list.remove_unit(0);
    a_list.output_line();
    std::cout<<"after mylist2(mylist)"<<std::endl;
    Mylist_cycle<int> b_list(a_list);
    b_list.output_line();
    std::cout<<"after update"<<std::endl; 
    //list很早就写好了，功能我觉得更加完善得多，没必要写个把数值乘二的update去污染它
    update(a_list);
    a_list.output_line();
    std::cout<<"after mylist3 = mylist"<<std::endl;
    auto mylist3 = a_list;
    mylist3.output_line();
}