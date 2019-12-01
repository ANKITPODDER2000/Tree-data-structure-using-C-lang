#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct tree{
    int value;
    struct tree *left, *right;
} BT;

void insert(BT **,int );
BT *create(int );
void printEdge(BT *root);
void printLeftEdge(BT *root);
void printRightEdge(BT *root);
void printLeafEdge(BT *root);

BT *root = NULL;

int main()
{
    int op, val;
    system("cls");
    while (1)
    {
        printf("\nEnter 1->Insert\nEnter 2->Edge Node\nEnter 3->Exit\nEnetr the Operation : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter the value : ");
            scanf("%d", &val);
            insert(&root, val);
            break;
        case 2:
            printf("\nEdges of the tree is : ");
            printEdge(root);
            break;
        case 3:
            printf("\nEnd of Program.");
            exit(0);
        }
        printf("\nEnter any key to Continue : ");
        getch();
        system("cls");
    }
}
void insert(BT **root,int val){
    if(*root == NULL)
        *root = create(val);
    else if((*root)->value > val)
        insert(&((*root)->left), val);
    else
        insert(&((*root)->right), val);
}
BT* create(int val){
    BT *new_node = (BT *)malloc(sizeof(BT));
    new_node->value = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
void printEdge(BT *root){
    printLeftEdge(root);
    printLeafEdge(root);
    printRightEdge(root->right);
}
void printLeftEdge(BT *root)
{
    if(!root->left && !root->right)
        return;
    while(root->left){
        printf("%d ", root->value);
        root = root->left;
    }
}
void printLeafEdge(BT *root)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
        printf("%d ", root->value);
    else{
        printLeafEdge(root->left);
        printLeafEdge(root->right);
    }
}
void printRightEdge(BT *root){
    if (root->right){
        printRightEdge(root->right);
        printf("%d ", root->value);
    }
}