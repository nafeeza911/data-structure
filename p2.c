#include <stdio.h>
#include<stdlib.h>
#define SIZE 10

int stk[SIZE];
int sp=-1;

void push(int);
int pop();
void display();

void main()
{
int opt,item;

do{
printf("1.push \n2.pop \n3.display \n4.exit \n");
printf("your option:");
scanf("%d",&opt);

switch(opt)
{
case 1:
printf("enter item: ");
scanf("%d",&item);
push(item);
break;

case 2:
item=pop();
if(item!=-1)
printf("popped value:%d \n",item);
break;

case 3:
display();
break;
case 4:
exit(0);

default:
printf("invalid option");
}
}
while(1);
}

void push(int x)
{
if(sp==SIZE-1)
{
printf("stack is full");
return;
}
else
{
stk[++sp]=x;
return;
}
}

int pop()
{
if(sp==-1)
{
printf("empty stack\n");
return -1;
}
else
{
return stk[sp--];
}
}

void display()
{
int i;

if(sp==-1)
{
printf("stack is empty\n");
return;
}

for(i=sp;i>=0;i--)
{
printf("%d\n",stk[i]);
}
}
