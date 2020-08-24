#include<stdio.h>
#define  size  2
int queue[20],rear=-1,front=-1;
void  enqueue();
int   dequeue();
void enqueue()
{
 int  value;
 if(front==-1&&rear==-1)
 {
  front=rear=0;
  printf("enter the value to be enqueued\n");
   scanf("%d",&value);
   queue[rear]=value;
}
 else if(front==(rear+1)%size)
 printf("the queue is filled\n");
 else
  {
	  rear=(rear+1)%size;
    printf("enter the value to be enqueued\n");
    scanf("%d",&value);
   
   queue[rear]=value;
  }
}
int dequeue()
{
	int value;
	if(front==-1&&rear==-1)
	printf("the queue is empty  so dequeue cannot be performed\n");
	else if((front==rear))
	{
		value=queue[front];
		front=rear=-1;
                printf("the value dequeued is %d\n",value);
           
		
	}
	else
	{
	 value=queue[front];
	 front=(front+1)%size;
         printf("the value dequeued is %d\n",value);
          }
}
void  display()
{
   int  i;
 if(front>rear)
 {
	 for(i=front;i<size;i++)
	 {
		 printf("the elements of the queue are %d\n",queue[i]);
	}
	 for(i=0;i<=rear;i++)
	 {
		 printf("the elements of the queue are %d\n",queue[i]);
	}
}
else if(front==-1&&rear==-1){
       printf("queue is empty\n");}
else
{
	for(i=front;i<=rear;i++)
	 printf("the elements of the queue are queue[%d]= %d\n",i,queue[i]);
}
}
int main()
{
  int  choice=0;
  printf("enter the operation to be performed\n");
  printf("enter 1-enqueue , 2-dequeue , 3-display and 4-exit \n");
  do{
	  printf("enter the choice\n");
	  scanf("%d",&choice);
	  switch(choice)
	{
      case 1:
               enqueue();
               break  ;
      case 2:
 
            dequeue();
            break  ; 

      case 3:
             display();
             break  ;
      default:
          printf("please enter a valid option\n"); 
     }
 }while(choice!=4);
return 0;
}
   
	
