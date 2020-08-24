#include<stdio.h>
#include<malloc.h>
struct node{
int value;
struct node * next;
};
void insert(struct node ** head_ref,int val)
{
 struct node * new_node;
 new_node=(struct node *)malloc(sizeof(struct node));
 new_node->next=* head_ref;
 *head_ref=new_node;
  new_node->value=val;
}
void end(struct node**head_ref,int val)
{
struct node * q,*new_node;
 q=*head_ref;
 new_node=(struct node*)malloc(sizeof(struct node));
 new_node->value=val;
 new_node->next=NULL;
while (q->next != NULL) {
        q = q->next;}
    q->next = new_node; 
   
}

void insertAfter(struct node* prev_node, int new_data) 
{ 
   
    if (prev_node == NULL)  
    {printf("the given previous node cannot be NULL");}   
    struct node* new_node =(struct node*) malloc(sizeof(struct node)); 
    new_node->value  = new_data; 
    new_node->next = prev_node->next;  
    prev_node->next = new_node; 
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
 insert(&r,1);
 end(&r,5);
 insertAfter(r->next->next->next->next, 8); 
 display(r);
 return 0;
}

