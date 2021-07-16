#include<bits/stdc++.h>
int reverse(int Max_Place,int Number);
int onebyone(int Max_Place,int Number);
int getmax(int Number);



int main()
{
	int Max_Place = 0,Number = 0;
	
	scanf("%d",&Number);
	
	Max_Place = getmax(Number);
	//printf("%d\n\n",Max_Place);
	Number = reverse(Max_Place,Number);
	printf("%d\n\n",Number);
	onebyone(Max_Place,Number);
}



int reverse(int Max_Place,int Number)
{
	int son,mom;
		for(int i=1;i<=Max_Place;i++)
	{
		son = Number%10;
		Number = Number/10;
		mom = (mom+son)*10;
	}
	mom = mom /10;
	return mom;
}
int onebyone(int Max_Place,int Number)
{
	for(int i = 1;i<=Max_Place;i++)
	{
		printf("%d\n",Number%10);
		Number = Number/10;
	}
}
int getmax(int Number)
{
	int count=0;
	while(Number != 0)
	{
		Number /= 10;
		count++;
	}
	return count;
}
