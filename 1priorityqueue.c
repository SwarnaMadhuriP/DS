#include<stdio.h>
#define  size  2
int queue[20],rear=-1,front=-1;
void  enqueue();
int   dequeue();
void enqueue(int data)

{

    if (rear >= MAX - 1)

    {

        printf("\nQueue overflow no more elements can be inserted");

        return;

    }

    if ((front == -1) && (rear == -1))

    {

        front++;

        rear++;

        pri_que[rear] = data;

        return;

    }    

    else

        check(data);

        rear++;

}
}
void dequeue(int data)

{

    int i;

 

    if ((front==-1) && (rear==-1))

    {

        printf("\nQueue is empty no elements to delete");

        return;

    }

 

    for (i = 0; i <= rear; i++)

    {

        if (data == pri_que[i])

        {

            for (; i < rear; i++)

            {

                pri_que[i] = pri_que[i + 1];

            }

 

        pri_que[i] = -99;

        rear--;

 

        if (rear == -1) 

            front = -1;

        return;

        }

    }

    printf("\n%d not found in queue to delete", data);

}
void check(int data)
{
  int i,j;
  for (i = 0; i <= rear; i++)
{
   if (data >= pri_que[i])
        {
          for (j = rear + 1; j > i;j--)
              {
               pri_que[j] = pri_que[j - 1];
               }

            pri_que[i] = data;

            return;

        }

    }

    pri_que[i] = data;

}
void  display()
{
 int  i;
 if((front==-1&&rear==-1)||front>rear)
 printf("the queue is empty\n");
 else{
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
   
	
