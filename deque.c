#include<stdio.h>
int array[50];
int front=-1;
int rear=-1;
int size;
void push();
void pop();
void inject();
void eject();
void display();
int item;
void main()
{
	int choice;
	int flag=0;
	printf("Enter the size of the queue: ");
	scanf("%d",&size);
	while(flag!=1)
	{
		printf("\n\t1.Push\n\t2.Pop\n\t3.Inject\n\t4.Eject\n\t5.Display\n\t0.Exit");
		printf("\n\tEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			push();
			break;
			case 2:
			pop();
			break;
			case 3:
			inject();
			break;
			case 4:
			eject();
			break;
			case 5:
			display();
			break;
			case 0:
			flag=1;
			break;
			default:
			printf("Invalid choice");
		}
	}
}
void push()
{
	printf("Enter the element: ");
	scanf("%d",&item);
	if(front==0&&rear==(size-1))
	{
		printf("Deque is full");
	}
	else if(front==-1&&rear==-1)
	{
		front=rear=0;
		array[front]=item;
	}
	else if(front>0)
	{
		front=(front-1);
		array[front]=item;
	}
	else
	{
		for(int i=rear;i>=front;i--)
		{
			array[i+1]=array[i];
		}
		array[front]=item;
		rear=rear+1;
	}
}

void pop()
{
	if(front==-1&&rear==-1)
	{
		printf("Deque is empty");
	}
	else if(front==rear)
	{
		printf("Dequed item is %d",array[front]);
		front=rear=-1;
	}
	else
	{
		printf("Dequed item is %d",array[front]);
		front=front+1;
	}
}

void inject()
{
	printf("Enter the element: ");
	scanf("%d",&item);
	if(front==0&&rear==size-1)
	{
		printf("Deque is full");
	}
	else if(front==-1&&rear==-1)
	{
		front=rear=0;
		array[rear]=item;
	}
	else if(rear<size-1)
	{
		rear=rear+1;
		array[rear]=item;
	}
	else
	{
		for(int i=front;i<=rear;i++)
		{
			array[i-1]=array[i];
		}
		array[rear]=item;
		front=front-1;
	}
}

void eject()
{
	if(front==-1&&rear==-1)
	{
		printf("Deque is empty");
	}
	else if(front==rear)
	{
		printf("Dequed item is %d",array[rear]);
		front=rear=-1;
	}
	else
	{
		printf("Dequed item is %d",array[rear]);
		rear=rear-1;
	}
}

void display()
{
	if(front==-1&&rear==-1)
	{
		printf("Deque is empty");
	}
	else
	{
		for(int i=front;i<=rear;i++)
		{
			printf("%d",array[i]);
		}
	}
}
