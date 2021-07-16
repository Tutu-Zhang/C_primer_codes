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
char* Mystrcat(char *s1,char* s2)
{
    int length1 = Mystrlen(s1),length2 = Mystrlen(s2);
    for(int i = 0;i<length2;i++)
    {
        s1[length1+i] = s2[i];
    }
    return s1;
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

void Sort(struct word *inputword1,struct word *inputword2)
{
    int size = inputword2 - inputword1 + 1;


    for(int i = 0;i<size-1;i++)
        for(int j = size-1;j>i;j--)
        {
            if(!cmp(inputword1+j-1,inputword1+j))
            {
                struct word rev;
                rev = *(inputword1+j-1);
                *(inputword1+j-1) = *(inputword1+j);
                *(inputword1+j) = rev;
            }
        }

}

void strreplace_infound(char *s1,char *s3,int length2,int length3,int* place,int k)
{
    if(!k)
        {
			printf("no string could be replaced");
			return;
		}
   char mstr[200];
   for(int i = 0;i<200;i++)
        mstr[i] = '\0';
   int subp=0;
   for(int i = 0;i<k;i++)
   {
        while(subp!=place[i])
            mstr[subp-i*(length2-length3)] = s1[subp],subp++;
        Mystrcat(mstr,s3);
            subp+=length2;
        if(i == k-1)
        {
            while(subp<Mystrlen(s1))
                mstr[subp-(i+1)*(length2-length3)] = s1[subp],subp++;
                
        }
   }
   Mystrcpy(s1,mstr);
}

char* Mystrcpy(char *s1,char *s2)
{
    clearstr(s1);
    for(int i = 0;i<Mystrlen(s2);i++)
        s1[i] = s2[i];

    return s1;
}
