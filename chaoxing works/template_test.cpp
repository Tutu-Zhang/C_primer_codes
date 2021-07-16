#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<string.h>
#include<list>
#include<set>
#include"my_template.h"
using namespace std;

union ele
{
   struct 
   {
      long *p;
      long y;
   }e1;
   struct 
   {
      long x;
      union ele *next;
   }e2;
};

void proc(union ele *up)
{
   up->e2.x = *(up->e2.next->e1.p) - up->e2.next->e1.y;;  
}

int main()
{
      Mylist<int> a;
      for(int i = 10;i>0;i--)
      {
         a.insert_order(i);
      }

      for(int i = 0;i<2;i++)
      {
         cout<<a.front()<<' '<<a.back()<<endl;
      }

}