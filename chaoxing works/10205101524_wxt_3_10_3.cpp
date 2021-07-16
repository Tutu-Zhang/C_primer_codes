#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include"my_template.h"

char right_output(int a)
{
    if(a<10)
        return a+48;
    else if(a>=10)
    {
        return a+55;
    }
}

using namespace std;  
int main( )
{
    int n;
    int r;
    mystack<int> numbers;  
    cout << "输入要转换的十进制数N：" << endl;
    cin  >> n;
    cout << "输入要转换的进制数r：" << endl;
    cin  >> r;

    
    while(n)
    {
        int num_putin = n%r;
        numbers.push_back(num_putin);
        n=n/r;
    }
    while (!numbers.empty()) 
    {
        cout << right_output(numbers.top()) << " ";
        numbers.pop_back();
    }
        cout << endl;
}