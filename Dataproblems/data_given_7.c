#include<stdio.h>
#include<string.h>

struct word
{
    char is[25];
    int times;
};
int cmp(struct word *inputword1,struct word *inputword2);

void Sort(struct word*,struct word*);



int main()
{
    struct word inputword[500] = {"\0",0};
    int amountofstr=0;

    char inp[30];
    char ch = getchar();
    while(ch!='\n'&&ch!=EOF)
    {
        int i = 0;
        while(ch!=' '&&ch!='\n'&&ch!=EOF&&ch!='^')
        {
            inp[i] = ch;
            i++;
            ch = getchar();
        }
        if(amountofstr == 0)
        {
            strcpy(inputword[0].is,inp);
            amountofstr++;
            inputword[0].times++;
        }
        else
        {
            int isnew = 1;
            for(int i = 0;i<amountofstr;i++)
            {
                if(strcmp(inputword[i].is,inp)==0)
                {
                    inputword[i].times++;
                    isnew = 0;
                }
            }
            if(isnew)
            {
                strcpy(inputword[amountofstr].is,inp);
                inputword[amountofstr].times++;
                amountofstr++;
            }
        }
        if(ch!='\n'&&ch!=EOF)
        ch = getchar();
        for(int i = 0;i<30;i++)
            inp[i] = '\0';
    }

    Sort(&inputword[0],&inputword[amountofstr-1]);

    for(int i = 0;i<amountofstr;i++)
        {
            printf("%s",inputword[i].is);
            if(i!=amountofstr-1)
                printf(" ");
        }
}

void Sort(struct word *inputword1,struct word *inputword2)
{
    int size = inputword2 - inputword1 + 1;

  //  struct word * pointer1 = inputword1;
   // struct word * pointer2 = inputword2;

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

int cmp(struct word *inputword1,struct word *inputword2)
{
    return inputword1->times <= inputword2->times;
}