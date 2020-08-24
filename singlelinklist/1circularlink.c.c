#include<stdio.h>

#include<malloc.h>


struct node{
 int val;
 struct node * next;
};

struct node * create_list(){
int k, n;

struct node * p, * head;

printf("enter no of elements\n");

scanf("%d",&n);

for(k=0;k<n;k++)
{
 
if(k==0){
  
head=(struct node*)malloc(sizeof(struct node));
  
p=head;
}

else{
  
 p->next=(struct node*)malloc(sizeof(struct node));

 p=p->next;
}
  
scanf("%d",&p->val);
 
}

p->next=head;

return head;
}

void traverse(struct node** head_ref)
{

  struct node *p;
  p=*head_ref;

  do  
{
 
  printf("the elements of the circular linked list are %d\n",p->val);

  p=p->next;
}while(p!=*head_ref);

  }

int main()
{
 
struct node * q;

q=create_list();
 
traverse(&q);
 
return 0;
}
