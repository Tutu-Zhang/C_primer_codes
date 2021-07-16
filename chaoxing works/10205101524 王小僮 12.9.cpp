#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int gets_s(char* a,int n)
{
    fgets(a,n,stdin);
    int i;
    for(i = 0;i<n;i++)
    {
        if(a[i] == '\n')
        {    
			a[i] = '\0';
			break;
		}
    }
    return i;
}

struct letter
{
	char let;
	int num;	
};

int main() 
{
	struct letter numofnumber[30];
    char str[1001];
    printf("读取一行字符串，统计串中每个字母出现的次数，大小写不区分，然后按照出现次数从大到小输出.\n");
    printf("输入END程序结束.\n");
    int backplace = gets_s(str,1000);
    //printf("%d",backplace);
    
	for(int i = 1;i<=26;i++)
	{
        	numofnumber[i].let = 96+i;
        	numofnumber[i].num = 0;
	}


    while(strcmp(str,"END")!=0)
    {
    	printf("字符串s1的长度是%d,内容是：%s\n",strlen(str),str);
        for(int i = 0;i<backplace;i++)
        {
            int temp;
            str[i] = tolower(str[i]);
            temp = str[i] - 96;
           // printf("%d",temp);
            if(temp>=1 || temp <=26);
                numofnumber[temp].num++;
        }
        
        
        for(int i=1;i<26;i++)
        	for(int j = i+1;j<=26;j++)
        	{
        		if(numofnumber[i].num<numofnumber[j].num)
        		{
        			int cha = numofnumber[i].num;
        			numofnumber[i].num = numofnumber[j].num;
        			numofnumber[j].num = cha;
        			
        			char chas = numofnumber[i].let;
        			numofnumber[i].let = numofnumber[j].let;
        			numofnumber[j].let = chas;
				}
			}
        
        for(int i = 1;i<=26;i++)
        {
        	printf("%c出现的次数是%d次。\n",numofnumber[i].let,numofnumber[i].num);
		}
		
		for(int i = 1;i<=26;i++)
	{
        	numofnumber[i].let = 96+i;
        	numofnumber[i].num = 0;
	}
		
		backplace = gets_s(str,1000);
    }

}
