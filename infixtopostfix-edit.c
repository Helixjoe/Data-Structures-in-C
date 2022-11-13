#include<stdio.h>

int push(char a[20],int top,char inf[20],int i);
int pop(char a[20],int top);
void display(int a[10],int top);
int precedance(int x,int y);

int main()
{
	char inf[20],post[20],s[20];
	int i=0,top=-1,k=0;
	printf("Enter Infix Expression");
	scanf("%s",inf);

	while(inf[i]!='\0')
	{
		
		if((inf[i]>='0' && inf[i]<='9')||(inf[i] >='A' && inf[i] <='Z'))
		{
			post[k] = inf[i];
			k++;
		}
		else if(inf[i] == '(')	
		{
			top = push(s,top,inf,i);
		}
		else if(inf[i] == ')')
		{
			if(s[top] != '(')
			{
				
				post[k] = s[top];
				top = pop(s,top);
				k++;
			}
			else
			{
				printf("BRacket time");
				top = push(s,top,inf,i);
			}		
		}
		else // operator condition
		{
			
			if (top == -1 || s[top-1] =='(')
			{
				top = push(s,top,inf,i);
				printf("s[top] = %c\n",s[top-1]);
			}
			else
			{
				while(precedance(inf[i],post[k])==1)
				{
					printf("Operator found");
					top = pop(s,top);
					post[k] = s[top];
					k++;
				}
				if(top == -1 || s[top] == '(')
					break;
			}
			top = push(s,top,inf,i);
		}
		i++;
	}
	
	while(top>0)
	{
		top = pop(s,top);
		post[k] = s[top];
		k++;
	
	}
	post[k] = '\0';
	k = 0;
	while(post[k] != '\0')
	{	
		printf("%c",post[k]);
		k++;
	}
	
	return 0;
}



int push(char a[20],int top,char inf[20],int i)
	{
		
			a[top] = inf[i];
			top++;
			return top;
	}

int pop(char a[20],int top)
{
	if(top==-1)
		printf("Stack is EMPTY");
	else
	{
		top--;
	}
	return top;
}	


int precedance(int x,int y)
{
	if(y == '*' || y == '/')
	{
			return 1;	 		
	}
	else if(y=='+' || y=='-')
	{
		if(x == '+' || x == 'y')
			return 1;
		else 
			return 0;
	}
}
