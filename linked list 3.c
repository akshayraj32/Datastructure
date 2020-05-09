/*program for creating a linked list with options os append addafter addatbegin etc*/
//akshay
#include<stdio.h>
#include<stdlib.h>	//required for malloc and exit function
struct node			//structure declaration
{
	int data;
	struct node* link;
};
struct node* root=0;		//globally initialised the root of linked list
void append(int);
void addatbegin(int);
void addafter(int,int);
int length();
void display();
main()
{
	int choice,item,loc,len;
	while(1)		//an infinite loop
	{
		printf("\nEnter your choice\n");
		printf("1.Append\n");
		printf("2.Add at begin\n");
		printf("3.Add after\n");
		printf("4.Length of list\n");
		printf("5.Display list\n");
		printf("6.Exit\n");			//exit function is necessary in infinite loop 
									//in order to terminate the loop
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the number\n");
					scanf("%d",&item);
					append(item);
					break;
			case 2:printf("Enter the number\n");
					scanf("%d",&item);
					addatbegin(item);
					break;
			case 3:printf("Enter the number\n");
					scanf("%d",&item);
					printf("Enter the location\n");
					scanf("%d",&loc);
					addafter(item,loc);
					break;
			case 4:len=length();
					printf("Length of list is %d\n",len);
					break;
			case 5:display();
					break;
			case 6:exit(0);
		}
	}
	getch();
}
void append(int item)	//code for inserting number at last of the linked list
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->link=0;
	if(root==0)
	{
		root=temp;
	}
	else
	{
		struct node* ptr;
		ptr=root;
		while(ptr->link!=0)
		{
			ptr=ptr->link;
		}
		ptr->link=temp;
	}
}
void addatbegin(int item)	//code for insert number in begining of linked list 
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->link=0;
	if(root==0)
	{
		root=temp;
	}
	else
	{
		temp->link=root;
		root=temp;
	}
}
void addafter(int item,int loc)	//insert numer at specified location
{
	int len,count=1;
	len=length();
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->link=0;
	if(loc>len)
	{
		printf("Invalide location\n");
	}
	else
	{
		struct node* ptr;
		ptr=root;
		while(count<loc)
		{
			ptr=ptr->link;
			count++;
		}
		temp->link=ptr->link;
		ptr->link=temp;
	}
	
	
}
int length()    //code for finding number of nodes in linked list i.e length
{
	int count=0;
	struct node* temp;
	temp=root;
	while(temp!=0)
	{
		temp=temp->link;
		count++;
	}
	return count;
}
void display()		//display the elements of linked list
{
	struct node* temp;
	temp=root;
	if(temp==0)
	{
		printf("List is empty\n");
	}
	else 
	{
		while(temp!=0)
		{
			printf("%d\t",temp->data);
			temp=temp->link;
		}
	}
}









