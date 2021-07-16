#include<stdio.h>
#include<stdlib.h>
int hanoi(int n,char from,char buffer,char to)
{
    if(n==1)
    {
        printf("Moveplate #%d from %c to %c\n",n,from,to);
        return 0;
    }
    else
    {

        hanoi(n-1,from,to,buffer);

        printf("Moveplate #%d from %c to %c\n",n,from,to);

        hanoi(n-1,buffer,from,to);

        return 0;
    }
}
int main()
{
    hanoi(6,'A','B','C');
    return 0;
}