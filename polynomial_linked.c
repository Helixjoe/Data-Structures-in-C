#include<stdio.h>
#include<stdlib.h>

struct node *create_poly();
void display(struct node *h);
void add_poly(struct node *p, struct node *q);
struct node * multiply();

struct node
{
    int coeff;
    int exp;
    struct node *link;
};

struct node *phead=NULL,*qhead = NULL,*rhead = NULL;

int main()
{
    int ch;
    printf("Enter first polynomial:");
    phead = create_poly();
    printf("First Polynomial:\n");
    display(phead);
    printf("Enter second polynomial:");
    qhead = create_poly();
    printf("Second Polynomial:\n");
    display(qhead);
    /*
    printf("Choose Option: \n1)Add Polynomials \n2)Multiply Polynomials");
    scanf("%d",&ch);
    
        add_poly(phead,qhead);
        display(rhead);
   */
        
        rhead = multiply();
        display(rhead);
    return 0;
}

struct node *create_poly()
{
        int n,i;
        struct node *new,*q,*p,*ptr,*head;  
        printf("Enter number of terms:");
        scanf("%d",&n);
        new = (struct node*)malloc(sizeof(struct node));
        head = new;
        ptr = new;
        for(i =0;i<n;i++)
        {
            printf("Enter coeffecient:");
            scanf("%d",&ptr->coeff);
            printf("Enter exponent:\n");
            scanf("%d",&ptr->exp);
            new = (struct node *)malloc(sizeof(struct node));
            ptr->link = new;
            ptr = new;
        }
        ptr->link = NULL;
        return head;
}

void display(struct node *h)
{
    while((h->link)->link!=NULL)
    {
        printf("%dX^(%d) + ",h->coeff,h->exp);
        h = h->link;
    }
    printf("%dX^(%d)\n",h->coeff,h->exp);
}

void add_poly(struct node *p, struct node *q)
{ 
    struct node *new,*r;
        while(p!=NULL & q!=NULL)
        {
            new = (struct node *)malloc(sizeof(struct node));
            if(p->exp == q->exp)
            {
                new->coeff = p->coeff + q->coeff;
                new->exp = p->exp;
                new->link = NULL;
                p = p->link;
                q = q->link;
            }
            else if(p->exp>q->exp)
            {
                new->coeff = p->coeff;
                new->exp = p->exp;
                new->link = NULL;
                p = p->link;
            }
            else if(q->exp>p->exp)
            {
                new->coeff = q->coeff;
                new->exp = q->exp;
                new->link = NULL;
                q = q->link;
            }
            if(rhead==NULL){
                rhead = new;
                r = new;
            }
            else
            {
                r->link = new;
                r = r->link;
            }
        }    
        while(p!=NULL)
        {
            new->coeff = p->coeff;
            new->exp = p->exp;
            new->link = NULL;
            p = p->link;
            if(rhead==NULL){
                rhead = new;
                r = new;
            }
            else
            {
                r->link = new;
                r = r->link;
            }
        }
        while(q!=NULL)
        {
            new->coeff = q->coeff;
            new->exp = q->exp;
            new->link = NULL;
            q = q->link;
            if(rhead=NULL)
            {
                rhead = new;
                r = rhead;
            }
            else
            {
                r->link = new;
                r = r->link;
            }
        }
}



struct node * multiply()
{
    struct node *prev,*q,*p,*new,*r;
    q = qhead;
    p = phead;
    rhead = NULL;
    while(p!=NULL)
    {
        while(q!=NULL)
        {
            new = (struct node *)malloc(sizeof(struct node *));
            new->coeff = p->coeff * q->coeff;
            new->exp = p->exp + q->exp;
            new->link = NULL;
            if(rhead==NULL)
            {
                rhead = new;
                r = new;
            }
            else
            {
                r->link = new;
                r = new;
            }
            q = q->link;
        }
        p = p->link;
        q = qhead;
    }
    p = rhead;
    while(p!=NULL)
    {
        prev = p;
        q = p->link;
        while(q!=NULL)
        {
            if(p->exp == q->exp)
            {
                p->coeff = p->coeff + q->coeff;
                prev->link = q->link;
                free(q);
                q = prev->link;
            }
            else
            {
                prev = p->link;
                q = q->link;
            }
        }
        p = p->link;
    }
    return rhead;
}

    