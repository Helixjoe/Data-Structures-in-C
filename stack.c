#include<stdio.h>

int push(int a[10],int top,int s);
int pop(int a[10],int top);
void display(int a[10],int top);
void status(int a[10],int top,float s);

int main()
{

	int arr[10],top=-1,ch,size;
	char cont='y';
	printf("Enter size of stack");
	scanf("%d",&size);
	while(cont == 'y')
	{
		printf("1. PUSH");
		printf("\n2. POP");
		printf("\n3. DISPLAY");
		printf("\n4. STATUS");
		printf("\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		
		{
			case 1:
				top = push(arr,top,size);
				break;
			case 2:
				top =pop(arr,top);
				break;
			case 3:
				display(arr,top);
				break;
			case 4:
				status(arr,top,size);
				break;
			default:
				printf("Enter the choice again");
				break;
		} 
		printf("\n Continue?(y/n)");
		scanf(" %c",&cont);
	}
	
	
	return 0;
}



int push(int a[10],int top,int s)
	{
		int item;
		if (top == s - 1)
			printf("Stack is FULL");
		else
		{
			printf("Enter Item to push:");
			scanf("%d",&item);
			top++;
			a[top] = item;
		}
		return top;
	}

int pop(int a[10],int top)
{
	if(top==-1)
		printf("Stack is EMPTY");
	else
	{
		printf("Item to be popped is %d",a[top]);
		top--;
	}
	return top;
}	
void display(int a[10],int top)
	{
		int i;
		if(top == -1)
			printf("Stack is empty");
		else 
		{
			for(i=top;i>=0;i--)
			{
				printf("%d\n",a[i]);
			} 
		}
	}

void status(int a[10],int top,float s)
{
	float free;
	if(top==-1)
	{
		printf("Stack is empty");
	}
	else
	{
			printf("Stack TOP Element is:%d\n",a[top]);
			if(top == s - 1)
				printf("Stack is full");
			else 
			{
				free = ((s-top-1)/s)*100;
				printf("Space free is %f",free);
			}
	}
}

