#include<stdio.h>
#include<iostream>
#include<string.h>

char s_gets(char *inp,int n)
{
	fgets(inp,n,stdin);
	int a = strlen(inp);
	inp[a-1] = '\0';
}

int main()
{
    char s1[100],s2[100];
    printf("请输入一行原串：\n");
    s_gets(s1,100);
    printf("原串s1的长度是%d，内容是：%s\n",strlen(s1),s1);
    printf("请输入一行子串：\n");
    s_gets(s2,100);
    printf("子串s2的长度是%d，内容是：%s\n\n查找结果：\n",strlen(s2),s2);
    
	int i,j = 0;
   while(i<strlen(s1))
   {
   		if(s1[i] == s2[j])
   		{
   			i++;j++;
		}
		else
		{
			int foundplace = -1;
			for(int z = strlen(s2)-1;z>=0;z--)
			{
				if(s1[i+strlen(s2)-j]==s2[z])
					{
						foundplace = z;
						break;
					}
			}
			if(foundplace!=-1)
			{
				i = i+strlen(s2)-foundplace-j;
				j=0;
			}
			else
			{
				i = i+strlen(s2)-j+1;
				j = 0;
			}
			
		}
		
		if(j>=strlen(s2))
			printf("%d ",i-strlen(s2));
	} 
	
	return 0;
}
