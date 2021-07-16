#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<math.h>
using namespace std;
string strtolower(string a);
void transferto10(string a);
void transferto2(string a);

int main()
{
    string input;
    printf("读取一行字符串，将串中的所有16进制数字字符进行转化成对应的10进制和2进制整数\n");
    printf("若不是0x或者0X开头，输出非法的16进制数\n输入END,程序退出\n");
    cin>>input;
    while(input != "END")
    {
        cout<<"字符串s1的长度是"<<input.size()<<",内容是:"<<input<<endl;
        if(input[0]!='0'&&(input[1]!='x'||input[1]!='X'))
        {
            cout<<"非法的16进制数值"<<endl;
            cin>>input;
            continue;
        }
        transferto10(input);
        transferto2(input);
        cin>>input;
    }

}


void transferto10(string a)
{
    a = strtolower(a);
    long long int result=0;
    int invalidnum=0;
    for(int i = a.size()-1;i>1;i--)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            result += (a[i]-48)*pow(16,a.size()-i-1-invalidnum);
        }
        else if(a[i]>=97&&a[i]<=102)
        {
            result += (a[i]-87)*pow(16,a.size()-i-1-invalidnum);
        }
        else
        {
            invalidnum++;
        }
        
    }
    cout<<"转化后的10进制整数数字是:"<<result<<endl;
}

void transferto2(string a)
{
    a=strtolower(a);
    cout<<"转化后的2进制整数数字是:";
    for(int i = 2;i<a.size();i++)
    {
        if(i == 2&&a[i]>='0'&&a[i]<='9')
        {
            if(a[i]=='1')
                cout<<"1";
            if(a[i]=='2')
                cout<<"10";
            if(a[i]=='3')
                cout<<"11";
            if(a[i]=='4')
                cout<<"100";
            if(a[i]=='5')
                cout<<"101";
            if(a[i]=='6')
                cout<<"110";
            if(a[i]=='7')
                cout<<"111";
                
            continue;
        }
        if(a[i]>='0'&&a[i]<='9')
        {
            switch(a[i])
            {
                case '0':cout<<"0000";
                         break;
                case '1':cout<<"0001";
                         break;
                case '2':cout<<"0010";
                         break;
                case '3':cout<<"0011";
                         break;
                case '4':cout<<"0100";
                         break;
                case '5':cout<<"0101";
                         break;
                case '6':cout<<"0110";
                         break;
                case '7':cout<<"0111";
                         break;
                case '8':cout<<"1000";
                         break;
                case '9':cout<<"1001";
                         break;
            }
        }
        else if(a[i]>=97&&a[i]<=102)
        {
            switch(a[i])
            {
                case 'a':cout<<"1010";
                         break;
                case 'b':cout<<"1011";
                         break;
                case 'c':cout<<"1100";
                         break;
                case 'd':cout<<"1101";
                         break;
                case 'e':cout<<"1110";
                         break;
                case 'f':cout<<"1111";
                         break;
            }
        }
    }
    printf("\n");
}

string strtolower(string a)
{
    for(int i = 0;i<a.size();i++)
    {
        if(a[i]>=65&&a[i]<=90)
            a[i] = a[i]+32;
    }
    return a;
}
