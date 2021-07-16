#include<stdio.h>
#include<stdlib.h>
char* Mystrcat(char *s1,char* s2);
char *s_gets(char *a,int n);
int Mystrcmp(char *one,char *two);
int Mystrlen(char *inp);
struct letter *insertnode_cycle(struct letter *head,char data);

typedef struct letter
{
    int number;//the number of a member,to make sure I know the tail node 
    char data;
    struct letter * next;
}Letter;

int main()
{
    char input[300];
    Letter *theletter = NULL;

    printf("锟斤拷锟斤拷锟斤拷一锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷母锟斤拷\n");
    s_gets(input,300);
    printf("锟斤拷母锟斤拷s锟侥筹拷锟斤拷锟斤拷%d,锟斤拷锟斤拷锟斤拷:%s\n",Mystrlen(input),input);
    for(int i = 0;i<Mystrlen(input);i++)
    {
        theletter = insertnode_cycle(theletter,input[i]);
    }
    Letter *current = theletter;
    
    
    //The first output
    printf("锟斤拷锟斤拷ASCII锟斤拷锟脚猴拷锟斤拷锟斤拷锟侥革拷锟斤拷锟絓n%c",current->data);
    while(current->next->number!=0)
    {
        printf("%c",current->next->data);
        current = current->next;
    }
    printf("\n"); 
    current = theletter;

    //The second output
    printf("The data is %c\n",current->data);
    current = current->next;
    while(current->number!=0)
    {
        printf("The data is %c\n",current->data);
        current = current->next;
    }

    //free memory
    Letter *prev = theletter;
    current = theletter;
    while(current->next->number!=0)
    {
    	prev = current;
    	current = current->next;
    	free(prev);
    }
    free(current);
 
    return 0;

}

struct letter *insertnode_cycle(struct letter *head,char data)
{
    Letter *ptd = head,*pr = head,*temp = NULL;
    ptd = (Letter*)malloc(sizeof(Letter));
    if(ptd == NULL)
    {
        printf("memory has been run out");
        exit(0);
    }
    ptd->next = NULL;
    ptd->data = data;

    if(head == NULL)
    {
        head = ptd;
        head->next=head;
        head->number = 0; 
    }
    else
    {
        while(pr->data<data&&pr->next->number!=0)
        {
            temp = pr;
            pr = pr->next;
        }
        if(pr->data>=data)
        {
            if(pr == head)
            {
                ptd->next = head;
                Letter *iterator = head;
                while(iterator->next->number!=0)
                {
                    iterator->next->number++;
                    iterator = iterator->next;
                }
                head->number++;
                head = ptd;
                head->number = 0;
                iterator->next = head;
            }
            else
            {
                ptd->next = pr;
                Letter *iterator = pr;
                while(iterator->next->number!=0)
                {
                    iterator->next->number++;
                    iterator = iterator->next;
                }
                pr->number++;
                ptd->number = pr->number - 1;
                temp->next = ptd;
            }
        }
        else
        {
            pr->next = ptd;
            ptd->next = head;
            ptd->number = pr->number+1;   
        }
    }

    return head;
    
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


int Mystrlen(char *inp)
{
    int i = 0;
    while(inp[i]!= '\0')
        i++;
    return i;
}
