#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,temp = 0;
	scanf("%d",&n);
	int m = sqrt(n);
	printf("%d",m); 
	if(n == 1||n== 2||n == 3)
		temp = 1,printf("素数");
	for(int i = 2;i<=m;i++)
	{
		if(n%i == 0)
		{
			printf("合数"); 
			temp = 1;
			break;
		}
	}
	
	if(temp == 0) printf("素数");
}
