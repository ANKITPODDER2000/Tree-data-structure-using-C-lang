#include <stdio.h>
#include <stdlib.h>

typedef struct btree{
    int value;
    struct btree *left,*right;
}BT;

BT* create(int );
void insert(BT **,int );
void push(BT *);
BT* pop(void);
int isEmpty();
void inorder(BT *);

BT *root = NULL;
BT* stack[100];
int top=-1;
int main()
{
    int op,val;
    while(1)
    {
        printf("\nEnter 1->Insert\nEnter 2->InOrder Traversal\nEnter 3->Exit\nEnetr the Operation : ");
        scanf("%d",&op);
        switch(op){
            case 1:
               printf("\nEnter the value : ") ;
               scanf("%d",&val);
               insert(&root,val);
               break;
            case 2:
                inorder(root);
                break;
            case 3:
                printf("\nEnd of Program.");
                exit(0);
        }
    }
    return 0;
}
BT* create(int val)
{
    BT *new_node = (BT *)malloc(sizeof(BT));
    new_node->value = val;
    new_node->left  = NULL;
    new_node->right = NULL;
    return new_node;
}
void insert(BT **ptr,int val)
{
    if(*ptr==NULL)
        *ptr = create(val);
    else if((*ptr)->value > val)
        insert(&((*ptr)->left),val);
    else
        insert(&((*ptr)->right),val);
}
void preorder(BT *ptr)
{
    BT *temp;
    temp = ptr;
    push(temp);
    while(isEmpty())
    {
        temp = pop();
        printf("%d ",temp->value);
        if(temp->right)
            push(temp->right);
        if(temp->left)
            push(temp->left);
    }
}
void push(BT *ptr)
{
    stack[++top] = ptr;
}
BT* pop()
{
    if(top==-1)
        return NULL;
    return stack[top--];
}
int isEmpty()
{
    if(top==-1)
        return 0;
    return 1;
}

