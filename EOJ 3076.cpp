#include<stdio.h>
#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
int a[131][40],num[12];

int Fibo(int n); //数斐波那契 
int countlen(int n); //读取一个数的位数 
int getmax(int n); //就是max函数 

int main()
{
	int t;
	memset(a,0,sizeof(a));
	a[0][0] = 0;
	a[1][0] = a[2][0] = 1;
	
	scanf("%d",&t);
	for(int i = 1;i<=t;i++)
	{
		scanf("%d",&num[i-1]);   //读取输入 
	}
	
	int maxone = getmax(t);
	
//	cout<<"This is maxone"<<maxone<<endl;
	
	for(int i = 3;i<=maxone;i++)
	{
		Fibo(i);                    //把斐波那契给遍历出来 
	}
	
	for(int i = 0;i<=t-1;i++)
	{
		if(num[i] == 0)
		{
			cout<<"case #"<<i<<":"<<endl<<0<<endl;
		}	
		else
		{
			cout<<"case #"<<i<<":"<<endl;	
			for(int j = countlen(num[i]);j>=1;j--)              //输出部分 
			{
				cout<<a[num[i]][j-1];
			}
			cout<<endl;
		}
	}
}

int Fibo(int n)
{
	int length1,length2;
	length1 = countlen(n-2);
	length2 = countlen(n-1);
	int length = max(length1,length2);
//	cout<<"This is length"<<length<<endl;
	for(int i = 0;i<=length-1;i++)
	{
		a[n][i] += a[n-1][i]+a[n-2][i];
	//	cout<<a[n][i]<<endl;
		if(a[n][i]/10 > 0)
		{
			a[n][i+1] += a[n][i] / 10;
		//	cout<<a[n][i+1]<<endl;
			a[n][i] = a[n][i] % 10;
		}
	}
	//	cout<<"This is the number"<<a[n][8]<<a[n][7]<<a[n][6]<<a[n][5]<<a[n][4]<<a[n][3]<<a[n][2]<<a[n][1]<<a[n][0]<<endl;
}

int countlen(int n)
{
	int len = 0;
	int temp = 0;
	for(int i = 29;i>=0;i--)
	{
		if(temp == 1) len++;
		if(a[n][i] != 0&& temp == 0)
			{
				len++;
				temp = 1;
			}
	}
	//cout<<len;
	return len;
}

int getmax(int n)
{
	int ch = 0;
	for(int i = 1;i<=n;i++)
	{
		if(num[i-1]>ch)
			ch = num[i-1];
	}
	return ch;
	
}
