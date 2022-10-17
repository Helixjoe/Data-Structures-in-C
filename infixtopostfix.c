#include<stdio.h>

int push(char a[20],int top,int i);
int pop(int a[20],int top);
void display(int a[10],int top);


int main()
{
	char inf[20],post[20],s[20];
	scanf("%s",inf);
	printf("%s",inf);
	int i=0,top=-1,k=0;
	while(inf[i]!='\0')
	{
		if(inf[i]>=0 && inf[i]<=9)
		{
			post[k] = inf[i];
			k++;
		}
		else if(inf[i] == ')')	
			top = push(s,top,i);
		else if(inf[i] == '(')
			top = 
	}
	
	

	return 0;
}



int push(char a[10],int top,int i)
	{
		int item;
		if (top == s - 1)
			printf("Stack is FULL");
		else
		{
			top++;
			a[top] = a[i];
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


