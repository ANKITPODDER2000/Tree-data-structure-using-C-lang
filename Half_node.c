#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct btree{
    int value;
    struct btree *left,*right;
}bt;

typedef struct queue{
    bt *add;
    struct queue *next;
}Queue;

void insert(bt **,int );
bt *create(int );
int half_node(bt *);
void enqueue(Queue *,bt *);
bt* dequeue(void);

bt *root = NULL;
Queue *head = NULL;

int main()
{
    int i,val;
    for(i=0;i<5;i++)
    {
        printf("\nEnter the value : ");
        scanf("%d",&val);
        insert(&root,val);
    }
    printf("\nTotal Number of Half Node is : %d",half_node(root));
    return 0;
}
void insert(bt **ptr,int val)
{
    if(*ptr==NULL)
        *ptr = create(val);
    else if ((*ptr)->value >= val)
        insert(&(*ptr)->left,val);
    else
        insert(&(*ptr)->right,val);
}
bt* create(int val)
{
    bt *new_node = (bt *)malloc(sizeof(bt));
    new_node->value = val;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}
void enqueue(Queue *ptr,bt *a)
{
    Queue *new_node = (Queue *)malloc(sizeof(Queue));
    new_node->add = a;
    if(ptr==NULL)
    {
        new_node->next = ptr;
        head = new_node;
        return;
    }
    while(ptr->next!=NULL)
        ptr = ptr->next;
    new_node->next = ptr->next;
    ptr->next = new_node;
}
bt* dequeue()
{
    if(head==NULL)
        return NULL;
    Queue *loc = head;
    bt *a = head->add;
    head = head->next;
    free(loc);
    return a;
}
int half_node(bt *ptr)
{
    bt *temp;
    temp = ptr;
    int count = 0;
    while(temp!=NULL)
    {
        if((temp->right==NULL && temp->left!=NULL) || (temp->right!=NULL && temp->left==NULL))
            count++;
        if(temp->left!=NULL)
            enqueue(head,temp->left);
        if(temp->right!=NULL)
            enqueue(head,temp->right);
        temp = dequeue();
    }
    return count;
}
