#include<stdio.h>
#include<malloc.h>
struct node {
	int data;
	struct node * next;
	struct node * prev;
};
struct node * start=NULL,*temp,*newptr;
int count=0;
void creation(){
	char ch;
	if(count==0){
		newptr=(struct node*)malloc(sizeof(struct node));
		printf("enter element\n");
		scanf("%d",&newptr->data);
		start=newptr;
		newptr->next=NULL;
		newptr->prev=NULL;
	}
	while(1)
	{
		printf("\n Do u wnt to add element? Y/N\n");
		scanf("%c",&ch);
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y'){
			newptr=(struct node *)malloc(sizeof(struct node));
			printf("\n enter element");
			scanf("%d",&newptr->data);
			 start->next=newptr;
			 newptr->next=NULL;
			 newptr->prev=start;
			
		 }
		 else
		 return;
	 }}
	 void display()
	 {
		 if(start==NULL)
		 printf("\n the list is empty\n");
		 else{
			 temp=start;
			 while(temp!=NULL){
				 printf("%5d\n",temp->data);
				 temp=temp->next;
			 }
		 }
	 }
	 void insert()
	 {
		 int key;
		 if(start==NULL)
		 {
			 printf("list is empty\n");
			 return;
		 }
		 printf("\n enter key element");
		 scanf("%d",&key);
		 newptr=(struct node *)malloc(sizeof(struct node));
		 printf("enter the elment\n");
		 scanf("%d",&newptr->data);
		 if(key==start->data)
		 {
			 newptr->next=start;
			 newptr->prev=NULL;
			 start=newptr;
		 }
		 else
		 {
			 temp=start;
			 while(key!=temp->data&& temp->next!=NULL)
			  temp=temp->next;
			  if(key==temp->data)
			  {
				  newptr->next=temp;
				  newptr->prev=temp->prev;
				  temp->prev->next=newptr;
				  temp->prev=newptr;
			  }
			  else if (temp->next==NULL)
			  {
				  printf("\n entered element not found\n");
				  free(newptr);
			  }
			  return;
		  }
	  }
	  void deletion()
	  {
		 int key;
		 struct node *p;
		 p=start;
		 if(start==NULL)
		 {
			 printf("list is empty and deltion is not possible\n");
			 return;
		 }
		 printf("\n enter the data which has to be deleted");
		 scanf("%d",&key);
		 if(key==p->data)
		 {
			 newptr->next=start;
			 newptr->prev=NULL;
			 start=newptr;
		 }
		 else
		 {
			 temp=start;
			 while(key!=temp->data&& temp->next!=NULL)
			  temp=temp->next;
			  if(key==temp->data)
			  {
				  newptr->next=temp;
				  newptr->prev=temp->prev;
				  temp->prev->next=newptr;
				  temp->prev=newptr;
			  }
			  else if (temp->next==NULL)
			  {
				  printf("\n entered element not found\n");
				  free(newptr);
			  }
			  return;
		  }
	  }
		  int main(){
			  int ch;
			  printf("enter 1-create,2-insert,3-display and 4-exit\n");
			  do{
				  printf("enter choice\n");
				  scanf("%d",&ch);
				  switch(ch){
					  case 1:creation();
					         count++;
					         break;
					   case 2: insert();
					           break;
					   case 3: display();
					            break;
					   
				   }
			   }while(ch!=4);
			   return 0;
		   }
		
