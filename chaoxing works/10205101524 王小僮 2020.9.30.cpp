#include<stdio.h>
#include<iostream>
using namespace std;

int fibonacci(int inp);

int main()
{
	int input = 0,output = 0;
	printf("请输入需要计算斐波那契数列的正整数N，输入-1时程序退出\n"); 
	scanf("%d",&input);
	while(input>-1)
	{
		output = fibonacci(input);
		printf("第%d个斐波那契数值是%d\n",input,output);
		printf("请输入需要计算斐波那契数列的正整数N，输入-1时程序退出\n");
		scanf("%d",&input);
	}
	return 0;
}

int fibonacci(int inp)
{
	int outp;
	if(inp == 0)
	return 0;
	if(inp<=2)
	return 1;
	outp = fibonacci(inp - 1)+fibonacci(inp - 2);
	return outp;
}
