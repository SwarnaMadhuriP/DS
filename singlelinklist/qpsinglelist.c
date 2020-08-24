#include<stdio.h>
#include<malloc.h>
struct node{
int backlog;
char name[25];
struct node * next;
};
void delete(struct node **head_ref)
{
 int k=0,rno;
 struct node *p,*q;
 printf("enter the element to be deleted rno should be greater than 4\n");
 scanf("%d",&rno);
 p=*head_ref;
 if(p->backlog==rno)//deletion at the start
{
  *head_ref=p->next;
   free(p);
}
else
{
 while((p!=NULL)&&(p->backlog!=rno))
{
  q=p;
  p=p->next;
}
if(p==NULL)//element not found.
{
  printf("no match found deletion failed\n");
}
else if(p->backlog==rno)//element found at the middle.
{
 q->next=p->next;
 free(p);
}
}
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
  scanf("%d%s",&p->backlog,p->name);
 }
p->next=NULL;
return head;
}
void display(struct node *head){
struct node * q;
 q=head;
 while(q!=NULL)
 {
  printf("The elements of the list are %d and %s \n",q->backlog,q->name);
  q=q->next;}
}
struct node* update(struct node** head_ref)
{
struct node * q;
 q=*head_ref;
 while(q!=NULL)
 {
  printf("update the number of backlogs\n");
  scanf("%d",&q->backlog);
  q=q->next;}
 }
 
int main()
{

 struct node * r;
 r=create_list();
 update(&r);
 delete(&r);
 display(r);
 return 0;
}
