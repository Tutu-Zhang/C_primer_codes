#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int weighttransfer(int inp1,char inp2);

int main()
{
	int i_number,realweight,lastweight,amount=0,time = 0,largest=0,smallest=0;
	char ch = 48;
	printf("欢迎来到货物质量单位统一换算系统。1千克=1000克，1磅=16盎司，1磅=454克\n");
	while(ch != 'x')
	{
		printf("请输入货物的质量数（正整数）\n");
		scanf("%d",&i_number);
		printf("请输入货物的质量单位（g,G-克，k,K-千克，o,O-盎司，p,P-磅），输入x程序退出\n");
		getchar();
		ch = getchar();
		if(ch == 'x')
			break;
		time++;
		realweight = weighttransfer(i_number,ch);
		if(time == 1)
		{
			largest = realweight;
			smallest = realweight;
			lastweight = realweight;
			amount = realweight;
		}
		else if(realweight > largest)
			largest = realweight;
		else if(realweight < smallest)
			smallest = realweight;
		
		if(time != 1)
		amount += realweight;
		
		printf("第%d个货物的质量是%d克\n",time,realweight);	
	//	printf("amount = %d\n",amount);
	}
	
	printf("最重货物的质量是%d克\n最轻货物的质量是%d克\n货物的全部总质量是%d克\n货物的平均质量是%d克\n",largest,smallest,amount,amount/time);
	return 0;
}

int weighttransfer(int inp1,char inp2)
{
	if(inp2 == 'g'||inp2 == 'G')
		return inp1;
	if(inp2 == 'k'||inp2 == 'K')
		return inp1*1000;
	if(inp2 == 'p'||inp2 == 'P')
		return inp1*454;
	if(inp2 == 'o'||inp2 == 'O')
		return inp1*454/16;
	else return 0;
	
}
