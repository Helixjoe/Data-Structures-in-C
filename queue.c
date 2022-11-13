#include<stdio.h>

int size,q[10],front=-1,rear=-1,item,i;
void enqueue();
void dequeue();
void display();

int main()
{
	int ch;
	char cont='y';
	printf("Enter size of queue:");
	scanf("%d",&size);
	while(cont=='y')
	{
		printf("1)Enqueue \n2)Dequeue \n3)Display");
		printf("Enter choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
		}
		printf("Rear is %d",rear);
		printf("Front is %d",front);
		printf("\nDo you want to continue?(y/n)?");
		scanf(" %c",&cont);
	}
	return 0;
}

void enqueue()
{
	if(rear==size-1)
	{
	
		printf("Queue is FULL");
	}
	else if(front == -1 && rear == -1)
	{
		printf("Enter item to enqueue");
		scanf("%d",&item);
		front = 0;
		rear = 0;
		q[rear] = item;
	}
	else
	{
		printf("Enter item to enqueue");
		scanf("%d",&item);
		rear = rear + 1;
		q[rear] = item;
	}
}

void dequeue()
{
	if(front==-1 && rear ==-1)
		printf("Queue is EMPTY");
	else if(front == rear)
	{
		printf("Dequeud item is %d",q[front]);
		front = - 1;
		rear = - 1;
	}
	else if(front<rear)
	{
		printf("Dequeued item is %d",q[front]);
		front++;
	}
}

void display()
{
	if(front ==-1 && rear ==-1) 
		printf("Queue is EMPTY");
	else
	{
		for(i=front;i<=rear;i++)
			printf("%d ",q[i]);
	}

}
