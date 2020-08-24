#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
int data;
struct node * next;
};
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
void sort_list(struct node**head){
	int flag,temp;
	struct node * ptr;
	if(*head==NULL){
		printf("no nodes in list\n");
		return ;
	}
	do{
		flag=0;
		ptr=*head;
		while(ptr->next!=NULL)
		{
			if(ptr->data>ptr->next->data){
				temp=ptr->data;
				ptr->data=ptr->next->data;
				ptr->next->data=temp;
				flag=1;}
		        ptr=ptr->next;
		 }
				
	}while(flag);
	printf("\n the sorted list is \n");
	ptr=*head;
	while(ptr!=NULL){
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
}
	
	 
 void display(struct node *head){
struct node * q;
 q=head;
 while(q!=NULL)
 {
  printf("The elements of the list are %d\n",q->data);
  q=q->next;}
}
int main(){
int choice;
 struct node * r,*k,*p,*q;
 printf("enter 0-create,1-concat,2-reverse ,3-display ,4-exit\n");
 do{
 printf("enter choice\n");
 scanf("%d",&choice);
 switch(choice){
 case 0:r=create_list();
        break;
 case 1:
         k=create_list();
         p=create_list();
         q= concat(&k,&p);
         display(q);
        break;
 
 case 2:reverse(&r);
        break;
 case 3:sort_list(&r);
        break;
 
 case 4:
        display(r);
        break;
 default:
         printf("please enter a valid option\n");}
 }while(choice!=5);
 return 0;
}
		 
		 

