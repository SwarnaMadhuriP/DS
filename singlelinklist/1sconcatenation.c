#include<stdio.h>
#include<malloc.h>
struct node{
int data;
struct node * next;
};
struct node* concat(struct node**h1,struct node**h2)
{
  struct node *rh,*temp;
 if(*h1!=NULL&&*h2==NULL)
  rh=*h1;
 else if(*h1==NULL&&*h2!=NULL)
  rh=*h2;
 else
   temp=*h1;
   rh=*h1;
   while(temp->next!=NULL)
   {
    temp=temp->next;
    
   }
   temp->next=*h2;
  return(rh);
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
 struct node *p,*r,*q;
 r=create_list();
 p=create_list();
 q= concat(&r,&p);
 printlist(q);
 return 0;
}
 
