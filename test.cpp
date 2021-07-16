#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
int Mystrlen(char *inp)
{
    int i = 0;
    while(inp[i]!= '\0')
        i++;
    return i;
}
char s_gets(char *a,int n)
{
    char *ret;
    ret = fgets(a,n,stdin);
    int i = 0;
    if(ret)
    {
        while(a[i]!= '\n'&&a[i] != '\0')
            i++;
        if(a[i] == '\n')
            {
                a[i] = '\0';
            }
        else
        {
            while(getchar()!= '\n')
                continue;
        }  
    }
}

int Mymin(int a,int b,int c)
{
    if(a<b)
    {
        if(b<=c)
            return a;
        else
        {
            if(a<c)
                return a;
            else
            {
                return c;
            }
            
        }
    }
    else
    {
        if(b>=c)
            return c;
        else
            return b;
    }
}

int main()
{
    char inp[30];
  //  s_gets(inp,30);
 //   printf("%d %s",Mystrlen(inp),inp);

    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);

    std::cout<<Mymin(a,b,c);
 
}
