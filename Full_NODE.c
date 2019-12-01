#include <stdio.h>
#include <stdlib.h>

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
int full_node(bt *);
void enqueue(Queue *,bt *);
bt* dequeue(void);

bt *root = NULL;
Queue *head = NULL;

int main()
{
    int i,val,op;
    while(1)
    {
        printf("\nEnter 1->Inser\nEnter 2->No of Full Node\nEnter 3->Exit\nEnter the Operation : ");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("\nEnter the value : ");
                scanf("%d",&val);
                insert(&root,val);
                break;
            case 2:
                printf("\nTotal Number of Half Node is : %d",full_node(root));
                break;
            case 3:
                printf("\nEnd Of Program.");
                exit(0);
            default:
                printf("\nWrong Input.");
        }
        printf("\nEnter any key to Continue : ");
        getch();
        system("cls");s
    }
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
int full_node(bt *ptr)
{
    bt *temp;
    temp = ptr;
    int count = 0;
    while(temp!=NULL)
    {
        if(temp->right!=NULL && temp->left!=NULL)
            count++;
        if(temp->left!=NULL)
            enqueue(head,temp->left);
        if(temp->right!=NULL)
            enqueue(head,temp->right);
        temp = dequeue();
    }
    return count;
}

