#include<bits/stdc++.h>

int output(char*,int*,int);

int main()
{
	char letter[3000];
	int s[3000];
	memset(s,0,sizeof(s));
	int temp=-1,wordnum=1;
	bool iffirst = 0;
	printf("本程序会将输入的一行英文句子，分成若干单词每行输出，并统计单词个数\n"); 
	int	ch = getchar();
	while(ch!='\n')
	{
		if(iffirst==1&&ch!=' '&&ch!='\t') iffirst = 0;
		if(iffirst == 0)temp++;
		if(ch == ' '||ch == '\t')
		{
			if(iffirst == 0)
			{
				wordnum++;
				s[temp] = 1;
				iffirst = 1;
			}
		}
		letter[temp] = ch;
		ch = getchar();
	}
	s[temp+1] = 1;
	
	output(letter,s,wordnum);
	
} 

int output(char *letter,int *s,int wordnum)
{
		
	int temp = 0;
	for(int i = 1;i<=wordnum;i++)
	{
		printf("第%d个单词：",i);
		while(!s[temp])
		{
			printf("%c",letter[temp]);
			temp++;
		}
			printf("\n");
			temp++;
	}	
	printf("一共%d个单词。",wordnum);
}
