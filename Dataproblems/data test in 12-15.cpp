#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<vector>

using namespace std;

int search(int donepage,int todaypage,int layer,int n,int m);

vector<int> arr;

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i = 1;i<m/2;i++)
        search(0,i,0,n,m);

    
}

int search(int donepage,int todaypage,int layer,int n,int m)
{
    arr.push_back(todaypage);

    int nextdaypage = todaypage+1;
    if(donepage+todaypage>m)
    {
        return 0;
    }

    if(layer == n-1)
    {
        if(donepage+todaypage == m)
        {
            for(int i = 0;i<arr.size();i++)
            {
                cout<<arr[i]<<" ";
                if(i == arr.size()-1)
                    cout<<"\n";
            }

            return 0;
        }
        else
        {

            return 0;
        }
        
    }
    
    for(int i = nextdaypage;i<m;i++)
    {
        search(donepage+todaypage,i,layer+1,n,m);
        arr.pop_back();
    }
}