#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

void putwall(int ,char ,int ,int ); 

char backone();

int Max(int,int);

int main()
{
	int type,letter,height,width;
	printf("请输入要绘制的图形：1-墙 2-框 3-三角，输入-1结束\n");
	scanf("%d",&type);
	
	while(type != -1)
	{
		if(type!=1 && type !=2 && type != 3)
			printf("类型不符合要求，请重新来！\n"); 
		else
		{
			printf("请输入图形的填充字母\n");
			letter = backone();
			printf("请输入高度\n");
			scanf("%d",&height);
			printf("请输入宽度\n");
			scanf("%d",&width);
			
			putwall(type,letter,height,width); 
		}
	printf("请输入要绘制的图形：1-墙 2-框 3-三角，输入-1结束\n");
	scanf("%d",&type);
	} 
}

int Max(int a,int b)
{
	return a>=b?a:b;
}

void putwall(int type,char letter,int height,int width)
{
	if(type == 1)
	{
		for(int i = 1;i<=height;i++)
			for(int j = 1;j<=width;j++)
			{
				printf("%c",letter);
				if(j==width)
					printf("\n");
			}	
	}
	
	if(type == 2)
	{
		for(int i = 1;i<=height;i++)
			for(int j = 1;j<=width;j++)
			{
				if(i == 1||j == 1||i == height||j == width)
					printf("%c",letter);
				else
					printf(" ");
				
				if(j==width)
					printf("\n");
			}
	}
	
	if(type == 3)
	{
		int tri = Max(height,width);
		for(int i = 1;i<=tri;i++)
			for(int j = 1;j<=i;j++)
			{
				printf("%c",letter);
				if(j==i)
					printf("\n");
			}
	}
	
}





char backone()
{
	char inp,oup;
	bool isone = 0;
	
	inp = getchar(); 
	while(inp != '\n' || isone == 0)
	{
		if(!isone)
			oup = inp;
		
		if(inp == '\n'||inp == ' '||inp == '\t')
			inp = getchar();
		else
		{
			isone = 1;
			inp = getchar();
		}
	}
	
	return oup;
}

