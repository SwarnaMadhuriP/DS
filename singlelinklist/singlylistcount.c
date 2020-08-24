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
 int count(struct node * head)
 {
	 int len=0;
	 struct node * temp;
	 if(head==NULL)
	 {
		 printf("the list is empty\n");
		 return len;}
	 temp=head;
	 while(temp!=NULL){
		 len++;
		 temp=temp->next;}
		 return len;
 }
 void search(int item,struct node * head)
 {
	 int i=0;
	 struct node *temp=head;
	 while((temp!=NULL)&&(temp->data!=item))
	     { temp=temp->next;i++;}
		 if(temp==NULL){
			 
			 printf("the item is not found \n");
			 
		 }
		 else if(temp->data==item){
		 i++;	
		 printf("the element is found at %d\n",i);}
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
int choice,val,c;
 struct node * r;
 printf("enter 0-create,1-count,2-search ,3-display ,4-exit\n");
 do{
 printf("enter choice\n");
 scanf("%d",&choice);
 switch(choice){
 case 0:r=create_list();
        break;
 case 1:c=count(r);
        printf("the number of nodes=%d\n",c);
        break;
 
 case 2:printf("enter the value to be searched\n");
        scanf("%d",&val);
        search(val,r);
        break;
 
 case 3:
        display(r);
        break;
 default:
         printf("please enter a valid option\n");}
 }while(choice!=4);
 return 0;
}
		 
		 
