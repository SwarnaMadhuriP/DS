
#include<stdio.h>
#include<malloc.h>
struct node{
int data;
struct node * next;
};
void reverse(struct node ** head_ref)
{
 struct node * next_ptr,*prev,*current;
 current=*head_ref;
 next_ptr=NULL;
 prev=NULL;
 while(current!=NULL)
{
 next_ptr=current->next;
 current->next=prev;
 prev=current;
 current=next_ptr;
}
 *head_ref=prev;
}
struct node * create_list()
{
int k, n;
struct node * p, * head;
printf("enter the number of elements in the linked list\n");
scanf("%d",&n);
for(k=0;k<n;k++)
{
 if(k==0){
  head=(struct node*)malloc(sizeof(struct node));
  p=head;
  }
 else{
  p->next=(struct node*)malloc(sizeof(struct node));
  p=p->next;}
  scanf("%d",&p->data);
 }
p->next=NULL;
return head;
}
void printlist(struct node * head)
{
 struct node * p;
 p=head;
 while(p!=NULL)
{
 printf("the elements of the list are %d\n",p->data);
 p=p->next;
 }
}
int main()
{
 struct node * r;
 r=create_list();
 reverse(&r);
 printlist(r);
 return 0;
}
