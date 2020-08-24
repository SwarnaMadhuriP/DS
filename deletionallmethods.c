#include<stdio.h>
#include<malloc.h>
struct node{
int value;
struct node * next;
};
void begin(struct node **head_ref)
{
 struct node * temp;
 temp=*head_ref;
 if(temp==NULL){
  printf("the list is empty so deletion is not possible\n");}
 *head_ref=temp->next;
  free(temp);
}
void end(struct node ** head_ref)
{
  struct node * temp,*prev;
  temp=*head_ref;
  while(temp!=NULL)
{
  prev=temp;
  temp=temp->next;}
  prev->next=NULL;
  free(temp);
}
void deleteNode(struct node **head_ref, int key) 
{ 
    struct node* temp = *head_ref, *prev;
    if (temp != NULL && temp->value == key) 
    { 
        *head_ref = temp->next;  
        free(temp);        
        return; 
    } 
    while (temp != NULL && temp->value != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) return;
    prev->next = temp->next; 
  
    free(temp); 
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
  scanf("%d",&p->value);
 }
p->next=NULL;
return head;
}
void display(struct node *head){
struct node * q;
 q=head;
 while(q!=NULL)
 {
  printf("The elements of the list are %d\n",q->value);
  q=q->next;}
}
int main()
{
 struct node * r;
 r=create_list();
 begin(&r);
 deleteNode(&r,4);
 end(&r);
 display(r);
 return 0;

}

