#include<bits/stdc++.h>
using namespace std;
#define N 100 
int determination[10][10],sum = 0;
int permutation(int a[N],int la,int n);

int main()
{
	int input;
	int a[N];
	memset(a,0,sizeof(a));
	printf("Please input the n:\n");
	scanf("%d",&input);
	
	printf("Please input the determination:\n");
	
	for(int i = 0;i<=input-1;i++)
	{
		a[i] = i+1;
	}
	
	for(int i = 0;i<=input - 1;i++)
		for(int j = 0;j<=input - 1;j++)
		{
			scanf("%d",&determination[i][j]);
		}
		
/*	for(int i = 0;i<=input - 1;i++)
		for(int j = 0;j<=input - 1;j++)
		{
			printf("%d",determination[i][j]);
		}*/
	permutation(a,0,input-1); 
	
	cout<<"\nThe answer is :"<<sum;
	
	getchar();
	getchar();
}
















int permutation(int a[N],int la,int n)
{
	int cycle,temp = 0,mutiply = 1;
	if(la == n)
	{
		for(int i = 0;i<=n;i++)
		{
		//	printf("%d\n",a[i]);
		//	printf("%d",determination[i][a[i]]);
			mutiply *= determination[i][a[i]-1];
			if(i==n)
				for(int j = i;j>=0;j--)
					for(int z = j;z>=0;z--)
					{
						if(a[j]<a[z]) temp++;
					}
		}
	//	printf("%d",mutiply);
	sum = sum + (pow(-1,temp) * mutiply);
		//printf("\n%d\n",temp);
	}
	else
	{
		for(cycle = la;cycle<=n;cycle++)
		{
			swap(a[cycle],a[la]);
			permutation(a,la+1,n);
			swap(a[cycle],a[la]);
		}
	}
}
