#include<stdio.h>
#include<malloc.h>
struct node{
int data;
struct node * next;
};
void delete_begin(struct node **head_ref)
{
 struct node * temp;
 temp=*head_ref;
 if(temp==NULL){
  printf("the list is empty so deletion is not possible\n");}
 *head_ref=temp->next;
  free(temp);
}

 void  delete_end(struct node *head)
{
  struct node *temp =head;
  struct node *t;
  while(temp->next != NULL)
  {
    t=temp;
    temp=temp->next;
  }
  free(t->next);
  t->next=NULL; 

}
/* Given a reference (pointer to pointer) to the head of a list 
   and a position, deletes the node at the given position */
void deleteNode(struct node **head_ref, int position) 
{ 
   // If linked list is empty 
   if (*head_ref == NULL) 
      return; 
  
   // Store head node 
   struct node* temp = *head_ref; 
  
    // If head needs to be removed 
    if (position == 0) 
    { 
        *head_ref = temp->next;   // Change head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Find previous node of the node to be deleted 
    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next; 
  
    // If position is more than number of ndoes 
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    // Node temp->next is the node to be deleted 
    // Store pointer to the next of node to be deleted 
    struct node *next = temp->next->next; 
  
    // Unlink the node from linked list 
    free(temp->next);  // Free memory 
  
    temp->next = next;  // Unlink the deleted node from list 
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
void insert_begin(struct node ** head_ref,int val)
{
 struct node * new_node;
 new_node=(struct node *)malloc(sizeof(struct node));
 new_node->next=* head_ref;
 *head_ref=new_node;
  new_node->data=val;
}
void insert_end(struct node**head_ref,int val)
{
struct node * q,*new_node;
 q=*head_ref;
 new_node=(struct node*)malloc(sizeof(struct node));
 new_node->data=val;
 new_node->next=NULL;
while (q->next != NULL) {
        q = q->next;}
    q->next = new_node; 
   
}
void insert_sp(int item, int p,struct node**head_ref) 
{ 
   
    int i;
    struct node *temp=*head_ref;
    struct node * new;
    if(p==1){
     insert_begin(&temp,item);}
    else{
     for(i=0;i<p-2;i++){
     temp=temp->next;}
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->next=temp->next;
    temp->next=new;
}
} 

int main()
{
 int choice,val,p;
 struct node * r;
 printf("enter 0-create,1-insertion_begin,2-insert_end,3-insert_sp,4-deletion_begin,5-delete_sp,6-delete_end,7-display and 8-exit\n");
 do{
 printf("enter choice\n");
 scanf("%d",&choice);
 switch(choice){
 case 0:r=create_list();
        break;
 case 1:printf("enter the value to be inserted at the begin\n");
        scanf("%d",&val);
        insert_begin(&r,val);
        break;
 
 case 2:printf("enter the value to be inserted at the end\n");
        scanf("%d",&val);
        insert_end(&r,val);
        break;
 case 3:printf("enter the value to be inserted at the specific position and also position\n");
        scanf("%d%d",&val,&p);
        insert_sp(val,p,&r);
        break;
 case 4:
        delete_begin(&r);
        break;
 case 5:printf("enter the position from which it is to be deleted\n");
        scanf("%d",&p);
        deleteNode(&r,p) ;
        break;
 case 6:
        delete_end(r);
        break;
 case 7:
        display(r);
        break;
 default:
         printf("please enter a valid option\n");}
 }while(choice!=8);
 return 0;
}

