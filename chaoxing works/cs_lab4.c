#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int h,v,s,E,b,S;
unsigned int hits_num=0,miss_num=0,eviction_num=0;
char t[100];

struct Cache
{
	int data;
	int address;
	int time_stamp;
}cache_line, *cache_group, **cache;

void initialize()
{
	cache = (struct Cache**)malloc(sizeof(cache_group)*S);
    for(int i = 0;i<S;i++)
    {

    }
}

int main(int argc,char **argv)
{
	

    return 0;
}