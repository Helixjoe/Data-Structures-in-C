#include<stdio.h>
struct PQUEUE{
    int num;
    int p;
}pq[10];

//Function Declaration
void ENQUEUE(int i,int pr);
void DEQUEUE();
void DISPLAY();
//Global Variables

int front=-1,rear=-1,k=0;
int size;
int main()
{
    char ch = 'y';
    int op,item,pr;
    printf("Enter size of Priority Queue:");
    scanf("%d",&size);
    while(ch=='y')
    {
        printf("1)ENQUEUE  2)DEQUEUE  3)DISPLAY\n");
        scanf("%d",&op);
        if(op==1)
        {
            printf("Enter number:");
            scanf("%d",&item);
            printf("Enter priority:");
            scanf("%d",&pr);
            ENQUEUE(item,pr);
        }
        else if(op==2)
        {
            DEQUEUE();
        }
        else if(op == 3)
        {
            DISPLAY();
        }
        else
        {
            printf("Choice does not exist");
        }
        printf("\nDo you want to continue?(y/n)");
        scanf(" %c",&ch);
    }
}

void ENQUEUE(int n,int pr)
{
    int loc,i;
    if (front==1 && rear==size-1)
    {
        printf("QUEUE is FULL");
    }
    else if(front == -1 && rear == -1)
    {
        rear = 0;
        front = 0;
        pq[rear].num = n;
        pq[rear].p = pr;
    }
    else if(rear == size -1)
    {
        for(i=front;i<rear;i++)
            pq[i-1] = pq[i];
        front--;
        rear--;
        for(i=rear;i>=front;i--)
            if(pq[i].p<pr)
                break;
        loc = i+1;
        for(i=rear;i>=loc;i--)
            pq[i+1] = pq[i];
        pq[loc].p = pr;
        pq[loc].num = n;
        rear++;
    }
    else
    {
        for(i=rear;i>=front;i--)
            if(pq[i].p<pr)
                break;
        loc = i+1;
        for(i=rear;i>=loc;i--)
            pq[i+1] = pq[i];
        pq[loc].p = pr;
        pq[loc].num = n;
        rear++;
    }

}

void DEQUEUE()
{
    if(front==-1)
        printf("QUEUE is Empty");
    else if(front==rear)
    {
        printf("Dequeued item is %d",pq[front].num);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Dequeued item is %d",pq[front].num);
        front++;
    }
}

void DISPLAY()
{
    int i;
    if(front==-1)
        printf("The Queueu is Empty");
    else
    {
        for(i=front;i<=rear;i++)
            printf("%d ",pq[i].num);
    }
}