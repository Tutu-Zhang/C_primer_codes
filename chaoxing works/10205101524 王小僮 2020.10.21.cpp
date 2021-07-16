#include<stdio.h>
#include<iostream>
using namespace std;

int ifleapyear(int n)
{
	int numofyears = 0;                  //计算闰年年份 
	for(int i = 2000;i<=n;i++)
	{
		if(i%4==0&&i%100!=0)
			numofyears++;
		if(i%400 == 0)
			numofyears++;
	}
	return numofyears;				//讲真，这题里小明2000年刚刚出生就认识了7个小伙伴并且当即过生日？？？出生就过生日？ 
}

int main()
{
	int input,num;
	
	printf("小明是闰年2000年2月29日出生的。他有7个非常好的小伙伴，都不是2月份出生。\n小明生日时候，会收到每个小伙伴100元红包。小伙伴过生日时候，小明会送出20元红包。\n\
根据输入的结束年份，计算小明从出生到该年份一共过了几次生日，送出多少红包，获得多少红包。\n请输入结束的年份，输入<2000时程序退出.\n");

	scanf("%d",&input);
	
	while(input >=2000)
	{
		printf("小明从出生到%d年一共过了%d次生日。\n",input,ifleapyear(input));
		printf("小明从出生到%d年一共送出红包%d元。\n",input,(input-1999)*140);
		printf("小明从出生到%d年一共收到小伙伴红包%d元。\n",input,ifleapyear(input)*700);
		printf("请输入结束的年份，输入<2000时程序退出。\n");
		
		scanf("%d",&input);
	}
	
	return 0; 
	
	
} 
