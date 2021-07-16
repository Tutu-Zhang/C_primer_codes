#include<stdio.h>
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

long double factorial(long double inp);

int main()
{
   long double input = 0;
    while(input != -1)
    {
        long double output;
        cout<<"请输入需要计算阶乘的正整数,输入-1时程序退出"<<endl;
        cin>>input;

        if(input == -1)
            {
                return 0;
            }
        output = factorial(input);
        cout<<input<<"的阶乘是"<<fixed<<setprecision(0)<<output<<endl;

    }
    
    //getchar();

    
}  

long double factorial(long double inp)
{
    long double back;

    if(inp == 1 || inp == 0)
        back = 1;
    else
    {
        back = factorial(inp - 1)*inp;
    }

    return back;
}
