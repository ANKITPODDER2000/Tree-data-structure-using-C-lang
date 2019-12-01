#include <stdio.h>
#include <stdlib.h>

//=============================Construct tree Structure==========================//

typedef struct btree{
    int value;
    struct btree *left,*right;
}bt;

//============================Construct Stack Structure==========================//

typedef struct stack{
    bt *add;
    struct stack *next;
}Stack;

//===========================Construct Queue Structure==========================//

typedef struct queue{
    bt *add;
    struct queue *next;
}Queue;

//============================Function Prototype==============================//


void insert(bt **,int );
bt* create(int );
void push_stack(Stack *,bt *);
bt* pop(Stack *);
void enqueue(Queue *,bt *);
bt* dequeue(void);
void levelorder_rev(void);
void display_stack(Stack *);


//=============================Global Declaration============================//

bt *root = NULL;
Stack *stack_head = NULL;
Queue *queue_head = NULL;

//===========================Main Function(Driver Function)=================//

int main()
{
    int i,val;
    for(i=0;i<6;i++)
    {
        printf("\nEnter the value to insert in tree : ");
        scanf("%d",&val);
        insert(&root,val);
    }
    levelorder_rev();
    printf("\nLevel Order in Reverse is : ");
    display_stack(stack_head);
    return 0;
}


void display_stack(Stack *ptr)
{
    if(ptr->next != NULL)
        display_stack(ptr->next);
    printf("%d ",ptr->add->value);
}


void insert(bt **ptr,int val)
{
    if(*ptr==NULL)
        *ptr = create(val);
    else if((*ptr)->value>val)
        insert(&((*ptr)->left),val);
    else
        insert(&((*ptr)->right),val);
}


bt* create(int val)
{
    bt *a = (bt *)malloc(sizeof(bt));
    a->value = val;
    a->left = NULL;
    a->right = NULL;
    return a;
}


void push_stack(Stack *ptr,bt *a)
{
    Stack *new_node = (Stack *)malloc(sizeof(Stack));
    new_node->add = a;
    if(ptr==NULL)
    {
        new_node->next = ptr;
        stack_head = new_node;
        return;
    }
    while(ptr->next!=NULL)
        ptr = ptr->next;
    new_node->next = ptr->next;
    ptr->next = new_node;
}


bt* pop(Stack *ptr)
{
    bt *a;
    if(ptr==NULL)
        return NULL;
    if(ptr->next == NULL)
    {
        a = ptr->add;
        stack_head = ptr->next;
        return (a);
    }
    while(ptr->next->next!=NULL)
        ptr =ptr->next;
    a = ptr->next->add;
    ptr->next = ptr->next->next;
}


void enqueue(Queue *ptr,bt *a)
{
    Queue *new_node = (Queue *)malloc(sizeof(Queue));
    new_node->add = a;
    if(ptr==NULL)
    {
        new_node->next = ptr;
        queue_head = new_node;
        return;
    }
    while(ptr->next!=NULL)
        ptr = ptr->next;
    new_node->next = ptr->next;
    ptr->next = new_node;
}


bt* dequeue(void)
{
    if(queue_head==NULL)
        return NULL;
    bt *a = queue_head->add;
    queue_head = queue_head->next;
    return a;
}


void levelorder_rev(void)
{
    bt *temp;
    temp = root;
    //printf("\n%d %d %d",temp->value,temp->left->value,temp->right->value);
    while(temp!=NULL)
    {
        push_stack(stack_head,temp);
        if(temp->right!=NULL)
            enqueue(queue_head,temp->right);
        if(temp->left!=NULL)
        {
            enqueue(queue_head,temp->left);
        }
        temp =dequeue();
    }
}
