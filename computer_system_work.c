#include<stdio.h>
#include<inttypes.h>

int int_shifts_are_arithmetic()
{
    int32_t a = -1;
    a>>1;
    if(a == -1)
        return 1;
    else
    {
        return 0;
    }
    
}

int bad_int_size_is_32()
{
    int set_msb = 1<<15;
    set_msb = set_msb<<15;
    set_msb = set_msb<<1;
    int beyond_msb = set_msb<<1;

    return set_msb&&!beyond_msb;
}

long decode2(long x, long y, long z)
{
    y = y-z;
    x = x*y;
    long temp = y;
    temp<<63>>63;
    return temp ^ x;
}

long loop(long x, int n){
    long result=0;
    long mask;
    for (mask = 1; mask	!=0	;mask <<=n	){
        result |= x & mask ;
    }
    return result;
}

int main()
{
    int x =2147483647;
    int y = -2147483648;

    printf("%d %d %d %d %d %d" ,x,y,-x,-y,x+1,y-1);
}