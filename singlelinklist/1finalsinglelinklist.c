#include<stdio.h>
#include<malloc.h>
struct node{
int data;
struct node * next;
};

void insert(struct node **head_ref)
{
 
int k=0,rno;

struct node *p,*q,*new;
 
new=(struct node*)malloc(sizeof(struct node));

printf("enter the data to be inserted\n");
 
scanf("%d",&new->data);

printf("Insert before roll \n");
 
scanf("%d",&rno);

p=*head_ref;
  
if(p->data==rno)//insertion at the beginning.

  {
     new->next=p;  
    *head_ref=new;
  }
 
else
 {
   while((p!=NULL)&&(p->data!=rno))
 {
  
  q=p;
    p=p->next;
  }

if(p==NULL)//insertion at the end.
{
  q->next=new;
  new->next=NULL;
}

else if(p->data==rno)//insertion at the middle.

{
 q->next=new;
 new->next=p;
}
}

}


void delete(struct node **head_ref)
{
 int k=0,rno;
 struct node *p,*q;
 printf("delete  roll \n");
 scanf("%d",&rno);
 p=*head_ref;
 if(p->data==rno)//deletion at the start
{
  *head_ref=p->next;
   free(p);
}
else
{
 while((p!=NULL)&&(p->data!=rno))
{
  q=p;
  p=p->next;
}
if(p==NULL)//element not found.
{
  printf("no match found deletion failed\n");
}
else if(p->data==rno)//element found at the middle.
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
  scanf("%d",&p->data);
 }
p->next=NULL;
return head;
}
void display(struct node *head){
struct node * q;
 q=head;
 while(q!=NULL)
 {
  printf("The elements of the list are %d\n",q->data);
  q=q->next;}
}
int main()
{
 int choice;
 struct node * r;
 printf("enter 1-insertion,2-deletion,3-display and 4-exit\n");
 do{
 printf("enter choice\n");
 scanf("%d",&choice);
 switch(choice){
 case 0:r=create_list();
        break;
 case 1:
        insert(&r);
        break;
 case 2:
        delete(&r);
        break;
 case 3:
        display(r);
        break;
 default:
         printf("please enter a valid option\n");}
 }while(choice!=4);
 return 0;
}
