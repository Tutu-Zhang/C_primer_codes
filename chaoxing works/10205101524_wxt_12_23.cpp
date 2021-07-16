#include<stdio.h>

char *s_gets(char *,int );
int find_substring_in_sunday_algotithm(char*,char*,int*,int*,int);
int Mystrlen(char *inp);
void strreplace_infound(char *s1,char *s3,int length2,int length3,int* place,int k);
char* Mystrcat(char *s1,char* s2);
char* Mystrcpy(char *s1,char *s2);
void initialize(char*s1,int n);
void clearstr(char *s1);

int main()
{
    char s1[200],s2[30],s3[30];
    int coord_of_str_that_should_be_replaced[100];
    initialize(s1,200),initialize(s2,30),initialize(s3,30);

    printf("请输入原串s1\n");
    s_gets(s1,200);
    printf("原串s1的长度是%d,内容是:%s\n请输入查找串s2\n",Mystrlen(s1),s1);
    s_gets(s2,30);
    printf("子串s2的长度是%d,内容是:%s\n请输入替换串s3\n",Mystrlen(s2),s2);
    s_gets(s3,30);
    printf("子串s3的长度是%d,内容是%s\n",Mystrlen(s3),s3);

    int length2 = Mystrlen(s2),length3 = Mystrlen(s3);
    
    int i=0,j=0,amountofsubstr=0;
    while(i<Mystrlen(s1))
    {
    	coord_of_str_that_should_be_replaced[amountofsubstr] = find_substring_in_sunday_algotithm(s1,s2,&i,&j,length2);
        if(coord_of_str_that_should_be_replaced[amountofsubstr]!=-1)
        {
            amountofsubstr++;
        }
	}
    strreplace_infound(s1,s3,length2,length3,coord_of_str_that_should_be_replaced,amountofsubstr);
    printf("替换后s1的长度是%d,内容是%s",Mystrlen(s1),s1);
    
}







void initialize(char*s1,int n)
{
    for(int i = 0;i<n;i++)
        s1[i] = '\0';
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

int find_substring_in_sunday_algotithm(char* s1,char* s2,int *i,int*j,int length2)
{   
    if(*s2 == '\0')
        return -1;

    while((*i)<Mystrlen(s1))
   	{	if(s1[*i] == s2[*j])
   		{
   			(*i)++;(*j)++;
		}
		else
		{
			int foundplace = -1;
			for(int z = length2-1;z>=0;z--)
			{
				if(s1[(*i)+length2-(*j)]==s2[z])
					{
						foundplace = z;
						break;
					}
			}
			if(foundplace!=-1)
			{
				(*i) = (*i)+length2-foundplace-*j;
				(*j)=0;
			}
			else
			{
				(*i) = (*i)+length2-(*j)+1;
				(*j) = 0;
			}
			
		}
		
		if((*j)>=length2)
			return (*i)-length2;
    }
    return -1;
}

int Mystrlen(char *inp)
{
    int i = 0;
    while(inp[i]!= '\0')
        i++;
    return i;
}

char* Mystrcat(char *s1,char* s2)
{
    int length1 = Mystrlen(s1),length2 = Mystrlen(s2);
    for(int i = 0;i<length2;i++)
    {
        s1[length1+i] = s2[i];
    }
    return s1;
}

char* Mystrcpy(char *s1,char *s2)
{
    clearstr(s1);
    for(int i = 0;i<Mystrlen(s2);i++)
        s1[i] = s2[i];

    return s1;
}

void clearstr(char*s1)
{
    int length = Mystrlen(s1);
    for(int i = 0;i<length;i++)
        s1[i] = '\0';
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
