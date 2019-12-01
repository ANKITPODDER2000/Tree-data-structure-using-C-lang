#include <stdio.h>
#include <stdlib.h>

typedef struct btree{
    int value;
    struct btree *left ,*right;
}bt;

typedef struct queue{
    struct queue *next;
    bt *add;
}Queue;

void insert(bt **,int );
bt* create_node(int );
bt *pop();
void push(Queue *,bt *);

bt *root = NULL;
Queue *head = NULL;

int main()
{
    int i,val,op;
    while(1)
    {
        printf("\nEnter 1->Insert\nEnter 2->LevelOrder\nEnetr 3->Exit\nEnetr the Operation : ");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("\nEnter the value to insert in btree : ");
                scanf("%d",&val);
                insert(&root,val);
                break;
            case 2:
                levelordervalue(root);
                break;
            case 3:
                printf("\nEnd Of Program.");
                exit(0);
            default:
                printf("\nWrong input,Try Again.");
                break;
        }
        printf("\nEnter any key to Continue : ");
        getch();
        system("cls");
    }
    return 0;
}

void levelordervalue(bt *ptr)
{
    if(ptr==NULL)
    {
        printf("\nEmpty Tree.");
        return;
    }
    printf("\nLevel order representation of tree : ");
    bt *temp=ptr;
    while(temp!=NULL)
    {
        printf("%d ",temp->value);
        if(temp->left!=NULL)
            push(head,temp->left);
        if(temp->right!=NULL)
            push(head,temp->right);
        temp = pop();
    }
}

bt* create_node(int val)
{
    bt *a = (bt *)malloc(sizeof(bt));
    a->value = val;
    a->left = NULL;
    a->right = NULL;
    return a;
}
void insert(bt **ptr,int val)
{
    if(*ptr==NULL)
        *ptr = create_node(val);
    else if((*ptr)->value>val)
        insert(&((*ptr)->left),val);
    else
        insert(&((*ptr)->right),val);
}
int isEmpty(Queue *ptr)
{
    if(ptr==NULL)
        return 1;
    return 0;
}
void push(Queue *ptr,bt *a)
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
bt* pop()
{
    if(head==NULL)
        return NULL;
    bt *loc = head->add;
    head = head->next;
    return loc;
}
