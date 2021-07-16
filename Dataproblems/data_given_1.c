#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int a;
    struct node *next;
};

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

int main()
{
    struct node *ss;
    (*ss).a = 1;
    struct node *news;
    news = (struct node*)malloc(sizeof(struct node));
    
    ss->next = news;

    int k;
    scanf("%d",&k);
    getchar();
    char ch = getchar();
    while(ch != '\n')
    {
        int i;
        if(i>=0)
        {
            for(i = k;i>0;i--)
            {
                ch++;
                if(ch == 123)
                    ch = 97;
            }
        }
        else
        {
             for(i = k;i<0;i++)
            {
                ch--;
                if(ch == 96)
                    ch = 122;
            }
        }
        
        printf("%c",ch);
        ch = getchar();
    }
}