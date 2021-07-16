#include<stdio.h>

int main()
{
	int inp1,inp2;
	char operat;
	
	printf("整数四则运算器，请依次输入数据-运算符-数据\n请输入第一个数字，输入-1时结束\n");
	scanf("%d",&inp1);
	
	while(inp1 != -1)
	{
		printf("请输入运算符\n");
		getchar();
		operat = getchar();
	//	printf("%c",operat);
		getchar();
		printf("请输入第二个数字\n");
		scanf("%d",&inp2); 
		
		if(operat == '+')
			printf("%d%c%d=%d\n",inp1,operat,inp2,inp1+inp2);
		
		else if(operat == '-')
			printf("%d%c%d=%d\n",inp1,operat,inp2,inp1-inp2);
		
		else if(operat == '*')
			printf("%d%c%d=%d\n",inp1,operat,inp2,inp1*inp2);
		
		else if(operat == '/')
		{
			if(!inp2)
				printf("除数不能为0！\n");
			else
				printf("%d%c%d=%d\n",inp1,operat,inp2,inp1/inp2); 
		}
		printf("请输入第一个数字，输入-1时结束\n");
		scanf("%d",&inp1); 
	} 
	
	
}
