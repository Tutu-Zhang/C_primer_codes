#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<iomanip>
using namespace std;

void displaystar(int, int);

int main()
{
    int w,h;
    cout<<"input width and height"<<endl;
    cin>>w>>h;
    cout<<"width and height are:"<<w<<' '<<h<<endl<<endl;
    displaystar(w,h);
}

void displaystar(int width, int height)
{
    if(width <=2 || height <=2)
    {
        cout<<"arguments too low";
        exit(0);
    }
    else
    {
        for(int i = 0;i<height;i++)
        {
            for(int j = 0;j<width;j++)
            {
                if(i == 0 || i == height - 1 || j == 0 || j == width - 1)
                    cout<<setw(2)<<'*';
                else
                {
                    cout<<setw(2)<<' ';
                }
            }
            cout<<endl;
        }
    }
    
}