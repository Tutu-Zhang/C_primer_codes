#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<getopt.h>
#include<stdlib.h>
#include "cachelab.h"

int h=0,v=0,s=0,E=0,b=0,S=0;
int hits_num=0,miss_num=0,eviction_num=0;
char filename[100];

struct Cache
{
	int data;
	int address_mark;
	int time_stamp;
}cache_line, *cache_group, **cache;

void help()
{
	printf("Usage: ./csim-ref [-hv] -s <num> -E <num> -b <num> -t <file>\n"
            "Options:\n"
            "  -h         Print this help message.\n"
            "  -v         Optional verbose flag.\n"
            "  -s <num>   Number of set index bits.\n"
            "  -E <num>   Number of lines per set.\n"
            "  -b <num>   Number of block offset bits.\n"
            "  -t <file>  Trace file.\n\n"
            "Examples:\n"
            "  linux>  ./csim-ref -s 4 -E 1 -b 4 -t traces/yi.trace\n"
            "  linux>  ./csim-ref -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
}

void initialize()
{
	cache = (struct Cache**)malloc(sizeof(cache_group)*S);
    for(int i = 0;i<S;i++)
    {
        cache[i] = (struct Cache*)malloc(sizeof(cache_line)*E);
        for(int j = 0;j<E;j++)
        {
            cache[i][j].data = 0;
            cache[i][j].address_mark = -1;
            cache[i][j].time_stamp = -1;
        }
    }
}

char* update(int address)
{
	int s_address = address>>b & ((1<<s)-1);
	int t_address = address>>(b+s);
	int max_stamp= -1;
	int max_place;
	//check if hit

    for(int i = 0;i<E;i++)
    {
        if(cache[s_address][i].address_mark == t_address)
        {
            hits_num++;
            cache[s_address][i].time_stamp = 0;
            return "hit";
        }
    }
	
	for(int i = 0;i<E;i++)
	{
		if(!cache[s_address][i].data)
        {
            cache[s_address][i].data = 1;
            cache[s_address][i].time_stamp = 0;
            cache[s_address][i].address_mark = t_address;
            miss_num++;
            return "miss";
            
        }
	}

    for(int i = 0;i<E;i++)
    {
        if(cache[s_address][i].time_stamp>max_stamp)
        {
            max_stamp = cache[s_address][i].time_stamp;
            max_place = i;
        }
    }
    cache[s_address][max_place].time_stamp=0;
    cache[s_address][max_place].address_mark = t_address;
    eviction_num++;
    miss_num++;
    return "miss eviction";
}

void simulate()
{
	FILE *fp = fopen(filename,"r");
	char order;
	unsigned int address;
	int data;
	while(fscanf(fp," %c %xu,%d",&order,&address,&data))
	{
		if(order == 'I') continue;
		else if(order == 'L' || order == 'S')
		{
			char *type = update(address);
            if(v)
            {
                printf("%c %x,1 %s",order,address,type);
            }
		}
		else if(order == 'M')
		{
			char *type1 = update(address);
			char *type2 = update(address);
            if(v)
            {
                printf("%c %x,1 %s %s",order,address,type1,type2);
            }
		}
		else
		{
			help();
		}
        for(int i = 0;i<S;i++)
            for(int j = 0;j<E;j++)
            {
                if(cache[i][j].time_stamp>-1)
                    cache[i][j].time_stamp++;
            }
	}
	
	fclose(fp);
	for(int i = 0;i<S;i++)
		free(cache[i]);
	free(cache);
}

int main(int argc,char *argv[])
{
	int opt;
    while((opt = (getopt(argc,argv,"hvs:E:b:t:")) != -1))
    {
        if(opt == 'h')
        {
            h = 1;
            help();
        }
        else if(opt == 'v')
        {
            v = 1;
        }
        else if(opt == 's')
        {
            s = atoi(optarg);
        }
        else if(opt == 'E')
        {
            E = atoi(optarg);
        }
        else if(opt == 'b')
        {
            b = atoi(optarg);
        }
        else if(opt == 't')
        {
            strcpy(filename,optarg);
        }
        else
        {
            help();
        }
    }

    S = 1<<s;

    initialize();
    simulate();

    //printSummary(0,0,0);
    printf("hits:%d misses:%d evictions:%d",hits_num,miss_num,eviction_num);
    return 0;
}
