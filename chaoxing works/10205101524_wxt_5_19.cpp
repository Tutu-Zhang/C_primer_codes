#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include"my_template.h"

int main()
{
    Mylist<int> lis;
    //我的Mylist结构中有一个insert_order函数，使用这个函数进行插入时list恒为递增序
    for(int i = 10;i>0;i--)
    {
        lis.insert_order(i); //从10开始降序插入
    }

    lis.insert(lis.begin(),0);//insert为需要迭代器标识的位置插入
    lis.replace(lis.begin(),-10);

    auto i = lis.begin();
    while(i != lis.end())
    {
        printf("%d ",*i);
        i++;
    }

    getchar();
    getchar();
}