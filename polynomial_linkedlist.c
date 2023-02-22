#include<stdio.h>
#include<stdlib.h>

struct poly *readPoly(struct poly *head);
void displayPoly(struct poly *head);
struct poly 
{
    int coeff;
    int exp;
    struct poly *link;
};

struct poly *p1head=NULL,*p2head=NULL,*paddHead=NULL,*pmulHead=NULL;

struct poly *readPoly(struct poly *head)
{
    struct poly *ptr,*temp;
    int n,i;
    printf("Enter number of terms of Polynomial:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp = (struct poly*)malloc(sizeof(struct poly));
        printf("Enter coefficient:");
        scanf("%d",&temp->coeff);
        printf("Enter exponent:");
        scanf("%d",&temp->exp);
        temp->link=NULL;
        if(head==NULL)  
        {
            head = temp;
            ptr = temp;
        }
        else
        {
            ptr->link = temp;
            ptr = temp; 
        }
    }
    return head;
}

void displayPoly(struct poly *head)
{
    struct poly *temp;
    temp = head;
    
    while(temp->link!=NULL)
    {
        printf("%dX^(%d)+",temp->coeff,temp->exp);
        temp=temp->link;
    }
        printf("%dX^(%d)",temp->coeff,temp->exp);
}

struct poly *addPoly(struct poly *head1, struct poly *head2)
{
    struct poly *p1=head1,*p2 =head2,*p3=paddHead,*prev;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->exp==p2->exp)
        {
            //Creating a new node
            p3 = (struct poly *)malloc(sizeof(struct poly *));
            p3->exp = p1->exp;
            p3->coeff = p1->coeff+p2->coeff;
            p3->link = NULL;
            //Checking if null or not
            if(paddHead==NULL)
            {
                paddHead = p3;
                prev = p3;
            }
            else
            {
                //connecting the previous node to the new one
                prev->link = p3;
                prev = p3;
            }
            p1 = p1->link;
            p2 = p2->link;
        }
        else if(p1->exp>p2->exp)
        {
            p3 = (struct poly *)malloc(sizeof(struct poly *));
            p3->exp = p1->exp;
            p3->coeff = p1->coeff+p2->coeff;
            p3->link = NULL;
            if(paddHead==NULL)
            {
                paddHead = p3;
                prev = p3;
            }
            else{
                prev->link = p3;
                prev = p3;
            }
            p1 = p1->link;
        }
        else
        {
            p3 = (struct poly *)malloc(sizeof(struct poly));
            p3->coeff = p2->coeff;
            p3->exp = p2->exp;
            p3->link = NULL;
            if(paddHead==NULL)
            {
                paddHead = p3;
                prev = p3;
            }
            else
            {
                prev->link = p3;
                prev = p3; 
            }
        }
    }
    while(p1!=NULL)
    {
        p3 = (struct poly *)malloc(sizeof(struct poly));
        p3->coeff = p1->coeff;
        p3->exp = p1->exp;
        p3->link = NULL;
        if(paddHead=NULL)
        {
            paddHead = p3;
            prev = p3;
        }
        else
        {
            prev->link = p3;
            prev=p3;
        }
    }
    while(p2!=NULL)
    {
        p3 = (struct poly *)malloc(sizeof(struct poly));
        p3->coeff = p2->coeff;
        p3->exp = p2->exp;
        p3->link = NULL;
        if(paddHead=NULL)
        {
            paddHead = p3;
            prev = p3;
        }
        else
        {
            prev->link = p3;
            prev=p3;
        }
    }
    return paddHead;
}

struct poly *pmulhead(struct poly *head1, struct poly *head2)
{
    struct poly *p1=head1,*p2=head2,*p3,*prev,*next,*new;
    while(p1!=NULL)
    {
        while(p2!=NULL)
        {
            p3 = (struct poly*)malloc(sizeof(struct poly));
            p3 ->coeff = p1->coeff * p2->coeff;
            p3 ->exp =  p1->coeff * p2-> exp;
            p3 ->link = NULL;
            if(pmulHead == NULL)
            {
                pmulHead = p3;
                prev = p3;
            }
            else 
            {
                prev->link = p3;
                prev = p3;
            }
            p2 = p2->link;
        }
        p1= p1->link;
        p2 = head2;
    }
    p3 = pmulHead;
    while(p3!=NULL)
    {
        prev = p3;
        next = p3->link;
        while(q!=NULL)
        {
            if(p3->exp == next->exp)
            {
                p3->coeff = p3->coeff + next->coeff;
                prev->link = next->link;
                free(next);
                next = prev->link;
            }
            else{
                prev = next;
                next = next->link;
            }
            p3 = p3->link;
        }
    }
    return pmulHead;
}
int main()
{
    p1head = readPoly(p1head);
    displayPoly(p1head);
    p2head = readPoly(p2head);
    displayPoly(p2head);
    paddHead = addPoly(p1head,p2head);
    displayPoly(paddHead);
    pmulHead = mulPoly(p1head,p2head);
    displayPoly(pmulHead);
    return 0;
}

