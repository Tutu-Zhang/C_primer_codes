#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void read(long long int *a,long long int *b,int n);
void LCM(long long int *,long long int *,int);
int GCD(long long ,long long );

int main()
{
	int n;
    long long int inputa[10],inputb[10];

    scanf("%d",&n);
    read(inputa,inputb,n);
    LCM(inputa,inputb,n);
	
    return 0;
}

void read(long long int *a,long long int *b,int n)
{
    for(int i = 0;i<n;i++)
    {
        scanf("%lld%lld",&a[i],&b[i]);
       // printf("%lld %lld %lld",a[i],b[i],b[i]%a[i]);
    }
}

void  LCM(long long int *a,long long int *b,int n)
{
    for(int i = 0;i<n;i++)
    {
        int temp;
        if(a[i]>b[i])
        {
            temp = b[i];
            b[i] = a[i];
            a[i] = temp;
        }
        if(b[i]%a[i] == 0) 
        {
            printf("case #%d:\n%lld\n",i,b[i]);
        }
        else
        {
            int gcd = GCD(b[i],a[i]);
            std::cout<<"case #"<<i<<":"<<std::endl<<(a[i]*b[i])/gcd<<std::endl;
        }
             
    }
}

int GCD(long long a,long long b)
{
    return (b==0)?a:GCD(b,a%b);
}