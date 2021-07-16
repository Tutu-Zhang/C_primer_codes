#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>

using namespace std;
p-p

int main()
{
    sort()
    double fawr = 0;
    double celsius = 5*(fawr-32)/9;
    printf("fawr  --->  celsius\n");
    for(int i = 0;i<=300;i+=30)
    {
        printf(" %7.0f\t%7.3f\n",fawr,celsius);
        fawr+=30;
        celsius = 5*(fawr-32)/9;
    } 
    
    printf("\nfawr  --->  celsius\n");
	celsius = 0;
	fawr = (celsius * 9 / 5) + 32;
	for(int i = 0;i<=300;i+=30)
	{
		printf(" %7.0f\t%7.3f\n",celsius,fawr);
		celsius += 30;
		fawr = (celsius * 9 / 5) + 32;
	} 

    getchar();
}
