#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *right_child;
    struct node *left_child;
}


struct node* new_node(int data)
{
    struct node* temp;
    temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->left_child = NULL;
    temp->right_child= NULL;
    return temp;
}

int main()
{
    printf("Enter root node");
    root = new_node(x);
}