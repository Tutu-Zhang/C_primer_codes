#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include"my_template.h"
using namespace std;

//写了个int的版本,str的版本只要把桶改成128个然后对于每位的处理改变一下即可
void radix_sort_str(Vec_base<string> &inp)
{
    int max=0,digits=0;
    int size = inp.size();

    for(int i = 0;i<size;i++)
    {
        if(inp[i].size()>max)
        {
            max = inp[i].size();
        }
    /*    if(i == size - 1)
        {
            while(max!=0)
            {
                max /= 10;
                digits++; //数max位数
            }
        }*/
    }

    for(int exp = 1;exp <= max;exp++)
    {
        Vec_base<Vec_base<string>> arr;
        for(int i = 0;i<27;i++)
        {
        Vec_base<string> one;
        arr.push_back(one);
        }

        for(int i = 0;i<size;i++)
        {
            if(inp[i].size()-exp < 0)
            {
                arr[0].push_back(inp[i]);
            }
            else
            {
                int dig = inp[i][inp[i].size()-exp] - 'a' + 1;
                arr[dig].push_back(inp[i]);
            }
        }
        int count = 0;
        for(int i = 0;i<arr.size();i++)
        {
            if(arr[i].size()!=0)
            {
                for(int j = 0;j<arr[i].size();j++)
                {
                    inp[count] = arr[i][j];
                    count++;
                }
            }
        }
    }


}

int main()
{
    Vec_base<string> arr_str;
    arr_str.push_back("rat");
    arr_str.push_back("mop");
    arr_str.push_back("cat");
    arr_str.push_back("map");
    arr_str.push_back("car");
    arr_str.push_back("top");
    arr_str.push_back("cot");
    arr_str.push_back("tar");
    arr_str.push_back("rap");

    for(int i = 0;i<arr_str.size();i++)
        cout<<arr_str[i]<<' ';

    radix_sort_str(arr_str);    
    cout<<endl;
    for(int i = 0;i<arr_str.size();i++)
        cout<<arr_str[i]<<' '; 
}