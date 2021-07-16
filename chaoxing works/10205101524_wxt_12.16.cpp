#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<vector>

int Mystrlen(char *inp);
int Mystrcmp(char *one,char *second);
char *s_gets(char *a,int n);
int Mymax(int a,int b,int c);
int Mymin(int,int,int);
void output(char*,char*,char*);
const int Max = 100;

int main()
{
    char inp1[Max],inp2[Max],inp3[Max];
    output(inp1,inp2,inp3);   
}







int Mystrcmp(char *one,char *two)
{
    int i=0,j=0;
    while(i<Mystrlen(one)&&i<Mystrlen(two))
    {
        if(one[i]>two[i])
            return 1;
        else if(one[i]==two[i])
            {
                i++;
            }
        else if(one[i]<two[i])
            return -1;
    }
    if(Mystrlen(one) == Mystrlen(two))
        return 0;
    else if(Mystrlen(one)<Mystrlen(two))
        return -1;
    else if(Mystrlen(one)>Mystrlen(two))
        return 1;
}

int Mystrlen(char *inp)
{
    int i = 0;
    while(inp[i]!= '\0')
        i++;
    return i;
}

char *s_gets(char *a,int n)
{
    char *ret;
    ret = fgets(a,n,stdin);
    int i = 0;
    if(ret)
    {
        while(a[i]!= '\n'&&a[i] != '\0')
            i++;
        if(a[i] == '\n')
            a[i] = '\0';
        else
        {
            while(getchar()!= '\n')
                continue;
        }  
    }
    return ret;
}

int Mymax(int a,int b,int c)
{
    if(a>b)
    {
        if(a>=c)
            return 1;
        else
        {
            return 3;
        }
    }
    else
    {
        if(b<c)
            return 3;
        else
            return 2;
    }
}

int Mymin(int a,int b,int c)
{
    if(a<b)
    {
        if(b<=c)
            return 1;
        else
        {
            if(a<c)
                return 1;
            else
            {
                return 3;
            }
            
        }
    }
    else
    {
        if(b>=c)
            return 3;
        else
            return 2;
    }
}

void output(char *inp1,char *inp2,char *inp3)
{
    printf("锟斤拷锟斤拷锟斤拷锟街凤拷锟斤拷s1:\n");
    s_gets(inp1,Max);
    printf("锟斤拷s1锟侥筹拷锟斤拷锟斤拷%d,锟斤拷锟斤拷锟斤拷: %s\n",Mystrlen(inp1),inp1);
    printf("锟斤拷锟斤拷锟斤拷锟街凤拷锟斤拷s2:\n");
    s_gets(inp2,Max);
    printf("锟斤拷s2锟侥筹拷锟斤拷锟斤拷%d,锟斤拷锟斤拷锟斤拷: %s\n",Mystrlen(inp2),inp2);
    printf("锟斤拷锟斤拷锟斤拷锟街凤拷锟斤拷s3:\n");
    s_gets(inp3,Max);
    printf("锟斤拷s3锟侥筹拷锟斤拷锟斤拷%d,锟斤拷锟斤拷锟斤拷: %s\n",Mystrlen(inp3),inp3);

    int str1=0,str2=0,str3=0;
    if(Mystrcmp(inp1,inp2) == 1)
        str1++;
    if(Mystrcmp(inp1,inp2) == -1)
        str2++;
    if(Mystrcmp(inp1,inp3) == 1)
        str1++;
    if(Mystrcmp(inp1,inp3) == -1)
        str3++;
    if(Mystrcmp(inp2,inp3) == 1)
        str2++;
    if(Mystrcmp(inp2,inp3) == -1)
        str3++;

    int big,sma;
    big = Mymax(str1,str2,str3);
    sma = Mymin(str1,str2,str3);


    if(big == 1)
    {
        printf("锟斤拷锟斤拷锟街凤拷锟斤拷锟斤拷:\n%s\n",inp1);
    }
    else if(big == 2)
    {
        printf("锟斤拷锟斤拷锟街凤拷锟斤拷锟斤拷:\n%s\n",inp2);
    }
    else if(big == 3)
    {
        printf("锟斤拷锟斤拷锟街凤拷锟斤拷锟斤拷:\n%s\n",inp3);
    }
    
    if(sma == 1)
    {
        printf("锟斤拷小锟斤拷锟街凤拷锟斤拷锟斤拷:\n%s\n",inp1);
    }
    else if(sma == 2)
    {
        printf("锟斤拷小锟斤拷锟街凤拷锟斤拷锟斤拷:\n%s\n",inp2);
    }
    else if(sma == 3)
    {
        printf("锟斤拷小锟斤拷锟街凤拷锟斤拷锟斤拷:\n%s\n",inp3);
    }
    
}
