#include<stdio.h>
#include<malloc.h>
struct node{
int data;
struct node * next;
struct node * prev;
};
void insert(struct node **head_ref,int val)
{
 struct node * new_node;
 new_node=(struct node *)malloc(sizeof(struct node));
 new_node->data=val;
 new_node->prev=NULL;
 if(*head_ref==NULL)
{
  new_node->next=NULL;
  *head_ref=new_node;
}
 else{
 new_node->next=*head_ref;
 (*head_ref)->prev=new_node;
 *head_ref=new_node;}
}
void end(struct node **head_ref,int val)
{
 struct node * new_node,*temp;
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=val;
  new_node->next=NULL;
  temp=*head_ref;
  while(temp->next!=NULL){
    temp=temp->next;
   }
  temp->next=new_node;
  new_node->prev=temp;
  }
void afterspecific(struct node **head_ref,int location,int val)
{
 struct node * new_node,*temp1,*temp2;
 new_node=(struct node *)malloc(sizeof(struct node));
 new_node->data=val;
 temp1=*head_ref;
 while((temp1->data!=location)&&(temp1!=NULL))
{
  temp1=temp1->next;
}
 if(temp1==NULL)
{
  printf("The element is not found in the list\n");}
 if(temp1->data==location)
{
  temp2=temp1->next;
  temp1->next=new_node;
  new_node->prev=temp1;
  new_node->next=temp2;
}
}
void delete(struct node **head_ref)
{
 struct node* temp;
 temp=*head_ref;
 if(temp->next==temp->prev)
{
 *head_ref=NULL;
  free(temp);
}
else{
 *head_ref=temp->next;
 (*head_ref)->prev=NULL;
  temp->next->prev=(*head_ref);
  free(temp);
}
}
void delend(struct node **head_ref)
{
struct node* temp;
 temp=*head_ref;
 if(temp->next==temp->prev)
{
 *head_ref=NULL;
  free(temp);
}
while(temp->next!=NULL)
{
   temp=temp->next;
}
 temp->prev->next=NULL;
  free(temp);
}
void specific(struct node **head,int location)
{
 struct node * temp;
 while((temp->data!=location)&&(temp!=NULL))
{
  temp=temp->next;
}
 if(temp==NULL)
{
  printf("The element is not found in the list\n");}
 if(temp->data==location)
{
  if(temp->next==temp->prev){
   *head=NULL;
    free(temp);}
  else if(temp==*head){
    *head=(*head)->next;
    (*head)->prev=NULL;
    free(temp);}
  else if(temp->next==NULL)
   {
    temp->prev->next=NULL;
    free(temp);}
  else{ temp->prev->next=temp->next;
   temp->next->prev=temp->prev;
   free(temp);
  }
   
}
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
  struct node *head=NULL;
  insert(&head,1);
  insert(&head,2);
  insert(&head,3);
  insert(&head,4);
  end(&head,5);
  afterspecific(&head,2,7);
  delete(&head);
  delend(&head);
  specific(&head,3);
  printlist(head);
  return 0;
}
 
