/*Program for creating a stack with options of push, pop, peek, traverse,
using static array*/
//akshay
#include<stdio.h>
#include<stdlib.h> 	//needed to use exit function
#define CAPACITY 5	//pre-processor macro
int stack[CAPACITY],top= -1;	//global declaration 
void push(int);
int pop();
void peek();
void traverse();
int isfull();
int isempty();
main()
{
	int ch, ele ;
	while(1)		//infinite loop
	{
		printf("1.push \n");
		printf("2.pop \n");
		printf("3.peek \n");
		printf("4.Traverse \n");
		printf("5.Exit\n");
		printf("Enter your choice \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the number\n");
					scanf("%d",&ele);
					push(ele);
					break;
			case 2: ele= pop();
					printf("%d \n",ele);
					break;
			case 3: peek();
					break;
			case 4: traverse();
					break;
			case 5: exit(0);
			default: printf("Invalid number \n");
		}
  
		
}
	getch();
}
void push(int item)
{
	if(isfull())
		printf("Stack overflow\n");
	else
	{
		top++;
		stack[top]=item;
		printf("Item pushed\n");
	}
	
}
int pop()
{
	int item;
	if(isempty())
	{
		printf("Stack is empty\n");
	}
	else 
	{
		item=stack[top];
		top--;
		return item;
	}
}
void peek()
{
	int item;
	if(isempty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		item=stack[top];
		printf("%d\n",item);
	}
}
void traverse()
{
	int i;
	if(isempty())
	{
		printf("Stack is empty \n");
	}
	else
	{
		for(i=0;i<=top;i++)
		{
			printf("%d\n",stack[i]);
		}
	}
}
int isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
int isfull()
{
	if(top==CAPACITY-1)
	return 1;
	else 
	return 0;
}






