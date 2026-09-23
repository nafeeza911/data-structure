#include<stdio.h>
#include<stdlib.h>
#define SIZE 10 

int Q[SIZE];
int front=0,rear=0;
void enqueue(int);
int dequeue();
void display();
int main()
{
int opt,item;
do
{
printf("\n1.Enqueue\n2.dequeue\n3.display\n4.Exit\n");
printf("your option: ");
scanf("%d",&opt);
switch(opt)
{
case 1:
printf("Enter item: \n");
scanf("%d",&item);
enqueue(item);
break;
case 2:
item=dequeue();
if(item!=-1)
printf("popped value=%d\n",item);
break;
case 3:
display();
break;
case 4:
exit(0);
default:
printf("invalid option\n");
}
}
while(1);
return 0;
}
void enqueue(int x)
{
int temp;
temp=(rear+1)%SIZE;
if(temp==front)
printf("queue is full\n");
else
{
rear=temp;
Q[rear]=x;
}
}
int dequeue()
{
if(front==rear)
{
printf("Queue is empty\n");
return -1;
}
else
{
front=(front+1)%SIZE;
return Q[front];
}
}
void display()
{
int i;
if(front==rear)
{
printf("Queue is empty\n");
return;
}
printf("queue elements are: ");
i=(front+1)%SIZE;
while(1)
{
printf("%d ",Q[i]);
if(i==rear)
break;
i=(i+1)%SIZE;
}
printf("\n");
}

