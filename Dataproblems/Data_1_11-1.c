#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct list_t
{
   int s;
   struct list_t*next;
}List;
void ListDelete(List* head, int n)
{
  List *nowList=head->next;
  int now=0;
  while(nowList->next!=NULL)
  {
    if(now==n-1)
    {
      break;
    }
    nowList=nowList->next;
    now++;
  }
  if(now==n-1&&nowList->next!=NULL)
  {
    nowList->next=nowList->next->next;
  }
}
void ListFree(List* head) {
    if (head->next != NULL) {
		ListFree(head->next);
		head->next = NULL;
	}
	free(head);
}
int main()
{
  int a[100];
  int i=0,j,x=1;
  while(a[i++]!=-1)
  {
    scanf("%d ",&a[i]);
  }
  List *head=(List*)malloc(sizeof(List));
  List *now=head;
  List *p=(List*)malloc(sizeof(List));
  head->s=a[1];
  for(i=1;a[i]!='\0';i++)
  {
    for(j=0;j<i;j++)
    {
      if(a[i]=a[j])
      {
        x=0;
      }
    }
    if(x)
    {
  	  now=now->next;
      p->s=a[i];
      now->s=p->s;
    }
  }
  now->next=NULL;
  int n;
  scanf("%d",&n);
  ListDelete(head,n);
  List *Head=head->next;
  while(Head!=NULL)
  {
    printf("%d ",Head->s);
    Head=Head->next;
  }
  ListFree(head);
  return 0;
}