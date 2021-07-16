#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<time.h>
#include<vector>
#include<iomanip>
#include<stack>
#include<set>
#include<sstream>
#include<queue>
using namespace std;

int compare();

int main()
{
	int a[3000],b[3000],c[3000];
	char s1[3000],s2[3000],s3[3000];
	int lena,lenb,lenmax;
	
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	
	scanf("%s",s1+1);
	lena = strlen(s1+1);
	for(int i = 1;i<=lena;i++)
	{
		a[i] = s1[lena-i+1] - '0';
	}
	
	scanf("%s",s2+1);
	lenb = strlen(s2+1);
	for(int i = 1;i<=lenb;i++)
	{
		b[i] = s2[lenb-i+1] - '0';
	}
	
	
	lenmax = max(lena,lenb);
	
	
	
	for(int i = 1;i<=lenmax;i++)
	{
		c[i] = c[i]+a[i]-b[i];
		if(c[i]<0)
		{
			c[i] += 10;
			c[i+1]=-1;
		}
	}
	
//	if(c[lenmax] == 0) lenmax--;
	
	for(int i = lenmax;i>0;i--)
		printf("%d",c[i]);
	 
}

int compare()
{
	if(lena > lenb) return 1;
	if(lenb > lena) return 0;
	for(int i = lena;i>0;i--)
	{
		
	}
}
