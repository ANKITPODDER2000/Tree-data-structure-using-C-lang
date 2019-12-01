#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct tree{
    int value;
    struct tree *left,*right;
}bt;

void insert_btree(bt **,int );
bt* create(int);
void preOrder(bt *);
void inOrder(bt *);
void postOrder(bt *);


bt *head=NULL;

int main()
{
    int op,val;
    do{
        system("cls");
        printf("\nEnter 1->Insert value in Tree\nEnter 2->Preorder\nEnter 3->Inorder\nEnter 4->Postorder\nEnter 5->Exit\nEnter the Operation : ");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("\nEnter value To insert : ");
                scanf("%d",&val);
                insert_btree(&head,val);
                break;
            case 2:
                printf("\nPre-Order of Binary Tree : ");
                preOrder(head);
                break;
            case 3:
                printf("\nIn-Order of Binary Tree : ");
                inOrder(head);
                break;
            case 4:
                printf("\nPost-Order of Binary Tree : ");
                postOrder(head);
                break;
            case 5:
                printf("\nEnd of Program.");
                exit(0);
            default:
                printf("\nWrong Input,Try Again.");
                break;
        }
        printf("\nEnter any key to continue : ");
        getch();
    }while(1);
    return 0;
}

bt *create(int data)
{
    bt *new_node = (bt *)malloc(sizeof(bt));
    new_node->value = data;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}
void insert_btree(bt **ptr,int data)
{
    if(*ptr==NULL)
        *ptr = create(data);
    else if(data > ((*ptr)->value))
        insert_btree(&((*ptr)->right),data);
    else
        insert_btree(&((*ptr)->left),data);
}
void preOrder(bt *ptr)
{
    if(ptr!=NULL)
    {
        printf("%d ",ptr->value);
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
    return;
}
void postOrder(bt *ptr)
{
    if(ptr)
    {
        postOrder(ptr->left);
        postOrder(ptr->right);
        printf("%d ",ptr->value);
    }
    return;
}
void inOrder(bt *ptr)
{
    if(ptr)
    {
        inOrder(ptr->left);
        printf("%d ",ptr->value);
        inOrder(ptr->right);
    }
    return;
}
